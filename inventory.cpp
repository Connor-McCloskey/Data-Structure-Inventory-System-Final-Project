#include "inventory.h"

//Main menu
void inventory::mainMenu()
{
	cout << "Welcome to the McCloskey Vehicle Inventory!" << endl;
	
	while (true)
	{
		int menuChoice = 0;
		cout << "Main Menu" << endl;
		cout << "1: Import inventory from file" << endl;
		cout << "2: Add vehicle to inventory" << endl;
		cout << "3: Delete vehicle from inventory" << endl;
		cout << "4: Search inventory" << endl;
		cout << "5: Sort inventory by serial number" << endl;
		cout << "6: Export inventory to file" << endl;
		cout << "7: Exit program" << endl;
		cout << "8: Display inventory" << endl;
		cout << "Enter choice now: ";
		cin >> menuChoice;

		//Import
		if (menuChoice == 1)
		{
			importInventory();
		}

		//Add
		else if (menuChoice == 2)
		{
			addVehcile();
		}

		//Delete
		else if (menuChoice == 3)
		{
			deleteVehicle();
		}

		//Search - returns index number
		else if (menuChoice == 4)
		{
			cout << endl;
			int vectorChoice = 0;
			cout << "Search sports cars or trucks?" << endl;
			cout << "1: Sports cars" << endl;
			cout << "2: Trucks" << endl;
			cout << "Enter choice now: ";
			cin >> vectorChoice;

			int position = searchInventory(vectorChoice);

			if (position == -1)
			{
				cout << "Term not found." << endl;
			}
			else
			{
				cout << "Term found at position " << position << "." << endl;
			}
		}

		//Sort
		else if (menuChoice == 5)
		{
			int sortChoice;
			cout << "Sort sports cars or trucks?" << endl;
			cout << "1: Sports Cars" << endl;
			cout << "2: Trucks" << endl;
			cin >> sortChoice;
			//generic algorithm
			if (sortChoice == 1 || sortChoice == 2)
			{
				sortInventory(sortChoice);
			}
			else
			{
				cout << "Invalid entry." << endl;
			}
		}

		//Print to file
		else if (menuChoice == 6)
		{
			printInventory();
		}

		//Exit
		else if (menuChoice == 7)
		{
			exit(0);
		}

		//Display
		else if (menuChoice == 8)
		{
			int displayChoice = 0;
			cout << endl;
			cout << "Which would you like to display?" << endl;
			cout << "1: Sports cars" << endl;
			cout << "2: Trucks" << endl;
			cout << "Enter choice now: ";
			cin >> displayChoice;

			if (displayChoice == 1)
			{
				displayInventory(sportsVector);
			}

			else
			{
				displayInventory(truckVector);
			}
			
		}

		//Invalid inputs
		else
		{
			cout << "Invalid input." << endl;
		}
	}
}

