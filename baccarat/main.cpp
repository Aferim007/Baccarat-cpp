#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int v[52]={0};
    int x,tip,val,cr;
    char ctip[4][15]={"Inima rosie","Inima Neagra","Trefla","Romb"};
    char cval[15][15]={" ","Unu","Doi","Trei","Patru","Cinci","Sase","Sapte","Opt","Noua","Zece"," ","Juvete","Dama","Rege"};
    cr=52;
    while(cr>0){
        x=rand()%52;
        if(v[x]==0){
            v[x]=1;
            cr--;
            tip=x/13;
            val=x%13+1;
            if(val>10){
                val++;
            }
            cout<<cval[val]<<" de "<<ctip[tip]<<'\n';
        }
    }
    return 0;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
