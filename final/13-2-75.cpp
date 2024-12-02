// 4
// 0 1 1 1
// 1 0 1 1
// 1 1 0 1
// 1 1 1 0

// 5
// 0 1 1 0 0
// 1 0 1 0 0
// 1 1 0 0 0
// 0 0 0 0 1
// 0 0 0 1 0

#include<iostream>
#include <set>
using namespace std;
int f(int k,int aa[101][101],int list[101][101],int n,int cal[]);

int main(){
    int n,a,check = 1,list[101][101] = {},cal[101] = {},aa[101][101] = {};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a;
            if (a == 1)
            {
                list[i][cal[i]++] = j;
            }
        }
    }

    for (int i = 0; i < n; i++)
    { 
        // cout << i << ": ";
        aa[i][i]  = 1;
        for (int j = 0; j < cal[i]; j++)
        {
            aa[i][list[i][j]] = 1;
            if (list[i][j] < i)
            {
                for (int q = 0; q < n; q++)
                {
                    if (aa[list[i][j]][q] == 1)
                    {
                        aa[i][q] = 1;
                    }
                }
            }
            // cout << list[i][j] << " -> ";
        }
        // cout << endl;
    }
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = cal[i]-1; j >= 0; j--){
            if (list[i][j] > i){
                for (int q = 0; q < n; q++)
                {
                    if (aa[list[i][j]][q] == 1) aa[i][q] = 1;
                }
            }
        }
    }
    // cout <<aa[0][0];
    for (int i = 0; i < n; i++)
    {
        int j;
        // cout << i <<":";
        for (j = 0; j < n; j++){
            // cout << aa[i][j] << " ";
            if (aa[i][j] == 0) break;
        }
        // cout << endl;
        if (j != n)
        {
            check = 0;
            break;
        }
        
    }
    
    

    if (check == 1) cout << 1 << endl;
    else cout << -1 << endl;
}