#define NOMINMAX
#define WHITE FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
#define YELLOW FOREGROUND_RED | FOREGROUND_GREEN
#define BGREEN FOREGROUND_GREEN | FOREGROUND_INTENSITY

#include <iostream>
#include <string>
#include <locale>
#include <limits>
#include <Windows.h>
#include "spam.h"

using namespace std;

int main() {
    
    string ans;
    UINT codepage;
    string sLocale;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    setlocale(LC_ALL, "cs_CZ");
    SetConsoleTextAttribute(hConsole, YELLOW);
    
    cout << "Chcete editovat nastavení? (ano/ne): ";
    cin >> ans;

    if (ans == "ano") {

        cout << "\nProdleva mezi repeticemi (ms): ";
        cin >> delay;
        cout << "Prodleva nastavena na základní (" << delay << ")ms.\n\n";

        cout << "Codepage: ";
        cin >> codepage;
        
        cout << "Locale: ";
        cin >> sLocale; 

    }
    else { // Cokoliv jiného než "ano" se bere jako ne
        
        delay = 30;
        cout << "\nProdleva nastavena na základní (" << delay << "ms).\n";

        codepage = 1250;
        locale = "cs_CZ";

    }
    setlocale(LC_ALL, sLocale);
    cout << "Locale nastaven na základní (" << sLocale << ").\n";
    SetConsoleCP(codepage);
    cout << "Codepage nastaven na základní (" << codepage << ").\n\n";

    cout << "(c) Petr Šácha 2022. Podporuje diakritiku.\n";
    cout << "Použitím programu souhlasíte se samostatností Míkovic.\n";
    cout << "Co chcete spamovat? -> ";
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // jinak nebude kvůli cin-u fungovat getline
    getline(wcin, wts);

    SetConsoleTextAttribute(hConsole, BGREEN);

    cout << "\nHotovo. Držte F12 pro spam.\n"; 
    
    while(true) {
        
        if (GetKeyState(VK_F12) & 0x8000) {
            sendText();
        }
        
    }
    SetConsoleTextAttribute(hConsole, WHITE);
    return 0;
}
