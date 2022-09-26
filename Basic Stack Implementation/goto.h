#ifndef GOTO_H_INCLUDED
#define GOTO_H_INCLUDED
#include <windows.h>
#include <iostream>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void bersihlayar()
{
    for(int a=0;a<80;a++)
    {
        for(int b=0;b<=24;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}
#endif // GOTO_H_INCLUDED