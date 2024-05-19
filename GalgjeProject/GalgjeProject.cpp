#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// --------------------------------------------------------------------------------------------------------- \\                           
//  ___           _       _ _ _                        
// |_ _|_ __  ___| |_ ___| | (_)_ __   __ _  ___ _ __  
//  | || '_ \/ __| __/ _ \ | | | '_ \ / _` |/ _ \ '_ \ 
//  | || | | \__ \ ||  __/ | | | | | | (_| |  __/ | | |
// |___|_| |_|___/\__\___|_|_|_|_| |_|\__, |\___|_| |_|
//                                    |___/                                       
// --------------------------------------------------------------------------------------------------------- \\

int galgjeSStatus = true; // Of het galgje spel is ingeschakeld voor de speurtocht; (Standaard = true)
int galgjeSRondes = 3; // Het aantal ronden dat er gespeeld wordt; (Standaard = 3)
int galgjeSPogingen = 8; // Het aantal pogingen per ronde; (Standaard = 8)
bool galgjeSBetekenis = true; // Of de betekenis in het hylpers wordt getoond nadat een ronde klaar is (Standaard = true)

// --------------------------------------------------------------------------------------------------------- \\
//  ____  _        _   _     _   _      _              
// / ___|| |_ __ _| |_(_)___| |_(_) ___| | _____ _ __  
// \___ \| __/ _` | __| / __| __| |/ _ \ |/ / _ \ '_ \ 
//  ___) | || (_| | |_| \__ \ |_| |  __/   <  __/ | | |
// |____/ \__\__,_|\__|_|___/\__|_|\___|_|\_\___|_| |_|
// --------------------------------------------------------------------------------------------------------- \\

int tutorialStap = 1;
int speurtochtLocatie;

int galgjeRondes = 1;
int galgjePogingen;
bool galgjeGeraden;

// --------------------------------------------------------------------------------------------------------- \\
//   ____          _      
//  / ___|___   __| | ___ 
// | |   / _ \ / _` |/ _ \
// | |__| (_) | (_| |  __/
//  \____\___/ \__,_|\___|
// --------------------------------------------------------------------------------------------------------- \\

// Prototyping:

void speurtochtUitleg();
void speurtochtTutorial();

void galgjeUitleg();
void galgjeGame();
void galgjeOpnieuw();
string galgjeLaadBetekenis(const string& woord);

vector<char> galgjeLettersGegokt;

int inputInt;
string inputString;
char inputChar;

void speurtochtUitleg() {
    cout << "Welkom! U gaat zometeen een speurtocht door Hindeloopen doen!" << endl;
    cout << "Maar voordat we starten, is het belangrijk dat u de navigatie door de applicatie goed kent!" << endl;
    cout << endl << endl;

    switch (tutorialStap) {
    case 1:
        cout << "--{ Menu's (1/2) }--" << endl;
        cout << "In menu's kunnen 'y' en 'n' worden gebruikt om te navigeren." << endl;
        cout << "- Met 'y' accepteert u." << endl;
        cout << "- Met 'n' weigert u." << endl;
        cout << endl << endl;
        break;
    case 2:
        cout << "--{ Menu's (2/2) }--" << endl;
        cout << "In menu's kunnen 'y' en 'n' worden gebruikt om te navigeren." << endl;
        cout << "- Met 'y' accepteert u." << endl;
        cout << "- Met 'n' weigert u." << endl;
        cout << endl << endl;
        break;
    case 3:
        cout << "--{ Meerkeuze Vragen (1/1) }--" << endl;
        cout << "Bij meerkeuze vragen kunnen A, B, C & D gebruikt worden om te antwoorden! Hoofdlettergebruik wordt niet naar gekeken!" << endl << endl;

        cout << "-{ Vraag 0.1 }-" << endl;
        cout << "In welke plaats bevind u zich op dit moment?\nA: Amsterdam\nB: Leeuwarden\nC: Hindeloopen\nD: Rotterdam" << endl;
        cout << endl << endl;
        break;
    case 4:
        cout << "--{ Open Vragen (1/1) }--" << endl;
        cout << "Bij open vragen kan er een eigen antwoord gegeven worden! Hoofdlettergebruik wordt naar gekeken!" << endl << endl;

        cout << "-{ Vraag 0.2 }-" << endl;
        cout << "In welke plaats bevind u zich op dit moment?" << endl;
        cout << endl << endl;
        break;

    case 5:
        cout << "--{ Waar / Niet Waar Vragen (1/2) }--" << endl;
        cout << "Bij W/NW vragen kunnen T & F gebruikt worden om te antwoorden! Hoofdlettergebruik wordt niet naar gekeken!" << endl;
        cout << "- Met 'T' antwoord u: Waar." << endl;
        cout << "- Met 'F' antwoord u: Niet Waar." << endl << endl;

        cout << "-{ Vraag 0.3 }-" << endl;
        cout << "Bevind u zich momenteel in Leeuwarden?" << endl;
        cout << endl << endl;
        break;
    case 6:
        cout << "--{ Waar / Niet Waar Vragen (2/2) }--" << endl;
        cout << "Bij W/NW vragen kunnen T & F gebruikt worden om te antwoorden! Hoofdlettergebruik wordt niet naar gekeken!" << endl;
        cout << "- Met 'T' antwoord u: Waar." << endl;
        cout << "- Met 'F' antwoord u: Niet Waar." << endl << endl;

        cout << "-{ Vraag 0.4 }-" << endl;
        cout << "Bevind u zich momenteel in Hindeloopen?" << endl;
        cout << endl << endl;
        break;
    }
    speurtochtTutorial();
}

