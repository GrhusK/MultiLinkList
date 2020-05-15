#include "relasi.h"


void createlist_relasi(list_relasi &L){
    first(L) = NULL;
    last(L) = NULL;
}
adr_relasi alokasi_relasi(adr_artikel A,adr_tag T) {

    adr_relasi R;

    R = new elm_relasi;

    next(R) = NULL;
    artikel(R) = A;
    tag(R) = T;

    return R;
}
void insertfirst(list_relasi &L, adr_relasi R){

    if ( first(L) == NULL ) {

        first(L) = R;

    } else{

        next(R) = first(L);
        first(L) = R;

    }
}
void insertLast_relasi(list_relasi &L, adr_relasi R){


    if (first(L) == NULL) {

        first(L) = R;
        last(L) = R;

    } else {
        adr_relasi prec = first(L);

        while (next(prec) != NULL ) {
            prec = next(prec);
        }
        next(prec) = R;
        last(L) = R;
    }


}
void delateAfter_relasi(list_relasi L,adr_artikel A) {
    adr_relasi prec = first(L);
    adr_relasi Q = next(prec);

    if (first(L) == last(L) ) {
        if (artikel(prec) == A) {
            first(L) = NULL;
            last(L) = NULL;
        }

    }
}
bool searching_relasi(list_relasi L,string artikel,string tag){

    if (first(L) != NULL){

        adr_relasi prec = first(L);
        bool found = false;

        while (!found && next(prec) != NULL) {
            if (info(artikel(prec)) == artikel && info(tag(prec)) == tag) {
                found = true;
                return found;
            } else {
                prec = next(prec);
            }
        }
        if (info(artikel(prec)) == artikel && info(tag(prec)) == tag) {
                found = true;
                return found;
            }
    }
    return false;

}
void printinfo_relasi(list_relasi L){
    if (first(L) != NULL) {
        adr_relasi prec = first(L);


        while (next(prec) != NULL) {
            cout<<info(artikel(prec))<<" berhubungan dengan "<<info(tag(prec))<<endl;
            prec = next(prec);
        }
        cout<<info(artikel(prec))<<" berhubungan dengan "<<info(tag(prec))<<endl;
    } else {
        cout<<"DATA TIDAK DITEMUKAN"<<endl;
    }
}
void print_artikel(list_relasi L,string artikel) {
    adr_relasi prec = first(L);

    int i =1 ;

    while (next(prec) != NULL) {
        if (info(artikel(prec)) == artikel ) {
            cout<<i<<". "<<endl;
            cout<<info(tag(prec))<<endl;
        } else {
            prec = next(prec);
        }
        i++;
        if (prec == last(L)) {
            cout<<i<<". "<<endl;
            cout<<info(tag(prec))<<endl;
        }
    }
}
void print_tag(list_relasi L,string tag){
    adr_relasi prec = first(L);
    int i = 0;

    while (prec != last(L)) {
        if (info(tag(prec)) == tag) {
            i++;
            cout<<i<<". ";
            cout<<info(artikel(prec))<<endl;

        }
            prec = next(prec);
        }
        if (prec == last(L)) {
            if (info(tag(prec)) == tag){
                    i++;
                cout<<i<<". ";
                cout<<info(artikel(prec))<<endl;
            }
        }

}
void printsama_tag(list_relasi LR,list_tag LT) {

    adr_tag prec_tag;
    adr_relasi prec_relasi;
    int i = 1;
    prec_tag = first(LT);
    prec_relasi = first(LR);

    if ( prec_tag == last(LT) ) {
        if( count(prec_tag) >= 2) {
        cout<<info(prec_tag)<<"terhubung pada artikel"<<endl;

        while (next(prec_relasi) != NULL) {

            if (tag(prec_relasi) == prec_tag) {
                cout<<info(artikel(prec_relasi))<<endl;
                i++;
            }
            prec_relasi = next(prec_relasi);
            if (next(prec_relasi) == last(LR)) {
                if (tag(prec_relasi) == prec_tag) {
                    cout<<info(artikel(prec_relasi))<<endl;
                    i++;
                }
            }
        }
        }

    } else {
        while ( next(prec_tag) != NULL ) {
            if (count(prec_tag) >= 2){
            cout<<"Artikel yang memiliki tag yang sama dengan tag "<<info(prec_tag)<<": "<<endl;
                while (next(prec_relasi) != NULL) {
                    if (tag(prec_relasi) == prec_tag) {
                        cout<<i<<". "<<info(artikel(prec_relasi))<<endl;
                        i++;
                    }
                    prec_relasi = next(prec_relasi);


                }
                if (prec_relasi == last(LR) ) {
                    if (tag(prec_relasi) == prec_tag) {
                        cout<<i<<". "<<info(artikel(prec_relasi))<<endl;
                        i++;
                    }
                }
            }
        prec_relasi = first(LR);
        prec_tag = next(prec_tag);

        i = 1;
        }



        if (count(prec_tag) >= 2) {
            cout<<"Artikel yang memiliki tag yang sama dengan tag "<<info(prec_tag)<<": "<<endl;
                prec_relasi = first(LR);
                while (next(prec_relasi) != NULL) {

                    if (tag(prec_relasi) == prec_tag) {
                        cout<<i<<". "<<info(artikel(prec_relasi))<<endl;
                        i++;
                    }
                    prec_relasi = next(prec_relasi);
                    if (prec_relasi == last(LR)) {
                        if (tag(prec_relasi) == prec_tag) {
                            cout<<i<<". "<<info(artikel(prec_relasi))<<endl;
                            i++;
                        }
                    }
                }
        }
        cout<<"List yang terhubung hanya pada 1 artikel atau tidak sama sekali"<<": "<<endl;
        prec_tag = first(LT);
        i = 1;
        while (next(prec_tag) != NULL) {

            if (count(prec_tag) <= 1) {
                cout<<i<<". "<<info(prec_tag)<<endl;
                i++;
            }
            prec_tag = next(prec_tag);
        }
        if (next(prec_tag) == NULL) {
            if (count(prec_tag) <= 1) {
                cout<<i<<". "<<info(prec_tag)<<endl;
            }
        }

    }
}
void delaterelasi_artikel(list_relasi &L,string X) {

    if (first(L) != NULL) {
        adr_relasi prec,Q,del_art;
        prec = first(L);
        while (next(prec) != NULL) {
            if (info(artikel(prec)) == X) {
                if (prec == first(L)) {
                    count(tag(prec)) = count(tag(prec)) - 1;
                    del_art = first(L);
                    prec = next(del_art);
                    next(del_art) = NULL;
                    first(L) = prec;

                } else {
                    Q = first(L);
                    while (next(Q) != prec) {
                        Q = next(Q);
                    }
                    count(tag(prec))= count(tag(prec)) - 1;
                    del_art = prec;
                    prec = next(prec);
                    next(Q) = prec;
                    next(del_art) = NULL;
                }
            } else {
                prec = next(prec);
            }
        }

        if (next(prec) == NULL) {
            if (info(artikel(prec)) == X) {
                Q = first(L);
                while (next(Q) != prec) {
                    Q = next(Q);
                }
                count(tag(prec))= count(tag(prec)) - 1;
                next(Q) = NULL;
                last(L) = Q;
            }
        }
    }

}
void delaterelasi_tag(list_relasi &L,string X) {
    if (first(L) != NULL) {
        adr_relasi prec,Q,del_art;
        prec = first(L);

        while (next(prec) != NULL) {
            if (info(tag(prec)) == X) {
                if (prec == first(L)) {
                    del_art = first(L);
                    prec = next(del_art);
                    next(del_art) = NULL;
                    first(L) = prec;

                } else {
                    Q = first(L);
                    while (next(Q) != prec) {
                        Q = next(Q);
                    }
                    del_art = prec;
                    prec = next(prec);
                    next(Q) = prec;
                    next(del_art) = NULL;

                }
            } else {
                prec = next(prec);
            }
        }

        if (next(prec) == NULL) {
            if (info(tag(prec)) == X) {
                Q = first(L);
                while (next(Q) != prec) {
                    Q = next(Q);
                }
                next(Q) = NULL;
                last(L) = Q;
            }
        }
    }

}







