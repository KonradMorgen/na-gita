#include <iostream>
#include <string>

using namespace std;

struct dane
{
	string nazwa;
	int nr_konta, pin;
	int stan_konta = 0;
};

class bank
{
public:

	bank(dane &d);
	void poka(dane &d);
	void nowe(dane &d);
	void stan_konta(dane &d);
	void WPLlac_srodki(dane &d);
	void WYplac_srodki(dane &d);
	void wydawanie_liczb( int x);
};

class logowanie
{
	string nazwa;
	int nr_konta, pin;

public:
	void log(dane &d);
};

class menu
{
public:
	menu(dane &d);
};

void wybor(dane &d);
