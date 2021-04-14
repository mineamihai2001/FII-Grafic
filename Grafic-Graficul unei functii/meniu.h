#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <graphics.h>
#include <cmath>
#include <cstring>
#include <stdio.h>
#define MAX_LUNGIME 100
#define MAX_CUVANT 10
#define scale 1.5

void citesteSir(char s[MAX_LUNGIME],int x, int y);
double Calculeaza(double val1,double val2,char operatie);
void meniu(stiva expresie);
void informatii(stiva expresie, char limbaButon);
void desenInterfata(stiva expresie);
void inapoi(stiva expresie);

char A[101], B[101];//capetele intervalelor
char limbaButon='R';//memoreaza limba selectata
char functie[MAX_LUNGIME];

void meniu(stiva expresie)
{
    bool limba=0;//verifica daca e deschis meniul de limbi
    bool gata=false;
    int x,y;
    readimagefile("./images/bckground.jpg", 0, 0, 800, 600);

    if(limbaButon=='R')//deschide meniul in functie de limba aleasa
    {
        readimagefile("./images/buton.jpg", 300, 150, 500, 225);
        readimagefile("./images/romania.jpg", 700, 15, 775, 50);
        readimagefile("./images/informatii.jpg", 315, 245, 485, 310);
        readimagefile("./images/iesire.jpg", 315, 330, 485, 385);
    }
    else if(limbaButon=='E')
    {
        readimagefile("./images/butonen.jpg", 300, 150, 500, 225);
        readimagefile("./images/romania.jpg", 700, 15, 775, 50);
        readimagefile("./images/about.jpg", 315, 245, 485, 310);
        readimagefile("./images/exit.jpg", 315, 330, 485, 385);
    }
    else if(limbaButon=='D')
    {
        readimagefile("./images/butonde.jpg", 300, 150, 500, 225);
        readimagefile("./images/romania.jpg", 700, 15, 775, 50);
        readimagefile("./images/info.jpg", 315, 245, 485, 310);
        readimagefile("./images/ausfahrt.jpg", 315, 330, 485, 385);
    }
    else if(limbaButon=='F')
    {
        readimagefile("./images/butonfr.jpg", 300, 150, 500, 225);
        readimagefile("./images/romania.jpg", 700, 15, 775, 50);
        readimagefile("./images/apropos.jpg", 315, 245, 485, 310);
        readimagefile("./images/sortie.jpg", 315, 330, 485, 385);
    }

    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();

            if(x>=315 && x<=485 && y>=330 && y<=385)//butonul de IESIRE
            {
                exit(0);
                closegraph();
            }
            else if ((x>=300 && x<=500 && y>=150&&y<=225))//butonul de CALCULATOR GRAFIC
            {
                cleardevice();
                desenInterfata(expresie);
                gata=true;
            }
            else if((x>=700 && x<=775 && y>=15&&y<=50))//deschidere meniu de limbi
            {
                readimagefile("./images/buton.jpg", 300, 150, 500, 225);
                readimagefile("./images/usa.jpg", 700, 65, 775, 100);
                readimagefile("./images/germana.jpg", 700, 115, 775, 150);
                readimagefile("./images/franceza.jpg", 700, 165, 775, 200);
                readimagefile("./images/informatii.jpg", 315, 245, 485, 310);
                readimagefile("./images/iesire.jpg", 315, 330, 485, 385);
                limba=1;
                limbaButon='R';
            }
            else if(x>=315 && x<=485 && y>=245 && y<=310)//butonul de INFORMATII
            {
                gata=true;
                informatii(expresie, limbaButon);
            }
            else if(limba=1)//verifica daca e deschis meniul de limbi si in caz ca da selecteaza limba
            {
                if(x>=700 && x<=775 && y>=15&&y<=50)
                {
                    readimagefile("./images/buton.jpg", 300, 150, 500, 225);
                    readimagefile("./images/informatii.jpg", 315, 245, 485, 310);
                    readimagefile("./images/iesire.jpg", 315, 330, 485, 385);
                    limbaButon='R';
                }
                else if(x>=700 && x<=775 && y>=65&&y<=100)
                {
                    readimagefile("./images/butonen.jpg", 300, 150, 500, 225);
                    readimagefile("./images/about.jpg", 315, 245, 485, 310);
                    readimagefile("./images/exit.jpg", 315, 330, 485, 385);
                    limbaButon='E';
                }
                else if(x>=700 && x<=775 && y>=115&&y<=150)
                {
                    readimagefile("./images/butonde.jpg", 300, 150, 500, 225);
                    readimagefile("./images/info.jpg", 315, 245, 485, 310);
                    readimagefile("./images/ausfahrt.jpg", 315, 330, 485, 385);
                    limbaButon='D';
                }
                else if(x>=700 && x<=775 && y>=165&&y<=200)
                {
                    readimagefile("./images/butonfr.jpg", 300, 150, 500, 225);
                    readimagefile("./images/apropos.jpg", 315, 245, 485, 310);
                    readimagefile("./images/sortie.jpg", 315, 330, 485, 385);
                    limbaButon='F';
                }
            }

        }
    }
    while (!gata);

}

