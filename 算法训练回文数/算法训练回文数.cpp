// 算法训练回文数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//问题描述
//若一个数（首位不为零）从左向右读与从右向左读都一样，我们就将其称之为回文数。
//例如：给定一个10进制数56，将56加65（即把56从右向左读），得到121是一个回文数。
//
//又如：对于10进制数87：
//STEP1：87 + 78 = 165 STEP2：165 + 561 = 726
//STEP3：726 + 627 = 1353 STEP4：1353 + 3531 = 4884
//
//在这里的一步是指进行了一次N进制的加法，上例最少用了4步得到回文数4884。
//
//写一个程序，给定一个N（2 <= N <= 10或N = 16）进制数M（其中16进制数字为0 - 9与A - F），求最少经过几步可以得到回文数。
//如果在30步以内（包含30步）不可能得到回文数，则输出“Impossible!”
//输入格式
//两行，N与M
//输出格式
//如果能在30步以内得到回文数，输出“STEP = xx”（不含引号），其中xx是步数；否则输出一行”Impossible!”（不含引号）
//样例输入
//9
//87
//样例输出
//STEP = 6


#include <iostream>
#include <string.h>
using namespace std;

void xiangjia(int* arr, int* arr2, int* len, int jinzhi);
int weishujisuan(int num);//一次
void shuzizhuanhuan(int num, int* arr, int weishu);//一次
void zifuchuanfanzhuan(int* arr, int* arr2, int len);
bool huiwenpanduan(int* arr, int* arr2, int len);
void shiliuzhuanshuzu(char* num, int* arr, int len);

int main()
{
	int jinzhi;
	int num;
	char nums[50] = {0};
	cin >> jinzhi;
	int len = 0;
	int arr[50] = { 0 };//反转
	int arr2[50] = { 0 };//未反转
	if (jinzhi == 16)
	{
		cin >> nums;
		len = strlen(nums);
		shiliuzhuanshuzu(nums,arr,len);
	}
	else
	{
		cin >> num;
		len = weishujisuan(num);
		shuzizhuanhuan(num, arr, len);
	}
	zifuchuanfanzhuan(arr, arr2, len);
	for (int count = 0; count < 31; count++)
	{
		bool result;
		result = huiwenpanduan(arr, arr2,len);
		if (result == true)
		{
			cout << "STEP=" << count;
			exit(0);
		}
		else
		{
			xiangjia(arr, arr2, &len,jinzhi);//存在arr
			zifuchuanfanzhuan(arr, arr2, len);
		}
	}
	cout << "Impossible!";
	return 0;
}
void xiangjia(int * arr, int *arr2, int *len,int jinzhi)
{
	for (int i = 0; i < *len; i++)
	{
		arr[i] = arr[i] + arr2[i];
		//如果个位大于进制数，则进位：12%10 = 2；12/10 = 1；
		if (arr[i] >= jinzhi)
		{
			int temp = arr[i];
			arr[i] = temp % jinzhi;
			arr[i + 1] = arr[i + 1] + temp / jinzhi;
			if (i + 1 == *len)
				(*len)++;
		}
	}
}
int weishujisuan(int num)//一次
{
	int weishu = 0;
	while (num)
	{
		num /= 10;
		weishu++;
	}
	return weishu;
}
void shuzizhuanhuan(int num, int* arr, int weishu)//一次
{
	for (int i = 0; i < weishu; i++)
	{
		arr[i] = num % 10;
		num /= 10;
	}
}
void zifuchuanfanzhuan(int* arr, int* arr2, int len)
{
	for (int i = 0; i < len; i++)
	{
		arr2[i] = arr[len - i - 1];
	}
}
bool huiwenpanduan(int* arr, int* arr2,int len)
{
	while (len--)
	{
		if (*arr == *arr2)
		{
			;
		}
		else
		{
			return false;
		}
		arr++;
		arr2++;
	}
	return true;
}
void shiliuzhuanshuzu(char* num, int* arr, int len)
{
	int i = 0;
	while (len--)
	{
		if (num[i]>='A' && num[i] <= 'F')
		{
			arr[len - i] = num[i] - 'A' + 10;
		}
		else
		{
			arr[len - i] = num[i] - '0';
		}
		num++;
	}
}