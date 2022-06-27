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
#include <fstream>

#include "pokemon.h"

using namespace std;

//-------------Do Not Change These Global Variables-------------//
int NAME_COUNTER = 0;   //Use this to keep track of the enemy names
int POK_COUNTER = 0;    //Use this to keep track of the pokemon names
int PLAYER_POKEMON_ATTACK = 20; //You don't have to use this variable but its here if you need it
int ENEMY_POKEMON_ATTACK = 10;  //You don't have to use this variable but its here if you need it
//--------------------------------------------------------------//

//---If Necessary Add Your Global Variables Here---// 
// 
//
//
//-------------------------------------------------//

//-------------Do Not Change These Function Definitions-------------//
string* readEnemyNames(const char*);
string* readPokemonNames(const char*);
player characterCreate(string, int);
void mainMenu();
void fightEnemy(player*, string*, string*);
void catchPokemon(player*, string*);
//------------------------------------------------------------------//

//---If Necessary Add Your Function Definitions Here---// 
//
//
//
//-----------------------------------------------------//

//-------------Do Not Change This Function-------------//
int main(int argc, char* argv[]){
	system("clear");

    //---Creating Enemy and Pokemon Name Arrays---//
    string* enemyNames = readEnemyNames(argv[1]);         
    string* pokemonNames = readPokemonNames(argv[2]);
    

    string playerName;
    int pokemonChoice;

    cout << "Welcome to the Pokemon Game! \n" << endl;
    cout << "Please enter your name: "; 
    cin >> playerName;
    cout << "Please choose one of these pokemons as your pokemon: \n1- Bulbasaur \n2- Charmender \n3- Squirtle \nChoice: ";
    cin >> pokemonChoice;

    //---Character Creation--//
    player newPlayer = characterCreate(playerName, pokemonChoice);
    
    int menuChoice;

    while(true){
        mainMenu(); 
        cin>>menuChoice;

        switch (menuChoice){
        case 1:
            fightEnemy(&newPlayer, enemyNames, pokemonNames);
            break;
        case 2:
            catchPokemon(&newPlayer, pokemonNames);
            break;
        case 3:
            cout<<newPlayer.showPokemonNumber()<<endl;
            break;
        case 4:
            cout<<newPlayer.showPokeballNumber()<<endl;
            break;
        case 5:
            cout<<newPlayer.showBadgeNumber()<<endl;
            break;
        case 6:
            cout << endl;
            cout << "------- Pokedex -------" <<endl;
            newPlayer.playerPokedex.printPokedex();
            break;
        case 7:
            //---Deletes Dynamic Arrays From Memory and Exits---//
            delete[] enemyNames;
            delete[] pokemonNames;
            return EXIT_SUCCESS;
            break;
  
        default:
            cout << "Please enter a valid number!!!" << endl;
            break;
        }
    }
    return EXIT_FAILURE;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string* readEnemyNames(const char* argv){
    //---Code Here---//
    fstream inFile;
    inFile.open(argv);
    int num;
    inFile >> num;

    string* enemyString = new string[num];
    string dummy;
    getline(inFile, dummy);

    for(int i = 0; i<num; i++){
        string tempStr;
        getline(inFile, tempStr);
        enemyString[i] = tempStr;
    }
    inFile.close();
    return enemyString;
    //---------------//   
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string* readPokemonNames(const char* argv){
    //---Code Here---//
    fstream inFile;
    inFile.open(argv);
    int num;
    inFile >> num;

    string* pokemonString = new string[num];
    string dummy;
    getline(inFile, dummy);

    for(int i = 0; i<num; i++){
        string tempStr;
        getline(inFile, tempStr);
        pokemonString[i] = tempStr;
    }
    inFile.close();
    return pokemonString;
    //---------------//
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
player characterCreate(string playerName, int pokemonChoice){
    //---Code Here---//
    string pokemonName;
    if(pokemonChoice == 1)
        pokemonName = "Bulbasaur";
    else if (pokemonChoice == 2)
        pokemonName = "Charmender";
    else if (pokemonChoice == 3)
        pokemonName = "Squirtle";
    
    pokemon playerPokemon(pokemonName, 20);
    player myPlayer(playerName, playerPokemon);
    return myPlayer;
    //---------------//
};
//--------------------------------------------//

//-------------Do Not Change This Function-------------//
void mainMenu(){
    cout << endl;
    cout << "-------- Menu --------" << endl;
    cout << "1. Fight for a badge" << endl;
    cout << "2. Catch a Pokemon" << endl;
    cout << "3. Number of Pokemons" << endl;
    cout << "4. Number of Pokeballs " << endl;
    cout << "5. Number of Badges" << endl;
    cout << "6. Pokedex" << endl;
    cout << "7. Exit" << endl;
    cout << endl;
    cout << "Choice: ";
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
void fightEnemy(player* newPlayer, string* enemyNames, string* pokemonNames){
    //---Code Here---//
    const string enemyPokemonName = pokemonNames[POK_COUNTER];
    const string enemyName = enemyNames[NAME_COUNTER];
    pokemon enemyPokemon(enemyPokemonName,10);
    enemy newEnemy(enemyName,enemyPokemon);
    newPlayer->playerPokedex.updatePokedex(enemyPokemon);

    cout << endl;
    cout << "You encounter with " << enemyName << " and his/hers pokemon " << enemyPokemonName << endl;
    cout << enemyPokemonName << " Health: " << enemyPokemon.gethpValue() << " Attack: " << enemyPokemon.getatkValue() << endl << endl;
    
    int enemyPokHp = enemyPokemon.gethpValue();
    int playerPokHp = newPlayer->getPokemon().gethpValue();
    int choice = 1;
    while(choice == 1){
        cout << "1- Fight" << endl << "2- Runaway" << endl;
        cout << "Choice: ";
        cin >> choice;

        if(choice == 2){
            POK_COUNTER += 1;
            NAME_COUNTER += 1;
            return;
        }
        enemyPokHp = enemyPokHp - PLAYER_POKEMON_ATTACK;
        playerPokHp = playerPokHp - ENEMY_POKEMON_ATTACK;
        cout << "Your Pokemons Health: " << playerPokHp << endl;
        cout << enemyName << " Pokemons Health: " << enemyPokHp << endl << endl;

        if(enemyPokHp == 0){
            cout << "You Won!" << endl;
            newPlayer->battleWon();
            NAME_COUNTER += 1;
            POK_COUNTER += 1;
            choice = 2;
        }
    }
    return;
    //---------------//
};
//--------------------------------------------//

//-------------Code This Function-------------//
void catchPokemon(player* newPlayer, string* pokemonNames){
    //---Code Here---//
    string pokemonName = pokemonNames[POK_COUNTER];
    pokemon newPokemon(pokemonName,10);
    newPlayer->playerPokedex.updatePokedex(newPokemon);

    int choice;
    cout << "You encounter with " << pokemonName << " Health: 100 Attack: 10" << endl;
    cout << "1- Catch" << endl << "2- Runaway" << endl;
    cout << "Choice: ";
    cin >> choice;

    if(choice == 1){
        newPlayer->catchPokemon();
        cout << "You catch " << pokemonName << endl;
    }
    POK_COUNTER += 1;
    return;
    //---------------//
};
//--------------------------------------------//
