#pragma once
#include<iostream>
#include<string>
using namespace std;

//Shahmeer Atif
//23i-0711
//CS-G


class ALU {
	int NoOfAdders;
	int NoOfSubtractor;
	int NoOfRegisters;
	int sizeOfRegisters;
public:
	ALU(int NOA = 35000, int NOS = 25000, int NOR = 3200, int SOR = 5);
	void setNoOfAdders(int NOA);
	void setNoofSubtractor(int NOS);
	void setNoofRegisters(int NOR);
	void setsizeofRegisters(int SOR);
	int getNoOfAdders();
	int getNoOfSubtractor();
	int getNoofRegisters();
	int getsizeofRegisters();

};


class ControlUnit {
	float clock;
public:
	ControlUnit(float c);
	void setNoOfclock(int c);
	float getNoOfclock();
};


class CPU {
protected:
	ALU alu; //Composed of Class ALU since its integrated in the CPU
	ControlUnit cu; //Composed of Class CU since its integrated in the CPU
	string brand; //Brand identifying if its an Intel,AMD or Apple M series CPU
public:
	CPU(int c = 5, int NOA = 35000, int NOS = 25000, int NOR = 10000, int SOR = 5, string b = "\0");
	void setbrand(string b);
	string getbrand();
	void setCPU(CPU& other);
	ALU& getALU();
	ControlUnit& getControlUnit();
};


class GraphicsCard {
	string brand; //Nividia, AMD or AppleGPU
	int memorySize;
	double price;
public:
	GraphicsCard(string b = "Nividia", int memsize = 4000, double p = 90);
	void setbrand(string b);
	void setmemorySize(int memsize);
	void setprice(double p);
	string getbrand();
	int getmemorySize();
	double getprice();

};


class AppleSilicon : public CPU { //It inherits the class CPU since its a CPU with a unique member variable
	GraphicsCard AppleGPU; //Graphics Card is composed as its integrated in the Apple Silicon CPU

public:
	AppleSilicon();
	GraphicsCard getGraphicsCard();
};

class MainMemory {//Basically your RAM
	int capacity;
	string technologyType;

public:
	MainMemory(int cap = 0, string techType = "Semiconductor");
	int getCapacity();
	void setCapacity(int cap);
	string getTechnologyType();
	void setTechnologyType(string techType);
};


class Port {
	string type;
	int baud_rate;

public:
	Port(const string& t = "\0", int br = 3600);
	string getType();
	void setType(string& t);
	int getBaudRate();
	void setBaudRate(int br);
};


class NetworkCard {
	string type;
	int speed;
	double price;

public:
	NetworkCard(const  string& t = "Ethernet", int spd = 1000, double prc = 50.0);
	string getType();
	void setType(string& t);
	int getSpeed();
	void setSpeed(int spd);
	double getPrice();
	void setPrice(double prc);
};

class StorageDevice {
	string type;
	int capacity;
	double price;

public:
	StorageDevice(string t = "HDD", int cap = 500, double prc = 100.0);
	string getType();
	void setType(string t);
	int getCapacity();
	void setCapacity(int cap);
	double getPrice();
	void setPrice(double prc);
};

class Motherboard {
protected:
	NetworkCard* NetCard; //Network Card is aggregated since its a removable part in the motherboard
	MainMemory* mm; //You can add and remove ram from the motherboard Aggregated
	StorageDevice* SD; //You can add and remove Storage device such as HDD or SDD from the motherboard Aggregated
	Port* ports; //Ports are composed since it comes with the motherboard and they are multiple fixed number of them
	int numofports;
public:

	Motherboard(NetworkCard* NC=new NetworkCard(), MainMemory* MM=new MainMemory(), StorageDevice* sd=new StorageDevice(), int NumofPorts=1);
	StorageDevice getStorageDevice();
	NetworkCard getNetworkCard();
	MainMemory getMainMemory();
	Port& getPort(int index);
	int getNumofPorts();
	void setPort(int index, const Port& port);
};


class PhysicalMemory {
	int capacity;
	string type;
public:
	PhysicalMemory(int c = 0, string t = "\0");
	void settype(string t);
	void setcapacity(int c);
	string gettype();
	int getcapacity();
};


class IntelAMDComputer {//Basically the Computer Class as mentioned in the assignment
	Motherboard* mb;//Motherboard can be removed and installed
	GraphicsCard* gpu;//Graphics Card can be attached to the motherboard so its aggregated
	CPU* cpu;//CPU can be attached to the motherboard so its aggregated
	PhysicalMemory pm;//MotherBoard comes with the physical memory DDR4 or LPDDR4
public:
	IntelAMDComputer(Motherboard* Moth = new Motherboard(), GraphicsCard* Grap = new GraphicsCard(), CPU* processor = new CPU());
	~IntelAMDComputer();
	GraphicsCard getGraphicsCard();
	CPU getCPU();
	Motherboard getMotherboard();
	PhysicalMemory getPhysicalMemory();
};


