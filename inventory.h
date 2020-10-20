#ifndef INVENTORY_
#define INVENTORY_

#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include "vehicles.h"
using namespace std;

class inventory
{
private:
	vector <sportsCar*> sportsVector;
	vector <truck*> truckVector;

public:
	void mainMenu();
	bool importInventory();
	void addVehcile();
	void deleteVehicle();

	//Template and overloaded operators for displaying both vectors
	template <class display>
	display displayInventory(display);

	friend ostream& operator << (ostream& out, vector <sportsCar*>_vector);
	friend ostream& operator << (ostream& out, vector<truck*> _vector);

	int searchInventory(int);
	void sortInventory(int);
	void printInventory();
};
#endif // !INVENTORY_
