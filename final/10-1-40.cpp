//5 1 3
#include<iostream>
using namespace std;

int main() {
	int n, a, b, posi[1000] = { 0 },count = 0,ans[1000],cal = 0;
	cin >> n >> a >> b;
	a--;
	for (int i = 0; i <= n; i++)
	{
		posi[i] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < b;)
		{
			a++;
			if (a > n)
			{
				a = 1;
			}
			if (posi[a] == 1)
			{
				j++;
			}
			if (j == b)
			{
				posi[a] = 0;
				ans[i] = a;
				break;
			}
			
			//cout << "hsdfj" << endl;
			
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
}