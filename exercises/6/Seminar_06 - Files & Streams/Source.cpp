
#include <fstream>
#include <iostream>

#include"Point.h"

int main()
{
	std::ifstream points("Resource/points.txt");

	//��� ��������� �������� �� ����� ,���������� ���������
	if (!points.is_open()) {

		std::cout << "can't open the file!\n";
		return -1;
	}

	size_t size;
	points >> size;

	//�������� ����� �� ������ ���� �����
	Point* pntArr = new Point[size];

	for (size_t i = 0; i < size; i++) {

		//��� ����� �������� � �������� ����� �������� 
		//���������� ������� ����� � ������������ ������������ �� ����������
		if (!points.good()){

			delete[] pntArr;
			points.close();
			return -1;
		}
		//��������� ������������� �� ����� �����
		points >> pntArr[i].x >> pntArr[i].y;
	}

	//��������� �������� ����������, ���������� � ����������� ����������
	std::cout << "the index of the closest point is : "
		<< closestPoint(pntArr, size);

	delete[] pntArr;
	points.close();
	return 0;
}