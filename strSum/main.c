#define _CRT_SECURE_NO_WARNINGS

//��������
//����һ������Ϊn���ַ���S������һ������L��ͳ�Ƴ��ȴ��ڵ���L�ĳ��ִ��������Ӵ�����ͬ�ĳ��ֿ����ཻ��������ж���������ģ������Ȼ�ж���������һ�γ�������ġ�
//�����ʽ
//��һ��һ������L��
//�ڶ������ַ���S��
//L����0���Ҳ�����S�ĳ��ȡ�
//�����ʽ
//һ�У���ĿҪ����ַ�����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#if 1
//��ȷ
char* fun(char* arr, int len, int L,int * strsum)
{
    char str[1000][60] = { 0 };//��ŷ���
    int count[1000] = { 0 };//��Ŵ���
    int i;
    for (i = 0; i < len - L + 1; i++)//�ָ��L���ȵ�
    {
        strncpy(str[i], arr + i, L);
    }
    /*for (i = 0; i < len - L + 1; i++)
        printf("%s ", str[i]);*/

    for (i = len - L; i != 0; i--)//�Ƚ�
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
    for (i = 0; i <= len - L + 1; i++)//�������������
    {
        max = count[i] > count[max] ? i : max;
    }
    *strsum = count[max];//��ǰL���������ַ��Ĵ���
    char* strarr = (char*)malloc(60);
    strcpy(strarr, str[max]);
    return strarr;
    //printf("\n%s", str[max]);
}
int main()
{
    int L = 0;
    scanf("%d", &L);//�ַ�����L

    char arr[1000] = { 0 };//������ַ���
    scanf("%s", arr);
    int len = strlen(arr);
    //printf("%d",len);

    char maxstr[60][60];//���ÿ��L��ֵ
    int maxstrCount[60];//���ÿ��L��ֵ�Ĵ���
    int strsum = 0;//ÿ��L�Ĵ���
    int i = 0; int j = 0;
    for (L; L <= 60 && L < len; L++)//��ÿ��L�����ַ��浽һ��
    {
        strcpy(maxstr[j], fun(arr, len, L,&strsum));
        maxstrCount[j] = strsum;
        j++;
    }
    int max = 0;
    for (i = 0; i < j; i++)//�������������
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
    char str[1000][60] = { 0 };//��ŷ���
    int count[1000] = { 0 };//��Ŵ���
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
    scanf("%d", &L);//�ַ�����L

    char arr[1000] = { 0 };//������ַ���
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
	scanf("%d", &L);//�ַ�����L

    char arr[1000] = { 0 };//������ַ���
	scanf("%s", arr);
	int len = strlen(arr);
    //printf("%d",len);

    char str[1000][60] = { 0 };//��ŷ���
    int count[1000] = { 0 };//��Ŵ���
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
            arr[zi][0] = 1;//��λ�Ŵ���
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
    int L;//��ʼ�ĳ���
    char s[61] = { 0 };//�洢������ַ���
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
    //fenge�ǽ����Ȳ�ͬ������ָ�����൱�ڽ���
    int fenge = 0; int zi = 0;//zi������������к�
    while (L <= len - 1)
    {
        char* cur = s;
        char* next = s + 1;
        int i = 0;
        //���ָ���ַ�����������У�����ĵ�һ��Ԫ��ֵ�Ǵ����������'\0'
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
            //���ָ��ÿһ������������ͬ��ǰ�������ֵ���бȽ�
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
                //flag==0��ʾ������ͬ�ģ������֮��ͬ��ǰ�������ֵ��1�����Լ���0
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
        int flag = 0;//�������齫�����ҳ����Ӧ���±��ָ�����ĺ��������ͷָ�ǰ�����ֵһ����������ָ���
        for (; i < len - L + 1; i++)
        {

            if (max < arr[zi][0] || (max <= arr[zi][0] && temp < L))
            {
                if (flag != 0 && max == arr[zi][0])//��ֹ����ͬһ���ָ��ͬ���Ĵ���������Ľ�ǰ��ĸ���
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