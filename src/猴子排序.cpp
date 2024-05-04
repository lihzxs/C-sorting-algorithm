#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
bool is_sorted(std::vector<int>& vec)
{
	int len = vec.size();
	for (int i = 0; i < len - 1; i++)
	{
		if (vec[i] > vec[i + 1])
		{
			return false;
		}
	}
	return true;
}
/*猴子排序的洗牌算法*/
void rand_random(std::vector<int>& vec)
{
	int len = vec.size() - 1;
	srand((unsigned int)(time(nullptr)));
	for (int i = len; i > 0; i--)
	{
		int swap_index = rand() % i;
		int temp = vec[i];
		vec[i] = vec[swap_index];
		vec[swap_index] = temp;
	}
}
int main()
{
	std::vector<int>vec{ 100,23,21,1111,67,45,333 };
	std::mt19937 random_t(time(nullptr));
	long long cnt = 0;
	while (!is_sorted(vec))   //不是有序
	{
		std::shuffle(vec.begin(), vec.end(), random_t);
		cnt++;
	}
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	std::cout << "排序了:" << cnt << "次!" << std::endl;

	std::vector<int>v{ 100,23,21,1111,67,45,333 };
	rand_random(v);
	std::cout << "----------------------------------" << std::endl;
	for (auto it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	return 0;
}