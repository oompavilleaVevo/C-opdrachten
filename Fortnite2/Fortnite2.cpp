#include <iostream>
using namespace std;


void agecheck(char use);
char use = '1';

int main() {
	cout << "Maak hier uw keuze uit welk programmatje u wilt gebruiken! " << endl << "1. leeftijdscheck" << endl;
	int keuze(0);
	cin >> keuze;
	if (keuze == 1) {
		agecheck(use);
	}
}



void agecheck(char use){
	system("cls");
	int leeftijd[2] = { 17, 17 };
	string naam[2] = { "Naam1","Naam2" };
	cout << " Persoon 1, Voer hier je naam in: ";
	cin >> naam[0];
	system("cls");
	cout << " Persoon 2, Voer hier je naam in: ";
	cin >> naam[1];
	system("cls");
	cout << "Hoe oud is " + naam[0] + ":" << endl;
	cin >> leeftijd[0];
	system("cls");
	cout << "Hoe oud is " + naam[1] + ":" << endl;
	cin >> leeftijd[1];
	system("cls");
	//cout << naam[0] << endl << leeftijd[0] << endl;
	//cout << naam[1] << endl << leeftijd[1] << endl;
	if (leeftijd[0] > leeftijd[1]) {
		cout << naam[0] + " is de oudste";
	}
	else if (leeftijd[0] == leeftijd[1]) {
		cout << " dus " << naam[0] + " is even oud als " + naam[1] << "!        ";
	}
	else cout << naam[0] + " is de jongste!  ";

	system("pause");

}