void informatii(stiva expresie, char limbaButon)
{
    setbkcolor(WHITE);
    setcolor(BLACK);
    if(limbaButon=='R')
    {
        cleardevice();
        readimagefile("./images/grid01.jpg", 0, 0, 800, 600);
        readimagefile("./images/chenar-titlu-01.jpg", 0, 0, 800, 40);
        //outtextxy(400, 300, "pagina_indisponibila");
        outtextxy(150, 200, "Plecand de la expresia unei functii, data sub forma de sir de caractere, ");
        outtextxy(175, 225, "programul reprezinta graficul functiei pe un anumit interval.");
        outtextxy(250, 275, "Proiect realizat si prezentat de: ");
        outtextxy(250, 300, "- Ivan Remus");
        outtextxy(250, 325, "- Minea Mihai");
    }
    if(limbaButon=='E')
    {
        cleardevice();
        readimagefile("./images/grid01.jpg", 0, 0, 800, 600);
        readimagefile("./images/chenar-titlu-01.jpg", 0, 0, 800, 40);
        //outtextxy(400, 300, "not_found");
        outtextxy(175, 200, "Starting from the expression of a function, given as a string, ");
        outtextxy(150, 225, "the program represents the graph of the function on a certain interval.");
        outtextxy(250, 275, "Project made and presented by: ");
        outtextxy(250, 300, "- Ivan Remus");
        outtextxy(250, 325, "- Minea Mihai");

    }
    if(limbaButon=='D')
    {
        cleardevice();
        readimagefile("./images/grid01.jpg", 0, 0, 800, 600);
        readimagefile("./images/chenar-titlu-01.jpg", 0, 0, 800, 40);
        //outtextxy(400, 300, "nicht gefunden");
        outtextxy(175, 200, "Ausgehend vom Ausdruck einer Funktion in Form einer Zeichenfolge, ");
        outtextxy(150, 225, "Das Programm repr�sentiert den Graphen der Funktion in einem bestimmten Intervall.");
        outtextxy(250, 275, "Projekt realisiert und pr�sentiert von:");
        outtextxy(250, 300, "- Ivan Remus");
        outtextxy(250, 325, "- Minea Mihai");

    }
    if(limbaButon=='F')
    {
        cleardevice();
        readimagefile("./images/grid01.jpg", 0, 0, 800, 600);
        readimagefile("./images/chenar-titlu-01.jpg", 0, 0, 800, 40);
        //outtextxy(400, 300, "pas trouv�");
        outtextxy(150, 200, "� partir de l'expression d'une fonction, donn�e sous forme de cha�ne,");
        outtextxy(175, 225, "le programme repr�sente le graphique de la fonction sur un certain intervalle.");
        outtextxy(250, 275, "Projet r�alis� et pr�sent� par: ");
        outtextxy(250, 300, "- Ivan Remus");
        outtextxy(250, 325, "- Minea Mihai");

    }
    inapoi(expresie);

}

void inapoi(stiva expresie)
{
    bool gata=false;
    int x,y;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            if ((x>=0 && x<=200 && y>=0&&y<=40))
            {
                gata=true;
                meniu(expresie);
            }
        }
    }
    while (!gata);
}

