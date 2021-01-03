#include <iostream>
#include <string>
using namespace std;

const int dim = 100;

string a[dim];
string name;


int size()
{
    int s = 0;
    while(a[s] != ""){
        s++;
    }
    return s;
}

bool emptylist(){
    if(size() == 0){
        cout << "La tua lista è vuota" << endl;
        return true;
    }
    return false;
}

bool existString(string &x){
    for (int w = 0; w < size(); w++) {
        if(a[w] == x)return true;
    }
    return false;
}

void addString(string &x)
{
    int z = size();
    if(z == dim){
        cout << "Spazio esaurito! Non puoi inserire nessuna stringa";
        return;
    }
    
    if(existString(x)){
        cout << "Stringa già presente nella lista!" << endl;
        return;
    }
    
    a[z] = x;
    z++;
    return;
}

void newArray(string c[dim], string &x){
    int s = 0;
    for (int y = 0; y < size(); y++) {
        if (a[y] != x)
        {
            c[s] = a[y];
            s++;
        }
    }
    for (int y = 0; y < size(); y++) {
        a[y] = c[y];
    }
    return;
}

void removeString(string &x)
{
    if (emptylist()) return;
    
    if(!existString(x)) {
        cout << "Nessun elemento presente nella lista, impossibile eliminare " << x << endl;
        return;
    }
    
    string c[dim];
    newArray(c,x);
    
}

void removeAll(){
    int r = size();
    int m = 0;
    while(r > -1){
        a[m] = "";
        r--;
        m++;
    }
}

void stampa()
{
    if(size() == 0){
        cout << "La tua lista è vuota" << endl;
        return;
    }
    cout << "[";
    for (int s = 0; s < size(); s++) {
        cout << a[s];
        if (s != size()-1){
        cout << ", ";
        }
    }
    cout << "]" << endl;
    return;
}

void fail(){
    if(cin.fail())
    {
        cout << "Scelta non ammessa" << endl;
        cin.clear();
        cin.ignore(256, '\n');
    }
    return;
}

int main(){
    
    int select = 0;
    string x;
    
    cout << "Inserisci il tuo nome: ";
    cin >> name;
    fail();
    cout << "Ciao, " << name << endl;
    cout << "Scegli una delle 6 opzioni" << endl;
    do{
        cout << endl;
        cout << "1 - Aggiungi Stringa" << endl;
        cout << "2 - Rimuovi Stringa" << endl;
        cout << "3 - Numero Stringhe Inserite" << endl;
        cout << "4 - Stampa Lista" << endl;
        cout << "5 - Cancella Lista" << endl;
        cout << "6 - Termina" << endl;
        cout << endl;
        cout << "Inserisci la scelta: ";
        cin >> select;
        fail();

        switch (select) {
            case 1:
                cout << "Inserisci una parola: ";
                cin >> x;
                fail();
                addString(x);
                break;
            case 2:
                if(emptylist()) break;
                cout << "Inserisci una parola da eliminare: ";
                cin >> x;
                fail();
                removeString(x);
                break;
            case 3:
                cout << "Hai inserito " << size() << " parole!" << endl;
                break;
            case 4:
                stampa();
                break;
            case 5:
                if(emptylist()) break;
                removeAll();
                cout << "Hai cancellato tutte le stringhe della lista!" << endl;
                break;
            case 6:
                cout << "Ciao " << name << ", a presto!" << endl;
                cout << "Fine Programma!" << endl;
                break;
            default:
                cout << "Non esiste questa scelta!" << endl;
                break;
        }
        
    }while(select != 6);
    
    return 0;
}
