#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int v[52]={0};
int x,tip,val,cr,s,f, g, j1_val, j2_val;
char ctip[4][15]={"Inima rosie","Inima Neagra","Trefla","Romb"};
char cval[15][15]={" ","Unu","Doi","Trei","Patru","Cinci","Sase","Sapte","Opt","Noua","Zece"," ","Juvete","Dama","Rege"};

void generare_carti()
{
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
        }
    }
}

void tragere_carti(){
    srand(time(NULL));
    generare_carti();
    cout << "Jucator1:" << '\n';
    int x = rand() % 15;
    int y = rand() % 4;
    cout << cval[x] << " de " << ctip[y] << '\n';
    int a = rand() % 15;
    int b = rand() % 4;
    cout << cval[a] << " de " << ctip[b] << '\n';

    if (x > 10)
        x = 10;
    if (a > 10)
        a = 10;
    s = x + a;
    if (s > 9){
        s = s - 10;
    }
    int j1_val = s;
    cout << "Valoare carti j1: " << j1_val << endl << endl;

    cout << "Jucator2:" << '\n';
    x = rand() % 15;
    y = rand() % 4;
    cout << cval[x] << " de " << ctip[y] << '\n';
    a = rand() % 15;
    b = rand() % 4;
    cout << cval[a] << " de " << ctip[b] << '\n';
    if (x > 10)
        x = 10;
    if (a > 10)
        a = 10;
    s = x + a;
    if (s > 9){
        s = s - 10;
    }
    int j2_val = s;
    cout << "Valoare carti j2: " << j2_val << endl << endl;
    int f = 9 - j1_val;
    int g = 9 - j2_val;

}

int main()
{
    srand(time(NULL));
    /*generare_carti();
    cout << "Jucator1:" << '\n';
    int x = rand() % 15;
    int y = rand() % 4;
    cout << cval[x] << " de " << ctip[y] << '\n';
    int a = rand() % 15;
    int b = rand() % 4;
    cout << cval[a] << " de " << ctip[b] << '\n';

    if (x > 10)
        x = 10;
    if (a > 10)
        a = 10;
    s = x + a;
    if (s > 9){
        s = s - 10;
    }
    int j1_val = s;
    cout << "Valoare carti j1: " << j1_val << endl << endl;

    cout << "Jucator2:" << '\n';
    x = rand() % 15;
    y = rand() % 4;
    cout << cval[x] << " de " << ctip[y] << '\n';
    a = rand() % 15;
    b = rand() % 4;
    cout << cval[a] << " de " << ctip[b] << '\n';
    if (x > 10)
        x = 10;
    if (a > 10)
        a = 10;
    s = x + a;
    if (s > 9){
        s = s - 10;
    }
    int j2_val = s;
    cout << "Valoare carti j2: " << j2_val << endl << endl;*/
    //int f = 9 - j1_val;
    //int g = 9 - j2_val;
    tragere_carti();
    if (f == g){
        cout << "Egalitate";
    }
    else if (j1_val == 9){
        cout << "Jucatorul unu castiga";
    }
    else if (j2_val == 9 ){
        cout << "Jucatorul al doilea castiga";
    }
    if (f < g)
        cout << "Jucatorul unu castiga";
    else if (f > g)
        cout << "Jucatorul al doilea castiga";

    return 0;
}
