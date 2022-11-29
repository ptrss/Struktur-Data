//Double Linked List Implementation - Music Playlist

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Playlist {
    string Title, Director;
    int Year;
    Playlist *next, *prev;
};
Playlist *head = NULL, *tail = NULL, *bantuan = NULL;

bool isEmpty() {
    return head == NULL;
}

// Find Word Procedure for Search Procedure
int findword(string s1, string s2) {
    int flag;
    for(int i=0; i<s1.length(); i++) {
        if(s1[i] == s2[0]) {
            flag = 0;
            for(int j=0; j<s2.length(); j++) {
                if(s1[i+j] != s2[j]) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) {
                return i;
            }
        }
    }
    return -1;
}

// Convert Procedure for Case-Insensitive String Compare 
string convert(string s) {
    for(int i=0; i<s.size(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

// Show Data Procedure
void showFirst2Last() {
    Playlist *bantu = head;
    if(isEmpty()) {
        cout <<"\n Your Playlist is Empty\n";
    } else if(head == tail) {
        cout << "\n === Your Playlist ===\n";
        cout << " " << bantu->Title << " (" << bantu->Year << ") by " << bantu->Director << endl;
    } else {
        cout << "\n === Your Playlist ===\n";
        do {
            cout << " " << bantu->Title << " (" << bantu->Year << ") by " << bantu->Director << endl;
            bantu = bantu->next;
        } while (bantu != head);
    }   
}

void showLast2First() {
    Playlist *bantu = tail;
    if(isEmpty()) {
        cout << "\n Your Playlist is Empty\n";
    } else if(head == tail) {
        cout << "\n === Your Playlist ===\n";
        cout << " " << bantu->Title << " (" << bantu->Year << ") by " << bantu->Director << endl;
    } else {
        cout << "\n === Your Playlist ===\n";
        do {
            cout << " " << bantu->Title << " (" << bantu->Year << ") by " << bantu->Director << endl;
            bantu = bantu->prev;
        } while(bantu != tail);
    }
}

// Search Data Procedure
void searchData() {
    Playlist *bantu = head;

    string cariJudul, cariSutradara;
    int ketemu = 0;

    if(isEmpty()) {
        cout <<"\n Your Playlist is Empty!\n";
    } else {
        cout << "\n === Search Movie ===\n"; cin.get();
        cout << " Title  : "; getline(cin, cariJudul);

        cout << "\n Finding Movie...\n";
        Sleep(2000);
        system("cls");
        cout << "\n === Movie Found! ===\n";
        do {
            if(findword(convert(bantu->Title), convert(cariJudul))!=-1) {
                cout << " " << bantu->Title << " ("<< bantu->Year << ") by "
                << bantu->Director << endl;
                ketemu = 1;
            }
            bantu = bantu->next;
        } while(bantu != head);

        if(ketemu == 0) {
            system("cls");
            cout << "\n === Movie not Found! ===\n";
        } 
    }
}

// Insert Data Procedure
void insertFirst(string title, string director, int year) {
    Playlist *baru = new Playlist;
    
    baru->T itle = title;
    baru->Director = director;
    baru->Year = year;
    baru->next = NULL;
    baru->prev = NULL;

    if(!isEmpty()) {
        baru->next = head;
        baru->prev = tail;
        head->prev = baru;
        head = baru;
        tail->next = head;
    } else {
        head = tail = baru;
    }
    cout << "\n Movie Added! ";
}

void insertLast(string title, string director, int year) {
    Playlist *baru = new Playlist;

    baru->Title = title;
    baru->Director = director;
    baru->Year = year;
    baru->next = NULL;
    baru->prev = NULL;

    if(!isEmpty()) {
        baru->next = head;
        baru->prev = tail;
        tail->next = baru;
        tail = baru;
        head->prev = tail;
    } else {
        head = tail = baru;
    }
    cout << "\n Movie Added! ";
}

void insertMiddle(string title, string director, int year) {
    Playlist *bantu = head;
    string cariJudul, cariSutradara;
    int ketemu = 0;

    Playlist *baru = new Playlist;

    baru->Title = title;
    baru->Director = director;
    baru->Year = year;
    baru->next = NULL;
    baru->prev = NULL;
    
    if(isEmpty()) {
        head = tail = baru;
        cout << "\n Movie Added!\n";
    } else {
        showFirst2Last();
        ulang:
        cout << "\n === Insert New Movie After ===\n";
        cout << " Title  : "; getline(cin, cariJudul);
        cout << " Director : "; getline(cin, cariSutradara);

        if(convert(cariJudul)==convert(tail->Title) && convert(cariSutradara)==convert(tail->Director)) {
            insertLast(title, director, year);
        } else {
            do {
                if(convert(cariJudul)==convert(bantu->Title) && convert(cariSutradara)==convert(bantu->Director)) {
                    baru->next = bantu->next;
                    bantu->next = baru;
                    baru->prev = bantu;
                    baru->next->prev = baru;
                    ketemu = 1;
                    break;
                }
                bantu = bantu->next;
            } while(bantu != head);
            if(ketemu==1) {
                cout << "\n Movie Added! ";
            } else {
                cout << "\n Movie not Found!\n";
                goto ulang;
            }
        }
    }
}

// Delete Data Procedure
void deleteFirst() {
    if(!isEmpty()) {
        Playlist *hapus;

        if(head==tail) {
            delete head;
            head = tail = NULL;
        } else {
            hapus = head;
            head = head->next;
            tail->next = head;
            head->prev = tail;
            delete hapus;
        }
        cout << "\n Playlist Updated!\n";
        showFirst2Last();
        cout << endl;
    } else cout <<"\n Your Playlist is Empty!\n";

}

void deleteLast() {
    if(!isEmpty()) {
        Playlist *hapus, *bantu;

        if(head==tail) {
            delete head;
            head = tail = NULL;
        } else {
            hapus = tail;
            bantu = tail->prev;
            bantu->next = head;
            tail = bantu;
            head->prev = tail;
            delete hapus;
            
        }
        cout << "\n Playlist Updated!\n";
        showFirst2Last();
        cout << endl;
    } else cout <<"\n Your Playlist is Empty!\n";
}

void deleteMiddle() {
    Playlist *hapus;
    string cariJudul, cariSutradara;

    if(!isEmpty()) {
        showFirst2Last();
        cout << "\n Remove Movie from Playlist\n"; cin.get();
        cout << " Title  : "; getline(cin, cariJudul);
        cout << " Director : "; getline(cin, cariSutradara);

        if(head == tail) {
            hapus = head;
            delete hapus;
            head = tail = NULL;
        } else {
            Playlist *bantu2, *bantu = head;
            do {
                if(convert(cariJudul)==convert(bantu->Title) && convert(cariSutradara)==convert(bantu->Director)) {
                    bantu2 = bantu->prev;
                    hapus = bantu;
                    bantu2->next = hapus->next;
                    hapus->next->prev = bantu2;
                    delete hapus;
                    break;
                }
                bantu = bantu->next;
            } while(bantu != head);
        }
        cout << "\n Playlist Updated!\n";
        showFirst2Last(); 
        cout << endl;
    } else cout <<"\n Your Playlist is Empty!\n";
}

// Move Data Procedure
void insertData(string titleA, string directorA, string titleB, string directorB) {
    Playlist *bantu = head;

    Playlist *baru = new Playlist;
    baru->Title = titleA;
    baru->Director = directorA;
    baru->next = NULL;
    baru->prev = NULL;
    
    if(convert(titleB)==convert(tail->Title) && convert(directorB)==convert(tail->Director)) {
        baru->next = head;
        baru->prev = tail;
        tail->next = baru;
        tail = baru;
        head->prev = tail;
    } else {
        do {
            if(convert(bantu->Title)==convert(titleB) && convert(bantu->Director)==convert(directorB)) {
                baru->next = bantu->next;
                bantu->next = baru;
                baru->prev = bantu;
                baru->next->prev = baru;
                break;
            }
            bantu = bantu->next;
        } while(bantu != head);
        cout << "\n Playlist Updated!\n";
    }
}

void moveData() {
    Playlist *lagu, *hapus, *bantu;

    if(isEmpty()) { // playlist masih kosong.
        cout << "\n Your Playlist is Empty!\n";
    } else if(head == tail) { // hanya ada satu lagu, tidak bisa dipindah.
        cout << "\n Sorry, there's only one movie..\n";
    } else {
        string cariJudul, cariSutradara, JudulPindah, SutradaraPindah;

        // variabel temporary sebagai wadah pemindahan data
        string tempJudul, tempArtis;
        
        // Untuk bantu searching Lagu yang ingin dipindah
        Playlist *bantuPindah = head, *bantuCari = head;
        int ketemuA = 0, ketemuB = 0;

        // Tampil data dulu agar lebih user friendly
        showFirst2Last();
        
        // Title - Director A yang ingin dipindah
        cin.get();
        ulangPindah:
        cout << "\n === Movie You Want to Move ===\n";
        cout << " Title  : "; getline(cin, JudulPindah);
        cout << " Director : "; getline(cin, SutradaraPindah);
        do {
            if(convert(JudulPindah)==convert(bantuPindah->Title) && convert(SutradaraPindah)==convert(bantuPindah->Director)) {
                ketemuA = 1;
                break;
            }
            bantuPindah = bantuPindah->next;
        } while(bantuPindah != head);
        if(ketemuA==0) {
            goto ulangPindah;
        }

        // Pindahkan Title - Director A ke setelah Title - Director B
        ulangCari:
        cout << "\n === Move After ===\n";
        cout << " Title  : "; getline(cin, cariJudul);
        cout << " Director : "; getline(cin, cariSutradara);
        do {
            if(convert(cariJudul)==convert(bantuCari->Title) && convert(cariSutradara)==convert(bantuCari->Director)) {
                ketemuB = 1;
                break;
            }
            bantuCari = bantuCari->next;
        } while(bantuCari != head);
        if(ketemuB==0) {
            goto ulangCari;
        }

        if(convert(JudulPindah)==convert(head->Title) && convert(SutradaraPindah)==convert(head->Director)) { //cari satu yang mau dipindah
            // pindah data ke temporary variable
            lagu = head;
            tempJudul = lagu->Title;
            tempArtis = lagu->Director;
            insertData(tempJudul, tempArtis, cariJudul, cariSutradara);

            //hapus data sebelumnya
            hapus = head;
            head = head->next;
            tail->next = head;
            head->prev = tail;
            delete hapus;
        } else if(convert(JudulPindah)==convert(tail->Title) && convert(SutradaraPindah)==convert(tail->Director)) {
            //pindah data ke temporary variable
            lagu = tail;
            tempJudul = lagu->Title;
            tempArtis = lagu->Director;
            insertData(tempJudul, tempArtis, cariJudul, cariSutradara);

            //hapus data sebelumnya
            bantu = tail->prev;
            hapus = tail;
            bantu->next = head;
            tail = bantu;
            head->prev = tail;
            delete hapus;
        } else {
            Playlist *bantu2;
            bantu = head;
            do {
                if(convert(JudulPindah)==convert(bantu->Title) && convert(SutradaraPindah)==convert(bantu->Director)) {
                    //pindah data
                    lagu = bantu;
                    tempJudul = lagu->Title;
                    tempArtis = lagu->Director;
                    insertData(tempJudul, tempArtis, cariJudul, cariSutradara);

                    //hapus data sebelumnya
                    bantu2 = bantu->prev;
                    hapus = bantu;
                    bantu2->next = hapus->next;
                    hapus->next->prev = bantu2;
                    delete hapus;
                    break;
                }
                bantu = bantu->next;
            } while(bantu != head);
        }
    }
}

void playFirstMovie() {
    bantuan = head;
    if(!isEmpty()) {
        cout << "\n === Now Playing ===\n"  << endl;
        cout << " " << bantuan->Title 
        << " (" << bantuan->Year << ") by "
        << bantuan->Director << endl;
    } else cout << "\n === No Movie is Playing ===\n" << endl;
}

void playNextMovie() {
    if(bantuan == NULL) {
        playFirstMovie();
    } else if(head == tail) {
        cout << "\n === There are No Other Movies ===\n" << endl;
    } else if(bantuan != NULL) {
        bantuan = bantuan->next;
        if(!isEmpty()) {
            cout << "\n === Now Playing ===\n"  << endl;
            cout << " " << bantuan->Title 
            << " (" << bantuan->Year << ") by "
            << bantuan->Director << endl;
        }
    } else cout << "\n === No Movie is Playing ===\n" << endl;
}

void playPreviousMovie() {
    if(bantuan == NULL) {
        playFirstMovie();
    } else if(head == tail) {
        cout << "\n === There are No Other Movies ===\n" << endl;
    } else if(bantuan != NULL) {
        bantuan = bantuan->prev;
        if(!isEmpty()) {
            cout << "\n === Now Playing ===\n"  << endl;
            cout << " " << bantuan->Title 
            << " (" << bantuan->Year << ") by "
            << bantuan->Director << endl;
        }
    } else cout << "\n === No Movie is Playing ===\n" << endl;
}

void stopMovie() {
    bantuan = NULL;
    cout << "\n === Stop Playing ===\n" << endl;
}

int main() {
    string title, director;
    int pil, year;

    do {
        jalan:
        cout << " =======================================" << endl;
        cout << " =          Playlist Program           =" << endl;
        cout << " = (Double Linked List Implementation) =" << endl;
        cout << " =======================================" << endl;
        cout << " =  (1) Insert First                   =" << endl;
        cout << " =  (2) Insert Middle                  =" << endl;
        cout << " =  (3) Insert Last                    =" << endl;
        cout << " =  (4) Delete First                   =" << endl;
        cout << " =  (5) Delete Middle                  =" << endl;
        cout << " =  (6) Delete Last                    =" << endl;
        cout << " =  (7) Relocate Movie                 =" << endl;
        cout << " =  (8) Search                         =" << endl;
        cout << " =  (9) Show First to Last             =" << endl;
        cout << " = (10) Show Last to First             =" << endl;
        cout << " = (11) Play Movie                     =" << endl;
        cout << " = (12) Play Next Movie                =" << endl;
        cout << " = (13) Play Previous Movie            =" << endl;
        cout << " = (14) Stop Movie                     =" << endl;
        cout << " =  (0) Exit                           =" << endl;
        cout << " =======================================" << endl;
        cout << " Masukan Pilihan : "; cin >> pil;
        system("cls");
        switch (pil) {
            case 1 :
                cin.get();
                cout << "\n === Add a New Movie ===\n";
                cout << " Title    : "; getline(cin, title);
                cout << " Director : "; getline(cin, director);
                cout << " Year     : "; cin >> year;
                insertFirst(title, director, year);
                cout << " Press Any Key...\n";
                getch(); 
                break;
            case 2 :
                cin.get();
                cout << "\n === Add a New Movie ===\n";
                cout << " Title    : "; getline(cin, title);
                cout << " Director : "; getline(cin, director);
                cout << " Year     : "; cin >> year;
                insertMiddle(title, director, year);
                cout << " Press Any Key...\n";
                getch();
                break;
            case 3 :
                cin.get();
                cout << "\n === Add a New Movie ===\n";
                cout << " Title    : "; getline(cin, title);
                cout << " Director : "; getline(cin, director);
                cout << " Year     : "; cin >> year;
                insertLast(title, director, year);
                cout << " Press Any Key...\n";
                getch();
                break;
            case 4 :
                deleteFirst();
                cout << " Press Any Key...\n";
                getch();
                break;
            case 5 : 
                deleteMiddle();
                cout << "\n Press Any Key...\n";
                getch();
                break;
            case 6 :
                deleteLast();
                cout << "\n Press Any Key...\n";
                getch();
                break;
            case 7 :
                moveData();
                cout << "\n Press Any Key...\n";
                getch();
                break;
            case 8 :
                searchData();
                cout << "\n Press Any Key...\n";
                getch();
                break;
            case 9 :
                showFirst2Last();
                cout << "\n Press Any Key...\n";
                getch();
                break; 
            case 10 :
                showLast2First();
                cout << "\n Press Any Key...\n";
                break;
            case 11 :
                playFirstMovie();
                goto jalan;
            case 12 : 
                playNextMovie();
                goto jalan;
            case 13 : 
                playPreviousMovie();
                goto jalan;
            case 14 : 
                stopMovie();
                goto jalan;
            case 0 :
                return 0;
                break;
            default:
                goto jalan;
        }
        system("cls");
    } while(pil != 0);
    cout << "\n Program Ended.\n";
}
