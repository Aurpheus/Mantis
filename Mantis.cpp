//
// Created by Baptiste on 15/12/2023.
//

#include "Mantis.h"

//constructor
Mantis::Mantis() {
    name = "Lurantis~";
    age = 0;
    hunger = 0;
    stage = 0;
    weight = 20;
    behaviour = 0;
    hours_passed = 0;
    is_dead = false;
    happiness_prct = 50;
}

Mantis::Mantis(char *name) {
    this->name = name;
    age = 0;
    hunger = 0;
    stage = 0;
    weight = 20;
    behaviour = 0;
    hours_passed = 0;
    is_dead = false;
    happiness_prct = 50;
}

//all args constructor
Mantis::Mantis(char *name ,long age, int hunger, int stage, int behaviour) {
    this->age = age;
    this->hunger = hunger;
    this->stage = stage;
    this->behaviour = behaviour;
    this->name = name;
    hours_passed = 0;
    weight = 20;
    is_dead = false;
    happiness_prct = 50;
}

//setters
void Mantis::setAge(long age) {
    this->age = age;
}

void Mantis::setHunger(int hunger) {
    if (hunger > 100) {
        this->hunger = 100;
        this->weight -= 1;
    } else if (hunger == 100) {
        this->hunger = 100;
    } else if (hunger < 0){
        this->hunger = 0;
    }else{
        this->hunger = hunger;
    }
}

void Mantis::setStage(int stage) {
    this->stage = stage;
}

void Mantis::setBehaviour(int behaviour) {
    this->behaviour = behaviour;
}

char* Mantis::getName() const{
    return name;
}

void Mantis::setIs_dead(bool is_dead) {
    this->is_dead = is_dead;
}

//getters

long Mantis::getAge() const {
    return age;
}

int Mantis::getHunger() const {
    return hunger;
}

int Mantis::getStage() const {
    return stage;
}

int Mantis::getBehaviour() const {
    return behaviour;
}

double Mantis::getWeight() const {
    return weight;
}

bool Mantis::isDead() const {
    return is_dead;
}

void Mantis::hour_pass() {
    setHunger(getHunger()+1);
    setWeight(getWeight()-0.4);

    if(weight<=0){
        this->is_dead = true;
    }

    hours_passed++;
    evolve();
    if(hours_passed%24==0){
        age++;
        hours_passed=0;
        if (age%96==0 && happiness_prct<75){
             this->is_dead = true;
        }
    }
}

//function to get the next stage of the mantis
//using the stage number, the weight and the happiness
//the mantis will evolve to the next stage
void Mantis::evolve() {
    if (stage == 0 && weight >= 50 && happiness_prct >= 50) {
        stage++;
    } else if (stage == 1 && weight >= 100 && happiness_prct >= 50) {
        stage++;
    } else if (stage == 2 && weight >= 150 && happiness_prct >= 50) {
        stage++;
    }
}


char *Mantis::getStageName() const {
    switch (stage) {
        case 0:
            return "Egg";
        case 1:
            return "Nymph";
        case 2:
            return "Adult";
        case 3:
            return "Elder";
        default:
            return "Egg";
    }
}

char *Mantis::getBehaviourName() const {
    switch (behaviour) {
        case 0:
            return "Scaredy-cat";
        case 1:
            return "Heavy_eater";
        case 2:
            return "Chill-out";
        case 3:
            return "Curious";
        default:
            return "Passive";
    }
}

void Mantis::feed(int prct_value) {
    setHunger(getHunger()-prct_value);
    weight += prct_value/2;
    happiness_prct += prct_value/2;
}

void Mantis::setWeight(double d) {
    if(d<0){
        d=0;
    }

}

int Mantis::getHappiness() const {
    return happiness_prct;
}
