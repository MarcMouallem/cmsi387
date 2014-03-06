#ifndef _PhilosophicalSecession_

#define _PhilosophicalSecession_

#include <semaphore.h>
#include "Philosopher.h"

class PhilosophicalSecession {
    
    private: 
    
        int numberOfChopsticks;
        int numberOfphilosophers;
    
        sem_t *chopsticks;
        Philosopher *philosophers;
        
        sem_t leftChopstick(int position);
        sem_t rightChopstick(int position);

    public:              
        PhilosophicalSecession(int numberOfphilosophers);
        ~PhilosophicalSecession();
        
};

#endif