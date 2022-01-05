#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <limits>
#include <Windows.h>
#include <time.h>

using namespace std;

// Prom�nn�
wstring wts;
int delay = 30;
int inbDelay = 0;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



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

        Sleep(inbDelay);
        SendInput(1, &input, sizeof(INPUT));
        Sleep(inbDelay);
        SendInput(1, &shift, sizeof(INPUT));
        Sleep(inbDelay);
        SendInput(1, &alt, sizeof(INPUT));

    }

    SendInput(1, &enter, sizeof(INPUT));
    enter.ki.dwFlags = KEYEVENTF_KEYUP;
    Sleep(inbDelay);
    SendInput(1, &enter, sizeof(INPUT));

    Sleep(delay);
}

void flushCin() {
    
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void setColor(WORD msgColor) {
    
    SetConsoleTextAttribute(hConsole, msgColor); // Jen v cmd prost�ed�!
}


void printColoredMsg(bool isRainbow, int clrBase, string msg, WORD nextColor) {

    // isRainbow - M� to b�t duhov�?
    // clrBase - V p��pad� jednobarevn�ho ur�uje barvu, v p��pad� duhov�ho ur�uje z�kladnu
    // msg - Co bude zbarven� a cout-ovan�?
    // nextColor - Jak� barva bude nastavena po dokon�en�?
    
    if (isRainbow == true) {
        int clr = clrBase;

        for (int i = 0; i < msg.length(); i++) {

            SetConsoleTextAttribute(hConsole, clr);
            clr++;

            if (clr > clrBase + 5) {

                clr = clrBase;
            }

            cout << msg[i];
        }
    }
    else {
        
        SetConsoleTextAttribute(hConsole, clrBase);
        cout << msg;
    }
    SetConsoleTextAttribute(hConsole, nextColor);
}

template<typename T>
T chooseRandElem(vector<T> &arr) {
       
    int randIndex = rand() % arr.size();

    return arr[randIndex];
}