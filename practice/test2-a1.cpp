#include<iostream>
#include<iomanip>
using namespace std;
struct poly
{
    float coef;
    int expon;
};
void addpoly(int starta,int enda,int startb,int endb,int startc,int endc,poly p[]);
void printpoly(int start,int end,poly p[]);

int main(){
    poly p[101];
    int a,b,cal = 0,starta = 0,enda,startb,endb,startc,endc;
    cin >> a;
    for (int i = 0; i < a; i++) cin >> p[cal].coef >> p[cal++].expon;
    enda = cal-1;
    startb = cal;
    cin >> b;
    for (int i = 0; i < b; i++) cin >> p[cal].coef >> p[cal++].expon;
    endb = cal-1;
    startc = cal;
    printpoly(starta,enda,p);
    printpoly(startb,endb,p);
    if (enda > endb-startb) addpoly(starta,enda,startb,endb,startc,endc,p);
    else addpoly(startb,endb,starta,enda,startc,endc,p);
}

void addpoly(int starta,int enda,int startb,int endb,int startc,int endc,poly p[]){
    int cal = startc;
    for (int i = startb; p[i].expon > p[starta].expon; i++) p[cal++] = p[i];
    for (int i = starta; i <= enda; i++)
    {
        int check = 0;
        for (int j = startb; j <= endb; j++){
            if (p[i].expon == p[j].expon)
            {
                if ((p[i].coef + p[j].coef) != 0)
                {
                    p[cal].coef = p[i].coef + p[j].coef;
                    p[cal++].expon = p[i].expon;
                }
            }
            else check++;
        }
        if (check == endb-startb+1) p[cal++] = p[i];
    }
    endc = cal-1;
    printpoly(startc,endc,p);
}

void printpoly(int start,int end,poly p[]){
    for (int i = start; i <= end; i++)
    {
        if(i != start && p[i].coef > 0) cout << "+";
        if(p[i].expon == 0) cout << fixed << setprecision(2) << p[i].coef;
        else if(p[i].expon == 1) cout << fixed << setprecision(2) << p[i].coef << "x";
        else cout << fixed << setprecision(2) << p[i].coef << "x^" << p[i].expon;
    }
    cout  << endl;
}