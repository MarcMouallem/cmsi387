#ifndef _PhilosophicalSecession_

#define _PhilosophicalSecession_

#include <iostream>
#include <iostream>
#include <semaphore.h>
#include "Philosopher.h"

class PhilosophicalSecession {
    
    private: 
    
        int numberOfChopsticks;
        int numberOfphilosophers; // JD: Should be capital p.
    
        sem_t* chopsticks; // JD: Why semamphores instead of mutexes?
                           //     That's all you need; sem_t is overkill.
        Philosopher* philosophers;
        
        sem_t getLeftChopstick(int position);
        sem_t getRightChopstick(int position);

    public:              
        PhilosophicalSecession(int numberOfphilosophers);
        
};

#endif
