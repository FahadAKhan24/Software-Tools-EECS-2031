# include <stdio.h>
# include <string.h>
# include <math.h>
# include "ppmtools.h"

void ppm2float(unsigned char *im, int width, int height, float *res)
{
  int i;
  for(i=0;i<width*height;i++)
    res[i] = (im[3 * i] + im[3 * i + 1] + im[3 * i + 2]) / 3;
}

void float2ppm(float *res, int width, int height, unsigned char *im)
{
  int i;
  float maxabs = 0.0f;

  for(i=0;i<width*height;i++)
    if(fabs(res[i]) > maxabs) maxabs = fabs(res[i]);
  if(maxabs == 0.0) maxabs = 1.0f;

  for(i=0;i<width*height;i++){
    unsigned char v =  res[i];
    im[3 * i] = im[3 * i + 1] = im[3 * i + 2] = 128 + 127 * v / maxabs;
  }
}

int readppm(char *fn, unsigned char *im, int *width, int *height)
{
  FILE *fd;
  char buf[81], line[720];
  int depth, foundHeader = 0;;

  if((fd = fopen(fn, "r")) == NULL){
    fprintf(stderr,"ppmtools: cannot open %s\n",fn);
    return(-1);
  }
  strcpy(line, "");
  while(!foundHeader) {
    if(fgets((char *)buf, 80, fd)==NULL){
      (void) fprintf(stderr,"%s is not a ppm file!\n",fn);
      return(-1);
    }
    if(buf[0] != '#') {
      buf[strlen(buf)-1] = ' ';
      strcat(line, buf);
      if(sscanf(line,"P6 %d %d %d", width, height, &depth) == 3)
        foundHeader = 1;
      if(strlen(line) > 640) {
        fprintf(stderr,"ppmtools: can't parse ppm file\n");
        return(-1);
      }
    }
  }
  printf("Input image is of size %d x %d\n",*width,*height);

  if(fread(im, (*width) * (*height * 3), 1, fd) != 1) {
    (void) fprintf(stderr,"read of %s failed\n",fn);
    return(-1);
  }
  (void) fclose(fd);
  return(0);
}


int writeppm(char *fn, unsigned char *im, int width, int height)
{
  FILE *fd;

  if((fd = fopen(fn, "w")) == NULL){
    fprintf(stderr,"ppmtools: cannot open %s\n",fn);
    return(-1);
  }
  (void) fprintf(fd, "P6 %d %d %d\n", width, height, 255);

  if(fwrite(im, 3 * height * width, 1, fd) != 1){
    (void) fprintf(stderr,"write of %s failed\n",fn);
    return(-1);
  }
  (void) fclose(fd);
  return(0);
}

  

