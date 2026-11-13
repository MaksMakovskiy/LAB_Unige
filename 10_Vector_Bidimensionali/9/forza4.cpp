#include <iostream>
#include <vector>
using namespace std;
const int R=6,C=7;
void print(const vector<vector<char>>& b){
 for(int r=0;r<R;++r){for(int c=0;c<C;++c) cout<<b[r][c]<<' ';cout<<'\n';}
 cout<<"1 2 3 4 5 6 7\n";
}
bool win(const vector<vector<char>>& b,int r,int c,char p){
 const int dr[]={0,1,1,1},dc[]={1,0,1,-1};
 for(int d=0;d<4;++d){int count=1;
 for(int sign=-1;sign<=1;sign+=2){int y=r+sign*dr[d],x=c+sign*dc[d];
 while(y>=0&&y<R&&x>=0&&x<C&&b[y][x]==p){++count;y+=sign*dr[d];x+=sign*dc[d];}}
 if(count>=4) return true;
 }return false;
}
int main(){
 vector<vector<char>> b(R,vector<char>(C,'.'));print(b);
 for(int turn=0;turn<R*C;++turn){
 char p=turn%2?'O':'X';int col;
 while(true){cout<<"Gioca "<<p<<" (colonna 1-7): ";if(!(cin>>col))return 1;
 if(col>=1&&col<=C&&b[0][col-1]=='.')break;cout<<"Colonna non valida!\n";}
 int c=col-1,r=R-1;while(b[r][c]!='.')--r;b[r][c]=p;print(b);
 if(win(b,r,c,p)){cout<<"Ha vinto "<<p<<"!\n";return 0;}
 }cout<<"Pareggio!\n";
}
