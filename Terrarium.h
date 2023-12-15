//
// Created by Baptiste on 15/12/2023.
//

#ifndef MANTIS_TERRARIUM_H
#define MANTIS_TERRARIUM_H

#include "Mantis.h"


class Terrarium {
    int humidity_prct;

    Mantis* mantis;

    public:
        //constructor
        Terrarium();

        //all args constructor
        Terrarium(int humidity_prct, Mantis* mantis);

        //setters
        void setHumidity_prct(int humidity_prct);
        void setMantis(Mantis* mantis);

        //getters
        int getHumidity_prct() const;
        Mantis* getMantis() const;

        void hour_pass();

        void spray(int prct_value);

};


#endif //MANTIS_TERRARIUM_H
