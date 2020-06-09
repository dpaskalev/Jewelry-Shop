#include "pch.h"
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

enum jewelryType {
	neckless,
	earring,
	bracelet,
	ring
};

enum jewelryMaterial {
	gold,
	silver,
	platin,
	brnze,

};

class Jewelry {
	string name;
	jewelryType type;
	jewelryMaterial material;
	int weight;
	int price;

public:
	Jewelry(){}

	Jewelry(string name, jewelryType type, jewelryMaterial material,int weight,int price)
	{
		this->name = name;
		this->type = type;
		this->material = material;
		this->weight = weight;
		this->price = price;
	}

	

	string GetName()
	{
		return name;
	}
	jewelryType GetType()
	{
		return type;
	}
	jewelryMaterial GetMaterial()
	{
		return material;
	}
	int GetWeight()
	{
		return weight;
	}
	int GetPrice()
	{
		return price;
	}

	void SetName(string value)
	{
		name = value;
	}
	void SetType(jewelryType value)
	{
		type = value;
	}
	void SetMaterial(jewelryMaterial value)
	{
		material = value;
	}
	void SetName(int value)
	{
		weight = value;
	}
	void SetName(int value)
	{
		price = value;
	}
};

int main()
{
    
}
