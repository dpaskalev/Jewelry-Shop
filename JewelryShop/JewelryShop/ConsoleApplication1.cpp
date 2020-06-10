#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Jewelry {
	int index;
	string type;
	string material;
	string name;
	int weight;
	int price;
	int count;

public:
	Jewelry() {}

	Jewelry(int index, string type, string material, string name, int weight, int price,int count)
	{
		this->index = index;
		this->name = name;
		this->type = type;
		this->material = material;
		this->weight = weight;
		this->price = price;
		this->count = count;
	}

	int GetIndex()
	{
		return index;
	}
	string GetName()
	{
		return name;
	}
	string GetType()
	{
		return type;
	}
	string GetMaterial()
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
	int GetCount()
	{
		return count;
	}

	void SetIndex(int value)
	{
		index = value;
	}
	void SetName(string value)
	{
		name = value;
	}
	void SetType(string value)
	{
		type = value;
	}
	void SetMaterial(string value)
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
	void SetCount(int value)
	{
		count = value;
	}
};

void PrintItemData(Jewelry element);

int main()
{
	ifstream file("../../file_1.txt");
	vector<Jewelry> colection;

	int index;
	string type;
	string material;
	string name;
	int weight;
	int price;
	int count;

	if (file.is_open())
	{
		while (file)
		{
			file >> index >> type >> material >> name >> weight >> price >> count;
			colection.push_back(Jewelry(index, type, material, name, weight, price, count));
		}
		for (int i = 0; i < colection.size(); i++)
		{
			PrintItemData(colection[i]); 
		}
	}
	else
	{
		cout << "'file_1.txt' couldn't open \n";
		return 1;
	}
}

void PrintItemData(Jewelry element) {
	cout << element.GetIndex() << "\n";
	cout << element.GetType() << "\n";
	cout << element.GetMaterial() << "\n";
	cout << element.GetName() << "\n";
	cout << element.GetWeight() << "\n";
	cout << element.GetPrice() << "\n";
	cout << element.GetCount() << "\n";
}