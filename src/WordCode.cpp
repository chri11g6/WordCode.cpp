#include "WordCode.h"
#include <algorithm>
#include <random>
#include <cstring>

string str_toupper(string s) {
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::toupper(c); });

    return s;
}

WordCode::WordCode(){
    this->LoadData();
}

// Loader all nødvendig data
void WordCode::LoadData(){
    // loader display data.
    this->LoadDisplay("YES", 1, 0);
    this->LoadDisplay("FIRST", 0, 1);
    this->LoadDisplay("DISPLAY", 2, 1);
    this->LoadDisplay("OKAY", 0, 1);
    this->LoadDisplay("SAYS", 2, 1);
    this->LoadDisplay("NOTHING", 1, 0);
    this->LoadDisplay(" ", 2, 0);
    this->LoadDisplay("BLANK", 1, 1);
    this->LoadDisplay("NO", 2, 1);
    this->LoadDisplay("LED", 1, 0);
    this->LoadDisplay("LEAD", 2, 1);
    this->LoadDisplay("READ", 1, 1);
    this->LoadDisplay("RED", 1, 1);
    this->LoadDisplay("REED", 2, 0);
    this->LoadDisplay("LEED", 2, 0);
    this->LoadDisplay("HOLD ON", 2, 1);
    this->LoadDisplay("YOU", 1, 1);
    this->LoadDisplay("YOU ARE", 2, 1);
    this->LoadDisplay("YOUR", 1, 1);
    this->LoadDisplay("YOU'RE", 1, 1);
    this->LoadDisplay("UR", 0, 0);
    this->LoadDisplay("THERE", 2, 1);
    this->LoadDisplay("THEY'RE", 2, 0);
    this->LoadDisplay("THEIR", 1, 1);
    this->LoadDisplay("THEY ARE", 1, 1);
    this->LoadDisplay("SEE", 2, 1);
    this->LoadDisplay("C", 0, 1);
    this->LoadDisplay("CEE", 2, 1);

    // loader button data.
    string x[14] = { "YES", "OKAY", "WHAT", "MIDDLE", "LEFT", "PRESS", "RIGHT", "BLANK", "READY", "NO", "FIRST", "UHHH", "NOTHING", "WAIT" };
    this->LoadButton("READY", x);
    string x2[14] = { "LEFT", "OKAY", "YES", "MIDDLE", "NO", "RIGHT", "NOTHING", "UHHH", "WAIT", "READY", "BLANK", "WHAT", "PRESS", "FIRST" };
    this->LoadButton("FIRST", x2);
    string x3[14] = { "BLANK", "UHHH", "WAIT", "FIRST", "WHAT", "READY", "RIGHT", "YES", "NOTHING", "LEFT", "PRESS", "OKAY", "NO", "MIDDLE" };
    this->LoadButton("NO", x3);
    string x4[14] = { "WAIT", "RIGHT", "OKAY", "MIDDLE", "BLANK", "PRESS", "READY", "NOTHING", "NO", "WHAT", "LEFT", "UHHH", "YES", "FIRST" };
    this->LoadButton("BLANK", x4);
    string x5[14] = { "UHHH", "RIGHT", "OKAY", "MIDDLE", "YES", "BLANK", "NO", "PRESS", "LEFT", "WHAT", "WAIT", "FIRST", "NOTHING", "READY" };
    this->LoadButton("NOTHING", x5);
    string x6[14] = { "OKAY", "RIGHT", "UHHH", "MIDDLE", "FIRST", "WHAT", "PRESS", "READY", "NOTHING", "YES", "LEFT", "BLANK", "NO", "WAIT" };
    this->LoadButton("YES", x6);
    string x7[14] = { "UHHH", "WHAT", "LEFT", "NOTHING", "READY", "BLANK", "MIDDLE", "NO", "OKAY", "FIRST", "WAIT", "YES", "PRESS", "RIGHT" };
    this->LoadButton("WHAT", x7);
    string x8[14] = { "READY", "NOTHING", "LEFT", "WHAT", "OKAY", "YES", "RIGHT", "NO", "PRESS", "BLANK", "UHHH", "MIDDLE", "WAIT", "FIRST" };
    this->LoadButton("UHHH", x8);
    string x9[14] = { "RIGHT", "LEFT", "FIRST", "NO", "MIDDLE", "YES", "BLANK", "WHAT", "UHHH", "WAIT", "PRESS", "READY", "OKAY", "NOTHING" };
    this->LoadButton("LEFT", x9);
    string x10[14] = { "YES", "NOTHING", "READY", "PRESS", "NO", "WAIT", "WHAT", "RIGHT", "MIDDLE", "LEFT", "UHHH", "BLANK", "OKAY", "FIRST" };
    this->LoadButton("RIGHT", x10);
    string x11[14] = { "BLANK", "READY", "OKAY", "WHAT", "NOTHING", "PRESS", "NO", "WAIT", "LEFT", "MIDDLE", "RIGHT", "FIRST", "UHHH", "YES" };
    this->LoadButton("MIDDLE", x11);
    string x12[14] = { "MIDDLE", "NO", "FIRST", "YES", "UHHH", "NOTHING", "WAIT", "OKAY", "LEFT", "READY", "BLANK", "PRESS", "WHAT", "RIGHT" };
    this->LoadButton("OKAY", x12);
    string x13[14] = { "UHHH", "NO", "BLANK", "OKAY", "YES", "LEFT", "FIRST", "PRESS", "WHAT", "WAIT", "NOTHING", "READY", "RIGHT", "MIDDLE" };
    this->LoadButton("WAIT", x13);
    string x14[14] = { "RIGHT", "MIDDLE", "YES", "READY", "PRESS", "OKAY", "NOTHING", "UHHH", "BLANK", "LEFT", "FIRST", "WHAT", "NO", "WAIT" };
    this->LoadButton("PRESS", x14);
    string x15[14] = { "SURE", "YOU ARE", "YOUR", "YOU'RE", "NEXT", "UH HUH", "UR", "HOLD", "WHAT?", "YOU", "UH UH", "LIKE", "DONE", "U" };
    this->LoadButton("YOU", x15);
    string x16[14] = { "YOUR", "NEXT", "LIKE", "UH HUH", "WHAT?", "DONE", "UH UH", "HOLD", "YOU", "U", "YOU'RE", "SURE", "UR", "YOU ARE" };
    this->LoadButton("YOU ARE", x16);
    string x17[14] = { "UH UH", "YOU ARE", "UH HUH", "YOUR", "NEXT", "UR", "SURE", "U", "YOU'RE", "YOU", "WHAT?", "HOLD", "LIKE", "DONE" };
    this->LoadButton("YOUR", x17);
    string x18[14] = { "YOU", "YOU'RE", "UR", "NEXT", "UH UH", "YOU ARE", "U", "YOUR", "WHAT?", "UH HUH", "SURE", "DONE", "LIKE", "HOLD" };
    this->LoadButton("YOU'RE", x18);
    string x19[14] = { "DONE", "U", "UR", "UH HUH", "WHAT?", "SURE", "YOUR", "HOLD", "YOU'RE", "LIKE", "NEXT", "UH UH", "YOU ARE", "YOU" };
    this->LoadButton("UR", x19);
    string x20[14] = { "UH HUH", "SURE", "NEXT", "WHAT?", "YOU'RE", "UR", "UH UH", "DONE", "U", "YOU", "LIKE", "HOLD","YOU ARE", "YOUR" };
    this->LoadButton("U", x20);
    string x21[14] = { "UH HUH", "YOUR", "YOU ARE", "YOU", "DONE", "HOLD", "UH UH", "NEXT", "SURE", "LIKE", "YOU'RE", "UR", "U", "WHAT?" };
    this->LoadButton("UH HUH", x21);
    string x22[14] = { "UR", "U", "YOU ARE", "YOU'RE", "NEXT", "UH UH", "DONE", "YOU", "UH HUH", "LIKE", "YOUR", "SURE", "HOLD", "WHAT?" };
    this->LoadButton("UH UH", x22);
    string x23[14] = { "YOU", "HOLD", "YOU'RE", "YOUR", "U", "DONE", "UH UH", "LIKE", "YOU ARE", "UH HUH", "UR", "NEXT", "WHAT?", "SURE" };
    this->LoadButton("WHAT?", x23);
    string x24[14] = { "SURE", "UH HUH", "NEXT", "WHAT?", "YOUR", "UR", "YOU'RE", "HOLD", "LIKE", "YOU", "U", "YOU ARE", "UH UH", "DONE" };
    this->LoadButton("DONE", x24);
    string x25[14] = { "WHAT?", "UH HUH", "UH UH", "YOUR", "HOLD", "SURE", "NEXT", "LIKE", "DONE", "YOU ARE", "UR", "YOU'RE", "U", "YOU" };
    this->LoadButton("NEXT", x25);
    string x26[14] = { "YOU ARE", "U", "DONE", "UH UH", "YOU", "UR", "SURE", "WHAT?", "YOU'RE", "NEXT", "HOLD", "UH HUH", "YOUR", "LIKE" };
    this->LoadButton("HOLD", x26);
    string x27[14] = { "YOU ARE", "DONE", "LIKE", "YOU'RE", "YOU", "HOLD", "UH HUH", "UR", "SURE", "U", "WHAT?", "NEXT", "YOUR", "UH UH" };
    this->LoadButton("SURE", x27);
    string x28[14] = { "YOU'RE", "NEXT", "U", "UR", "HOLD", "DONE", "UH UH", "WHAT?", "UH HUH", "YOU", "LIKE", "SURE", "YOU ARE", "YOUR" };
    this->LoadButton("LIKE", x28);
}

