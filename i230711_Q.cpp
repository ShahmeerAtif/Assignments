#include<iostream>
#include"i230711_Q.h"
#include<string>
using namespace std;

//Shahmeer Atif
//23i-0711
//CS-G

//Class ALU
ALU::ALU(int NOA, int NOS, int NOR, int SOR) :NoOfAdders(NOA), NoOfSubtractor(NOS), NoOfRegisters(NOR), sizeOfRegisters(SOR) {}
void ALU::setNoOfAdders(int NOA) {NoOfAdders = NOA;}
void ALU::setNoofSubtractor(int NOS) {NoOfSubtractor = NOS;}
void ALU::setNoofRegisters(int NOR) {NoOfRegisters = NOR;}
void ALU::setsizeofRegisters(int SOR) {sizeOfRegisters = SOR;}
int ALU::getNoOfAdders() {return NoOfAdders;}
int ALU::getNoOfSubtractor() {return NoOfSubtractor;}
int ALU::getNoofRegisters() {return NoOfRegisters;}
int ALU::getsizeofRegisters() {return sizeOfRegisters;}

//Class Control Unit
ControlUnit::ControlUnit(float c = 0) :clock(c) {}
void ControlUnit::setNoOfclock(int c) {clock = c;}
float ControlUnit::getNoOfclock() {return clock;}

//Class CPU
CPU::CPU(int c, int NOA, int NOS, int NOR, int SOR, string b) :alu(NOA, NOS, NOR, SOR), cu(c), brand(b) {}
void CPU::setCPU(CPU& other){alu = other.alu;cu = other.cu;}
void CPU::setbrand(string b) {brand = b;}
string CPU::getbrand() {return brand;}
ALU& CPU::getALU(){return this->alu;}
ControlUnit& CPU::getControlUnit(){return this->cu;}

//Class Graphics Card
GraphicsCard::GraphicsCard(string b, int memsize, double p) :brand(b), memorySize(memsize), price(p) {}
void GraphicsCard::setbrand(string b){brand = b;}
void GraphicsCard::setmemorySize(int memsize){memorySize = memsize;}
void GraphicsCard::setprice(double p){price = p;}
string GraphicsCard::getbrand(){return brand;}
int GraphicsCard::getmemorySize(){return memorySize;}
double GraphicsCard::getprice(){return price;}

//Class AppleSilicon
AppleSilicon::AppleSilicon() :CPU(50, 32000, 24000, 10000, 5, "M3 Apple Silicon"), AppleGPU("AppleGPU", 8, 250) {}
GraphicsCard AppleSilicon:: getGraphicsCard() {return AppleGPU;}

//Class MainMemory
MainMemory::MainMemory(int cap, string techType) : capacity(cap), technologyType(techType) {}
int MainMemory::getCapacity() {return capacity;}
void MainMemory::setCapacity(int cap){capacity = cap;}
string MainMemory::getTechnologyType(){return technologyType;}
void MainMemory::setTechnologyType(string techType){technologyType = techType;}

//Class Port
Port::Port(const string& t, int br): type(t),baud_rate(br){}
string Port::getType(){return type;}
void Port::setType(string& t){type = t;}
int Port::getBaudRate() {return baud_rate;}
void Port::setBaudRate(int br) {baud_rate = br;}

//Class Network Card
NetworkCard::NetworkCard(const  string& t, int spd, double prc) : type(t), speed(spd), price(prc) {}
string NetworkCard::getType() { return type; }
int NetworkCard::getSpeed() { return speed; }
double NetworkCard::getPrice() { return price; }
void NetworkCard::setType(string& t) { type = t; }
void NetworkCard::setSpeed(int spd) { speed = spd; }
void NetworkCard::setPrice(double prc) { price = prc; }

//Class Storage Device
StorageDevice::StorageDevice(string t, int cap, double prc): type(t), capacity(cap), price(prc) {}
string StorageDevice::getType() { return type; }
void StorageDevice::setType(string t) { type = t; }
int StorageDevice::getCapacity() { return capacity; }
void StorageDevice::setCapacity(int cap) { capacity = cap; }
double StorageDevice::getPrice() { return price; }
void StorageDevice::setPrice(double prc) { price = prc; }

