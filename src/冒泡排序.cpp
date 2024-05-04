#include <iostream>
void print_Arr(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		std::cout << "arr[" << i + 1 << "]=" << arr[i] <<std::endl;
	}
}
void Bubble_Sort(int* arr, int len,void(*func_point)(int *,int))
{
	for (int i = 0; i < len - 1; i++)
	{
		bool flag = false;
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = true;
			}
		}
		if (!flag)
		{
			break;
		}
	}
	func_point(arr, len);
}
int main()
{
	int arr[10] = { 100,1,10,0,56,43,21,23,4,3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Bubble_Sort(arr, len,print_Arr);
	return 0;
}