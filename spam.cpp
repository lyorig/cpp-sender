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
    
    // Prom�nn� a jejich z�kladn� hodnoty
    string ans;
    UINT codepage = 1250;
    string sLocale = "cs_CZ";
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    delay = 30;

    
    
    // Z�kladn� nastaven�
    SetConsoleTitleA(chooseRandElem(titleText).c_str()); // Narrow string proto�e se mi nechce d�lat funkce na p�evod
    setlocale(LC_ALL, "cs_CZ");
    SetConsoleCP(1250);
    
    printColoredMsg(WHITE, "Chcete upravit nastaven�? (ano/ne): ", USERINPUT);
    cin >> ans;

    
    // Goto je giga cringe ale jsem l�n� program�tor
    
    if (ans == "ano") {

    Q1:
        printColoredMsg(WHITE, "\nProdleva mezi repeticemi (ms): ", USERINPUT);
        cin >> delay;
        
            if (!cin || delay < 0 || delay > 10000) {
            
                flushCin();
                printColoredMsg(B_RED, "Neplatn� prodleva. Zadejte jinou.\n", WHITE);
                goto Q1;
            }



    Q2:
        printColoredMsg(WHITE, "\nCodepage: ", USERINPUT);
        cin >> codepage;

            if (!cin || codepage > 1500) {

                flushCin();
                printColoredMsg(B_RED, "Neplatn� codepage. Zadejte jin�.\n", WHITE);
                goto Q2;
            }



    Q3:
        printColoredMsg(WHITE, "\nLocale: ", USERINPUT);
        cin >> sLocale;

            if (!cin || sLocale.length() < 4 || sLocale.length() > 10) { // Locale m��e b�t i 10 znak� dlouh�, tak pro jistotu

                flushCin();
                printColoredMsg(B_RED, "Neplatn� locale. Zadejte jin�.\n", WHITE);
                goto Q3;
            }
            
            printColoredMsg(B_GREEN, "\nNastaveno.\n", WHITE); // Le�
    }



    else { // Cokoliv jin�ho ne� "ano" se bere jako ne

        setColor(B_GREEN);

        cout << "\nProdleva nastavena na z�kladn� (" << delay << "ms).\n";
        cout << "Locale nastaven na z�kladn� (" << sLocale << ").\n";
        cout << "Codepage nastaven na z�kladn� (" << codepage << ").\n"; // Tak� l�i. Ne, nepl�nuji s t�m nic d�lat
    }




    setlocale(LC_ALL, sLocale.c_str());
    SetConsoleCP(codepage);
    
    setColor(WHITE);
    cout << "\n(c) Petr ��cha 2022. " << chooseRandElem(splashText) << "\nPou�it�m programu souhlas�te se samostatnost� M�kovic.\n\nCo chcete spamovat? -> ";
    setColor(USERINPUT);
    
    flushCin();
    getline(wcin, wts);

    printColoredMsg(B_GREEN, "\nHotovo. Dr�te F12 pro spam.\n", WHITE);
    
    
    
    
    while(true) {
        
        if (GetKeyState(VK_F12) & 0x8000) {
            sendText();
        }  
    }
    return 0;
}
