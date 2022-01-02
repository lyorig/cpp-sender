#define NOMINMAX

#include <iostream>
#include <string>
#include <locale>
#include <limits>
#include <Windows.h>
#include "Header.h"

using namespace std;

int main() {
    
    string ans;
    UINT codepage;

    setlocale(LC_ALL, "cs_CZ");
    system("Color 0E");
    
    cout << "Chcete editovat nastavení? (ano/ne): ";
    cin >> ans;

    if (ans == "ano") {

        cout << "\nProdleva mezi repeticemi (ms): ";
        cin >> delay;
        cout << "Prodleva nastavena na " << delay << "ms.\n\n";

        cout << "Codepage: ";
        cin >> codepage;

    }
    else { // Cokoliv jiného než "ano" se bere jako ne
        delay = 30;
        cout << "\nProdleva nastavena na 30ms.\n";
        codepage = 1250;
    }
    
    SetConsoleCP(codepage);
    cout << "Codepage nastaven na " << codepage << ".\n\n";

    cout << "(c) Petr Šácha 2022. Podporuje znaky.\n";
    cout << "Použitím programu souhlasíte se samostatností Míkovic.\n";
    cout << "Co chcete spamovat? -> ";
    
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // jinak nebude kvůli cin-u fungovat getline
    getline(wcin, wts);

    system("Color 0A"); // Zelená - program je ready

    cout << "\nHotovo. Držte F12 pro spam.\n"; 
    
    while(true) {
        
        if (GetKeyState(VK_F12) & 0x8000) {
            sendText();
        }
        
    }
    return 0;
}
