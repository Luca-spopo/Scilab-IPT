
#include <iostream>
#include <octave/oct.h>
#include <octave/octave.h>
#include <octave/parse.h>
#include <octave/toplev.h>
//#include <complex.h>
#include <cstring>
#include<cstdio>

using namespace std;

extern "C"{
#include "api_scilab.h"
#include "sciprint.h"


int
callOctave(char *fname, unsigned long fname_len)
{ 


//    struct data_type
//    {
//        double matr;
//    };
    SciErr sciErr;
    int iLen        = 0;
    //variable info
    int iType       = 0;
    int iComplex    = 0;
    int iPrec       = 0;
    char* pcData    = NULL;
    short* psData   = NULL;
    unsigned char* pucData  = NULL;
    unsigned short* pusData = NULL;
    unsigned int* puiData   = NULL;
    int* piBool     = NULL;
    double** pdblReal2   = NULL;
    double** pdblImg2    = NULL;
    int* piNbItemRow    = NULL;
	int* piColPos       = NULL;
	double* pdblReal3   = NULL;
	double* pdblImg3    = NULL;
    int iVarLen     = 0;
    int iNbItem             = 0;
    char* pstVarname= NULL;
    int* piNbCoef   = NULL;
    int* piData     = NULL;
    int iItem       = 0;
    int iRows       = 0;
    int iCols       = 0;
    int *piAddr     = NULL;
    int *piAddrNew  = NULL;
    double* pdblReal    = NULL;
	double* pdblImg     = NULL;
    double* pdbl_op   = NULL;
    char** pchar_op=NULL;
    int piRows      = 0;
    int piCols      = 0;
    int *piLen      = NULL;
    char **pstData  = NULL;
    char **pstData1 = NULL;
    //int **pstData1  = NULL;
    int i,j,k=0;
    string_vector argv (2);
    int y;
    double x;    
    int r,c,p;
    char* string_pointer;
    char* string1;
    char* pint8_op = NULL;
    short* pint16_op = NULL;
    int* pint32_op = NULL;
    unsigned char* puint8_op = NULL;
    unsigned short* puint16_op = NULL;
    unsigned int* puint32_op = NULL;
    int* pibool_op=NULL;
    double* pdbl_real_op=NULL;
    double* pdbl_imag_op=NULL;
    

    int n=nbInputArgument(pvApiCtx);
    int o=nbOutputArgument(pvApiCtx);
    FILE *debugfile=fopen("/tmp/debug.txt","w");

///////////// First input argument will be a string containing the name of the Octave function.///////////////////////////////////////////////

    sciErr = getVarAddressFromPosition(pvApiCtx, 1, &piAddr);

    if (sciErr.iErr)
    {
        printError(&sciErr, 0);
        return 0;
    }

    sciErr = getMatrixOfString(pvApiCtx, piAddr, &iRows, &iCols, NULL, NULL);
    if(sciErr.iErr)
    {
        printError(&sciErr, 0);
        return 0;
    }
    piLen = (int*)malloc(sizeof(int) * iRows * iCols);
    
    sciErr = getMatrixOfString(pvApiCtx, piAddr, &iRows, &iCols, piLen, NULL);
    if(sciErr.iErr)
    {
        printError(&sciErr, 0);
        return 0;
	
    }
    pstData = (char**)malloc(sizeof(char*) * iRows * iCols);

    for(i = 0 ; i < iRows * iCols ; i++)
    {
        pstData[i] = (char*)malloc(sizeof(char) * (piLen[i] + 1));//+ 1 for null termination
    }
    
    sciErr = getMatrixOfString(pvApiCtx, piAddr, &iRows, &iCols, piLen, pstData);
    if(sciErr.iErr)
    {
        printError(&sciErr, 0);
        return 0;
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    octave_value_list in;
    //Assign rest of the input arguments to the corresponding data type
    for(i=2;i<=n;i++)
    {
        sciErr = getVarAddressFromPosition(pvApiCtx, i, &piAddr);
        if(sciErr.iErr)
        {
                printError(&sciErr, 0);
                return 1;
        }

        sciErr = getVarType(pvApiCtx, piAddr, &iType);
        if(sciErr.iErr)
        {
                printError(&sciErr, 0);
                return 1;
        }
        switch(iType)
        {
            case 1:
            {            
                iComplex= isVarComplex(pvApiCtx, piAddr);
                if(iComplex)
	            {
	    	        //get size and data from Scilab memory
		            sciErr = getComplexMatrixOfDouble(pvApiCtx, piAddr, &iRows, &iCols, &pdblReal, &pdblImg);
		            ComplexMatrix matrix_double_complex = ComplexMatrix  (iRows,iCols);
		            for (r=0;r<iRows;r++)
                    {
                        for(c=0;c<iCols;c++)
                        {
                            Complex comp(pdblReal[r+iRows*c],pdblImg[r+iRows*c]);
                            matrix_double_complex(r,c)=comp;
                        }
                    }
                    in(i-2)=octave_value (matrix_double_complex);
	            }
	            else
	            {
                    sciErr= getMatrixOfDouble(pvApiCtx, piAddr, &iRows, &iCols, &pdblReal);
//                    if(sciErr.iErr)
//                    {
//                     return sciErr;
//                    }
                    Matrix matrix_double = Matrix (iRows,iCols);
                    for (r=0;r<iRows;r++)
                    {
                        for(c=0;c<iCols;c++)
                        {
                            matrix_double(r,c)=(pdblReal[r+iRows*c]);
                        
                        }
                    }
                    in(i-2)=octave_value (matrix_double);
                }                
                break;
            }

            case 8:
            {
                sciErr = getMatrixOfIntegerPrecision(pvApiCtx, piAddr, &iPrec);
		        if(sciErr.iErr)
		        {
			        printError(&sciErr, 0);
			        return sciErr.iErr;
		        }

		        switch(iPrec)
                {
		            case SCI_INT8 :
                    {
                        sciErr = getMatrixOfInteger8(pvApiCtx, piAddr, &iRows, &iCols, &pcData);
				        if(sciErr.iErr)
				        {
					        printError(&sciErr, 0);
					        return sciErr.iErr;
				        }
				        dim_vector dv (iRows, iCols); 				      
				        int8NDArray matrix_int8 (dv);
//                        intNDArray< octave_int<short> > matrix_int8 =intNDArray< octave_int<short> > (dv);
                        for (r=0;r<iRows;r++)
                        {
                            for(c=0;c<iCols;c++)
                            {
                                matrix_int8(r,c)=(pcData[r+iRows*c]);                                
                            }
                        }
                        in(i-2)=octave_value (matrix_int8);
			            break;
			         }

		             case SCI_INT16 :
		             {
			            sciErr = getMatrixOfInteger16(pvApiCtx, piAddr, &iRows, &iCols, &psData);
				        if(sciErr.iErr)
				        {
				            printError(&sciErr, 0);
					        return sciErr.iErr;
				        }
				        dim_vector dv (iRows, iCols);
				        int16NDArray matrix_int16 (dv);
                        for (r=0;r<iRows;r++)
                        {
                            for(c=0;c<iCols;c++)
                            {
                                matrix_int16(r,c)=(psData[r+iRows*c]);                        
                            }
                        }
                        in(i-2)=octave_value (matrix_int16);
				        break;
				    }

		            case SCI_INT32 :
		            {
			            sciErr = getMatrixOfInteger32(pvApiCtx, piAddr, &iRows, &iCols, &piData);
				        if(sciErr.iErr)
				        {
					        printError(&sciErr, 0);
					        return sciErr.iErr;
				        }
				        dim_vector dv (iRows, iCols);
				        int32NDArray matrix_int32 (dv);
                        for (r=0;r<iRows;r++)
                        {
                            for(c=0;c<iCols;c++)
                            {
                                matrix_int32(r,c)=(piData[r+iRows*c]);                        
                            }
                        }
                        in(i-2)=octave_value (matrix_int32);
			            break;
			       }

		           case SCI_UINT8 :
		           {
				        sciErr = getMatrixOfUnsignedInteger8(pvApiCtx, piAddr, &iRows, &iCols, &pucData);
				        if(sciErr.iErr)
				        {
					        printError(&sciErr, 0);
					        return sciErr.iErr;
				        }
				        dim_vector dv (iRows, iCols);
				        uint8NDArray matrix_uint8 (dv);
                        for (r=0;r<iRows;r++)
                        {
                            for(c=0;c<iCols;c++)
                            {
                                matrix_uint8(r,c)=(pucData[r+iRows*c]);                        
                            }
                        }
                        in(i-2)=octave_value (matrix_uint8);
                        break;
                    }

                    case SCI_UINT16 :
                    {
				        sciErr = getMatrixOfUnsignedInteger16(pvApiCtx, piAddr, &iRows, &iCols, &pusData);
				        if(sciErr.iErr)
				        {
					        printError(&sciErr, 0);
					        return sciErr.iErr;
				        }
				        dim_vector dv (iRows, iCols);
				        uint16NDArray matrix_uint16 (dv);
                        for (r=0;r<iRows;r++)
                        {
                            for(c=0;c<iCols;c++)
                            {
                                matrix_uint16(r,c)=(pusData[r+iRows*c]);                        
                            }
                        }
                        in(i-2)=octave_value (matrix_uint16);
                        break;
			        }

		            case SCI_UINT32 :
		            {
				        sciErr = getMatrixOfUnsignedInteger32(pvApiCtx, piAddr, &iRows, &iCols, &puiData);
				        if(sciErr.iErr)
				        {
					        printError(&sciErr, 0);
					        return sciErr.iErr;
				        }
				        dim_vector dv (iRows, iCols);
				        uint32NDArray matrix_uint32 (dv);
                        for (r=0;r<iRows;r++)
                        {
                            for(c=0;c<iCols;c++)
                            {
                                matrix_uint32(r,c)=(puiData[r+iRows*c]);
                            }
                        }
                        in(i-2)=octave_value (matrix_uint32);
                        break;
			        }
                }
                break;
            }
            
            case 10:
            {
                sciErr = getMatrixOfString(pvApiCtx, piAddr, &iRows, &iCols, NULL, NULL);
                if(sciErr.iErr)
                {
                    printError(&sciErr, 0);
                    return 0;
                }
                piLen = (int*)malloc(sizeof(int) * iRows * iCols);
    
                sciErr = getMatrixOfString(pvApiCtx, piAddr, &iRows, &iCols, piLen, NULL);
                if(sciErr.iErr)
                {
                    printError(&sciErr, 0);
                    return 0;
                }
                pstData1 = (char**)malloc(sizeof(char*) * iRows * iCols);

                for(j = 0 ; j < iRows * iCols ; j++)
                {
                    pstData1[j] = (char*)malloc(sizeof(char) * (piLen[j] + 1));//+ 1 for null termination
                }
    
                sciErr = getMatrixOfString(pvApiCtx, piAddr, &iRows, &iCols, piLen, pstData1);
                
                if(sciErr.iErr)
                {
                    printError(&sciErr, 0);
                    return 0;
                }
                
                charMatrix matrix_string = charMatrix (iRows,iCols);
                for (r=0;r<iRows;r++)
                {
                    for(c=0;c<iCols;c++)
                    {
//                        char xyz[]=*(pstData1[r+iRows*c]);
                        matrix_string(r,c)=*(pstData1[r+iRows*c]);
                                                
                    }
                }
//                fprintf(debugfile,"%s",*(pstData1));
                in(i-2)=octave_value (matrix_string);
                break;
            }

            case 2:
            {
                sciErr = getPolyVariableName(pvApiCtx, piAddr, NULL, &iVarLen);
	            if(sciErr.iErr)
	            {
		            printError(&sciErr, 0);
		            return 0;
	            }

	            //alloc buff to receive variable name
	            pstVarname = (char*)malloc(sizeof(char) * (iVarLen + 1));//1 for null termination

	            //get variable name
	            sciErr = getPolyVariableName(pvApiCtx, piAddr, pstVarname, &iVarLen);
	            if(sciErr.iErr)  
	            {   
		            printError(&sciErr, 0);
		            return 0;
	            }

	            //First call: retrieve dimmension
	            sciErr = getComplexMatrixOfPoly(pvApiCtx, piAddr, &iRows, &iCols, NULL, NULL, NULL);
	            if(sciErr.iErr)
	            {
		            printError(&sciErr, 0);
		            return 0;
	            }

	            //alloc array of coefficient
	            piNbCoef = (int*)malloc(sizeof(int) * iRows * iCols);

	            //Second call: retrieve coefficient
	            sciErr = getComplexMatrixOfPoly(pvApiCtx, piAddr, &iRows, &iCols, piNbCoef, NULL, NULL);
	            if(sciErr.iErr)
	            {
		            printError(&sciErr, 0);
		            return 0;
	            }

	            //alloc arrays of data
	            pdblReal2    = (double**)malloc(sizeof(double*) * iRows * iCols);
	            pdblImg2     = (double**)malloc(sizeof(double*) * iRows * iCols);

	            for(k = 0 ; k < iRows * iCols ;k++)
	            {
		            pdblReal2[k] = (double*)malloc(sizeof(double) * piNbCoef[k]);
		            pdblImg2[k] = (double*)malloc(sizeof(double) * piNbCoef[k]);
	            }

	            //Third call: retrieve data
	            sciErr = getComplexMatrixOfPoly(pvApiCtx, piAddr, &iRows, &iCols, piNbCoef, pdblReal2, pdblImg2);
	            if(sciErr.iErr)
	            {
		            printError(&sciErr, 0);
		            return 0;
	            }
	            break;
            }

            case 5:
            {
                if(isVarComplex(pvApiCtx, piAddr))
	            {
		            sciErr = getComplexSparseMatrix(pvApiCtx, piAddr, &iRows, &iCols, &iNbItem, &piNbItemRow, &piColPos, &pdblReal3, &pdblImg3);
		            int z=0;
		            SparseMatrix matrixComplexSparse = SparseMatrix (iRows,iCols);
		            
                    for(i = 0 ; i < iRows ; i++)
	                {
		                for(j = 0 ; j < piNbItemRow[i] ; j++)
		                {
		                    Complex sparseCplx(pdblReal3[z],pdblImg3[z]);
//			                matrixComplexSparse(i,piColPos[z])= sparseCplx;
			                z++;
			            }
			        }
			        in(i-2)=octave_value (matrixComplexSparse);
	            }
	            else
	            {
		            sciErr = getSparseMatrix(pvApiCtx, piAddr, &iRows, &iCols, &iNbItem, &piNbItemRow, &piColPos, &pdblReal3);
		            int z=0;
		            SparseMatrix matrixSparse = SparseMatrix (iRows,iCols);
                    for(i = 0 ; i < iRows ; i++)
	                {
		                for(j = 0 ; j < piNbItemRow[i] ; j++)
		                {
			                matrixSparse(i,piColPos[z])= pdblReal3[z];
			                z++;
			            }
			        }
			        in(i-2)=octave_value (matrixSparse);
	            }
                
                break;
            }
            
            case 6:
            {
                sciErr = getBooleanSparseMatrix(pvApiCtx, piAddr, &iRows, &iCols, &iNbItem, &piNbItemRow, &piColPos);
                if(sciErr.iErr)
                {
                    printError(&sciErr, 0);
                    return 0;
                 }
//                 SparseBoolMatrix matrix_bool_sparse = SparseBoolMatrix (iRows,iCols);
//                 for (r=0;r<iRows;r++)
//                 {
//                    for(c=0;c<iCols;c++)
//                    {
//                        matrix_bool_sparse(r,c)=(piBool[r+iRows*c]);
//                    }
//                }
//                in(i-2)=octave_value (matrix_bool_sparse);
                break;
            }
            
            case 4:
            {
                sciErr = getMatrixOfBoolean(pvApiCtx, piAddr, &iRows, &iCols, &piBool);
                if(sciErr.iErr)
                {
                    printError(&sciErr, 0);
                    return 0;
                }
                dim_vector dv(iRows,iCols);
                boolMatrix matrix_bool (dv);
                for (r=0;r<iRows;r++)
                {
                    for(c=0;c<iCols;c++)
                    {
                        matrix_bool(r,c)=(piBool[r+iRows*c]);
                    }
                }
                in(i-2)=octave_value (matrix_bool);
                break;
            }
        }
    }

//*******************************************************************************************************************************
    argv(0) = "embedded";
    argv(1) = "-q";
    octave_main (2, argv.c_str_vec (), 1);
    //feval ("pkg", ovl ("load", "all"), 0);
    octave_value_list out = feval (pstData[0], in, o);
//*******************************************************************************************************************************
    
    for (p = 0; p <o; p++)
    {
                if(out(p).is_double_type())
                {
                    dim_vector d = (out(p).matrix_value().dims());
                    pdbl_op = (double*)malloc(sizeof(double) * d(0) * d(1));
                    Matrix x=(out(p).matrix_value ());
                    for(int l = 0 ; l < d(0) ; l++)
	                {
		                for(int m = 0 ; m < d(1) ; m++)
		                {
			                
			                pdbl_op[l+d(0)*m]=x(l,m);
		                }
	                }
                    sciErr=createMatrixOfDouble(pvApiCtx, nbInputArgument(pvApiCtx) + (p+1), d(0), d(1),pdbl_op);
	                AssignOutputVariable(pvApiCtx, p+1) = nbInputArgument(pvApiCtx) + (p+1);
                    free(pdbl_op);
                 }
                 
                 if(out(p).is_complex_type())
                {
                    dim_vector d = (out(p).matrix_value().dims());
                    pdbl_real_op = (double*)malloc(sizeof(double) * d(0) * d(1));
                    pdbl_imag_op = (double*)malloc(sizeof(double) * d(0) * d(1));
//                    Matrix x=(out(p).matrix_value ());
                    for(int l = 0 ; l < d(0) ; l++)
	                {
		                for(int m = 0 ; m < d(1) ; m++)
		                {
			                Complex x=out(p).complex_array_value()(l,m);
			                
			                pdbl_real_op[l+d(0)*m]=x.real();
			                pdbl_imag_op[l+d(0)*m]=x.imag();
		                }
	                }
                    sciErr=createComplexMatrixOfDouble(pvApiCtx, nbInputArgument(pvApiCtx) + (p+1), d(0), d(1), pdbl_real_op,pdbl_imag_op);
	                AssignOutputVariable(pvApiCtx, p+1) = nbInputArgument(pvApiCtx) + (p+1);
                    free(pdbl_real_op);
                    free(pdbl_imag_op);
                 }
                                  
                 else if(out(p).is_int8_type())
                 {
                    dim_vector d = (out(p).int8_array_value().dims());
                    pint8_op = (char*)malloc(1 * d(0) * d(1));
                    int8_t temp;
                    for(int l = 0 ; l < d(0) ; l++)
	                {
		                for(int m = 0 ; m < d(1) ; m++)
		                {
                            temp=out(p).int8_array_value()(l,m);
			                pint8_op[l+d(0)*m]=temp;
		                }
	                }
	                sciErr=createMatrixOfInteger8(pvApiCtx, nbInputArgument(pvApiCtx) + (p+1), d(0), d(1),pint8_op);
	                AssignOutputVariable(pvApiCtx, p+1) = nbInputArgument(pvApiCtx) + (p+1);
                    free(pint8_op);
                }
                
                else if(out(p).is_int16_type())
                 {
                    dim_vector d = (out(p).int16_array_value().dims());
                    pint16_op = (short*)malloc(1 * d(0) * d(1));
                    int16_t temp;
                    for(int l = 0 ; l < d(0) ; l++)
	                {
		                for(int m = 0 ; m < d(1) ; m++)
		                {
                            temp=out(p).int16_array_value()(l,m);
			                pint16_op[l+d(0)*m]=temp;
		                }
	                }
	                sciErr=createMatrixOfInteger16(pvApiCtx, nbInputArgument(pvApiCtx) + (p+1), d(0), d(1),pint16_op);
	                AssignOutputVariable(pvApiCtx, p+1) = nbInputArgument(pvApiCtx) + (p+1);
                    free(pint16_op);
                }
                
                else if(out(p).is_int32_type())
                 {
                    dim_vector d = (out(p).int32_array_value().dims());
                    pint32_op = (int*)malloc(1 * d(0) * d(1));
                    int32_t temp;
                    for(int l = 0 ; l < d(0) ; l++)
	                {
		                for(int m = 0 ; m < d(1) ; m++)
		                {
                            temp=out(p).int32_array_value()(l,m);
			                pint32_op[l+d(0)*m]=temp;
		                }
	                }
	                sciErr=createMatrixOfInteger32(pvApiCtx, nbInputArgument(pvApiCtx) + (p+1), d(0), d(1),pint32_op);
	                AssignOutputVariable(pvApiCtx, p+1) = nbInputArgument(pvApiCtx) + (p+1);
                    free(pint32_op);
                }
                
                else if(out(p).is_uint8_type())
                 {
                    dim_vector d = (out(p).uint8_array_value().dims());
                    puint8_op = (unsigned char*)malloc(1 * d(0) * d(1));
                    uint8_t temp;
                    for(int l = 0 ; l < d(0) ; l++)
	                {
		                for(int m = 0 ; m < d(1) ; m++)
		                {
                            temp=out(p).uint8_array_value()(l,m);
			                puint8_op[l+d(0)*m]=temp;
		                }
	                }
	                sciErr=createMatrixOfUnsignedInteger8(pvApiCtx, nbInputArgument(pvApiCtx) + (p+1), d(0), d(1),puint8_op);
	                AssignOutputVariable(pvApiCtx, p+1) = nbInputArgument(pvApiCtx) + (p+1);
                    free(puint8_op);
                }
                
                else if(out(p).is_uint16_type())
                 {
                    dim_vector d = (out(p).uint16_array_value().dims());
                    puint16_op = (unsigned short*)malloc(1 * d(0) * d(1));
                    uint16_t temp;
                    for(int l = 0 ; l < d(0) ; l++)
	                {
		                for(int m = 0 ; m < d(1) ; m++)
		                {
                            temp=out(p).uint16_array_value()(l,m);
			                puint16_op[l+d(0)*m]=temp;
		                }
	                }
	                sciErr=createMatrixOfUnsignedInteger16(pvApiCtx, nbInputArgument(pvApiCtx) + (p+1), d(0), d(1),puint16_op);
	                AssignOutputVariable(pvApiCtx, p+1) = nbInputArgument(pvApiCtx) + (p+1);
                    free(puint16_op);
                }
                
                else if(out(p).is_uint32_type())
                 {
                    dim_vector d = (out(p).uint32_array_value().dims());
                    puint32_op = (unsigned int*)malloc(1 * d(0) * d(1));
                    uint32_t temp;
                    for(int l = 0 ; l < d(0) ; l++)
	                {
		                for(int m = 0 ; m < d(1) ; m++)
		                {
                            temp=out(p).uint32_array_value()(l,m);
			                puint32_op[l+d(0)*m]=temp;
		                }
	                }
	                sciErr=createMatrixOfUnsignedInteger32(pvApiCtx, nbInputArgument(pvApiCtx) + (p+1), d(0), d(1),puint32_op);
	                AssignOutputVariable(pvApiCtx, p+1) = nbInputArgument(pvApiCtx) + (p+1);
                    free(puint32_op);
                }
                
                else if(out(p).is_bool_type())
                 {
                    dim_vector d = (out(p).bool_array_value().dims());
                    for(int l = 0 ; l < d(0) ; l++)
	                {
		                for(int m = 0 ; m < d(1) ; m++)
		                {
                            pibool_op[l+d(0)*m]=out(p).bool_array_value()(l,m);
			            }
	                }
	                sciErr=createMatrixOfBoolean(pvApiCtx, nbInputArgument(pvApiCtx) + (p+1), d(0), d(1),pibool_op);
	                AssignOutputVariable(pvApiCtx, p+1) = nbInputArgument(pvApiCtx) + (p+1);
                    free(pibool_op);
                }
                
                else
                {
                    sciprint("Undefined datatype");
                }
//             if(out(0).is_string())
//             {
////                sciprint("test");
//                dim_vector d = (out(0).char_matrix_value().dims());
////                sciprint("%d\n%d",d(0),d(1));
//                pchar_op= (char**)malloc(sizeof(char*) * d(0) * d(1));
//                string_pointer=(char*)malloc(sizeof(char*) * d(0) * d(1));
//                
////                for(int l = 0 ;l < d(0) ; l++)
////	            {
////		            for(int m = 0 ; m < d(1) ; m++)
////		            {
////		                
//                        string_matrix=out(0).string();
////                        pchar_op[l+d(0)*m]=string_matrix.string_value()(l,m);
//////                        fprintf(debugfile,"str_p=%s\n",string_matrix[l+d(0)*m]);
////                        char* string_pointer=string_matrix.fortran_vec();
////                        string1[l+d(0)*m]=string_pointer[l+d(0)*m];
////                        sciprint("%s",string_pointer[l+d(0)*m]);
////                        string_pointer[l+d(0)*m]=string_matrix.string_matrix_value()(l,m);
////			            pchar_op[l+d(0)*m]=&(string1[l+d(0)*m]);
//////                        std::string tmp=string_matrix(l,m);
//////                        fprintf(debugfile,"str_p=%s\n",tmp);
//////                        pchar_op[l+d(0)*m]=tmp;                        
////			        }
////			    }

//			        fprintf(debugfile,"pchar=%s\n",*pchar_op);
//			        fprintf(debugfile,"str1=%s\n",*string1);
//			        sciErr = createMatrixOfString(pvApiCtx, nbInputArgument(pvApiCtx) + (p+1), d(0), d(1), pchar_op);
//			        free(pchar_op);
//	                if(sciErr.iErr)
//	                {
//		               printError(&sciErr, 0);
//		               return 0;
//	                }
			     
//             }
             
             
//             else if(out(0).is_sparse_type())
//             {
//               SparseMatrix sparse_matrix=out(0).sparse_matrix_value ();
//               int iNbItem= sparse_matrix.nnz();

//               
//                
//             }    
             
             
            
//            if(sciErr.iErr)
//	        {
//		       printError(&sciErr, 0);
//		       return 0;
//	        }
            
//        }
    }
    fclose(debugfile);
    ReturnArguments(pvApiCtx);
    
    
//            for (octave_idx_value di = 0 ; di < d.length (); di++)
//                std::cout << "Length of dimension " << di << ": " << d(di) << std:endl;
//    
    
  //return 0;
}
}
