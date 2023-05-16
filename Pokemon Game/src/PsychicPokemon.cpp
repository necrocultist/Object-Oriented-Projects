/* @Author
Student Name: Kaan Karataş
Student ID : 150200081
Date: 05.05.2023
*/

#include <iostream>
#include <stdio.h>
#include "PsychicPokemon.h"

// used constructor for psychic pokemon
PsychicPokemon::PsychicPokemon(std::string name, int hp, int damage) : Pokemon(name, hp, damage, 3, 5) {
    std::cout << "Psychic Pokemon " << name << " has entered the arena." << std::endl;

    std::cout << "Class: Psychic" << std::endl;
    std::cout << "\tName: " << name << std::endl;
    std::cout << "\tHP: " << hp << std::endl;
    std::cout << "\tDamage: " << damage << std::endl;
    std::cout << std::endl << std::endl;
}

// implemetation of base method
int PsychicPokemon::attack() {
    if (isFainted) return 0;   // if pokemon is fainted return with no damage

    if (powerUpCount >= rechargeDuration) attemptPowerUp();    // if counter is greater than reharge duration, attempt power up
    else    powerUpCount++;     // if not in power up state, increase counter

    // checks if the pokemon is in power up state, if so, transitions from power up state to can confuse state
    if (isPoweredUp) {
        isPoweredUp = false;
        m_canConfuse = true;
    } else {
        m_canConfuse = false;
    }

    return (isOwnTerrain ? 2 : 1) * damage;     // if is on own terraşn, return 2 times damage
}