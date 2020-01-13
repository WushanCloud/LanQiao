#define _CRT_SECURE_NO_WARNINGS

//问题描述
//给定一个长度为n的字符串S，还有一个数字L，统计长度大于等于L的出现次数最多的子串（不同的出现可以相交），如果有多个，输出最长的，如果仍然有多个，输出第一次出现最早的。
//输入格式
//第一行一个数字L。
//第二行是字符串S。
//L大于0，且不超过S的长度。
//输出格式
//一行，题目要求的字符串。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#if 1
//正确
char* fun(char* arr, int len, int L,int * strsum)
{
    char str[1000][60] = { 0 };//存放分组
    int count[1000] = { 0 };//存放次数
    int i;
    for (i = 0; i < len - L + 1; i++)//分割成L长度的
    {
        strncpy(str[i], arr + i, L);
    }
    /*for (i = 0; i < len - L + 1; i++)
        printf("%s ", str[i]);*/

    for (i = len - L; i != 0; i--)//比较
    {
        int j = 0;
        for (j = 0; j < i; j ++)
        {
            if (strcmp(str[i], str[j]) == 0)
            {
                count[j] ++;
                break;
            }
        }
    }
    //printf("\n");
    /*for (i = 0; i < len - L + 1; i++)
        printf("%d ", count[i]);*/
    int max = 0;
    for (i = 0; i <= len - L + 1; i++)//找最多次数最早的
    {
        max = count[i] > count[max] ? i : max;
    }
    *strsum = count[max];//当前L的最多次数字符的次数
    char* strarr = (char*)malloc(60);
    strcpy(strarr, str[max]);
    return strarr;
    //printf("\n%s", str[max]);
}
int main()
{
    int L = 0;
    scanf("%d", &L);//字符长度L

    char arr[1000] = { 0 };//存放总字符串
    scanf("%s", arr);
    int len = strlen(arr);
    //printf("%d",len);

    char maxstr[60][60];//存放每个L的值
    int maxstrCount[60];//存放每个L的值的次数
    int strsum = 0;//每个L的次数
    int i = 0; int j = 0;
    for (L; L <= 60 && L < len; L++)//把每个L长的字符存到一起
    {
        strcpy(maxstr[j], fun(arr, len, L,&strsum));
        maxstrCount[j] = strsum;
        j++;
    }
    int max = 0;
    for (i = 0; i < j; i++)//找最多次数切最长的
    {
        max = maxstrCount[i] >= maxstrCount[max] ? i : max;
    }
    printf("%s", maxstr[max]);

    return 0;
}

#endif

#if 0
char* fun(char* arr,int len ,int L)
{
    char str[1000][60] = { 0 };//存放分组
    int count[1000] = { 0 };//存放次数
    int i;
    for (i = 0; i < len - L + 1; i++)
    {
        strncpy(str[i], arr + i, L);
    }
    /*for (i = 0; i < len - L + 1; i++)
        printf("%s ", str[i]);*/

    for (i = len - L; i != 0; i--)
    {
        int j = 0;
        for (j = 0; j < i; j++)
        {
            if (strcmp(str[i], str[j]) == 0)
            {
                count[j] ++;
                break;
            }
        }
    }
    int max = len - L + 1;
    for (i = len - L + 1; i != 0; i--)
    {
        max = count[i] >= count[max] ? i : max;
    }
    char* returnstr = (char*)malloc(60);
    strcpy(returnstr, str[max]);
    printf("%s\n", returnstr);
    return returnstr;
}

int main()
{
    int L = 0;
    scanf("%d", &L);//字符长度L

    char arr[1000] = { 0 };//存放总字符串
    scanf("%s", arr);
    int len = strlen(arr);

    char maxstr[60][60];

    int i = 60; int j = 0;
    for (L; L <= i && L < len; L++)
    {
        strcpy(maxstr[j++], fun(arr, len, L));
    }
    for (i = 0; i < 60-L+1 && i < len - L+1; i++)
    printf("%s\n", maxstr[i]);

    return 0;
}

#endif

#if 0

int main()
{
	int L = 0;
	scanf("%d", &L);//字符长度L

    char arr[1000] = { 0 };//存放总字符串
	scanf("%s", arr);
	int len = strlen(arr);
    //printf("%d",len);

    char str[1000][60] = { 0 };//存放分组
    int count[1000] = { 0 };//存放次数
    int i;
    for (i = 0; i < len - L + 1; i++)
    {
        strncpy(str[i], arr+i, L);
    }
    for (i = 0; i < len - L +1; i++)
        printf("%s ", str[i]);

    for (i = len - L; i != 0; i--)
    {
        int j = 0;
        for (j = 0; j < i; j+=(L-1))
        {
            if (strcmp(str[i], str[j]) == 0)
            {
                count[j] ++;
                break;
            }
        }
    }
    printf("\n");
    for (i = 0; i < len - L + 1; i++)
        printf("%d ", count[i]);
    int max = 0;
    for (i = 0;i <= len - L +1; i++)
    {
        max = count[i] > count[max] ? i : max;
    }
    printf("\n%s", str[max]);

	return 0;
}
#endif

