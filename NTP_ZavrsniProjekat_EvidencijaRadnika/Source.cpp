#include<iostream>
#include<Windows.h>
#include<string>
#include<thread>
#include<chrono>
#include<fstream>
#include<iomanip>
#include<ctime>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>

using namespace std;
//ZA DEKORACIJU
using std::flush;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
#pragma warning(disable : 4996) //NE DIRAJ OVO
//KRAJ ZA DEKORACIJU

enum statusRadnika { Nezaposlen = 0, Zaposlen };

struct Posao {
	char nazivFirme[50];
	char pozicijaUFirmi[50];
	char adresaFirme[50];
	float plata;
	int godinaZaposlenja;
};

struct Radnik {
	int uID;
	char ime[50];
	char prezime[50];
	char datumRodjenja[15];
	char adresaStanovanja[50];
	char brojTelefona[13];
	char emailAdresa[50];
	statusRadnika zaposlenje;
	Posao mjestoZaposlenja;
};

Radnik tmpRadnik[1000];

//DODATNE FUNKCIJE------>
void dekoracijaMainMenu(const string&, unsigned int);
void ucitajMenu();
//<------KRAJ DODATNIH FUNKCIJA

//REGULARNE FUNKCIJE------>
void unosRadnika(Radnik& R) {
	cout << "\t::OSNOVNI PODACI O RADNIKU::\n";
	cout << "Unesite ID radnika: ";
	cin >> R.uID;
	cin.ignore();
	cin.clear();
	cout << "Unesite ime radnika: ";
	cin.getline(R.ime, 50);
	cout << "Unesite prezime radnika: ";
	cin.getline(R.prezime, 50);
	cout << "Unesite datum rodjenja: ";
	cin.getline(R.datumRodjenja, 15);
	cout << "Unesite adresu stanovanja radnika: ";
	cin.getline(R.adresaStanovanja, 50);
	cout << "Unesite broj telefona radnika: ";
	cin >> R.brojTelefona;
	cin.ignore();
	cout << "Unesite e-mail radnika: ";
	cin.getline(R.emailAdresa, 50);
	cout << "\n\t::PODACI O ZAPOSLENJU RADNIKA::\n";
	cout << "Unesite ime firme u kojoj je " << R.ime << " " << R.prezime << " zaposlen: ";
	cin.getline(R.mjestoZaposlenja.nazivFirme, 50);
	cout << "Unesite poziciju u firmi: ";
	cin.getline(R.mjestoZaposlenja.pozicijaUFirmi, 50);
	cout << "Unesite adresu firme: ";
	cin.getline(R.mjestoZaposlenja.adresaFirme, 50);
	cout << "Unsite godinu zaposlenja: ";
	cin >> R.mjestoZaposlenja.godinaZaposlenja; //popravljeno!!!!!!!!!!!!!!!! kod upisa. 
	cin.ignore();
	cin.clear();
	cout << "Unesite platu za radnika " << R.ime << " " << R.prezime << " : ";
	cin >> R.mjestoZaposlenja.plata;
	cin.ignore();
	cin.clear();
	Sleep(200);
	MessageBoxA(NULL, "Unos radnika uspjesan!!", "Obavijest!", MB_OK | MB_ICONINFORMATION);
}
//WARNING ACHTUNG POKUSO SAM DA PRAVIM ISPIS DOLE U . MENIJU KAKO BI LAKSE TABAK MOGO PREGLEDAT AL ME MALO SEX U MOZAK KAKO NASTIMAT
// DA PRAVI ISPIS IAKO SU ZAPOSLI I AKO NISU KOTATE.. (POKUSAO, KO ZNA DA URADI BUJRUM) 

void ispis(Radnik* R) {
	cout << "Ime: " << R->ime << endl;
	cout << "Prezime: " << R->prezime << endl;
	cout << "Datum rodjenja radnika: " << R->datumRodjenja << endl;
	cout << "Adresa stanovanja radnika: " << R->adresaStanovanja << endl;
	cout << "Broj telefona: " << R->brojTelefona << endl;
	cout << "Email adresa: " << R->emailAdresa << endl;
	cout << "Ime firme: " << R->mjestoZaposlenja.nazivFirme << endl;
	cout << "Pozicija u firmi: " << R->mjestoZaposlenja.pozicijaUFirmi << endl;
	cout << "Adresa firme: " << R->mjestoZaposlenja.adresaFirme << endl;
	cout << "Godina zaposljenja: " << R->mjestoZaposlenja.godinaZaposlenja << endl;
	cout << "Plata (neto + bruto): " << R->mjestoZaposlenja.plata << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;
	cout << endl;
}

