#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>

struct Student {

	char name[24];
	unsigned int fn;
};

//���� ��������� �� ���� ������� ����
//� ����� �� ������, ����� get position-�� � �������� �� �����
size_t getFileLen( std::ifstream& ifs )
{ //����� �� �������� ���� �������� ����� �� �������

	ifs.seekg( 0, std::ios::end ); //������ �� � ���� �� �����
	size_t size = ifs.tellg(); //������� �������� �������
	ifs.seekg( 0, std::ios::beg ); //������� �� � ��������

	return size;
}

//������� ������� �������� � ������� ����
//������� ���� ����� ��, ���� �������� ������� ����������
//�� �����
//����� true ��� ������� ���������, false �����
bool writeStudents( const char* path )
{

	std::ofstream ofs( path, std::ios::binary | std::ios::trunc );

	if ( !ofs.is_open() ) //�������� ���� � ������� ������� ������
		return false;

	//������� �������� �������
	Student students[] = {

		{ "Yasen", 45460 },
		{ "Stefan", 45728 },
		{ "Gosho", 71433}

	};

	//��������� �� ��� ����� ���� �� ����
	//size_t size = sizeof(students) / sizeof(Student);
	//for (size_t i = 0; i < size; i++)
	//ofs.write((const char*)&students[i], sizeof(Student));

	//���� �� �� ����� �� �� ������� � ������ �������� :
	ofs.write( (const char*) students, sizeof( students ) ); //students � �������� �� ������
														//���� ����� �� & �� �� ������ ������

	if ( !ofs.good() ) // ����������� ���� ���� ���������� ������� � � ���������� ���������
		return false;

	ofs.close();
	return true;
}


//���� ���������� ������������� ���� �������� �������� � ������� ����
bool readStudents( const char* path )
{

	std::ifstream ifs( path, std::ios::binary );

	if ( !ifs.is_open() )
		return false;

	size_t fileSize = getFileLen( ifs ); // ����� ���� �������� �������

	if ( fileSize == 0 )
		return false;

	size_t objCount = fileSize / sizeof( Student ); // ����� ���� ������

	Student* students; //��� �� �������� ����������

	students = new Student[ objCount ];

	//��������� �� �� ����� � ������ 
	ifs.read( (char*) students, fileSize );

	if ( !ifs ) //��� �������� �� � ���� �������
		return false;

	for ( size_t i = 0; i < objCount; i++ )
		std::cout << students[ i ].name << ' '
		<< students[ i ].fn << std::endl;

	ifs.seekg( std::ios::beg ); // ����������� ��� �������� �� ������ � �������� �� �����
	//����� � �� �������� ����� ���� ������� �� ���������� ������� �� �����
	srand( time( nullptr ) );
	size_t randomIndex = rand() % objCount; // �������� ������ ������
	ifs.seekg( randomIndex * sizeof( Student ) ); // ����������� �������� �� ������ ������� ����� �� ��������, ������� �� ������ randomIndex ��������


	Student singleStudent; // ��������� �� �������
	// Student* singleStudent = new Student; // ����� � ��������� �� �����
	ifs.read( (char*) &singleStudent, sizeof( Student ) );
	//ifs.read( (char*) singleStudent, sizeof( Student ) ); // ���� ����� �� & �� �� ������ ������ �� ������������, 
															//�� ���� �� � ����� � ���� �������� ��� char*

	std::cout << singleStudent.name << ' '
		<< singleStudent.fn << std::endl;

	//������������� ���������
	delete[] students;
	ifs.close();
	return true;
}

bool writeStudentsInEndOfFile( const char* path )
{
	std::ofstream ofs( path, std::ios::binary | std::ios::app ); // ������� � std::ios::ate
	//'app' comes from 'append' - all output will be added (appended) to the end of the file. 
	// In other words you cannot write anywhere else in the file but at the end.
	//'ate' comes from 'at end' - it sets the stream position at the end of the file when you open it,
	// but you are free to move it around (seek) and write wherever it pleases you.

	if ( !ofs.is_open() ) //�������� ���� � ������� ������� ������
		return false;

	//������� �������� �������
	Student students[] = {

		{ "Ivo", 45260 },
		{ "Viktoria", 45726 },
		{ "Petar", 61433 }
	};

	//��������� �� ��� ����� ���� �� ����
	//size_t size = sizeof(students) / sizeof(Student);
	//for (size_t i = 0; i < size; i++)
	//ofs.write((const char*)&students[i], sizeof(Student));

	//���� �� �� ����� �� �� ������� � ������ �������� :
	ofs.write( (const char*) students, sizeof( students ) ); //students � �������� �� ������
															 //���� ����� �� & �� �� ������ ������

	if ( !ofs.good() ) // ����������� ���� ���� ���������� ������� � � ���������� ���������
		return false;

	ofs.close();
	return true;
}


int main()
{

	if ( writeStudents( "students.bin" ) )
	{
		std::cout << "successfully written!\n";
	}
	else
	{
		std::cout << "error while writing\n";
	}

	std::cout << "trying to read the information ...\n";

	if ( !readStudents( "students.bin" ) )
	{
		std::cout << "error while reading";
	}

	if ( writeStudentsInEndOfFile( "students.bin" ) )
	{
		std::cout << "successfully written of the end of file!\n";
	}
	else
	{
		std::cout << "error while writing\n";
	}

	return 0;
}