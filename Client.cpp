#include "Client.h"
#include <stdlib.h>
#include <iostream>

Client::Client()
{
	_request = rand() % 4;
	_birthYear = rand() % 60 + 1944;
	_number = 0;
	nextInLine = NULL;
}

Client::Client(int request, int birthYear, int number)
{
	_request = request;
	_birthYear = birthYear;
	_number = number;
	nextInLine = NULL;
}

int Client::GetRequest()
{
	return _request;
}

int Client::GetAge()
{
	return 2024 - _birthYear;
}

std::string Client::GetRequestString()
{
	switch (_request)
	{
	case 0:
		return "recieve packages";
	case 1:
		return "send packages";
	case 2:
		return "perform payments";
	case 3:
		return "purchase products";
	default:
		return NULL;
	}
}

void Client::SetNumber(int num)
{
	_number = num;
}

int Client::GetNumber()
{
	return _number;
}

Client* Client::GetNextClient()
{
	return nextInLine;
}

void Client::SetNextClient(Client* client)
{
	nextInLine = client;
}
