#include<iostream>
using namespace std;

int main(){
    int n,a,check = 1,list[101][101] = {},cal[101] = {};
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
        cout << i << ": ";
        int aa[101] = {};
        aa[i] = 1;
        for (int j = 0; j < cal[i]; j++)
        {
            aa[list[i][j]] = 1;
            cout << list[i][j] << " -> ";
        }
        // cout << "end\n";
        for (int j = 0; j < n; j++)
        {
            if (aa[j] != 1) {
                // cout << j << "\n";
                check = 0;
            }
            // else{
            //     cout << j;
            // }
        }
        cout << endl;
    }

    if (check == 1) cout << 1 << endl;
    else cout << -1 << endl;
    
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (i == j && a[i][j] != 0)
    //         {
    //             check = 0;
    //             break;
    //         }
            
    //         if(i != j && a[i][j] != 1)
    //         {
    //             check = 0;
    //             break;
    //         } 
    //     }
    //     if (check == 0)
    //     {
    //         cout << -1 << endl;
    //         break;
    //     }
    // }
}