/* @Author
Student Name: Kaan Karataş
Student ID : 150200081
Date: 05.05.2023
*/

#include <iostream>
#include <stdio.h>
#include "ElectricPokemon.h"
#include "PsychicPokemon.h"

class Arena {
    public:
        void addPokemon(char type, std::string name , int hp, int damage);      // adds a pokemon by checking its type with type argument and calls corresponding constructor
        void simulateBattle();      // to simulate battles between 1 electric pokemon and 1 psychic pokemon
    private:
        void controlTerrain(int&);  // controls terrain and decide to spawn a random one if necessery
        void spawnTerrain();    // spawns a random throwing a die and checking its value
        void restartTerrain() { m_terrain = "none"; };  // resets terrain to none

        void informPokemons() const;    // informs pokemons whether they are on their own terrain
        void duelPokemons(int) const;    // pokemons attack and confuse each other according to the random variable defined in simulateBattle

        void printRoundStats(int, int) const;   // prints stats of pokemon, power ups and first attacking pokemon on each round
        void checkPowerUp() const;      // checks power up visibility of each pokemon, prints if visible and turns of power up visibility
        void printMatchResults() const;     // prints match results after a battle ends by checking which pokemon is dead

        std::string m_terrain = "none";
        ElectricPokemon* mp_electricPokemon = nullptr;
        PsychicPokemon* mp_psychicPokemon = nullptr;
};