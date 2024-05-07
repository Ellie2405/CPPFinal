#include "File.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

void File::SaveToFile(Client* line)
{
	int counter = 0;
	Client* client = line;
	ofstream outfile("data.txt");
	if (outfile.is_open()) {
		while (client != NULL) {
			outfile << client->GetRequest() << " " << 2024 - client->GetAge() << " " << client->GetNumber() << endl;
			client = client->GetNextClient();
			counter++;
		}
		cout << "Saved " << counter << " clients successfully" << endl;
		outfile.close();
	}
}

Client* File::LoadFile()
{
	int counter = 0;
	Client* output = NULL;
	Client* latest = NULL;
	string line;
	ifstream infile("data.txt");
	if (infile.is_open()) {
		while (getline(infile, line)) {
			counter++;
			stringstream ss(line);
			int i1, i2, i3;

			ss >> i1 >> i2 >> i3;

			Client* temp = new Client(i1, i2, i3);
			if (output == NULL) {
				output = temp;
				latest = output;
				continue;
			}

			latest->SetNextClient(temp);
			latest = temp;
		}
		cout << "loaded " << counter << " clients" << endl;
		infile.close();
	}
	return output;
}
