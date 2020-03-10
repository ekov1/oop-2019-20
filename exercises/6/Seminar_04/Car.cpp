#include "Car.h"
#include <iostream>

Car::Car( unsigned int horsePower, double volume, EngineType type,
		unsigned int doorCount, bool hasWing, const char * color,
		const char * name, const char * model, unsigned int year,
		bool isNew, unsigned int price ) :
		fEngineDetails(horsePower, volume, type), // ��� �� ���� ����������� � ��������� �� EngineDetails �����
		fVisualDetails(doorCount, hasWing, color), // ��� �� ���� ����������� � ��������� �� VisualDetails �����
		fManufactureDetails(name, model, year), // ��� �� ���� ����������� � ��������� �� ManufactureDetails �����
		fIsNew(isNew), fPrice(price) // ���������� ��������� �� ������������� ��� ����������� ����
{
	std::cout << "Constuctor Car" << std::endl;
}

Car::Car( const EngineDetails& engineDetails,
		const VisualDetails & visualDetails, 
		const ManufactureDetails & manufactureDetails, 
		bool isNew, unsigned int price ) : 
		fEngineDetails(engineDetails), // ��� �� ���� ��������� ���� ���������� �� EngineDetails �����
		fVisualDetails(visualDetails), // ��� �� ���� ��������� ���� ���������� �� VisualDetails �����
		fIsNew(isNew), fPrice(price)
		// ���� ���� �� ���� � ��������� ���������� �� ManufactureDetails, �� �� �� ������� ������ fManufactureDetails
{
	fManufactureDetails = manufactureDetails; // ���� ���� ���� � ��������� ������, ��� �� ���� operator= �� ManufactureDetails �����
	std::cout << "Constuctor Car" << std::endl;
}

// �� � ������������, ������ ������ ��������� �����, ����� �� �����
// ����, �� ����� �� �������� �� ����� �� ������ ��������� ��������� �����, 
// ��� (�������������) ������ �� ���� ����������, �� �� ������(��� �����������)
// � ������������� �� ��������� �� ����������� ������
Car::~Car()
{
	std::cout << "Destructor Car" << std::endl;
}