//Import inventory from file
bool inventory::importInventory()
{
	cout << endl;
	int menuChoice;
	ifstream inFile;
	cout << endl;
	cout << "Would you like to import the inventory for sports cars or trucks?" << endl;
	cout << "1: Sports Cars" << endl;
	cout << "2: Trucks" << endl;
	cout << "Enter choice now: ";
	cin >> menuChoice;

	//Importing sports cars
	if (menuChoice == 1)
	{
		try 
		{
			inFile.open("sportsCars.txt");
			if (inFile.fail())
			{
				throw 99;
			}
		}
		catch (int x)
		{
			cout << "Error opening file. ERROR NUMBER: " << x << endl;
			return false;
		}
		cin.ignore();

		int i = 0;
		while (!inFile.eof())
		{
			//Variables
			sportsCar* newCar = new sportsCar;
			int tempSerial, tempYear = 0;
			string tempMake, tempModel, convertible = "empty";

			//Import serial number
			inFile >> tempSerial;
			newCar->setSerial(tempSerial);

			//Import year
			inFile >> tempYear;
			newCar->setYear(tempYear);

			//Import make
			inFile.ignore();
			getline(inFile, tempMake);
			newCar->setMake(tempMake);

			//Import model
			getline(inFile, tempModel);
			newCar->setModel(tempModel);

			//See if it's convertible or not and set accordingly
			getline(inFile, convertible);
			if (convertible == "Convertible")
			{
				newCar->setTop(true);
			}
			else
			{
				newCar->setTop(false);
			}

			sportsVector.push_back(newCar);
		}
		cout << "Importing complete." << endl << endl;
		inFile.close();
		return true;
	}

	if (menuChoice == 2)
	{
		try
		{
			inFile.open("trucks.txt");
			if (inFile.fail())
			{
				throw 98;
			}
		}
		catch (int x)
		{
			cout << "Error opening file. ERROR NUMBER: " << x << endl;
			return false;
		}
		cin.ignore();

		int i = 0;
		while (!inFile.eof())
		{
			//Variables
			truck* newTruck = new truck;
			int tempSerial, tempYear = 0;
			string tempMake, tempModel, convertible = "empty";

			//Import serial number
			inFile >> tempSerial;
			newTruck->setSerial(tempSerial);

			//Import year
			inFile >> tempYear;
			newTruck->setYear(tempYear);

			//Import make
			inFile.ignore();
			getline(inFile, tempMake);
			newTruck->setMake(tempMake);

			//Import model
			getline(inFile, tempModel);
			newTruck->setModel(tempModel);

			//See if it's convertible or not and set accordingly
			getline(inFile, convertible);
			if (convertible == "Has roof")
			{
				newTruck->setFlatbed(true);
			}
			else
			{
				newTruck->setFlatbed(false);
			}
			truckVector.push_back(newTruck);
		}
		cout << "Importing complete." << endl << endl;
		inFile.close();
		return true;
	}
}

//Add vehicle
void inventory::addVehcile()
{
	cout << endl;
	int addChoice = 0;
	cout << "Add new sports car or vehicle?" << endl;
	cout << "1: Add sports car" << endl;
	cout << "2: Add truck" << endl;
	cin >> addChoice;

	if (addChoice == 1)
	{
		sportsCar* newCar = new sportsCar;

		cout << "You will now be prompted to enter information on the new vehicle." << endl;

		//Adding serial number
		int tempSerial = 0;
		cout << "Serial Number: ";
		cin >> tempSerial;
		newCar->setSerial(tempSerial);

		//Add year
		int tempYear = 0;
		cout << "Year: ";
		cin >> tempYear;
		newCar->setYear(tempYear);

		//Add make
		cin.ignore();
		string tempMake = "empty";
		cout << "Make: ";
		getline(cin, tempMake);
		newCar->setMake(tempMake);

		//Add model
		string tempModel = "empty";
		cout << "Model: ";
		getline(cin, tempModel);
		newCar->setModel(tempModel);

		//Convertible or not
		char convertible;
		cout << "Convertible? Enter Y for yes or N for no." << endl;
		cin >> convertible;
		if (convertible == 'Y' || convertible == 'y')
		{
			newCar->setTop(true);
		}
		else
		{
			newCar->setTop(false);
		}
		
		sportsVector.push_back(newCar);
	}

	else
	{
		truck* newTruck = new truck;

		cout << "You will now be prompted to enter information on the new vehicle." << endl;

		//Adding serial number
		int tempSerial = 0;
		cout << "Serial Number: ";
		cin >> tempSerial;
		newTruck->setSerial(tempSerial);

		//Add year
		int tempYear = 0;
		cout << "Year: ";
		cin >> tempYear;
		newTruck->setYear(tempYear);

		//Add make
		cin.ignore();
		string tempMake = "empty";
		cout << "Make: ";
		getline(cin, tempMake);
		newTruck->setMake(tempMake);

		//Add model
		string tempModel = "empty";
		cout << "Model: ";
		getline(cin, tempModel);
		newTruck->setModel(tempModel);

		//Convertible or not
		char roof;
		cout << "Flatbed roof? Enter Y for yes or N for no." << endl;
		cin >> roof;
		if (roof == 'Y' || roof == 'y')
		{
			newTruck->setFlatbed(true);
		}
		else
		{
			newTruck->setFlatbed(false);
		}

		truckVector.push_back(newTruck);
	}
	cout << endl;
}

