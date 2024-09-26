#include <iostream>
#include <cstdlib> //RNG
#include <ctime> //Reset RNG

using namespace std;

void game();

int main(int argc, char** argv) 
	{
	int pilmenu, restart;
	string nama;
	
	cout<<"Input Name: ";
	getline(cin, nama); //Jika menggunakan cin, maka akan hanya terambil kata pertama.
	
	do{
		do
		{
		system("cls");
		cout<<"=================="<<endl;
		cout<<"WELCOME TO COPEMON"<<endl;
		cout<<"=================="<<endl<<endl;
		
		cout<<"Username: "<<nama<<endl<<endl;
		
		cout<<"1. Start"<<endl;
		cout<<"2. Quit"<<endl<<endl;
		
		cout<<"Input Number: ";
		
		cin>>pilmenu;
		switch(pilmenu)
		{
		case 1:
			system("cls");
			game();
			cout<<"----------------------"<<endl;
			cout<<"Press 1 To Play Again!"<<endl;
			cout<<"----------------------"<<endl<<endl;
			cout<<"Input Number: ";
		
			cin>>restart;
			break;
		case 2:
			system("cls");
			cout<<"==================="<<endl;
			cout<<"Thanks For Playing!"<<endl;
			cout<<"==================="<<endl<<endl;
			return 0;
			break;
		}
		
		}while(pilmenu < 1 || pilmenu > 2);
	}while(restart == 1);
	return 0;
	}
	
void game()
{
	int pilchar, diff, attack, health, Eattack, Ehealth, action, chance, current, Ecurrent, confirm;
	
	do
	{
	system("cls");
	cout<<"=========="<<endl;
	cout<<"Difficulty"<<endl;
	cout<<"=========="<<endl<<endl;
	cout<<"1. Easy"<<endl;
	cout<<"2. Normal"<<endl;
	cout<<"3. Hard"<<endl<<endl;
	cout<<"Input Number: ";
	
	cin>>diff;
	
	switch(diff)
	{
	case 1:
	Eattack = 2, Ehealth = 20;
	break;
	case 2:
	Eattack = 3, Ehealth = 25;
	break;
	case 3:
	Eattack = 4, Ehealth = 35;
	break;
	}
	}while(diff < 1 || diff > 3);
	
	do
	{
	system("cls");
	
	cout<<"==============="<<endl;
	cout<<"List Of Copemon"<<endl;
	cout<<"==============="<<endl<<endl;
	
	cout<<"1. Chonkder"<<endl;
	cout<<"- Attack: 10"<<endl;
	cout<<"- Health: 10"<<endl<<endl;
	
	cout<<"2. Bobasaur"<<endl;
	cout<<"- Attack: 5"<<endl;
	cout<<"- Health: 15"<<endl<<endl;
	
	cout<<"3. Squidle"<<endl;
	cout<<"- Attack: 13"<<endl;
	cout<<"- Health: 7"<<endl<<endl;
	cout<<"Input Number: ";
	
	cin>>pilchar;
	
	switch(pilchar)
	{
		case 1: attack = 10, health = 10;
		cout<<endl<<"You Chose Chonkder!"<<endl<<endl;
		break;
		case 2: attack = 5, health = 15;
		cout<<endl<<"You Chose Bobasaur!"<<endl<<endl;
		break;
		case 3: attack = 13, health = 7;
		cout<<endl<<"You Chose Squidle!"<<endl<<endl;
		break;
	}
	}while(pilchar < 1 || pilchar > 3);
	
	do
	{
		
	srand(time(NULL)); //Reset RNG
	chance = rand()%100;
	
	system("cls");
	cout<<"----------"<<endl;
	cout<<"Your Turn!"<<endl;
	cout<<"----------"<<endl<<endl;
	
	cout<<"=========="<<endl;
	cout<<"Your Stats"<<endl;
	cout<<"=========="<<endl<<endl;
	
	cout<<"Attack: "<<attack<<endl;
	cout<<"Health: "<<health<<endl<<endl;
	
	cout<<"==========="<<endl;
	cout<<"Enemy Stats"<<endl;
	cout<<"==========="<<endl<<endl;
	
	cout<<"Enemy Attack: "<<Eattack<<endl;
	cout<<"Enemy Health: "<<Ehealth<<endl<<endl;
	
	cout<<"1. Attack"<<endl;
	cout<<"2. Surrender"<<endl<<endl;
	
	//cout<<"Chance: "<<chance<<endl; //Untuk Melihat Output RNG
	cout<<"Action: ";
	cin>>action;
	
	switch(action) //Player RNG
		{
		case 1:
		if(chance % 2 == 0 || chance % 3 == 0)
		{
		Ecurrent = Ehealth - attack;
		Ehealth = Ecurrent;
		
		system("cls");
		cout<<"Attack Landed!"<<endl;
		cout<<"You've Dealt "<<attack<<" Damage!"<<endl<<endl;
		}
		else 
		{
		system("cls");
		cout<<"Attack Missed!"<<endl;
		cout<<"You've Dealt 0 Damage!"<<endl<<endl;
		}
		break;
		case 2:
		system("cls");
		cout<<"======================"<<endl;
		cout<<"Better Luck Next Time!"<<endl;
		cout<<"======================"<<endl<<endl;
		cout<<"Input Anything To Restart: ";
		cin>>confirm;
		game();
		break;
		}
		
	switch(action) //Enemy RNG
		{
		case 1:
		if(chance % 3 == 0)
		{
		Ecurrent = health - Eattack;
		health = Ecurrent;
		
		cout<<"Enemy Attack Landed!"<<endl;
		cout<<"Enemy Dealt "<<Eattack<<" Damage!"<<endl<<endl;
		cout<<"Input Anything To Continue: ";
		cin>>confirm;
		}
		else
		{
		cout<<"Enemy Attack Missed!"<<endl;
		cout<<"Enemy Dealt 0 Damage!"<<endl<<endl;
		cout<<"Input Anything To Continue: ";
		cin>>confirm;
		}
		}
	}while(health > 0 && Ehealth > 0);
	
	if (health <= 0)
	{
	cout<<endl<<"========="<<endl;
	cout<<"You Lose!"<<endl;
	cout<<"========="<<endl<<endl;
	}
	else 
	{
	cout<<endl<<"========"<<endl;
	cout<<"You Win!"<<endl;
	cout<<"========"<<endl<<endl;
	}
	}
