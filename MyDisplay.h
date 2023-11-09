#pragma once
#include <string>

using namespace std;

class MyDisplay{
    public:
        MyDisplay(string Title, string button1, string button2, string button3, string button4, string button5, string button6);

    private:
        void addLind(void);
        void TitleLind(string titleText);
        string ButtonText(string Text);
        void ButtonLind(string buttonText1, string buttonText2);
};