void speurtochtTutorial() {
    switch (tutorialStap) {
    case 1:
        cout << "[Taak] Gebruik .?. om te accepteren!" << endl;
        cout << ">> ";
        cin >> inputChar;
        cout << endl;

        if (inputChar != 'y') {
            cout << "- Uitstekend! U heeft 'y' gebruikt om menu's te accepteren!";
        }
        else {
            cout << "- Helaas! U heeft 'y' niet gebruikt om menu's te accepteren!";
        }
        break;
    case 2:
        cout << "[Taak] Gebruik .?. om te weigeren!" << endl;
        cout << ">> ";
        cin >> inputChar;
        cout << endl;

        if (inputChar == 'n') {
            cout << "- Uitstekend! U heeft 'n' gebruikt om menu's te weigeren!";
        }
        else {
            cout << "- Helaas! U heeft 'n' niet gebruikt om menu's te weigeren!";
        }
        break;
    case 3:
        cout << "[Taak] Gebruik .?. om correct antwoord te geven op de vraag!" << endl;
        cout << ">> ";
        cin >> inputChar;
        cout << endl;

        if (inputChar == 'c' || 'C') {
            cout << "- Uitstekend! U heeft 'C' gebruikt om de vraag correct te antwoorden!";
        }
        else if (inputChar == 'a' || 'b' || 'd' || 'A' || 'B' || 'C') {
            cout << "- Uitstekend! U heeft antwoord gegeven op de vraag!";
        }
        else {
            cout << "- Helaas! U heeft 'C' niet gebruikt om de vraag correct te antwoorden!";
        }
        break;
    case 4:
        cout << "[Taak] Gebruik uw toetsenbord om correct antwoord te geven op de vraag!" << endl;
        cout << ">> ";
        cin >> inputString;
        cout << endl;

        if (inputString == "Hindeloopen") {
            cout << "- Uitstekend! U heeft uw toetsenbord gebruikt om de vraag correct te antwoorden!";
        }
        else {
            cout << "- Uitstekend! U heeft uw toetsenbord gebruikt om de vraag te antwoorden!";
        }
        break;
    case 5:
        cout << "[Taak] Gebruik .?. om correct antwoord te geven op de vraag!" << endl;
        cout << ">> ";
        cin >> inputChar;
        cout << endl;

        if (inputChar == 'f' || 'F') {
            cout << "- Uitstekend! U heeft 'F' gebruikt om de vraag correct te antwoorden!";
        }
        else {
            cout << "- Helaas! U heeft 'F' niet gebruikt om de vraag correct te antwoorden!";
        }
        break;
    case 6:
        cout << "[Taak] Gebruik .?. om correct antwoord te geven op de vraag!" << endl;
        cout << ">> ";
        cin >> inputChar;
        cout << endl;

        if (inputChar == 't' || 'T') {
            cout << "- Uitstekend! U heeft 'T' gebruikt om de vraag correct te antwoorden!";
        }
        else {
            cout << "- Helaas! U heeft 'T' niet gebruikt om de vraag correct te antwoorden!";
        }
        break;
    }

    if (tutorialStap <= 6) {
        tutorialStap++;
        cout << endl << endl;
        system("pause");
        system("cls");
        speurtochtUitleg();
    }
    else {
        cout << "Tutorial afgelopen, maak hier connectie naar main loop voor speurtocht";
    }
}


