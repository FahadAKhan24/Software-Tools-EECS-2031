int writeppm(char *fn, unsigned char *im, int width, int height);
int readppm(char *fn, unsigned char *im, int *width, int *height);
void ppm2float(unsigned char *im, int width, int height, float *res);
void float2ppm(float *res, int width, int height, unsigned char *im);
