#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

const int n = 300;

struct premiazione
{
    char anno[n];
    char ruolo[n];
    char attore[n];
};

premiazione oscar[n];

int fine = 0;
int indice = 0;


bool ctrl(char p[n]){
    if( strcmp(p,"") == 0 || strcmp(p," ") == 0){
        cout << "Non hai inserito niente..." << endl;
        return true;
    }
    return false;
}


void file(){
    
    ifstream attore;
    char f1[n];
    cout << "Inserisci nome del file: ";
    cin.getline(f1, n, '\n');
    attore.open(f1);
        if(attore.fail()){
            cout << "Il file non esiste!" << endl;
            attore.clear();
            return;
        }else{
            cout << "Aperto Correttamente!" << endl;
        }
    
    do{
        char f[n];
        attore.getline(f, n, '\n');
        strcpy(oscar[indice].anno, f);
        
        char r[n];
        attore.getline(r, n, '\n');
        strcpy(oscar[indice].ruolo, r);
        
        char p[n];
        attore.getline(p, n, '\n');
        strcpy(oscar[indice].attore, p);
        
        indice++;
    }while(!attore.eof());
    
    return;
}

void search()
{
    char v[n];
    cout << "Inserisci Nome Completo: ";
    cin.getline(v, '\n');
    if(ctrl(v)) return;
    for (int i = 0; i < indice; i++) {
        if(strcmp(oscar[i].attore, v) == 0){
            cout << "Ruolo: " << oscar[i].ruolo << endl;
            cout << "Anno: " << oscar[i].anno << endl;
            cout << endl;
        }
    }
    return;
}

void stampa(){
    if (indice == 0) {
        cout << "Nessun Attore Inserito..." << endl;
        return;
    }
    cout << "I vincitori Inseriti sono:" << endl;
    for (int j = 0; j < indice; j++) {
        cout << endl;
        cout << "Attore: " << oscar[j].attore << endl;
        cout << "Ruolo: " << oscar[j].ruolo << endl;
        cout << "Anno: " << oscar[j].anno << endl;
        cout << endl;
    }
    return;
}

int main()
{
    file();
    do{
        cout << endl;
        cout << "Premiazioni Oscar" << endl;
        cout << "1_ Stampa Vincitori" << endl;
        cout << "2_ Cerca Attore" << endl;
        cout << "0_ Termina Programma" << endl;
        cin >> fine;
        
        switch (fine) {
            case 1:
                stampa();
                break;
            case 2:
                search();
                break;
            default:
                break;
        }
    }while(fine != 0);
    
    
    return 0;
}


