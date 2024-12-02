#include<iostream>
#include <iomanip>
using namespace std;
struct poly
{
    int expon;
    float coef;
};
void f(poly p[],int starta,int enda,int startb,int endb);
void printpoly(int start,int end,poly p[]);

int main(){
    poly p[101];
    int a,b,cal = 0,starta = 0,enda,startb,endb,startc,endc;
    cin >> a;
    for (int i = 0; i < a; i++) cin >> p[cal].coef >> p[cal++].expon;
    enda = cal-1;
    cin >> b;
    startb = cal;
    for (int i = 0; i < b; i++) cin >> p[cal].coef >> p[cal++].expon;
    endb = cal-1;
    printpoly(starta,enda,p);
    printpoly(startb,endb,p);
    if (enda+1 > endb-startb+1) f(p,starta,enda,startb,endb);
    else f(p,startb,endb,starta,enda);
}
void f(poly p[],int starta,int enda,int startb,int endb){
    int cal,startc;
    if(endb > enda) {cal = endb+1;startc = endb+1;}
    else {cal = enda+1;startc = enda+1;}
    for (int i = startb; p[i].expon > p[starta].expon; i++){
        p[cal].coef = p[i].coef;
        p[cal++].expon = p[i].expon;
    }
    for (int i = starta; i <= enda; i++)
    {
        int check = 0;
        for (int j = startb; j <= endb; j++)
        {
            if (p[i].expon == p[j].expon)
            {
                if ((p[i].coef+p[j].coef) != 0)
                {
                    p[cal].coef = p[i].coef+p[j].coef;
                    p[cal++].expon = p[i].expon;
                }
            }
            else check++;
        }
        if (check == endb-startb+1)
        {
            p[cal].coef = p[i].coef;
            p[cal++].expon = p[i].expon;
        }
    }
    printpoly(startc,cal-1,p);
}
void printpoly(int start,int end,poly p[]){
    for (int i = start; i <= end; i++)
    {
        if (i != start && p[i].coef > 0) cout << "+";
        if (p[i].expon > 1) cout << fixed << setprecision(2) << p[i].coef << "x^" << p[i].expon;
        else if(p[i].expon == 1) cout << fixed << setprecision(2) << p[i].coef << "x";
        else if(p[i].coef != 0) cout << fixed << setprecision(2) << p[i].coef;
        if(i == end) cout << endl;
    }
}