//Class Motherboard
Motherboard:: Motherboard(NetworkCard* NC, MainMemory* MM, StorageDevice* sd, int NumofPorts) :NetCard(NC), mm(MM), SD(sd) {
	int num;
	do
	{
		cout << "Enter the Number of Ports for your MotherBoard:\n";
		cin >> num;
	} while (num > 0 && num > 4);
	ports = new Port[num];
	numofports = num;
	string type;
	for (int i = 0; i < num; i++)
	{

		cout << "For Port " << i + 1 << " Enter Type\nVGI,I/O,USB or HDMI?\n";
		cin >> type;
		while (type != "VGI" && type != "I/O" && type != "USB" && type != "HDMI")
		{
			cout << "Invalid Input Enter Again: \n";
			cin >> type;
		}
		ports[i].setType(type);
		if (type == "VGI")
			ports[i].setBaudRate(50);
		else if (type == "I/O")
			ports[i].setBaudRate(70);
		else if (type == "USB")
			ports[i].setBaudRate(100);
		else
			ports[i].setBaudRate(150);
	}
}
StorageDevice Motherboard::getStorageDevice() { return *SD; }
NetworkCard Motherboard:: getNetworkCard() { return *NetCard; }
MainMemory Motherboard::getMainMemory() { return *mm; }
Port& Motherboard::getPort(int index) { return ports[index]; }
int Motherboard::getNumofPorts() {return numofports;}
void Motherboard::setPort(int index, const Port & port) { ports[index] = port; }

//Class PhysicalMemory
PhysicalMemory::PhysicalMemory(int c, string t) :capacity(c), type(t) {}
void PhysicalMemory::settype(string t){type = t;}
void PhysicalMemory::setcapacity(int c){capacity = c;}
string PhysicalMemory::gettype() {return type;}
int PhysicalMemory::getcapacity() {return capacity;}

//Class IntelAMDComputer
IntelAMDComputer::IntelAMDComputer(Motherboard* Moth, GraphicsCard* Grap, CPU* processor) :mb(Moth), gpu(Grap), cpu(processor), pm(mb->getMainMemory().getCapacity(), "DDR4") {}
IntelAMDComputer::~IntelAMDComputer() {
	delete mb;
	delete gpu;
	delete cpu;
}
GraphicsCard IntelAMDComputer::getGraphicsCard(){return *gpu;}
CPU IntelAMDComputer::getCPU(){return *cpu;}
Motherboard IntelAMDComputer::getMotherboard() {return *mb;}
PhysicalMemory IntelAMDComputer::getPhysicalMemory() {return pm;}

//Class AppleComputer
AppleComputer::AppleComputer(Motherboard* MotherB) :mb(MotherB), pm(mb->getMainMemory().getCapacity(), "LPDDR4") { mb->getMainMemory().setTechnologyType("Silicon"); }
AppleComputer::~AppleComputer() {delete mb;}
Motherboard AppleComputer::getMotherboard() {return *mb;}
AppleSilicon AppleComputer::getAppleSilicon() {return M1;}
PhysicalMemory& AppleComputer::getPhysicalMemory() {return pm;}

//Class Case
Case::Case(const string& form, const string& col) : formFactor(form), color(col) {}
string Case::getFormFactor() { return formFactor; }
void Case::setFormFactor(const string& form) { formFactor = form; }
string Case::getColor() { return color; }
void Case::setColor(const string& col) { color = col; }

//Class Power Supply
PowerSupply::PowerSupply(int watt, const string& rating, double prc) : wattage(watt), efficiencyRating(rating), price(prc) {}
int PowerSupply::getWattage() const { return wattage; }
void PowerSupply::setWattage(int watt) { wattage = watt; }
string PowerSupply::getEfficiencyRating() const { return efficiencyRating; }
void PowerSupply::setEfficiencyRating(const string& rating) { efficiencyRating = rating; }
double PowerSupply::getPrice() const { return price; }
void PowerSupply::setPrice(double prc) { price = prc; }

//Class Battery
Battery::Battery(int cap):capacity(cap){}
int Battery::getCapacity(){return capacity;}
void Battery::setCapacity(int cap) {capacity = cap;}

