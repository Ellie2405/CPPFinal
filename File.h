#pragma once
#include "Client.h"

class File
{
private:
public:
	void SaveToFile(Client* line);
	Client* LoadFile();
};

