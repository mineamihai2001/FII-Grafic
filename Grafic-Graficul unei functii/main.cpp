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
#include "eval.h"
#include "functiiGrafice.h"
#include "meniu.h"

using namespace std;

int main()
{
    stiva expresie;
    InitializareStiva(expresie);

    initwindow(800, 600);
    meniu(expresie);

    getch();
    closegraph();
    return 0;
}
