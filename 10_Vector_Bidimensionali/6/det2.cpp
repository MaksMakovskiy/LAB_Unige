#include <iostream>
#include <vector>
using namespace std;
int main() {
 vector<vector<float>> A(2,vector<float>(2));
 for(int i=0;i<2;++i) for(int j=0;j<2;++j) if(!(cin>>A[i][j])) return 1;
 cout<<"Determinante: "<<A[0][0]*A[1][1]-A[0][1]*A[1][0]<<endl;
}
