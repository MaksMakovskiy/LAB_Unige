#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
 const int SIZE=4,COLORS=6,MAX_TRIES=10;
 srand(unsigned(time(nullptr)));
 vector<int> secret(SIZE);
 for(int i=0;i<SIZE;++i)secret[i]=1+rand()%COLORS;
 cout<<"Mastermind: indovina 4 colori (numeri 1-6), in 10 tentativi.\n";
 for(int turn=1;turn<=MAX_TRIES;++turn){
 vector<int> guess(SIZE);cout<<"Tentativo "<<turn<<": ";
 for(int i=0;i<SIZE;++i)if(!(cin>>guess[i]))return 1;
 bool valid=true;for(int v:guess)if(v<1||v>COLORS)valid=false;
 if(!valid){cout<<"Usa solo numeri da 1 a 6.\n";--turn;continue;}
 int exact=0,misplaced=0;vector<int> sc(COLORS+1,0),gc(COLORS+1,0);
 for(int i=0;i<SIZE;++i){if(guess[i]==secret[i])++exact;else{++sc[secret[i]];++gc[guess[i]];}}
 for(int c=1;c<=COLORS;++c)misplaced+=sc[c]<gc[c]?sc[c]:gc[c];
 if(exact==SIZE){cout<<"Hai vinto!\n";return 0;}
 cout<<"Posizione corretta: "<<exact<<", colore corretto in posizione errata: "<<misplaced<<'\n';
 }
 cout<<"Hai perso! Codice: ";for(int x:secret)cout<<x<<' ';cout<<'\n';
}
