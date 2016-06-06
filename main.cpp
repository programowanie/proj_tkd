#include "Tkd.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <time.h> 

#define interval 900000

using namespace std;

void get_injury(vector <Tkd> &vecB,int a1,int b1,bool &Won1,int injury)
{
	int type=rand()%5;
	
	if (injury==0&&Won1!=true)
	{
		if (type==0||type==1)
		{
		   	cout<<endl<<vecB[a1].name()<<" doznaje niewielkiej kontuzji i kontynuuje walke!\n\n";
		   	vecB[a1].change_stats(-5);
		   	usleep(interval);usleep(interval);
		}
		if (type==2||type==3)
		{
		   	cout<<endl<<vecB[a1].name()<<" doznaje powaznej kontuzji i z trudem walczy dalej!\n\n";
		   	vecB[a1].change_stats(-20);
		   	usleep(interval);usleep(interval);
		}
		   	if (type==4)
		{
			cout<<"\nBardzo powazna kontuzja zawodnika--->"<<vecB[a1].name()<<"\nJest on nie zdolny do dalszej walki!";
			cout<<"\n\nWygrywa--->"<<vecB[b1].name()<<endl;
		   	Won1=true;
			vecB[b1].add(vecB[a1].points());
			usleep(interval);usleep(interval);
		}
	}	
}
void duel(vector <Tkd> &vecA,int a,int b,bool &Won)
{
	int where_atk=rand()%3;
	int KO=rand()%4;
	int value=0;
	double atk=0,def=0;	
		if((where_atk==1)||(where_atk==2))
		{	
			atk=(rand()%vecA[a].atkchance()/2+vecA[a].attack().lower);
			def=(rand()%vecA[b].defchance()/2+vecA[b].defence().lower);
			value=atk>def?1:0; //atak
			vecA[a].add(value);
			if (value==1)
			{
			vecA[a].get_tired();
			cout<<vecA[a].name()<<"\t: Trafia w korpus\t\t";
			
				   if (atk-def>40)  // KO
				   {
				   		if (KO==0)
						   {
						   	cout<<"\n\n\t---->NOKAUT !!!<----\n\n";
						   	cout<<vecA[b].name()<<" nie jest zdolny do walki\n";
						   	cout<<"Wygrywa---> "<<vecA[a].name()<<endl;
						   	Won=true;
						   	vecA[a].add(vecA[b].points());
						   	usleep(interval);usleep(interval);
						   }
				   }	
			}
			if (def-atk>30) //kontra
			{				
				value=1;
				vecA[b].add(value);
				cout<<vecA[b].name()<<"\t: Kontratakuje w korpus\t\t";
			}
		}
		else
		{
			atk=(rand()%vecA[a].atkchance()/2+vecA[a].attack().upper);
			def=(rand()%vecA[b].defchance()/2+vecA[b].defence().upper);
			value=atk>def?3:0;
			vecA[a].add(value);
			if(value==3)
			{
			vecA[a].get_tired();	
			cout<<vecA[a].name()<<"\t: Trafia w glowe\t\t";
			}
				if (atk-def>40)  //KO
				   {
				   		if (KO==0)
						   {
						   	cout<<"\n\n\t---->NOKAUT !!!<----\n\n";
						   	cout<<vecA[b].name()<<" nie jest zdolny do walki\n";
						   	cout<<"Wygrywa---> "<<vecA[a].name()<<endl;
						   	Won=true;
						   	vecA[a].add(vecA[b].points());
						   	usleep(interval);usleep(interval);
						   }
				   }	
			if (def-atk>30) //kontra
			{
				value=3;
				vecA[b].add(value);
				cout<<vecA[b].name()<<"\t: Kontratakuje w glowe\t\t";
			}
		}
		if (value!=0&&Won==false)
		{
			if(a<b)
			{
			cout<<vecA[a].points()<<":"<<vecA[b].points()<<endl;	
			}
			else
			{
			cout<<vecA[b].points()<<":"<<vecA[a].points()<<endl;	
			}
		usleep(interval);	
		}
	
}
int main(int argc, char** argv)
{
	srand(time(NULL));
	Tkd comp[8];
	vector <Tkd> vecTkd;
	for (int i=0;i<8;i++)
	{
		vecTkd.push_back(comp[i]);	   	
	}
string ladder[8];
int fight_number=1;
int winner,loser,injury;
bool alreadyWon;
int whoatk,num=0;
for (int w=0;w<3;w++)	
{
	for (int k=0;k<vecTkd.size();k++)
		{
		
		cout<<"\n\n\t\t--------Walka numer:"<<fight_number<<"--------";fight_number++; 	
		cout<<"\n\n\n"<<vecTkd[k].name()<<"\t-------VS------\t\t"<<vecTkd[k+1].name();
		cout<<"\nAttack:";cout.width(19);cout<<vecTkd[k].attack().lower<<"/"<<vecTkd[k].attack().upper;
		cout<<"<--->"<<vecTkd[k+1].attack().lower<<"/"<<vecTkd[k+1].attack().upper;
		cout<<"\nDefence:";cout.width(18);cout<<vecTkd[k].defence().lower<<"/"<<vecTkd[k].defence().upper;
		cout<<"<--->"<<vecTkd[k+1].defence().lower<<"/"<<vecTkd[k+1].defence().upper;
		cout<<"\nStamina:";cout.width(18);cout<<vecTkd[k].stamina()<<"<--------->"<<vecTkd[k+1].stamina();
		cout<<"\nAttackChance:";cout.width(13);cout<<vecTkd[k].atkchance()<<"<--------->"<<vecTkd[k+1].atkchance();
		cout<<"\nDefenceChance:";cout.width(12);cout<<vecTkd[k].defchance()<<"<--------->"<<vecTkd[k+1].defchance();
		usleep(interval);usleep(interval);
		
		alreadyWon=false;   	
		
			for (int j=0;j<3;j++)//3 rundy
			{
		   	cout<<"\n\n----Rozpoczyna sie "<<j+1<<" runda----"<<endl<<endl;
		   	usleep(interval);
			  
			   	for (int i=0;i<rand()%10+5;i++) //ile akcji w rundzie
				   	{
					injury=rand()%40;
				   	whoatk=rand()%2;
					if(whoatk==0)
					   	{
							duel(vecTkd,k,k+1,alreadyWon);
							get_injury(vecTkd,k,k+1,alreadyWon,injury);
								  if (alreadyWon==true)
								  {
 								  	j=3;break;
								  }

				   		}
				   	if(whoatk==1);
			  	    	{
							duel(vecTkd,k+1,k,alreadyWon);
							get_injury(vecTkd,k,k+1,alreadyWon,injury);
								if (alreadyWon==true)
								{
									j=3;break;
								}
					    }
			   	if (j>0)//jezeli po 1 rundzie przewaga 12 pkt to koniec
			   	{
			

				   	if (vecTkd[k].points()-vecTkd[k+1].points()>=12&&alreadyWon==false)
					   	{
						   	cout<<"\n\nZawodnik "<<vecTkd[k].name()<<" WYGRYWA !! przewaga punktow"<<endl;
						   	j=3;alreadyWon=true;
						   	break;
	  	    			}
	 	 				 if	(vecTkd[k+1].points()-vecTkd[k].points()>=12)
					   	{
							cout<<"\n\n"<<vecTkd[k+1].name()<<" WYGRYWA !! przewaga punktow"<<endl;
							j=3;alreadyWon=true;
							break;	
				   	   	}
		  		 }		 
		   			 }
				if (j!=2||alreadyWon==true)	
				{
				vecTkd[k].rest(5); // odpoczynek po rundzie
				vecTkd[k+1].rest(5);
				}		
		     }
    		 while (vecTkd[k].points()==vecTkd[k+1].points()) //jezeli po 3 rundach remis to walka do pierwszego punktu
			 {
				 whoatk=rand()%2;
			if(whoatk==0)
				{
					duel(vecTkd,k,k+1,alreadyWon);
				}
			if(whoatk==1);
 	    		{
					duel(vecTkd,k+1,k,alreadyWon);
		    	}
			 }
   	   		winner=vecTkd[k].points()>vecTkd[k+1].points()?k:k+1; //szukamy zwyciezcy
	 		if(alreadyWon==false) 		//jesli jescze nie wygral to wyswietlamy
	 		{	
			cout<<"\n\nWYGRYWA --->"<<vecTkd[winner].name()<<endl;
			}
			vecTkd[winner].rest(vecTkd[winner].tiredness());
			loser=vecTkd[k].points()<vecTkd[k+1].points()?k:k+1; //przegrany  
			ladder[num]=vecTkd[loser].name();num++;
			vecTkd.erase(vecTkd.begin()+loser);
			vecTkd[k].clearStats();
			vecTkd[k+1].clearStats();
			usleep(interval);usleep(interval);usleep(interval);
			system("cls");
		}
 
}		
		ladder[num]=vecTkd[winner].name();
		cout<<"\n\n\t\tKLASYFIKACJA GENERALNA\n\n";
		for (int i=0;i<8;i++)
		{
			if (i<4) cout<<"\nMiejsce 5-8:";
			else if(i<6) cout<<"\nMiejsce 3-4:";
			else if(i==6) cout<<"\nMiejsce 2:";
			else if(i==7) cout<<"\nMiejsce 1:";									
			cout<<"\t"<<ladder[i];
		}  		
			return 0;
}