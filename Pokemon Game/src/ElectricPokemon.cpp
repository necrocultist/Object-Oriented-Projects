/* @Author
Student Name: Kaan Karataş
Student ID : 150200081
Date: 05.05.2023
*/

#include <iostream>
#include <stdio.h>
#include "ElectricPokemon.h"

// used constructor for electric pokemon
ElectricPokemon::ElectricPokemon(std::string name, int hp, int damage) : Pokemon(name, hp, damage, 2, 3) {
    std::cout << "Electric Pokemon " << name << " has entered the arena." << std::endl;

    std::cout << "\tClass: Electric" << std::endl;
    std::cout << "\tName: " << name << std::endl;
    std::cout << "\tHP: " << hp << std::endl;
    std::cout << "\tDamage: " << damage << std::endl;
    std::cout << std::endl << std::endl;
}

// sets the pokemon to confused state and starts the counter
void ElectricPokemon::confuse() {
    m_isConfused = true;
    m_confusionCount = 3;
}

// implemetation of base method
int ElectricPokemon::attack() {
    if (isFainted)  return 0;   // if pokemon is fainted return with no damage

    // if pokemon is on own terrain, set confusion count to 0 and set confused state to fasle
    if (isOwnTerrain) {
        m_confusionCount = 0;
        m_isConfused = false;
    }
    
    if(m_confusionCount == 0) m_isConfused = false;     // if confusion count is 0, set confused state to false

    // if confused, decrease counter and return with no damage
    if(m_isConfused) {
        m_confusionCount--;
        return 0;
    }

    if (powerUpCount >= rechargeDuration)   attemptPowerUp();    // if counter is greater than reharge duration, attempt power up
    
    // checks if the pokemon is in power up state, if so, transitions from power up state and returns 3 times damage
    if (isPoweredUp) {
        isPoweredUp = false;
        return 3 * damage;
    }

    powerUpCount++; // if not in power up state, increase counter

    return damage;
}