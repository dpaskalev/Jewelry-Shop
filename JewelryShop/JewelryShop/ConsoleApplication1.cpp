#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream file("../../file_1.txt");
	/*string line;
	int index;
	string type;
	string material;
	string name;
	int weight;
	int price;
	int count;*/

	if (file.is_open())
	{
		while (file)
		{
			/*file >> index >> type >> material >> name >> weight >> price >> count;*/
		}
		/*cout << index << type << material << name << weight << price << count << endl;*/
	}
	else
	{
		cout << "'file_1.txt' couldn't open \n";
		return 1;
	}
}
