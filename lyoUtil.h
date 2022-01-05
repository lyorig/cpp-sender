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

// Promìnné
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

// Použijte pøed getline, pokud ho nìkdy pøecházel wcin.

void FlushCinW() {
    
    wcin.clear();
    wcin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Usnadní práci jen trochu, ale i tak je užiteèná.

void SetColor(WORD msgColor) {
    
    SetConsoleTextAttribute(hConsole, msgColor); // Jen v cmd prostøedí!
}


void PrintColoredMsg(bool isRainbow, int clrBase, wstring msg, WORD nextColor) {

    // isRainbow - Má to být duhové?
    // clrBase - V pøípadì jednobarevného urèuje barvu, v pøípadì duhového urèuje základnu
    // msg - Co bude zbarvené a cout-ované?
    // nextColor - Jaká barva bude nastavena po dokonèení?
    
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

// Tato funkce je plnì automatizovaná - vektor mùže mít jakýkoliv
// typ a velikost, a ChooseRandElem to pøijme díky templatu

template<typename T>
T ChooseRandElem(vector<T> &arr) {
       
    int randIndex = rand() % arr.size();

    return arr[randIndex];
}