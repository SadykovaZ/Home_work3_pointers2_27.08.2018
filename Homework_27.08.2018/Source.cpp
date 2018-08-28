#include<iostream>
#include<time.h>
#include<iomanip>

using namespace std;
//1.	�������� �������, ������� �������� ��������� �� ������ � ��� ������, � ���������� ����� � ������������ ��� ��������� � ���� ����������-����������.
void function1(int *a, int const *size, int *sum, int *mult)
{
	for (int i = 0; i < *size; i++)
	{
		*sum += a[i];
		*mult *= a[i];
	}
}
//2.	�������� �������, ������� �������� ��������� �� ������ � ��� ������, � ���������� ���������� �������������, ������������� � ������� ��������� �������.
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
	cout << "������������� = " << pos << endl;
	cout << "������������� = " << neg << endl;
	cout << "������� = " << zero << endl;
}
//3. �������� ��������� ������� ��� ������ � ������������ �����-���:
//a.������� ������������� ������������ ������
//b.������� ������������� ������������� �������
//c.������� ������ ������������� �������
//d.������� �������� ������������� �������

void aFunc(int *aNew)
{
	int size;
	cout << "������� ����� ������ �������:"; //a.������� ������������� ������������ ������
	cin >> size;
	aNew = new int[size]; //b. ������� ������������� ������������� �������
	for (int i = 0; i < size; i++)
	{
		cout << "aNew [" << i << "] = ";
		cin >> aNew[i];
	}
	for (int i = 0; i < size; i++)
	{
		cout << setw(3) << aNew[i]; //c.������� ������ ������������� �������
	}
	cout << endl;
	delete[] aNew; //d.������� �������� ������������� �������
}
//e. ������� ���������� �������� � ����� �������
void addElement(int *a, int number)
{

}
//f. ������� ������� �������� �� ���������� �������
void addNumber(int *&array, int &currentSize, int index, int number)
{
	int *newArray = new int[++currentSize]; 
	for (int i = 0; i < index; ++i) 
		newArray[i] = array[i];
	newArray[index] = number;
	for (int i = index; i < currentSize - 1; ++i) 
		newArray[i + 1] = array[i];
	delete[]array; 
	array = newArray;
}
//g. ������� �������� �������� �� ���������� �������
bool iDel(int *array, int &lenAr, int nom)
{
	if (nom > lenAr || nom < 1)
	{
		cout << "������ ��������" << endl;
		return false;
	}

	for (int i = nom - 1; i < lenAr - 1; i++)
	{
		array[i] = array[i + 1];
	}
	lenAr--;
	return true;
}


//4.	�������� �������, ������� �������� ��������� �� ������������ ������ � ��� ������. ������� ������ ������� �� ������� ��� ��-����������� ����� � ������� ��������� �� ����� ������������ ������.
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
	cout << "������� ����� �������: ";
	cin >> n;

	if (n == 1)
	{
		cout << "1.	�������� �������, ������� �������� ��������� �� ������ � ��� ������, � ���������� ����� � ������������ ��� ��������� � ���� ����������-����������." << endl;
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
		cout << "����� = " << s << endl;
		cout << "������������ = " << m << endl;

	}

	else if (n == 2)
	{
		cout << "2.	�������� �������, ������� �������� ��������� �� ������ � ��� ������, � ���������� ���������� �������������, ������������� � ������� ��������� �������." << endl;
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
		cout << "3.�������� ��������� ������� ��� ������ � ������������ �����-���:" << endl;
		cout << "a.������� ������������� ������������ ������ " << endl;
		cout << "b.������� ������������� ������������� ������� " << endl;
		cout << "c.������� ������ ������������� ������� " << endl;
		cout << "d.������� �������� ������������� ������� " << endl;
		cout << "e.������� ���������� �������� � ����� ������� " << endl;
		cout << "f.������� ������� �������� �� ���������� ������� " << endl;
		cout << "g.������� �������� �������� �� ���������� ������� " << endl;
		cout << "---------------------------------------------------------------------------" << endl;
		char f = 0;
		cout << "�������� �����:";
		cin >> f;
		cout << endl;
		switch (f)
		{
		case 'a':
		{
			cout << "a.������� ������������� ������������ ������ " << endl;

		}
			break;
		case 'b': 
		{
			cout << "b.������� ������������� ������������� ������� " << endl;
		}
			break;
		case 'c': {
			cout << "c.������� ������ ������������� ������� " << endl;
		}
			break;
		case 'd': 
		{
			cout << "d.������� �������� ������������� ������� " << endl;
			int b[5];

			for (int i = 0; i < 5; i++)
			{
				b[i] = 1 + rand() % 10;
				cout << setw(3) << b[i];
			}
			cout << endl;
			aFunc(b);
		}
			break;
		case 'e':
		{
			cout << "e.������� ���������� �������� � ����� ������� " << endl;
			
		}
			break;
		case 'f': 
		{
			cout << "f.������� ������� �������� �� ���������� ������� " << endl;
			int *a = new int[5], k = 5;
			for (int i = 0; i < k; i++) a[i] = i;
			for (int i = 0; i < k; ++i) cout << a[i] << " ";
			cout << endl;
			addNumber(a, k, 3, 899);
			for (int i = 0; i < k; ++i) cout << a[i] << " ";
			cout << endl;
			addNumber(a, k, 4, 1000);
			for (int i = 0; i < k; ++i) cout << a[i] << " ";
			cout << endl;
			delete[]a;
		}
			break;
		case 'g':
		{
			cout << "g.������� �������� �������� �� ���������� ������� " << endl;
			int length_array;
			cout << "������� ���������� ��������� �������: ";
			cin >> length_array;

			int *arrayPtr = new int[length_array]; 

												  
			for (int counter = 0; counter < length_array; counter++)
			{
				arrayPtr[counter] = rand() % 100; 
				cout << arrayPtr[counter] << "  "; 
			}
			cout << endl;

			int n;
			cout << "������� ����� �������� �������, ������� ���������� �������: ";
			cin >> n;

			iDel(arrayPtr, length_array, n);

			for (int counter = 0; counter < length_array; counter++)
			{
				cout << arrayPtr[counter] << "  "; 
			}

			cout << endl;

			delete[] arrayPtr;
		}
			break;		
		}
	}

	else if (n == 4)
	{
		cout << "4.	�������� �������, ������� �������� ��������� �� ������������ ������ � ��� ������. ������� ������ ������� �� ������� ��� ��-����������� ����� � ������� ��������� �� ����� ������������ ������." << endl;
		int *a;
		int n;
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

	}
	else if (n == 5)
	{
		cout << "5.	���� ��� �������: �[M] � B[N] (M �  N �������� � ����������). ���������� ������� ������ ������ ���������� ���������� �����-��, � ������� ����� ������� �������� ����� ��������. " << endl;

		int *a;
		int *b;
		int *c;

		int m, n;

		cout << "����� M = ";
		cin >> m;
		cout << "������� N = ";
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