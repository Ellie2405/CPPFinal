#include "PostOfficeBranch.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

PostOfficeBranch branch;
char input;

//game of mail
int main() {
	srand((unsigned)time(NULL)); //initialize random seed
	branch.Initialize(4);
	cout << endl;
	while (true) {
		input = _getch();
		if (input == 'n') {
			//add client to queue
			branch.AddClientToQueue(NULL);
			continue;
		}
		else if (input == 'r') {
			//remove first in queue
			branch.GetFirstInQueue();
			continue;
		}
		else if (input == 'x') {
			//stop simulation
			break;
		}
		else if (input == 's') {
			//save queue
			branch.SaveQueueData();
			continue;
		}
		else if (input == 'l') {
			//load queue
			branch.LoadQueueData();
			continue;
		}
		else if (input == 'i') {
			//inspect queue
			branch.InspectQueue();
			continue;
		}
		branch.CycleTime();
		cout << endl;
	}


}