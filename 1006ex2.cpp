#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
typedef struct {
	int row, col, val;
}matrix;

int main() {
	int n, max = 0, cal = 0;
	matrix a[10001], b[10001];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("\n(%d:%d)=%d", &a[i].row, &a[i].col, &a[i].val);
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].row > a[j].row) {
				matrix temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].row == a[j].row && a[i].col > a[j].col) {
				matrix temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			if (max < a[i].row)
			{
				max = a[i].row;
			}
			else if (max < a[i].col)
			{
				max = a[i].col;
			}
		}
	}
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i].row << "," << a[i].col << "," << a[i].val << endl;
    // }
    
	for (int i = 1; i <= max; i++)
	{
		for (int j = 1; j <= max; j++)
		{
			b[cal].val = 0;
            // cout << "(" << i <<"," << j <<")" << endl;
			for (int p = 1; p <= max; p++) {
				int x = 0,y = 0;
				for (int q = 0; q < n; q++)
				{
					if (a[q].col == p && a[q].row == i) {
						x = a[q].val;
                        // cout << i << p;
                        // cout << "*";
					}
					if (a[q].col == p && a[q].row == j)
					{
						y = a[q].val;
                        // cout << j << p;
                        // cout << "---" << endl;
					}
                    
				}
                // cout << "!!!" << endl;
                b[cal].val += x*y;
			}
			if (b[cal].val != 0)
			{
				b[cal].row = i;
				b[cal].col = j;
				cal++;
			}
		}
	}
	// cout << max << endl;
	for (int i = 0; i < cal; i++)
	{
		cout << b[i].row << " " << b[i].col << " " << b[i].val << endl;
	}
}