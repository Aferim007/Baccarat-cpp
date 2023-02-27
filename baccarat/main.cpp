#include <graphics.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <time.h>

using namespace std;

ifstream fin ("carti.txt");

int bal = 1000, par, pierdut = 0, r, par_s = 0, j = 0, egal = 0;

struct carte {
    int val, tip;
    char img[30];
    carte *leg;
}*carti;

carte* generare_carti()
{
    int cr = 52, v[52] = {0}, tip, val, x;
    carte *p = NULL, *q;
    while (cr > 0){
        x = rand() % 52;
        if(v[x] == 0){
            v[x] = 1;
            cr--;
            tip = x / 13;
            val = x % 13 + 1;
            if(val > 10)
                val++;
            q = new carte;
            q -> val = val;
            q -> tip = tip;
            q -> leg = p;
            p = q;
        }
    }
    return p;
}

void adimagine (carte *p){
    carte *q;
    int valf, tipf;
    char numeimg[30];
    while (fin >> valf >> tipf){
        fin >> numeimg;
        q = p;
        for (int i = 1; i <= 52; i++){
            if(q -> val == valf && q -> tip == tipf)
                strcpy(q -> img, numeimg);
            else q = q -> leg;
        }
    }
}

stats (){
    cleardevice();
    char stats [100];
    settextstyle (10, 0, 4);
    outtextxy (350, 20, "Statistici");
    settextstyle (9, 0, 2);
    sprintf (stats, "Ai jucat %d runde de Baccarat", j);
    outtextxy (50, 100, stats);
    sprintf (stats, "Runde castigate: %d", r);
    outtextxy (50, 130, stats);
    sprintf (stats, "Runde pierdute: %d", j - r - egal);
    outtextxy (50, 160, stats);
    sprintf (stats, "Balanta finala: %d de lei", bal);
    outtextxy (50, 190, stats);
    sprintf (stats, "Total castig: %d de lei", pierdut + bal - 1000);
    outtextxy (50, 220, stats);
    sprintf (stats, "Total pierdere: %d de lei", pierdut);
    outtextxy (50, 250, stats);
    sprintf (stats, "Total suma pariata: %d de lei", par_s);
    outtextxy (50, 280, stats);
    sprintf (stats, "Runde care s-au terminat la egalitate: %d", egal);
    outtextxy (50, 310, stats);
    settextstyle (1, 0, 3);
    delay (2500);
    outtextxy (50, 600, "Apasa tasta ESCAPE pentru a iesi din joc");
    while (1){
        if (GetKeyState(VK_ESCAPE) & 0x8000)
            return 0;
    }
}

