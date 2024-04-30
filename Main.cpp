#include<iostream>
#include"i230711_Q.h"
using namespace std;

//Shahmeer Atif
//23i-0711
//CS-G

int main()
{
	int input, input2;
	cout << "Do you want to create a PC or a MAC:\nPress 1 for PC or 2 for MAC:\n";
	do {
		cin >> input;
	} while (input != 1 && input != 2);
	cout << "Do you Want to go For a Desktop or Laptop\nPress 1 for Desktop or 2 for Laptop:\n";
	do {
		cin >> input2;
	} while (input2 != 1 && input2 != 2);

	MainMemory* RAM = new MainMemory();
	cin >> RAM;
	NetworkCard* NC = new NetworkCard();
	cin >> NC;
	StorageDevice* SD = new StorageDevice();
	cin >> SD;
	Motherboard* mb = new Motherboard(NC, RAM, SD, 0);
	if (input == 1)
	{
		if (input2 == 1)
		{
			PowerSupply* PS = new PowerSupply();
			cin >> PS;
			Case* C = new Case();
			cin >> C;
			GraphicsCard* GPU = new GraphicsCard();
			cin >> GPU;
			CPU* processor = new CPU();
			cin >> processor;
			PC_Assembly pc(mb, GPU, processor, C, PS, 0);
			cout << pc;
		}
		else
		{
			Battery* Bat = new Battery();
			cin >> Bat;
			GraphicsCard* GPU = new GraphicsCard();
			cin >> GPU;
			CPU* processor = new CPU();
			cin >> processor;
			Laptop_Assembly pc(mb, GPU, processor, Bat, 0);
			cout << pc;
		}


	}
	else
	{
		if (input2 == 1)
		{
			PowerSupply* PS = new PowerSupply();
			cin >> PS;
			Case* C = new Case();
			cin >> C;
			MAC_Assembly MAC(mb, C, PS, 0);
			cout << MAC;
		}
		else
		{
			Battery* Bat = new Battery();
			cin >> Bat;
			MacBook_Assembly pc(mb, Bat,0);
			cout << pc;
		}
	}
}