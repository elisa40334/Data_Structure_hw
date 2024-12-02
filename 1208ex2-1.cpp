#include<iostream>
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
        
        aa[i][0] = 1;
        for (int j = 0; j < cal[i]; j++)
        {
            aa[i][list[i][j]] = 1;
            // cout << list[i][j] << " -> ";
        }
        // cout << "end\n";
        
        cout << endl;
    }
    for (int i = 0; i < 0; i++)
    {
        check = f(i,aa,list,n,cal);
    }
    
    

    if (check == 1) cout << 1 << endl;
    else cout << -1 << endl;
    
}

int f(int k,int aa[101][101],int list[101][101],int n,int cal[]){
    
    
    // for (int i = 0; i < n; i++)
    // {
    //     int count = 0;
    //     for (int j = 0; j < cal[i]; j++){
    //         if (aa[i][j] == 1)
    //         {
    //             count++;
    //         }
    //     }
    // }
    // // if (count == 2*n)
    // // {
    // //     return 1;
    // // }
    // // else
    // // {
    // //     for (int i = 0; i < n; i++)
    // //     {
    // //         for (int j = 0; j < cal[i]; j++){

    // //         }
    // //     }
    // // }
    
}