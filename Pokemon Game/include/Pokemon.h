/* @Author
Student Name: Kaan Karataş
Student ID : 150200081
Date: 05.05.2023
*/

#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <stdio.h>

class Pokemon {
public:
    // member initializer list for Pokemon class
    Pokemon(std::string name, int hp, int damage, unsigned int powerUpChance, unsigned int rechargeDuration) :
        damage{damage}, powerUpChance{powerUpChance}, rechargeDuration{rechargeDuration}, m_name{name}, m_hp{hp} {};

    std::string getName() const { return m_name; }; // inline getter
    bool getPowerUp() const { return isPowerUpVisible; }    // inline getter
    int getHP() const { return m_hp; }; // inline getter

    void setOwnTerrain(bool ownTerrain) { isOwnTerrain = ownTerrain; }; // to inform pokemons 
    void turnOffPowerUpVisibility() { isPowerUpVisible = false;}; // used in order to update power up visibility from outside the class
    void takeDamage(int damage);    // main hp decrease methpd for pokemons
protected:
    void attemptPowerUp();  // rolls a die and attempts power up

    const int damage;

    const unsigned int powerUpChance;
    const unsigned int rechargeDuration;

    unsigned int powerUpCount = rechargeDuration;   // TODO
    bool isPoweredUp = false;   
    bool isPowerUpVisible = false;  // visibility of power up outside the class, used in order to print power up in round stats without reaching isPoweredUp variable
    bool isOwnTerrain = false;

    bool isFainted = false;
private:
    const std::string m_name;
    int m_hp;
};

#endif