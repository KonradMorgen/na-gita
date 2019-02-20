#include <iostream>
#include <string>
#include "a.h"

using namespace std;

bank::bank(dane &d)
{
	d.nazwa = "auto";
	d.nr_konta = 1234;
	d.pin = 6969;
	d.stan_konta = 2137;
}

void bank::wydawanie_liczb( int x)
{
	int ile, aktualnystan = 0;
	int d = 200, s = 100, p = 50, dwadz = 20, dz = 10, pie = 5, dwa = 2, j = 1;

	aktualnystan = x;
	cout <<endl<< "Wyplacono: " << endl;

		if (x / d)
		{
			ile = x / d;
			cout << "tyle banknotow 200zl: " << ile << endl;
			aktualnystan = aktualnystan - ile * d;
		}

		if (aktualnystan / s)
		{
			ile = aktualnystan / s;
			cout << "tyle banknotow 100zl: " << ile << endl;
			aktualnystan = aktualnystan - ile * s;
		}

		if (aktualnystan / p)
		{
			ile = aktualnystan / p;
			cout << "tyle banknotow 50zl: " << ile << endl;
			aktualnystan = aktualnystan - ile * p;
		}

		if (aktualnystan / dwadz)
		{
			ile = aktualnystan / dwadz;
			cout << "tyle banknotow 20zl: " << ile << endl;
			aktualnystan = aktualnystan - ile * dwadz;
		}

		if (aktualnystan / dz)
		{
			ile = aktualnystan / dz;
			cout << "tyle banknotow 10zl: " << ile << endl;
			aktualnystan = aktualnystan - ile * dz;
		}
}

void bank::nowe(dane &d)
{
	cout << "Tworzenie konta";
	cout << endl << "nazwa: ";
	cin >> d.nazwa;
	cout << "nr konta: ";
	cin >> d.nr_konta;
	cout << "pin: ";
	cin >> d.pin;
}

void bank::stan_konta(dane &d)
{
	cout << endl << "Aktualny stan konta to: " << d.stan_konta <<"zl"<< endl;
}

void bank::WPLlac_srodki(dane &d)
{
	int kwota;
	cout << "Ile chcesz wplacic? (Mozliwe nominaly:200,100,50,20,10)\nWpisz kwote: ";
	cin >> kwota;
	d.stan_konta = d.stan_konta + kwota;
	cout <<endl<< "Aktualny stan konta: " << d.stan_konta << endl;
}

void bank::WYplac_srodki(dane & d)
{
	int kwotaDoWybrania;
	cout << "Ile chcesz wyplacic?(Mozliwa kwota do wybrania: "<<d.stan_konta<<" zl)"<<endl;
	cin >> kwotaDoWybrania;

	if (kwotaDoWybrania > d.stan_konta)
		cout << "Brak wystarczajacych srodkow" << endl;

	else if (kwotaDoWybrania <= d.stan_konta)
	{
		if (kwotaDoWybrania <= d.stan_konta && kwotaDoWybrania != 200 || kwotaDoWybrania != 100 || kwotaDoWybrania != 50 || kwotaDoWybrania != 20 || kwotaDoWybrania != 10)
			wydawanie_liczb(kwotaDoWybrania);

		d.stan_konta = d.stan_konta - kwotaDoWybrania;
	}

	else cout << "Wprowadzono zla kwote" << endl;
}

void bank::poka(dane &d)
{
	cout << "Dane";
	cout << endl << "Nazwa: " << d.nazwa << endl;
	cout << "Nr konta: " << d.nr_konta << endl;
	cout << "Nr pin: " << d.pin << endl;
}

void logowanie::log(dane &d) //logowanie wlasne zmienne, inne niz w banku
{
	cout << "Logowanie";
	cout << endl << "Nazwa: ";
	cin >> nazwa;
	cout << "Nr konta: ";
	cin >> nr_konta;
	cout << "Pin: ";
	cin >> pin;

	if (nazwa == d.nazwa && nr_konta == d.nr_konta && pin == d.pin)
		cout << "Zalogowano" << endl;

	else
	{
		cout << "Nie udalo sie zalogowac" << endl;
	}
}

menu::menu(dane &d)
{
	dane a;
	cout << "    Bank\nDostepne opcje:\n\nlogowanie\ntworzenie konta\nstan konta\nwplac srodki\nwyplac srodki\ndane konta\nzakoncz\n\n";
	wybor(a);
}

void wybor(dane &d)
{
	logowanie l;
	string wybor;
	bank b(d);

	while (true)
	{
		getline(cin, wybor);

		if (wybor == "logowanie")
		{
			l.log(d);
		}

		if (wybor == "tworzenie konta")
		{
			b.nowe(d);
			cout << endl << "utworzono konto o nastepujacych danych" << endl << endl;
			b.poka(d);
			d.stan_konta = 0;
		}

		if (wybor == "dane konta")
		{
			b.poka(d);
		}

		if (wybor == "stan konta")
		{
			b.stan_konta(d);
		}

		if (wybor == "wplac srodki")
		{
			b.WPLlac_srodki(d);
		}

		if (wybor == "wyplac srodki")
		{
			b.WYplac_srodki(d);
		}

		if (wybor == "zakoncz")
			break;
	}
}
