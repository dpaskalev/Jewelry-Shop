#include "pch.h"
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <array>

using namespace std;

void PrintTypes();
void PrintMaterials();

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
	void SetWeight(int value)
	{
		weight = value;
	}
	void SetPrice(int value)
	{
		price = value;
	}
	void SetAllString(string name, int weight, int price)
	{
		this->name = name;
		this->type = type;
		this->material = material;
		this->weight = weight;
		this->price = price;
	}
};

int main()
{
	ofstream file("file_1.txt");
	map<Jewelry, int> Colection;

	if (file.is_open())
	{
		
	}
	else
	{
		cout << "file_1.txt couldn't open \n";
		return 1;
	}

	file.close();
}

Jewelry GetItem()
{
	string line = "";
	string message[5] = { "name", "type","material","wieght","price" };
	string info[3];
	Jewelry jewelry = Jewelry();
	int choice;
	int index = 0;

	for (int i = 0; i < sizeof(message) / sizeof(message[0]); i++)
	{
		cout << "Enter " << message[i] << " of the jewelry.\n";

		if (i == 1)
		{
			PrintTypes();
			cin >> choice;
			jewelry.SetType(jewelryType(choice - 1));
		}
		else if (i == 2)
		{
			PrintMaterials();
			cin >> choice;
			jewelry.SetMaterial(jewelryMaterial(choice - 1));
		}
		else
		{
			getline(cin, line);
			info[index] = line;
			index++;
		}
	}

	jewelry.SetName(info[0]);
	jewelry.SetWeight(stoi(info[1]));
	jewelry.SetWeight(stoi(info[2]));
}

void PrintTypes()
{
	cout << "1. Neckless\n" << "2. Earring\n" << "3. Bracelet\n" << "4. Ring\n";
}

void PrintMaterials() {
	cout << "1. Gold\n" << "2. Silver\n" << "3. Platine\n" << "4. Bronze\n";
}