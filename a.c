#include <stdio.h>  
#include <pthread.h>  
#include <unistd.h>  

void *work_thread(void *arg)  
{  
    pthread_mutex_t mutex;  
    pthread_mutex_init(&mutex, 0);  
    usleep(1000*1000);  
    fprintf(stderr, "timeout we will start dead lock\n");  
    pthread_mutex_lock(&mutex);  
    pthread_mutex_lock(&mutex);  
    return 0;
}  

void *alive_thread(void *arg)  
{  
    while (1)  
    {  
        usleep(1000*1000);  
    }  
    return 0;
}  

int main()  
{  
    pthread_t alive_pid;  
    pthread_create(&alive_pid, 0, alive_thread, 0);  
    pthread_t dead_pid;  
    pthread_create(&dead_pid, 0, work_thread, 0);  
    void *ret = NULL;  
    pthread_join(dead_pid, &ret);  
    void *ret2 = NULL;  
    pthread_join(alive_pid, &ret2);  
    return 0;  
}
