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

string GetType(int choice);

string GetMaterial(int choice);

int main()
{
	ofstream file("../../file_1.txt");
	string message[] = { "name", "weight","price","count" };
	string input;
	int count;
	int choice;

	if (file.is_open())
	{
		cout << "Enter Jewelry count: ";
		cin >> count;

		for (int i = 0; i < count; i++)
		{
			file << "(" << i + 1 << ")\n";
			PrintTypes();
			cin >> choice;
			file << "Type: "<<GetType(choice)<<"\n";
			PrintMaterials();
			cin >> choice;
			file <<"Material: "<< GetMaterial(choice) << "\n";
			getline(cin, input);
			for (int j = 0; j < sizeof(message) / sizeof(message[0]); j++)
			{
				cout << "Enter " << message[j] << " of the jewelry.\n";
				getline(cin, input);
				file << message[j]<<": "<<input<<"\n";
			}
			file << "::\n";
		}
	}
	else
	{
		cout << "'file_1.txt' couldn't open \n";
		return 1;
	}

	file.close();
}

void PrintTypes()
{
	cout << "1. Neckless\n" << "2. Earrings\n" << "3. Bracelet\n" << "4. Ring\n";
}

void PrintMaterials() {
	cout << "1. Gold\n" << "2. Silver\n" << "3. Platinum\n" << "4. Bronze\n";
}

string GetType(int choice) {
	string result;
	
	switch (choice)
	{
	case 1:
		result = "Neckless";
		break;
	case 2:
		result = "Earring";
		break;
	case 3:
		result = "Bracelet";
		break;
	case 4:
		result = "Ring";
		break;
	default:
		break;
	}

	return result;
}

string GetMaterial(int choice) {
	string result;

	switch (choice)
	{
	case 1:
		result = "Gold";
		break;
	case 2:
		result = "Silver";
		break;
	case 3:
		result = "Platinum";
		break;
	case 4:
		result = "Bronze";
		break;
	default:
		break;
	}

	return result;
}