//Class PC_Assembly
PC_Assembly::PC_Assembly(Motherboard* mb, GraphicsCard* gpu, CPU* processor, Case* c, PowerSupply* po, double p) :MBoard(mb, gpu, processor), C(c), power(po), price(p) {}
PC_Assembly::~PC_Assembly() {
	delete C;
	delete power;
}
Case PC_Assembly::getCase() {return *C;}
PowerSupply PC_Assembly::getPowerSupply() {return *power;}
IntelAMDComputer PC_Assembly::getIntelAMDComputers() {return MBoard;}
void PC_Assembly::getPC() {
	cout << "\n->Your PC Has The Following Components: \n";
	cout << "Your Graphics Card:\n";
	cout << "Brand: " << (MBoard.getGraphicsCard()).getbrand() << "\nMemory Size: " << (MBoard.getGraphicsCard()).getmemorySize() << "\nPrice: " << (MBoard.getGraphicsCard()).getprice() << " $" << endl << endl;
	cout << "Your CPU:\n";
	cout << "Brand: " << MBoard.getCPU().getbrand() << endl << " Number of Adders: " << MBoard.getCPU().getALU().getNoOfAdders() << " Number of Subtractors: " << MBoard.getCPU().getALU().getNoOfSubtractor() << " Number of Registers : " << MBoard.getCPU().getALU().getNoofRegisters() << " Size of Registers : " << MBoard.getCPU().getALU().getsizeofRegisters() << endl;
	cout << "Clock Speed: " << MBoard.getCPU().getControlUnit().getNoOfclock() << " per second" << endl << endl;
	cout << "Installed RAM:\n";
	cout << "Technology Type: " << ((MBoard.getMotherboard()).getMainMemory()).getTechnologyType() << "\nCapacity: " << ((MBoard.getMotherboard()).getMainMemory()).getCapacity() << endl << endl;
	cout << "Physical Memory:\n";
	cout << "Type: " << (MBoard.getPhysicalMemory()).gettype() << "\nCapacity: " << (MBoard.getPhysicalMemory()).getcapacity() << endl << endl;
	cout << "Your Storage Device:\n";
	cout << "Type: " << ((MBoard.getMotherboard()).getStorageDevice()).getType() << "\nMemory Size: " << ((MBoard.getMotherboard()).getStorageDevice()).getCapacity() << " GB\nPrice: " << ((MBoard.getMotherboard()).getStorageDevice()).getPrice() << " $" << endl << endl;
	cout << "Your Network Card:\n";
	cout << "Type: " << ((MBoard.getMotherboard()).getNetworkCard()).getType() << "\nSpeed: " << ((MBoard.getMotherboard()).getNetworkCard()).getSpeed() << " Mbps" << "\nPrice: " << ((MBoard.getMotherboard()).getNetworkCard()).getPrice() << " $" << endl << endl;
	cout << "Ports:\n";
	for (int i = 0; i < (MBoard.getMotherboard().getNumofPorts()); i++)
	{
		cout << "Port " << i << " Type: " << (MBoard.getMotherboard().getPort(i)).getType();
		cout << " Baud Rate: " << (MBoard.getMotherboard().getPort(i)).getBaudRate() << endl;
	}
	cout << endl;
	cout << "Your Power Supply:\n";
	cout << "Efficiency Rating: " << power->getEfficiencyRating() << "\nWattage: " << power->getWattage() << " W\nPrice: " << power->getPrice() << " $" << endl << endl;
	cout << "Your Case:\n";
	cout << "Form Factor: " << C->getFormFactor() << "\nColor: " << C->getColor() << endl << endl;
	this->price = (MBoard.getGraphicsCard()).getprice() + ((MBoard.getMotherboard()).getStorageDevice()).getPrice() + ((MBoard.getMotherboard()).getNetworkCard()).getPrice() + power->getPrice();
	cout << "The Total Price of this system comes out to be: " << this->price << " $" << endl;
}

