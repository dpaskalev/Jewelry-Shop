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

void PrintElements(vector<Jewelry> colection);

void ProcessChoice(vector<Jewelry> colection, vector<Jewelry> inventory, int choice, int cost);

void ProcessInventory(vector<Jewelry> inventory, vector<Jewelry> colection, int i, int cost);

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

	int choice;
	int cost = 0;

	if (file.is_open())
	{
		while (file)
		{
			file >> index >> type >> material >> name >> weight >> price >> count;
			colection.push_back(Jewelry(index, type, material, name, weight, price, count));
		}

		while (colection.size() > 0)
		{
			PrintElements(colection);

			while (true)
			{
				cout << "---\n";
				cout << "Choose an item index for purchase: ";
				cin >> choice;

				if (choice > 0 && choice < colection.size())
				{
					break;
				}
			}

			for (int i = 0; i < colection.size(); i++)
			{
				if (colection[i].GetIndex() == choice)
				{
					cost += colection[i].GetPrice();
					colection[i].SetCount(colection[i].GetCount() - 1);
					colection[colection.size() - 1] = colection[i];

					if (colection[i].GetCount() == 0)
					{
						colection.erase(colection.begin(), colection.begin() + (i + 1));
					}
					break;
				}
				//
				bool contains = false;
				for (int j = 0; j < inventory.size(); j++)
				{
					if (inventory[j].GetIndex() == colection[i].GetIndex())
					{
						inventory[j].SetCount(inventory[j].GetCount() + 1);
						cost += colection[i].GetPrice();
						contains = true;
						break;
					}
				}
				if (contains == false)
				{
					colection[colection.size() - 1].SetCount((colection[i].GetCount()) - (colection[i].GetCount() - 1));
					inventory.push_back(colection[colection.size() - 1]);
				}
			}
		}
	}
	else
	{
		cout << "'file_1.txt' couldn't open \n";
		return 1;
	}
}

void PrintItemData(Jewelry element) {
	cout << "(" << element.GetIndex() << ")" << "\n";
	cout << element.GetType() << "\n";
	cout << element.GetMaterial() << "\n";
	cout << element.GetName() << "\n";
	cout << element.GetWeight() << "\n";
	cout << element.GetPrice() << "\n";
	cout << element.GetCount() << "\n";
}

void PrintElements(vector<Jewelry> colection) {
	for (int i = 0; i < colection.size(); i++)
	{
		PrintItemData(colection[i]);
	}
}

void ProcessChoice(vector<Jewelry> colection, vector<Jewelry> inventory, int choice, int cost)
{
	
}

void ProcessInventory(vector<Jewelry> inventory, vector<Jewelry> colection, int i,int cost)
{
	
}