#pragma once

#define NOMINMAX // Windows.h má svoji vlastní definici MAX, tu musíme zrušit, jinak by nefungoval flushCin.

#include <iostream>   // wcin, wstring
#include <vector>     // vektory
#include <string>     // getline
#include <locale>     // setlocale
#include <limits>     // numeric_limits
#include <random>     // random_device, mt19937
#include <Windows.h>  // wmain, SendInput, SetConsoleTextAttribute

using namespace std;

// Promìnné a jejich základní hodnoty
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
wstring wts;
unsigned short delay = 30;
unsigned short inbDelay = 0;




void sendText() {
 
    INPUT enter;
    enter.ki.wVk = 0x0D;
    enter.type = INPUT_KEYBOARD;
    enter.ki.dwFlags = 0;

    for (short i = 0; i < wts.length(); i++) {

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




// Nutné pøed každým getline.

void flushCin() {
    
    wcin.clear();
    wcin.ignore(numeric_limits<streamsize>::max(), '\n');
}





// Ohavná funkce, zatím ale nemám na výbìr, pokud chci opravit tu resetující se barvu textu...
// Nìkdy(!) z toho udìlám Win32 aplikaci, to by mi snad mohlo nìjak usnadnit život.

void printColoredMsg(WORD clrBase, wstring msg, WORD nextColor = 0) { // nextColor neni povinný parametr.

    for (short i = 0; i < msg.length(); i++) {

        SetConsoleTextAttribute(hConsole, clrBase);

        wcout << msg[i];

        #ifndef LYONOSLEEP
            Sleep(1);
        #endif
    }
    
    if (nextColor != 0) { SetConsoleTextAttribute(hConsole, nextColor); } // užiteèné pro nastavení samostatné barvy pro (w)cin/getline.
}




// "If it ain't broke, don't fix it." Slyšeli jste nìkdy toto rèení? Já ne,
// teï je to zase broke a nemám ponìtí jak to opravit.

template<typename T>
wstring rIndex(T &vec) {
    
    random_device rDevice;
    mt19937 rGen(rDevice());
    uniform_int_distribution<> rDist(0, vec.size() - 1);

    return vec[rDist(rGen)].c_str();
}