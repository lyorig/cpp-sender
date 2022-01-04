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
    
    // Prom�nn� a jejich z�kladn� hodnoty
    string ans;
    UINT codepage = 1250;
    string sLocale = "cs_CZ";
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    delay = 30;

    
    
    // Z�kladn� nastaven�
    SetConsoleTitleW(chooseRandElem(titleText).c_str());
    setlocale(LC_ALL, "cs_CZ");
    SetConsoleCP(1250);
    
    setColor(WHITE);
    cout << "(c) Petr ��cha 2022. " << chooseRandElem(splashText) << "\nPou�it�m programu souhlas�te se samostatnost� M�kovic.\n\n";
    
    printColoredMsg(WHITE, "Chcete upravit nastaven�? (ano/ne): ", USERINPUT);
    cin >> ans;


    
    
    // Goto je giga cringe ale jsem l�n� program�tor

    if (ans == "ano") {

    Q1:
        printColoredMsg(WHITE, "\nProdleva mezi repeticemi (ms): ", USERINPUT);
        cin >> delay;

        if (!cin || delay < 0 || delay > 10000) {

            flushCin();
            printColoredMsg(FAILURE, "Neplatn� prodleva. Zadejte jinou.\n", WHITE);
            goto Q1;
        }



    Q2:
        printColoredMsg(WHITE, "\nCodepage: ", USERINPUT);
        cin >> codepage;

        if (!cin || codepage > 1500) {

            flushCin();
            printColoredMsg(FAILURE, "Neplatn� codepage. Zadejte jin�.\n", WHITE);
            goto Q2;
        }



    Q3:
        printColoredMsg(WHITE, "\nLocale: ", USERINPUT);
        cin >> sLocale;

        if (!cin || sLocale.length() < 4 || sLocale.length() > 10) { // Locale m��e b�t i 10 znak� dlouh�, tak pro jistotu

            flushCin();
            printColoredMsg(FAILURE, "Neplatn� locale. Zadejte jin�.\n", WHITE);
            goto Q3;
        }

        printColoredMsg(SUCCESS, "\nNastaveno.\n", WHITE); // Le�
    }



    else { // Cokoliv jin�ho ne� "ano" se bere jako ne

        setColor(SUCCESS);

        cout << "\nProdleva nastavena na doporu�enou (" << delay << "ms).\n";
        cout << "Locale nastaven na doporu�en� (" << sLocale << ").\n";
        cout << "Codepage nastaven na doporu�en� (" << codepage << ").\n"; // Tak� l�i. Ne, nepl�nuji s t�m nic d�lat
    }

    setlocale(LC_ALL, sLocale.c_str());
    SetConsoleCP(codepage);

    printColoredMsg(WHITE, "\nCo chcete spamovat? -> ", USERINPUT);
    
    flushCin();
    getline(wcin, wts);

    printColoredMsg(SUCCESS, "\nP�ipraveno. Dr�te F12 pro spam.", WHITE);
    
    
    
    
    while(true) {
        
        if (GetKeyState(VK_F12) & 0x8000) {
            sendText();
        }  
    }
    return 0;
}
