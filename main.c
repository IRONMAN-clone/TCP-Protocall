#include <stdio.h>
#include <string.h>
#include "fio.h"

void tostr(int n,char data[],int len)
{
  FILE *fp;
  fp = fopen("temp.t","w");
  fprintf(fp,"%d",n);
  fclose(fp);

  FILE *r;
  r = fopen("temp.t","r");
  fgets(data,len+1,r);
  fclose(r);

  remove("temp.t");
}

// print 1-5 in a file using my custom file stream
// TODO : Completed

// this was the basic of my logging system for server protocals
// purely made in C through some syscalls or whatever
// TODO : Start working upto how TCP prots work / make a tcp prot
// TODO : make tostr function with my custom filestream

int main(int argc, char** argv)
{
  FILE_STREAM fs;
  stream_open(&fs,"log.txt",O_RDWR);

  char finalset[5];
  char setstore[5];
  int temp = 0;
  
  for(int i = 0; i <= 5; i++){

    if(i == 0){
      char tmp[1];
      tostr(i,tmp,1);
      memcpy(finalset,tmp,strlen(tmp)+1);
    }

    // .. I dunno what this part do but without it the code calls
    // stack smashing detected
    for(int f = 0; f < i; f++){
      setstore[i] = finalset[i];
    }
    
    char t[i];
    sprintf(t,"%d",i);

    finalset[temp] = t[0];
    temp += 1;
  }

  stream_write(&fs,finalset,sizeof(finalset)+1,SEEK_SET);

  printf("0 - 5 Written on log.txt");
  
  return 0;
}	
