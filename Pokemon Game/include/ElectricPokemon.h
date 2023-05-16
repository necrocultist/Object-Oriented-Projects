/* @Author
Student Name: Kaan Karataş
Student ID : 150200081
Date: 05.05.2023
*/

#ifndef ELECTRICPOKEMON_H
#define ELECTRICPOKEMON_H

#include <iostream>
#include <stdio.h>
#include "Pokemon.h"

class ElectricPokemon : public Pokemon {
    public:
        ElectricPokemon(std::string name, int hp, int damage);    // used constructor for electric pokemon
        int attack();  
        bool getConfuse() const { return m_isConfused; };   // returns true if pokemon is in confusion state
        void confuse();  // sets the pokemon to confused state and starts the counter
    private:
        bool m_isConfused = false;  // confusion state
        int m_confusionCount = 0;   // the confusion counter
};

#endif