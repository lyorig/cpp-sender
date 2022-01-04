#define NOMINMAX
#define SUCCESS 10
#define USERINPUT 11
#define FAILURE 12
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
    SetConsoleTitleW(chooseRandElem(titleText).c_str());
    setlocale(LC_ALL, "cs_CZ");
    SetConsoleCP(1250);
    
    setColor(WHITE);
    cout << "(c) Petr Šácha 2022. " << chooseRandElem(splashText) << "\nPoužitím programu souhlasíte se samostatností Míkovic.\n\n";
    
    printColoredMsg(WHITE, "Chcete upravit nastavení? (ano/ne): ", USERINPUT);
    cin >> ans;


    
    
    // Goto je giga cringe ale jsem líný programátor

    if (ans == "ano") {

    Q1:
        printColoredMsg(WHITE, "\nProdleva mezi repeticemi (ms): ", USERINPUT);
        cin >> delay;

        if (!cin || delay < 0 || delay > 10000) {

            flushCin();
            printColoredMsg(FAILURE, "Neplatná prodleva. Zadejte jinou.\n", WHITE);
            goto Q1;
        }



    Q2:
        printColoredMsg(WHITE, "\nCodepage: ", USERINPUT);
        cin >> codepage;

        if (!cin || codepage > 1500) {

            flushCin();
            printColoredMsg(FAILURE, "Neplatný codepage. Zadejte jiný.\n", WHITE);
            goto Q2;
        }



    Q3:
        printColoredMsg(WHITE, "\nLocale: ", USERINPUT);
        cin >> sLocale;

        if (!cin || sLocale.length() < 4 || sLocale.length() > 10) { // Locale mùže být i 10 znakù dlouhý, tak pro jistotu

            flushCin();
            printColoredMsg(FAILURE, "Neplatný locale. Zadejte jiný.\n", WHITE);
            goto Q3;
        }

        printColoredMsg(SUCCESS, "\nNastaveno.\n", WHITE); // Lež
    }



    else { // Cokoliv jiného než "ano" se bere jako ne

        setColor(SUCCESS);

        cout << "\nProdleva nastavena na doporuèenou (" << delay << "ms).\n";
        cout << "Locale nastaven na doporuèený (" << sLocale << ").\n";
        cout << "Codepage nastaven na doporuèený (" << codepage << ").\n"; // Také lži. Ne, neplánuji s tím nic dìlat
    }

    setlocale(LC_ALL, sLocale.c_str());
    SetConsoleCP(codepage);

    printColoredMsg(WHITE, "\nCo chcete spamovat? -> ", USERINPUT);
    
    flushCin();
    getline(wcin, wts);

    printColoredMsg(SUCCESS, "\nPøipraveno. Držte F12 pro spam.", WHITE);
    
    
    
    
    while(true) {
        
        if (GetKeyState(VK_F12) & 0x8000) {
            sendText();
        }  
    }
    return 0;
}
