/* @Author
Student Name: Kaan Karataş
Student ID : 150200081
Date: 05.05.2023
*/

#include <iostream>
#include <stdio.h>
#include "Pokemon.h"

// main hp decrease methpd for pokemons
void Pokemon::takeDamage(int damage) {
    m_hp -= damage; // decrease hp equal to the amount attacked

    // if hp is negative, set hp to zero and set faint condition
    if (m_hp <= 0) {
        m_hp = 0;
        isFainted = true;
    }
}

// rolls a die and attempts power up
void Pokemon::attemptPowerUp() {
    unsigned int powerUpDie = rand() % 10;  // random die

    // if die is between 0 and power up chance, reset power up counter and set power up variables
    if(powerUpDie < powerUpChance) {    
        isPoweredUp = true;
        isPowerUpVisible = true;
        powerUpCount = 0;
    }
}