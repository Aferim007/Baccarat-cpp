#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <time.h>
 
using namespace std;
 
int v[52] = {0};
int z, tip, val, cr, x, y, a, b, f, g, s, k, j1_val, j2_val, bal = 1000, par;
string nume;
char ctip[4][14] = {"Inima rosie","Inima Neagra","Trefla","Romb"};
char cval[14][14] = {" ","Unu","Doi","Trei","Patru","Cinci","Sase","Sapte","Opt","Noua","Zece","Juvete","Dama","Rege"};
 
void generare_carti()
{
    cr = 52;
    while (cr > 0){
        z = rand() % 52;
        if(v[z] == 0){
            v[z] = 1;
            cr--;
            tip = z / 13;
            val = z % 13 + 1;
        }
    }
}
 
void joc(){
    k = 0;
    cout << "                                                                              Balanta: " << bal << " de lei" << endl;
    cout << "Cat doriti sa pariati?" << endl;
    cin >> par;
    while(par > bal){
        cout << "NU poti sa pariezi mai multi bani decat ai, incearca sa pariezi mai putin." << endl;
        cin >> par;
    }
    cout << nume << ":" << endl;
    x = 1 + rand() % 13;
    y = rand() % 4;
    cout <<  "-" << cval[x] << " de " << ctip[y] << '\n';
    a = 1 + rand() % 13;
    b = rand() % 4;
    cout <<  "-" << cval[a] << " de " << ctip[b] << '\n';
    if (x > 10)
        x = 10;
    if (a > 10)
        a = 10;
    s = x + a;
    if (s > 9){
        s = s - 10;
    }
     if (s == 20){
        s = 0;
    }
    int j1_val = s;
    cout << "Valoare cartilor tale: " << j1_val << endl << endl;
 
    cout << "Bancher:" << '\n';
    x = 1 + rand() % 13;
    y = rand() % 4;
    cout << "-" << cval[x] << " de " << ctip[y] << '\n';
    a = 1 + rand() % 13;
    b = rand() % 4;
    cout <<  "-" << cval[a] << " de " << ctip[b] << '\n';
    if (x > 10)
        x = 10;
    if (a > 10)
        a = 10;
    s = x + a;
    if (s > 9){
        s = s - 10;
    }
    if (s == 20){
        s = 0;
    }
    int j2_val = s;
    cout << "Valoare cartilor bancherului: " << j2_val << endl << endl;
 
    if (j1_val == j2_val){
        joc();
    }
    else if (j1_val == 9){
        cout << "AI CASTIGAT! :)" << " Primesti " << par * 3 << " de lei" << endl;
        bal = bal + par * 3;
        k++;
    }
    else if (j2_val == 9 ){
        cout << "AI PIERDUT! :(" << " Pierzi " << par << " de lei" << endl;
        bal = bal - par;
        k++;
    }
    f = 9 - j1_val;
    g = 9 - j2_val;
    if (f < g && k == 0) {
        cout << "AI CASTIGAT! :)" << " Primesti " << par * 2 << " de lei" << endl;
        bal = bal + par * 2;
    }
    else if (f > g && k == 0){
        cout << "AI PIERDUT! :(" << " Pierzi " << par << " de lei" << endl;
        bal = bal - par;
    }
}
 
int main()
{
    srand(time(NULL));
    generare_carti();
    cout << "Alege-ti numele: ";
    cin >> nume;
    char again;
    do{
        joc();
        if (bal < 0){
            cout << "Ai pierdut toti banii la pariuri..";
                return 0;
        }
        cout << "Vrei sa mai joci o runda? (d/n): ";
        cin >> again;
    }while (again == 'd');
 
    return 0;
}
