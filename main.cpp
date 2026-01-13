#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

int maxVettore (vector<int> & v, int n, bool flag) {
    int max(v[0]), i(0), idx(0);

    while (i<=n-1) {

        if (v[i]>max) {
            max=v[i];
            idx=i;
        }
        i++;
    }

    if (flag) {
        cout<<"Posizione="<<idx<<"; ";
    }

    return max;
}
void ordina (vector<int> & v, int n) {
    int i(0), j(0), t;
    bool scambi(true);

    while (i<=n-1 && scambi) {

        scambi=false;
        j=0;

        while (j<=(n-2)-i) {

            if (v[j]>v[j+1]) {

                t=v[j];
                v[j]=v[j+1];
                v[j+1]=t;
                scambi=true;

            }
            j++;
        }
        i++;
    }
}

void riempiVettore (vector<int> & v, int n) {
    srand(time(0));

    int i(0);

    while (i<=n-1) {
        v[i]=rand() % n*10;
        i++;
    }
}

void visualizzaVettore (vector<int> & v, int n, bool flag) {
    int i;

    for (i=0; i<=n-1; i++) {
        cout<<"Numero: ";
        cout<<v[i]<<"; ";

        if (flag) {
            cout<<"Posizione:";
            cout<<i<<"; ";
        }
    }
}

int main () {
    int n, max;
    bool flag;

    cout<<"Quanti numeri generare?"<<endl;
    cin>>n;
    while (n<=0) {
        cout<<"Il numero deve essere positivo"<<endl;
        cin>>n;
    }

    vector<int> v(n), w(n);

    //Riempi vettori
    riempiVettore(v, n);
    riempiVettore(w, n);

    //Visualizza i vettori
    cout<<"Vettore V: ";
    flag=false;
    visualizzaVettore(v, n, flag);
    cout<<"";

    cout<<"Vettore W: "<<endl;
    flag=true;
    visualizzaVettore(w, n, flag);
    cout<<"";

    //Massimo
    flag=false;
    max=maxVettore(v, n, flag);
    cout<<"V_max="<<max;
    cout<<""<<endl;

    flag=true;
    max=maxVettore(w, n, flag);
    cout<<"W_max="<<max;
    cout<<""<<endl;

    //Ordina vettori
    ordina(v, n);
    ordina(w, n);

    //Visualizza vettori ordinati
    cout<<"Vettore V ordinato: ";
    flag=false;
    visualizzaVettore(v, n, flag);
    cout<<"";
    
    cout<<"Vettore W ordinato: "<<endl;
    flag=true;
    visualizzaVettore(w, n, flag);
    cout<<"";
}

//LEGGERE LE ISTRUZIONI NEL FILE README.md