void joc (){
    int maxx = getmaxwidth();
    int maxy = getmaxheight();
    carte *victim;
    POINT poz;
    int k = 0, s1 = 0 , s2 = 0, dif1, dif2, x, y, e = 0;
    char pariu [10], bani [1000000];
    closegraph();
    initwindow (maxx, maxy, "Baccarat");
    setbkcolor(2);
    cleardevice();
    settextstyle(5, 0, 2);
    outtextxy(700,600,"Autori: Turcu Alexandru-Costin");
    outtextxy(770,630,"Soisun Mina-David");
    outtextxy(770,660,"Tirila Briana-Maria");
    outtextxy(700, 195, "Regulile jocului Baccarat:");
    outtextxy(650, 220, "-fiecare jucator primeste cate 2 carti");
    outtextxy(650, 240, "-Juvetele, Regina si Regele valoreaza 10 puncte, iar restul cartilor au valoarea implicita");
    outtextxy(650, 260, "-daca suma cartilor unui jucator depaseste 9 ea scade cu 10 puncte");
    outtextxy(650, 280, "de exemplu daca un jucator are suma cartilor egala cu 15, valoarea reala a cartilor va fi 5");
    outtextxy(650, 300, "-daca un jucator va avea suma cartilor egala cu 10 sau cu 20");
    outtextxy(650, 320, "valoarea reala va fi de 0 puncte, cu alte cuvinte BACCARAT");
    outtextxy(650, 340, "-castiga cel care are valoarea cartilor cea mai apropiata de 9");
    outtextxy(700, 370, "Incasari:");
    outtextxy(650, 390, "-pentru valoarea cartilor egala cu 9 se incaseaza trilplul pariului");
    outtextxy(650, 410, "-pentru orice alt castig se incaseaza dublu");
    settextstyle(6, 0, 2);
    sprintf (bani, "Balanta: %d de lei", bal);
    outtextxy (190, 600, bani);
    settextstyle(9, 0, 2);
    outtextxy(10, 10, "Apasa CLICK in mijlocul jetonului ca sa alegi suma pe care vrei sa o pariezi");
    setfillstyle(1, 8);
    circle(100, 170, 80);
    floodfill(100, 170, WHITE);
    setfillstyle(1, 6);
    circle(300, 170, 80);
    floodfill(300, 170, WHITE);
    setfillstyle(1, 5);
    circle(500, 170, 80);
    floodfill(500, 170, WHITE);
    setfillstyle(1, 1);
    circle(200, 320, 80);
    floodfill(200, 320, WHITE);
    setfillstyle(1, 3);
    circle(400, 320, 80);
    floodfill(400, 320, WHITE);
    setfillstyle(1, 4);
    circle(300, 470, 80);
    floodfill(300, 470, WHITE);
    settextstyle(9, 0, 6);
    setfillstyle(1, 8);
    outtextxy(80, 145, "1");
    floodfill(80, 145, WHITE);
    setfillstyle(1, 6);
    outtextxy(260, 145, "25");
    floodfill(260, 145, WHITE);
    setfillstyle(1, 5);
    outtextxy(460, 145, "50");
    floodfill(460, 145, WHITE);
    setfillstyle(1, 1);
    outtextxy(135, 290, "100");
    floodfill(135, 290, WHITE);
    setfillstyle(1, 3);
    outtextxy(340, 290, "250");
    floodfill(340, 290, WHITE);
    setfillstyle(1, 4);
    outtextxy(235, 445, "500");
    floodfill(235, 445, WHITE);
    par = 0;
    while (par == 0 || par > bal){
    if (GetKeyState(VK_LBUTTON) & 0x8000)
        GetCursorPos (&poz);
        x = poz.x;
        y = poz.y;
    if ((x <= 170 && x >= 40) && (y <= 230 && y >= 110)){
        par = 1;
    }
    if ((x <= 360 && x >= 240) && (y <= 230 && y >=110)){
        par = 25;
    }
    if ((x <= 560 && x >= 440) && (y <= 230 && y >= 110)){
        par = 50;
    }
    if ((x <= 260 && x >= 140) && (y <= 380 && y >= 260)){
        par = 100;
    }
    if ((x <= 460 && x >= 340) && (y <= 380 && y >= 260)){
        par = 250;
    }
    if ((x <= 360 && x >= 240) && (y <= 530 && y >= 410)){
        par = 500;
    }
}
    par_s = par_s + par;
    cleardevice();
    settextstyle (8,0,2);
    sprintf (bani, "Balanta: %d de lei", bal);
    outtextxy (430, 0, bani);
    settextstyle (7,0,1);
    outtext ("Cartile tale:");
    readimagefile (carti -> img, 3, 20, 105, 157);
    if(carti -> val > 10)
        carti -> val = 10;
    s1 = s1 + carti -> val;
    victim = carti;
    carti = carti -> leg;
    delete victim;
    readimagefile (carti -> img, 150, 20, 45, 157);
    if(carti -> val > 10)
        carti -> val = 10;
    s1 = s1 + carti -> val;
    victim = carti;
    carti = carti -> leg;
    delete victim;
    outtextxy (0, 190, "Cartile adversarului:");
    readimagefile (carti -> img, 3, 210, 105, 65);
    if(carti -> val > 10)
        carti -> val = 10;
    s2 = s2 + carti -> val;
    victim = carti;
    carti = carti -> leg;
    delete victim;
    readimagefile (carti -> img, 150, 210, 45, 65);
    if(carti -> val > 10)
        carti -> val = 10;
    s2 = s2 + carti -> val;
    victim = carti;
    carti = carti -> leg;
    delete victim;
    if (s1 == 20){
        s1 = 0;
    }
    if (s2 == 20){
        s2 = 0;
    }
    if (s1 > 9){
        s1 = s1 - 10;
    }
    if (s2 > 9){
        s2 = s2 - 10;
    }
    settextstyle(9, 0, 1);
    e = 0;
    k = 0;
    if (s1 == s2) {
        outtextxy(3, 400, "Egalitate. Apasa tasta SPACE pentru a continua sau tasta ESCAPE pentru a iesi din joc");
        egal++;
        e++;
    }
    if (s1 == 9 && e == 0){
        sprintf (pariu, "AI CASTIGAT! :) Primesti  %d de lei", par * 3);
        outtextxy (3, 400, pariu);
        bal = bal + par * 3;
        k++;
        r++;
        outtextxy(3, 430, "Apasa tasta SPACE pentru a juca din nou sau tasta ESCAPE pentru a iesi din joc");
    }
    if (s2 == 9 && e == 0){
        sprintf (pariu, "Ai pierdut :( Pierzi %d de lei", par);
        outtextxy (3, 400, pariu);
        bal = bal - par;
        pierdut = pierdut + par;
        k++;
        outtextxy(3, 430, "Apasa tasta SPACE pentru a juca din nou sau tasta ESCAPE pentru a iesi din joc");
    }
    dif1 = 9 - s1;
    dif2 = 9 - s2;
    if (dif1 < dif2 && k == 0) {
        sprintf (pariu, "AI CASTIGAT! :) Primesti  %d de lei", par * 2);
        outtextxy (3, 400, pariu);
        bal = bal + par * 2;
        outtextxy(3, 430, "Apasa tasta SPACE pentru a juca din nou sau tasta ESCAPE pentru a iesi din joc");
        r++;
    }
    else if (dif1 > dif2 && k == 0){
        sprintf (pariu, "Ai pierdut :( Pierzi %d de lei", par);
        outtextxy (3, 400, pariu);
        bal = bal - par;
        pierdut = pierdut + par;
        outtextxy(3, 430, "Apasa tasta SPACE pentru a juca din nou sau tasta ESCAPE pentru a iesi din joc");
    }
        j++;
}