//Delete vehicle
void inventory::deleteVehicle()
{
	cout << endl;

	int vectorChoice = 0;
	cout << "Find the entry you would like to delete." << endl;
	cout << "Search sports cars or trucks?" << endl;
	cout << "1: Sports cars" << endl;
	cout << "2: Trucks" << endl;
	cout << "Enter choice now: ";
	cin >> vectorChoice;
	int position = 0;

	position = searchInventory(vectorChoice);
	if (position == -1)
	{
		cout << "Entry not found." << endl;
	}

	else
	{
		//Delete from sports cars
		if (vectorChoice == 1)
		{
			sportsVector.erase(sportsVector.begin() + position);
		}

		//Delete from trucks
		else
		{
			truckVector.erase(truckVector.begin() + position);
		}
	}
	cout << endl;
}

//Search inventory - returns index number
int inventory::searchInventory(int vectorChoice)
{
	cout << endl;

	//Searching sports cars vector
	if (vectorChoice == 1)
	{
		//Submenu
		int searchChoice = 0;
		cout << "What would you like to search the inventory by?" << endl;
		cout << "1: Serial Number" << endl;
		cout << "2: Year" << endl;
		cout << "3: Make" << endl;
		cout << "4: Model" << endl;
		cout << "Enter choice now: ";
		cin >> searchChoice;

		//Serial number
		if (searchChoice == 1)
		{
			int searchValue = 0;
			cout << "Enter search term: ";
			cin >> searchValue;
			for (int i = 0; i < sportsVector.size(); i++)
			{
				if (sportsVector[i]->getSerial() == searchValue)
				{
					return i;
				}
			}
			return -1;
		}

		//Year
		if (searchChoice == 2)
		{
			int searchValue = 0;
			cout << "Enter search term: ";
			cin >> searchValue;
			for (int i = 0; i < sportsVector.size(); i++)
			{
				if (sportsVector[i]->getYear() == searchValue)
				{
					return i;
				}
			}
			return -1;
		}

		//Make
		if (searchChoice == 3)
		{
			cin.ignore();
			string searchValue;
			cout << "Enter search term: ";
			getline(cin, searchValue);
			for (int i = 0; i < sportsVector.size(); i++)
			{
				if (sportsVector[i]->getMake() == searchValue)
				{
					return i;
				}
			}
			return -1;
		}

		//Model
		if (searchChoice == 4)
		{
			cin.ignore();
			string searchValue;
			cout << "Enter search term: ";
			getline(cin, searchValue);
			for (int i = 0; i < sportsVector.size(); i++)
			{
				if (sportsVector[i]->getModel() == searchValue)
				{
					return i;
				}
			}
			return -1;
		}
	}

	//Search trucks vector
	else
	{
		//Submenu
		int searchChoice = 0;
		cout << "What would you like to search the inventory by?" << endl;
		cout << "1: Serial Number" << endl;
		cout << "2: Year" << endl;
		cout << "3: Make" << endl;
		cout << "4: Model" << endl;
		cout << "Enter choice now: ";
		cin >> searchChoice;

		//Serial number
		if (searchChoice == 1)
		{
			int searchValue = 0;
			cout << "Enter search term: ";
			cin >> searchValue;
			for (int i = 0; i < truckVector.size(); i++)
			{
				if (truckVector[i]->getSerial() == searchValue)
				{
					return i;
				}
			}
			return -1;
		}

		//Year
		if (searchChoice == 2)
		{
			int searchValue = 0;
			cout << "Enter search term: ";
			cin >> searchValue;
			for (int i = 0; i < truckVector.size(); i++)
			{
				if (truckVector[i]->getYear() == searchValue)
				{
					return i;
				}
			}
			return -1;
		}

		//Make
		if (searchChoice == 3)
		{
			cin.ignore();
			string searchValue;
			cout << "Enter search term: ";
			getline(cin, searchValue);
			for (int i = 0; i < truckVector.size(); i++)
			{
				if (truckVector[i]->getMake() == searchValue)
				{
					return i;
				}
			}
			return -1;
		}

		//Model
		if (searchChoice == 4)
		{
			cin.ignore();
			string searchValue;
			cout << "Enter search term: ";
			getline(cin, searchValue);
			for (int i = 0; i < truckVector.size(); i++)
			{
				if (truckVector[i]->getModel() == searchValue)
				{
					return i;
				}
			}
			return -1;
		}
	}

	cout << endl;
}

