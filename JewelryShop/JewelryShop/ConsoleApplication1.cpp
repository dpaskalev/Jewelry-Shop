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

void PrintItemData(Jewelry element,int i);

void PrintColection(vector<Jewelry> colection);

vector<Jewelry> ProcessColection(vector<Jewelry> colection, int choice);

vector<Jewelry> ProcessInventory(vector<Jewelry> inventory, vector<Jewelry> colection, int choice);

void Loop(vector<Jewelry> colection, vector<Jewelry> inventory);

void PrintResult(vector<Jewelry> inventory);

int main()
{
	ifstream file("../../file_1.txt");
	vector<Jewelry> colection;
	vector<Jewelry> inventory;

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

		Loop(colection, inventory);
	}
	else
	{
		cout << "'file_1.txt' couldn't open \n";
		return 1;
	}
}

void PrintItemData(Jewelry element, int i) {
	element.SetIndex(i + 1);
	cout <<"Index: "<< "(" << element.GetIndex()<< ")" << "\n";
	cout <<"Type: "<< element.GetType() << "\n";
	cout <<"Material: "<< element.GetMaterial() << "\n";
	cout <<"Name: "<< element.GetName() << "\n";
	cout <<"Weight: "<< element.GetWeight() << "gr.\n";
	cout <<"Price: "<< element.GetPrice() << "$\n";
	cout <<"Count: "<< element.GetCount() << "\n";
}

void PrintColection(vector<Jewelry> colection) {
	for (int i = 0; i < colection.size() - 1; i++)
	{
		PrintItemData(colection[i],i);
	}
}

vector<Jewelry> ProcessColection(vector<Jewelry> colection, int choice)
{
	for (int i = 0; i < colection.size() - 1; i++)
	{
		if (colection[i].GetIndex() == choice)
		{
			colection[i].SetCount(colection[i].GetCount() - 1);
			colection[colection.size() - 1] = colection[i];

			if (colection[i].GetCount() == 0)
			{
				colection.erase(colection.begin() + (i + 1));
			}
			break;
		}
	}

	return colection;
}

vector<Jewelry> ProcessInventory(vector<Jewelry> inventory, vector<Jewelry> colection,int choice)
{
	if (choice > colection.size() - 1)
	{
		choice--;
	}

	bool contains = false;
	for (int j = 0; j < inventory.size(); j++)
	{
		if (inventory[j].GetIndex() == colection[choice].GetIndex())
		{
			inventory[j].SetCount(inventory[j].GetCount() + 1);
			contains = true;
			break;
		}
	}
	if (contains == false)
	{
		colection[colection.size() - 1].SetCount((colection[choice].GetCount()) - (colection[choice].GetCount() - 1));
		inventory.push_back(colection[colection.size() - 1]);
	}

	return inventory;
}

void Loop(vector<Jewelry> colection, vector<Jewelry> inventory)
{
	int choice;
	
	while (colection.size() > 1)
	{
		PrintColection(colection);

		while (true)
		{
			cout << "---\n";
			cout << "Choose an item index for purchase: ";
			cin >> choice;

			if (choice > 0 && choice < colection.size())
			{
				break;
			}
			else if (choice == 0)
			{
				PrintResult(inventory);
				return;
			}
		}

		colection = ProcessColection(colection, choice);
		//
		inventory = ProcessInventory(inventory, colection, choice);
	}

	PrintResult(inventory);
}

void PrintResult(vector<Jewelry> inventory)
{
	cout<<"----------\n";
	cout << "Your inventory:\n";

	int cost = 0;

	for (int i = 0; i < inventory.size(); i++)
	{
		PrintItemData(inventory[i],i);
		cost += (inventory[i].GetPrice() * inventory[i].GetCount());
	}

	cout <<"Total cost: "<< cost << "$\n";
}

string GetName(string value)
{

}