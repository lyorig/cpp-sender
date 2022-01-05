// Jednoduchý C++ spammer. Kvůli využití wmain() musí být všechny I/O operace wide (široké), tzn. string musí být wstring a cin musí být wcin.
// Před každým stringem musí také být prefix L (pro wide string).
// _setmode zajišťuje Unicode podporu, tudíž není nutné nastavovat locale a codepage.




// Windows definice
#define NOMINMAX

// Konstantní výrazy
constexpr int B_BASE = 9;
constexpr int SUCCESS = 10;
constexpr int FAILURE = 12;
constexpr int USERINPUT = 11;
constexpr int WHITE = 15;

#include "lyoUtil.h"

using namespace std;

int wmain() {
    
    // Seed pro rand()
    srand((unsigned int)time(NULL));

    // Proměnné a jejich základní hodnoty
    wstring ans;
    delay = 30;

    // Vektory
    vector<wstring> splashText = { L"Le fishe au chocolat.", L"Napajedla neexistují.", L"Praise Gabča.", L"30x rychlejší než Python.", L"Garance špagetového kódu.", L"Schváleno Kuncišem.", L"Směřujte spam na lyorig#0775.", L"Isn't it?", L"Nenávidím tento jazyk.", L"Pořád stabilnější než Fallout 76.", L"Kvůli tomuto mám dvojku z biologie.", L"Spam! není spam."};
    vector<wstring> titleText = { L"Audavillage", L"Videomath", L"paint.com", L"Imagine 2", L"Malování 4D", L"XboxDiagram", L"C++Charm", L"Kyberdigi", L"Craftmine", L"Windows Defender" };
    
    // Základní nastavení
    SetConsoleTitleW(ChooseRandElem(titleText).c_str());
    SetColor(WHITE);

    (void)_setmode(_fileno(stdout), _O_U16TEXT); // Oba jsou castované na void protože jinak Visual Studio hází
    (void)_setmode(_fileno(stdin), _O_U16TEXT);  // varování o ignorování vratné hodnoty (kterou stejně nevyužiju)



    
    wcout << L"(c) Petr Šácha 2022. ";

    PrintColoredMsg(false, USERINPUT, ChooseRandElem(splashText), WHITE);

    wcout << L"\nPoužitím či modifikací programu souhlasíte se samostatností Míkovic.\n\n";

    PrintColoredMsg(false, WHITE, L"Chcete upravit nastavení? (ano/ne): ", USERINPUT);

    wcin >> ans;


    
    
    // Goto je giga cringe ale jsem líný programátor

    if (ans == L"ano") {

    Q1:
        PrintColoredMsg(false, WHITE, L"\nProdleva mezi repeticemi (ms): ", USERINPUT);
        wcin >> delay;

        if (!wcin || delay < 0 || delay > 10000) {

            PrintColoredMsg(false, FAILURE, L"Neplatná prodleva. Zadejte jinou.\n", WHITE);
            FlushCinW();
            goto Q1;
        }


    
    Q2:
        PrintColoredMsg(false, WHITE, L"\nProdleva mezi stiskem a odesláním klávesy (ms): ", USERINPUT);
        wcin >> inbDelay;

        if (!wcin || inbDelay < 0 || inbDelay > 1000) {

            PrintColoredMsg(false, FAILURE, L"Neplatná prodleva. Zadejte jinou.\n", WHITE);
            FlushCinW();
            goto Q2;
        }


        
        PrintColoredMsg(false, SUCCESS, L"\nNastaveno.\n", WHITE);
    }



    else { // Cokoliv jiného než "ano" se bere jako ne

        SetColor(SUCCESS);

        wcout << L"\nProdleva nastavena na doporučenou (" << delay << "ms).\n";
        wcout << L"Prodleva mezi stiskem a odesláním klávesy nastavena na doporučenou (" << inbDelay << "ms).\n";
    }



    PrintColoredMsg(false, WHITE, L"\nCo chcete spamovat? -> ", USERINPUT);
    
    FlushCinW();
    getline(wcin, wts);

    PrintColoredMsg(false, SUCCESS, L"\nPřipraveno. Držte F12 pro spam.", WHITE);
    


    // DEBUG ZÓNA

    
    
    // KONEC DEBUG ZÓNY



    while(true) {
        
        if (GetKeyState(VK_F12) & 0x8000) {
            sendText();
        }  
    }
    return 0;
}
