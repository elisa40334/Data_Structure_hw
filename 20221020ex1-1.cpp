#include<iostream>
#include<string>
using namespace std;
struct poin{
    string c;
    int ri,up,le,down;
};
poin a[10][10];
void f(int x,int y);

int main() {
    
    int x = 8, y = 8;
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++) {
            cin >> a[i][j].c;
            a[x][y].ri = 0;
            a[x][y].le = 0;
            a[x][y].up = 0;
            a[x][y].down = 0;
        }
    }
    cout << "\n\n\n";
    a[1][1].c = "X"; a[8][8].c = "S";
    f(8, 8);
    if (a[0][1].c == "G" || a[2][1].c == "G" || a[1][0].c == "G" || a[1][2].c == "G")
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++) {
            cout << a[i][j].c;
            if (j != 10-1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    
}


void f(int x,int y){
    int cal = 0;
    cout << a[x][y - 1].c << "::" << y << endl;
    if (x != 8 && y != 8)
    {
        a[x][y].c = "G";
    }
    
    if ((a[x+1][y].c == "0") || (a[x+1][y].c == "X"))
    {
        f(x+1,y);
        if (a[x+1][y].c == "X")
        {
            return;
        }
        
        else if (a[x+1][y].c == "D")
        {
            f(x,y);
        }

    }
    else if((a[x][y - 1].c == "0") || (a[x][y-1].c == "X")) {
        //cout << x << "::" << y << endl;
        f(x,y-1);
        cout << x << "::" << y << endl;
        if (a[x][y-1].c == "X")
        {
            return;
        }
        
        else if (a[x][y - 1].c == "D")
        {
            f(x,y);
        }
    }
    
    else if((a[x-1][y].c == "0") || (a[x-1][y].c == "X")){
        f(x-1,y);
        if (a[x-1][y].c == "X")
        {
            return;
        }
        
        else if (a[x-1][y].c == "D")
        {
            f(x,y);
        }
    }
    else if ((a[x][y + 1].c == "0") || (a[x][y+1].c == "X"))
    {
        f(x,y+1);
        if (a[x][y+1].c == "X")
        {
            return;
        }
        
        else if (a[x][y + 1].c == "D")
        {
            f(x,y);
        }
    }
    cout << x << "::" << y  << "cal" << cal << endl;
    if(a[x][y - 1].c == "G" || a[x][y - 1].c == "0"){
       cal++;
    }
    if(a[x][y + 1].c == "G" || a[x][y + 1].c == "0"){
       cal++;
    }
    if(a[x+1][y].c == "G" || a[x+1][y].c == "0"){
       cal++;
    }
    if(a[x-1][y].c == "G" || a[x-1][y].c == "0"){
       cal++;
    }
    if (cal == 2)
    {
        return;
    }
    
    a[x][y].c = "D";
    return;
}
