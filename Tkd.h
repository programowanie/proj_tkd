#pragma once
#include <string>
#include <vector>

using namespace std;

struct parameter
{
	int upper;
	int lower;
};

class Tkd
{
	static vector <string> names;
	
	string _name;
	int _points,_atkchance,_defchance;
	parameter _attack, _defence;
	int _stamina,_attitude;
	int _tiredness,_overall;
	static void init();

	public:
		Tkd();
		
		string name() {return _name;}
		parameter attack() {return _attack;}
		parameter defence() {return _defence;}
		int points() {return _points;}
		int stamina() {return _stamina;}
		int attitude() {return _attitude;}
		int tiredness() {return _tiredness;}
		double overall() {return _overall;}
		int atkchance() {return _atkchance;}
		int defchance() {return _defchance;}
		void add(int n);
		void change_stats(int value);
		void clearStats();
		void get_tired();
		void rest(int value);
};  
