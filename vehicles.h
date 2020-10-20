#ifndef VEHICLE_
#define VEHICLE_

#include <string>
using namespace std;
class vehicle 
{
private:
	int serialNumber, year;
	string make, model;

public:
	//default constructor
	vehicle();

	//constructor to set private members
	vehicle(int, int, string, string);

	//Mutators
	void setSerial(int);
	void setYear(int);
	void setMake(string);
	void setModel(string);

	//Accessors
	int getSerial() const;
	int getYear() const;
	string getMake() const;
	string getModel() const;
};

class sportsCar : public vehicle 
{
private:
	bool convertibleTop;
public:
	//default constructor
	sportsCar();

	//construct w/ parameter
	sportsCar(bool);

	//Accessor and mutator
	void setTop(bool);
	bool getTop() const;
};

class truck :public vehicle
{
private:
	bool flatbedRoof;
public:
	//default constructor
	truck();

	//constructor w/ parameter
	truck(bool);

	//Accessor and mutator
	void setFlatbed(bool);
	bool getFlatbed() const;
};
#endif // !VEHICLE_
