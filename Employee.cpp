#include "Employee.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>


Employee::Employee(int id)
{
	_id = id;
	cout << endl << "employee ";
	for (int i = 0; i < 4; i++)
	{
		skills[i] = rand() % 3 > 0;
		cout << skills[i];
	}
}

Employee::Employee(int id, bool skill1, bool skill2, bool skill3, bool skill4)
{
	_id = id;
	skills[0] = skill1;
	skills[1] = skill2;
	skills[2] = skill3;
	skills[3] = skill4;
}

int Employee::GetID() const
{
	return _id;
}

void Employee::SetClient(Client* client)
{
	handledClient = client;
	if (client == NULL) return;
	EstimateProcessTime(handledClient->GetRequest());
	cout << "Employee " << _id << " has started handling client " << handledClient->GetNumber() << " request" << endl;
}

void Employee::EstimateProcessTime(int process)
{
	processTimeLeft = rand() % 3 + 4 + process; //random simple algorithm, returns between 4 and 6 plus processID
}

void Employee::HandleClient()
{
	if (handledClient == NULL) {
		cout << "Employee isnt busy; ";
	}
	else {
		processTimeLeft--;
		if (processTimeLeft == 0) {
			cout << "Employee " << _id << " completed the request of client " << handledClient->GetNumber() << endl;
			hasHandledSenior = handledClient->GetAge() > 65;
			handledClient = NULL;
		}
	}
}

bool Employee::CheckHasClient()
{
	return handledClient != NULL;
}

bool Employee::CheckSkills(int skill)
{
	return skills[skill];
}

bool Employee::GetHasHandledSeniorLast()
{
	return hasHandledSenior;
}
