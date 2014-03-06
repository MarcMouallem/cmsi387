#ifndef _Philosopher_

#define _Philosopher_

#include <semaphore.h>
#include <pthread.h>

class Philosopher {
    
    private :
    
        sem_t chopstickAcquiredFirst;
        sem_t chopstickAcquiredSecond;
        pthread_t life;
        
        static void* birth(void* arg);
        void think();
        void eat();

    public :
        void init(sem_t chopstickAcquiredFirst, sem_t chopstickAcquiredSecond);
      
};

#endif