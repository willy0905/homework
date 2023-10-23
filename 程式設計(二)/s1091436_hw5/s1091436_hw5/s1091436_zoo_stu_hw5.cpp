#include <iostream>
#include "s1091436_zoo_stu_hw5.h"
using namespace std;
int horse::feed(int amount)
{
	cout << "[LOG] horse eat " << amount << " food\n";
	energy += amount * 2;
	hungry -= amount;
	if (hungry < 0)
	{
		hungry = 0;
	}
	return hungry;
}
int horse::exercise(int times)
{
	int gain = 0;
	for (int i = 0; i < times; i++)
	{
		if (hungry < 100)
		{
			if (hungry <= 65)
			{
				hungry += 35;
				energy -= 35;
				gain += 50;
			}
			else
			{
				gain += (100 - hungry) * 50 / 35;
				energy -= 100 - hungry;
				hungry = 100;
			}
		}
		else if (hungry == 100 && energy > 0)
		{
			if (energy >= 50)
			{
				energy -= 50;
				gain += 25;
			}
			else
			{
				gain += (100 - energy) / 2;
				energy = 0;
			}
		}
	}
	return gain;
}
int horse::rest(int &food, int &water)
{
	if (water > 10)
	{
		water -= 0;
		cout << "[LOG] horse take a rest, eat 0 food & drink 10 water, gain 10 energy\n";
		energy += 10;
		return energy;
	}
	else
		return 0;
}
int horse::drink(int amount)
{
	cout << "[LOG] horse drink " << amount << " water\n";
	energy += amount;
	return energy;
}
int pig::feed(int amount)
{
	cout << "[LOG] pig eat " << amount << " food\n";
	int x=0;
	hungry -= amount;
	if (hungry < 0)
	{
		x = -hungry;
		hungry = 0;
		energy += x * 2;
	}
	return hungry;
}
int pig::exercise(int times)
{
	int gain = 0;
	for (int i = 0; i < times; i++)
	{
		if (hungry < 50 && energy  > 0)
		{
			if (energy >= 35)
			{
				if (hungry <= 30)
				{
					energy -= 35;
					hungry += 20;
					gain += 100;
				}
				else
				{
					energy -= (50 - hungry) * 35 / 20;
					hungry = 50;
					gain += (50 - hungry) * 5;
				}
			}
			else
			{
				if (hungry + (energy * 20 / 35) >50)
				{
					energy -= (50 - hungry) * 35 / 20;
					gain += (50 - hungry) * 5;
					hungry = 50;
				}
				else
				{
					hungry += energy * 20 / 35;
					gain += energy / 100 * 35;
					energy = 0;
				}
			}
		}
	}
	return gain;
}
int pig::rest(int &food, int &water)
{
	if (food > 10)
	{
		food -= 10;
		cout << "[LOG] pig take a rest, eat 10 food & drink 0 water, gain 0 energy\n";
	}
	return 0;
}
int pig::drink(int amount)
{

	cout << "[LOG] pig drink " << amount << " water\n";
	energy += amount;
	return amount;
}
int human::feed(int amount)
{
	cout << "[LOG] human eat " << amount << " food\n";
	int x = 0;
	if (hungry < amount)
	{
		x = hungry;
		hungry = 0;
	}
	else
	{
		hungry -= amount;
		x = amount;
	}
	energy += amount-10;
	return hungry;
}
int human::exercise(int times)
{
	int gain = 0;
	if (energy > 10)
	{
		energy -= 10;
	}
	if (energy > 35)
	{
		if (hungry <= 115)
		{
			hungry += 35;
			energy -= 35;
			gain += 100;
		}
		else
		{
			energy -= 150 - hungry;
			hungry = 0;
			gain += (150 - hungry) * 100 / 35;
		}
	}
	else
	{
		if (energy > hungry)
		{
			energy -= hungry;
			gain = hungry * 100 / 35;
			hungry = 0;
		}
		else
		{
			hungry -= energy;
			gain = energy * 100 / 35;
			energy = 0;
		}
	}
	return gain;
}
int human::rest(int &food, int &water)
{
	if (energy >= 10)
	{
		if (food > 10 && water > 20)
		{
			food -= 10;
			water -= 20;
			cout << "[LOG] human take a rest, eat 10 food & drink 20 water, gain 20 energy\n";
		}
		energy += 10;
		return 20;
	}
	else
	{
		return 0;
	}
}
int human::drink(int amount)
{
	if (energy >= 10)
	{
		cout << "[LOG] human drink " << amount << " water\n";
		energy += amount * 2 - 10;
		return amount * 2;
	}
}

