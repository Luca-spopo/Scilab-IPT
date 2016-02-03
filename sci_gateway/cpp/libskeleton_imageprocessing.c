#ifdef __cplusplus
extern "C" {
#endif
#include <mex.h> 
#include <sci_gateway.h>
#include <api_scilab.h>
#include <MALLOC.h>
static int direct_gateway(char *fname,void F(void)) { F();return 0;};
extern Gatefunc dctmtx;
extern Gatefunc multithresh;
extern Gatefunc opencv_applycform;
extern Gatefunc opencv_arrowedline;
extern Gatefunc opencv_blur;
extern Gatefunc opencv_boundingRect;
extern Gatefunc opencv_bwconvhull;
extern Gatefunc opencv_bwdistgeodesic;
extern Gatefunc opencv_bwlookup;
extern Gatefunc opencv_canny;
extern Gatefunc opencv_circle;
extern Gatefunc opencv_clipline;
extern Gatefunc opencv_convexhull;
extern Gatefunc opencv_convmtx2;
extern Gatefunc opencv_copymakeborder;
extern Gatefunc opencv_corner;
extern Gatefunc opencv_cornerEigenValsAndVecs;
extern Gatefunc opencv_cornerHarris;
extern Gatefunc opencv_cornerMinEigenVal;
extern Gatefunc opencv_cvtColor;
extern Gatefunc opencv_demosaic;
extern Gatefunc opencv_dilate;
extern Gatefunc opencv_ellipse;
extern Gatefunc opencv_ellipse2poly;
extern Gatefunc opencv_erode;
extern Gatefunc opencv_fftshift;
extern Gatefunc opencv_fillconvexpoly;
extern Gatefunc opencv_filter2D;
extern Gatefunc opencv_findContours;
extern Gatefunc opencv_fsamp2;
extern Gatefunc opencv_gabor;
extern Gatefunc opencv_gaussianblur;
extern Gatefunc opencv_getStructuringElement;
extern Gatefunc opencv_getTextSize;
extern Gatefunc opencv_getgaussiankernel;
extern Gatefunc opencv_getrectsubpix;
extern Gatefunc opencv_getrotationmatrix2D;
extern Gatefunc opencv_goodfeaturestotrack;
extern Gatefunc opencv_houghcircles;
extern Gatefunc opencv_houghlines;
extern Gatefunc opencv_houghlinesp;
extern Gatefunc opencv_ifftshift;
extern Gatefunc opencv_im2double;
extern Gatefunc opencv_imabsdiff;
extern Gatefunc opencv_imadd;
extern Gatefunc opencv_imattributes;
extern Gatefunc opencv_imboxfilt3;
extern Gatefunc opencv_imcomplement;
extern Gatefunc opencv_imcontour;
extern Gatefunc opencv_imcontrast;
extern Gatefunc opencv_imcrop;
extern Gatefunc opencv_imdivide;
extern Gatefunc opencv_imextendedmax;
extern Gatefunc opencv_imextendedmin;
extern Gatefunc opencv_imfill;
extern Gatefunc opencv_imfindcircles;
extern Gatefunc opencv_imfuse;
extern Gatefunc opencv_imgaborfilt;
extern Gatefunc opencv_imgaussfilt3;
extern Gatefunc opencv_imguidedfilter;
extern Gatefunc opencv_imhmax;
extern Gatefunc opencv_imhmin;
extern Gatefunc opencv_imimposemin;
extern Gatefunc opencv_imlincomb;
extern Gatefunc opencv_immultiply;
extern Gatefunc opencv_impixel;
extern Gatefunc opencv_impyramid;
extern Gatefunc opencv_imread;
extern Gatefunc opencv_imrect;
extern Gatefunc opencv_imresize;
extern Gatefunc opencv_imsharpen;
extern Gatefunc opencv_imshowpair;
extern Gatefunc opencv_imsubtract;
extern Gatefunc opencv_imwarp;
extern Gatefunc opencv_imwrite;
extern Gatefunc opencv_ind2gray;
extern Gatefunc opencv_ind2rgb;
extern Gatefunc opencv_lab2double;
extern Gatefunc opencv_lab2rgb;
extern Gatefunc opencv_lab2uint16;
extern Gatefunc opencv_lab2uint8;
extern Gatefunc opencv_lab2xyz;
extern Gatefunc opencv_laplacian;
extern Gatefunc opencv_line;
extern Gatefunc opencv_medianblur;
extern Gatefunc opencv_montage;
extern Gatefunc opencv_morphologyEx;
extern Gatefunc opencv_ntsc2rgb;
extern Gatefunc opencv_puttext;
extern Gatefunc opencv_pyrDown;
extern Gatefunc opencv_pyrUp;
extern Gatefunc opencv_rectangle;
extern Gatefunc opencv_regionfill;
extern Gatefunc opencv_rgb2lab;
extern Gatefunc opencv_rgb2ntsc;
extern Gatefunc opencv_rgb2xyz;
extern Gatefunc opencv_roifill;
extern Gatefunc opencv_roipoly;
extern Gatefunc opencv_scharr;
extern Gatefunc opencv_sepFilter2D;
extern Gatefunc opencv_sobel;
extern Gatefunc opencv_ssim;
extern Gatefunc opencv_threshold;
extern Gatefunc opencv_undistort;
extern Gatefunc opencv_viscircles;
extern Gatefunc opencv_watershed;
extern Gatefunc opencv_whitepoint;
extern Gatefunc opencv_wiener2;
extern Gatefunc opencv_xyz2double;
extern Gatefunc opencv_xyz2lab;
extern Gatefunc opencv_xyz2rgb;
extern Gatefunc opencv_xyz2uint16;
extern Gatefunc opencv_deconvlucy;
extern Gatefunc opencv_imhistmatch;
extern Gatefunc opencv_graycoprops;
extern Gatefunc opencv_graydiffweight;
extern Gatefunc opencv_decorrstretch;
extern Gatefunc opencv_adapthisteq;
extern Gatefunc opencv_affine2d;
extern Gatefunc approxpolyDP;
extern Gatefunc arclenght;
extern Gatefunc bilateralfilter;
extern Gatefunc borderInterpolate;
extern Gatefunc boxfilter;
extern Gatefunc contourarea;
extern Gatefunc boxfilter;
extern Gatefunc fitellipse;
extern Gatefunc getkerneltype;
extern Gatefunc histeq;
extern Gatefunc imrotate;
extern Gatefunc mean1;
extern Gatefunc minAreaRect;
extern Gatefunc minimumenclosingcirlce;
extern Gatefunc pyrMeanShiftFiltering;
extern Gatefunc rgb2gray;
extern Gatefunc warpaffine;
static GenericTable Tab[]={
  {(Myinterfun)sci_gateway_without_putlhsvar,dctmtx,"raw_dctmtx"},
  {(Myinterfun)sci_gateway_without_putlhsvar,multithresh,"raw_multithresh"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_applycform,"raw_applycform"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_arrowedline,"raw_arrowedline"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_blur,"raw_blur"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_boundingRect,"raw_boundingRect"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_bwconvhull,"raw_bwconvhull"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_bwdistgeodesic,"raw_bwdistgeodesic"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_bwlookup,"raw_bwlookup"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_canny,"raw_canny"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_circle,"raw_circle"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_clipline,"raw_clipline"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_convexhull,"raw_convexhull"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_convmtx2,"raw_convmtx2"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_copymakeborder,"raw_copymakeborder"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_corner,"raw_corner"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_cornerEigenValsAndVecs,"raw_cornerEigenValsAndVecs"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_cornerHarris,"raw_cornerHarris"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_cornerMinEigenVal,"raw_cornerMinEigenVal"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_cvtColor,"raw_cvtColor"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_demosaic,"raw_demosaic"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_dilate,"raw_dilate"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_ellipse,"raw_ellipse"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_ellipse2poly,"raw_ellipse2poly"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_erode,"raw_erode"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_fftshift,"raw_fftshift"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_fillconvexpoly,"raw_fillconvexpoly"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_filter2D,"raw_filter2D"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_findContours,"raw_findContours"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_fsamp2,"raw_fsamp2"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_gabor,"raw_gabor"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_gaussianblur,"raw_gaussianblur"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_getStructuringElement,"raw_getStructuringElement"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_getTextSize,"raw_getTextSize"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_getgaussiankernel,"raw_getgaussiankernel"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_getrectsubpix,"raw_getrectsubpix"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_getrotationmatrix2D,"raw_getrotationmatrix2D"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_goodfeaturestotrack,"raw_goodfeaturestotrack"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_houghcircles,"raw_houghcircles"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_houghlines,"raw_houghlines"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_houghlinesp,"raw_houghlinesp"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_ifftshift,"raw_ifftshift"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_im2double,"raw_im2double"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imabsdiff,"raw_imabsdiff"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imadd,"raw_imadd"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imattributes,"raw_imattributes"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imboxfilt3,"raw_imboxfilt3"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imcomplement,"raw_imcomplement"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imcontour,"raw_imcontour"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imcontrast,"raw_imcontrast"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imcrop,"raw_imcrop"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imdivide,"raw_imdivide"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imextendedmax,"raw_imextendedmax"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imextendedmin,"raw_imextendedmin"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imfill,"raw_imfill"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imfindcircles,"raw_imfindcircles"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imfuse,"raw_imfuse"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imgaborfilt,"raw_imgaborfilt"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imgaussfilt3,"raw_imgaussfilt3"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imguidedfilter,"raw_imguidedfilter"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imhmax,"raw_imhmax"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imhmin,"raw_imhmin"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imimposemin,"raw_imimposemin"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imlincomb,"raw_imlincomb"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_immultiply,"raw_immultiply"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_impixel,"raw_impixel"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_impyramid,"raw_impyramid"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imread,"raw_imread"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imrect,"raw_imrect"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imresize,"raw_imresize"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imsharpen,"raw_imsharpen"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imshowpair,"raw_imshowpair"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imsubtract,"raw_imsubtract"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imwarp,"raw_imwarp"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imwrite,"raw_imwrite"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_ind2gray,"raw_ind2gray"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_ind2rgb,"raw_ind2rgb"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_lab2double,"raw_lab2double"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_lab2rgb,"raw_lab2rgb"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_lab2uint16,"raw_lab2uint16"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_lab2uint8,"raw_lab2uint8"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_lab2xyz,"raw_lab2xyz"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_laplacian,"raw_laplacian"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_line,"raw_line"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_medianblur,"raw_medianblur"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_montage,"raw_montage"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_morphologyEx,"raw_morphologyEx"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_ntsc2rgb,"raw_ntsc2rgb"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_puttext,"raw_puttext"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_pyrDown,"raw_pyrDown"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_pyrUp,"raw_pyrUp"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_rectangle,"raw_rectangle"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_regionfill,"raw_regionfill"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_rgb2lab,"raw_rgb2lab"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_rgb2ntsc,"raw_rgb2ntsc"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_rgb2xyz,"raw_rgb2xyz"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_roifill,"raw_roifill"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_roipoly,"raw_roipoly"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_scharr,"raw_scharr"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_sepFilter2D,"raw_sepFilter2D"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_sobel,"raw_sobel"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_ssim,"raw_ssim"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_threshold,"raw_threshold"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_undistort,"raw_undistort"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_viscircles,"raw_viscircles"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_watershed,"raw_watershed"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_whitepoint,"raw_whitepoint"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_wiener2,"raw_wiener2"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_xyz2double,"raw_xyz2double"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_xyz2lab,"raw_xyz2lab"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_xyz2rgb,"raw_xyz2rgb"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_xyz2uint16,"raw_xyz2uint16"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_deconvlucy,"deconvlucy"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imhistmatch,"imhistmatch"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_graycoprops,"graycoprops"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_graydiffweight,"graydiffweight"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_decorrstretch,"decorrstretch"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_adapthisteq,"adaptf"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_affine2d,"affine2d"},
  {(Myinterfun)sci_gateway_without_putlhsvar,approxpolyDP,"approxpolyDP"},
  {(Myinterfun)sci_gateway_without_putlhsvar,arclenght,"arclenght"},
  {(Myinterfun)sci_gateway_without_putlhsvar,bilateralfilter,"bilateralfilter"},
  {(Myinterfun)sci_gateway_without_putlhsvar,borderInterpolate,"borderInterpolate"},
  {(Myinterfun)sci_gateway_without_putlhsvar,boxfilter,"boxfilter"},
  {(Myinterfun)sci_gateway_without_putlhsvar,contourarea,"contourarea"},
  {(Myinterfun)sci_gateway_without_putlhsvar,boxfilter,"boxfilter"},
  {(Myinterfun)sci_gateway_without_putlhsvar,fitellipse,"fitellipse"},
  {(Myinterfun)sci_gateway_without_putlhsvar,getkerneltype,"getkerneltype"},
  {(Myinterfun)sci_gateway_without_putlhsvar,histeq,"histeq"},
  {(Myinterfun)sci_gateway_without_putlhsvar,imrotate,"imrotate"},
  {(Myinterfun)sci_gateway_without_putlhsvar,mean1,"mean1"},
  {(Myinterfun)sci_gateway_without_putlhsvar,minAreaRect,"minAreaRect"},
  {(Myinterfun)sci_gateway_without_putlhsvar,minimumenclosingcirlce,"minimumenclosingcirlce"},
  {(Myinterfun)sci_gateway_without_putlhsvar,pyrMeanShiftFiltering,"pyrMeanShiftFiltering"},
  {(Myinterfun)sci_gateway_without_putlhsvar,rgb2gray,"rgb2gray"},
  {(Myinterfun)sci_gateway_without_putlhsvar,warpaffine,"warpaffine"},
};
 
int C2F(libskeleton_imageprocessing)()
{
  Rhs = Max(0, Rhs);
  if (*(Tab[Fin-1].f) != NULL) 
  {
     if(pvApiCtx == NULL)
     {
       pvApiCtx = (StrCtx*)MALLOC(sizeof(StrCtx));
     }
     pvApiCtx->pstName = (char*)Tab[Fin-1].name;
    (*(Tab[Fin-1].f))(Tab[Fin-1].name,Tab[Fin-1].F);
  }
  return 0;
}
#ifdef __cplusplus
}
#endif
