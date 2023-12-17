//
// Created by Baptiste on 15/12/2023.
//

#ifndef MANTIS_MANTIS_H
#define MANTIS_MANTIS_H

#include <Gamebuino-Meta.h>


class Mantis {

    long age;
    int hunger;
    int stage;
    int behaviour;
    char* name;
    int hours_passed;
    bool is_dead;
    int x;
    int y;
    bool flip;
    bool rotated;

    int moveEveryXTicks;
    int ticksSinceLastMove;

    //where does she try to go
    int direction;


    double weight;
    //if not happy mantis will hide
    int happiness_prct;

    public:
        //constructor
        Mantis();

        Mantis(char* name);

        //all args constructor
        Mantis(char* name , long age, int hunger, int stage, int behaviour);

        //setters
        void setAge(long age);
        void setHunger(int hunger);
        void setStage(int stage);
        void setBehaviour(int behaviour);
        void setIs_dead(bool is_dead);
        void setPos(int x, int y);
        void setMoveEveryXTicks(int moveEveryXTicks);


        //getters
        long getAge() const;
        int getHunger() const;
        int getStage() const;
        char* getStageName() const;
        int getBehaviour() const;
        char* getBehaviourName() const;
        char* getName() const;
        double getWeight() const;
        int getHappiness() const;
        int getX() const;
        int getY() const;
        char *getDirection() const;
        bool isFlipped() const;
        bool isRotated() const;



        void hour_pass();

        bool isDead() const;

        void feed(int prct_value);

        void rollNewDirection();

        void move(bool canMoveUp, bool canMoveDown, bool canMoveLeft, bool canMoveRight);

    void setWeight(double d);

    void evolve();
};


#endif //MANTIS_MANTIS_H
