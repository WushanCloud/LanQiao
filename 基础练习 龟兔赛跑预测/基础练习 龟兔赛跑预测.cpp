// 基础练习 龟兔赛跑预测.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

int main()
{
    int v1, v2;//兔，龟
    int t, s;//领先t,停s秒
    int l;//赛道长
    cin >> v1 >>v2>> t>> s>> l;
    int time = 0;
    int Rlucheng = 0;//路程
    int Tlucheng = 0;
    int Rlingxian = 0;//兔子领先
    int L1 = l;//兔子剩余距离
    int L2 = l;//乌龟剩余距离
    while (L1 > 0 && L2 > 0)
    {
        while (Rlingxian <t)
        {
            Rlucheng += v1;
            Tlucheng += v2;
            Rlingxian = Rlucheng - Tlucheng;
            time++;
            L1 -= v1;
            L2 -= v2;
            if (L1 == L2 &&L2 == 0)
            {
                cout << "D\n"<<time;
                exit(0);
            }
            else if (L1 == 0)
            {
                cout << "R\n" << time;
                exit(0);
            }
            if (Rlingxian == t)break;
        }
        for (int i = 0; i < s; i++)
        {
            Tlucheng += v2;
            L2 -= v2;
            time++;
            if (L2 == 0)
            {
                cout << "T\n" << time;
                exit(0);
            }
        }
        Rlingxian = Rlucheng - Tlucheng;
    }
    return 0;
}

