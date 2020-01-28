
#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 0;
	cin >> a >> b;//行，列
	int arr[200][200] = {0};
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cin >> arr[i][j];
		}
	}
	int m = 0,n = 0;//行，列
	int count = 0;//圈数
	int endkey = 0;
	int key = a * b;
	while (endkey < key)
	{
		for (m = count; m < a; m++)
		{
			cout << arr[m][n];
			endkey++;
			if (endkey == key) exit(0);
			cout << " ";
		}
		m--,n++;
		for (; n <b; n++)
		{
			endkey++;
			cout << arr[m][n];
			if (endkey == key) exit(0);
			cout << " ";
		}
		n--,m--;
		for (; m >= count; m--)
		{
			endkey++;
			cout << arr[m][n];
			if (endkey == key) exit(0);
			cout << " ";
		}
		m++,n--;
		for (; n > count; n--)
		{
			endkey++;
			cout << arr[m][n];
			if (endkey == key) exit(0);
			cout << " ";
		}
		n++;
		a--; b--;
		count++;
	}
	return 0;
}

/*for (int k = 0; k < a*b; k++)
	{
		cout << arr[m][n];

		if (m + 1 == a && n + 1 < b)
		{
			n++;
		}
		else if (m + 1 < a && n < b)
		{
			m++;
		}
		else if (n+1 == b && m > 0)
		{
			m--;
		}
		else if (m == count && n > 0)
		{
			n--;
		}
	}*/