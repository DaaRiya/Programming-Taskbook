#include <string>
#include <fstream>
#include <algorithm>
#include "pt4taskmaker.h"

void MediumTask1()
{
	CreateTask("Задачи на логику");
	TaskText("Именинник получил в подарок на свой день рождения статуэтки разных размеров, \n"
		"каждая статуэтка имеет неотрицательный целочисленный размер.\n"
		"Поскольку ему нравится доводить вещи до совершенства,\n"
		"он хочет расположить их от самых маленьких к самым большим, \n"
		"чтобы каждая статуэтка была больше предыдущей ровно на 1.\n"
		"Для этого ему могут понадобиться дополнительные статуэтки. \n"
		"Помогите ему определить минимальное количество необходимых \n"
		"дополнительных статуэток.");

	int n = RandomN(2, 10);
	int array[10];
	for (int i = 0; i < n; i++)
	{
		int el = RandomN(1, 20);
		if (find(array, array + n, el) == array + n)
		{
			array[i] = el;
			DataN(array[i], Center(i + 1, n, 5, 1), 2, 5);
		}
	}
	auto x = minmax_element(array, array + n - 1);
	ResultN("Res =", *x.second - *x.first - n + 1, 1, 1, 5);
	SetTestCount(5);
}

void MediumTask2()
{
	CreateTask("Работа с массивами");
	TaskText("Дана последовательность целых чисел в виде массива длины N, \n"
		"определите, возможно ли получить строго возрастающую последовательность,\n"
		"удалив из массива не более одного элемента.");
	int n = RandomN(1, 13);
	switch (CurrentTest())
	{
	case 2:
		n = 1;
		break;
	}
	int a[13];
	DataN("N = ", n, 1, 1, 2);
	for (int i = 0; i < n; i++)
	{
		a[i] = RandomN(0, 100);
		DataN(a[i], Center(i + 1, n, 5, 1), 2, 5);
	}
	int p = -1, c = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i - 1] >= a[i]) { p = i; c++; }
	}
	if (c > 1) ResultB(false, 5, 1);
	else {
		if (c == 0)  ResultB(true, 5, 1);
		else {
			if (p == n - 1 || p == 1)  ResultB(true, 5, 1);
			else {
				if (a[p - 1] < a[p + 1])  ResultB(true, 5, 1);
				else {
					if (a[p - 2] < a[p])  ResultB(true, 5, 1);
					else {
						ResultB(false, 5, 1);
					}
				}
			}
		}
	}
	SetTestCount(5);
}

void MediumTask3()
{
	CreateTask("Работа с массивами");
	TaskText("Несколько человек стоят в ряд в парке. Между ними есть деревья,\n"
		"которые нельзя передвинуть. Ваша задача - расположить людей по их росту\n"
		"в порядке неубывания, не перемещая деревья. ");
	int n = RandomN(3, 13);
	int r = RandomN(0, 13);
	while (r > n)
	{
		r = RandomN(0, 13);
	}
	int arr[13], arr1[13];
	DataN("N = ", n, 1, 1, 2);
	for (int i = 0; i < r; i++)
	{
	a: arr1[i] = RandomN(0, n - 1);
		for (int j = 0; j < i; j++)
		{
			if (arr1[j] == arr1[i])
			{
				goto a;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = -1;
		if (find(arr1, arr1 + r, i) != arr1 + r)
		{
			arr[i] = -1;
		}
		else
		{
			arr[i] = RandomN(10, 100);
		}
		DataN(arr[i], Center(i + 1, n, 5, 1), 2, 5);
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == -1)
		{
			ResultN(arr[i], Center(i + 1, n, 5, 1), 2, 5);
			continue;
		}
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] == -1)
			{
				continue;
			}
			else
			{
				if (arr[i] > arr[j])
				{
					int tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
				}
			}
		}
		ResultN(arr[i], Center(i + 1, n, 5, 1), 2, 5);
		SetTestCount(5);
	}
}

void MediumTask4()
{
	CreateTask("Работа с массивами");
	TaskText("Два массива называются похожими, если один может быть получен\n"
		"из другого путем замены не более одной пары элементов в одном из массивов.\n"
		"Даны два массива a и b длиной N, проверьте, похожи ли они");
	int n = RandomN(1, 13);
	int arr1[13] , arr2[13] ;
	for (int i = 0; i < n; i++)
	{
		arr1[i] = RandomN(0, 100);
		arr2[i] = RandomN(0, 100);
		DataN(arr1[i], Center(i + 1, n, 5, 1), 1, 5);
		DataN(arr2[i], Center(i + 1, n, 5, 1), 2, 5);
	}
	switch (CurrentTest())
	{
	case 2:

		arr1[0] = 1 , arr1[1] = 2, arr1[2] = 3;
		arr2[0] =  2 , arr2[1] = 1, arr2[2] = 3;
		for (int i = 3; i < n; i++)
		{
			arr1[i] = NULL;
			arr2[i] = NULL;
		}
		break;
	}
	int c = 0, t = 0;
	for (int i = 0; i < 3; i++)
	{
		if (arr1[i] ^ arr2[i]) c++;
		t ^= (arr1[i] ^ arr2[i]);
	}
	ResultB(c == 0 || (c == 2 && t == 0), 1, 1);
}

