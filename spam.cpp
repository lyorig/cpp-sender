#define NOMINMAX
#define B_GREEN 10
#define USERINPUT 11
#define B_RED 12
#define WHITE 15

#include <iostream>
#include <string>
#include <locale>
#include <limits>
#include <Windows.h>
#include "spam.h"

using namespace std;

int main() {
    
    // Promìnné a jejich základní hodnoty
    string ans;
    UINT codepage = 1250;
    string sLocale = "cs_CZ";
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    delay = 30;

    
    
    // Základní nastavení
    SetConsoleTitleA(chooseRandElem(titleText).c_str()); // Narrow string protože se mi nechce dìlat funkce na pøevod
    setlocale(LC_ALL, "cs_CZ");
    SetConsoleCP(1250);
    
    printColoredMsg(WHITE, "Chcete upravit nastavení? (ano/ne): ", USERINPUT);
    cin >> ans;

    
    // Goto je giga cringe ale jsem líný programátor
    
    if (ans == "ano") {

    Q1:
        printColoredMsg(WHITE, "\nProdleva mezi repeticemi (ms): ", USERINPUT);
        cin >> delay;
        
            if (!cin || delay < 0 || delay > 10000) {
            
                flushCin();
                printColoredMsg(B_RED, "Neplatná prodleva. Zadejte jinou.\n", WHITE);
                goto Q1;
            }



    Q2:
        printColoredMsg(WHITE, "\nCodepage: ", USERINPUT);
        cin >> codepage;

            if (!cin || codepage > 1500) {

                flushCin();
                printColoredMsg(B_RED, "Neplatný codepage. Zadejte jiný.\n", WHITE);
                goto Q2;
            }



    Q3:
        printColoredMsg(WHITE, "\nLocale: ", USERINPUT);
        cin >> sLocale;

            if (!cin || sLocale.length() < 4 || sLocale.length() > 10) { // Locale mùže být i 10 znakù dlouhý, tak pro jistotu

                flushCin();
                printColoredMsg(B_RED, "Neplatný locale. Zadejte jiný.\n", WHITE);
                goto Q3;
            }
            
            printColoredMsg(B_GREEN, "\nNastaveno.\n", WHITE); // Lež
    }



    else { // Cokoliv jiného než "ano" se bere jako ne

        setColor(B_GREEN);

        cout << "\nProdleva nastavena na základní (" << delay << "ms).\n";
        cout << "Locale nastaven na základní (" << sLocale << ").\n";
        cout << "Codepage nastaven na základní (" << codepage << ").\n"; // Také lži. Ne, neplánuji s tím nic dìlat
    }




    setlocale(LC_ALL, sLocale.c_str());
    SetConsoleCP(codepage);
    
    setColor(WHITE);
    cout << "\n(c) Petr Šácha 2022. " << chooseRandElem(splashText) << "\nPoužitím programu souhlasíte se samostatností Míkovic.\n\nCo chcete spamovat? -> ";
    setColor(USERINPUT);
    
    flushCin();
    getline(wcin, wts);

    printColoredMsg(B_GREEN, "\nHotovo. Držte F12 pro spam.\n", WHITE);
    
    
    
    
    while(true) {
        
        if (GetKeyState(VK_F12) & 0x8000) {
            sendText();
        }  
    }
    return 0;
}
