//
// Created by Baptiste on 15/12/2023.
//

#include "Terrarium.h"

//constructor
Terrarium::Terrarium() {
    humidity_prct = 50;
    mantis = new Mantis();
}

//all args constructor
Terrarium::Terrarium(int humidity_prct, Mantis *mantis)  {
    this->humidity_prct = humidity_prct;
    this->mantis = mantis;
}

//setters
void Terrarium::setHumidity_prct(int humidity_prct) {
    if (humidity_prct > 100) {
        this->humidity_prct = 100;
    }else if (humidity_prct < 0) {
        this->humidity_prct = 0;
        this->mantis->setIs_dead(true);
    }else
        this->humidity_prct = humidity_prct;
}

void Terrarium::setMantis(Mantis *mantis) {
    this->mantis = mantis;
}

//getters
int Terrarium::getHumidity_prct() const {
    return humidity_prct;
}

Mantis *Terrarium::getMantis() const {
    return mantis;
}

void Terrarium::hour_pass() {
    setHumidity_prct(getHumidity_prct() - 1);
    mantis->hour_pass();
}

void Terrarium::spray(int prct_value) {
    setHumidity_prct(getHumidity_prct() + prct_value);
}