//Class MAC_Assembly
MAC_Assembly:: MAC_Assembly(Motherboard* Moth, Case* c, PowerSupply* po, double p) :AComp(Moth), C(c), power(po), price(p) {}
MAC_Assembly::~MAC_Assembly(){
	delete C;
	delete power;
}
Case MAC_Assembly:: getCase() {return *C;}
PowerSupply MAC_Assembly::getPowerSupply() {return *power;}
AppleComputer MAC_Assembly::getAppleComputer() {return AComp;}
void MAC_Assembly::getMac() {
	cout << "\n->Your MAC Has The Following Components: \n";
	cout << "Your Graphics Card:\n";
	cout << "Brand: " << ((AComp.getAppleSilicon()).getGraphicsCard()).getbrand() << "\nMemory Size: " << ((AComp.getAppleSilicon()).getGraphicsCard()).getmemorySize() << "\nPrice: " << ((AComp.getAppleSilicon()).getGraphicsCard()).getprice() << " $" << endl << endl;
	cout << "Your CPU:\n";
	cout << "Brand: " << AComp.getAppleSilicon().getbrand() << endl << " Number of Adders: " << AComp.getAppleSilicon().getALU().getNoOfAdders() << " Number of Subtractors: " << AComp.getAppleSilicon().getALU().getNoOfSubtractor() << " Number of Registers : " << AComp.getAppleSilicon().getALU().getNoofRegisters() << " Size of Registers : " << AComp.getAppleSilicon().getALU().getsizeofRegisters() << endl;
	cout << "Clock Speed: " << AComp.getAppleSilicon().getControlUnit().getNoOfclock() << " per second" << endl << endl;
	cout << "Installed RAM:\n";
	cout << "Technology Type: " << ((AComp.getMotherboard()).getMainMemory()).getTechnologyType() << "\nCapacity: " << ((AComp.getMotherboard()).getMainMemory()).getCapacity() << endl << endl;
	cout << "Physical Memory:\n";
	cout << "Type: " << (AComp.getPhysicalMemory()).gettype() << "\nCapacity: " << (AComp.getPhysicalMemory()).getcapacity() << endl << endl;
	cout << "Your Storage Device:\n";
	cout << "Type: " << ((AComp.getMotherboard()).getStorageDevice()).getType() << "\nMemory Size: " << ((AComp.getMotherboard()).getStorageDevice()).getCapacity() << " GB\nPrice: " << ((AComp.getMotherboard()).getStorageDevice()).getPrice() << " $" << endl << endl;
	cout << "Your Network Card:\n";
	cout << "Type: " << ((AComp.getMotherboard()).getNetworkCard()).getType() << "\nSpeed: " << ((AComp.getMotherboard()).getNetworkCard()).getSpeed() << " Mbps" << "\nPrice: " << ((AComp.getMotherboard()).getNetworkCard()).getPrice() << " $" << endl << endl;
	for (int i = 0; i < (AComp.getMotherboard().getNumofPorts()); i++)
	{
		cout << "Port " << i + 1 << " Type: " << (AComp.getMotherboard().getPort(i)).getType();
		cout << " Baud Rate: " << (AComp.getMotherboard().getPort(i)).getBaudRate() << endl;
	}
	cout << endl;
	cout << "Your Power Supply:\n";
	cout << "Efficiency Rating: " << power->getEfficiencyRating() << "\nWattage: " << power->getWattage() << " W\nPrice: " << power->getPrice() << " $" << endl << endl;
	cout << "Your Case:\n";
	cout << "Form Factor: " << C->getFormFactor() << "\nColor: " << C->getColor() << endl << endl;
	this->price = ((AComp.getAppleSilicon()).getGraphicsCard()).getprice() + ((AComp.getMotherboard()).getStorageDevice()).getPrice() + ((AComp.getMotherboard()).getNetworkCard()).getPrice() + power->getPrice();
	cout << "The Total Price of this system comes out to be: " << this->price << " $" << endl;

}

