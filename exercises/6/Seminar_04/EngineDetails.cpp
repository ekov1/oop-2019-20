#include "EngineDetails.h"
#include <iostream>

EngineDetails::EngineDetails( unsigned int horsePower, double volume, EngineType type) : // ��������� ������������� ������
	fHorsePower(horsePower),
	fVolume(volume),
	fEngineType(type)
{
	std::cout << "Constuctor EngineDetails" << std::endl;
}

// �� � ������������, ������ ������ ��������� �����, ����� �� �����
EngineDetails::~EngineDetails()
{
	std::cout << "Destructor EngineDetails" << std::endl;
}
