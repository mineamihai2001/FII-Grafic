#include <fstream>
#include <cmath>
#include <cstring>
#include <graphics.h>
#include <winbgim.h>
#include <iomanip>

void NumarInSir(tipDate numar,char sir[30]);

void TransformareLiniara(tipDate a,tipDate b,tipDate capat1,tipDate capat2,tipDate &m,tipDate &n);
void ReprezentareGrafic(stiva expresie,tipDate a,tipDate b);
void DesenareAxeDeCoordonate(stiva functie,int stanga,int dreapta,int sus,int jos,tipDate a,tipDate b,int distantaSageata);

void NumarInSir(tipDate numar,char sir[30])
{
    int copie,numarCifre=0,i;
    if(numar<0)
    {
        numar*=-1;
        ++numarCifre;
        sir[0]='-';
    }
    copie=int(numar);
    do
    {
        ++numarCifre;
        copie/=10;
    }
    while(copie);
    sir[numarCifre]=0;
    i=numarCifre;
    copie=int(numar);
    do
    {
        sir[--numarCifre]=copie%10+48;
        copie/=10;
    }
    while(copie);
    copie=int((numar-int(numar))*100);
    if(copie)
    {
        sir[i]='.';
        sir[i+3]=0;
        i+=3;
        while(copie)
        {
            sir[--i]=copie%10+48;
            copie/=10;
        }
    }
}
void TransformareLiniara(tipDate a,tipDate b,tipDate capat1,tipDate capat2,tipDate &m,tipDate &n)
{
    if(a!=b)
        m=(capat1-capat2)/(a-b);
    else
        m=1;
    n=capat1-m*a;
}
void DesenareAxeDeCoordonate(stiva functie,int stanga,int dreapta,int sus,int jos,tipDate a,tipDate b,int distantaSageata)
{
    tipDate m1,m2,n1,n2,x1,x2,y1,y2,valSegment,valPunct1,valPunct2;
    int lungimeSageata=10,lungimeSegmentEcran,nrSegmente,raza=2,i,stangaCopie,dreaptaCopie,josCopie,susCopie;
    char Sir[30];
    stangaCopie=stanga;
    dreaptaCopie=dreapta;
    josCopie=jos;
    susCopie=sus;
    stanga+=distantaSageata;
    dreapta-=distantaSageata;
    jos-=distantaSageata;
    sus+=distantaSageata;
    nrSegmente=10;
    lungimeSegmentEcran=(dreapta-stanga)/nrSegmente;
    valSegment=1.0*(b-a)/nrSegmente;
    TransformareLiniara(a,b,stanga,dreapta,m1,n1);
    TransformareLiniara(a,b,jos,sus,m2,n2);


    /// axa Oy
    ///Grid
    setcolor(7);
    x1=stangaCopie;
    x2=dreaptaCopie;
    y1=y2=n2;

    while(1)
    {
        y1-=lungimeSegmentEcran;
        if(y1<sus)
            break;
        line(x1,y1,x2,y1);
    }
    while(1)
    {
        y2+=lungimeSegmentEcran;
        if(y2>jos)
            break;
        line(x1,y2,x2,y2);
    }
    x1=x2=n1;
    y1=susCopie;
    y2=josCopie;
    while(1)
    {
        x1-=lungimeSegmentEcran;
        if(x1<stanga)
            break;
        line(x1,y1,x1,y2);
    }
    while(1)
    {
        x2+=lungimeSegmentEcran;
        if(x2>dreapta)
            break;
        line(x2,y1,x2,y2);
    }

    if(a<=0&&0<=b)
    {
        ///axa Oy
        x1=x2=n1;
        y1=susCopie;
        y2=josCopie;
        setcolor(BLACK);
        line(x1,y1,x2,y2);
        setcolor(BLACK);
        /// Sageata
        y1=susCopie;
        x1=n1;
        for(i=1; i<=lungimeSageata; ++i)
        {
            line(x1-i,y1+lungimeSageata,x1,y1);
            line(x1+i,y1+lungimeSageata,x1,y1);
        }
        ///Segmente
        x1=x2=n1;
        y1=y2=n2;
        valPunct1=valPunct2=0;
        while(1)
        {
            if(y1-lungimeSegmentEcran<sus)
                break;
            y1-=lungimeSegmentEcran;
            valPunct1+=valSegment;
            circle(x1,y1,raza);
            std::setprecision(2);
            NumarInSir(valPunct1,Sir);
            outtextxy(x1-textwidth(Sir)-raza-4,y1-textheight(Sir)/2,Sir);
            ///posibil bug la conditia asta in cazul in care lungimeEcran e numar real
        }
        while(1)
        {
            if(y2+lungimeSegmentEcran>jos)
                break;
            y2+=lungimeSegmentEcran;
            valPunct2-=valSegment;
            circle(x2,y2,raza);
            std::setprecision(2);
            NumarInSir(valPunct2,Sir);
            outtextxy(x2-textwidth(Sir)-raza-4,y2-textheight(Sir)/2,Sir);
        }

        /// axa Ox
        y1=y2=n2;
        x1=stangaCopie;
        x2=dreaptaCopie;
        line(x1,y1,x2,y2);
        /// Sageata
        for(i=1; i<=lungimeSageata; ++i)
        {
            line(x2-lungimeSageata,y2-i,x2,y2);
            line(x2-lungimeSageata,y2+i,x2,y2);
        }
        ///Segmente

        x1=x2=n1;
        y1=y2=n2;
        valPunct1=valPunct2=0;
        while(1)
        {
            if(x1-lungimeSegmentEcran<stanga)
                break;
            x1-=lungimeSegmentEcran;
            valPunct1-=valSegment;
            circle(x1,y1,raza);
            NumarInSir(valPunct1,Sir);
            outtextxy(x1-textwidth(Sir)/2,y1+raza+4,Sir);
        }
        while(1)
        {
            if(x2+lungimeSegmentEcran>dreapta)
                break;
            x2+=lungimeSegmentEcran;
            valPunct2+=valSegment;
            circle(x2,y2,raza);
            NumarInSir(valPunct2,Sir);
            outtextxy(x2-textwidth(Sir)/2,y2+raza+4,Sir);
        }


        ///Originea
        circle(n1,n2,raza);
        outtextxy(n1-textwidth("0")-4,n2+raza+4,"0");
    }
    else
    {
        ///Margine stanga axa Oy
        setcolor(BLACK);
        x1=stanga;
        y1=jos;
        valPunct1=a;
        NumarInSir(valPunct1,Sir);
        outtextxy(x1-textwidth(Sir)-raza-4,y1-textheight(Sir)/2+4,Sir);
        while(1)
        {
            if(y1-lungimeSegmentEcran<sus)
                break;
            y1-=lungimeSegmentEcran;
            valPunct1+=valSegment;
            circle(x1,y1,raza);
            NumarInSir(valPunct1,Sir);
            outtextxy(x1-textwidth(Sir)-raza+4,y1-textheight(Sir)/2,Sir);
            ///posibil bug la conditia asta in cazul in care lungimeEcran e numar real
        }
        x2=stanga;
        y2=jos;
        valPunct2=a;
        while(1)
        {
            if(x2+lungimeSegmentEcran>dreapta)
                break;
            x2+=lungimeSegmentEcran;
            valPunct2+=valSegment;
            circle(x2,y2,raza);
            NumarInSir(valPunct2,Sir);
            outtextxy(x2-textwidth(Sir)/2,y2+raza+4,Sir);
        }
    }
}
void ReprezentareGrafic(stiva functie,tipDate a,tipDate b)
{
    /*
    Puteri ale lui 0.5
    0.5
    0.25
    0.125
    0.0625
    0.03125
    0.015625
    0.0078125
    0.00390625 ----
    0.001953125
    0.0009765625
    */
    tipDate xCapat,yCapat,yVal,xVal,xVal1,yVal1,yValCurenta,yValPrec,epsilon,m1,n1,m2,n2,stanga,dreapta,sus,jos,distantaCareu=0;
    tipDate x1,y1,m,n,alfa;
    int culoareGrafic,latime,inaltime,distantaSageata;

    distantaSageata=30;
    latime=800;
    inaltime=600;
    culoareGrafic=3; //BLUE
    /*
    stanga=sus=distantaEcran;
    dreapta=latime-distantaEcran;
    jos=inaltime-distantaEcran;
    */
    stanga=0;
    dreapta=latime-240;
    sus=40;
    jos=inaltime;

    //DesenareCareu(stanga,dreapta,sus,jos);

    stanga+=distantaCareu;
    dreapta-=distantaCareu;
    sus+=distantaCareu;
    jos-=distantaCareu;
    DesenareAxeDeCoordonate(functie,stanga,dreapta,sus,jos,a,b,distantaSageata);
    /// * -> functia desenare axe va face in zona pusa graficul functie pe intervalul [a,b]
    ///dar aceasta va face loc si pentru sagetile de la axele Ox si Oy
    stanga+=distantaSageata;
    dreapta-=distantaSageata;
    sus+=distantaSageata;
    jos-=distantaSageata;
    TransformareLiniara(a,b,stanga,dreapta,m1,n1);
    TransformareLiniara(a,b,jos,sus,m2,n2);

    setcolor(culoareGrafic); ///-------------------

    ///Idee de lucru
    ///Idee este de a parcurge functia respectiva si de a alege 2 puncte xVal si xVal+epsilon
    ///si vom considera dreapta formata de acestea cu ajutorul unei ecuatii de gradul intai
    ///de forma y1=m*x1+n ,y2=m*x2+n.In functie de panta acestea(panta se refera si la cresterea
    ///functiei pe Oy in raport cu cresterea pe Ox).Daca abs(m) <1,atunci aceasta este mai apropiata de o
    ///linie orizontala si putem merge de la xVal pana la xVal + epsilon.Daca abs(m) > 1,atunci se apropie
    ///de o axa verticala si ar fi mai bine sa mergem de la min(y1,y2) pana la max(y1,y2) si aflam x1,x2
    ///cu formula de mai sus.Din ce am testat ,e cea mai rapida idee pana acum si traseaza graficul unei functii
    ///destul de bine
    ///<9 a=100,b=100,x*sin(x)
    epsilon=0.05*(abs(a)+abs(b))/20;
    alfa=epsilon/10;
    xVal=a;
    yValPrec=EvaluareExpresie(functie,xVal);
    while(yValPrec==inf)
    {
        xVal+=alfa;
        yValPrec=EvaluareExpresie(functie,xVal);
    }
    while(xVal<=b)
    {
        yValCurenta=EvaluareExpresie(functie,xVal+epsilon);
        while(yValCurenta==inf&&xVal<=b)
        {
            xVal+=epsilon;
            yValCurenta=EvaluareExpresie(functie,xVal+epsilon);
        }
        if(yValCurenta==inf)
            break;

        m=abs((yValPrec-yValCurenta)/epsilon);
        if(m<=1)
        {
            xCapat=xVal+epsilon+alfa;
            xVal+=alfa;
            for(; xVal<=xCapat; xVal+=alfa)
            {
                yVal=EvaluareExpresie(functie,xVal);
                if(yVal!=inf)
                {
                    x1=m1*xVal+n1;
                    y1=m2*yVal+n2;
                    if(yVal>=a&&yVal<=b)
                        circle(x1,y1,1);
                }
            }
        }
        else
        {
            yVal=std::min(yValPrec,yValCurenta);
            yCapat=std::max(yValPrec,yValCurenta);
            n=yVal-m*xVal;
            if(!(yCapat<a||yVal>b)&&yCapat!=inf)
            {
                for(; yVal<=yCapat; yVal+=alfa)
                {
                    xVal1=(yVal-n)/m;
                    yVal1=EvaluareExpresie(functie,xVal1);
                    if(yVal1!=inf)
                    {
                        x1=m1*xVal1+n1;
                        y1=m2*yVal1+n2;
                        if(yVal1>=a&&yVal1<=b)
                            circle(x1,y1,1);
                    }
                }
                xVal+=epsilon;
            }
        }
        yValPrec=yValCurenta;
    }
}

