#pragma once
#include "Employee.h"
#include "Client.h"
#include "File.h"
#include <list>

class PostOfficeBranch
{
private:
	File data;
	int time;
	int numberProvider = 1;
	list<Employee> employees;
	Client* firstInLine;
	Client* newRandClient();
	Client* InsertClientBehind(Client* position, Client* toInsert);
	Client* RemoveFromQueue(Client* position, Client* toRemove, bool deleteClient);
	Client* PickNextClient(Employee* employee);
public:
	void Initialize(int employeeAmount);
	void AddClientToQueue(Client* client);
	Client* GetFirstInQueue();
	void CycleTime(); //the looping method, advances 1 minute
	void PrintTime();
	void SaveQueueData();
	void LoadQueueData();
	void InspectQueue();
};

