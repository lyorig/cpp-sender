#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <limits>
#include <Windows.h>
#include <fcntl.h>
#include <time.h>
#include <io.h>

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

// Pou�ijte p�ed getline, pokud ho n�kdy p�ech�zel wcin.

void FlushCinW() {
    
    wcin.clear();
    wcin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Usnadn� pr�ci jen trochu, ale i tak je u�ite�n�.

void SetColor(WORD msgColor) {
    
    SetConsoleTextAttribute(hConsole, msgColor); // Jen v cmd prost�ed�!
}


void PrintColoredMsg(bool isRainbow, int clrBase, wstring msg, WORD nextColor) {

    // isRainbow - M� to b�t duhov�?
    // clrBase - V p��pad� jednobarevn�ho ur�uje barvu, v p��pad� duhov�ho ur�uje z�kladnu
    // msg - Co bude zbarven� a cout-ovan�?
    // nextColor - Jak� barva bude nastavena po dokon�en�?
    
    if (isRainbow == true) {
        int clr = clrBase;

        for (int i = 0; i < msg.length(); i++) {

            SetConsoleTextAttribute(hConsole, clr);
            clr++;

            if (clr > clrBase + 6) {

                clr = clrBase;
            }

            cout << msg[i];
        }
    }
    else {
        
        SetConsoleTextAttribute(hConsole, clrBase);
        wcout << msg;
    }
    SetConsoleTextAttribute(hConsole, nextColor);
}

// Tato funkce je pln� automatizovan� - vektor m��e m�t jak�koliv
// typ a velikost, a ChooseRandElem to p�ijme d�ky templatu

template<typename T>
T ChooseRandElem(vector<T> &arr) {
       
    int randIndex = rand() % arr.size();

    return arr[randIndex];
}