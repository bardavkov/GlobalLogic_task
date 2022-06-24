#ifndef LOL_H
#define LOL_H

#include <iostream>
#include <pthread.h>
#include <string>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
bool state=true;
std::string filename;
std::vector<std::string>filedata;
void outvector(std::vector<std::string>outstring);

void* server(void *p){
int fd_fifo;
char buf[256];
if((fd_fifo=open(filename.c_str(),O_RDWR))==-1){
filedata.push_back("not correct");
return NULL;}
if(read(fd_fifo,&buf,sizeof(buf))==-1){
fprintf(stderr,"impossible to read from fifo");
}
else
printf("readed from fifo %s\n",buf);
return NULL;
}
void *client(void* q){
std::cout<<"Enter exit if you want to end the program";
while(state){
std::cout<<"write file name or exit";
std::cin>>filename;
if(filename=="exit"){
state=false;
}
else{
pthread_t takedata;
pthread_create(&takedata,NULL,server,NULL);
pthread_join(takedata,NULL);
}
}
return NULL;
}


#endif
