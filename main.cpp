#include <iostream>
#include "MyDisplay.h"
#include "WordCode.h"

using namespace std;

int main(){

	string key;

	system("clear");

	WordCode Game;
	Game.Start();
	MyDisplay x(Game.DisplayText,Game.buttonTable[0][0],Game.buttonTable[0][1],Game.buttonTable[1][0],Game.buttonTable[1][1],Game.buttonTable[2][0],Game.buttonTable[2][1]);


	bool KeyIsFind = false;

	do{
		cout << "\nKey: ";
		cin >> key;
		KeyIsFind = Game.keyIs(key);

		if(KeyIsFind){
			cout << "\nKey is found!\n";
		}else{
			cout << "\n!!Key is not found!!\n";
		}

	}while(!KeyIsFind);


	return 0;
}

