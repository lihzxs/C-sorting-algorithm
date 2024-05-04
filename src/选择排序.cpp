#include <iostream>
void print_Arr(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		std::cout << "arr[" << i + 1 << "]=" << arr[i] << std::endl;
	}
}
void Selection_Sort(int* arr, int len,void(*func_point)(int *,int))
{
	for (int i = 0; i < len; i++)
	{
		int index = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[index])
			{
				index = j;
			}
		}
		int temp = arr[index];
		arr[index] = arr[i];
		arr[i] = temp;
		
	}
	func_point(arr, len);
}
int main()
{
	int arr[10] = { 100,1,10,0,56,43,21,23,4,3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Selection_Sort(arr, len, print_Arr);
}