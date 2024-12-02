#include<iostream>
#include<string>
using namespace std;

struct poin{
    string c;
    int dir;
};
struct stack{
    int x,y,dir;
};
int cal = 0,endd = 0;
stack b[100];
poin a[10][10];
void f(int x,int y,int where);
void checkd();

int main() {
    
    int x = 8, y = 8;
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++) {
            cin >> a[j][i].c;
            b[i*j].dir = 0;
        }
    }
    
    a[1][1].c = "X"; a[8][8].c = "S";
    b[cal].x = 8;
    b[cal].y = 8;
    f(8, 8,0);

    if (a[0][1].c == "G" || a[2][1].c == "G" || a[1][0].c == "G" || a[1][2].c == "G")
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++) {
            cout << a[j][i].c;
            if (j != 10-1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    // for (int i = 0; i <= cal; i++){
    //     cout << b[i].x <<"sd" <<b[i].y<< endl;
    // }
}

void f(int x,int y,int where){

    if (b[cal].dir == 0)
    {
        // cout << x << "::" << y  << "cal" << cal << "dir" << b[cal].dir << endl;
        if (a[x+1][y].c == "0" && endd != 1)
        {
            b[++cal].x = x+1;
            b[cal].y = y;
            a[x+1][y].c = "G";
            f(x+1,y,0);
        }
        else if(a[x+1][y].c  == "X" && endd != 1){
            endd = 1;
            return;
        }
        else if((a[x+1][y].c  == "D" || a[x+1][y].c  == "1") && endd != 1)
        {
            b[cal].dir++;
            f(x,y,0);
        }
        else if ((a[x+1][y].c  == "G" || a[x+1][y].c  == "S") && endd != 1)
        {
            b[cal].dir++;
            f(x,y,0);
        }
    }
    else if (b[cal].dir == 1)
    {
        // cout << x << "::" << y  << "cal" << cal << "dir" << b[cal].dir << endl;
        if (a[x][y-1].c == "0" && endd != 1)
        {
            b[++cal].x = x;
            b[cal].y = y-1;
            a[x][y-1].c = "G";
            f(x,y-1,0);
        }
        else if(a[x][y-1].c  == "X" && endd != 1){
            endd = 1;
            return;
        }
        else if((a[x][y-1].c  == "D" || a[x][y-1].c  == "1") && endd != 1)
        {
            b[cal].dir++;
            f(x,y,0);
        }
        else if ((a[x][y-1].c  == "G" || a[x][y-1].c  == "S") && endd != 1)
        {
            b[cal].dir++;
            f(x,y,0);
        }
    }
    else if (b[cal].dir == 2)
    {
        // cout << x << "::" << y  << "cal" << cal << "dir" << b[cal].dir << endl;
        // cout << x <<"," << b[cal].y << endl;
        if (a[x-1][y].c == "0" && endd != 1)
        {
            b[++cal].x = x-1;
            b[cal].y = y;
            a[x-1][y].c = "G";
            f(x-1,y,0);
        }
        else if(a[x-1][y].c  == "X" && endd != 1){
            endd = 1;
            return;
        }
        else if((a[x-1][y].c  == "D" || a[x-1][y].c  == "1") && endd != 1)
        {
            b[cal].dir++;
            f(x,y,0);
        }
        else if ((a[x-1][y].c  == "G" || a[x-1][y].c  == "S") && endd != 1)
        {
            b[cal].dir++;
            f(x,y,0);
        }
        
    }
    else if (b[cal].dir == 3)
    {
        // cout << x << "::" << y  << "cal" << cal << "dir" << b[cal].dir << endl;
        if (a[x][y+1].c == "0" && endd != 1)
        {
            b[++cal].x = x;
            b[cal].y = y+1;
            a[x][y+1].c = "G";
            f(x,y+1,0);
        }
        else if(a[x][y+1].c  == "X" && endd != 1){
            endd = 1;
            return;
        }
        else if((a[x][y+1].c  == "D" || a[x][y+1].c  == "1") && endd != 1)
        {
            b[cal].dir++;
            // cout << x << "::" << y  << "cal" << cal << "dir" << b[cal].dir << endl;
            f(x,y,0);
        }
        else if (a[x][y+1].c != "G" && endd != 1)
        {
            f(x,y+1,0);
        }
        
    }

    int around = 0;
    if(a[x][y - 1].c == "1" || a[x][y - 1].c == "D"){
       around++;
    }
    if(a[x][y + 1].c == "1" || a[x][y + 1].c == "D"){
       around++;
    }
    if(a[x+1][y].c == "1" || a[x+1][y].c == "D"){
       around++;
    }
    if(a[x-1][y].c == "1" || a[x-1][y].c == "D"){
       around++;
    }

    // if (a[x][y - 1].c == "X" || a[x][y + 1].c == "X" || a[x-1][y].c == "X" || a[x+1][y].c == "X")
    // {
    //     cout << "lala";
    //     return;
    // }
    

    // cout << "sdasdda"<< x << "::" << y  << "cal" << cal << "dir" << b[cal].dir << endl;

    if (around == 3 && (x!= 8 || y != 8))
    {
        a[x][y].c = "D";
        b[cal].dir = 0;
        cal -= 1;
        f(b[cal].x,b[cal].y,0);
    }
    return;
}

