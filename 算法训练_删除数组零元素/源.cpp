//�Ӽ��̶���n���������������У���д����CompactIntegers��ɾ������������ֵΪ0��Ԫ�أ����Ԫ���������׶��ƶ���
//ע�⣬CompactIntegers������Ҫ�������鼰��Ԫ�ظ�����Ϊ��������������ֵӦΪɾ������ִ�к��������Ԫ�ظ�����
//���ɾ����������Ԫ�صĸ����������������Ԫ�ء�

//�������� : �������ʽ˵����5Ϊ�������ݵĸ�����3 4 0 0 2 ���Կո������5��������
//5
//3 4 0 0 2
//������� : �������ʽ˵����3Ϊ�������ݵĸ�����3 4 2 ���Կո������3������������
//3
//3 4 2
#if 1

#include <iostream>
#include <array>
using namespace std;

int CompactIntegers(int * array, int arraysSize)
{
	int i = 0;//��¼0��λ��
	int count = 0;
	for (; i < arraysSize; i++)
	{
		if (array[i] == 0)
		{
			for (int j = i+1; j < arraysSize; j++)
			{
				if (array[j] != 0)
				{
					array[i] = array[j];
					array[j] = 0;
					count++;
					break;
				}
			}
		}
		else
		{
			count++;
		}
	}
	cout << count << endl;
	for (i = 0; i < count; i++)
	{
		cout << array[i] << " ";
	}
	return i;
}
int main()
{
	int arrSize = 0;//�����С
	cin >> arrSize;
	int * arrays = new int [arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		cin >> arrays[i];
	}
	CompactIntegers(arrays, arrSize);
	return 0;
}
#endif

#if 0	//1
#include <iostream>
#include <vector>
using namespace std;

int CompactIntegers(vector <int> arrays, int arraysSize)
{
	size_t i = 0;//��¼0��λ��
	vector<int>::iterator it;//����������
	for (i = 0; i < arrays.size();)
	{
		if (arrays[i] == 0)
		{
			arrays.erase(it + i);
			continue;
		}
		i++;
	}
	cout << arrays.size() << endl;
	for (it = arrays.begin(); it != arrays.end(); ++it)
	{
		cout << *it << " ";
	}
	return arrays.size();
}
int main()
{
	int arrSize = 0;//�����С
	cin >> arrSize;
	vector<int> arrays = {0};
	int c = 0;
	for (int i = 0; i < arrSize; i++)
	{
		cin >> c;
		arrays.push_back(c);
	}
	c = CompactIntegers(arrays, arrSize);
	return 0;
}
#endif
#if 0//TA

#include <iostream>
#include <array>
using namespace std;

int CompactIntegers(int* nums, int len)
{
	int n = 0; int arr[len] = { 0 };

	//�������в�Ϊ0��Ԫ�ش�ŵ�
	for (int i = 0; i < len; i++)
	{
		if (nums[i] != 0)
		{
			arr[n] = nums[i];
			n++;

		}

	}
	cout << n << endl;
	//��ӡû��0������
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	return n + 1;
}

int main()
{
	int n = 0; int number;
	cin >> n;
	int nums[n];
	int len = n;
	int i = 0;
	while (n--)//����n��ֵ����������
	{
		cin >> number;
		nums[i] = number; i++;
		// cout<<nums[number];
	}
	CompactIntegers(nums, len);
}

#endif