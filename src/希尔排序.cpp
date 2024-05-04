#include <iostream>
void shell_Sort(int* arr, int len)
{
	int gap = len / 2;
	while (gap > 0)
	{
		for (int i = gap; i < len; i++)
		{
			int index = i;
			int temp = arr[i];
			while (index >= gap)
			{
				if (arr[index - gap] > temp)
				{
					arr[index] = arr[index - gap];
					index = index - gap;
				}
				else
				{
					break;
				}
			}
			arr[index] = temp;
		}
		gap = gap / 2;
	}
}
int main()
{
	int arr[] = { 100,23,21,1111,67,45,333,32,21,23,10,0,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	shell_Sort(arr, len);
	for (int i = 0; i < len; i++)
	{
		std::cout << arr[i] << std::endl;
	}
	return 0;
}