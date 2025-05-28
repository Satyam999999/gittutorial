#include<iostream> 
using namespace std;
int N=15;


int main(){
    int a[N][N];
    int b[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            a[i][j]=rand()%10;
            b[i][j]=rand()%10;
        }
    }
int c[N][N];
int d[N][N];
for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
c[i][j]=0;
for(int k=0;k<N;k++){
    c[i][j]+=a[i][j]*b[i][j];
}
    }
}
for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
        cout<<c[i][j]<<" ";
    }
    cout<<endl;
}
int paddedSize = pow(2, ceil(log2(N)));
int paddedMatrix[paddedSize][paddedSize] = {0};

for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
        paddedMatrix1[i][j] = a[i][j];
                paddedMatrix[i][j] = a[i][j];

}