// Start game
void WordCode::Start(){
    this->NewDisplay = this->display[this->randomTal(this->display.size() - 1)];
    this->NewButton = this->button[this->randomTal(this->button.size() - 1)];

    this->buttonTable[this->NewDisplay.row][this->NewDisplay.col] = this->NewButton.text;

    this->findButton();
    this->findXWord();
    this->DisplayText = this->NewDisplay.text;
}

// Tjekker om key er OK
bool WordCode::keyIs(string key){
    string xKey = str_toupper(key);

    return xKey == this->xWord;
}

// Finder key
void WordCode::findXWord(){
    bool wordIsFind = false;
    for(int i = 0; i < this->NewButton.buttonList.size(); i++){
        if(wordIsFind){
            break;
        }

        for(int row = 0; row < 3; row++){
            if(wordIsFind){
                break;
            }
            for(int col = 0; col < 2; col++){
                if(this->NewButton.buttonList[i] == this->buttonTable[row][col]){
                    this->xWord = this->NewButton.buttonList[i];
                    wordIsFind = true;
                    break;
                }
            }
        }
    }
}

// Finder de button text.
void WordCode::findButton(){
    string x[5];

    // Finder button text og sørge for at de ikke er ens.
    for(int i = 0; i < 5; i++){
        while(true){
            bool isOK = true;
            string getText = this->NewButton.buttonList[this->randomTal(this->NewButton.buttonList.size() - 1)];
            for(int i2 = 0; i2 < 4; i2++){ // fra x
                if(getText == x[i2] || getText == this->NewButton.text){
                    isOK = false;
                    break;
                }
            }
            if(isOK){
                x[i] = getText;
                break;
            }
        }
    }

    int xTal = 0;

    // Sætter dem ind i button table.
    for(int rowF = 0; rowF < 3; rowF++){ // ROW
        for(int colF = 0; colF < 2; colF++){ // COL
            if(rowF == this->NewDisplay.row && colF == this->NewDisplay.col){
                continue;
            }

            this->buttonTable[rowF][colF] = x[xTal];
            xTal++;			
        }
    }
}

// Alt data der load til button
void WordCode::LoadButton(string text, string buttonList[]) {
    ButtonData x;
    x.text = text;

    for (int i = 0; i < 14; i++) {
        x.buttonList.push_back(buttonList[i]);
    }

    this->button.push_back(x);
}

// Alt data der load til display
void WordCode::LoadDisplay(string dis, int row, int col){
    DisplayData x;
    x.text = dis;
    x.col = col;
    x.row = row;

    this->display.push_back(x);
}

// Random tal gen...
int WordCode::randomTal(int x){
    mt19937 rng;
    rng.seed(random_device()());

    uniform_int_distribution<mt19937::result_type> dist6(0,x);

    return dist6(rng);
}