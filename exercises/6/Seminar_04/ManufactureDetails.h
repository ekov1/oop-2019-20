#pragma once

#define CURRENT_YEAR (2020)

class ManufactureDetails
{
	char* fName;
	char* fModel;
	unsigned int fYear;

public:
	// THE BIG 4
	// ������������� �� ���������� �����������, ��������= � ����������, 
	// ������ ����� ��������� ����� � ������ �� �� �������� ���� �� �������.
	// ���� ������ ���������� ���������� life cycle �� �������� �� ���� ���
	ManufactureDetails();
	ManufactureDetails( const char*, const char*, unsigned int );
	ManufactureDetails( const ManufactureDetails& );
	ManufactureDetails& operator=( const ManufactureDetails& );
	~ManufactureDetails();

	void print() const;

private:
	void init( const char*, const char*, unsigned int );
	void clean();
};

