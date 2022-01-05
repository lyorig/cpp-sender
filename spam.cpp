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

    // Promìnné a jejich základní hodnoty
    string ans;
    UINT codepage = 1250;
    string sLocale = "cs_CZ";
    delay = 30;

    // Vektory
    vector<string> splashText = { "Le fishe au chocolat.", "Napajedla neexistují.", "Praise Gabèa.", "30x rychlejší než Python.", "Garance špagetového kódu.", "Schváleno Kuncišem.", "Smìøujte spam na lyorig#0775.", "Isn't it?", "Nenávidím tento jazyk.", "Poøád stabilnìjší než Fallout 76.", "Kvùli tomuto mám dvojku z biologie.", "Spam! není spam."};
    vector<string> titleText = { "Audavillage", "Videomath", "paint.com", "Imagine 2", "Paint 4D", "XboxDiagram", "C++Charm", "Kyberdigi.cz", "Craftmine", "Toto !== virus" }; // UTF-8
    
    // Základní nastavení
    SetConsoleTitleA(chooseRandElem(titleText).c_str());
    setlocale(LC_ALL, "cs_CZ");
    SetConsoleCP(1250);
    
    setColor(WHITE);

    cout << "(c) Petr Šácha 2022. ";
    printColoredMsg(false, USERINPUT, chooseRandElem(splashText), WHITE);
    cout << "\nPoužitím èi modifikací programu souhlasíte se samostatností Míkovic.\n\n";
    printColoredMsg(false, WHITE, "Chcete upravit nastavení? (ano/ne): ", USERINPUT);
    cin >> ans;


    
    
    // Goto je giga cringe ale jsem líný programátor
    if (ans == "ano") {

    Q1A:
        printColoredMsg(false, WHITE, "\nProdleva mezi repeticemi (ms): ", USERINPUT);
        cin >> delay;

        if (!cin || delay < 0 || delay > 10000) {

            printColoredMsg(false, FAILURE, "Neplatná prodleva. Zadejte jinou.\n", WHITE);
            flushCin();
            goto Q1A;
        }


    
    Q1B:
        printColoredMsg(false, WHITE, "\nProdleva mezi stiskem a odesláním klávesy (ms): ", USERINPUT);
        cin >> inbDelay;

        if (!cin || inbDelay < 0 || inbDelay > 1000) {

            printColoredMsg(false, FAILURE, "Neplatná prodleva. Zadejte jinou.\n", WHITE);
            flushCin();
            goto Q1B;
        }



    Q2:
        printColoredMsg(false, WHITE, "\nCodepage: ", USERINPUT);
        cin >> codepage;

        if (!cin || codepage > 1500) {

            printColoredMsg(false, FAILURE, "Neplatný codepage. Zadejte jiný.\n", WHITE);
            flushCin();
            goto Q2;
        }



    Q3:
        printColoredMsg(false, WHITE, "\nLocale: ", USERINPUT);
        cin >> sLocale;

        if (!cin || sLocale.length() < 4 || sLocale.length() > 10) { // Locale mùže být i 10 znakù dlouhý, tak pro jistotu

            printColoredMsg(false, FAILURE, "Neplatný locale. Zadejte jiný.\n", WHITE);
            flushCin();
            goto Q3;
        }

        printColoredMsg(false, SUCCESS, "\nNastaveno.\n", WHITE); // Lež! Pøece to bude nastaveno až o nìkolik øádkù pozdìji
    }



    else { // Cokoliv jiného než "ano" se bere jako ne

        setColor(SUCCESS);

        cout << "\nProdleva nastavena na doporuèenou (" << delay << "ms).\n";
        cout << "Prodleva mezi stiskem a odesláním klávesy nastavena na doporuèenou (" << inbDelay << "ms).\n";
        cout << "Locale nastaven na doporuèený (" << sLocale << ").\n";
        cout << "Codepage nastaven na doporuèený (" << codepage << ").\n"; // Další lži! Tyto jsou alespoò o hodnì øádkù blíž
    }

    setlocale(LC_ALL, sLocale.c_str());
    SetConsoleCP(codepage);

    printColoredMsg(false, WHITE, "\nCo chcete spamovat? -> ", USERINPUT);
    
    flushCin();
    getline(wcin, wts);

    printColoredMsg(false, SUCCESS, "\nPøipraveno. Držte F12 pro spam.", WHITE);
    
    
    
    
    while(true) {
        
        if (GetKeyState(VK_F12) & 0x8000) {
            sendText();
        }  
    }
    return 0;
}
