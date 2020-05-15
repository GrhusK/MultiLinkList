#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include "tag.h"
#include "artikel.h"

using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(L) L->next
#define artikel(L) L->artikel
#define tag(L) L->tag

typedef struct elm_relasi *adr_relasi;

struct elm_relasi {
    adr_relasi next;
    adr_artikel artikel;
    adr_tag tag;
};

struct list_relasi {
    adr_relasi first;
    adr_relasi last;
};

void createlist_relasi(list_relasi &L);
adr_relasi alokasi_relasi(adr_artikel A,adr_tag T);
void insertLast_relasi(list_relasi &L, adr_relasi R);
void deleteAfter_relasi(list_relasi &L, adr_relasi R);
bool searching_relasi(list_relasi L,string artikel,string tag);
void print_artikel(list_relasi L, string artikel);
void print_tag(list_relasi L,string tag);
void printinfo_relasi(list_relasi L);
void printsama_tag(list_relasi L,list_tag T);
void delaterelasi_artikel(list_relasi &L,string X);
void delaterelasi_tag(list_relasi &L,string X);
#endif // RELASI_H_INCLUDED
