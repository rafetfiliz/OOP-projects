//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname: Rafet Filiz
//---Student Number: 150200028
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
//-------------Do Not Add Change Header Include Paths-------------//
#include "CommandCenter.h"
#include "Robot.h"
#include <iostream>
using namespace std;
/*
****************
BEGIN: CREW CLASS FUNCTION DECLARATIONS 
****************
*/
Crew::Crew(int _maxExplorers, int _maxMiners, int _explorerCrewSize, int _minerCrewSize){
    crewManufactureCost = 0;
	crewMaintenanceCost = 0;

    if(_maxExplorers < 1 || _maxExplorers > 5)
        this->maxExplorers = 2;
    else
        this->maxExplorers = _maxExplorers;

    if(_maxMiners < 1 || _maxMiners > 5)
        this->maxMiners = 2;
    else
        this->maxMiners= _maxMiners;

    if(_explorerCrewSize < 0 || _explorerCrewSize > maxExplorers)
        explorerCrewSize = maxExplorers;
    else
        explorerCrewSize = _explorerCrewSize;

    if(_minerCrewSize < 0 || _minerCrewSize > maxMiners)
        minerCrewSize = maxMiners;
    else
        minerCrewSize = _minerCrewSize;
    

    this->ExplorerCrew = new Explorer*[maxExplorers];
    this->MinerCrew = new Miner*[maxMiners];

    for(int i = 0; i < explorerCrewSize; i++){
        string type = "explorer";
        Robot* newExp = manufactureRobot(type);
        ExplorerCrew[i] = new Explorer(type, newExp->getSpeed(), newExp->getDurability());
        crewManufactureCost += 3000;
        delete newExp;
    }

    for(int i = 0; i < minerCrewSize; i++){
        string type = "miner";
        Robot* newMnr = manufactureRobot(type);
        MinerCrew[i] = new Miner(type, newMnr->getSpeed(), newMnr->getDurability());
        crewManufactureCost += 5000;
        delete newMnr;
    }
}

Crew::~Crew(){
    for(int i = 0; i < explorerCrewSize; i++){
        if(ExplorerCrew[i] != NULL)
            delete ExplorerCrew[i];
    }
    delete[] ExplorerCrew;
    ExplorerCrew = NULL;

    for(int i = 0; i < minerCrewSize; i++){
        if(MinerCrew[i] != NULL)
            delete MinerCrew[i];
    }
    delete[] MinerCrew;
    MinerCrew = NULL;
}

Robot* Crew::manufactureRobot(string robotType){
    int robotDurability = 1 + (rand() % 5);
    float robotSpeed = 0;

    const float min = 1.5, max = 2.5;
    const float range = max - min;
    float random = range * ((((float) rand()) / (float) RAND_MAX)) + min; 
    if(robotType == "explorer"){
        robotSpeed = random;
        Explorer* newRobot = new Explorer(robotType, robotSpeed, robotDurability);
        newRobot->setCanMove(false);
        int newID = ExplorerCrew[0]->getUnqID() + 1;
        ExplorerCrew[0]->setUnqID(newID);
        return newRobot;
    }
    else {
        robotSpeed = (random + 0.5) / 2;
        Miner* newRobot = new Miner(robotType, robotSpeed, robotDurability);
        newRobot->setCanMove(false);
        int newID = ExplorerCrew[0]->getUnqID() + 1;
        ExplorerCrew[0]->setUnqID(newID);
        return newRobot;
    } 


}

Robot* Crew::manufactureRobot(){
    string robotType;
    cout << "Type:";
    cin >> robotType;

    int robotDurability = 1 + (rand() % 5);
    float robotSpeed = 0;

    const float min = 1.5, max = 2.5;
    const float range = max - min;
    float random = range * ((((float) rand()) / (float) RAND_MAX)) + min;
    if(robotType == "explorer"){
        robotSpeed = random;
        Explorer* newRobot = new Explorer(robotType, robotSpeed, robotDurability);
        newRobot->setCanMove(false);
        int newID = ExplorerCrew[0]->getUnqID() + 1;
        ExplorerCrew[0]->setUnqID(newID);
        return newRobot;
    }
    else{
        robotSpeed = (random + 0.5) / 2;
        Miner* newRobot = new Miner(robotType, robotSpeed, robotDurability);
        newRobot->setCanMove(false);
        int newID = ExplorerCrew[0]->getUnqID() + 1;
        ExplorerCrew[0]->setUnqID(newID);
        return newRobot;
    }  
}

