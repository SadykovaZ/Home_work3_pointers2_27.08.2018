#include<iostream>
#include<time.h>
#include<iomanip>

using namespace std;
//1.	Написать функцию, которая получает указатель на массив и его размер, и возвращает сумму и произведение его элементов в двух параметрах-указателях.
void function1(int *a, int const *size, int *sum, int *mult)
{
	for (int i = 0; i < *size; i++)
	{
		*sum += a[i];
		*mult *= a[i];
	}
}
//2.	Написать функцию, которая получает указатель на массив и его размер, и возвращает количество отрицательных, положительных и нулевых элементов массива.
void function2(int *a, int const *size)
{
	int pos = 0, neg = 0, zero = 0;
	for (int i = 0; i < *size; i++)
	{
		if (a[i] > 0)
			pos++;
		if (a[i] < 0)
			neg++;
		if (a[i] == 0)
			zero++;
	}
	cout << "Положительных = " << pos << endl;
	cout << "Отрицательных = " << neg << endl;
	cout << "Нулевых = " << zero << endl;
}
//3. Написать следующие функции для работы с динамическим масси-вом:
//a.функция распределения динамической памяти
void alloc(int *&arr, int n)
{
	arr = new int[n];
}
//b.функция инициализации динамического массива
void init(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}
}
//c.функция печати динамического массива
void print(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
//d.функцию удаления динамического массива
void erase(int *&arr)
{
	delete[] arr;
}
//e. функцию добавления элемента в конец массива
void insert_end(int *&arr, int &n, int value)
{
	int *tmp = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		tmp[i] = arr[i];
	}
	tmp[n] = value;
	n += 1;
	delete[]arr;
	arr = tmp;

}
//f. функцию вставки элемента по указанному индексу
void addNumber(int *&arr, int &n, int index, int number)
{
	int *tmp1 = new int[++n];
	for (int i = 0; i < index; ++i)
		tmp1[i] = arr[i];
	tmp1[index] = number;
	for (int i = index; i < n - 1; ++i)
		tmp1[i + 1] = arr[i];
	delete[]arr;
	arr = tmp1;
}
//g. функцию удаления элемента по указанному индексу
bool DelNum(int *arr, int &n, int nom)
{
	if (nom > n || nom < 1)
	{
		cout << "Ошибка удаления" << endl;
		return false;
	}

	for (int i = nom - 1; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
	return true;
}

//4.	Написать функцию, которая получает указатель на динамический массив и его размер. Функция должна удалить из массива все от-рицательные числа и вернуть указатель на новый динамический массив.
void delNeg(int *&a, int &n)
{
	int *tmp;
	int k = 0;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 0)
		{
			k++;
		}
	}
	tmp = new int[k];
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 0)
			tmp[j++] = a[i];
	}
	delete[] a;
	a = tmp;
	n = k;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int n = 0;
start:
	cout << "Введите номер задания: ";
	cin >> n;

	if (n == 1)
	{
		cout << "1.	Написать функцию, которая получает указатель на массив и его размер, и возвращает сумму и произведение его элементов в двух параметрах-указателях." << endl;
		const int size{ 5 };
		int a[size];
		int s = 0, m = 1;

		for (int i = 0; i < size; i++)
		{
			a[i] = 1 + rand() % 5;
			cout << setw(4) << *(a + i);
		}
		cout << endl;

		function1(a, &size, &s, &m);
		cout << "Сумма = " << s << endl;
		cout << "Произведение = " << m << endl;
	}
	else if (n == 2)
	{
		cout << "2.	Написать функцию, которая получает указатель на массив и его размер, и возвращает количество отрицательных, положительных и нулевых элементов массива." << endl;
		int const size{ 9 };
		int a[size] = { -5,-8,-9,0,-1,2,0,5,0 };
		for (int i = 0; i < size; i++)
		{
			cout << setw(3) << a[i];
		}
		cout << endl;
		function2(a, &size);

	}
	else if (n == 3)
	{
		cout << "3.Написать следующие функции для работы с динамическим масси-вом:" << endl;
		cout << "a.функция распределения динамической памяти " << endl;
		cout << "b.функция инициализации динамического массива " << endl;
		cout << "c.функция печати динамического массива " << endl;
		cout << "d.функцию удаления динамического массива " << endl;
		cout << "e.функцию добавления элемента в конец массива " << endl;
		cout << "f.функцию вставки элемента по указанному индексу " << endl;
		cout << "g.функцию удаления элемента по указанному индексу " << endl;
		cout << "---------------------------------------------------------------------------" << endl;
		
		int *a;
		int n = 5;
		alloc(a, n);
		init(a, n);
		print(a, n);
		insert_end(a, n, 10); 
		cout << "e.функцию добавления элемента в конец массива " << endl;
		print(a, n);
		addNumber(a, n, 3, 89);
		cout << "f.функцию вставки элемента по указанному индексу " << endl;
		print(a, n);
		DelNum(a, n, 2);
		cout << "g.функцию удаления элемента по указанному индексу " << endl;
		print(a, n);
		erase(a);				
	}


	else if (n == 4)
	{
		cout << "4.	Написать функцию, которая получает указатель на динамический массив и его размер. Функция должна удалить из массива все от-рицательные числа и вернуть указатель на новый динамический массив." << endl;
		int *a;
		int n;
		cout << "Введите размер массива:";
		cin >> n;
		a = new int[n];
		for (int i = 0; i < n; i++)
		{
			a[i] = rand() % 10 - 5;
			cout << setw(3) << a[i];
		}
		cout << endl;
		delNeg(a, n);
		for (int i = 0; i < n; i++)
		{
			cout << setw(3) << a[i];
		}
		cout << endl;
		delete[] a;

	}
	else if (n == 5)
	{
		cout << "5.	Даны два массива: А[M] и B[N] (M и  N вводятся с клавиатуры). Необходимо создать третий массив минимально возможного разме-ра, в котором нужно собрать элементы обоих массивов. " << endl;

		int *a;
		int *b;
		int *c;

		int m, n;

		cout << "Введи M = ";
		cin >> m;
		cout << "Введите N = ";
		cin >> n;

		int k = m + n;

		a = new int[m];
		b = new int[n];
		c = new int[k];

		for (int i = 0; i < m; i++)
		{
			a[i] = 1 + rand() % 20;
			c[i] = a[i];
			cout << setw(3) << a[i];
		}
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			b[i] = 1 + rand() % 20;
			c[i + m] = b[i];
			cout << setw(3) << b[i];
		}
		cout << endl;
		for (int i = 0; i < k; i++)
		{
			cout << setw(3) << c[i];
		}
		cout << endl;

		delete[] a;
		delete[] b;
		delete[] c;

	}

	goto start;
	system("pause");
	return 0;
}