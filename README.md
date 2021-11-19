# QT Sine Wave player

To get this once and for all out of the way here here is a
class called `AudioBeep` which creates a nice pleasant
sine tone and sends it out.

## How to compile

`qmake`

`make`

## How to run

`./qtsineplay`

## How to use it in your program

Include `audiobeep.h` into your program:
```
#include "audiobeep.h"
```

Create an instance of `AudioBeep` in the *constructor*
of your program (i.e. create it only once):
```
audiobeep = new AudioBeep(this,[duration,][frequency,][volume]);
```
where frequency defaults to 1kHz, duration to 1sec and volume at one. `this`
points to the underlying QT widget, usually a window but
it can also be a button itself. Any QT Object will work.

And play a sound whenever you need it and as often as you like:
```
audiobeep->play();
```

Credits:

https://forum.qt.io/topic/86218/trouble-playing-sound-directly-out-of-raw-data-vectors/12

## Troubleshooting

Ubuntu/Debian: Make sure that `libqt5multimedia5-plugins` are installed.