class AppleComputer {//Basically the Computer Class as mentioned in the assignment
	Motherboard* mb;//Motherboard can be removed and installed
	AppleSilicon M1;//unlike the amd or intel cpu chips AppleSilicon cannot be seperated from the motherboard since its integrated right into it which is why its composed
	PhysicalMemory pm;//MotherBoard comes with the physical memory LPDDR4

public:
	AppleComputer(Motherboard* MotherB=new Motherboard());
	~AppleComputer();
	Motherboard getMotherboard();
	AppleSilicon getAppleSilicon();
	PhysicalMemory& getPhysicalMemory();
};


class Case {
	string formFactor;
	string color;

public:
	Case(const string& form = "ATX", const string& col = "Black");
	string getFormFactor();
	void setFormFactor(const string& form);
	string getColor();
	void setColor(const string& col);
};


class PowerSupply {
	int wattage;
	string efficiencyRating;
	double price;

public:
	PowerSupply(int watt = 500, const string& rating = "80 Plus Bronze", double prc = 50.0);
	int getWattage() const;
	void setWattage(int watt);
	string getEfficiencyRating() const;
	void setEfficiencyRating(const string& rating);
	double getPrice() const;
	void setPrice(double prc);
};


class Battery {
	int capacity;

public:
	Battery(int cap = 5000);
	int getCapacity();
	void setCapacity(int cap);
};

//No battery is included in PC and MAC since Dektop require constant power and they shut off when the power go off.
class PC_Assembly {//Class For Assembling all the reamining pasrt together
	IntelAMDComputer MBoard;//There is no computer assembly if there is no computer which is why its composed
	Case* C;//Case is Aggregated since you can change it afterwards
	PowerSupply* power;//PowerSupply is Aggregated since you can change it afterwards
	double price;
public:
	PC_Assembly(Motherboard* mb = new Motherboard(), GraphicsCard* gpu = new GraphicsCard(), CPU* processor = new CPU(), Case* c = new Case(), PowerSupply* po = new PowerSupply(), double p=0);
	~PC_Assembly();
	Case getCase();
	PowerSupply getPowerSupply();
	IntelAMDComputer getIntelAMDComputers();
	void getPC();
};


class MAC_Assembly {//Class For Assembling all the reamining pasrt together
	AppleComputer AComp;//There is no computer assembly if there is no computer which is why its composed
	Case* C;//Case is Aggregated since you can change it afterwards
	PowerSupply* power;//PowerSupply is Aggregated since you can change it afterwards
	double price;
public:
	MAC_Assembly(Motherboard* Moth = new Motherboard(), Case* c = new Case(), PowerSupply* po = new PowerSupply(), double p=0);
	~MAC_Assembly();
	Case getCase();
	PowerSupply getPowerSupply();
	AppleComputer getAppleComputer();
	void getMac();
};

//Case is excluded and comes with the laptop or macbook
class Laptop_Assembly {
	IntelAMDComputer MBoard;//There is no computer assembly if there is no computer which is why its composed
	Battery* power;//In a laptop or tablet you dont have the power supply you have a Battery instead which is charged directly
	double price;
public:
	Laptop_Assembly(Motherboard* mb=new Motherboard(), GraphicsCard* gpu=new GraphicsCard(), CPU* processor=new CPU(), Battery* po=new Battery(), double p=0);
	~Laptop_Assembly();
	Battery getBattery();
	IntelAMDComputer getIntelAMDComputers();
	void getPC();
};


class MacBook_Assembly {
	AppleComputer AComp;//There is no computer assembly if there is no computer which is why its composed
	Battery* power;//In a laptop or tablet you dont have the power supply you have a Battery instead which is charged directly
	double price;
public:
	MacBook_Assembly(Motherboard* Moth=new Motherboard(), Battery* po = new Battery(), double p = 0);
	~MacBook_Assembly();
	Battery getBattery();
	AppleComputer getAppleComputer();
	void getMac();
};


//Following are the input output operators overloaded for each class so the user can change his/her computer parts afterward if needed plus its a good programming practice i heard :)
ostream& operator<<(ostream& output, PC_Assembly computer);
ostream& operator<<(ostream& output, MAC_Assembly computer);
ostream& operator<<(ostream& output, Laptop_Assembly computer);
ostream& operator<<(ostream& output, MacBook_Assembly computer);
istream& operator>>(istream& input, GraphicsCard* GPU);
ostream& operator<<(ostream& output, GraphicsCard GPU);
istream& operator>>(istream& input, MainMemory* RAM);
ostream& operator<<(ostream& output, MainMemory* RAM);
istream& operator>>(istream& input, StorageDevice* SD);
ostream& operator<<(ostream& output, StorageDevice* SD);
istream& operator>>(istream& input, NetworkCard* NC);
ostream& operator<<(ostream& output, NetworkCard* NC);
istream& operator>>(istream& input, PowerSupply* PS);
ostream& operator<<(ostream& output, PowerSupply* PS);
istream& operator>>(istream& input, Case* C);
ostream& operator<<(ostream& output, Case* C);
istream& operator>>(istream& input, CPU* processor);
istream& operator>>(istream& input, Battery* power);

