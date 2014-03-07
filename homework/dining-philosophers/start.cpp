#include <iostream>
#include "Philosopher.h"
#include "PhilosophicalSecession.h"

int main(int argc, char ** argv) {
    int numberOfPhilosophers = std::stoi(argv[1]);
    PhilosophicalSecession philosophicalSecession(numberOfPhilosophers);
}