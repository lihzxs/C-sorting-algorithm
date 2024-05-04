#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
int position(std::vector<int>& vec, int left, int right)
{
	srand((unsigned int)time(nullptr));
	int l = left;
	int r = right;

	int rand_index = rand() % (right - left + 1) + left;
	int temp = vec[l];
	vec[l] = vec[rand_index];
	vec[rand_index] = temp;

	int pivot = vec[l];
	while (l < r)
	{
		while (l < r && vec[r] >= pivot) r--;
		if (l < r)
		{
			vec[l] = vec[r];
		}
		while (l < r && vec[l] <= pivot) l++;
		if (l < r)
		{
			vec[r] = vec[l];
		}
	}
	vec[l] = pivot;
	return l;
}
void quickly_Sort(std::vector<int>& vec, int left, int right)
{
	if (left >= right) return;
	int index = position(vec, left, right);
	quickly_Sort(vec, left, index - 1);
	quickly_Sort(vec, index + 1, right);
}
int main()
{
	std::vector<int>vec{ 100,23,21,1111,67,45,333,32,21,23,10,0,1 };
	quickly_Sort(vec, 0, vec.size() - 1);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	return 0;
}