#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <windows.h>
using namespace std;

//globale functies
void agecheck();
void bigcheck();
void bigsearch();
void searchstudent();
void infinitenames();
void galgjespel();
void pointnaam(string* naamopslag);


// galgje
int keuze;
void galgjespel();
void userdata();
void galgje();




#define STUDENTEN_SIZE 5
string namen[STUDENTEN_SIZE];
int leeftijden[STUDENTEN_SIZE];
int invoer;
int invoer2;
string resultaat;
int j;
int i;
//string naamopslag[STUDENTEN_SIZE];

//hoofdmenu/keuzemenu
int main() {
	int keuze = 0;
	while (true) {

		system("cls");
		cout << "Maak hier uw keuze welk programmetje u wilt gebruiken:" << endl << "1. Exit" << endl << "2. Agecheck" << endl
			<< "3. Bigcheck" << endl << "4. Namenzoek van bepaalde leeftijd" << endl << "5. student search" << endl << "6. infinitenames/infinitenames2.0" <<
			endl << "7. Galgje" << endl;
		cin >> keuze;
		system("cls");
		switch (keuze) {
		case 1:
			exit(0);
			break;
		case 2:
			agecheck();
			break;
		case 3:
			bigcheck();
			break;
		case 4:
			bigsearch();
			break;
		case 5:
			searchstudent();
			break;
		case 6:
			infinitenames();
			break;
		case 7:
			galgjespel();
			break;


		default:
			cout << "HEY! niet doen he" << endl;
			break;
		}
		system("pause");
	}
}

//kleine leeftijdscheck
void agecheck() {
	string name[2] = { "name1", "name2" };
	int age[2] = { 17, 16 };
	cout << "Persoon 1 voer hier uw naam in:" << endl;
	cin >> name[0];
	system("cls");
	cout << "Persoon 2 voer hier uw naam in:" << endl;
	cin >> name[1];
	system("cls");
	cout << "Hoe oud is " + name[0] + ":" << endl;
	cin >> age[0];
	system("cls");
	cout << "Hoe oud is " + name[1] + ":" << endl;
	cin >> age[1];
	system("cls");
	cout << name[0] + " is " << age[0] << endl;
	cout << name[1] + " is " << age[1] << endl;
	if (age[0] > age[1]) {
		cout << "Dus " << name[0] + " is ouder ";
	}
	else if (age[0] == age[1]) {
		cout << "Dus " << name[0] + " is even oud als " + name[1] << endl;;
	}
	else {
		cout << "Dus " << name[0] + " is jonger " << endl;
	}
}


//invoeren van namen en leeftijden
void bigcheck() {
	for (int i = 0; i < STUDENTEN_SIZE; i++) {
		cout << "Hoe heet u?" << endl;
		cin >> namen[i];
		cout << endl << "Hoe oud bent u, " + namen[i] << "?" << endl;
		cin >> leeftijden[i];
		system("cls");
	}
}

//ophalen van namen + leeftijden
void bigsearch() {
	int invoer2 = 0;
	int invoer = 0;
	string resultaat[20];
	cout << "Van welke leeftijd wilt u de namen zien:" << endl;
	cin >> invoer;

	for (int i = 0; i < STUDENTEN_SIZE; i++) {
		if (invoer == leeftijden[i]) {
			resultaat[invoer2] += namen[i];
			invoer2 += 1;
		}
	}
	if (invoer2 == 0) {
		cout << "Er is niks gevonden";
		return;
	}
	//weergeven van namen met die bepaalde leeftijd

	for (int j = 0; j < invoer2; j++) {
		cout << endl << resultaat[j] << " is " << invoer << endl;
	}

	cout << endl << "U wordt nu teruggestuurd naar het hoofdmenu" << endl;
}