void editRadnika(Radnik* R) {
	int izbor;
	system("cls");
	cout << "Odaberite sta zelite da uredite: " << endl;
	cout << "\t1. Ime radnika\n\t2. Prezime radnika\n\t3. Adresa stanovanja\n\t4. Broj telefona\n\t5. E-mail adresa\n\t6. Pozicija u firmi\n\t7. Plata\n";
	cin >> izbor;
	cin.ignore();
	cin.clear();
	switch (izbor)
	{
	case 1:
		char novoIme[50];
		cout << "Unesite novo ime: ";
		cin.getline(novoIme, 50);
		strcpy(R->ime, novoIme);
		break;
	case 2:
		char novoPrezime[50];
		cout << "Unesite novo prezime: ";
		cin.getline(novoPrezime, 50);
		strcpy(R->prezime, novoPrezime);
		break;
	case 3:
		char novaAdresaStanovanja[50];
		cout << "Unesite novu adresu stanovanja: ";
		cin.getline(novaAdresaStanovanja, 50);
		strcpy(R->adresaStanovanja, novaAdresaStanovanja);
		break;
	case 4:
		char noviBrojTelefona[50];
		cout << "Unesite novi broj telefona: ";
		cin.getline(noviBrojTelefona, 50);
		strcpy(R->brojTelefona, noviBrojTelefona);
		break;
	case 5:
		char noviEmailAdresa[50];
		cout << "Unesite novu email adresu: ";
		cin.getline(noviEmailAdresa, 50);
		strcpy(R->emailAdresa, noviEmailAdresa);
		break;
	case 6:
		char novaPozicijaUFirmi[50];
		cout << "Unesite novu poziciju u firmi: ";
		cin.getline(novaPozicijaUFirmi, 50);
		strcpy(R->mjestoZaposlenja.pozicijaUFirmi, novaPozicijaUFirmi);
		break;
	case 7:
		float novaPlata;
		cout << "Unesite novu platu: ";
		cin >> novaPlata;
		R->mjestoZaposlenja.plata = novaPlata;
		break;
	default:
		break;
	}
}

