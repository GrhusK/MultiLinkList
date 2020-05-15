#include <iostream>
#include "artikel.h"
#include "relasi.h"
#include "tag.h"


using namespace std;

int main()
{
    int pilih;
    list_artikel LA;
    list_tag LT;
    list_relasi LR;

    createlist_artikel(LA);
    createlist_relasi(LR);
    createlist_tag(LT);
    cout<<"======== M E N U ========"<<endl;
    cout<<"1. Tambah artikel baru"<<endl;
    cout<<"2. Tambah tag baru"<<endl;
    cout<<"3. Tambah relasi artikel dan tag"<<endl;
    cout<<"4. Hapus artikel"<<endl;
    cout<<"5. Hapus tag"<<endl;
    cout<<"6. Tampilkan artikel"<<endl;
    cout<<"7. Tag paling banyak digunakan"<<endl;
    cout<<"8. Artikel dengan tag sama"<<endl;
    cout<<"9. Artikel dengan tag tertentu"<<endl;
    cout<<"10. Keluar"<<endl;
    cout<<endl;
    cout<<"Masukkan pilihan: ";
    cin>>pilih;
    cout<<endl;

    adr_artikel a;
    adr_tag t;
    adr_relasi r;
    string judul,tag;

    while (pilih != 10) {
        if (pilih == 1) {
            cout<<"--- Tambah Artikel Baru ---"<<endl;
            cout<<"Masukkan judul artikel: ";
            cin>>judul;
            a = searching_artikel(LA,judul);
            if (a != NULL) {
                cout<<"Data sudah ada, Silahkan masukan data baru"<<endl;
                cout<<"Masukkan judul artikel: ";
                cin>>judul;
                a = searching_artikel(LA,judul);
            }
            a = alokasi_artikel(judul);
            insertLast_artikel(LA,a);
            cout<<"- Artikel berhasil ditambah -"<<endl;

        } else if (pilih == 2) {
            cout<<"--- Tambah Tag Baru ---"<<endl;
            cout<<"Masukkan tag: ";
            cin>>tag;
            t = alokasi_tag(tag);
            insertLast_tag(LT,t);
            cout<<"- Tag berhasil ditambah -"<<endl;

        } else if (pilih == 3) {
            cout<<"--- Tambah Relasi Artikel dan Tag  ---"<<endl;
            cout<<endl;
            cout<<"D A F T A R   A R T I K E L"<<endl;
            printinfo_artikel(LA);
            cout<<endl;
            cout<<"D A F T A R   T A G"<<endl;
            printinfo_tag(LT);
            cout<<endl;

            cout<<"Pastikan semua artikel terhubung dengan tag"<<endl;

            cout<<"pilih artikel: ";
            cin>>judul;
            cout<<"pilih tag: ";
            cin>>tag;

            a = searching_artikel(LA,judul);
            t = searching_tag(LT,tag);
            while (a == NULL || t == NULL) {
                if (a == NULL && t != NULL) {
                    cout<<"artikel tidak dapat ditemukan, masukan artikel lagi"<<endl;
                    printinfo_artikel(LA);
                    cout<<"pilih artikel: ";
                    cin>>judul;
                    a = searching_artikel(LA,judul);
                } else if (a!= NULL && t == NULL) {
                    cout<<"tag tidak dapat ditemukan, masukan tag lagi"<<endl;
                    printinfo_tag(LT);
                    cout<<"pilih tag: ";
                    cin>>tag;
                    t = searching_tag(LT,tag);
                } else if (a== NULL && t == NULL) {
                    cout<<"artikel dan tag tidak ditemukan, silahkan masukan artikel dan tag lagi"<<endl;
                    printinfo_artikel(LA);
                    printinfo_tag(LT);
                    cout<<"pilih artikel: ";
                    cin>>judul;
                    a = searching_artikel(LA,judul);
                    cout<<"pilih tag: ";
                    cin>>tag;
                    t = searching_tag(LT,tag);
                }
            }
            info(a) = judul;
            info(t) = tag;
            r = alokasi_relasi(a,t);
            if (searching_relasi(LR,judul,tag) == true) {
                cout<<"Artikel dan Tag telah memiliki relasi"<<endl;
            } else {
                insertLast_relasi(LR,r);
                addcounter(LT,t);
                cout<<"- Relasi berhasil didaftarkan -";
                cout<<endl;
                cout<<"D A F T A R   R E L A S I"<<endl;
                printinfo_relasi(LR);
            }

        } else if (pilih == 4) {
            cout<<"--- Hapus Artikel ---"<<endl;
            cout<<endl;
            printinfo_artikel(LA);
            if  (first(LA) != NULL) {
                cout<<"Judul artikel yang akan dihapus: ";
                cin>>judul;
                a = searching_artikel(LA,judul);
                if (first(LA) == NULL) {
                    cout<<"list artikel kosong"<<endl;
                }
                if (first(LA) != NULL && a!= NULL) {
                    info(a) = judul;
                    delate_artikel(LA,a);
                    delaterelasi_artikel(LR,judul);

                    cout<<endl;
                    cout<<"- Artikel berhasil dihapus -";
                    cout<<endl;
                    printinfo_artikel(LA);
                } else if ( a== NULL  || first(LA) == NULL) {
                    cout<<"TIDAK ADA"<<endl;
                }
            }

        } else if (pilih == 8) {
            cout<<"--- Artikel Dengan Tag Sama  ---"<<endl;
            cout<<endl;

            if (first(LR) != NULL) {
                printsama_tag(LR,LT);
            } else {
                cout<<"List Kosong"<<endl;
            }


        } else if (pilih == 9) {
            cout<<"--- Artikel Dengan Tag Tertentu  ---"<<endl;
            cout<<endl;
            if (first(LT) != NULL) {
                cout<<"- Daftar Tag -"<<endl;
                printinfo_tag(LT);
                cout<<"Tag pilihan: ";
                cin>>tag;
                cout<<endl;
                t = searching_tag(LT,tag);
            }
            if (first(LT) == NULL) {
                cout<<"List kosong, silahkan isi data"<<endl;
            } else if (t == NULL) {
                while (t == NULL) {
                    cout<<"Data yang anda masukan tidak ada,silahkan masukan kembali data"<<endl;
                    printinfo_tag(LT);
                    cout<<"Tag pilihan: ";
                    cin>>tag;
                    t = searching_tag(LT,tag);
                    cout<<"Daftar artikel yang terhubung dengan "<<tag<<endl;
                    print_tag(LR,tag);
                }
            } else {
                cout<<"Daftar artikel yang terhubung dengan "<<tag<<endl;
                print_tag(LR,tag);
            }


        } else if (pilih == 6) {
            cout<<"--- Daftar Artikel  ---"<<endl;
            cout<<endl;
            if (first(LR) == NULL) {
                cout<<"LIST KOSONG"<<endl;
            } else {
                printinfo_artikel(LA);
            }
        } else if (pilih == 7) {
            cout<<"--- Tag Paling Banyak Digunakan  ---"<<endl;
            cout<<endl;

            if (first(LT) != NULL ) {
                terbanyak(LT);
            } else {
                cout<<"LIST KOSONG"<<endl;
            }

        } else if (pilih == 5 ) {

            cout<<"--- Hapus TAG ---"<<endl;
            cout<<endl;
            printinfo_tag(LT);
            if (first(LT) != NULL ){
                cout<<"Judul tag yang akan dihapus: ";
                cin>>tag;
                t = searching_tag(LT,tag);
                if (first(LT) == NULL) {
                    cout<<"List tag kosong"<<endl;
                }
                if (first(LA) != NULL && t!= NULL) {
                    info(t) = tag;
                    delate_tag(LT, t);
                    delaterelasi_tag(LR,tag);
                    cout<<endl;
                    cout<<"- Tag Berhasil Dihapus -";
                    cout<<endl;
                    printinfo_tag(LT);
                } else if ( t== NULL  || first(LT) == NULL) {
                    cout<<"TIDAK ADA"<<endl;
                }
            }
        }
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"======== M E N U ========"<<endl;
        cout<<"1. Tambah artikel baru"<<endl;
        cout<<"2. Tambah tag baru"<<endl;
        cout<<"3. Tambah relasi artikel dan tag"<<endl;
        cout<<"4. Hapus artikel"<<endl;
        cout<<"5. Hapus tag"<<endl;
        cout<<"6. Tampilkan artikel"<<endl;
        cout<<"7. Tag paling banyak digunakan"<<endl;
        cout<<"8. Artikel dengan tag sama"<<endl;
        cout<<"9. Artikel dengan tag tertentu"<<endl;
        cout<<"10. Keluar"<<endl;
        cout<<endl;
        cout<<"Masukkan pilihan: ";
        cin>>pilih;
    }
        cout<<"== K E L U A R ==";
}
