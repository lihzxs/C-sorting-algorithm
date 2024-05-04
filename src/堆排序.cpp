#include <iostream>
#include <vector>
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
/*��������*/
void create_Max_Heap(std::vector<int>& vec,int root,int len)
{
	int son = root * 2 + 1;   //�����±�
	while (son < len)
	{
		if (son + 1 < len && vec[son + 1] > vec[son])  //�Һ��Ӵ������Һ��ӵ�ֵ��������
		{
			son++;   //��ȡ�Һ��ӵ��±�
		}
		if (vec[son] > vec[root])  //���ӽ����ڸ���㣬�򽻻�
		{
			swap(vec[son], vec[root]);
		}
		else
		{
			break;
		}
		root = son;
		son = son * 2 + 1;
	}
}
int main()
{
	std::vector<int>vec{ 100,23,21,1111,67,45,333,32,21,23,10,0,1 };
	int len = vec.size();
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		create_Max_Heap(vec, i, len);
	}
	for (int i = 0; i < len; i++)
	{
		std::cout << vec[i] << std::endl;
	}
	std::cout << "-------------------------------" << std::endl;
	for (int i = len - 1; i >= 0; i--)
	{
		swap(vec[0], vec[i]);
		create_Max_Heap(vec, 0, i);
	}
	for (int i = 0; i < len; i++)
	{
		std::cout << vec[i] << std::endl;
	}
	return 0;
}