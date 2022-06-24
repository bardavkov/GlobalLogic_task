#include <iostream>
#include <pthread.h>
#include <string>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "task_lib.h"
int main(){
pthread_t thread;
pthread_create(&thread,NULL,client,NULL);
pthread_join(thread,NULL);
return 0;
}

