#include "vehicles.h"


//*****************************************************************
//	Vehicle implementation
//*****************************************************************
vehicle::vehicle()
{
	serialNumber, year = 0;
	string make, model = "empty";
}

vehicle::vehicle(int _serial, int _year, string _make, string _model)
{
	serialNumber = _serial;
	year = _year;
	make = _make;
	model = _model;
}

void vehicle::setSerial(int _serial)
{
	serialNumber = _serial;
}

void vehicle::setYear(int _year)
{
	year = _year;
}

void vehicle::setMake(string _make)
{
	make = _make;
}

void vehicle::setModel(string _model)
{
	model = _model;
}

int vehicle::getSerial() const
{
	return serialNumber;
}

int vehicle::getYear() const
{
	return year;
}

string vehicle::getMake() const
{
	return make;
}

string vehicle::getModel() const
{
	return model;
}

//*****************************************************************
//	sportsCar implementation
//*****************************************************************
sportsCar::sportsCar() 
{
	convertibleTop = false;
}

sportsCar::sportsCar(bool _hasTop)
{
	convertibleTop = _hasTop;
}

void sportsCar::setTop(bool _hasTop)
{
	convertibleTop = _hasTop;
}

bool sportsCar::getTop() const
{
	return convertibleTop;
}

//*****************************************************************
//	Truck implementation
//*****************************************************************

truck::truck()
{
	flatbedRoof = false;
}

truck::truck(bool _hasRoof)
{
	flatbedRoof = _hasRoof;
}

void truck::setFlatbed(bool _hasRoof)
{
	flatbedRoof = _hasRoof;
}

bool truck::getFlatbed() const
{
	return flatbedRoof;
}