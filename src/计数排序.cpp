#include <iostream>
#include <vector>
int get_max_value(std::vector<int>vec)
{
	int max_value = vec[0];
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] > max_value)
		{
			max_value = vec[i];
		}
	}
	return max_value;
}
int get_min_value(std::vector<int>vec)
{
	int min_value = vec[0];
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] < min_value)
		{
			min_value = vec[i];
		}
	}
	return min_value;
}
void counting_Sort(std::vector<int>vec)
{
	int max_value = get_max_value(vec);
	int min_value = get_min_value(vec);
	int count = max_value - min_value + 1;
	std::vector<int>counting(count, 0);
	for (int i = 0; i < vec.size(); i++)
	{
		counting[vec[i] - min_value]++;
	}
	for (int i = 0; i < counting.size(); i++)
	{
		int cnt = counting[i];
		while (cnt--)
		{
			std::cout << i + min_value << " ";
		}
	}
}
int main()
{
	std::vector<int>vec{ 100,67,45,1,34,23,9,6,45,32,89,23 };
	counting_Sort(vec);
	return 0;
}