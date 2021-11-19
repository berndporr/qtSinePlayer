# QT Sine Wave player

To get this once and for all out of the way here here is a
class called `AudioBeep` which creates a nice pleasant
1kHz sine tone and sends it out.

## How to compile

`qmake`
`make`

## How to run

`./qtsineplay`

## How to use in your program

Include audiobeep.h into your program:
```
#include "audiobeep.h"
```

Create an instance of `AudioBeep`:
```
audiobeep = new AudioBeep(this,[[duration,]frequency]);
```
where frequency defaults to 1kHz and duration to 1sec.

And play a sound whenever you need it:
```
audiobeep->play();
```

Credits:

https://forum.qt.io/topic/86218/trouble-playing-sound-directly-out-of-raw-data-vectors/12