//Class Laptop_Assembly
Laptop_Assembly::Laptop_Assembly(Motherboard* mb, GraphicsCard* gpu, CPU* processor, Battery* po, double p) :MBoard(mb, gpu, processor), power(po), price(p) {}
Laptop_Assembly::~Laptop_Assembly(){delete power;}
Battery Laptop_Assembly::getBattery(){return *power;}
IntelAMDComputer Laptop_Assembly::getIntelAMDComputers() {return MBoard;}
void Laptop_Assembly::getPC() {
	cout << "\n->Your Laptop Has The Following Components: \n";
	cout << "Your Graphics Card:\n";
	cout << "Brand: " << (MBoard.getGraphicsCard()).getbrand() << "\nMemory Size: " << (MBoard.getGraphicsCard()).getmemorySize() << "\nPrice: " << (MBoard.getGraphicsCard()).getprice() << " $" << endl << endl;
	cout << "Your CPU:\n";
	cout << "Brand: " << MBoard.getCPU().getbrand() << endl << " Number of Adders: " << MBoard.getCPU().getALU().getNoOfAdders() << " Number of Subtractors: " << MBoard.getCPU().getALU().getNoOfSubtractor() << " Number of Registers : " << MBoard.getCPU().getALU().getNoofRegisters() << " Size of Registers : " << MBoard.getCPU().getALU().getsizeofRegisters() << endl;
	cout << "Clock Speed: " << MBoard.getCPU().getControlUnit().getNoOfclock() << " per second" << endl << endl;
	cout << "Installed RAM:\n";
	cout << "Technology Type: " << ((MBoard.getMotherboard()).getMainMemory()).getTechnologyType() << "\nCapacity: " << ((MBoard.getMotherboard()).getMainMemory()).getCapacity() << endl << endl;
	cout << "Physical Memory:\n";
	cout << "Type: " << (MBoard.getPhysicalMemory()).gettype() << "\nCapacity: " << (MBoard.getPhysicalMemory()).getcapacity() << endl << endl;
	cout << "Your Storage Device:\n";
	cout << "Type: " << ((MBoard.getMotherboard()).getStorageDevice()).getType() << "\nMemory Size: " << ((MBoard.getMotherboard()).getStorageDevice()).getCapacity() << " GB\nPrice: " << ((MBoard.getMotherboard()).getStorageDevice()).getPrice() << " $" << endl << endl;
	cout << "Your Network Card:\n";
	cout << "Type: " << ((MBoard.getMotherboard()).getNetworkCard()).getType() << "\nSpeed: " << ((MBoard.getMotherboard()).getNetworkCard()).getSpeed() << " Mbps" << "\nPrice: " << ((MBoard.getMotherboard()).getNetworkCard()).getPrice() << " $" << endl << endl;
	cout << "Ports:\n";
	for (int i = 0; i < (MBoard.getMotherboard().getNumofPorts()); i++)
	{
		cout << "Port " << i << " Type: " << (MBoard.getMotherboard().getPort(i)).getType();
		cout << " Baud Rate: " << (MBoard.getMotherboard().getPort(i)).getBaudRate() << endl;
	}
	cout << endl;
	cout << "Your Battery:\n";
	cout << "Capacity: " << power->getCapacity() << " MAH" << endl << endl;
	this->price = (MBoard.getGraphicsCard()).getprice() + ((MBoard.getMotherboard()).getStorageDevice()).getPrice() + ((MBoard.getMotherboard()).getNetworkCard()).getPrice();
	cout << "The Total Price of this system comes out to be: " << this->price << " $" << endl;

}

//Class MacBook_Assembly
MacBook_Assembly::MacBook_Assembly(Motherboard* Moth, Battery* po, double p) :AComp(Moth), power(po), price(p) {}
MacBook_Assembly:: ~MacBook_Assembly() { delete power; }
Battery MacBook_Assembly::getBattery() {return *power;}
AppleComputer MacBook_Assembly::getAppleComputer() {return AComp;}
void MacBook_Assembly::getMac() {
	cout << "\n->Your MacBook Has The Following Components: \n";
	cout << "Your Graphics Card:\n";
	cout << "Brand: " << ((AComp.getAppleSilicon()).getGraphicsCard()).getbrand() << "\nMemory Size: " << ((AComp.getAppleSilicon()).getGraphicsCard()).getmemorySize() << "\nPrice: " << ((AComp.getAppleSilicon()).getGraphicsCard()).getprice() << " $" << endl << endl;
	cout << "Your CPU:\n";
	cout << "Brand: " << AComp.getAppleSilicon().getbrand() << endl << " Number of Adders: " << AComp.getAppleSilicon().getALU().getNoOfAdders() << " Number of Subtractors: " << AComp.getAppleSilicon().getALU().getNoOfSubtractor() << " Number of Registers : " << AComp.getAppleSilicon().getALU().getNoofRegisters() << " Size of Registers : " << AComp.getAppleSilicon().getALU().getsizeofRegisters() << endl;
	cout << "Clock Speed: " << AComp.getAppleSilicon().getControlUnit().getNoOfclock() << " per second" << endl << endl;
	cout << "Installed RAM:\n";
	cout << "Technology Type: " << ((AComp.getMotherboard()).getMainMemory()).getTechnologyType() << "\nCapacity: " << ((AComp.getMotherboard()).getMainMemory()).getCapacity() << endl << endl;
	cout << "Physical Memory:\n";
	cout << "Type: " << (AComp.getPhysicalMemory()).gettype() << "\nCapacity: " << (AComp.getPhysicalMemory()).getcapacity() << endl << endl;
	cout << "Your Storage Device:\n";
	cout << "Type: " << ((AComp.getMotherboard()).getStorageDevice()).getType() << "\nMemory Size: " << ((AComp.getMotherboard()).getStorageDevice()).getCapacity() << " GB\nPrice: " << ((AComp.getMotherboard()).getStorageDevice()).getPrice() << " $" << endl << endl;
	cout << "Your Network Card:\n";
	cout << "Type: " << ((AComp.getMotherboard()).getNetworkCard()).getType() << "\nSpeed: " << ((AComp.getMotherboard()).getNetworkCard()).getSpeed() << " Mbps" << "\nPrice: " << ((AComp.getMotherboard()).getNetworkCard()).getPrice() << " $" << endl << endl;
	for (int i = 0; i < (AComp.getMotherboard().getNumofPorts()); i++)
	{
		cout << "Port " << i + 1 << " Type: " << (AComp.getMotherboard().getPort(i)).getType();
		cout << " Baud Rate: " << (AComp.getMotherboard().getPort(i)).getBaudRate() << endl;
	}
	cout << endl;
	cout << "Your Battery:\n";
	cout << "Capacity: " << power->getCapacity() << " MAH" << endl << endl;
	this->price = ((AComp.getAppleSilicon()).getGraphicsCard()).getprice() + ((AComp.getMotherboard()).getStorageDevice()).getPrice() + ((AComp.getMotherboard()).getNetworkCard()).getPrice();
	cout << "The Total Price of this system comes out to be: " << this->price << " $" << endl;

}



