Dining Philosophers
===================

I am implementing the audience solution. Details can be found [here][1].

To Compile
----------
You must add a few flags, but here is the command.
``g++ -lpthread -std=c++11 start.cpp PhilosophicalSecession.cpp Philosopher.cpp``

To Run
------
You must specify how many philosophers are at the table as an argument. Typically five.
``a.out 5``

  [1]: http://en.wikipedia.org/wiki/Dining_philosophers_problem#Audience_solution
