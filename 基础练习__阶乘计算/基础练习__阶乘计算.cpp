// 基础练习__阶乘计算.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//问题描述
//输入一个正整数n，输出n!的值。
//其中n != 1 * 2 * 3 * … * n。
//算法描述
//n!可能很大，而计算机能表示的整数范围有限，需要使用高精度计算的方法。使用一个数组A来表示一个大整数a，A[0]表示a的个位，A[1]表示a的十位，依次类推。
//将a乘以一个整数k变为将数组A的每一个元素都乘以k，请注意处理相应的进位。
//首先将a设为1，然后乘2，乘3，当乘到n时，即得到了n!的值。
//输入格式
//输入包含一个正整数n，n <= 1000。
//输出格式
//输出n!的准确值。
//样例输入
//10
//样例输出
//3628800

//30
//265252859812191058636308480000000
//265252859812191058636308480000000

#include <iostream>

using namespace std;


void func(int n, int* nums, int& len)
{
	while (n)
	{
		*nums = n % 10;
		n /= 10;
		nums++;
		len++;
	}
}
void factorial(int* nums, int pos, int& len)
{
	int temp = 0;//存储进位
	for (int i = 0; i < len; i++)
	{
		nums[i] =temp + nums[i] * pos;
		temp = 0;
		if (nums[i] >= 10)
		{
			temp = nums[i] / 10;
			nums[i] = nums[i] % 10;
		}
		if (i + 1 == len)
		{
			if (temp != 0)
			{
				nums[i + 1] = temp;
				len++;
			}
				
			break;
		}
	}

	if (temp >= 10)
	{
		len--;
		while (temp)
		{
			nums[len] = temp % 10;
			temp /= 10;
			len++;
		}
	}
}
int main()
{
	int n = 0;
	cin >> n;
	int *nums = new int[10000]();

	int len = 0;//位数
	func(n,nums,len);
	
	for (int i = n - 1; i > 0; i--)
	{
		factorial(nums,i,len);
	}
	for (int j = len - 1; j >= 0; j--)
	{
		cout << nums[j];
	}
	delete[] nums;
	return 0;
}


