#pragma once

#include "Starship.h"
#include "MotherShip.h"

class Interceptor : public Starship
{
	//<<<< ����������� �� ����� �� �� ���������� � ������
	Interceptor();
	Interceptor(const Interceptor &other) = delete;
	Interceptor& operator=(const Interceptor &other) = delete;
	//<<<<

	int attacks_count = 0;
public:
	virtual void attack() override;
	virtual void printInfo() override;

	friend class MotherShip;
};