#if 0
void fun(int L, int len, char* s, char arr[1000][1000])
{
    char* cur = s;
    char* next = s + 1;
    int flag = 0; int i = 0;
    for (; i < len - L + 1; i++)
    {
        arr[i][0] = 1;
        if (cur + 3 == '\0')break;
        int j = 0;
        for (j = 1; j < L + 1; j++)
        {

            arr[i][j] = *cur;
            cur++;
        }
        arr[i][j] = '\0';
        int m = 0;
        for (; m < i; m++)
        {
            int n = 1;
            for (; n < L + 1; n++)
            {
                if (arr[i][n] != arr[m][n])
                    flag = 1;
            }
            if (flag == 1)
            {
                arr[i][0] = 0;
                arr[m][0]++;
                break;
            }

        }

        cur = next;
        next++;
    }

}
void print(char arr[1000][1000], int L, int len)
{
    int max = arr[0][0];
    int i = 0; int k = 0;
    for (; i < len - L + 1; i++)
    {
        if (max < arr[i][0])
        {
            max = arr[i][0];
            k = i;
        }

    }
    int j = 1;
    for (; j < L + 1; j++)
    {
        printf("%c", arr[k][j]);
    }
}

int main()
{
    int L = 4;
    char s[] = "aabbaaabba";
    //  scanf("%d",&L);
    //  scanf("%s",s);
    int len = strlen(s);
    char arr[1000][1000];
    fun(L, len, s, arr);
    print(arr, L, len);
    return 0;
}

#endif
#if 0


void fun(int L, int len, char* s, char arr[1000][62])
{
    int fenge = 0; int zi = 0;

    while (L <= len )
    {
        char* cur = s;
        char* next = s + 1;
        int i = 0;
        for (; i < len - L + 1; i++)
        {
            arr[zi][0] = 1;//首位放次数
            //if (cur + L - 1 == '\0')break;
            int j = 0;
            for (j = 1; j < L + 1; j++)
            {
                arr[zi][j] = *cur;
                cur++;
            }
            arr[zi][j] = '\0';
            int m = fenge;
            for (; m < zi; m++)
            {
                int n = 1; int flag = 0;
                for (; n < L + 1; n++)
                {
                    if (arr[zi][n] != arr[m][n])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    arr[zi][0] = 0;
                    arr[m][0]++;
                    break;
                }
            }
            cur = next;
            next++;
            zi++;
        }
        L++;
        fenge = zi;
    }

}
void print(char arr[1000][62], int L, int len)
{
    int max = arr[0][0]; int temp = L;
    int k = 0; int zi = 0;
    while (L <= len)
    {
        int i = 0;

        for (; i < len - L + 1; i++)
        {

            if (max < arr[zi][0] || (max <= arr[zi][0] && temp < L))
            {
                max = arr[i][0];
                k = zi;
            }
            zi++;
        }
        temp = L;
        L++;

    }

    int j = 1;

    while (arr[k][j] != '\0')
    {
        printf("%c", arr[k][j]);
        j++;
    }
}

int main()
{
    int L;//初始的长度
    char s[61] = { 0 };//存储输入的字符串
    scanf("%d", &L);
    scanf("%s", s);
    int len = strlen(s);
    char arr[1000][62] = { 0 };
    fun(L, len, s, arr);
    print(arr, L, len);
    return 0;
}

#endif
#if 0

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void fun(int L, int len, char* s, char arr[1000][1000])
{
    //fenge是将长度不同的数组分割出来相当于界限
    int fenge = 0; int zi = 0;//zi是真正数组的行号
    while (L <= len - 1)
    {
        char* cur = s;
        char* next = s + 1;
        int i = 0;
        //将分割的字符串存进数组中，数组的第一个元素值是次数，最后是'\0'
        for (; i < len - L + 1; i++)
        {
            //arr[zi][0] = 1;
            //if (cur + L - 1 == '\0')break;
            int j = 0;
            for (j = 1; j < L + 1; j++)
            {
                arr[zi][j] = *cur;
                cur++;
            }
            //arr[zi][j] = '\0';
            int m = fenge;
            //将分割的每一块与它长度相同的前面的数组值进行比较
            for (; m < zi; m++)
            {
                int n = 1; int flag = 0;
                for (; n < L + 1; n++)
                {
                    if (arr[zi][n] != arr[m][n])
                    {
                        flag = 1;
                        break;
                    }
                }
                //flag==0表示出现相同的，则给与之相同的前面的数组值加1，他自己成0
                if (flag == 0)
                {
                    arr[zi][0] = 0;
                    arr[m][0]++;
                    break;
                }
            }
            cur = next;
            next++;
            zi++;
        }
        L++;
        fenge = zi;
    }

}
void print(char arr[1000][1000], int L, int len)
{
    int max = arr[0][0]; int temp = L;
    int k = 0; int zi = 0;
    while (L <= len - 1)
    {
        int i = 0;
        int flag = 0;//遍历数组将最大的找出其对应的下表，分割出来的后面的如果和分割前的最大值一样，则输出分割后的
        for (; i < len - L + 1; i++)
        {

            if (max < arr[zi][0] || (max <= arr[zi][0] && temp < L))
            {
                if (flag != 0 && max == arr[zi][0])//防止出现同一个分割部分同样的次数，后面的将前面的覆盖
                    ;
                else
                {
                    max = arr[i][0];
                    k = zi;
                }
            }
            zi++;
            flag = 1;
        }
        temp = L;
        L++;
    }
    int j = 1;
    while (arr[k][j] != '\0')
    {
        printf("%c", arr[k][j]);
        j++;
    }
}

int main()
{
    int L;
    char s[62] = {0};
    scanf("%d", &L);
    scanf("%s", s);
    int len = strlen(s);
    char arr[1000][1000] = {0};
    fun(L, len, s, arr);
    print(arr, L, len);
    return 0;
}


#endif