#include "Philosopher.h"

void* Philosopher::birth(void* arg) {
    Philosopher* philosopher = (Philosopher*) arg;
    while(true){
        philosopher -> think();
        philosopher -> eat();
    }            
}

// JD: The console log-style strategy for output is technically correct, but ultimately
//     not ideal for communicating the state of the system to the user.  The messages
//     have to be read vertically and the system state needs to be reconstructed manually
//     based on the sequence of events---cognitively more difficult than it has to be.
//     Better to display the entire state of the system; who's eating, who's thinking,
//     who has which chopstick, etc.  That way potential error conditions are easier
//     to catch.
void Philosopher::think() {
    std::cout << std::string("Philosopher ") + philosopherIdString + std::string(" thinking.\n");
    randomBlock();
}

// JD: Case in point---here is an exact copy-paste excerpt from when I was running
//     your program.  Note the bottom 9 lines.  ***It logs that philosophers 1, 2,
//     and 3 are eating***---which of course violates the conditions of the system!
//     How did this happen?  How did things get here?  With output like this, it is
//     hard to say.  You would have to give the code a really close look.
//
//        Philosopher 3 thinking.
//        Philosopher 0 thinking.
//        Philosopher 4 thinking.
//        Philosopher 0 waiting for first chopstick.
//        Philosopher 0 waiting for second chopstick.
//        Philosopher 0 eating.
//        Philosopher 1 thinking.
//        Philosopher 2 thinking.
//        Philosopher 0 thinking.
//        Philosopher 3 waiting for first chopstick.
//        Philosopher 3 waiting for second chopstick.
//        Philosopher 3 eating.
//        Philosopher 2 waiting for first chopstick.
//        Philosopher 2 waiting for second chopstick.
//        Philosopher 2 eating.
//        Philosopher 1 waiting for first chopstick.
//        Philosopher 1 waiting for second chopstick.
//        Philosopher 1 eating.
//
void Philosopher::eat() {
  
    std::cout << std::string("Philosopher ") + philosopherIdString + std::string(" waiting for first chopstick.\n");
    sem_wait(&chopstickAcquiredFirst);

    // JD: By not keeping track of the state of an actual table data structure, you
    //     lose sight of the real reason we are writing this program---which is to
    //     coordinate the use of shared resources.  Your implementation includes
    //     only the synchronization, and not the resource.  This prevents two things:
    //     first, the "snapshot"-style output which communicates things to the user
    //     better than the log style.  Second, and more importantly, it prevents you
    //     from including sanity-check guard statements that can verify, after lock
    //     acquisition, whether a chopstick is still available to pick up.  Considering
    //     that the output I got illustrates a potential issue with your synchronization,
    //     the lack of system state makes things harder to debug.
    std::cout << std::string("Philosopher ") + philosopherIdString + std::string(" waiting for second chopstick.\n");
    sem_wait(&chopstickAcquiredSecond);

    std::cout << std::string("Philosopher ") + philosopherIdString + std::string(" eating.\n");
    randomBlock();

    // JD: At this point, you should also check whether the chopsticks that you are
    //     about to release are indeed still in your hand.  Just another sanity check
    //     to ensure that the system is working as specified.
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