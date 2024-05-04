#include <iostream>
#include <vector>
void merge(std::vector<int>&vec,int begin, int mid, int end)
{
	std::vector<int>temp;
	int l = begin;
	int r = mid + 1;
	while (l <= mid && r <= end)
	{
		if (vec[l] <= vec[r])
		{
			temp.push_back(vec[l]);
			l++;
		}
		else
		{
			temp.push_back(vec[r]);
			r++;
		}
	}
	while (l <= mid)
	{
		temp.push_back(vec[l]);
		l++;
	}
	while (r <= end)
	{
		temp.push_back(vec[r]);
		r++;
	}
	for (int i = 0; i < temp.size(); i++)
	{
		vec[begin + i] = temp[i];
	}
}
void merge_Sort(std::vector<int>& vec,int begin,int end)
{
	if (begin == end)
	{
		return;
	}
	int mid = (begin + end) / 2;
	merge_Sort(vec, begin, mid);
	merge_Sort(vec, mid + 1, end);
	merge(vec, begin, mid, end);
}
int main()
{
	std::vector<int>vec{ 100,23,21,1111,67,45,333,32,21,23,10,0,1 };
	int begin = 0;
	int end = vec.size() - 1;
	merge_Sort(vec, begin, end);
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}
	return 0;
}