void pretragaRadnika(Radnik* lRadnika, int kapacitetBaze) {
	int izborPretrage, brojPretrazenihRadnika = 0, redniBrojRadnika, pronadjeniRadnici[100], izborZaEdit;
	cout << "Odaberite sta zelite da pretrazite: " << endl;
	cout << "\t1. Ime radnika\n\t2. Prezime radnika\n\t3. Datum rodjenja\n\t4. Adresa stanovanja\n\t5. Broj telefona\n\t6. E-mail adresa\n\t7. Ime firme\n\t8. Pozicija u firmi\n\t9. Adresa firme\n\t10. Godina zaposlenja\n\t11. Plata\n";
	bool ispravanIzborPretrage = false;
	do
	{
		cout << "------------>Unesite izbor: ";
		cin >> izborPretrage;
		switch (izborPretrage) {
		case 1:
			system("cls");
			ispravanIzborPretrage = true;
			cout << "Unesite ime radnika:";
			char pretragaImena[50];
			cin >> pretragaImena;
			for (int i = 0; i < kapacitetBaze; i++) {
				if (strcmp(lRadnika[i].ime, pretragaImena) == 0) {
					redniBrojRadnika = i;
					pronadjeniRadnici[brojPretrazenihRadnika] = redniBrojRadnika;
					brojPretrazenihRadnika++;
				}
			}
			if (brojPretrazenihRadnika == 0) {
				cout << "Nazalost u bazi nemamo radnika kojeg ste trazili :(\n";
			}
			else if (brojPretrazenihRadnika == 1) {
				cout << "---------------------------------------------" << endl;
				cout << "U bazi imamo trazenog radnika!" << endl;
				cout << "---------------------------------------------" << endl;
				Sleep(200);
				system("cls");
				ispis(&lRadnika[redniBrojRadnika]);
				cout << "Da li zelite urediti podatke o radniku? 1-DA/0-NE: ";
				cin >> izborZaEdit;
				cin.ignore();
				cin.clear();
				if (izborZaEdit == 1) {
					editRadnika(&lRadnika[redniBrojRadnika]);
				}
			}
			else {
				int izborRadnika;
				bool ispravanIzborRadnika = false;
				cout << "---------------------------------------------" << endl;
				cout << "U bazi imamo vise trazenih radnika!" << endl;
				cout << "---------------------------------------------" << endl;
				Sleep(200);
				system("cls");
				cout << "Lista radnika iz pretrage: " << endl;
				for (int i = 0; i < brojPretrazenihRadnika; i++) {
					cout << "\t" << pronadjeniRadnici[i] + 1 << ". " << lRadnika[pronadjeniRadnici[i]].ime << " " << lRadnika[pronadjeniRadnici[i]].prezime << endl;
				}
				do {
					cout << "------------>Unesite izbor: ";
					cin >> izborRadnika;
					for (int i = 0; i < brojPretrazenihRadnika; i++) {
						if (izborRadnika - 1 == pronadjeniRadnici[i]) {
							system("cls");
							ispravanIzborRadnika = true;
							ispis(&lRadnika[izborRadnika]);
						}
					}
					if (!ispravanIzborRadnika) {
						cout << "Greska!Unijeti izbor nije validan." << endl;
					}
				} while (!ispravanIzborRadnika);
				cout << "Da li zelite urediti podatke o radniku? 1-DA/0-NE: ";
				cin >> izborZaEdit;
				cin.ignore();
				cin.clear();
				if (izborZaEdit == 1) {
					editRadnika(&lRadnika[redniBrojRadnika]);
				}
			}
			break;
		case 2:
			system("cls");
			ispravanIzborPretrage = true;
			cout << "Unesite prezime radnika:";
			char pretragaPrezimena[50];
			cin >> pretragaPrezimena;
			for (int i = 0; i < kapacitetBaze; i++) {
				if (strcmp(lRadnika[i].prezime, pretragaPrezimena) == 0) {
					redniBrojRadnika = i;
					pronadjeniRadnici[brojPretrazenihRadnika] = redniBrojRadnika;
					brojPretrazenihRadnika++;
				}
			}
			if (brojPretrazenihRadnika == 0) {
				cout << "Nazalost u bazi nemamo radnika kojeg ste trazili :(\n";
			}
			else if (brojPretrazenihRadnika == 1) {
				cout << "---------------------------------------------" << endl;
				cout << "U bazi imamo trazenog radnika!" << endl;
				cout << "---------------------------------------------" << endl;
				Sleep(200);
				system("cls");
				ispis(&lRadnika[redniBrojRadnika]);
				cout << "Da li zelite urediti podatke o radniku? 1-DA/0-NE: ";
				cin >> izborZaEdit;
				cin.ignore();
				cin.clear();
				if (izborZaEdit == 1) {
					editRadnika(&lRadnika[redniBrojRadnika]);
				}
			}
			else {
				int izborRadnika;
				bool ispravanIzborRadnika = false;
				cout << "---------------------------------------------" << endl;
				cout << "U bazi imamo vise trazenih radnika!" << endl;
				cout << "---------------------------------------------" << endl;
				Sleep(200);
				system("cls");
				cout << "Lista radnika iz pretrage: " << endl;
				for (int i = 0; i < brojPretrazenihRadnika; i++) {
					cout << "\t" << pronadjeniRadnici[i] + 1 << ". " << lRadnika[pronadjeniRadnici[i]].ime << " " << lRadnika[pronadjeniRadnici[i]].prezime << endl;
				}
				do {
					cout << "------------>Unesite izbor: ";
					cin >> izborRadnika;
					for (int i = 0; i < brojPretrazenihRadnika; i++) {
						if (izborRadnika - 1 == pronadjeniRadnici[i]) {
							system("cls");
							ispravanIzborRadnika = true;
							ispis(&lRadnika[izborRadnika]);
						}
					}
					if (!ispravanIzborRadnika) {
						cout << "Greska!Unijeti izbor nije validan." << endl;
					}
				} while (!ispravanIzborRadnika);
				cout << "Da li zelite urediti podatke o radniku? 1-DA/0-NE: ";
				cin >> izborZaEdit;
				cin.ignore();
				cin.clear();
				if (izborZaEdit == 1) {
					editRadnika(&lRadnika[redniBrojRadnika]);
				}
			}
			break;
		case 3:
			system("cls");
			ispravanIzborPretrage = true;
			cout << "Unesite datum rodjenja radnika:";
			char pretragaDatumaRodjenja[15];
			cin >> pretragaDatumaRodjenja;
			for (int i = 0; i < kapacitetBaze; i++) {
				if (strcmp(lRadnika[i].datumRodjenja, pretragaDatumaRodjenja) == 0) {
					redniBrojRadnika = i;
					pronadjeniRadnici[brojPretrazenihRadnika] = redniBrojRadnika;
					brojPretrazenihRadnika++;
				}
			}
			if (brojPretrazenihRadnika == 0) {
				cout << "Nazalost u bazi nemamo radnika kojeg ste trazili :(\n";
			}
			else if (brojPretrazenihRadnika == 1) {
				cout << "---------------------------------------------" << endl;
				cout << "U bazi imamo trazenog radnika!" << endl;
				cout << "---------------------------------------------" << endl;
				Sleep(200);
				system("cls");
				ispis(&lRadnika[redniBrojRadnika]);
				cout << "Da li zelite urediti podatke o radniku? 1-DA/0-NE: ";
				cin >> izborZaEdit;
				cin.ignore();
				cin.clear();
				if (izborZaEdit == 1) {
					editRadnika(&lRadnika[redniBrojRadnika]);
				}
			}
			else {
				int izborRadnika;
				bool ispravanIzborRadnika = false;
				cout << "---------------------------------------------" << endl;
				cout << "U bazi imamo vise trazenih radnika!" << endl;
				cout << "---------------------------------------------" << endl;
				Sleep(200);
				system("cls");
				cout << "Lista radnika iz pretrage: " << endl;
				for (int i = 0; i < brojPretrazenihRadnika; i++) {
					cout << "\t" << pronadjeniRadnici[i] + 1 << ". " << lRadnika[pronadjeniRadnici[i]].ime << " " << lRadnika[pronadjeniRadnici[i]].prezime << endl;
				}
				do {
					cout << "------------>Unesite izbor: ";
					cin >> izborRadnika;
					for (int i = 0; i < brojPretrazenihRadnika; i++) {
						if (izborRadnika - 1 == pronadjeniRadnici[i]) {
							system("cls");
							ispravanIzborRadnika = true;
							ispis(&lRadnika[izborRadnika]);
						}
					}
					if (!ispravanIzborRadnika) {
						cout << "Greska!Unijeti izbor nije validan." << endl;
					}
				} while (!ispravanIzborRadnika);
				cout << "Da li zelite urediti podatke o radniku? 1-DA/0-NE: ";
				cin >> izborZaEdit;
				cin.ignore();
				cin.clear();
				if (izborZaEdit == 1) {
					editRadnika(&lRadnika[redniBrojRadnika]);
				}
			}
			break;
		case 4:
			system("cls");
			ispravanIzborPretrage = true;
			cout << "Unesite adresu stanovanja radnika:";
			char pretragaAdreseStanovanja[50];
			cin >> pretragaAdreseStanovanja;
			for (int i = 0; i < kapacitetBaze; i++) {
				if (strcmp(lRadnika[i].adresaStanovanja, pretragaAdreseStanovanja) == 0) {
					redniBrojRadnika = i;
					pronadjeniRadnici[brojPretrazenihRadnika] = redniBrojRadnika;
					brojPretrazenihRadnika++;
				}
			}
			if (brojPretrazenihRadnika == 0) {
				cout << "Nazalost u bazi nemamo radnika kojeg ste trazili :(\n";
			}
			else if (brojPretrazenihRadnika == 1) {
				cout << "---------------------------------------------" << endl;
				cout << "U bazi imamo trazenog radnika!" << endl;
				cout << "---------------------------------------------" << endl;
				Sleep(200);
				system("cls");
				ispis(&lRadnika[redniBrojRadnika]);
				cout << "Da li zelite urediti podatke o radniku? 1-DA/0-NE: ";
				cin >> izborZaEdit;
				cin.ignore();
				cin.clear();
				if (izborZaEdit == 1) {
					editRadnika(&lRadnika[redniBrojRadnika]);
				}
			}
			else {
				int izborRadnika;
				bool ispravanIzborRadnika = false;
				cout << "---------------------------------------------" << endl;
				cout << "U bazi imamo vise trazenih radnika!" << endl;
				cout << "---------------------------------------------" << endl;
				Sleep(200);
				system("cls");
				cout << "Lista radnika iz pretrage: " << endl;
				for (int i = 0; i < brojPretrazenihRadnika; i++) {
					cout << "\t" << pronadjeniRadnici[i] + 1 << ". " << lRadnika[pronadjeniRadnici[i]].ime << " " << lRadnika[pronadjeniRadnici[i]].prezime << endl;
				}
				do {
					cout << "------------>Unesite izbor: ";
					cin >> izborRadnika;
					for (int i = 0; i < brojPretrazenihRadnika; i++) {
						if (izborRadnika - 1 == pronadjeniRadnici[i]) {
							system("cls");
							ispravanIzborRadnika = true;
							ispis(&lRadnika[izborRadnika]);
						}
					}
					if (!ispravanIzborRadnika) {
						cout << "Greska!Unijeti izbor nije validan." << endl;
					}
				} while (!ispravanIzborRadnika);
				cout << "Da li zelite urediti podatke o radniku? 1-DA/0-NE: ";
				cin >> izborZaEdit;
				cin.ignore();
				cin.clear();
				if (izborZaEdit == 1) {
					editRadnika(&lRadnika[redniBrojRadnika]);
				}
			}
			break;
		case 5:
			system("cls");
			ispravanIzborPretrage = true;
			cout << "Unesite broj telefona radnika:";
			char pretragaBrojaTelefona[13];
			cin >> pretragaBrojaTelefona;
			for (int i = 0; i < kapacitetBaze; i++) {
				if (strcmp(lRadnika[i].brojTelefona, pretragaBrojaTelefona) == 0) {
					redniBrojRadnika = i;
					pronadjeniRadnici[brojPretrazenihRadnika] = redniBrojRadnika;
					brojPretrazenihRadnika++;
				}
			}
			if (brojPretrazenihRadnika == 0) {
				cout << "Nazalost u bazi nemamo radnika kojeg ste trazili :(\n";
			}
			else if (brojPretrazenihRadnika == 1) {
				cout << "---------------------------------------------" << endl;
				cout << "U bazi imamo trazenog radnika!" << endl;
				cout << "---------------------------------------------" << endl;
				Sleep(200);
				system("cls");
				ispis(&lRadnika[redniBrojRadnika]);
				cout << "Da li zelite urediti podatke o radniku? 1-DA/0-NE: ";
				cin >> izborZaEdit;
				cin.ignore();
				cin.clear();
				if (izborZaEdit == 1) {
					editRadnika(&lRadnika[redniBrojRadnika]);
				}
			}
			else {
				int izborRadnika;
				bool ispravanIzborRadnika = false;
				cout << "---------------------------------------------" << endl;
				cout << "U bazi imamo vise trazenih radnika!" << endl;
				cout << "---------------------------------------------" << endl;
				Sleep(200);
				system("cls");
				cout << "Lista radnika iz pretrage: " << endl;
				for (int i = 0; i < brojPretrazenihRadnika; i++) {
					cout << "\t" << pronadjeniRadnici[i] + 1 << ". " << lRadnika[pronadjeniRadnici[i]].ime << " " << lRadnika[pronadjeniRadnici[i]].prezime << endl;
				}
				do {
					cout << "------------>Unesite izbor: ";
					cin >> izborRadnika;
					for (int i = 0; i < brojPretrazenihRadnika; i++) {
						if (izborRadnika - 1 == pronadjeniRadnici[i]) {
							system("cls");
							ispravanIzborRadnika = true;
							ispis(&lRadnika[izborRadnika]);
						}
					}
					if (!ispravanIzborRadnika) {
						cout << "Greska!Unijeti izbor nije validan." << endl;
					}
				} while (!ispravanIzborRadnika);
				cout << "Da li zelite urediti podatke o radniku? 1-DA/0-NE: ";
				cin >> izborZaEdit;
				cin.ignore();
				cin.clear();
				if (izborZaEdit == 1) {
					editRadnika(&lRadnika[redniBrojRadnika]);
				}
			}
			break;
		case 6:
			system("cls");
			ispravanIzborPretrage = true;
			cout << "Unesite email adresu radnika:";
			char pretragaEmailAdrese[50];
			cin >> pretragaEmailAdrese;
			for (int i = 0; i < kapacitetBaze; i++) {
				if (strcmp(lRadnika[i].emailAdresa, pretragaEmailAdrese) == 0) {
					redniBrojRadnika = i;
					pronadjeniRadnici[brojPretrazenihRadnika] = redniBrojRadnika;
					brojPretrazenihRadnika++;
				}
			}
			if (brojPretrazenihRadnika == 0) {
				cout << "Nazalost u bazi nemamo radnika kojeg ste trazili :(\n";
			}
			else if (brojPretrazenihRadnika == 1) {
				cout << "---------------------------------------------" << endl;
				cout << "U bazi imamo trazenog radnika!" << endl;
				cout << "---------------------------------------------" << endl;
				Sleep(200);
				system("cls");
				ispis(&lRadnika[redniBrojRadnika]);
				cout << "Da li zelite urediti podatke o radniku? 1-DA/0-NE: ";
				cin >> izborZaEdit;
				cin.ignore();
				cin.clear();
				if (izborZaEdit == 1) {
					editRadnika(&lRadnika[redniBrojRadnika]);
				}
			}
			else {
				int izborRadnika;
				bool ispravanIzborRadnika = false;
				cout << "---------------------------------------------" << endl;
				cout << "U bazi imamo vise trazenih radnika!" << endl;
				cout << "---------------------------------------------" << endl;
				Sleep(200);
				system("cls");
				cout << "Lista radnika iz pretrage: " << endl;
				for (int i = 0; i < brojPretrazenihRadnika; i++) {
					cout << "\t" << pronadjeniRadnici[i] + 1 << ". " << lRadnika[pronadjeniRadnici[i]].ime << " " << lRadnika[pronadjeniRadnici[i]].prezime << endl;
				}
				do {
					cout << "------------>Unesite izbor: ";
					cin >> izborRadnika;
					for (int i = 0; i < brojPretrazenihRadnika; i++) {
						if (izborRadnika - 1 == pronadjeniRadnici[i]) {
							system("cls");
							ispravanIzborRadnika = true;
							ispis(&lRadnika[izborRadnika]);
						}
					}
					if (!ispravanIzborRadnika) {
						cout << "Greska!Unijeti izbor nije validan." << endl;
					}
				} while (!ispravanIzborRadnika);
				cout << "Da li zelite urediti podatke o radniku? 1-DA/0-NE: ";
				cin >> izborZaEdit;
				cin.ignore();
				cin.clear();
				if (izborZaEdit == 1) {
					editRadnika(&lRadnika[redniBrojRadnika]);
				}
			}
			break;
		case 7:
			system("cls");
			ispravanIzborPretrage = true;
			cout << "Unesite ime firme radnika:";
			char pretragaNazivaFirme[50];
			cin >> pretragaNazivaFirme;
			for (int i = 0; i < kapacitetBaze; i++) {
				if (strcmp(lRadnika[i].mjestoZaposlenja.nazivFirme, pretragaNazivaFirme) == 0) {
					redniBrojRadnika = i;
					pronadjeniRadnici[brojPretrazenihRadnika] = redniBrojRadnika;
					brojPretrazenihRadnika++;
				}
			}
			if (brojPretrazenihRadnika == 0) {
				cout << "Nazalost u bazi nemamo radnika kojeg ste trazili :(\n";
			}
			else if (brojPretrazenihRadnika == 1) {
				cout << "---------------------------------------------" << endl;
				cout << "U bazi imamo trazenog radnika!" << endl;
				cout << "---------------------------------------------" << endl;
				Sleep(200);
				system("cls");
				ispis(&lRadnika[redniBrojRadnika]);
				cout << "Da li zelite urediti podatke o radniku? 1-DA/0-NE: ";
				cin >> izborZaEdit;
				cin.ignore();
				cin.clear();
				if (izborZaEdit == 1) {
					editRadnika(&lRadnika[redniBrojRadnika]);
				}
			}
			else {
				int izborRadnika;
				bool ispravanIzborRadnika = false;
				cout << "---------------------------------------------" << endl;
				cout << "U bazi imamo vise trazenih radnika!" << endl;
				cout << "---------------------------------------------" << endl;
				Sleep(200);
				system("cls");
				cout << "Lista radnika iz pretrage: " << endl;
				for (int i = 0; i < brojPretrazenihRadnika; i++) {
					cout << "\t" << pronadjeniRadnici[i] + 1 << ". " << lRadnika[pronadjeniRadnici[i]].ime << " " << lRadnika[pronadjeniRadnici[i]].prezime << endl;
				}
				do {
					cout << "------------>Unesite izbor: ";
					cin >> izborRadnika;
					for (int i = 0; i < brojPretrazenihRadnika; i++) {
						if (izborRadnika - 1 == pronadjeniRadnici[i]) {
							system("cls");
							ispravanIzborRadnika = true;
							ispis(&lRadnika[izborRadnika]);
						}
					}
					if (!ispravanIzborRadnika) {
						cout << "Greska!Unijeti izbor nije validan." << endl;
					}
				} while (!ispravanIzborRadnika);
				cout << "Da li zelite urediti podatke o radniku? 1-DA/0-NE: ";
				cin >> izborZaEdit;
				cin.ignore();
				cin.clear();
				if (izborZaEdit == 1) {
					editRadnika(&lRadnika[redniBrojRadnika]);
				}
			}
			break;
		case 8:
			system("cls");
			ispravanIzborPretrage = true;
			cout << "Unesite poziciju u firmi radnika:";
			char pretragaPozicijeUFirmi[50];
			cin >> pretragaPozicijeUFirmi;
			for (int i = 0; i < kapacitetBaze; i++) {
				if (strcmp(lRadnika[i].mjestoZaposlenja.pozicijaUFirmi, pretragaPozicijeUFirmi) == 0) {
					redniBrojRadnika = i;
					pronadjeniRadnici[brojPretrazenihRadnika] = redniBrojRadnika;
					brojPretrazenihRadnika++;
				}
			}
			if (brojPretrazenihRadnika == 0) {
				cout << "Nazalost u bazi nemamo radnika kojeg ste trazili :(\n";
			}
			else if (brojPretrazenihRadnika == 1) {
				cout << "---------------------------------------------" << endl;
				cout << "U bazi imamo trazenog radnika!" << endl;
				cout << "---------------------------------------------" << endl;
				Sleep(200);
				system("cls");
				ispis(&lRadnika[redniBrojRadnika]);
				cout << "Da li zelite urediti podatke o radniku? 1-DA/0-NE: ";
				cin >> izborZaEdit;
				cin.ignore();
				cin.clear();
				if (izborZaEdit == 1) {
					editRadnika(&lRadnika[redniBrojRadnika]);
				}
			}
			else {
				int izborRadnika;
				bool ispravanIzborRadnika = false;
				cout << "---------------------------------------------" << endl;
				cout << "U bazi imamo vise trazenih radnika!" << endl;
				cout << "---------------------------------------------" << endl;
				Sleep(200);
				system("cls");
				cout << "Lista radnika iz pretrage: " << endl;
				for (int i = 0; i < brojPretrazenihRadnika; i++) {
					cout << "\t" << pronadjeniRadnici[i] + 1 << ". " << lRadnika[pronadjeniRadnici[i]].ime << " " << lRadnika[pronadjeniRadnici[i]].prezime << endl;
				}
				do {
					cout << "------------>Unesite izbor: ";
					cin >> izborRadnika;
					for (int i = 0; i < brojPretrazenihRadnika; i++) {
						if (izborRadnika - 1 == pronadjeniRadnici[i]) {
							system("cls");
							ispravanIzborRadnika = true;
							ispis(&lRadnika[izborRadnika]);
						}
					}
					if (!ispravanIzborRadnika) {
						cout << "Greska!Unijeti izbor nije validan." << endl;
					}
				} while (!ispravanIzborRadnika);
				cout << "Da li zelite urediti podatke o radniku? 1-DA/0-NE: ";
				cin >> izborZaEdit;
				cin.ignore();
				cin.clear();
				if (izborZaEdit == 1) {
					editRadnika(&lRadnika[redniBrojRadnika]);
				}
			}
			break;
		case 9:
			system("cls");
			ispravanIzborPretrage = true;
			cout << "Unesite adresu firme radnika:";
			char pretragaAdreseFirme[50];
			cin >> pretragaAdreseFirme;
			for (int i = 0; i < kapacitetBaze; i++) {
				if (strcmp(lRadnika[i].mjestoZaposlenja.adresaFirme, pretragaAdreseFirme) == 0) {
					redniBrojRadnika = i;
					pronadjeniRadnici[brojPretrazenihRadnika] = redniBrojRadnika;
					brojPretrazenihRadnika++;
				}
			}
			if (brojPretrazenihRadnika == 0) {
				cout << "Nazalost u bazi nemamo radnika kojeg ste trazili :(\n";
			}
			else if (brojPretrazenihRadnika == 1) {
				cout << "---------------------------------------------" << endl;
				cout << "U bazi imamo trazenog radnika!" << endl;
				cout << "---------------------------------------------" << endl;
				Sleep(200);
				system("cls");
				ispis(&lRadnika[redniBrojRadnika]);
				cout << "Da li zelite urediti podatke o radniku? 1-DA/0-NE: ";
				cin >> izborZaEdit;
				cin.ignore();
				cin.clear();
				if (izborZaEdit == 1) {
					editRadnika(&lRadnika[redniBrojRadnika]);
				}
			}
			else {
				int izborRadnika;
				bool ispravanIzborRadnika = false;
				cout << "---------------------------------------------" << endl;
				cout << "U bazi imamo vise trazenih radnika!" << endl;
				cout << "---------------------------------------------" << endl;
				Sleep(200);
				system("cls");
				cout << "Lista radnika iz pretrage: " << endl;
				for (int i = 0; i < brojPretrazenihRadnika; i++) {
					cout << "\t" << pronadjeniRadnici[i] + 1 << ". " << lRadnika[pronadjeniRadnici[i]].ime << " " << lRadnika[pronadjeniRadnici[i]].prezime << endl;
				}
				do {
					cout << "------------>Unesite izbor: ";
					cin >> izborRadnika;
					for (int i = 0; i < brojPretrazenihRadnika; i++) {
						if (izborRadnika - 1 == pronadjeniRadnici[i]) {
							system("cls");
							ispravanIzborRadnika = true;
							ispis(&lRadnika[izborRadnika]);
						}
					}
					if (!ispravanIzborRadnika) {
						cout << "Greska!Unijeti izbor nije validan." << endl;
					}
				} while (!ispravanIzborRadnika);
				cout << "Da li zelite urediti podatke o radniku? 1-DA/0-NE: ";
				cin >> izborZaEdit;
				cin.ignore();
				cin.clear();
				if (izborZaEdit == 1) {
					editRadnika(&lRadnika[redniBrojRadnika]);
				}
			}
			break;
		case 10:
			system("cls");
			ispravanIzborPretrage = true;
			cout << "Unesite godinu zaposljenja radnika:";
			int pretragaGodineZaposlenja;
			cin >> pretragaGodineZaposlenja;
			for (int i = 0; i < kapacitetBaze; i++) {
				if (lRadnika[i].mjestoZaposlenja.godinaZaposlenja == pretragaGodineZaposlenja) {
					redniBrojRadnika = i;
					pronadjeniRadnici[brojPretrazenihRadnika] = redniBrojRadnika;
					brojPretrazenihRadnika++;
				}
			}
			if (brojPretrazenihRadnika == 0) {
				cout << "Nazalost u bazi nemamo radnika kojeg ste trazili :(\n";
			}
			else if (brojPretrazenihRadnika == 1) {
				cout << "---------------------------------------------" << endl;
				cout << "U bazi imamo trazenog radnika!" << endl;
				cout << "---------------------------------------------" << endl;
				Sleep(200);
				system("cls");
				ispis(&lRadnika[redniBrojRadnika]);
				cout << "Da li zelite urediti podatke o radniku? 1-DA/0-NE: ";
				cin >> izborZaEdit;
				cin.ignore();
				cin.clear();
				if (izborZaEdit == 1) {
					editRadnika(&lRadnika[redniBrojRadnika]);
				}
			}
			else {
				int izborRadnika;
				bool ispravanIzborRadnika = false;
				cout << "---------------------------------------------" << endl;
				cout << "U bazi imamo vise trazenih radnika!" << endl;
				cout << "---------------------------------------------" << endl;
				Sleep(200);
				system("cls");
				cout << "Lista radnika iz pretrage: " << endl;
				for (int i = 0; i < brojPretrazenihRadnika; i++) {
					cout << "\t" << pronadjeniRadnici[i] + 1 << ". " << lRadnika[pronadjeniRadnici[i]].ime << " " << lRadnika[pronadjeniRadnici[i]].prezime << endl;
				}
				do {
					cout << "------------>Unesite izbor: ";
					cin >> izborRadnika;
					for (int i = 0; i < brojPretrazenihRadnika; i++) {
						if (izborRadnika - 1 == pronadjeniRadnici[i]) {
							system("cls");
							ispravanIzborRadnika = true;
							ispis(&lRadnika[izborRadnika]);
						}
					}
					if (!ispravanIzborRadnika) {
						cout << "Greska!Unijeti izbor nije validan." << endl;
					}
				} while (!ispravanIzborRadnika);
				cout << "Da li zelite urediti podatke o radniku? 1-DA/0-NE: ";
				cin >> izborZaEdit;
				cin.ignore();
				cin.clear();
				if (izborZaEdit == 1) {
					editRadnika(&lRadnika[redniBrojRadnika]);
				}
			}
			break;
		case 11:
			system("cls");
			ispravanIzborPretrage = true;
			cout << "Unesite platu radnika:";
			float pretragaPlate;
			cin >> pretragaPlate;
			for (int i = 0; i < kapacitetBaze; i++) {
				if (lRadnika[i].mjestoZaposlenja.plata == pretragaPlate) {
					redniBrojRadnika = i;
					pronadjeniRadnici[brojPretrazenihRadnika] = redniBrojRadnika;
					brojPretrazenihRadnika++;
				}
			}
			if (brojPretrazenihRadnika == 0) {
				cout << "Nazalost u bazi nemamo radnika kojeg ste trazili :(\n";
			}
			else if (brojPretrazenihRadnika == 1) {
				cout << "---------------------------------------------" << endl;
				cout << "U bazi imamo trazenog radnika!" << endl;
				cout << "---------------------------------------------" << endl;
				Sleep(200);
				system("cls");
				ispis(&lRadnika[redniBrojRadnika]);
				cout << "Da li zelite urediti podatke o radniku? 1-DA/0-NE: ";
				cin >> izborZaEdit;
				cin.ignore();
				cin.clear();
				if (izborZaEdit == 1) {
					editRadnika(&lRadnika[redniBrojRadnika]);
				}
			}
			else {
				int izborRadnika;
				bool ispravanIzborRadnika = false;
				cout << "---------------------------------------------" << endl;
				cout << "U bazi imamo vise trazenih radnika!" << endl;
				cout << "---------------------------------------------" << endl;
				Sleep(200);
				system("cls");
				cout << "Lista radnika iz pretrage: " << endl;
				for (int i = 0; i < brojPretrazenihRadnika; i++) {
					cout << "\t" << pronadjeniRadnici[i] + 1 << ". " << lRadnika[pronadjeniRadnici[i]].ime << " " << lRadnika[pronadjeniRadnici[i]].prezime << endl;
				}
				do {
					cout << "------------>Unesite izbor: ";
					cin >> izborRadnika;
					for (int i = 0; i < brojPretrazenihRadnika; i++) {
						if (izborRadnika - 1 == pronadjeniRadnici[i]) {
							system("cls");
							ispravanIzborRadnika = true;
							ispis(&lRadnika[izborRadnika]);
						}
					}
					if (!ispravanIzborRadnika) {
						cout << "Greska!Unijeti izbor nije validan." << endl;
					}
				} while (!ispravanIzborRadnika);
				cout << "Da li zelite urediti podatke o radniku? 1-DA/0-NE: ";
				cin >> izborZaEdit;
				cin.ignore();
				cin.clear();
				if (izborZaEdit == 1) {
					editRadnika(&lRadnika[redniBrojRadnika]);
				}
			}
			break;
		default:
			if (!ispravanIzborPretrage) {
				cout << "Greska!Unijeti izbor nije validan.1" << endl;
				Sleep(200);
			}
			break;
		}
	} while (!ispravanIzborPretrage);

}

