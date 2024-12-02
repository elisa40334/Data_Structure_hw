#include<iostream>
using namespace std;
struct people
{
    int data, check;
    people* link;
};
void findfriend(people *rela[], int n);
int maxx = 0,cal = 0;

int main() {
    int total, m, n, a, b;
    people *rela[10000];
    cin >> total;
    for (int j = 0; j < total; j++)
    {
        maxx = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            rela[i] = new people();
            rela[i]->data = 0;
            rela[i]->link = NULL;
        }
        for (int q = 0; q < m; q++)
        {
            cin >> a >> b;
            people *tempa, *tempb;
            tempa = new people();
            tempa->data = a;
            tempa->check = 0;
            tempb = new people();
            tempb->data = b;
            tempb->check = 0;
            if (rela[a]->link == NULL)
            {
                tempb->link = NULL;
                rela[a]->link = tempb;

            }
            else {
                tempb->link = rela[a]->link;
                rela[a]->link = tempb;

            }
            if (rela[b]->link == NULL)
            {
                tempa->link = NULL;
                rela[b]->link = tempa;

            }
            else {
                tempa->link = rela[b]->link;
                rela[b]->link = tempa;
            }
        }
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << i << ":";
        //     for (people *j = rela[i]->link; j != NULL; j = j->link)
        //     {
        //         cout << j->data << "!!";
        //     }
        //     cout << endl;
        // }
        for (int i = 1; i <= n; i++){
            if (rela[i]->check == 0)
            {
                cal = 0;
                // cout <<"start" << endl;
                findfriend(rela, i);
            }
        }
        cout << maxx << endl;
    }
}

void findfriend(people *rela[], int n) {
    rela[n]->check = 1;
    cal++;
    // cout << n << ":: " << cal << endl;
    for (people *j = rela[n]->link; j != NULL; j = j->link)
    {
        if (rela[j->data]->check == 0)
        {
            findfriend(rela, j->data);
        }
    }
    if (cal > maxx) maxx = cal;
    return;
}