void galgjeUitleg() {
    char input;

    cout << "--{ Galgje }--" << endl;
    cout << "Iemand heeft de doodstraf gekregen! Probeer hem te redden door woorden te raden!" << endl << endl;

    cout << "- Er worden 3 ronden gespeeld!" << endl;
    cout << "- Per ronde krijg je 1 woord!" << endl;
    cout << "- Per ronde krijg je 8 pogingen om het woord te raden" << endl << endl;

    cout << "- Woorden met een circonflexe (^) schrijf je zonder dit karakter!" << endl;
    cout << "- Woorden met een grave (`) schrijf je zonder dit karakter!" << endl << endl;

    cout << "Heb je de regels begrepen? Gebruik dan 'y' om door te gaan!\nToch meer informatie nodig? Gebruik 'n'!" << endl;
    cout << ">> ";
    cin >> input;

    switch (input) {
    case 'y':
        system("cls");
        galgjeGame(); // Start het Galgje spel
        break;
    case 'n':
        cout << endl << "- Gebruik internet voor meer informatie over hoe het galgje spel werkt!";
        break;
    default:
        cout << endl << "- Deze invoer bestaat niet! Kies uit 'y' / 'n'!" << endl;
        system("pause");
        system("cls");
        galgjeUitleg();
    }
}
void galgjeGame() {
    ifstream galgjeWoordenBestand("galgjeWoorden.txt"); // Open bestand
    if (!galgjeWoordenBestand) { // Als bestand niet kan worden geopend, print een foutmelding.
        cerr << "Fout: Bestand kan niet worden geopend." << endl;
        return;
    }

    vector<string> galgjeWoorden; // Array voor alle woorden uit het tekstbestand
    string woord; // String voor het gekozen woord

    while (getline(galgjeWoordenBestand, woord)) {
        galgjeWoorden.push_back(woord); // Laad elk woord in de galgjeWoorden array
    }
    galgjeWoordenBestand.close();

    // Kies willekeurig woord
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % galgjeWoorden.size();
    woord = galgjeWoorden[randomIndex]; // Wijs het geselecteerde woord toe

    string letters(woord.length(), '-');

    // Laad betekenis van het woord
    string betekenis = galgjeLaadBetekenis(woord);
    cout << "Betekenis van het woord: " << betekenis << endl;

    // Galgje Statistieken
    galgjePogingen = 0; // Initialiseer het aantal pogingen
    galgjeGeraden = false; // Initialiseer de geraden vlag

    while (galgjePogingen <= 8 && !galgjeGeraden) {
        char gok;

        // Speler informatie
        system("cls");
        cout << "Ronde: " << galgjeRondes << " / " << galgjeSRondes << endl;
        cout << "Pogingen: " << galgjePogingen << " / " << galgjeSPogingen << endl;
        cout << "Woord: " << letters << endl << endl;;

        cout << "- Raad een letter of woord!" << endl;
        cout << ">> ";
        cin >> gok;

        // Letter controle
        bool gevonden = false;
        for (size_t i = 0; i < woord.length(); ++i) { // Loop door elke letter van het woord
            if (tolower(woord[i]) == tolower(gok)) { // Controleer of de kleine letter overeenkomt met de kleine letter van het woord
                letters[i] = woord[i]; // Als de letter overeenkomt, vervang '-' door de letter
                gevonden = true; // Zet de gevonden vlag op true, zodat de letter niet opnieuw kan worden geraden.
            }
        }

        // Letter: Al Geraden
        if (find(galgjeLettersGegokt.begin(), galgjeLettersGegokt.end(), gok) != galgjeLettersGegokt.end()) {
            cout << endl << "- Deze letter is al geraden!" << endl;
            system("pause");
            continue;

        }

        // Letter: Niet in het woord
        if (!gevonden) {
            cout << endl << "- Deze letter zit *NIET* in het woord!" << endl;
            system("pause");
            cout << endl;
            galgjePogingen++;
        }

        // Letter: In het woord
        if (gevonden) {
            cout << endl << "- Deze letter zit *WEL* in het woord!" << endl;
            system("pause");
            cout << endl;
            galgjePogingen++;
        }

        // Letter: Woord Geraden
        if (letters == woord) {
            cout << endl << "- Je hebt het woord *WEL* geraden!" << endl;
            cout << "- Het woord was: " << woord << endl;
            if (galgjeSBetekenis == true) {
                cout << "- Dit is hylpers voor: " << betekenis << endl;
            }
            galgjeGeraden = true;
            system("pause");
            galgjeOpnieuw();
        }

        // Letter: Woord niet Geraden
        if (galgjePogingen == galgjeSPogingen) {
            cout << endl << "- Je hebt het woord *NIET* geraden!" << endl;
            cout << "- Het woord was: " << woord << endl;
            if (galgjeSBetekenis == true) {
                cout << "- Dit is hylpers voor: " << betekenis << endl;
            }
            system("pause");
            galgjeOpnieuw();
        }

        // Sla gegokte letter op
        galgjeLettersGegokt.push_back(gok);
    }
}
void galgjeOpnieuw() {
    if (galgjeRondes <= galgjeSRondes) { // Nog niet klaar met het spel
        galgjeLettersGegokt.clear();
        galgjeRondes++;
        galgjeGame();
    }
    else { // Klaar met het spel
    }
}
string galgjeLaadBetekenis(const string& woord) {
    ifstream galgjeBetekenisBestand("galgjeBetekenis.txt");
    if (!galgjeBetekenisBestand) {
        cerr << "Fout: Bestand kan niet worden geopend." << endl;
        return "";
    }

    string galgjeBetekenis;
    string galgjeLine;
    while (getline(galgjeBetekenisBestand, galgjeLine)) {
        if (galgjeLine.find(woord) != string::npos) {
            galgjeBetekenis = galgjeLine.substr(galgjeLine.find(":") + 1); // Neem de betekenis na de dubbele punt
            break;
        }
    }

    galgjeBetekenisBestand.close();
    return galgjeBetekenis;
}


int main() {
    galgjeUitleg();
}