void printanjeRadnika(Radnik& R) {
	cout << "Ime radnika: " << R.ime << endl;
	cout << "Prezime radnika: " << R.prezime << endl;
	cout << "Datum rodjenja: " << R.datumRodjenja << endl;
	cout << "Adresa stanovanja: " << R.adresaStanovanja << endl;
	cout << "Broj telefona: " << R.brojTelefona << endl;
	cout << "Email adresa: " << R.emailAdresa << endl;
	cout << "Plata: " << R.mjestoZaposlenja.plata << endl;
}

int menu(int brojRadnika, int maxBrojRadnika) {
	int izbor;
	do {
		cout << "TRENUTNI BROJ UNESENIH RADNIKA: " << brojRadnika << "/" << maxBrojRadnika << endl;
		cout.width(25);
		cout << "\t\t - MAIN MENU - \n\n";
		cout << "\t1. Unos radnika\n\t2. Pretraga i edit radnika\n\t3. Printanje svih radnika \n\t4. Brisanje radnika\n \t5. Rekurzivno pronadji min platu\n\t6. Sacuvaj i izadji\n";
		cout << "------------>Unesite izbor: ";			/*Sortiranje po : Alfabetu -> Visini place -> Godina zaposlenja*/
		cin >> izbor;
		cin.clear();
		cin.ignore();
		return izbor;
	} while (1);
}

