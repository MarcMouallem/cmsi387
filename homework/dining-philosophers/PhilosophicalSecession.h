#ifndef _PhilosophicalSecession_

#define _PhilosophicalSecession_

#include <iostream>
#include <iostream>
#include <semaphore.h>
#include "Philosopher.h"

class PhilosophicalSecession {
    
    private: 
    
        int numberOfChopsticks;
        int numberOfphilosophers;
    
        sem_t* chopsticks;
        Philosopher* philosophers;
        
        sem_t getLeftChopstick(int position);
        sem_t getRightChopstick(int position);

    public:              
        PhilosophicalSecession(int numberOfphilosophers);
        
};

#endif
