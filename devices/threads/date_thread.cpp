#include "threads_conf.h"

pthread_t thread_date;

void date_create_thread(void) 
{
    pthread_create(&thread_date, NULL, date_thread, NULL);
}

void* date_thread(void* arg) 
{
    while(1) 
    {
        date_loop();
        usleep(1000000); 
    }
    return NULL;
}