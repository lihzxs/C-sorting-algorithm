#include <iostream>
void print_Arr(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		std::cout << "arr[" << i + 1 << "]=" << arr[i] << std::endl;
	}
}
void Insertion_Sort(int* arr, int len, void(*func_point)(int*, int))
{
	for (int i = 1; i < len; i++)
	{
		int index = i;
		int temp = arr[i];
		while (index - 1 >= 0 && arr[index - 1] > temp)
		{
			arr[index] = arr[index - 1];
			index--;
		}
		arr[index] = temp;
	}
	func_point(arr, len);
}
int main()
{
	int arr[10] = { 100,1,10,0,56,43,21,23,4,3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Insertion_Sort(arr, len, print_Arr);
}