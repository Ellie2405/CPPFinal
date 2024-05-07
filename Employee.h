#pragma once
#include "Client.h"
#include <list>

using namespace std;

class Employee
{
private:
	int _id;
	bool skills[4]; // 0:collect package; 1:send package; 2:make payment; 3:buy products
	bool isBusy = false;
	bool hasHandledSenior = true;
	int processTimeLeft = 0;
	Client* handledClient = NULL;
public:
	Employee(int id);
	Employee(int id, bool skill1, bool skill2, bool skill3, bool skill4);
	int GetID() const;
	void SetClient(Client* client);
	void EstimateProcessTime(int process);
	void HandleClient();
	bool CheckHasClient();
	bool CheckSkills(int skill);
	bool GetHasHandledSeniorLast();
};

