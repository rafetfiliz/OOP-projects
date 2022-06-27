//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname: Rafet Filiz
//---Student Number: 150200028
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
//-------------Do Not Add Change Header Include Paths-------------/

#include <iostream>
using namespace std;
#include "Robot.h"



/*
****************
BEGIN: ROBOT CLASS FUNCTION DECLARATIONS 
****************
*/
int Robot::unqID = 0;
float Explorer::totalExploredArea = 0;
int Explorer::totalNumberOfSeleniumArea = 0;
int Miner::totalGatheredSelenium = 0;

Robot::Robot(string& _type, float _speed, int _durability, int _manufacture, float _maintenance)
                                                    :RobotType(_type), manufactureCost(_manufacture){
    this->speed = _speed;
    this->durability = _durability;
    this->maintenanceCost = _maintenance;
    this->canMove = true;
    string name;

    if (_type == "explorer")
    {
        name = "exp-" + to_string(unqID);
    }
    else if (_type == "miner"){
        name = "mnr-" + to_string(unqID);
    }

    this->RobotName = name;
}

void Robot::operator=(const Robot& copyRobot){
    this->RobotName = copyRobot.RobotName;
    this->speed = copyRobot.speed;
    this->durability = copyRobot.durability;
    this->maintenanceCost = copyRobot.maintenanceCost;
    this->canMove = copyRobot.canMove;
}

const void Robot::showInfo(){
    cout << "Name: " << this->RobotName << endl;
    cout << "Type: " << this->RobotType << endl;
    cout << "Speed: " << this->speed << endl;
    cout << "Durability: " << this->durability << endl;
    cout << "ManufactureCost: " << this->manufactureCost << endl;
    cout << "MaintenanceCost: " << this->maintenanceCost << endl;
    cout << "Can Move: " << this->canMove << endl;
}

const bool Robot::getCanMove(){
    return this->canMove;
}

const float Robot::getMaintenanceCost(){
    return this->maintenanceCost;
}

const string Robot::getName(){
    return this->RobotName;
}

const float Robot::getSpeed(){
    return this->speed;
}

const int Robot::getDurability(){
    return this->durability;
}

const string Robot::getType(){
    return this->RobotType;
}

const int Robot::getUnqID(){
    return Robot::unqID;
}

const void Robot::setCanMove(bool movement){
    this->canMove = movement;
}

const void Robot::setDurability(int _durability){
    this->durability = _durability;
}

const void Robot::setUnqID(int num){
    Robot::unqID = num;
}

const void Robot::setName(string newName){
    this->RobotName = newName;
}

/*
****************
END: ROBOT CLASS FUNCTION DECLARATIONS 
****************
*/


/*
****************
BEGIN: EXPLORER CLASS FUNCTION DECLARATIONS 
****************
*/
Explorer::Explorer(string& _type, float _speed, int _durability) : Robot(_type, _speed, _durability, 3000, 450.0/_speed){
    this->exploredArea = 0;
    this->detectedSelenium = false;
}

const bool Explorer::move(){
    return this->getCanMove();
}

void Explorer::explore(){
    int number = rand() % 101;
    if(number >= 40){
        this->detectedSelenium = true;
        Explorer::totalNumberOfSeleniumArea += 1;
    }
    else{
        this->detectedSelenium = false;
    }
    Explorer::totalExploredArea += 1500;
    this->exploredArea = 1500;
}

void Explorer::operator=(const Explorer& copyRobot){
    this->Robot::operator=(copyRobot);
    this->exploredArea = copyRobot.exploredArea;
    this->detectedSelenium = copyRobot.detectedSelenium;
}

const void Explorer::showInfo(){
    this->Robot::showInfo();
    cout << "explored area: " << this->exploredArea << endl;
}

const float Explorer::getExploredArea(){
    return this->exploredArea;
}

const void Explorer::setExploredArea(float area){
    this->exploredArea = area;
}
/*
****************
END: EXPLORER CLASS FUNCTION DECLARATIONS 
****************
*/

/*
****************
BEGIN: MINER CLASS FUNCTION DECLARATIONS 
****************
*/
Miner::Miner(string& _type, float _speed, int _durability) : Robot(_type, _speed, _durability, 5000, 750.0/_speed){
    this->gatheredSelenium = 0;
}

void Miner::mine(){
    if (Explorer::totalNumberOfSeleniumArea > 0){
        float randomNum = (10 + (rand() % 91)) * 5;
        this->gatheredSelenium = randomNum;
        Miner::totalGatheredSelenium += randomNum;
        Explorer::totalNumberOfSeleniumArea -= 1;    
    }
}

const bool Miner::move(){
    if(this->getCanMove() == true && Explorer::totalNumberOfSeleniumArea > 0){
        return true;      
    }
    else
        return false;
}

void Miner::operator=(const Miner& copyRobot){
    this->Robot::operator=(copyRobot);
    this->gatheredSelenium = copyRobot.gatheredSelenium;
}

const void Miner::showInfo(){
   this->Robot::showInfo();
   cout << "# of gathered selenium: " << this->gatheredSelenium << endl; 
}

const int Miner::getGatheredSelenium(){
    return this->gatheredSelenium;
}

const void Miner::setGatheredSelenium(int value){
    this->gatheredSelenium = value;
}
/*
****************
END: MINER CLASS FUNCTION DECLARATIONS 
****************
*/