float pronadjiMinPlatu(Radnik R[], int kapacitetBaze) {
	if (kapacitetBaze == 1) {
		return R[0].mjestoZaposlenja.plata;
	}
	return min((R[kapacitetBaze - 1].mjestoZaposlenja.plata), pronadjiMinPlatu(R, kapacitetBaze - 1));
}

//<------KRAJ REGULARNIH FUNKCIJA


int main() {
	SetConsoleTitleA("VEX SISTEM ZA EVIDENCIJU RADNIKA");
	int izbor, maxRadnika = 1000, trenutnoRadnika = 0, brojac = 0;
	Radnik* listaRadnika = new Radnik[maxRadnika];
	Radnik* tempRadnika = new Radnik[maxRadnika];
	system("COLOR 06");
	string poruka = "Dobro dosli u VEX sistem za evidenciju radnika.\n";
	ucitajMenu();
	system("cls");
	dekoracijaMainMenu(poruka, 30);
	//VRIJEME
	time_t tt;
	struct tm* ti;
	time(&tt);
	ti = localtime(&tt);
	cout << "Program pokrenut zadnji put: " << asctime(ti);
	//KRAJ VRIJEME
	do {
		izbor = menu(trenutnoRadnika, maxRadnika);
		if (izbor == 1) {
			system("cls");
			unosRadnika(listaRadnika[trenutnoRadnika]);
			++trenutnoRadnika;
		}
		if (izbor == 2) {
			system("cls");
			pretragaRadnika(listaRadnika, trenutnoRadnika);
		}
		if (izbor == 3) {
			system("cls");
			for (int i = 0; i < trenutnoRadnika; i++) {
				cout << "Radnik broj: " << i << endl;
				printanjeRadnika(listaRadnika[i]);
				cout << "\n\n";
			}
		}
		if (izbor == 4) {
			system("cls");
			int jedinstveniKod, provjera;
			cout << "Unesite ID radnika: ";
			cin >> jedinstveniKod;
			for (int i = 0; i < trenutnoRadnika; i++) {
				if (listaRadnika->uID == jedinstveniKod) {
					provjera = i;
				}
			}
			for (int i = 0; i < trenutnoRadnika; i++) {
				if (i == provjera) {
					continue;
				}
				else {
					if (i > provjera) {
						tempRadnika[i - 1] = listaRadnika[i];
					}
					else {
						tempRadnika[i] = listaRadnika[i];
					}
				}
			}
			trenutnoRadnika--;
			cout << "Podaci radnika koji ce biti obrisan:\n";
			ispis(listaRadnika);
		}
		if (izbor == 5) {
			//poziv rek fuk
		}
		if (izbor == 6) {
			ofstream podaci(("radnici.txt"), ios::app);
			if (podaci.is_open()) {
				podaci << "ID: " << listaRadnika->uID << endl;
				podaci << "Ime: " << listaRadnika->ime << endl;
				podaci << "Prezime: " << listaRadnika->prezime << endl;
				podaci << "Datum rodjenja: " << listaRadnika->datumRodjenja << endl;
				podaci << "Adresa radnika: " << listaRadnika->adresaStanovanja << endl;
				podaci << "Broj telefona: " << listaRadnika->brojTelefona << endl;
				podaci << "Email: " << listaRadnika->emailAdresa << endl;
				podaci << "Firma zaposlenja: " << listaRadnika->mjestoZaposlenja.nazivFirme << endl;
				podaci << "Pozicija u firmi: " << listaRadnika->mjestoZaposlenja.pozicijaUFirmi << endl;
				podaci << "Adresa firme: " << listaRadnika->mjestoZaposlenja.adresaFirme << endl;
				podaci << "Godina zaposlenja: " << listaRadnika->mjestoZaposlenja.godinaZaposlenja << endl;
				podaci << "Plata: " << listaRadnika->mjestoZaposlenja.plata << " KM" << endl;
				podaci.close();
			}
			system("cls");
			delete[]listaRadnika;
			listaRadnika = nullptr;
			break;
		}
		system("pause");
		system("cls");
	} while (izbor != 6);
	return 0;
}

//FUNKCIJA DEKORACIJE
void dekoracijaMainMenu(const string& poruka, unsigned int msc) {
	for (const char c : poruka) {
		cout << c << flush;
		sleep_for(milliseconds(msc));
	}
}

void ucitajMenu() {
	system("COLOR 06");
	system("cls");

	for (int i = 1; i <= 50; i++)
	{
		system("cls");
		cout << "\n\n\n\n\t\t\t\t   Ucitavanje " << '\n' << '\t' << '\t';
		for (int j = 1; j <= i; j++)
			cout << "²";
		cout << "\n\n\t " << 2 * i << "%";
		if (i > 1 && i < 20)
			cout << "\n\n\tPravljenje privremenih fajlova";
		else if (i > 20 && i < 40)
			cout << "\n\n\tPristupanje glavnoj memoriji";
		else if (i > 40 && i < 48)
			cout << "\n\n\tPristupanje kes memoriji";
		else cout << "\n\n\Zavreseno. Pritisnite Enter za nastavak ";
		Sleep(150 - i * 3);
	}
	getch();
}

//KRAJ FUNKCIJE ZA DEKORACIJU
