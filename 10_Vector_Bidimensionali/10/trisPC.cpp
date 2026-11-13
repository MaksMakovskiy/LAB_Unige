#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
void print(const vector<vector<char>>& b){
 cout<<"  1   2   3\n";
 for(int i=0;i<3;++i){cout<<i+1<<" "<<b[i][0]<<" | "<<b[i][1]<<" | "<<b[i][2]<<'\n';if(i<2)cout<<" ---+---+---\n";}
}
bool win(const vector<vector<char>>& b,char p){
 for(int i=0;i<3;++i)if((b[i][0]==p&&b[i][1]==p&&b[i][2]==p)||(b[0][i]==p&&b[1][i]==p&&b[2][i]==p))return true;
 return (b[0][0]==p&&b[1][1]==p&&b[2][2]==p)||(b[0][2]==p&&b[1][1]==p&&b[2][0]==p);
}
int main(){
 srand(unsigned(time(nullptr)));vector<vector<char>> b(3,vector<char>(3,'.'));print(b);
 for(int turn=0;turn<9;++turn){
 int r,c;char p=turn%2?'O':'X';
 if(p=='X'){
 while(true){cout<<"Gioca X (riga colonna, da 1 a 3): ";if(!(cin>>r>>c))return 1;
 --r;--c;if(r>=0&&r<3&&c>=0&&c<3&&b[r][c]=='.')break;cout<<"Casella non valida!\n";}
 }else{
 vector<int> freeCells;for(int i=0;i<9;++i)if(b[i/3][i%3]=='.')freeCells.push_back(i);
 int pos=freeCells[rand()%freeCells.size()];r=pos/3;c=pos%3;
 cout<<"PC gioca: "<<r+1<<" "<<c+1<<'\n';
 }
 b[r][c]=p;print(b);if(win(b,p)){cout<<"Ha vinto "<<p<<"!\n";return 0;}
 }cout<<"Pareggio!\n";
}