const string elems = "abcdefghijklmnopqrstuvwxyz";

string RandomS(int Len)
{
	string result = "";
	int L = elems.length();
	for (int i = 0; i < Len; i++)
		result = result + elems[RandomN(0, L - 1)];
	return result;
}

void MediumTask5()
{
	CreateTask("Палиндром");
	TaskText("Дана строка, выясните, можно ли переставить ее символы,\n"
		     "чтобы сформировать палиндром");
	int n = RandomN(1, 13);
	string s= RandomS(n);
	DataS(s.c_str(), 1, 1);
	int A[256];
	for (int i = 0; i < n; i++)	
		++A[s[i]];
	int c = 0;
	for (int i = 0; i < 256; ++i)
		c += A[i] & 1;	
	ResultB(c<2, 1, 1);
}

void MediumTask6()
{
	CreateTask("Работа с матрицами");
	TaskText("Выполнить преобразование матрицы, а именно — \n"
		     "перестановку строк и столбцов. Для квадратной матрицы размером n\n"
		     "переставляйте столбцы и строки таким образом, \n"
		     "чтобы элемент матрицы с наибольшим значением, по модулю,\n"
		     "располагался в нижнем правом углу матрицы.");
	int n = RandomN(1, 6);
	int i, j, max, x = 0, y = 0;
	DataN("N=", n, 1, 1, 5);
	
	int a[6][6];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = RandomN(0, 10);
			DataN(a[i][j], Center(j + 1, n, 5, 1), i + 1, 5);
		}
	}

	max = a[0][0];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (a[i][j] >= max)
			{
				max = a[i][j];
				x = i; y = j;
			}
		}
	}

	if (x != n - 1)
	{
		int x1;
		for (int i = 0; i < n; i++)
		{
			x1 = a[n - 1][i];
			a[n - 1][i] = a[x][i];
			a[x][i] = x1;
		}		
	}
	if (y != n - 1)
	{
		int y1;
		for (int i = 0; i < n; i++)
		{
			y1 = a[i][n - 1];
			a[i][n - 1] = a[i][y];
			a[i][y] = y1;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			ResultN(a[i][j], Center(j + 1, n, 5, 1), i + 1, 5);
		}
	}
	SetTestCount(5);
}

void MediumTask7()
{
	CreateTask("Работа с массивами");
	TaskText("Дан массив целых чисел длины N. За каждый ход вам разрешается\n"
		"увеличивать ровно один его элемент на единицу. \n"
		"Найдите минимальное количество ходов, необходимое для получения \n"
		"строго возрастающей последовательности из входных данных.");
	int n = RandomN(1, 13);
	int arr[13];
	for (int i = 0; i < n; i++)
	{
		arr[i] = RandomN(0, 100);
		DataN(arr[i], Center(i + 1, n, 5, 1), 2, 5);
	}
	int ma = MININT;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ma = max(ma + 1, arr[i]);
		ans += ma - arr[i];
	}
	ResultN("Res = ", ans, 1, 1, 5);
}

void Medium8()
{
	int x = RandomN(0, 10);
	PNode res = NULL;
	int n = RandomN(2, 9);
	PNode p1 = new TNode;
	p1->Data = RandomN(0, 10);
	p1->Prev = NULL;
	if (p1->Data == x)
	{
		res = p1;
	}
	PNode p2 = p1, p;
	for (int i = 2; i <= n; i++)
	{
		p = new TNode;
		p->Data = RandomN(0, 10);
		p->Prev = p2;
		p2->Next = p;
		p2 = p;
	}
	switch (CurrentTest())
	{
	case 2:
		for (int i = 2; i <= n; i++)
		{
			p = new TNode;
			if (i == 2)
			{
				p->Data = p1->Data = x;
			}
			p->Data = RandomN(0, 10);
			p->Prev = p2;
			p2->Next = p;
			p2 = p;
		}
		break;
	case 3:
		p1->Data = x;
		for (int i = 2; i <= n; i++)
		{
			p = new TNode;
			p->Data = RandomN(0, 10);
			while (p->Data == p1->Data)
			{
				p->Data = RandomN(0, 10);
			}
			p->Prev = p2;
			p2->Next = p;
			p2 = p;
		}
		break;
	case 4:
		while (p1->Data == x)
		{
			p1->Data = RandomN(0, 10);
		}
		for (int i = 2; i <= n; i++)
		{
			p = new TNode;
			p->Data = RandomN(0, 10);
			while (p->Data == x)
			{
				p->Data = RandomN(0, 10);
			}
			p->Prev = p2;
			p2->Next = p;
			p2 = p;
		}
		break;
	case 5:
		n = 1;
		break;
	}
	p2->Next = NULL;
	p = p1;
	while (p != NULL)
	{
		if (p->Data == x)
		{
			res = p;
		}
		p = p->Next;
	}
	if (res == NULL)
	{
		res = p2;
	}
	SetPointer(1, p1);
	SetPointer(2, res);
	ResultList(1, 0, 3);
	ShowPointer(2);
	DataP(1, 0, 2);
	DataN("x=", x, 5, 1, 5);
	DataList(1, 0, 3);
	ShowPointer(1);
	SetTestCount(5);
}

