#include <iostream>
#include <windows.h>
#include <conio.h>
#include "stackimpl.h"
#include "goto.h"

using namespace std;

int main() {
    int top = 1;
    int pilih;

    do {
        bersihlayar();
        gotoxy(7,1);cout << "==Program Basic Stack==" << endl;
        gotoxy(5,2);cout << "1. Tambah Data" << endl;
        gotoxy(5,3);cout << "2. Hapus Data Terakhir" << endl;
        gotoxy(5,4);cout << "3. Tampilkan Data Terakhir" << endl;
        gotoxy(5,5);cout << "4. Tampilkan Data" << endl;
        gotoxy(5,6);cout << "9. Keluar" << endl;
        gotoxy(5,7);cout << "Pilihan anda [1-9] : "; cin >> pilih;
        bersihlayar();
        switch(pilih) {
            case 1:
                pushData(&top);
                break;
            case 2:
                popData(&top);
                break;
            case 3:
                peepData(top-1);
                break;
            case 4:
                showData(&top);
                break;
            case 9:
                cout << "Thanks! Have a nice day!\n";
                break;
            default:
                gotoxy(5,3);cout << "Invalid choice" << endl;
                gotoxy(5,5);cout << "Press Any Key...";
                getch();
                break;
        }
    }while (pilih != 9);

    return 0;
}