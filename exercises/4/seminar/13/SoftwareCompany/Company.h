#pragma once

#include "Employee.h"
#include "Project.h"

class Company {
public:
	static Company sharedInstance;

	void addClient(const Client& newClient);
	void addEmployee(Employee* newEmployee);
	void addProject(const Project& newProject);

	Project& getProject(const char* name);
	Client& getClient(const char* name);
	Employee& getEmployee(const char* name);

	void work();
private:
	Company();
	Company(const Company& other) = delete;
	Company& operator=(const Company& other) = delete;
	~Company();

	Vector<Employee*> employees;
	Vector<Client> clients;
	Vector<Project> projects;
};

