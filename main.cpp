#include<iostream>
#include<Windows.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

int** allocate(const int rows, const int cols);
void clear(int** arr, const int rows, const int cols);
int** push_row_back(int** arr, int& rows, const int cols);
void FillRand(int** arr, const int rows, const int cols, int minRand = 50, int maxRand = 100)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
		arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
	}
	/*for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}*/
}
void FillRand(int* arr, const unsigned int n, int minRand = 50, int maxRand=100)
{
	for (int i = 0; i < n; i++)
	{
		/*arr[i] = rand() % (maxRand - minRand) + minRand;*/
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
	}
}

void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++) 
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int** arr, const int n, const int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* insert(int arr[], int& n, int value,int index);


int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int index);

void Razdelenie()
{
	int n = 10;
	int* arr = new int[n] {0};
	FillRand(arr, n);
	cout << "������ �� ������ ���������: " << endl;
	Print(arr, n);
	int a=0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			a++;
		}
	}
	int b = n - a;
	int* even = new int [a] {0}/*������*/, * odd = new int[a] {0}/*�� ������*/;
	
	for (int i=0,ia=0,ib = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			even[ia] = arr[i];
			ia++;
		}
		else
		{
			odd[ib] = arr[i];
			ib++;
		}
			
	}
	cout << "������ c ������� ������� [������: " << a << " ]" << endl;
	Print(even,a);
	cout << "������ c �� ������� ������� [������: " << b << " ]" << endl;
	Print(odd, b);
}

void main()
{
	setlocale(LC_ALL, "");
	Razdelenie();
	
	int n=10; //������ �������



	cout << "������� ������ �������: "; cin >> n;
	int* ar = new int[n] {};	
	
	FillRand(ar,n);
	Print(ar, n);	

	int value; //���������� ��������
	cout << "������� �������� ����������� � �����: "; cin >> value;
	ar = push_back(ar, n, value);
	Print(ar, n);
	
	cout << "������� �������� ����������� � ������: "; cin >> value;
	ar = push_front(ar, n, value);
	Print(ar, n);	

	int index = 0;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	if (index<0 || index>n) 
	{ cout << "������ ������� �� ������� �������" << endl; }
	else
	{
		cout << "������� ����������� ��������: "; cin >> value;
		ar = insert(ar, n, value, index);
		Print(ar, n);
	}
	cout << "�������� ���������� �������� �������: " << endl;
	ar = pop_back(ar, n);
	Print(ar, n);

	cout << "������� ������ ���������� ��������: "; cin >> index;
	if (index<0 || index>n-1) cout << "������ ������� �� ������� �������" << endl;
	else 
	{
		ar = erase(ar, n, index);
		Print(ar, n);
	}
	cout << "�������� �������� ������� �������: " << endl;
	ar = pop_front(ar, n);
	Print(ar, n);


}


int** allocate(const int rows, const int cols)
{
	int** arr = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int [cols] {0};
	}
	return arr;
}
void clear(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1]{};
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[] arr;
	buffer[rows] = new int [cols] {};
	rows++;
	return buffer;
}

int* push_back(int arr[], int& n, int value)
{
	//1. �������� ��������� ������� ������� �������
	int* buffer = new int[n + 1]{0};
	//2. �������� ���������� ��������� ������� � �����(��������) ������
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[n] = value;
	//3. ����� ���� ��� ������ ������������, �������� ������ ����� ������� 
	delete[] arr;
	//4. ��������� ����� ������� ������� ������� ������ �������
	//5. ����� ����� � ������� 'ar' ���������� ��� ���� �������,
	//� ������� ����� ��������� ����������� ��������
	//6. ����� ���� ��� � ������� �������� ��� ���� �������, 
	//���������� ��� ��������� ����������� �� 1
	n++;
	return buffer;
}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;

}
int* insert(int arr[], int& n, int value, int index)
{	
	int* buffer = new int[n + 1]{};
	for (int i = 0, j=0; i < n+1; i++)
	{
		
		if (i!=index)
		{ 
			buffer[i] = arr[j];
			j++;
		}
		else
		buffer[i] = value;
	}
	delete[] arr;
	
	n++;
	return buffer;
} //����� ������������ ��� ���������� � ������ � � �����

int* pop_back(int arr[], int& n)
{
	n = n - 1;
	int* buffer = new int[n]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	return buffer;
}
int* pop_front(int arr[], int& n)
{
	return erase(arr, n, 0);
}
int* erase(int arr[], int& n, int index)
{
	int* buffer = new int[n - 1]{};
	for (int i = 0, j = 0; i < n; i++)
	{

		if (i != index)
		{
			buffer[j] = arr[i];
			j++;
		}
		
	}
	delete[] arr;

	n--;
	return buffer;
}