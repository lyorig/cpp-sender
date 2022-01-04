#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <Windows.h>
#include <time.h>

using namespace std;

// Prom�nn�
wstring wts;
int delay;

// Arrays
vector<string> splashText = { "Le fishe au chocolat.", "Napajedla neexistuj�.", "Praise Gab�a.", "Python je cringe.", "Garance �pagetov�ho k�du.", "Schv�leno Kunci�em.", "Spamujte s t�m Hendrycha.", "Isn't it?", "Nen�vid�m tento jazyk.", "Po��d stabiln�j�� ne� Fallout 76.", "Amogus sus." };
vector<wstring> titleText = { L"Audacity", L"Photomath", L"paint.net", L"Imagine", L"Malov�n� 3D", L"PSDiagram", L"PyCharm", L"Counter-Strike: Global Offensive", L"Minecraft", L"Among Us", L"Microsoft Excel" }; // L kv�li wstring

void sendText() {
 
    INPUT enter;
    enter.ki.wVk = 0x0D;
    enter.type = INPUT_KEYBOARD;
    enter.ki.dwFlags = 0;

    for (int i = 0; i < wts.length(); i++) {

        HKL myKL = GetKeyboardLayout(0);
        SHORT scan = VkKeyScanExW(wts[i], myKL);

        INPUT shift;
        shift.ki.wVk = 0x10;
        shift.type = INPUT_KEYBOARD;
        shift.ki.dwFlags = 0;

        INPUT alt;
        alt.ki.wVk = 0x12;
        alt.type = INPUT_KEYBOARD;
        alt.ki.dwFlags = 0;

        INPUT input;
        input.ki.wVk = scan;
        input.type = INPUT_KEYBOARD;
        input.ki.dwFlags = 0;

        if (scan & 0x100) { SendInput(1, &shift, sizeof(INPUT)); }

        if (scan & 0x200) { SendInput(1, &alt, sizeof(INPUT)); }

        SendInput(1, &input, sizeof(INPUT));

        input.ki.dwFlags = KEYEVENTF_KEYUP;
        shift.ki.dwFlags = KEYEVENTF_KEYUP;
        alt.ki.dwFlags = KEYEVENTF_KEYUP;

        SendInput(1, &input, sizeof(INPUT));
        SendInput(1, &shift, sizeof(INPUT));
        SendInput(1, &alt, sizeof(INPUT));

    }

    SendInput(1, &enter, sizeof(INPUT));
    enter.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &enter, sizeof(INPUT));

    Sleep(delay);
}

void flushCin() {
    
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void setColor(WORD msgColor) {
    
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, msgColor);
}

void printColoredMsg(WORD msgColor, string msg, WORD nextColor) {
    
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, msgColor);
    cout << msg;
    SetConsoleTextAttribute(hConsole, nextColor);
}

template<typename T>

T chooseRandElem(vector<T> arr) {
  
    srand(time(NULL));
    int randIndex = rand() % arr.size();

    return arr[randIndex];
}