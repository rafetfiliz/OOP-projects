//---Name & Surname: Rafet Filiz
//---Student Number: 150200028
#include <iostream>
#include "Robot.h"
using namespace std;
class Crew{
	friend class CommandCenter;
	private:
		int maxExplorers;
		int maxMiners;
		int crewManufactureCost;
		float crewMaintenanceCost;
		int explorerCrewSize;
		int minerCrewSize;
		Explorer **ExplorerCrew;
		Miner **MinerCrew;
		
	public:
		Crew(int, int, int, int);
		~Crew();
		Robot* manufactureRobot(string);
		Robot* manufactureRobot();
		void initMovement();
		void updateDurability();
		void operator+=(Robot*);
		void operator-=(const string);
		const void showInfo();
		const float getCrewMaintenanceCost();
		const void setCrewMaintenanceCost(float);
		Explorer** getExplorers();
		Miner** getMiners();
		const int getExplorerCrewSize();
		const int getMinerCrewSize();
		const int getCrewManufactureCost();
};

class CommandCenter{
	private:
		const int neededSelenium;
		const float searchArea;
		const int seleniumWorth;
		int turnCount;
		float totalCrewMaintenanceCost;
		float profit;
	public:
		CommandCenter(int, int, int);
		const bool isGameEnded();
		void calculateProfit(Crew&);
		void operator++();
		const void showInfo();
};



