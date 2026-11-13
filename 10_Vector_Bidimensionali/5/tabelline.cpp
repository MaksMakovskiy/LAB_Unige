#include <iostream>
#include <vector>
using namespace std;
int main() {
 const int N=10;
 vector<vector<int>> tavolaPitagorica(N,vector<int>(N));
 for(int i=0;i<N;++i) for(int j=0;j<N;++j) tavolaPitagorica[i][j]=(i+1)*(j+1);
 int a,b;
 do { cout<<"Inserisci due numeri tra 1 e 10: "; if(!(cin>>a>>b)) return 1; } while(a<1||a>10||b<1||b>10);
 cout<<tavolaPitagorica[a-1][b-1]<<endl;
}
