#include "Arduino.h"
#include "Licht.h"
int statusVar;
int loopje;

Licht::Licht(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void Licht::aan() {
    digitalWrite(_pin, HIGH);
}

void Licht::uit() {
    loopje = 0;
    digitalWrite(_pin, LOW);
}

boolean Licht::leesKnop(int knop) {
    pinMode(knop, INPUT_PULLUP);
    _knop = knop;
    
    if(digitalRead(_knop) == LOW) {
        statusVar = 1;
        
        if(statusVar == 1) {
            return true;
        }
        
        else {
            return false;
        }
        
        delay(50);
        statusVar = 0;
    }
    
    return false;
}

void Licht::flits(int vertraag) {
    loopje = 1;
    while(loopje == 1) {
        digitalWrite(_pin, HIGH) ;
        delay(vertraag);
        digitalWrite(_pin, LOW);
        delay(vertraag);
    }
}