//Needed extra sorting methods
bool sortSports(const sportsCar* lhs, const sportsCar* rhs)
{
	return lhs->getSerial() < rhs->getSerial();
}

bool sortTrucks(const truck* lhs, const truck* rhs)
{
	return lhs->getSerial() < rhs->getSerial();
}

//Sort inventory
void inventory::sortInventory(int sortChoice)
{
	//Sort - uses generic sort algorithm, sorts by serial number
	cout << endl;
	cout << "Sorting..." << endl;
	if (sortChoice == 1)
	{
		sort(sportsVector.begin(), sportsVector.end(), sortSports);
	}

	else
	{
		sort(truckVector.begin(), truckVector.end(), sortTrucks);
	}
	cout << "Sorting complete." << endl << endl;
}

//Export to file
void inventory::printInventory()
{
	cout << endl;
	cout << "Printing to file..." << endl;

	ofstream outFile;
	outFile.open("inventoryOutput.txt");

	//Outputting sports cars
	outFile << "Sports cars: " << endl;
	if (!sportsVector.empty())
	{
		for (int i = 0; i < sportsVector.size(); i++)
		{
			outFile << sportsVector[i]->getSerial() << endl;
			outFile << sportsVector[i]->getYear() << endl;
			outFile << sportsVector[i]->getMake() << endl;
			outFile << sportsVector[i]->getModel() << endl;
			if (sportsVector[i]->getTop() == true)
			{
				outFile << "Convertible" << endl;
			}
			else if (sportsVector[i]->getTop() == false)
			{
				outFile << "Not convertible" << endl;
			}
		}
	}

	else
	{
		outFile << "No sports cars in inventory." << endl;
	}

	outFile << endl;
	//Outputting trucks
	outFile << "Trucks: " << endl;
	if (!truckVector.empty())
	{
		for (int i = 0; i < truckVector.size(); i++)
		{
			outFile << truckVector[i]->getSerial() << endl;
			outFile << truckVector[i]->getYear() << endl;
			outFile << truckVector[i]->getMake() << endl;
			outFile << truckVector[i]->getModel() << endl;
			if (truckVector[i]->getFlatbed() == true)
			{
				outFile << "Has roof" << endl;
			}
			else if (truckVector[i]->getFlatbed() == false)
			{
				outFile << "No roof" << endl;
			}
		}
	}

	else
	{
		outFile << "No trucks in inventory." << endl;
	}

	//Wrapping it all up...
	outFile.close();
	cout << "Printing complete." << endl << endl;
}

//Printing to screen
template <class display>
display inventory::displayInventory(display vector)
{
	cout << endl;
	cout << vector << endl;
	return vector;
}

//Friend functions
ostream& operator << (ostream& out, vector<sportsCar*>_vector)
{
	for (int i = 0; i < _vector.size(); i++)
	{
		out << "Serial Number: " << _vector[i]->getSerial() << endl;
		out << "Year: " << _vector[i]->getYear() << endl;
		out << "Make: " << _vector[i]->getMake() << endl;
		out << "Model: " << _vector[i]->getModel() << endl;
		if (_vector[i]->getTop() == true)
		{
			out << "Convertible top" << endl;
		}
		else
		{
			out << "No convertible top" << endl;
		}
	}
	return out;
}

ostream& operator << (ostream& out, vector<truck*>_vector)
{
	for (int i = 0; i < _vector.size(); i++)
	{
		out << "Serial Number: " << _vector[i]->getSerial() << endl;
		out << "Year: " << _vector[i]->getYear() << endl;
		out << "Make: " << _vector[i]->getMake() << endl;
		out << "Model: " << _vector[i]->getModel() << endl;
		if (_vector[i]->getFlatbed() == true)
		{
			out << "Flatbed roof" << endl;
		}
		else
		{
			out << "No flatbed roof" << endl;
		}
	}
	return out;
}