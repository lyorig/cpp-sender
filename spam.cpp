// Celkem jednoduch� aplikace na spamov�n� V�mi vybran�ho textu. Podporuje Unicode. Teda, m�la by.
// V�echny I/O operace mus� m�t p�edponu w (wide - �irok�, nutn� pro Unicode) a v�echny stringy mus� m�t p�edponu L (long - tak� nutn� pro Unicode).
// Z n�jak�ho d�vodu wide funkce zp�sobuj� to, �e se text v n�hodn�m bod� zm�n� zp�t na z�kladn� barvu (7). Proto se text na��t� postupn�.
// Pokud se mi nebudou cht�t p�ekl�dat n�jak� v�razy z angli�tiny, prost� je tak nech�m.

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
    const vector<wstring> splashText = { L"Le fishe au chocolat.", L"Napajedla neexistuj�.", L"Praise Gab�a.", L"30x rychlej�� ne� Python!", L"Garance �pagetov�ho k�du.", L"Schv�leno Jakubem Kuncem.", L"Sm��ujte spam na lyorig#0775.", L"Isn't it?", L"Nen�vid�m tento jazyk.", L"Po��d stabiln�j�� ne� Fallout 76.", L"Kv�li tomuto m�m dvojku z biologie.", L"Spam! nen� spam.", L"Drei aktivit�ten.", L"M�m v�s v�echny ulo�en�.", L"\"Beate, telefon!\"", L"Brzy na OnlyFans(tm).", L"H�r zu und erg�nze den Dialog."};
    const vector<wstring> titleText = { L"Audavillage", L"Videomath", L"paint.com", L"Imagine 2", L"Malov�n� 4D", L"XboxDiagram", L"C++Charm", L"Kyberdigi", L"Bing Chilling", L"Toto != virus", L"hek.ekse", L"j� kdy�", L"hendrych je gay", L"Capybara therapy (CBT)", L"Postrach Defenderu", L"cmd > Win32", L"V�clav Moravec", L"h"};
    
    

    
    // Basic settings
    SetConsoleTitle(rIndex(titleText).c_str()); // Pokud to chce LPCWSTR, pou�ijte c_str().

    setlocale(LC_ALL, "");

    

    
    printColoredMsg(WHITE, L"(c) Petr ��cha 2022. ");

    printColoredMsg(USERINPUT, rIndex(splashText));

    printColoredMsg(WHITE, L"\nPou�it�m �i modifikac� programu souhlas�te se samostatnost� M�kovic.\n\n");

    printColoredMsg(WHITE, L"Chcete ponechat doporu�en� nastaven�? (ano/ne): ", USERINPUT);

    InitialQ:
    wcin >> ans;

    
    

    // Goto je sice giga cringe, ale jsem l�n� program�tor.
    if (ans == L"ne") {
    
        printColoredMsg(WHITE, L"\nProdleva mezi repeticemi (ms): ", USERINPUT);
    
        Delay1:
        wcin >> delay;

        if (!wcin || delay < 0 || delay > 10000) {

            printColoredMsg(FAILURE, L"Neplatn� prodleva. Zadejte jinou: ", USERINPUT);
            flushCin();

            goto Delay1;
        }

        printColoredMsg(WHITE, L"\nProdleva mezi stiskem a odesl�n�m kl�vesy (ms): ", USERINPUT);
    
        Delay2:
        wcin >> inbDelay;

        if (!wcin || inbDelay < 0 || inbDelay > 1000) {

            printColoredMsg(FAILURE, L"Neplatn� prodleva. Zadejte jinou: ", USERINPUT);
            flushCin();

            goto Delay2;
        }
    }




    else if (ans == L"ano") {

        printColoredMsg(SUCCESS, L"Z�kladn� nastaven� ponech�ny.\n");
    }

    else {
        
        printColoredMsg(FAILURE, L"Neplatn� odpov��. Zadejte ano/ne: ", USERINPUT);

        goto InitialQ;
    }

    
    
    
    printColoredMsg(WHITE, L"\nCo chcete spamovat? -> ", USERINPUT);
    
    flushCin();
    getline(wcin, wts);

    printColoredMsg(SUCCESS, L"P�ipraveno. Dr�te F12 pro spam.");
    


    
    while(true) {
        
        if (GetKeyState(VK_F12) & 0x8000) {
            
            sendText();
        }
    }
    
    fflush(stdout);
    
    return 0;
}
