#include <iostream>
#include <vector>
using namespace std;
void print(const vector<vector<char>>& b) {
 cout<<"  1   2   3\n";
 for(int i=0;i<3;++i){cout<<i+1<<" "<<b[i][0]<<" | "<<b[i][1]<<" | "<<b[i][2]<<'\n';if(i<2) cout<<" ---+---+---\n";}
}
bool win(const vector<vector<char>>& b,char c){
 for(int i=0;i<3;++i) if((b[i][0]==c&&b[i][1]==c&&b[i][2]==c)||(b[0][i]==c&&b[1][i]==c&&b[2][i]==c)) return true;
 return (b[0][0]==c&&b[1][1]==c&&b[2][2]==c)||(b[0][2]==c&&b[1][1]==c&&b[2][0]==c);
}
int main(){
 vector<vector<char>> b(3,vector<char>(3,'.'));print(b);
 for(int turn=0;turn<9;++turn){
 char player=turn%2?'O':'X';int r,c;
 while(true){cout<<"Gioca "<<player<<" (riga colonna, da 1 a 3): ";
 if(!(cin>>r>>c)) return 1;
 if(r>=1&&r<=3&&c>=1&&c<=3&&b[r-1][c-1]=='.') break;
 cout<<"Casella non valida!\n";
 }
 b[r-1][c-1]=player;print(b);
 if(win(b,player)){cout<<"Ha vinto "<<player<<"!\n";return 0;}
 }
 cout<<"Pareggio!\n";
}
