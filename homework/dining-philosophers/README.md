Dining Philosophers
===================

I am implementing the audience solution. Details can be found [here][1].

> JD: Strange name for it—I don't see the purpose of stating that one of the philosophers
>     is facing the other way.  This is merely asymmetry, which is indeed known to avoid
>     deadlock by breaking circular wait.  I agree with the Wikipedia note disputing this
>     section's accuracy; it does not add anything that hasn't already been known for
>     decades.

To Compile
----------
You must add a few flags, but here is the command.
``g++ -lpthread -std=c++11 start.cpp PhilosophicalSecession.cpp Philosopher.cpp``

> JD: You know a `Makefile` would have totally made this turnkey.

To Run
------
You must specify how many philosophers are at the table as an argument. Typically five.
``a.out 5``

  [1]: http://en.wikipedia.org/wiki/Dining_philosophers_problem#Audience_solution
