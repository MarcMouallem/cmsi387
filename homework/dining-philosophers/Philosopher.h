#ifndef _Philosopher_

#define _Philosopher_

#include <iostream>
#include <cstdio>
#include <semaphore.h>
#include <pthread.h>

class Philosopher {
    
    private :
    
        int philosopherId;
        char philosopherIdString[21];
        sem_t chopstickAcquiredFirst;
        sem_t chopstickAcquiredSecond;
        pthread_t life;
        
        static void* birth(void* arg);
        void think();
        void eat();

    public :
        void init(int philosopherId, sem_t chopstickAcquiredFirst, sem_t chopstickAcquiredSecond);
        pthread_t getLife();
      
};

#endif