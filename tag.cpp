#include "tag.h"

adr_tag alokasi_tag(info_tag X) {

    adr_tag T;
    T = new elm_tag;
    count(T) = 0;
    next(T) = NULL;
    info(T) = X;

    return T;
}
void insertLast_tag(list_tag &L,adr_tag T){

    if (first(L) == NULL ) {
        first(L) = T;
        last(L) = T;
    }else {
        adr_tag prec = first(L);
        last(L) = T;
        while (next(prec) != NULL) {
            prec = next(prec);
        }
        next(prec) = T;
    }
}
adr_tag searching_tag(list_tag L,string X) {

    if (first(L) == NULL) {
        return NULL;
    } else {
        adr_tag prec = first(L);

        while (next(prec) != NULL) {
            if (info(prec) == X) {
                return prec;
            } else {
                prec = next(prec);
            }
        }
        if (info(prec) == X) {
                return prec;
        return NULL;
        }
    }
}
void createlist_tag(list_tag &L){
    first(L) = NULL;
    last(L) = NULL;
}
void printinfo_tag(list_tag L){

    if (first(L) != NULL ) {

        adr_tag prec = first(L);
        int i;
        i = 1;
        while (next(prec) != NULL) {
            cout<<i<<". "<<info(prec)<<endl;
            i++;
            prec = next(prec);
        }
        cout<<i<<". "<<info(prec)<<endl;
    } else {
        cout<<"List Kosong"<<endl;
    }
}
void delate_tag(list_tag &L,adr_tag T) {
    adr_tag prec = first(L);

    if (T == first(L) ) {
        first(L) = next(T);
        next(T) = NULL;
    }else if (T == last(L) ) {
        while (next(prec) != T ) {
            prec = next(prec);
        }
        last(L) = prec;
        next(prec) = NULL;
    }else {
        while (next(prec)!= T) {
            prec = next(prec);
        }
        next(prec) = next(T);
        next(T) = NULL;
    }
}
void addcounter(list_tag &L,adr_tag T) {
    adr_tag prec;
    bool found = false;
    prec = first(L);

    while (!found) {
        if (prec = T) {
            found = true;
            count(prec)++;
        }
    }
}
void terbanyak(list_tag &L) {

    int i = 0;
    adr_tag counter,prec;

    counter = first(L);

    cout<<"Daftar list yang terhubung: "<<endl;
    while (next(counter) != NULL) {
        if (count(counter) != 0) {
            cout<<"- Tag "<<info(counter)<<" terhubung dengan "<<count(counter)<< " artikel."<<endl;;
            if (i < count(counter)) {
                i= count(counter);
                prec = counter;

            }
        } else {
            cout<<"- Tag "<<info(counter)<<" Tidak terhubung dengan artikel manapun."<<endl;
        }
        counter = next(counter);

        }
        cout<<"= Tag yang paling banyak digunakan adalah tag "<<info(prec)<< " dengan artikel yang terhubung sebanyak "<<i<<" artikel."<<endl;
    }

