#include <iostream>
#include <string>
#include "MyDisplay.h"

using namespace std;

MyDisplay::MyDisplay(string Title, string button1, string button2, string button3, string button4, string button5, string button6){
    this->addLind();
	this->TitleLind(Title);
	this->addLind();
	this->ButtonLind(button1, button2);
	this->addLind();
	this->ButtonLind(button3, button4);
	this->addLind();
	this->ButtonLind(button5, button6);
	this->addLind();
}

void MyDisplay::addLind(){
    cout << "+-----------------------------+" << endl;
}

void MyDisplay::ButtonLind(string buttonText1, string buttonText2){
	cout << "|"<< this->ButtonText(buttonText1) <<"|"<< this->ButtonText(buttonText2) <<"|" << endl;
}

string MyDisplay::ButtonText(string Text){
	const int maxTal = 14;
	int newMaxTal = maxTal - Text.length() + 1;
	int imellem = newMaxTal/2;
	bool ifContinueLoop = true;
	string newText;
	
	for(int i = 0; i<imellem;i++){
		if (ifContinueLoop && (newMaxTal % 2) == 0){
			ifContinueLoop = false;
			continue;
		}
		newText.append(" ");
	}

	newText.append(Text);

	for(int i = 0; i<imellem;i++){
		newText.append(" ");
	}

	return newText;
}


void MyDisplay::TitleLind(string titleText){
	const int maxTal = 30;
	int newMaxTal = maxTal - titleText.length();
	int imellem = newMaxTal/2;
	bool ifContinueLoop = true;
	string text;
	
	for(int i = 0; i<imellem;i++){
		if (ifContinueLoop && (newMaxTal % 2) == 0){
			ifContinueLoop = false;
			continue;
		}
		text.append(" ");
	}

	text.append(titleText);

	for(int i = 0; i<imellem;i++){
		text.append(" ");
	}

	cout << "|"<< text <<"|" << endl;
}