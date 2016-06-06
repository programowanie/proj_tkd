#include <iostream>
#include <fstream>
#include "Tkd.h"
#include <stdlib.h>
#include <iterator>
using namespace std;

vector <string> Tkd::names;
void Tkd::init()
{
	ifstream file("names.txt");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
}
int randValue()
{
	return 50+rand()%49;	
}
Tkd::Tkd()
{
	static int amountOfNames = (init(), names.size());
	static bool *tab=new bool[names.size()];
		while(1){
			int amount =rand() % amountOfNames;
			if(tab[amount]==0)
			{
				_name = names[amount];
				tab[amount]+=1;
				break;	
			}}
	_attack.upper=randValue();
	_attack.lower=randValue();
	_defence.upper=randValue();
	_defence.lower=randValue();
	_atkchance=randValue();
	_defchance=randValue();
	_attitude=50;
	_points=0;
	_stamina=randValue();
	_tiredness=0;
	_overall=(_attack.lower+_attack.upper+_defence.lower+_defence.upper
				+_defchance+_atkchance)/6;
}
void Tkd::add(int n)
{
	_points+=n;	
}
void Tkd::clearStats()
{
	_points=0;
	_tiredness=0;
}
void Tkd::change_stats(int value)
{
	_attack.upper+=value;
	_attack.lower+=value;
	_defence.upper+=value;
	_defence.lower+=value;
	_atkchance+=value;
	_defchance+=value;
}
void Tkd::get_tired()
{
	if (_stamina<66)
	{
		change_stats(-3);
		_tiredness+=3;
	}
	else if ((_stamina>=66)&&(_stamina<83))
	{
		change_stats(-2);
		_tiredness+=2;
	}
	else
	{
		change_stats(-1);
		_tiredness+=1;
	}
}
void Tkd::rest(int value)
{
	if ((_tiredness-value)<0)
	{
		change_stats(_tiredness);
		_tiredness=0;
	}
	else
	{
		_tiredness-=value;
		change_stats(value);	   	   	
	}
}