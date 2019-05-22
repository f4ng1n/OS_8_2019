#include <stdio.h>
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string>
#include <string.h>
#include <time.h>

using namespace std;

int fd;   
bool flag1 = true;

void* func1(void *) 
{    
    cout << "Reading from named channel:"<<endl;
    int buf;
    while(flag1)
    {
       buf = 0;
       int pr = read(fd,(void*)&buf,sizeof(buf));
       if (pr > 0)
       cout<<buf<<flush<<endl;    
       else
        {
         flag1 = 0;
         cout <<"Press ENTER"<<endl; 
        }
    }                  
}

int main() 
{
    pthread_t id1;
    mkfifo("canal",0777);
    
    fd=open("canal",O_RDONLY);
    
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
