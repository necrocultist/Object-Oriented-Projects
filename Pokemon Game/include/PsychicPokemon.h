/* @Author
Student Name: Kaan Karataş
Student ID : 150200081
Date: 05.05.2023
*/

#ifndef PSYCHICPOKEMON_H
#define PSYCHICPOKEMON_H

#include <iostream>
#include <stdio.h>
#include "Pokemon.h"

class PsychicPokemon : public Pokemon {
    public:
        PsychicPokemon(std::string name, int hp, int damage);   // used constructor for psychic pokemon
        int attack();  // implemetation of base method

        bool getCanConfuse() const { return m_canConfuse; };    // returns true if pokemon can confuse
        void setCanConfuse(bool canConfuse) { m_canConfuse = canConfuse; }; // sets the confusion power
    private:
        bool m_canConfuse = false;  // to control if a psychic pokemon can confuse or not
};

#endif