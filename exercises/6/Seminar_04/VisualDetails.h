#pragma once

#define MAX_SIZE (50)

struct VisualDetails
{
	unsigned int fDoorCount;
	bool fHasWing;
	char fColor[ MAX_SIZE + 1 ];

	VisualDetails( unsigned int, bool, const char* );
	~VisualDetails();

	// ������ � ���� ��������� � ��������, �� ��� ��� ���� �� �� �������� set-�� �� �����, ���� �� ����� ������ �� fColor
	void setColor( const char* );

};

