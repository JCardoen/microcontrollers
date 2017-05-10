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
    digitalWrite(_pin, LOW);
    loopje = 0;
}

boolean Licht::leesKnop() {
    pinMode(_pin, INPUT_PULLUP);
    
    if(digitalRead(_pin) == LOW) {
        statusVar = 1;
        
        if(statusVar == 1) {
            return true;
        }
    } 
    
    delay(20);
    return false;
}

void Licht::toggle() {
    if(digitalRead(_pin) == LOW) {
        digitalWrite(_pin, HIGH);
    }
    else {
        digitalWrite(_pin, LOW);
    }
}

void Licht::flits(int vertraag) {
    digitalWrite(_pin, HIGH) ;
    delay(vertraag);
    digitalWrite(_pin, LOW);
}
