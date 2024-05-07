#pragma once
#include <string>

class Client
{
private:
	int _request;
	int _birthYear;
	int _number;
	Client* nextInLine;
public:
	Client();
	Client(int request, int birthYear, int number);
	int GetRequest();
	int GetAge();
	std::string GetRequestString();
	void SetNumber(int num);
	int GetNumber();
	Client* GetNextClient();
	void SetNextClient(Client* client);
	void ForfeitPosition();
};

