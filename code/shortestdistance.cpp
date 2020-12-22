#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	//���

	int k;
	cin >> k;
	while (k--)
	{
		int a, b;
		cin >> a >> b;
		int l1 = 0, l2 = 0;
		for (int i = a; i != b; i++)
		{
			if (i > n)
				i = 1;
			l1 += arr[i];
		}
		for (int i = b; i != a; i++)
		{
			if (i > n)
				i = 1;
			l2 += arr[i];
		}

		cout << l1 << " " << l2 << endl;
	}
}
