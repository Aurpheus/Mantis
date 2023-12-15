//
// Created by Baptiste on 15/12/2023.
//

#ifndef MANTIS_MANTIS_H
#define MANTIS_MANTIS_H


class Mantis {

    long age;
    int hunger;
    int stage;
    int behaviour;
    char* name;
    int hours_passed;
    bool is_dead;

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


        void hour_pass();

        bool isDead() const;

        void feed(int prct_value);

    void setWeight(double d);

    void evolve();
};


#endif //MANTIS_MANTIS_H
