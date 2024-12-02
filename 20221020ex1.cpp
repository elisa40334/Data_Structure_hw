#include<iostream>
#include<string>
using namespace std;
string a[10][10];
int f(int x,int y);

int main() {
    
	int x = 8, y = 8;
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			cin >> a[i][j];
		}
	}
    cout << "\n\n\n";
	a[1][1] = "X", a[8][8] = "S";
	// int aa = f(8, 8);
    // if (aa == 1)
    // {
    //     cout << "Yes" << endl;
    // }
    // else
    // {
    //     cout << "No" << endl;
    // }
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++) {
            cout << a[i][j];
            if (j != 10-1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    
}

int f(int x, int y) {
    int k;
	if (a[x+1][y] == "0" || a[x + 1][y] == "G" || a[x + 1][y] == "X")
	{
		a[x + 1][y] = "G";
        k = f(x + 1, y);
		if (k == 0)
		{
			a[x + 1][y] = "D";
		}
		else if (a[x + 1][y] == "X")
		{
			return 1;
		}
		else {
			return 2;
		}
	}
	else if (a[x][y - 1] == "0" || a[x][y - 1] == "G" || a[x][y - 1] == "X") {
		a[x][y - 1] = "G";
        k = f(x, y - 1);
		if (k == 0)
		{
			a[x][y - 1] = "D";
		}
		else if (a[x][y - 1] == "X")
		{
			return 1;
		}
		else {
			return 2;
		}
	}
	else if (a[x - 1][y] == "0" || a[x - 1][y] == "G" || a[x - 1][y] == "X")
	{
		a[x - 1][y] = "G";
        k = f(x - 1, y);
		if (k == 0)
		{
			a[x - 1][y] = "D";
		}
		else if (a[x - 1][y] == "X")
		{
			return 1;
		}
		else {
			return 2;
		}
	}
	else if (a[x][y + 1] == "0" || a[x][y + 1] == "G" || a[x][y + 1] == "X") {
		a[x][y + 1] = "G";
        k = f(x, y + 1);
		if (k == 0)
		{
			a[x][y + 1] = "D";
		} 
		else if (a[x][y + 1] == "X") {
			return 1;
		}
		else {
			return 2;
		}
	}
	a[x][y] = "D";
	return 0;
}