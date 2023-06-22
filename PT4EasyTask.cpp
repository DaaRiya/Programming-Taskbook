#include <string>
#include <fstream>
#include <algorithm>
#include "pt4taskmaker.h"

void EasyTask1()
{
	CreateTask("Ввод и вывод данных, оператор присваивания");
	TaskText("Дано двузначное целое число число n (10<=n<=99).", 0, 2);
	TaskText("Найти сумму его цифр.", 0, 4);
	int n = RandomN(1, 99);
	DataN("n = ", n, 0, 3, 4);
	ResultN("Sum = ", n % 10 + n / 10, 0, 2, 4);
	SetTestCount(3);
}

void EasyTask2()
{
	CreateTask("Двумерные массивы: вывод элементов");
	TaskText("Дан массив длинны M ", 0, 2);
	TaskText("Вывести элементы массива, удвоив каждый элемент.", 0, 4);
	int m = RandomN(3, 10);
	DataN("m = ", m, 0, 1, 2);
	int a[10];
	for (int i = 0; i < m; i++)
	{
		a[i] = RandomN(-10, 10);
		DataN(a[i], Center(i + 1, 7, 5, 1), 3, 5);
	}
	for (int i = 0; i < m; i++)
	{
		ResultN(a[i] * 2, Center(i + 1, 7, 5, 1), 3, 5);
	}
	SetTestCount(5);
}

void EasyTask3()
{
	CreateTask("Ввод и вывод данных, оператор присваивания");
	TaskText("Учитывая целое число n, верните наибольшее число, содержащее ровно n цифры.", 0, 2);
	int n = RandomN(1, 10);
	DataN("n = ", n, 0, 3, 4);
	ResultN("Res = ", pow(10, n) - 1, 0, 2, 4);
	SetTestCount(3);
}

void EasyTask4()
{
	CreateTask("Ввод и вывод данных, оператор присваивания");
	TaskText("У N детей есть M кусочков конфет. Они хотят съесть как можно больше конфет, \n"
		"но каждый ребенок должен съесть точно такое же количество конфет, \n"
		" как и любой другой ребенок. \n"
		"Определите, сколько конфет будет съедено всеми детьми вместе. \n "
		"Отдельные кусочки конфеты нельзя разделить.\n");

	int n = RandomN(1, 10);
	DataN("n = ", n, 0, 2, 4);
	int m = RandomN(2, 100);
	DataN("m = ", m, 0, 3, 4);
	ResultN("Res = ", m - (m % n), 0, 2, 4);
	SetTestCount(3);
}
void EasyTask5()
{
	CreateTask("Работа с массивами");
	TaskText("Дан массив целых чисел, найдите пару смежных элементов, которая имеет \n наибольшее произведение,"
		"наибольшее произведение,и верните это произведение.");
	int n = RandomN(2, 10);
	int array[10];
	for (int i = 0; i < n; i++)
	{
		array[i] = RandomN(-1000, 1000);
		DataN(array[i], Center(i + 1, n, 5, 1), 2, 5);
	}
	int ma = MININT;
	for (int i = 1; i < n; i++)
	{
		ma = max(ma, array[i] * array[i - 1]);
	}
	ResultN("Res = ", ma, 0, 2, 4);
	SetTestCount(3);
}
const string c = "0123456789abcdefghijklmnopqrstuvwxyz";
const string elems = "abcdefghijklmnopqrstuvwxyz";

string RandomS(int Len)
{
	string result = "";
	int L = elems.length();
	for (int i = 0; i < Len; i++)
		result = result + elems[RandomN(0, L - 1)];
	return result;
}

void EasyTask6()
{
	CreateTask("Работа со строками");
	TaskText("Дана строка S. Проверьте, является ли она полиндромом.");
	int n = RandomN(1, 10);
	DataN("N=", n, 1, 1, 3);
	switch (CurrentTest())
	{
	case 2:
		n = 1;
		break;
	}
	string s = RandomS(n);
	string s1 = s;
	reverse(s.begin(), s.end());
	ResultB(s1 == s, 0, 2);
	DataS(s.c_str(), 0, 0);
	SetTestCount(5);
}
void EasyTask7()
{
	CreateTask("Работа со строками");
	TaskText("Дан массив строк длины N, верните другой массив,\n"
		" содержащий все его самые длинные строки");
	int n = RandomN(1, 10);
	DataN("N=", n, 1, 1, 3);
	string a[10];
	for (int i = 0; i < n; i++)
	{
		int len = RandomN(1, 5);
		a[i] = RandomS(len);
		DataS(a[i].c_str(), Center(i + 1, n, 5, 1), 1);
		DataN(a[i].size(), Center(i + 1, n, 5, 1), 5, 5);
	}
	int b = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].size() > b)
			b = a[i].size();
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i].size() == b)
			ResultS(a[i].c_str(), Center(i + 1, n, 5, 5), 3);
	}
	SetTestCount(5);
}

