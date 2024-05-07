#include "PostOfficeBranch.h"
#include "Client.h"
#include <iostream>
#include <string>

using namespace std;

Client* PostOfficeBranch::newRandClient()
{
	return new Client;
}

Client* PostOfficeBranch::InsertClientBehind(Client* position, Client* toInsert)
{
	if (position == NULL) {
		toInsert->SetNumber(numberProvider++);
		return toInsert;
	}
	position->SetNextClient(InsertClientBehind(position->GetNextClient(), toInsert));
	return position;
}

Client* PostOfficeBranch::RemoveFromQueue(Client* position, Client* toRemove, bool deleteClient)
{
	if (position == NULL) {
		cout << "client toRemove not found";
		return position;
	}
	else if (position != toRemove) {
		position->SetNextClient(RemoveFromQueue(position->GetNextClient(), toRemove, deleteClient));
		return position;
	}
	else {
		Client* temp = position->GetNextClient();
		if (deleteClient) delete position;
		return temp;
	}
}

Client* PostOfficeBranch::PickNextClient(Employee* employee)
{
	Client* temp;
	if (!employee->GetHasHandledSeniorLast()) {
		temp = firstInLine;
		while (temp != NULL) {
			if (temp->GetAge() > 65 && employee->CheckSkills(temp->GetRequest())) {
				firstInLine = RemoveFromQueue(firstInLine, temp, false);
				return temp;
			}
			temp = temp->GetNextClient();
		}
	}
	temp = firstInLine;
	while (temp != NULL) {
		if (employee->CheckSkills(temp->GetRequest())) {
			firstInLine = RemoveFromQueue(firstInLine, temp, false);
			return temp;
		}
		temp = temp->GetNextClient();
	}
	return temp;
}

void PostOfficeBranch::Initialize(int employeeAmount)
{
	time = 0;
	PrintTime();
	for (int i = 0; i < employeeAmount;)
	{
		Employee e(++i);
		employees.push_back(e);
	}
}

void PostOfficeBranch::AddClientToQueue(Client* client)
{
	if (client == NULL) {
		firstInLine = InsertClientBehind(firstInLine, client = newRandClient());
	}
	else {
		firstInLine = InsertClientBehind(firstInLine, client);
	}

	if (client->GetAge() > 65) cout << "Senior ";
	cout << "Client #" << client->GetNumber() << " entered the queue to " << client->GetRequestString() << endl;
}

Client* PostOfficeBranch::GetFirstInQueue()
{
	if (firstInLine == NULL) {
		cout << "queue empty" << endl;
		return NULL;
	}
	Client* first = firstInLine;
	firstInLine = RemoveFromQueue(firstInLine, firstInLine, false);
	return first;
}

void PostOfficeBranch::CycleTime()
{
	time++;
	PrintTime();
	for (list<Employee>::iterator i = employees.begin(); i != employees.end(); i++)
	{
		if (i->CheckHasClient()) {
			i->HandleClient();
		}
		else {
			i->SetClient(PickNextClient(&*i));
		}
	}
}

void PostOfficeBranch::PrintTime()
{
	cout << time / 60 + 7 << ':' << time % 60 / 10 << time % 10 << ' ';
}

void PostOfficeBranch::SaveQueueData()
{
	data.SaveToFile(firstInLine);
}

void PostOfficeBranch::LoadQueueData()
{
	firstInLine = data.LoadFile();
}

void PostOfficeBranch::InspectQueue()
{
	cout << "printing queue:" << endl;
	int counter = 0;
	Client* temp = firstInLine;
	while (temp != NULL) {
		counter++;
		if (temp->GetAge() > 65) cout << "Senior";
		cout << "Client " << temp->GetNumber() << " age " << temp->GetAge() << " waiting to " << temp->GetRequestString() << endl;
		temp = temp->GetNextClient();
	}
	cout << "There are " << counter << " clients in the queue" << endl;
}
