#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "dos2sd.h"

/*
FAHAD AHMED KHAN
214468888
5TH OCT 2017
THE CODE LIST  FILES SECTORS FROM THE DISK AND CALCULATES THE SIZE OF EACH FILE.
 */

static void fileInfo(FILE *fd, struct ATRSSDISK *disk, char fileName[])
{
  int sector, entry, i, count, start, baseFileNumber;
  char name[9], ext[4];

  baseFileNumber = 0;
  for(sector=361;sector<=368;sector++) {
    for(entry=0;entry<ATR_SECTOR_SIZE;entry+=16) {
      if(disk->sector[sector-1][entry] == 0x042) {
        for(i=0;i<8;i++)
          name[i] = disk->sector[sector-1][entry+5+i];
        name[8] = '\0';
        for(i=0;i<3;i++) 
          ext[i] = disk->sector[sector-1][entry+13+i];
        ext[3] = '\0';
        count = disk->sector[sector-1][entry+1]|disk->sector[sector-1][entry+2]<<8;
        start = disk->sector[sector-1][entry+3]|disk->sector[sector-1][entry+4]<<8;
        char n[9];
        char e[4];
        
        sscanf(fileName, "%[^.]%*[.]%s", n,e);
        if(strcmp(n, name) == 0){
				
		fprintf(fd,"%s.%s sector List ", n, e);
			for(i=start;i<(count+start);i++)
				fprintf(fd,"%d ", i);	
			
			
		int next = start;
		int s = 0;
		int b = 0;
		
		while(next < (count+start)){
			 s = disk->sector[next][127];  
			 b = b + s;
			 
			 next++;
		}
		fprintf(fd,"Total file size %d\n", b);
		}
      }
      baseFileNumber++;
    }
  }
}



int main(int argc, char *argv[])
{
  struct ATRSSDISK *disk;
  if(argc != 3) {
    fprintf(stderr,"usage: %s disk\n", argv[0]);
    exit(1);
  }
  if((disk = readDisk(argv[1])) == (struct ATRSSDISK *)NULL) {
    fprintf(stderr,"Unable to read disk %s\n", argv[1]);
    exit(1);
  }
  fileInfo(stdout, disk, argv[2]); /* put it in atari offset notation 1..720 */
  freeDisk(disk);
  return 0;
    
}
