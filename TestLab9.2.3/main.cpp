#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці
using namespace std;
enum Posada { ROBITNYK, INZHENER, SLUZHBOVETS, FIS, TRYD };
string posadaStr[] = { "Комп’ютерні науки", "Інформатика", "Математика та економіка","Фізика та інформатика","Трудове навчання" };
struct Pracivnyk
{
	string prizv;
	unsigned rik_nar;
	Posada posada;
	union
	{
		double taryf;
		int stavka;
		int program;
		int program2;
		int pedagog;
	};
};
void Create(Pracivnyk* p, const int N);
void Print(Pracivnyk* p, const int N);
int BinSearch(Pracivnyk* p, const int N, const string prizv, const Posada posada, const int taryf, const int rik_nar);
int main()
{ // забезпечення відображення кирилиці:
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	int N;
	cout << "Введіть N: "; cin >> N;

	Pracivnyk* p = new Pracivnyk[N];
	int iposada;
	Posada posada;
	string prizv;
	double taryf;
	int rik_nar;
	int found;
	Create(p, N);
	Print(p, N);
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - сортувати масив за прізвищем" << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			cout << "Введіть ключі пошуку:" << endl;
			cout << "Спеціальність (0 - Комп’ютерні науки, 1 -Інформатика , 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
			cin >> iposada;
			posada = (Posada)iposada;
			cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
			cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

			cout << " Прізвище: "; getline(cin, prizv);
			cout << " Оцінка з фізики: "; cin >> taryf;
			cout << " Курс "; cin >> rik_nar;
			cout << endl;
			if ((found = BinSearch(p, N, prizv, posada, taryf, rik_nar)) != -1)
				cout << "Знайдено студента в позиції " << found + 1 << endl;
			else
				cout << "Шуканого працівника не знайдено" << endl;
			break;
		}
	} while (menuItem != 0);
	return 0;

}
void Create(Pracivnyk* p, const int N)
{
	int posada;
	for (int i = 0; i < N; i++)
	{
		cout << "Працівник № " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " Курс.: "; cin >> p[i].rik_nar;
		cout << " Спеціальність (0 - Комп’ютерні науки, 1 -Інформатика , 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
		cin >> posada;
		p[i].posada = (Posada)posada;
		switch (p[i].posada)
		{
		case ROBITNYK:
			cout << " Фізика : "; cin >> p[i].taryf;
			cout << " Матиматика : "; cin >> p[i].stavka;
			cout << " Програмування : "; cin >> p[i].program;
			break;
		case INZHENER:
			cout << " Фізика : "; cin >> p[i].taryf;
			cout << " Матиматика : "; cin >> p[i].stavka;
			cout << " чисельних методів : "; cin >> p[i].program2;
			break;
		case SLUZHBOVETS:
		case FIS:
		case TRYD:
			cout << " Фізика : "; cin >> p[i].taryf;
			cout << " Матиматика : "; cin >> p[i].stavka;
			cout << " педагогіки : "; cin >> p[i].pedagog;
			break;
		}
		cout << endl;
	}
}
void Print(Pracivnyk* p, const int N)
{
	cout << "=============================================================================================================="
		<< endl;
	cout << "| № | Прізвище | Курс | Спеціальність | Фізика | Матиматика | програмування | чисельних методів | педагогіки |"
		<< endl;
	cout << "--------------------------------------------------------------------------------------------------------------"
		<< endl;
	int h = 0, m = 0, a = 0, g = 0;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << p[i].prizv
			<< "| " << setw(4) << right << p[i].rik_nar << " "
			<< "| " << setw(11) << left << posadaStr[p[i].posada];
		switch (p[i].posada)
		{
		case ROBITNYK:
			cout << "| " << setw(9) << setprecision(2) << fixed << right
				<< p[i].taryf << " |" << setw(4) << right << " " << setw(4) << right
				<< p[i].stavka << " |" << setw(4) << " " << setw(6)
				<< p[i].program << " |" << endl;
			break;
		case INZHENER:
			cout << "| " << setw(9) << setprecision(2) << fixed << right
				<< p[i].taryf << " |" << setw(4) << right << " " << setw(4) << right
				<< p[i].stavka << " |" << setw(4) << " " << setw(6)
				<< p[i].program2 << " |" << endl;
			break;
		case SLUZHBOVETS:
		case FIS:
		case TRYD:
			cout << "| " << setw(9) << setprecision(2) << fixed << right
				<< p[i].taryf << " |" << setw(4) << right << " " << setw(4) << right
				<< p[i].stavka << " |" << setw(4) << " " << setw(6)
				<< p[i].pedagog << " |" << endl;
			break;
		}
		h = 0;
		if (p[i].taryf >= 3) {
			++h;
		}
		m += h;
		cout << "кількість оцінок з фізики >= 3 = " << m << endl;
		a = 0;
		if (p[i].taryf >= 4 && p[i].stavka >= 4) {
			++g;
		}
		a += g;
		cout << "кількість оцінок з фізики і матиматики >= 4 = " << a << endl;
	}
	cout << "============================================================================================================="
		<< endl;
	cout << endl;
}
int BinSearch(Pracivnyk* p, const int N, const string prizv, const Posada posada, const int taryf, const int rik_nar)
{ // повертає індекс знайденого елемента або -1, якщо шуканий елемент відсутній
	int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;
		if (p[m].prizv == prizv && p[m].posada == posada && p[m].taryf == taryf && p[m].rik_nar == rik_nar)
			return m;
		if ((p[m].posada < posada)
			||
			(p[m].posada == posada &&
				p[m].prizv < prizv && p[m].taryf < taryf && p[m].rik_nar < rik_nar))
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	return -1;
}