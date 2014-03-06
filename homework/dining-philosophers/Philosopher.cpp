#include "Philosopher.h"

void* Philosopher::birth(void* arg) {
    Philosopher* philosopher = (Philosopher*) arg;
    while(true){
        philosopher -> think();
        philosopher -> eat();
    }            
}

void Philosopher::think() {
    std::cout << std::string("Philosopher ") + philosopherIdString + std::string(" thinking.\n");
    timespec duration = {5, 0};
    nanosleep(&duration, 0);
}

void Philosopher::eat() {
  
    std::cout << std::string("Philosopher ") + philosopherIdString + std::string(" waiting for first chopstick.\n");
    sem_wait(&chopstickAcquiredFirst);
    
    std::cout << std::string("Philosopher ") + philosopherIdString + std::string(" waiting for second chopstick.\n");
    sem_wait(&chopstickAcquiredSecond);

    std::cout << std::string("Philosopher ") + philosopherIdString + std::string(" eating.\n");
    timespec duration = {5, 0};
    nanosleep(&duration, 0);

    sem_close(&chopstickAcquiredSecond);
    sem_close(&chopstickAcquiredFirst);

}
    
void Philosopher::init(int philosopherId, sem_t chopstickAcquiredFirst, sem_t chopstickAcquiredSecond) {

    this -> philosopherId = philosopherId;
    std::sprintf(philosopherIdString, "%d", philosopherId);
    this -> chopstickAcquiredFirst = chopstickAcquiredFirst; 
    this -> chopstickAcquiredSecond = chopstickAcquiredSecond; 

    pthread_create(&life, 0, &Philosopher::birth, this);
    std::cout << std::string("Philosopher ") + philosopherIdString + std::string(" born!\n");

}

pthread_t Philosopher::getLife() {
    return life;
}