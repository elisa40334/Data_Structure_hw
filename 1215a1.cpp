#include<iostream>
using namespace std;

int main(){
    int n,m;
    while (cin >> n >> m)
    {
        int ans = 0;
        char oil[101][101];
        if(n == 0 && m == 0){
            break;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> oil[i][j];
            }
        }
        int kk = n/2;
        for (int i = kk; i < n; i++)
        {
            for (int j = 0; j < m; j++){
                int check;
                if (oil[i][j] == '@')
                {
                    check = 0;
                    if (i-1 >= 0 && j-1 >= 0) if (oil[i-1][j-1] == '0') check = 1;
                    if (i-1 >= 0 && j+1 >= 0) if (oil[i-1][j+1] == '0') check = 1;
                    if (i+1 >= 0 && j+1 >= 0) if (oil[i+1][j+1] == '0') check = 1;
                    if (i+1 >= 0 && j-1 >= 0) if (oil[i+1][j-1] == '0') check = 1;
                    if (i-1 >= 0) if (oil[i-1][j] == '0') check = 1;
                    if (i+1 >= 0) if (oil[i+1][j] == '0') check = 1;
                    if (j-1 >= 0) if (oil[i][j-1] == '0') check = 1;
                    if (j+1 >= 0) if (oil[i][j+1] == '0') check = 1;
                    oil[i][j] = '0';
                }
                else check = 2;
                if (check == 0) {
                    ans++;
                    // cout << i << j << "::" << endl;
                }
                
            }
        }
        for (int i = kk-1; i >= 0; i--)
        {
            for (int j = 0; j < m; j++){
                int check;
                if (oil[i][j] == '@')
                {
                    check = 0;
                    if (i-1 >= 0 && j-1 >= 0) if (oil[i-1][j-1] == '0') check = 1;
                    if (i-1 >= 0 && j+1 >= 0) if (oil[i-1][j+1] == '0') check = 1;
                    if (i+1 >= 0 && j+1 >= 0) if (oil[i+1][j+1] == '0') check = 1;
                    if (i+1 >= 0 && j-1 >= 0) if (oil[i+1][j-1] == '0') check = 1;
                    if (i-1 >= 0) if (oil[i-1][j] == '0') check = 1;
                    if (i+1 >= 0) if (oil[i+1][j] == '0') check = 1;
                    if (j-1 >= 0) if (oil[i][j-1] == '0') check = 1;
                    if (j+1 >= 0) if (oil[i][j+1] == '0') check = 1;
                    oil[i][j] = '0';
                }
                else check = 2;
                if (check == 0) {
                    ans++;
                    // cout << i << j << "::" << endl;
                }
                
            }
        }
        cout << ans << endl;
    }
}