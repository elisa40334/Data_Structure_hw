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
	
    
	for (int i = 1; i <= max; i++)
	{
		for (int j = 1; j <= max; j++)
		{
			b[cal].val = 0;
            calh1 = -1;
            calh2 = -1;
            // cout << "n" << i << "," << j << endl;
            for (int p = 0; p < n; p++)
            {
                if (a[p].row == i)
                {
                    h1[++calh1] = a[p];
                    //cout << p << ":" << a[p].row << endl;
                }
                if (a[p].row == j)
                {
                    h2[++calh2] = a[p];
                    //cout << p << endl;
                }
            }
            // for (int q = 0; q <= calh1; q++)
            // {
            //     cout << h1[q].row << "," << h1[q].col <<',' << h1[q].val << endl;
            // }
            // cout << "h2" << endl;
            // for (int q = 0; q <= calh2; q++)
            // {
            //     cout << h2[q].row << "," << h2[q].col <<',' << h2[q].val << endl;
            // }
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