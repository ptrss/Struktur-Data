#ifndef STACKIMPL_H_INCLUDED
#define STACKIMPL_H_INCLUDED

#include <iostream>
#include <string.h>
#include <conio.h>
#include "goto.h"

using namespace std;
#define max 5; 

struct pakett {
    int beratBrg;
    string nmBrg;
    string kota;
};
struct pakett paket[100];

bool isEmpty(int x) {
    return x == 1;
}

bool isFull(int x) {
    return x > max;
}

void pushData(int *x) {
    if (isFull(*x)) {
        gotoxy(5,3);cout << "Stack is FULL\n";
        gotoxy(5,5);cout << "Press Any Key...";
        getch();
    }
    else {
        gotoxy(5,2);cout << "Data ke-" << *x << endl;
        gotoxy(5,3);cout << "Nama Barang       : "; cin >> paket[*x].nmBrg;
        gotoxy(5,4);cout << "Berat Barang (kg) : "; cin >> paket[*x].beratBrg;
        gotoxy(5,5);cout << "Kota Tujuan       : "; cin >> paket[*x].kota;
        (*x)++;
    }
}

void popData(int *x) {
    if (isEmpty(*x)) {
        gotoxy(5,3);cout << "Stack is EMPTY\n";
        gotoxy(5,5);cout << "Press Any Key...";
        getch();
    }
    else {
        (*x)--;
        gotoxy(5,2);cout << "Data terhapus :\n";
        gotoxy(5,3);
        cout << paket[*x].nmBrg << "\t";
        cout << paket[*x].beratBrg << "\t";
        cout << paket[*x].kota << "\n";
        
        gotoxy(12,5);cout << "Press Any Key...";
        getch();
    }
}
 
void peepData(int x) {
    gotoxy(5,2);cout << "Data terakhir :\n";
    gotoxy(5,3);
    cout << paket[x].nmBrg << "\t";
    cout << paket[x].beratBrg << "\t";
    cout << paket[x].kota << "\n";

    gotoxy(12,5);cout << "Press Any Key...";
    getch();
}

void showData(int *x) {
    if (isEmpty(*x)) {
        gotoxy(5,3);cout << "Daftar Pengiriman Kosong!\n";
        gotoxy(12,5);cout << "Press Any Key...";
        getch();
    }
    else {
        gotoxy(5,2);cout << "Daftar Pengiriman : \n";
        for (int i=1; i<*x; ++i) {
            gotoxy(5,3+i);
            cout << i << "\t";
            cout << paket[i].nmBrg << "\t";
            cout << paket[i].beratBrg << "\t";
            cout << paket[i].kota << "\n";
        }
        gotoxy(12,10);cout << "Press Any Key...";
        getch();
    }
}

#endif // STACKIMPL_H_INCLUDED