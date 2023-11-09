#pragma once
#include <string>
#include <vector>

using namespace std;

struct DisplayData {
	string text;
	int row;
	int col;
};

struct ButtonData {
	string text;
	vector<string> buttonList;
};

class WordCode{
    public:
        string DisplayText;
        string buttonTable[3][2];
        WordCode();
        void Start();
        bool keyIs(string key);

    private:
        vector<DisplayData> display;
        vector<ButtonData> button;
        DisplayData NewDisplay;
        ButtonData NewButton;
        string xWord;
        void LoadData();
        void LoadButton(string text, string buttonList[]);
        void LoadDisplay(string dis, int row, int col);
        int randomTal(int x);
        void findButton();
        void findXWord();
};
