#include<cstdio>
#include<iostream>
#include<iomanip>
using namespace std;
typedef struct
{
	float coef; //係數
	unsigned int expon; //次數
}polynomial;
void lalala(int start, int end, polynomial* p) {
	int cal = start;
	for (int cal = start; cal <= end; cal++)
	{
		if (p[cal].expon == 0 && p[cal].coef != 0)
		{
			if (cal != start && p[cal].coef > 0) cout << "+";
			cout << fixed << setprecision(2) << p[cal].coef;
			
		}
		else if (p[cal].expon == 1 && p[cal].coef != 0)
		{
			if (cal != start && p[cal].coef > 0) cout << "+";
			cout << fixed << setprecision(2) << p[cal].coef << "x";
			
		}
		else if(p[cal].expon != 1  && p[cal].expon != 0  && p[cal].coef != 0)
		{
			if (cal != start && p[cal].coef > 0) cout << "+";
			cout << fixed << setprecision(2) << p[cal].coef << "x^" << p[cal].expon;
			
		}
		
	}
	cout << endl;
}



int main() {
	int n,starta = 0,enda,startb,endb, startc, endc,avail = 0,cala,calb;
	polynomial p[101];
	cin >> n;
	for(int i =  0; i < n;i++)
	{
		cin >> p[avail].coef >> p[avail].expon;
		avail++;
	}
	enda = avail - 1;
	startb = avail;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[avail].coef >> p[avail].expon;
		avail++;
	}
	endb = avail - 1;
	cala = starta; calb = startb;
	startc = avail;
	while (cala != enda+1 && calb != endb+1)
	{
		if (p[cala].expon > p[calb].expon)
		{
			p[avail].expon = p[cala].expon;
			p[avail].coef = p[cala].coef;
			avail++; cala++;
		}
		else if (p[cala].expon < p[calb].expon)
		{
			p[avail].expon = p[calb].expon;
			p[avail].coef = p[calb].coef;
			avail++; calb++;
		}
		else
		{
			p[avail].coef = p[cala].coef + p[calb].coef;
			p[avail].expon = p[cala].expon;
			cala++; calb++; avail++;
		}
	}
	endc = avail-1;
	lalala(starta, enda, p);
	lalala(startb, endb, p);
	lalala(startc, endc, p);
}