//Overloaded input output operations for each classes
ostream& operator<<(ostream& output, PC_Assembly computer)
{
	computer.getPC();
	return output;
}
ostream& operator<<(ostream& output, MAC_Assembly computer)
{
	computer.getMac();
	return output;
}
ostream& operator<<(ostream& output, Laptop_Assembly computer)
{
	computer.getPC();
	return output;
}
ostream& operator<<(ostream& output, MacBook_Assembly computer)
{
	computer.getMac();
	return output;
}
istream& operator>>(istream& input, GraphicsCard* GPU)
{
	string brand;
	do {
		cout << "Enter the type of GPU you want to install\n Nivida or AMD\n";
		cin >> brand;
	} while (brand != "AMD" && brand != "Nividia");
	int n;
	do {
		cout << "Select Preferance for your GPU: \n1: Memory Size 4 GB for 150$\n2: Memory Size 8 GB for 200$\n1 or 2?\n";
		cin >> n;
	} while (n != 1 && n != 2);

	GPU->setbrand(brand);
	if (1) {
		GPU->setmemorySize(4);
		GPU->setprice(150);
	}
	else
	{
		GPU->setmemorySize(8);
		GPU->setprice(200);
	}
	return input;
}
ostream& operator<<(ostream& output, GraphicsCard GPU)
{
	output << "Your Graphics Card:\n";
	output << "Brand: " << GPU.getbrand() << "\nMemory Size: " << GPU.getmemorySize() << "\nPrice: " << GPU.getprice() << " $" << endl << endl;

	return output;
}
istream& operator>>(istream& input, MainMemory* RAM)
{

	int capacity;
	bool valid = true;
	do
	{
		cout << "Enter how much memory you want for your RAM stick:\n";
		cin >> capacity;
		for (int i = 0; i < 6 && valid; i++)
		{
			int power = 1;
			for (int j = 0; j < i; j++)
				power *= 2;
			if (capacity == power)
				valid = false;

		}
		if (valid)
			cout << "Invalid Memory Enter Again:\n";

	} while (valid);
	RAM->setCapacity(capacity);
	return input;
}
ostream& operator<<(ostream& output, MainMemory* RAM)
{
	output << "Installed RAM:\n";
	output << "Technology Type: " << RAM->getTechnologyType() << "\nCapacity: " << RAM->getCapacity() << endl << endl;

	return output;
}
istream& operator>>(istream& input, StorageDevice* SD)
{
	string type;
	do
	{
		cout << "What type of Storage Device you Prefer\nSSD or HDD?\n";
		cin >> type;
	} while (type != "HDD" && type != "SSD");
	SD->setType(type);
	int capacity;

	do
	{
		cout << "Enter how much Capacity you want for your Storage Device\n256 GB for 30$, 500 GB for 50$ or 1024 GB for 80$\nEnter The Desired Capacity:\n";
		cin >> capacity;
	} while (capacity != 256 && capacity != 500 && capacity != 1024);
	SD->setCapacity(capacity);
	if (capacity == 256)
		SD->setPrice(30);
	else if (capacity != 500)
		SD->setPrice(50);
	else
		SD->setPrice(80);
	return input;
}
ostream& operator<<(ostream& output, StorageDevice* SD)
{
	output << "Your Storage Device:\n";
	output << "Type: " << SD->getType() << "\nMemory Size: " << SD->getCapacity() << " GB\nPrice: " << SD->getPrice() << " $" << endl << endl;

	return output;
}
istream& operator>>(istream& input, NetworkCard* NC)
{
	int c;
	do
	{
		cout << "Enter what type of Network Card youll like to use\n1: Wired Ethernet for 20$ with 50 mps \n2: Wireless Internet for 40$ with 30 mps\n1 or 2?\n";
		cin >> c;
	} while (c != 1 && c != 2);
	if (1)
	{
		string s = "Ethernet";
		NC->setSpeed(50);
		NC->setPrice(20);
		NC->setType(s);
	}
	else
	{
		string s = "Internet";
		NC->setSpeed(30);
		NC->setPrice(40);
		NC->setType(s);
	}
	return input;
}
ostream& operator<<(ostream& output, NetworkCard* NC)
{
	output << "Your Network Card:\n";
	output << "Type: " << NC->getType() << "\nSpeed: " << NC->getSpeed() << " Mbps" << "\nPrice: " << NC->getPrice() << " $" << endl << endl;

	return output;
}
istream& operator>>(istream& input, PowerSupply* PS)
{
	int type;
	do
	{
		cout << "What type of Power Supply you want to install\n1: 80 Plus Bronze \n2: 80 Plus Gold\n1 or 2?\n";
		cin >> type;
	} while (type != 1 && type != 2);
	if (1)
		PS->setEfficiencyRating("80 Plus Bronze");
	else
		PS->setEfficiencyRating("80 Plus Gold");
	int watt;
	do
	{
		cout << "Enter The Desired Wattage 500W for 50$ or 750W for 70$\n500 or 750?\n";
		cin >> watt;
	} while (watt != 500 && watt != 750);
	PS->setWattage(watt);

	if (watt == 500)
		PS->setPrice(50);
	else
		PS->setPrice(70);
	return input;
}
ostream& operator<<(ostream& output, PowerSupply* PS)
{
	output << "Your Power Supply:\n";
	output << "Efficiency Rating: " << PS->getEfficiencyRating() << "\nWattage: " << PS->getWattage() << " W\nPrice: " << PS->getPrice() << " $" << endl << endl;

	return output;
}
istream& operator>>(istream& input, Case* C)
{
	string type;
	do
	{
		cout << "Enter a Form Factor for your Case\nATX or Micro ATX?\n";
		cin >> type;
	} while (type != "ATX" && type != "Micro ATX");
	C->setFormFactor(type);
	string color;
	do
	{
		cout << "Enter the Desired Color for your Case\nBlack Blue or Red?\n";
		cin >> color;
	} while (color != "Black" && color != "Blue" && color != "Red");
	C->setColor(color);
	return input;
}
ostream& operator<<(ostream& output, Case* C)
{
	output << "Your Case:\n";
	output << "Form Factor: " << C->getFormFactor() << "\nWattage: " << C->getColor() << endl << endl;

	return output;
}
istream& operator>>(istream& input, CPU* processor)
{
	string type;
	cout << "Which Brand of CPU you Want to install:\nIntel or AMD? ";
	cin >> type;
	while (type != "Intel" && type != "AMD")
	{
		cout << "Invalid Input Enter Again: ";
		cin >> type;
	}
	processor->setbrand(type);
	return input;
}
istream& operator>>(istream& input, Battery* power)
{
	int capacity;
	cout << "Enter The Capacity for your Battery: (MAX 10000)\n ";
	cin >> capacity;
	while (capacity <= 0 && capacity > 10000)
	{
		cout << "Invalid Input Enter Again: ";
		cin >> capacity;
	}
	return input;
}

//Bonus marks are Appreciated