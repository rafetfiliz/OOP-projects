//--- 2021-2022 Summer Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname: Rafet Filiz
//---Student Number: 150200028
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "pokemon.h"

using namespace std;

//-------------You Can Add Your Functions Down Below-------------//
pokemon::pokemon(){
    name = "";
    hpValue = 100;
    atkValue = 0;
}

pokemon::pokemon(string pokemonName, const int attackValue){
    name = pokemonName;
    atkValue = attackValue;
    hpValue = 100;
}

pokemon::pokemon(const pokemon& p){
    name = p.name;
    atkValue = p.atkValue;
    hpValue = p.hpValue;
}

const string pokemon::getName(){
    return name;
}

const int pokemon::gethpValue(){
    return hpValue;
}

const int pokemon::getatkValue(){
    return atkValue;
}

//////////////////////////////////////////////

pokedex::pokedex(){
    value = 0;
}

void pokedex::updatePokedex(pokemon p){
    if (value == 0){
        pokedexArray[value] = p;
        value += 1;
    }
    else{
        int counter = 0;
        for(int i = 0;i<value;i++){
            if(pokedexArray[i].getName() == p.getName()){
                counter += 1;
            }
        }
        if(counter == 0){
            pokedexArray[value] = p;
            value += 1;
        }
    }
}

const void pokedex::printPokedex(){
    for(int i = 0;i<value;i++){
        cout << pokedexArray[i].getName() << endl;
    }
}

//////////////////////////////////////////////

player::player(){
    name = "";
    pokemonNumber = 0;
    pokeballNumber = 10;
    badgeNumber = 0;
}

player::player(string playerName, pokemon p){
    name = playerName;
    playerPokemon = p;
    pokemonNumber = 0;
    badgeNumber = 0;
    pokeballNumber = 10;
}

const int player::showPokemonNumber(){
    return pokemonNumber;
}

const int player::showPokeballNumber(){
    return pokeballNumber;
}

const int player::showBadgeNumber(){
    return badgeNumber;
}

pokemon player::getPokemon(){
    return playerPokemon;
}

const void player::battleWon(){
    badgeNumber += 1;
    pokeballNumber += 3;
}

const void player::catchPokemon(){
    pokemonNumber += 1;
    pokeballNumber -= 1;
}

//////////////////////////////////////////////

enemy::enemy(){
    name = "";
}

enemy::enemy(string enemyName, pokemon p){
    name = enemyName;
    enemyPokemon = p;
}

const pokemon enemy::getPokemon(){
    return enemyPokemon;
}

const string enemy::getName(){
    return name;
}