void citesteSir(char s[MAX_LUNGIME],int x, int y)
{
    setbkcolor(WHITE);
    strcpy(s,"");
    char s1[MAX_LUNGIME]= {0};
    char t[2];
    char tasta;
    t[0]=tasta;
    t[1]='\0';

    strcpy(t, "");
    strcpy(s,t);
    strcpy(s1,s);
    strcat(s1,"_");
    setcolor(BLACK);//
    outtextxy(x,y,s1);
    do
    {
        tasta=getch();
        if (tasta==8) // backspace
            if (strlen(s)>0)
            {
                setcolor(WHITE);
                strcpy(s1,s);
                strcat(s1,"_");
                outtextxy(x,y,s1);
                s[strlen(s)-1]='\0';
                strcpy(s1,s);
                strcat(s1,"_");
                outtextxy(x,y,s1);
                setcolor(BLACK);//
                outtextxy(x,y,s1);
            }
            else
                Beep(1000,100);
        else
        {
            t[0]=tasta;
            t[1]='\0';
            strcat(s,t);
            strcpy(s1,s);
            strcat(s1,"_");
            setcolor(BLACK);//
            outtextxy(x,y,s1);
        }
    }
    while (tasta!=13);
    strcpy(t, "");
    strcat(s,t);
    strcpy(s1,s);

    setcolor(BLACK);//
    s1[strlen(s1)-1]='\0';
    outtextxy(x,y,s1);
    strcpy(s, s1);

}