void Crew::initMovement(){
    for(int i = 0; i < explorerCrewSize; i++)
        ExplorerCrew[i]->setCanMove(true);
    
    for(int i = 0; i < minerCrewSize; i++)
        MinerCrew[i]->setCanMove(true);
}

void Crew::updateDurability(){
    cout << "Explorer durability is being updated" << endl;
    
    for(int i = 0; i < explorerCrewSize; i++){
        if(ExplorerCrew[i]->getDurability() > 0){
            int newDurability = ExplorerCrew[i]->getDurability() - 1;
            ExplorerCrew[i]->setDurability(newDurability);
        }
        if(ExplorerCrew[i]->getDurability() == 0){
                string name = ExplorerCrew[i]->getName();
                operator-=(name);
            }
        }

    cout << "Miner durability is being updated" << endl;

    for(int i = 0; i < minerCrewSize; i++){
        if(MinerCrew[i]->getDurability() > 0){
            int newDurability = MinerCrew[i]->getDurability() - 1;
            MinerCrew[i]->setDurability(newDurability);
        }
        if(MinerCrew[i]->getDurability() == 0){
                string name = MinerCrew[i]->getName();
                operator-=(name);
            }
        }

}




void Crew::operator+=(Robot* newRobot){
    string typeExp = "explorer";
    string typeMnr = "miner";
        
    if(newRobot->getType() == typeExp)
    {
        if(explorerCrewSize == maxExplorers){
            cout << "This robot cannot be added, check maximum size of the crew" << endl;
            delete newRobot;
            return;
        }
        for(int i = 0; i<maxExplorers; i++){
            if(ExplorerCrew[i]){ 
            }
            else{
                ExplorerCrew[i] = new Explorer(typeExp, newRobot->getSpeed(), newRobot->getDurability());
                explorerCrewSize += 1;
                crewManufactureCost += 3000;
                int tempID = ExplorerCrew[i]->getUnqID();
                ExplorerCrew[i]->setUnqID(tempID);
                ExplorerCrew[i]->setCanMove(false);
                delete newRobot;
                break;
            }
        }
    } 

    else if(newRobot->getType() == typeMnr)
    {
        if(minerCrewSize == maxMiners){
            cout << "This robot cannot be added, check maximum size of the crew" << endl;
            delete newRobot;
            return;
        }
        for(int i = 0; i<maxMiners; i++){
            if(MinerCrew[i]){ 
            }
            else{
                MinerCrew[i] = new Miner(typeMnr, newRobot->getSpeed(), newRobot->getDurability());
                minerCrewSize += 1;
                crewManufactureCost += 5000;
                int tempID = MinerCrew[i]->getUnqID();
                MinerCrew[i]->setUnqID(tempID);
                MinerCrew[i]->setCanMove(false);
                delete newRobot;
                break;
            }
        }
    }        
}

void Crew::operator-=(const string deletedRobot){
    cout << deletedRobot << ": Goodbye" << endl;
    if(deletedRobot[0] == 'e'){
        if(explorerCrewSize > 1){
            
            Explorer **tempArray = new Explorer*[maxExplorers];
            int k = 0;
            string type = "explorer";
            for(int i = 0; i<explorerCrewSize; i++){
                if(ExplorerCrew[i]->getName() == deletedRobot){}
                else{
                    tempArray[k] = new Explorer(type, ExplorerCrew[i]->getSpeed(), ExplorerCrew[i]->getDurability());
                    tempArray[k]->setName(ExplorerCrew[i]->getName());
                    tempArray[k]->setExploredArea(ExplorerCrew[i]->getExploredArea());
                    k++;
                }
            }

            for(int i=0; i<explorerCrewSize; i++){ 
                delete ExplorerCrew[i];
            }
            delete[] ExplorerCrew;

            ExplorerCrew = tempArray;
            explorerCrewSize -= 1; 
           }
        }


    if(deletedRobot[0] == 'm'){
        if(minerCrewSize > 1){
            Miner **tempArray = new Miner*[maxMiners];
            int k = 0;
            string type = "miner";
            for(int i = 0; i<minerCrewSize; i++){
                if(MinerCrew[i]->getName() == deletedRobot){}
                else{
                    tempArray[k] = new Miner(type, MinerCrew[i]->getSpeed(), MinerCrew[i]->getDurability());
                    tempArray[k]->setName(MinerCrew[i]->getName());
                    tempArray[k]->setGatheredSelenium(MinerCrew[i]->getGatheredSelenium());
                    k++;
                }
            }

            for(int i=0; i<minerCrewSize; i++){ 
                delete MinerCrew[i];
            }
            delete[] MinerCrew;

            MinerCrew = tempArray;
            minerCrewSize -= 1;
            }
        }
        

}