void MediumTask8()
{

	CreateTask("Динамические структуры данных: двусвязный список");
	TaskText("Дан двусвязный список и число Х. Верните указатель\n"
		"на последний узел с этим элементом, либо на последний узел списка,\n"
		"если такого элемента нет.");
	Medium8();
}

void MediumTask8Obj()
{
	CreateTask("Двусвязный список");
	TaskText("Дан двусвязный список и число Х. Верните указатель\n"
		"на последний узел с этим элементом, либо на последний узел списка,\n"
		"если такого элемента нет.");
	SetObjectStyle();
	Medium8();
}
const string c = "0123456789abcdefghijklmnopqrstuvwxyz";

string FileName(int Len)
{
	string result = "";
	int L = c.length();
	for (int i = 0; i < Len; i++)
		result = result + c[RandomN(0, L - 1)];
	return result;
}
void MediumTask9()
{
	CreateTask("Работа с файлами");
	TaskText("Дан текстовый файл.", 0, 2);
	TaskText("Удалить из него все пробелы и пустые строки.", 0, 4);
	string s1 = FileName(6) + ".tst",
		s2 = "#" + FileName(6) + ".tst",
		s = TextSample(RandomN(0, TextCount() - 1));
	ofstream t2(s2.c_str()), t1(s1.c_str());
	t2 << s << endl;
	t2.close();
	char* s0 = (char*)"\r\n";
	size_t p = s.find(s0);
	char* s00 = (char*)" ";
	size_t p00 = s.find(s0);
	while (p != string::npos)
	{
		s.erase(p, 2);

		p = s.find(s0);
	}
	while (p00 != string::npos)
	{

		s.erase(p00, 1);
		p00 = s.find(s00);
	}
	t1 << s << endl;
	t1.close();
	ResultFileT(s1.c_str(), 1, 5);
	rename(s2.c_str(), s1.c_str());
	DataFileT(s2.c_str(), 2, 5);
	DataS("Имя файла: ", s1.c_str(), 0, 1);
	t2.open(s1);
	t2 << s << endl;
	t2.close();
	SetTestCount(3);
}

void MediumTask10()
{
	CreateTask("Задачи на логику");
	TaskText("Рассмотрим целые числа от 0 до n-1, записанные \n"
		"вдоль окружности таким образом, чтобы расстояние\n"
		"между любыми двумя соседними числами было равным \n"
		"(обратите внимание, что 0 и n-1 также являются соседними).\n"
		"Учитывая n и firstNumber, найдите число, которое записано в позиции,\n"
		"радиально противоположной firstNumber.");
	int n = RandomN(4,20);
	int fn = RandomN(0, n-1);
	DataN("N=", n, 1, 1, 2);
	DataN("Fn=", fn, 15, 1, 2);
	ResultN("Res = ",(fn + (n / 2)) % n,1,1,2);
	SetTestCount(5);
}

void _stdcall InitTask(int num)
{
	switch (num)
	{
	case 1:
		MediumTask1(); break;
	case 2:
		MediumTask2(); break;
	case 3:
		MediumTask3(); break;
	case 4:
		MediumTask4(); break;
	case 5:
		MediumTask5(); break;
	case 6:
		MediumTask6(); break;
	case 7:
		MediumTask7(); break;
	case 8:
		if ((CurrentLanguage() & lgWithPointers) != 0)
			MediumTask8();
		else
			MediumTask8Obj();
		break;
	case 9:
		MediumTask9(); break;
	case 10:
		MediumTask10(); break;
	}
}

void _stdcall inittaskgroup()
{
	int n = 10;

	CreateGroup("MediumTask", "Группа задач среднего уровня",
		"М. Э. Абрамян, Д. Р. Ключникова, 2023", "qwqjcu13dfttd", n, InitTask);
}
