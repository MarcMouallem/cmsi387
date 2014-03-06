#include "Philosopher.h"

void* Philosopher::birth(void* arg) {
    Philosopher* philosopher = (Philosopher*) arg;
    while(true){
        philosopher -> think();
        philosopher -> eat();
    }            
}

void Philosopher::think() {
    timespec duration = {5, 0};
    nanosleep(&duration, 0);
}

void Philosopher::eat() {

    sem_wait(&chopstickAcquiredFirst);
    sem_wait(&chopstickAcquiredSecond);

    timespec duration = {5, 0};
    nanosleep(&duration, 0);

    sem_close(&chopstickAcquiredSecond);
    sem_close(&chopstickAcquiredFirst);

}
    
void Philosopher::init(sem_t chopstickAcquiredFirst, sem_t chopstickAcquiredSecond) {

    this -> chopstickAcquiredFirst = chopstickAcquiredFirst; 
    this -> chopstickAcquiredSecond = chopstickAcquiredSecond; 

    pthread_create(&life, 0, &Philosopher::birth, this);

}