#include <iostream>
#include <vector>
int counting_Max(int max)
{
	int cnt = 0;
	while (max)
	{
		int a = max % 10;
		cnt++;
		max = max / 10;
	}
	return cnt;
}
int get_Max(std::vector<int>vec)
{
	int max = vec[0];
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] > max)
		{
			max = vec[i];
		}
	}
	return max;
}
void radix_Sort(std::vector<int>&vec)
{
	int base = 1;
	int max = get_Max(vec);
	int cnt = counting_Max(max);

	//����ʮ��Ͱ
	std::vector<std::vector<int>>s(10);
	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < vec.size(); j++)
		{
			int r = vec[j] / base % 10;  //������λ�ŵ���ͬ��Ͱ��
			s[r].push_back(vec[j]);
		}
		//��Ͱ�б���ÿ��Ԫ�����ηŻ�ԭ����
		int index = 0;      
		for (int k = 0; k < 10; k++)
		{
			for (int h = 0; h < s[k].size(); h++)
			{
				vec[index++] = s[k][h];
			}
			s[k].clear();
		}
		base = base * 10;
	}
}
int main()
{
	std::vector<int>vec{ 100,23,21,1111,67,45,333,32,21,23,10,0,1 };
	radix_Sort(vec);
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}
	return 0;
}