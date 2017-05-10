
#ifndef Licht_h
#define Licht_h

#include "Arduino.h"

class Licht
{
  public:
    Licht(int pin);
    void aan();
    void uit();
    void flits(int vertraag);
    boolean leesKnop();
    void toggle();
  private:
    int _pin;
    int _vertaag;
    int _knop;
};

#endif
