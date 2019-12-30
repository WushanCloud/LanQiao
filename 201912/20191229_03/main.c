#include <stdio.h>
#include <stdlib.h>

int prime(int num)
{
    int i = 2;
    for(;i<= num/2;i++)
    {
        if(num%i == 0)
        {
            return 1;//不是质数
        }
    }
    return 0;
}
void primeArr( int num,int *arr)
{
    int i = 2;int j = 0;
    for(;i < num; i++)
    {
        if(prime(i))continue;
        else arr[j++] = i;
    }
}
void resolve(int num,int *arr)
{
    int i = 0;
    while(num != 1)
    {
        for (;arr[i];i++)
        {
            if(num%arr[i] == 0)
            {
                printf("%d*",arr[i]);
                break;
            }
        }
        num = num/arr[i];
        if(prime(num) == 0)
        {
            printf("%d",num);
            break;
        }
        i = 0;
    }

}

int main()
{
    int a = 2,b = 10000;
    //scanf("%d%d",&a,&b);
    int array[5000] = {0};
    primeArr(b,array);
    for(;a<=b;a++)
    {
        printf("%d=",a);
        if(prime(a))
        {
            resolve(a,array);
        }
        else
        {
            printf("%d",a);
        }
        printf("\n");
    }
    return 0;
}
