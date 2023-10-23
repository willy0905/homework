#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Animal {
public:
	Animal(string inName, int inEnergy = 100) //名稱跟初始體力
		: Name(inName), hungry(0), energy(inEnergy) {};
	virtual int feed(int amount) { return 0; }; //傳入消耗量，回傳飢餓度
	virtual int exercise(int times) { return 0; }; //傳入次數，回傳所賺的錢
	virtual int rest(int &food, int &water) { return 0; }; //需要傳入一些資訊方便你調整動物園食物量 水量...
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
	int foodCount; //動物園食物 沒食物可以用存款轉換
	int waterCount; //動物園水 每RUN會增加100;
	int deposit; //動物園存款 動物運動可增加
	const int sizeLimit; //動物園設計上限(初次創建時設定)可超過但追加動物會警告
};


class horse :public Animal
{
public:
	horse(string inName, int inEnergy = 100) :Animal(inName, inEnergy) {};
	int feed(int amount); //傳入消耗量，回傳飢餓度
	int exercise(int times); //傳入次數，回傳所賺的錢
	int rest(int &food, int &water) ; //需要傳入一些資訊方便你調整動物園食物量 水量...
	int drink(int amount) ;
};
class pig :public Animal
{
public:
	pig(string inName, int inEnergy = 100) :Animal(inName, inEnergy) {};
	int feed(int amount); //傳入消耗量，回傳飢餓度
	int exercise(int times); //傳入次數，回傳所賺的錢
	int rest(int &food, int &water); //需要傳入一些資訊方便你調整動物園食物量 水量...
	int drink(int amount);
};
class human :public Animal
{
public:
	human(string inName, int inEnergy = 100) :Animal(inName, inEnergy) {};
	int feed(int amount); //傳入消耗量，回傳飢餓度
	int exercise(int times); //傳入次數，回傳所賺的錢
	int rest(int &food, int &water); //需要傳入一些資訊方便你調整動物園食物量 水量...
	int drink(int amount);
};