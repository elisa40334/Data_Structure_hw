#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
typedef struct {
	int row, col, val;
}matrix;

int main() {
	int n, max = 0, cal = 0,calh1 = -1,calh2 = -1;
	matrix a[11], b[11],h1[11],h2[11];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("\n(%d:%d)=%d", &a[i].row, &a[i].col, &a[i].val);
        if (max < a[i].row)
        {
            max = a[i].row;
        }
        else if (max < a[i].col)
        {
            max = a[i].col;
        }
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
		}
	}
	for (int i = 0; i < n; i++)
	{
		b[cal].val = 0;
        calh1 = -1;
        calh2 = -1;
        for (int p = 0; p < n; p++)
        {
            if (a[p].row == a[i].row)
            {
                h1[++calh1] = a[p];
                //cout << p << ":" << a[p].row << endl;
            }
            if (a[p].row == a[i].col)
            {
                h2[++calh2] = a[p];
                //cout << p << endl;
            }
        }
        for (int q = 0; q <= calh1; q++)
        {
            for (int r = 0; r <= calh2; r++)
            {
                if (h1[q].col == h2[r].col)
                {
                    b[cal].val += h1[q].val * h2[r].val;
                }
            }
        }
        if (b[cal].val != 0)
        {
            b[cal].row = h1[0].row;
            b[cal].col = h2[0].col;
            cal++;
        }
	}
	// cout << max << endl;
	for (int i = 0; i < cal; i++)
	{
		cout << b[i].row << " " << b[i].col << " " << b[i].val << endl;
	}
}