void EasyTask8()
{
	CreateTask("Работа со строками");
	TaskText("Даны две строки длины N1 и N2, \n"
		"найдите количество общих символов между ними.");
	int n1 = RandomN(1, 10);
	int n2 = RandomN(1, 10);
	DataN("N1=", n1, 1, 1, 3);
	DataN("N2=", n2, 1, 2, 3);
	string s1, s2;
	s1 = RandomS(n1);
	s2 = RandomS(n2);
	DataS(s1.c_str(), 10, 1);
	DataS(s2.c_str(), 10, 2);
	int r = 0;
	for (int i = 0; i < n1; i++) {
		int p = s2.find(s1[i]);
		if (p != -1) {
			s2.erase(p, 1);
			r++;
		}
	}
	ResultN("Res=", r, 1, 1, 5);
	SetTestCount(5);
}
int Count_digits(int n)
{
	int len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return len;
}
void EasyTask9()
{
	CreateTask("Счастливые билеты");
	TaskText("Номера билетов обычно состоят из четного числа цифр.\n"
		"Номер билета считается счастливым если сумма \n"
		"первой половины цифр равна сумме второй половины. \n"
		"Дан номер билета n, определите, является ли он счастливым или нет.");
	int n = RandomN(10,10000000);
	while (Count_digits(n) % 2 != 0)
	{
		n = RandomN(10,10000000);
	}
	DataN("N=", n, 1, 1, 5);
	int sum1 = 0, sum2 = 0;
	switch (CurrentTest())
	{
	case 2:
		n = 134008;
		break;
	}
	int digits = Count_digits(n);
	for (int x = 0; n > 0; n /= 10, x++) {
		if (x < digits / 2)
			sum1 += n % 10;
		else
			sum2 += n % 10;
	}
	ResultB(sum1 == sum2, 1, 1);
	SetTestCount(5);
}

void EasyTask10()
{
	CreateTask("Счастливые билеты");
	TaskText("Несколько человек стоят в ряд, и их нужно разделить на две команды.\n"
		     "Первый участник - в команду 1, второй - в команду 2, третий - в команду 1,\n"
		     "четвертый - в команду 2 и так далее. Дан массив весов людей,\n"
		     "вернуть массив из 2х чисел, где 1е число – общий вес 1й команды,\n"
		     "2е – общий вес 2ой команды.");
	int n = RandomN(1, 10);
	DataN("N=", n, 1, 1, 5);
	switch (CurrentTest())
	{
	case 2:
		n = 1;
		break;
	}
	int arr[10], res[2] = { 0,0 };
	for (int i = 0; i < n; i++) {
		arr[i] = RandomN(40, 120);
		DataN(arr[i], Center(i+1, n, 5, 2), 2, 5);
	}	
	for (int i = 0; i < n; i++)
	{
		res[i % 2] += arr[i];
	}
	ResultN("1st= ", res[0], 1, 1, 2);
	ResultN("2nd= ",res[1], 10, 1, 2);
	SetTestCount(5);
}


void _stdcall InitTask(int num)
{
	switch (num)
	{
	case 1:
		EasyTask1(); break;
	case 2:
		EasyTask2(); break;
	case 3:
		EasyTask3(); break;
	case 4:
		EasyTask4();
		break;
	case 5:
		EasyTask5();
		break;
	case 6:
		EasyTask6(); break;
	case 7:
		EasyTask7();
		break;
	case 8:
		EasyTask8();
		break;

	case 9:
		EasyTask9(); break;
	case 10:
		EasyTask10(); break;
	}
}

void _stdcall inittaskgroup()
{
	int n = 10;
	CreateGroup("EasyTask", "Группа задач легкого уровня",
		"М. Э. Абрамян, Д. Р. Ключникова, 2023", "qwqfwer13dfttd", n, InitTask);

}
