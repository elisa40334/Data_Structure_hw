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
void mulpoly(int starta,int enda,int startb,int endb,int startc,int endc,poly p[]);

int main(){
    poly p[1001];
    int cal = 0,starta = 0,enda,startb,endb,startc,endc;
    while (cin >> p[cal].coef)
    {
        if (p[cal].coef == -1) break;
        cin >> p[cal++].expon;
    }
    enda = cal-1;
    for (int i = starta; i <= enda; i++)
    {
        for (int j = i+1; j <= enda; j++){
            if (p[i].expon < p[j].expon)
            {
                poly temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    startb = cal;
    while (cin >> p[cal].coef)
    {
        if (p[cal].coef == -1) break;
        cin >> p[cal++].expon;
    }
    endb = cal-1;
    for (int i = startb; i <= endb; i++)
    {
        for (int j = i+1; j <= endb; j++){
            if (p[i].expon < p[j].expon)
            {
                poly temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    startc = cal;
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
    for (int i = endb; p[i].expon < p[enda].expon; i--) p[cal++] = p[i];
    endc = cal-1;
    for (int i = startc; i <= endc; i++)
    {
        for (int j = i+1; j <= endc; j++){
            if (p[i].expon < p[j].expon)
            {
                poly temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    cout << "add = ";
    printpoly(startc,endc,p);
    mulpoly(starta,enda,startb,endb,startc,endc,p);
}

void printpoly(int start,int end,poly p[]){
    for (int i = start; i <= end; i++)
    {
        if(i != start && p[i].coef > 0) cout << " + ";
        if(p[i].expon == 0) cout <<  p[i].coef;
        else if(p[i].expon == 1) cout << p[i].coef << "x";
        else cout <<  p[i].coef << "x^" << p[i].expon;
    }
    cout  << endl;
}

void mulpoly(int starta,int enda,int startb,int endb,int startc,int endc,poly p[]){
    int cal = endc+1,startd = cal,endd,starte,ende;
    for (int i = starta; i <= enda; i++){
        for (int j = startb; j <= endb; j++){
            p[cal].coef = p[i].coef * p[j].coef;
            p[cal++].expon = p[i].expon + p[j].expon;
        }
    }
    endd = cal-1;
    starte = cal;
    for (int i = startd; i <= endd; i++){
        for (int j = i+1; j <= endd; j++){
            if (p[i].expon == p[j].expon)
            {
                p[i].coef = p[i].coef + p[j].coef;
                p[i].expon = p[i].expon;
                p[j].coef = 0;
            }
        }
    }
    for (int i = startd; i <= endd; i++){
        if (p[i].coef != 0)
        {
            p[cal].coef = p[i].coef;
            p[cal++].expon = p[i].expon;
        }
        
    }
    ende = cal-1;
    for (int i = starte; i <= ende; i++)
    {
        for (int j = i+1; j <= ende; j++){
            if (p[i].expon < p[j].expon)
            {
                poly temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    cout << "mult = ";
    printpoly(starte,ende,p);
}