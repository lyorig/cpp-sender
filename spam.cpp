// Celkem jednoduchá aplikace na spamování Vámi vybraného textu. Podporuje Unicode. Teda, mìla by.
// Všechny I/O operace musí mít pøedponu w (wide - široké, nutné pro Unicode) a všechny stringy musí mít pøedponu L (long - také nutné pro Unicode).
// Z nìjakého dùvodu wide funkce zpùsobují to, že se text v náhodném bodì zmìní zpìt na základní barvu (7). Proto se text naèítá postupnì.
// Pokud se mi nebudou chtít pøekládat nìjaké výrazy z angliètiny, prostì je tak nechám.

// #define LYONOSLEEP
#define SUCCESS 10
#define FAILURE 12
#define USERINPUT 11
#define WHITE 15

#include "lyoUtil.h"

using namespace std;




int wmain() {

    // Variables
    wstring ans;




    // Arrays
    const vector<wstring> splashText = { L"Le fishe au chocolat.", L"Napajedla neexistují.", L"Praise Gabèa.", L"30x rychlejší než Python!", L"Garance špagetového kódu.", L"Schváleno Jakubem Kuncem.", L"Smìøujte spam na lyorig#0775.", L"Isn't it?", L"Nenávidím tento jazyk.", L"Poøád stabilnìjší než Fallout 76.", L"Kvùli tomuto mám dvojku z biologie.", L"Spam! není spam.", L"Drei aktivitäten.", L"Mám vás všechny uložené.", L"\"Beate, telefon!\"", L"Brzy na OnlyFans(tm).", L"Hör zu und ergänze den Dialog."};
    const vector<wstring> titleText = { L"Audavillage", L"Videomath", L"paint.com", L"Imagine 2", L"Malování 4D", L"XboxDiagram", L"C++Charm", L"Kyberdigi", L"Bing Chilling", L"Toto != virus", L"hek.ekse", L"já když", L"hendrych je gay", L"Capybara therapy (CBT)", L"Postrach Defenderu", L"cmd > Win32", L"Václav Moravec", L"h"};
    
    

    
    // Basic settings
    SetConsoleTitle(rIndex(titleText).c_str()); // Pokud to chce LPCWSTR, použijte c_str().

    setlocale(LC_ALL, "");

    

    
    printColoredMsg(WHITE, L"(c) Petr Šácha 2022. ");

    printColoredMsg(USERINPUT, rIndex(splashText));

    printColoredMsg(WHITE, L"\nPoužitím èi modifikací programu souhlasíte se samostatností Míkovic.\n\n");

    printColoredMsg(WHITE, L"Chcete ponechat doporuèené nastavení? (ano/ne): ", USERINPUT);

    InitialQ:
    wcin >> ans;

    
    

    // Goto je sice giga cringe, ale jsem líný programátor.
    if (ans == L"ne") {
    
        printColoredMsg(WHITE, L"\nProdleva mezi repeticemi (ms): ", USERINPUT);
    
        Delay1:
        wcin >> delay;

        if (!wcin || delay < 0 || delay > 10000) {

            printColoredMsg(FAILURE, L"Neplatná prodleva. Zadejte jinou: ", USERINPUT);
            flushCin();

            goto Delay1;
        }

        printColoredMsg(WHITE, L"\nProdleva mezi stiskem a odesláním klávesy (ms): ", USERINPUT);
    
        Delay2:
        wcin >> inbDelay;

        if (!wcin || inbDelay < 0 || inbDelay > 1000) {

            printColoredMsg(FAILURE, L"Neplatná prodleva. Zadejte jinou: ", USERINPUT);
            flushCin();

            goto Delay2;
        }
    }




    else if (ans == L"ano") {

        printColoredMsg(SUCCESS, L"Základní nastavení ponechány.\n");
    }

    else {
        
        printColoredMsg(FAILURE, L"Neplatná odpovìï. Zadejte ano/ne: ", USERINPUT);

        goto InitialQ;
    }

    
    
    
    printColoredMsg(WHITE, L"\nCo chcete spamovat? -> ", USERINPUT);
    
    flushCin();
    getline(wcin, wts);

    printColoredMsg(SUCCESS, L"Pøipraveno. Držte F12 pro spam.");
    


    
    while(true) {
        
        if (GetKeyState(VK_F12) & 0x8000) {
            
            sendText();
        }
    }
    
    fflush(stdout);
    
    return 0;
}
