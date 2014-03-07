#include "PhilosophicalSecession.h"

sem_t PhilosophicalSecession::getLeftChopstick(int position) {
    int leftPhilosopher = position - 1;
    if (leftPhilosopher < 0) {
        leftPhilosopher += numberOfphilosophers;
    }
    return chopsticks[leftPhilosopher];
}

sem_t PhilosophicalSecession::getRightChopstick(int position) {
    return chopsticks[position];
}
    
PhilosophicalSecession::PhilosophicalSecession(int numberOfphilosophers) {
    
    this -> numberOfChopsticks = numberOfphilosophers;
    this -> numberOfphilosophers = numberOfphilosophers;

    chopsticks = new sem_t[numberOfChopsticks];
    philosophers = new Philosopher[numberOfphilosophers];

    for (int index = 0; index < numberOfChopsticks; index++) {
        sem_init(&chopsticks[index], 0, 1);
    }
    int lastPhilosopher = numberOfphilosophers - 1;
    for (int index = 0; index < lastPhilosopher; index++) {
        philosophers[index].init(index, getLeftChopstick(index), getRightChopstick(index));
    }
    philosophers[lastPhilosopher].init(lastPhilosopher, getRightChopstick(lastPhilosopher), getLeftChopstick(lastPhilosopher));
    pthread_join(philosophers[lastPhilosopher].getLife(), NULL);
    
}
