#include <iostream>
#include <vector>
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void print(std::vector<int>vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}
}
void selection_Sort(std::vector<int>&vec)
{
	int len = vec.size();
	for (int i = 0; i < len; i++)
	{
		int index = i;
		for (int j = i + 1; j < len; j++)
		{
			if (vec[j] < vec[index])
			{
				index = j;
			}
		}
		swap(vec[i], vec[index]);
	}
}
void bucket_Sort(std::vector<int>&vec,void(*func_point)(std::vector<int>))
{
	std::vector<std::vector<int>>temp(3);  //生成三个桶
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] >= 0 && vec[i] < 10)
		{
			temp[0].push_back(vec[i]);
		}
		else if (vec[0] >= 10 && vec[i] < 50)
		{
			temp[1].push_back(vec[i]);
		}
		else
		{
			temp[2].push_back(vec[i]);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		selection_Sort(temp[i]);
	}
	int index = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int result : temp[i])
		{
			vec[index++] = result;
		}
	}
	func_point(vec);
}
int main()
{
	std::vector<int>vec{ 100,67,45,1,34,23,9,6,45,32,89,23 };
	bucket_Sort(vec,print);
	return 0;
}