void desenInterfata(stiva expresie)
{
    long a, b;
    bool gata=false;
    int x, y;
    char copieFunctie[MAX_LUNGIME]={0};
    readimagefile("./images/grid01.jpg", 0, 0, 800, 600);
    readimagefile("./images/chenar-titlu-01.jpg", 0, 0, 800, 40);
    readimagefile("./images/functie-01.jpg", 575, 85, 625, 120);
    setbkcolor(WHITE);
    setcolor(BLACK);
    line(560, 40, 560, 600);
    line(0, 40, 800, 40);
    DesenareAxeDeCoordonate(expresie, 0, 560, 40, 600, -10, 10, 30);

    outtextxy(575, 150, "a=");
    outtextxy(575, 180, "b=");

    stiva S;
    InitializareStiva(S);
    InitializareStiva(expresie);

    citesteSir(functie, 630, 95);

    citesteSir(A, 600, 150);
    a=SirInNumar(A);
    citesteSir(B, 600, 180);
    b=SirInNumar(B);

    strcpy(copieFunctie, functie);
    SpatiereSir(functie);
    ExtragereCuvinte(functie,S);
    AflareExpresiePostfixata(S,expresie);

    if(a>=-500 && a<=500 && b>=-500 && b<=500 && a<b)//verifica daca intervalul e introdus corect
    {
        cleardevice();
        readimagefile("./images/chenar-titlu-01.jpg", 0, 0, 800, 40);
        readimagefile("./images/functie-01.jpg", 575, 85, 625, 120);
        line(560, 40, 560, 600);
        line(0, 40, 800, 40);
        outtextxy(630, 95, copieFunctie);
        outtextxy(575, 150, "a=");
        outtextxy(575, 180, "b=");
        outtextxy(600, 150, A);
        outtextxy(600, 180, B);
        ReprezentareGrafic(expresie,a,b);
        readimagefile("./images/zoom.jpg", 695, 405, 775, 525);
        readimagefile("./images/reload.jpg", 695, 525, 775, 585);

        do
        {
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                clearmouseclick(WM_LBUTTONDOWN);
                x=mousex();
                y=mousey();
                if ((x>=695 && x<=775 && y>=525 && y<=585))//butonul de reload
                {
                    gata=true;
                    esteBuna=true;
                }
                else if ((x>=0 && x<=200 && y>=0 && y<=40))//butonul GRAFIC.H (butonul de inapoi)
                {
                    gata=true;
                    esteBuna=true;
                    meniu(expresie);

                }
                else if ((x>=695 && x<=775 && y>=405 && y<=464))
                {
                    if(b>1)//butonul de zoom in
                    {
                        a=a/scale;
                        b=b/scale;
                        readimagefile("./images/grid01.jpg", 0, 40, 800, 600);

                        setcolor(BLACK);
                        readimagefile("./images/functie-01.jpg", 575, 85, 625, 120);
                        line(560, 40, 560, 600);
                        line(0, 40, 800, 40);
                        outtextxy(630, 95, copieFunctie);
                        outtextxy(575, 150, "a=");
                        outtextxy(575, 180, "b=");
                        outtextxy(600, 150, A);
                        outtextxy(600, 180, B);
                        setcolor(3);

                        ReprezentareGrafic(expresie,a,b);
                        readimagefile("./images/zoom.jpg", 695, 405, 775, 525);
                        readimagefile("./images/reload.jpg", 695, 525, 775, 585);
                    }

                }
                else if ((x>=695 && x<=775 && y>=465 && y<=525))
                {
                    if(b<=1)//cazul in care a sau b ajung 0
                    {
                        b=2;
                        a=-2;
                        readimagefile("./images/grid01.jpg", 0, 40, 800, 600);
                        setcolor(BLACK);
                        readimagefile("./images/functie-01.jpg", 575, 85, 625, 120);
                        line(560, 40, 560, 600);
                        line(0, 40, 800, 40);
                        outtextxy(630, 95, copieFunctie);
                        outtextxy(575, 150, "a=");
                        outtextxy(575, 180, "b=");
                        outtextxy(600, 150, A);
                        outtextxy(600, 180, B);
                        setcolor(3);
                        ReprezentareGrafic(expresie,a,b);
                        readimagefile("./images/zoom.jpg", 695, 405, 775, 525);
                        readimagefile("./images/reload.jpg", 695, 525, 775, 585);
                    }
                    else if(b<=1000)//butonul de zoom out
                    {
                        a=a*scale;
                        b=b*scale;
                        readimagefile("./images/grid01.jpg", 0, 40, 800, 600);
                        setcolor(BLACK);
                        readimagefile("./images/functie-01.jpg", 575, 85, 625, 120);
                        line(560, 40, 560, 600);
                        line(0, 40, 800, 40);
                        outtextxy(630, 95, copieFunctie);
                        outtextxy(575, 150, "a=");
                        outtextxy(575, 180, "b=");
                        outtextxy(600, 150, A);
                        outtextxy(600, 180, B);
                        setcolor(3);
                        ReprezentareGrafic(expresie,a,b);
                        readimagefile("./images/zoom.jpg", 695, 405, 775, 525);
                        readimagefile("./images/reload.jpg", 695, 525, 775, 585);
                    }
                }
            }
        }
        while (!gata);
        if(gata==true)
        {
            cleardevice();
            desenInterfata(expresie);
        }
    }
    else
    {
        settextstyle(0, 0, 3);
        setcolor(RED);
        if(limbaButon=='R')
        {
            outtextxy(75, 250, "INTERVALUL NU ESTE VALID:");
            //outtextxy(5, 275, "INTRODUCE-TI UN INTERVAL SIMETRIC");
        }
        else if(limbaButon=='E')
        {
            outtextxy(150, 250, "INVALID INTERVAL:");
            //outtextxy(80, 275, "ENTER A SYMMETRICAL INTERVAL");
        }
        else if(limbaButon=='D')
        {
            settextstyle(0, 0, 2);
            outtextxy(150, 250, "INTERVALL IST NICHT G�LTIG:");
            //outtextxy(80, 275, "EINGEBEN EINES SYMMETRISCHEN INTERVALLS");
            settextstyle(0, 0, 3);
        }
        else if(limbaButon=='F')
        {
            outtextxy(75, 250, "L'INTERVALLE N'EST PAS VALIDE:");
            //outtextxy(5, 275, "ENTREZ UN INTERVALLE SYM�TRIQUE");
        }
        setcolor(BLACK);
        settextstyle(0, 0, 0);
        readimagefile("reload.jpg", 695, 525, 775, 585);

        do//refacerea interfatei pt cazul in care e gresit intervalul
        {
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                clearmouseclick(WM_LBUTTONDOWN);
                x=mousex();
                y=mousey();
                if(x>=695 && x<=775 && y>=525 && y<=585)//butonul de reload
                {
                    gata=true;
                    desenInterfata(expresie);
                }
                else if ((x>=0 && x<=200 && y>=0&&y<=40))//butonul de inapoi
                {
                    gata=true;
                    esteBuna=true;
                    meniu(expresie);

                }
            }
        }
        while(!gata);
    }
}
