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
    randomBlock();
}

void Philosopher::eat() {
  
    std::cout << std::string("Philosopher ") + philosopherIdString + std::string(" waiting for first chopstick.\n");
    sem_wait(&chopstickAcquiredFirst);
    
    std::cout << std::string("Philosopher ") + philosopherIdString + std::string(" waiting for second chopstick.\n");
    sem_wait(&chopstickAcquiredSecond);

    std::cout << std::string("Philosopher ") + philosopherIdString + std::string(" eating.\n");
    randomBlock();

    sem_post(&chopstickAcquiredSecond);
    sem_post(&chopstickAcquiredFirst);

}
    
void Philosopher::init(int philosopherId, sem_t chopstickAcquiredFirst, sem_t chopstickAcquiredSecond) {

    this -> philosopherId = philosopherId;
    std::sprintf(philosopherIdString, "%d", philosopherId);
    this -> chopstickAcquiredFirst = chopstickAcquiredFirst; 
    this -> chopstickAcquiredSecond = chopstickAcquiredSecond; 

    pthread_create(&life, 0, &Philosopher::birth, this);
    std::cout << std::string("Philosopher ") + philosopherIdString + std::string(" born!\n");

}

void Philosopher::randomBlock() {
    int maxSeconds = 3;
    int seconds = rand() % maxSeconds;
    int nanosecondsInSecond = 1000000000;
    long nanoseconds = rand() % nanosecondsInSecond;
    timespec duration = {seconds, nanoseconds};
    nanosleep(&duration, 0);
}

pthread_t Philosopher::getLife() {
    return life;
}