#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
typedef struct {
	int row, col, val;
    int check;
}matrix;

int main() {
	int n, max = 0, cal = 0,calh1 = -1,calh2 = -1,rank[11] = {0},cou = 0,rankb[11] = {0},coub = 0;
	matrix a[11], b[11],h1[11],h2[11];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("\n(%d:%d)=%d", &a[i].row, &a[i].col, &a[i].val);
        b[i].col = a[i].row;
        b[i].row = a[i].col;
        b[i].val = a[i].val;
        b[i].check = 0;
        a[i].check = 0;
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
	for (int i = 0; i < n-1; i++)
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
    for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (b[i].row > b[j].row) {
				matrix temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (b[i].row == b[j].row && b[i].col > b[j].col) {
				matrix temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
    for (int i = 0; i < n; i++)
    {
        if (a[i].check != 1)
        {
            rank[cou] = 1;
            for (int j = i+1; j < n; j++)
            {
                if (a[i].row == a[j].row)
                {
                    rank[cou]++;
                    a[j].check = 1;
                }
            }
            rank[cou] += rank[cou-1];
            cou++;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (b[i].check != 1)
        {
            rankb[coub] = 1;
            for (int j = i+1; j < n; j++)
            {
                if (b[i].row == b[j].row)
                {
                    rankb[coub]++;
                    b[j].check = 1;
                }
            }
            rankb[coub] += rankb[coub-1];
            coub++;
        }
    }
    
    for (int i = 0; i < cou; i++)
    {
        cout << rank[i] << "," << endl;
    }
    cout << "adlhkl"<< endl;
    for (int i = 0; i < coub; i++)
    {
        cout << rankb[i] << "," << endl;
    }
	for (int i = 0; i < cou; i++)
    {
        for (int q = 0; q < coub; q++)
        {
            b[cal].val = 0;
            calh1 = -1;
            calh2 = -1;
            for (int j = rank[i-1]; j < rank[i]; j++)
            {
                h1[++calh1] = a[j];
            }
            for (int j = rankb[q-1] ; j < rankb[q]; j++)
            {
                h2[++calh2] = a[j];
            }
            // cout << "test" << endl;
            // for (int k = 0; k <= calh1; k++)
            // {
            //     cout << h1[k].row << "," << h1[k].col <<',' << h1[k].val << endl;
            // }
            // cout << "h2" << endl;
            // for (int k = 0; k <= calh2; k++)
            // {
            //     cout << h2[k].row << "," << h2[k].col <<',' << h2[k].val << endl;
            // }
            int xx,yy;
            for (int k = 0; k <= calh1; k++)
            {
                for (int r = 0; r <= calh2; r++)
                {
                    if (h1[k].col == h2[r].col)
                    {
                        b[cal].val += h1[k].val * h2[r].val;
                    }
                }
            }
            if (b[cal].val != 0)
            {
                b[cal].row = h1[0].row;
                b[cal].col = h2[0].row;
                cal++;
            } 
        }
    }
	for (int i = 0; i < cal; i++)
	{
		cout << b[i].row << " " << b[i].col << " " << b[i].val << endl;
	}
}