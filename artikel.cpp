#include "artikel.h"

adr_artikel alokasi_artikel(info_artikel X) {

    adr_artikel A;
    A = new elm_artikel;

    next(A) = NULL;
    info(A) = X;


    return A;
}

void insertLast_artikel(list_artikel &L,adr_artikel A) {

    if (first(L) == NULL ) {
        first(L) = A;
        last(L) = A;
    }else {
        adr_artikel prec = first(L);

        while (next(prec) != NULL) {
            prec = next(prec);
        }
        next(prec) = A;
        last(L) = A;
    }
}

void delate_artikel(list_artikel &L,adr_artikel A) {

  adr_artikel prec = first(L);

    if (A == first(L) ) {
        first(L) = next(A);
        next(A) = NULL;
    }else if (A == last(L) ) {
        while (next(prec) != A ) {
            prec = next(prec);
        }
        last(L) = prec;
        next(prec) = NULL;
    }else {
        while (next(prec) != A) {
            prec = next(prec);
        }
        next(prec) = next(A);
        next(A) = NULL;
    }
}
adr_artikel searching_artikel(list_artikel L,string X){
    if (first(L) == NULL) {
        return NULL;
    } else {
        adr_artikel prec = first(L);

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
void createlist_artikel(list_artikel &L) {
    first(L) = NULL;
    last(L) = NULL;
}

void printinfo_artikel(list_artikel L){
    if (first(L) != NULL) {
        adr_artikel prec = first(L);
        int i;
        i = 1;
        while (next(prec) != NULL) {
            cout<<i<<". "<<info(prec)<<endl;
            i++;
            prec = next(prec);
        }
        cout<<i<<". "<<info(prec)<<endl;
    } else {
        cout<<"KOSONG"<<endl;
    }
}
