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
	cout << "Массив из десяти элементов: " << endl;
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
	int* even = new int [a] {0}/*четные*/, * odd = new int[a] {0}/*не четные*/;
	
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
	cout << "Массив c четными числами [размер: " << a << " ]" << endl;
	Print(even,a);
	cout << "Массив c не четными числами [размер: " << b << " ]" << endl;
	Print(odd, b);
}

void main()
{
	setlocale(LC_ALL, "");
	Razdelenie();
	
	int n=10; //Размер массива



	cout << "Введите размер массива: "; cin >> n;
	int* ar = new int[n] {};	
	
	FillRand(ar,n);
	Print(ar, n);	

	int value; //Добвляемое значение
	cout << "Введите значение добавляемое в конец: "; cin >> value;
	ar = push_back(ar, n, value);
	Print(ar, n);
	
	cout << "Введите значение добавляемое в начало: "; cin >> value;
	ar = push_front(ar, n, value);
	Print(ar, n);	

	int index = 0;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	if (index<0 || index>n) 
	{ cout << "Индекс выходит за пределы массива" << endl; }
	else
	{
		cout << "Введите добавляемое значение: "; cin >> value;
		ar = insert(ar, n, value, index);
		Print(ar, n);
	}
	cout << "Удаление последнего элемента массива: " << endl;
	ar = pop_back(ar, n);
	Print(ar, n);

	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	if (index<0 || index>n-1) cout << "Индекс выходит за пределы массива" << endl;
	else 
	{
		ar = erase(ar, n, index);
		Print(ar, n);
	}
	cout << "Удаление нулевого элемета массива: " << endl;
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
	//1. создание буферного массива нужного размера
	int* buffer = new int[n + 1]{0};
	//2. копируем содержимое исходного массива в новый(буферный) массив
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[n] = value;
	//3. после того как данные скопированны, исходный массив можно удалить 
	delete[] arr;
	//4. подменяем адрес старого массива адресом нового массива
	//5. после этого в массиве 'ar' появляется еще один элемент,
	//в который можно сохранить добавляемое значение
	//6. после того как в массиве появился еще один элемент, 
	//количество его элементов увеличилось на 1
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
} //можно использовать для добавление в начало и в конец

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