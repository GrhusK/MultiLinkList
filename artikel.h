#ifndef ARTIKEL_H_INCLUDED
#define ARTIKEL_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define next(L) L->next
#define last(L) L.last
#define info(L) L->info

typedef struct elm_artikel *adr_artikel;
typedef string info_artikel;

struct elm_artikel {
    adr_artikel next;
    info_artikel info;
};
struct list_artikel {
    adr_artikel first;
    adr_artikel last;
};

adr_artikel alokasi_artikel(info_artikel X);
void insertLast_artikel(list_artikel &L,adr_artikel A);
void delate_artikel(list_artikel &L,adr_artikel A);
adr_artikel searching_artikel(list_artikel L,string X);
void createlist_artikel(list_artikel &L);
void printinfo_artikel(list_artikel L);

#endif // ARTIKEL_H_INCLUDED