const void Crew::showInfo(){
    cout << "explorerCrew Size:" << explorerCrewSize << endl;
    cout << "minerCrew Size:" << minerCrewSize << endl;

    for(int i = 0; i<explorerCrewSize; i++){
        ExplorerCrew[i]->showInfo();
    }
    for(int i = 0; i<minerCrewSize; i++){
        MinerCrew[i]->showInfo();
    }
    cout << "Total manufacture cost: " << crewManufactureCost << endl;
    cout << "Total maintenance cost: " << crewMaintenanceCost << endl;
}

const float Crew::getCrewMaintenanceCost(){
    return this->crewMaintenanceCost;
}

const void Crew::setCrewMaintenanceCost(float cost){
    this->crewMaintenanceCost = cost;
}

Explorer** Crew::getExplorers(){
    return ExplorerCrew;
}

Miner** Crew::getMiners(){
    return MinerCrew;
}

const int Crew::getExplorerCrewSize(){
    return this->explorerCrewSize;
}

const int Crew::getMinerCrewSize(){
    return this->minerCrewSize;
}

const int Crew::getCrewManufactureCost(){
    return this->crewManufactureCost;
}



/*
****************
END: CREW CLASS FUNCTION DECLARATIONS 
****************
*/

/*
****************
BEGIN: COMMANDCENTER CLASS FUNCTION DECLARATIONS 
****************
*/
CommandCenter::CommandCenter(int selenium, int area, int worth) : neededSelenium(selenium), searchArea(area), seleniumWorth(worth){
    this->turnCount = 1;
	this->totalCrewMaintenanceCost = 0;
	this->profit = 0;
}

const bool CommandCenter::isGameEnded(){
    if(Explorer::totalExploredArea == searchArea){
        cout << "Area has been fully explored." << endl;
        cout << "Aim: " << neededSelenium << " selenium." << endl;
        cout << "Collected " << Miner::totalGatheredSelenium << endl;
        if(profit > 0 && Miner::totalGatheredSelenium >= neededSelenium){
            cout << "Congrats!" << endl;
        }
        else{
            cout << "Mission Failed!" << endl;
        }
        return true;
    }
    else{
        return false;
    }
}

void CommandCenter::calculateProfit(Crew &myCrew){
    this->totalCrewMaintenanceCost = myCrew.getCrewMaintenanceCost();
    float expenses = totalCrewMaintenanceCost + myCrew.getCrewManufactureCost();
    float revenue = Miner::totalGatheredSelenium * seleniumWorth;
    this->profit = revenue - expenses;
    cout << "Profit:" << profit << endl;
    cout << "Expenses:" << expenses << endl;
    cout << "Selenium Revenue:" << revenue << endl;
}

void CommandCenter::operator++(){
    this->turnCount += 1;
}


const void CommandCenter::showInfo(){
    cout << "Current turn: " << turnCount << endl;
    cout << "Aim: " << neededSelenium << " selenium." << endl;
    cout << "Collected: " << Miner::totalGatheredSelenium << endl;
    cout << "Total Search Area: " << searchArea << endl;
    cout << "Explored Area: " << Explorer::totalExploredArea << endl;
    cout << "Currently, there are " << Explorer::totalNumberOfSeleniumArea << " area/s that include selenium." << endl;
    if(Explorer::totalNumberOfSeleniumArea > 0)
        cout <<  "Mine these areas if miners have not finished their turn! If you cannot cope with mining, you can always add new miners!" << endl;
}
/*
****************
END: COMMANDCENTER CLASS FUNCTION DECLARATIONS 
****************
*/