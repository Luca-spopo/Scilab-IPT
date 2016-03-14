Read help.pdf for instructions.

Note that many of the functions don't seem to work for images with a single channel.
This was not apparant earlier because imread would open even grayscale images as 3 channels.
Imread has been modified and now returns 1 channel in case of grayscale images. Please make sure your functions work for normal 2D matrices too.
