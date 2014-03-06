#include "PhilosophicalSecession.h"

sem_t PhilosophicalSecession::leftChopstick(int position) {
    int leftPhilosopher = position - 1;
    if (leftPhilosopher < 0) {
        leftPhilosopher += numberOfphilosophers;
    }
    return chopsticks[leftPhilosopher];
}

sem_t PhilosophicalSecession::rightChopstick(int position) {
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
        philosophers[index].init(index, leftChopstick(index), rightChopstick(index));
    }
    philosophers[lastPhilosopher].init(lastPhilosopher, rightChopstick(lastPhilosopher), leftChopstick(lastPhilosopher));
    pthread_join(philosophers[lastPhilosopher].getLife(), NULL);
    
}