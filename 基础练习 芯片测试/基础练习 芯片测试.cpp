// 基础练习 芯片测试.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int arr[20][20]{0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int num = 0;//假设是好的
    int temp = 0;
    while (num < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (i == num) continue;
            if (arr[num][i] == 1 && arr[num][i] != arr[i][num])
            {
                temp = 1;
                break;
            }
        }
        if (temp == 0)
            break;
        else
        {
            num++;
            temp = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[num][i] != 0)
            cout << i+1 << " ";
    }
}
