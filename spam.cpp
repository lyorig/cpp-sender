#define NOMINMAX
#define SUCCESS 10
#define FAILURE 12
#define USERINPUT 11
#define WHITE 15

#include "lyoUtil.h"

using namespace std;

int main() {
    
    // Seed pro rand()
    srand((unsigned int)time(NULL));

    // Prom�nn� a jejich z�kladn� hodnoty
    string ans;
    UINT codepage = 1250;
    string sLocale = "cs_CZ";
    delay = 30;

    // Vektory
    vector<string> splashText = { "Le fishe au chocolat.", "Napajedla neexistuj�.", "Praise Gab�a.", "30x rychlej�� ne� Python.", "Garance �pagetov�ho k�du.", "Schv�leno Kunci�em.", "Sm��ujte spam na lyorig#0775.", "Isn't it?", "Nen�vid�m tento jazyk.", "Po��d stabiln�j�� ne� Fallout 76.", "Kv�li tomuto m�m dvojku z biologie.", "Spam! nen� spam."};
    vector<string> titleText = { "Audavillage", "Videomath", "paint.com", "Imagine 2", "Paint 4D", "XboxDiagram", "C++Charm", "Kyberdigi.cz", "Craftmine", "Toto !== virus" }; // UTF-8
    
    // Z�kladn� nastaven�
    SetConsoleTitleA(chooseRandElem(titleText).c_str());
    setlocale(LC_ALL, "cs_CZ");
    SetConsoleCP(1250);
    
    setColor(WHITE);

    cout << "(c) Petr ��cha 2022. ";
    printColoredMsg(false, USERINPUT, chooseRandElem(splashText), WHITE);
    cout << "\nPou�it�m �i modifikac� programu souhlas�te se samostatnost� M�kovic.\n\n";
    printColoredMsg(false, WHITE, "Chcete upravit nastaven�? (ano/ne): ", USERINPUT);
    cin >> ans;


    
    
    // Goto je giga cringe ale jsem l�n� program�tor
    if (ans == "ano") {

    Q1A:
        printColoredMsg(false, WHITE, "\nProdleva mezi repeticemi (ms): ", USERINPUT);
        cin >> delay;

        if (!cin || delay < 0 || delay > 10000) {

            printColoredMsg(false, FAILURE, "Neplatn� prodleva. Zadejte jinou.\n", WHITE);
            flushCin();
            goto Q1A;
        }


    
    Q1B:
        printColoredMsg(false, WHITE, "\nProdleva mezi stiskem a odesl�n�m kl�vesy (ms): ", USERINPUT);
        cin >> inbDelay;

        if (!cin || inbDelay < 0 || inbDelay > 1000) {

            printColoredMsg(false, FAILURE, "Neplatn� prodleva. Zadejte jinou.\n", WHITE);
            flushCin();
            goto Q1B;
        }



    Q2:
        printColoredMsg(false, WHITE, "\nCodepage: ", USERINPUT);
        cin >> codepage;

        if (!cin || codepage > 1500) {

            printColoredMsg(false, FAILURE, "Neplatn� codepage. Zadejte jin�.\n", WHITE);
            flushCin();
            goto Q2;
        }



    Q3:
        printColoredMsg(false, WHITE, "\nLocale: ", USERINPUT);
        cin >> sLocale;

        if (!cin || sLocale.length() < 4 || sLocale.length() > 10) { // Locale m��e b�t i 10 znak� dlouh�, tak pro jistotu

            printColoredMsg(false, FAILURE, "Neplatn� locale. Zadejte jin�.\n", WHITE);
            flushCin();
            goto Q3;
        }

        printColoredMsg(false, SUCCESS, "\nNastaveno.\n", WHITE); // Le�! P�ece to bude nastaveno a� o n�kolik ��dk� pozd�ji
    }



    else { // Cokoliv jin�ho ne� "ano" se bere jako ne

        setColor(SUCCESS);

        cout << "\nProdleva nastavena na doporu�enou (" << delay << "ms).\n";
        cout << "Prodleva mezi stiskem a odesl�n�m kl�vesy nastavena na doporu�enou (" << inbDelay << "ms).\n";
        cout << "Locale nastaven na doporu�en� (" << sLocale << ").\n";
        cout << "Codepage nastaven na doporu�en� (" << codepage << ").\n"; // Dal�� l�i! Tyto jsou alespo� o hodn� ��dk� bl�
    }

    setlocale(LC_ALL, sLocale.c_str());
    SetConsoleCP(codepage);

    printColoredMsg(false, WHITE, "\nCo chcete spamovat? -> ", USERINPUT);
    
    flushCin();
    getline(wcin, wts);

    printColoredMsg(false, SUCCESS, "\nP�ipraveno. Dr�te F12 pro spam.", WHITE);
    
    
    
    
    while(true) {
        
        if (GetKeyState(VK_F12) & 0x8000) {
            sendText();
        }  
    }
    return 0;
}
