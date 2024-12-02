#include<iostream>
using namespace std;

int main(){
    int n,a,b,count,list[1001];
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) list[i] = 1;
    int rast = n;

    count = 0;
    for (int i = a; i <= n; i++)
    {
        if (list[i] == 1)
        {
            count += 1;
            // cout << "count" << count << ":" << i << endl;
        }
        if (count == b)
        {
            cout << i << " ";
            list[i] = 0;
            rast -= 1;
            count = 0;
        }
    }

    while (rast != 0)
    {
        // cout << "count" << count;
        for (int i = 1; i <= n; i++)
        {
            if (list[i] == 1)
            {
                count += 1;
                // cout << "count" << count << ":" << i << endl;
            }
            if (count == b)
            {
                cout << i << " ";
                list[i] = 0;
                rast -= 1;
                count = 0;
            }
        }
    }
}