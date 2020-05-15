#ifndef TAG_H_INCLUDED
#define TAG_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define next(L) L->next
#define last(L) L.last
#define info(L) L->info
#define count(L) L->count

typedef struct elm_tag *adr_tag;
typedef string info_tag;

struct elm_tag {
    adr_tag next;
    info_tag info;
    int count;
};

struct list_tag {
    adr_tag first;
    adr_tag last;
};
void createlist_tag(list_tag &L);
adr_tag alokasi_tag(info_tag X);
void insertLast_tag(list_tag &L,adr_tag T);
adr_tag searching_tag(list_tag L,string X);
void printinfo_tag(list_tag L);
void delate_tag(list_tag &L,adr_tag T);
void addcounter(list_tag &L,adr_tag T);
void terbanyak(list_tag &L);
#endif // TAG_H_INCLUDED
