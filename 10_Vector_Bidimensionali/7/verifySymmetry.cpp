#include <iostream>
#include <vector>
using namespace std;
int main() {
 int rows,cols;
 cout<<"Righe e colonne: ";
 if(!(cin>>rows>>cols)||rows<=0||cols<=0) return 1;
 vector<vector<int>> A(rows,vector<int>(cols));
 for(int i=0;i<rows;++i) for(int j=0;j<cols;++j) if(!(cin>>A[i][j])) return 1;
 bool symmetric=rows==cols;
 if(symmetric) for(int i=0;i<rows;++i) for(int j=i+1;j<cols;++j) if(A[i][j]!=A[j][i]) symmetric=false;
 cout<<(symmetric?"Matrice simmetrica":"Matrice non simmetrica")<<endl;
}
