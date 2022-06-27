//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname: Rafet Filiz
//---Student Number: 150200028
//--------------------------//
#include <iostream>
#ifndef _H
#define _H
using namespace std;
class Robot {
	private:
		static int unqID;
		string RobotName;
		const string RobotType;
		float speed; 
		int durability; 
		const int manufactureCost; 
		float maintenanceCost;
		bool canMove;
	
	public:
		Robot(string&, float, int, int, float);
		void operator=(const Robot&);
		const void showInfo();
		const bool getCanMove();
		const float getMaintenanceCost();
		const string getName();
		const float getSpeed();
		const int getDurability();
		const string getType();
		const int getUnqID();
		const void setDurability(int);
		const void setCanMove(bool);
		const void setUnqID(int);
		const void setName(string);
}; 


class Explorer : public Robot{
	friend class Miner;
	friend class CommandCenter;
	private:
		static float totalExploredArea;
		static int totalNumberOfSeleniumArea;
		float exploredArea;
		bool detectedSelenium;
		
		
	public:
		Explorer(string&, float, int);
		const bool move();
		void explore();
		void operator=(const Explorer&);
		const void showInfo();
		const void setExploredArea(float);
		const float getExploredArea();
		
};



class Miner : public Robot{
	friend class CommandCenter;
	private:
		static int totalGatheredSelenium;
		int gatheredSelenium;

		
	public:
		Miner(string&, float, int);
		void mine();
		const bool move();
		void operator=(const Miner&);
		const void showInfo();
		const void setGatheredSelenium(int);
		const int getGatheredSelenium();
};
#endif