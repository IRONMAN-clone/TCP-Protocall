#ifndef FIO_H
#define FIO_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct syscallfilesys
{
  int filed;
  char buffer[];
}FILE_STREAM;

void stream_open(FILE_STREAM *fs,const char* name,int m){
  fs->filed = open(name,m);
}

/*
void stream_read(int filed,char buffer[],size_t size)
{
  lseek(filed,0,SEEK_SET);
  read(filed,buffer,size);

  for(int i = 0; i < (int)size; i++)
    {
      if(buffer[i] == '\0'){
	buffer[i] = 0;
      }
    }
}
*/
void stream_read(FILE_STREAM *fs,size_t size)
{
  lseek(fs->filed,0,SEEK_SET);
  read(fs->filed,fs->buffer,size);

  for(int i = 0; i < (int)size; i++)
    {
      if(fs->buffer[i] == '\0')
	fs->buffer[i] = 0;
    }
}

/*
void stream_write(int filed,char msg[],size_t msgsize,int whence)
{
  lseek(filed,0,whence);
  write(filed,msg,msgsize);
}
*/
void stream_write(FILE_STREAM *fs,char msg[],size_t msgsize,int wh)
{
  lseek(fs->filed,0,wh);
  write(fs->filed,msg,msgsize);
}

/*
void stream_end(int filed)
{
   close(filed);
}
*/
void stream_end(FILE_STREAM *fs)
{
  close(fs->filed);
}

#endif // FIO_H end
