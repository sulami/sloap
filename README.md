SLOAP
=====

An interactive powernap wakeup timer / alarm clock.

How it works
------------

When powernapping, you want to wake up at a pretty specific time after falling
asleep, usually about ten minutes. But this is quite difficult, because you do
not know in advance when you are going to fall asleep. SLOAP lets you define a
command to run at wakeup time, like starting a music player, but also lets you
restart the countdown on a keypress. Simply hit a key every few minutes while
you are still awake.

Usage
-----

    sloap [-h] [-t time] command [args...]

The default time is 900 seconds, or 15 minutes. By hitting `q` at any time, you
abort the countdown. To restart it, just hit any other key that produces a
character (yes, spacebar does).

Building
--------

Simply run `make`. SLOAP does not need any libraries aside from the C standard
library. Not even (n)curses.

