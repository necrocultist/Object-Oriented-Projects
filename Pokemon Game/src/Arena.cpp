/* @Author
Student Name: Kaan Karataş
Student ID : 150200081
Date: 05.05.2023
*/

#include <iostream>
#include <stdio.h>
#include "Arena.h"

// adds a pokemon by checking its type with type argument and calls corresponding constructor
void Arena::addPokemon(char type, std::string name, int hp, int damage) {
    // if type is e call electric pokemon constructor
    if (type == 'e') {
        mp_electricPokemon = new ElectricPokemon(name, hp, damage);
    }
    // if type is p call psychic pokemon 
    else if (type == 'p') {
        mp_psychicPokemon = new PsychicPokemon(name, hp, damage);
    }
}

// to simulate battles between one electric pokemon and one psychic pokemon
void Arena::simulateBattle() {
    int round = 1;  // default round definiton
    int terrainCount = 0;   // to save terrain

    restartTerrain();   // reset terrain before a battle

    // loop until a pokemon dies
    while(mp_electricPokemon->getHP() > 0 && mp_psychicPokemon->getHP() > 0) {
        
        controlTerrain(terrainCount);   // in each iteration, control terrain and decide to spawn a random one if necessery

        informPokemons();   // informs pokemons whether they are on their own terrain

        int firstPokemon = rand() % 2;  // random die to decide first attacking pokemon

        duelPokemons(firstPokemon); // pokemons attack each other, firstPokemon goes first

        printRoundStats(round, firstPokemon);   // print stats for the current iteration
        
        round++;    // increase round counter
        terrainCount++;
    }

    printMatchResults();    // after a pokemon dies, print match results

    delete mp_electricPokemon;  // delete dynamicly allocated memory after a battle to prevent memory leak
    delete mp_psychicPokemon;   // delete dynamicly allocated memory after a battle to prevent memory leak
}

// controls terrain and decide to spawn a random one if necessery
void Arena::controlTerrain(int &terrainCount) {
    if(m_terrain == "none" || terrainCount == 5) {
        spawnTerrain();
        terrainCount = 0;
    }
}

// spawns a random throwing a die and checking its value
void Arena::spawnTerrain() {
    int terrainDie = rand() % 10;   // throw a random die

    // if die is smaller than 2 (%20) spawn electric terrain and reset counter
    if(terrainDie < 2) {
        m_terrain = "electric";
    }
    // if die is smaller than 4 and bigger than 2 (%20) spawn psychic terrain and reset counter
    else if(terrainDie < 4) {
        m_terrain = "psychic";
    }
    // else spawn none (%60) and reset counter when necessery
    else {
        m_terrain = "none";
    }
}

// informs pokemons whether they are on their own terrain
void Arena::informPokemons() const {

    mp_electricPokemon->setOwnTerrain(m_terrain == "electric");
    mp_psychicPokemon->setOwnTerrain(m_terrain == "psychic");
}

// pokemons attack and confuse each other according to the random variable defined in simulateBattle
void Arena::duelPokemons(int firstPokemon) const {
    // electric attacks first
    if(firstPokemon == 0) {
        mp_psychicPokemon->takeDamage(mp_electricPokemon->attack());    // decrease hp of psychic by the amount of current attack damage of electric
        mp_electricPokemon->takeDamage(mp_psychicPokemon->attack());    // decrease hp of electric by the amount of current attack damage of psychic
        if(mp_psychicPokemon->getCanConfuse())  mp_electricPokemon->confuse();   // set electric to confuse if psychic can confuse
    }
    // psychic attacks first
    else {
        mp_electricPokemon->takeDamage(mp_psychicPokemon->attack());    // decrease hp of electric by the amount of current attack damage of psychic
        if(mp_psychicPokemon->getCanConfuse())  mp_electricPokemon->confuse();   // set electric to confuse if psychic can confuse
        mp_psychicPokemon->takeDamage(mp_electricPokemon->attack());    // decrease hp of psychic by the amount of current attack damage of electric
    }
}

// prints stats of pokemon, power ups and first attacking pokemon on each round
void Arena::printRoundStats(int round, int heads) const {
    std::string firstPokemon = (heads == 0) ? mp_electricPokemon->getName() : mp_psychicPokemon->getName(); // if die is 0 electric goes first, if 1 psychic goes first

    //  sets leading pokemon to the one with more HP
    std::string leadPokemon = (mp_electricPokemon->getHP() > mp_psychicPokemon->getHP()) ? mp_electricPokemon->getName() : mp_psychicPokemon->getName();
    
    std::cout << "Round: " << round << std::endl;
    std::cout << "Current Terrain " << m_terrain << std::endl;
    std::cout << firstPokemon << " goes first" << std::endl;

    checkPowerUp(); // check if a pokemons has initiated a power up and print it

    std::cout << mp_electricPokemon->getName() << " HP: " << mp_electricPokemon->getHP() << std::endl;
    std::cout << mp_psychicPokemon->getName() << " HP: " << mp_psychicPokemon->getHP() << std::endl;
    std::cout << leadPokemon << " is in the lead!" << std::endl;
    std::cout << std::endl;
}

// checks power up visibility of each pokemon, prints if visible and turns of power up visibility
void Arena::checkPowerUp() const {
    // if electric has initiated a power up, print it and turn of the visibility for curren round
    if(mp_electricPokemon->getPowerUp()) {
        std::cout << mp_electricPokemon->getName() << " has initiated a power up." << std::endl;
        mp_electricPokemon->turnOffPowerUpVisibility();
    }
    // if psychic has initiated a power up, print it and turn of the visibility for curren round
    if(mp_psychicPokemon->getPowerUp()) {
        std::cout << mp_psychicPokemon->getName() << " has initiated a power up." << std::endl;
        mp_psychicPokemon->turnOffPowerUpVisibility();
    }
}

// prints match results after a battle ends by checking which pokemon is dead
void Arena::printMatchResults() const {
    // sets the winner pokemon to the one that does not have 0 HP
    std::string winnerPokemon = (mp_electricPokemon->getHP() == 0) ? mp_psychicPokemon->getName() : mp_electricPokemon->getName();

    std::cout << "Match Results:" << std::endl;
    std::cout << winnerPokemon << " has won the match!" << std::endl;
    std::cout << std::endl;
}