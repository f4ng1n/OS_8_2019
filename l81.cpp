#include <stdio.h>
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <csignal>
#include <errno.h>


using namespace std;
int fd;

bool flag1 = true;


void sig_handle (int signo)
{
	flag1 = 0;
	cout << "ENTER " << endl;
}


void* func1(void *) {
    
cout << "Writing to named channel:"<<endl;
  
int buf = 0;
   while(flag1){

      buf++;
      
     int pr = write(fd,(void*)&buf,sizeof(int));
    if (pr > 0)
       cout<<buf<<flush;
       cout<<endl;
        sleep(1);
  }
}




int main() {
	
    pthread_t id1;
   signal (SIGPIPE, sig_handle); 
    
  mkfifo("canal",0777);

  
  fd=open("canal",O_WRONLY|O_NONBLOCK);
  if (fd < 0)
       {
	cout << "No process to read!" << endl;
	return 0;
		}
    
    pthread_t args;
    flag1=true;
    pthread_create(&id1, NULL, func1,(void*)&args);
    getchar();
    flag1 = 0;
    pthread_join(id1, NULL);
    
    close(fd);
    unlink("canal");
    return 0;
}
