#include<iostream>
using namespace std;
bool Dposi[1000] = {},Bcheck[1000] = {};
int Dcount = 0;
void Depthtree(int n,int list[1000][1000],int cal[],int max);

int main(){
    int a,b,list[1000][1000] = {},cal[1000] = {},max = 0,waitinglist[1000],waitlength = 0;
    while (cin >> a >> b)
    {
        list[a][cal[a]++] = b;
        list[b][cal[b]++] = a;
        if (a > max) max = a;
        if (b > max) max = b;
    }
    // cout << "\nAdjacency list:\n";
    // for (int i = 0; i <= max; i++)
    // {
    //     cout << i << ": ";
    //     for (int j = 0; j < cal[i]; j++)
    //     {
    //         cout << list[i][j] << " -> ";
    //     }
    //     cout << "end\n";
    // }
    cout << "Depth First Search:\n";
    Depthtree(0,list,cal,max);
    cout << "\n\n";

    cout << "Breadth First Search:\n0 ";
    waitinglist[waitlength++] = 0;
    Bcheck[0] = true;
    for (int i = 0; i < waitlength; i++)
    {
        for (int j = 0; j < cal[waitinglist[i]]; j++)
        {
            // cout << list[i][j] << ":" << i << " ";
            if (!Bcheck[list[waitinglist[i]][j]])
            {
                cout << list[waitinglist[i]][j];
                if (waitlength < max) cout << " ";
                waitinglist[waitlength++] = list[waitinglist[i]][j];
                Bcheck[list[waitinglist[i]][j]] = true;
            }
        }
    }
    
    cout << " \n";
}

void Depthtree(int n,int list[1000][1000],int cal[],int max){
    if (Dposi[n]) return;
    Dposi[n] = true;
    Dcount++;
    cout << n;
    if(Dcount <= max) cout << " ";
    for (int i = 0; i < cal[n]; i++)
    {
        Depthtree(list[n][i],list,cal,max);
    }
}