int main()
{
    srand(time(NULL));
    carti = generare_carti();
    adimagine(carti);
    while (carti){
        joc();
        if (bal == 0){
            settextstyle(4, 0, 2);
            outtextxy (3, 430, "Ai pierdut toti banii la pariuri.........................................................");
            settextstyle(9, 0, 2);
            outtextxy (3, 460, "Apasa tasta SHIFT pentru a vedea statisticile jocului sau tasta ESCAPE pentru a iesi din joc");
            while (1){
        if (GetKeyState(VK_LSHIFT) & 0x8000)
            stats();
        if (GetKeyState(VK_ESCAPE) & 0x8000)
            return 0;
        }
    }
        if (carti){
        while (1){
        if(GetKeyState(VK_SPACE) & 0x8000)
            break;
        if(GetKeyState(VK_ESCAPE) & 0x8000)
            return 0;
        }
    }
}
    settextstyle(4, 0, 2);
    outtextxy(3, 430, "S-a terminat pachetul de carti.........................................................");
    settextstyle(9, 0, 2);
    outtextxy (3, 460, "Apasa tasta SHIFT pentru a vedea statisticile jocului sau tasta ESCAPE pentru a iesi din joc");
    while (1){
        if (GetKeyState(VK_LSHIFT) & 0x8000)
            stats();
        if (GetKeyState(VK_ESCAPE) & 0x8000)
            return 0;
        }
    return 0;
    getch();
}