int Zoo::Run(int quantity)
{
	day++;
	cout << "today is " << day << " day\n";
	int amount = 0;
	int money;
	//you SHOULD update this function
	for (int i = 0; i < quantity; i++)
	{
		for (std::vector<Animal*>::iterator iter = house.begin(); iter != house.end(); ++iter) 
		{
			money= (*iter)->exercise(1);
			amount += money;
			(*iter)->print();
		}
		AskRest();
		FeedFood(1);
		FeedWater(1);
	}
	if (foodCount == 0)
	{
		getMoreFood(100);
	}
	waterCount += 100;
	deposit += amount;
	return amount;
}
bool Zoo::FeedFood(int quantity)
{
	std::cout << "[LOG] Feeding food...\n";
	int feeds = 0;
	for (int i = 0; i < quantity; i++)
	{
		if (foodCount < 50)
		{
			break;
		}
		for (std::vector<Animal*>::iterator iter = house.begin(); iter != house.end(); ++iter) {
			if (foodCount < 50)
			{
				break;
			}
			else
			{
				(*iter)->feed(50);
				feeds += 50;
				foodCount -= 50;
			}
		}
	}
	if (foodCount < 50)
	{
		std::cout << "[LOG] total consume " << feeds << " food.\n";
		std::cout << "[WARNING] Insufficient food !!!\n";
		return false;
	}
	std::cout << "[LOG] total consume " << feeds << " food.\n";
	return true;
}

bool Zoo::FeedWater(int quantity)
{
	std::cout << "[LOG] Feeding water...\n";
	int waters = 0;
	for (int i = 0; i < quantity; i++)
	{
		if (waterCount < 10)
		{
			break;
		}
		for (std::vector<Animal*>::iterator iter = house.begin(); iter != house.end(); ++iter) {
			if (waterCount < 10)
			{
				break;
			}
			else
			{
				(*iter)->drink(10);
				waters += 10;
				waterCount -= 10;
			}
		}
	}
	if (waterCount < 10)
	{
		std::cout << "[WARNING] Insufficient water !!!\n";
		std::cout << "[LOG] total consume " << waters << " water.\n";
		return false;
	}
	std::cout << "[LOG] total consume " << waters << " water.\n";
	return true;
}

bool Zoo::AskRest()
{
	std::cout << "[LOG] ask all animals to rest.\n";
	for (std::vector<Animal*>::iterator iter = house.begin(); iter != house.end(); ++iter) {
		(*iter)->rest(foodCount, waterCount);
	}
	return true;
}

void Zoo::Listing()
{
	for (std::vector<Animal*>::iterator iter = house.begin(); iter != house.end(); ++iter) {
		(*iter)->print();
	}
}
int Zoo::getMoreFood(int amount)
{
	{ //try to buy food
		int gain = 0;
		if (amount <= deposit)
		{
			gain = amount * 2;
			cout << "[LOG] Transfer $" << amount << " to " << gain << " food\n";
			deposit -= amount;
			foodCount += gain;
		}
		else if(deposit>0)
		{
			gain = deposit * 2;
			foodCount += gain;
			cout << "[LOG] Transfer $" << deposit << " to " << gain << " food\n";
			deposit = 0;
		}
		return gain;
	}
}
Zoo Zoo::operator+=(Animal* inPtr)
{
	AddAnimal(inPtr);
	return *this;
}

Animal* Zoo::operator[](int x)
{
	return house[x];
}

ostream & operator<<(ostream & output, const Zoo animal)
{
	output <<"[INFO] Food: "<<animal.foodCount <<", Water: "<<animal.waterCount<<", Foud$: "<<animal.deposit<<"$";
	return output;
}