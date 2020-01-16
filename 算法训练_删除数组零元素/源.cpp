//从键盘读入n个整数放入数组中，编写函数CompactIntegers，删除数组中所有值为0的元素，其后元素向数组首端移动。
//注意，CompactIntegers函数需要接受数组及其元素个数作为参数，函数返回值应为删除操作执行后数组的新元素个数。
//输出删除后数组中元素的个数并依次输出数组元素。

//样例输入 : （输入格式说明：5为输入数据的个数，3 4 0 0 2 是以空格隔开的5个整数）
//5
//3 4 0 0 2
//样例输出 : （输出格式说明：3为非零数据的个数，3 4 2 是以空格隔开的3个非零整数）
//3
//3 4 2
#if 1

#include <iostream>
#include <array>
using namespace std;

int CompactIntegers(int * array, int arraysSize)
{
	int i = 0;//记录0的位置
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
	int arrSize = 0;//数组大小
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
	size_t i = 0;//记录0的位置
	vector<int>::iterator it;//迭代器对象
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
	int arrSize = 0;//数组大小
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

	//将数组中不为0的元素存放到
	for (int i = 0; i < len; i++)
	{
		if (nums[i] != 0)
		{
			arr[n] = nums[i];
			n++;

		}

	}
	cout << n << endl;
	//打印没有0的数组
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
	while (n--)//输入n个值并存入数组
	{
		cin >> number;
		nums[i] = number; i++;
		// cout<<nums[number];
	}
	CompactIntegers(nums, len);
}

#endif