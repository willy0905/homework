#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Animal {
public:
	Animal(string inName, int inEnergy = 100) //�W�ٸ��l��O
		: Name(inName), hungry(0), energy(inEnergy) {};
	virtual int feed(int amount) { return 0; }; //�ǤJ���Ӷq�A�^�ǰ��j��
	virtual int exercise(int times) { return 0; }; //�ǤJ���ơA�^�ǩ��Ȫ���
	virtual int rest(int &food, int &water) { return 0; }; //�ݭn�ǤJ�@�Ǹ�T��K�A�վ�ʪ��魹���q ���q...
	virtual int drink(int amount) { return 0; };
	virtual void print() {
		std::cout << Name << " (hungry: " << hungry << ", energy : " << energy << ")" << std::endl;
	}
protected:
	string Name;
	int hungry;	//hungry index (initial = 0, upper bound is varying)
	int energy; //energy index (initial = 100)
};
class Zoo {
	friend ostream& operator<<(ostream &output, const Zoo animal); //[INFO] Food: ###, Water: ###, Foud$: ###$
public:
	Zoo(size_t size = 5) : foodCount(500), waterCount(100), deposit(100), sizeLimit(size) {
		house.reserve(size);
	};
	int Run(int quantity = 1) ;
	bool FeedFood(int quantity = 1);
	bool FeedWater(int quantity = 1);
	bool AskRest();
	void Listing();
	bool AddAnimal(Animal* inPtr)
	{
		house.push_back(inPtr);
		if (house.size() > sizeLimit)
		{
			cout << "[WARNING] Too many animals !!!";
			return false;
		}
		else
		{
			return true;
		}
	}
	int getCount() { return house.size(); }
	bool isBankrupt() {
		if (foodCount == 0 && deposit == 0)
		{
			cout << "you are bankrupt";
			return true;
		}
			//you may update this function
		return false;
	}
	int getMoreFood(int amount);
	Zoo operator+=(Animal* inPtr);
	Animal* operator[](int x);
	
private:
	int day = 0;
	vector<Animal*> house;
	int foodCount; //�ʪ��魹�� �S�����i�H�Φs���ഫ
	int waterCount; //�ʪ���� �CRUN�|�W�[100;
	int deposit; //�ʪ���s�� �ʪ��B�ʥi�W�[
	const int sizeLimit; //�ʪ���]�p�W��(�즸�Ыخɳ]�w)�i�W�L���l�[�ʪ��|ĵ�i
};


class horse :public Animal
{
public:
	horse(string inName, int inEnergy = 100) :Animal(inName, inEnergy) {};
	int feed(int amount); //�ǤJ���Ӷq�A�^�ǰ��j��
	int exercise(int times); //�ǤJ���ơA�^�ǩ��Ȫ���
	int rest(int &food, int &water) ; //�ݭn�ǤJ�@�Ǹ�T��K�A�վ�ʪ��魹���q ���q...
	int drink(int amount) ;
};
class pig :public Animal
{
public:
	pig(string inName, int inEnergy = 100) :Animal(inName, inEnergy) {};
	int feed(int amount); //�ǤJ���Ӷq�A�^�ǰ��j��
	int exercise(int times); //�ǤJ���ơA�^�ǩ��Ȫ���
	int rest(int &food, int &water); //�ݭn�ǤJ�@�Ǹ�T��K�A�վ�ʪ��魹���q ���q...
	int drink(int amount);
};
class human :public Animal
{
public:
	human(string inName, int inEnergy = 100) :Animal(inName, inEnergy) {};
	int feed(int amount); //�ǤJ���Ӷq�A�^�ǰ��j��
	int exercise(int times); //�ǤJ���ơA�^�ǩ��Ȫ���
	int rest(int &food, int &water); //�ݭn�ǤJ�@�Ǹ�T��K�A�վ�ʪ��魹���q ���q...
	int drink(int amount);
};