void searchstudent() {
	//zoeken naar student/ opslaan van ingevoerde namen
	string studenten[STUDENTEN_SIZE];
	string zoeken;


	//loopt 5 keer of meer door de namen heen
	for (int i = 0; i < STUDENTEN_SIZE; i++) {
		cout << "Voer de namen in: " << endl;
		cin >> studenten[i];
	}
	//ful de letters in van de naam die u wilt zoeken
	system("cls");
	cout << "Naar welke naam zoekt u:  " << endl;
	cin >> zoeken;
	string zoek = zoeken.substr(0, 3);

	//laat de namen met de 3 letters die u had opgesgreven
	system("cls");
	cout << "U heeft ingevoerd: " << zoeken << endl << "Resultaten zijn: " << endl;
	for (const string& naam : studenten) {
		string subnaam = naam.substr(0, 3);

		if (zoek != subnaam)
			continue;
		//laat de namen zien
		cout << naam << endl;
	}


}


void infinitenames() {
	vector<string> studentnamen;
	string naamopslag;

	do {
		cout << "Type quit om te returnen...!  " << endl << "Welke namen wilt u opslaan?  " << endl;


		// namen worden opgeslagen in naamopslag en worden daarna gepushed in studentnamen
		cin >> naamopslag;
		studentnamen.push_back(naamopslag);
		system("cls");

		// als je quit invoerd dan skipt het de code en return je weer naar het menubalk
	} while (naamopslag != "quit");

	//cout << "De opgeslagen namen zijn:  " << endl;

	studentnamen.pop_back();
	// de namen worden op het scherm getoont 
	//for (i = 0; i < studentnamen.size(); i++) {
		//cout << studentnamen[i] << endl;

//	}





	string* v = &studentnamen[0];
	pointnaam(v);

	return;
	system("cls");
}


//hier een nieuwe functie die als parameter een pointer type string vraagt
//in de functie kijk je hoeveel elementen in de array zitten
//gebruik de pointer om door de array te wandelen om de namen te tonen

/// <summary>
///in deze funtie gaan we alle studenten tonen die in de vector array zijn opgeslagen
///voor het benaderen van deze vector array vragen we als parameter niet de hele array
///maar alleen een pointer die verwijst naar de array, cout << "we gaan hier de studentnamen tonen obv de pointer " << endl;
/// </summary>
/// <param name="naamopslag"></param>
void pointnaam(string* naamopslag) {
	cout << *naamopslag << endl << endl;

	cout << "Opgehaalde namen: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << *naamopslag << endl;
		naamopslag++;
	}
	cout << endl << "Dit zijn de opgehaalde namen!" << endl;
	system("pause"); }





void galgjespel() {

	std::cout << "welkom bij het wonderlijke spel galgje" << std::endl;
	std::cout << "kies uit de opties onder" << std::endl;
	std::cout << "1. Return to home.. " << std::endl;
	std::cout << "2. Galgje " << std::endl;

	cin >> keuze;
	switch (keuze) {
	case 1:
		exit(0);
		break;
	case 2:
		galgje();}
}

/// <summary>
/// letters opslag voor geraden letters door gebruiker, het gevragen woord
/// </summary>
unordered_set<char> letters;
string woord;

void weergave() {
	for (const char geradenLetter : woord) {
		if (letters.contains(geradenLetter)) {
			cout << geradenLetter;
		}
		else {
			//niet geraden
			cout << '-';
		}
		std::cout << std::endl;	}
}

	void userdata() {
		char letter;
		std::cout << "Voer een letter in om het woord te raden!" << std::endl;
		while (cin >> letter)
		{
			system("cls");
			letter = tolower(letter); //maakt letter lowercase als uppercase invoert
			if (!letters.contains(letter)) //is de letter nog niet geraden is
			{
				letters.insert(letter);
				break;
			}
			std::cout << " De letter: " << letter << " is al eens geraden" << std::endl;
		}
	}

	/// <summary>
	/// vraagt om het woord en loopt het 7 keer voordat het afsluit. 7 levens dus
	/// </summary>
	void galgje() {
		system("cls");
		std::cout << "welk woord wilt u dat de gebruiker raad?" << std::endl;
		std::cin >> woord;
		system("cls");

		for (int i = 0; i< 7; i++) {
			userdata();
			weergave();
			//system("pause");
			}
		if ("") {
			std::cout << "Goed gespeeld, je hebt het woord geraden" << std::endl;
			
		}else {

		}
		//system("pause");
		//system("cls");
	}
	