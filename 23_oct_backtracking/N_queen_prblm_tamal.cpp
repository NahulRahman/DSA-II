#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int arr[N][N], mark[N][N], n;

bool isSafe(int row, int col){
    for(int i=row, j=col; j>=1; i--, j--) if(mark[i][j]) return false;
    for(int i=row, j=col; j<=n; i--, j++) if(mark[i][j]) return false;
    for(int i=row; i>=1; i--) if(mark[i][col]) return false;
    return true;
}

int cnt;

void f(int i){
    if(i > n) cnt++;
    for(int k=1;k<=n;k++){
        if(isSafe(i, k)){
            mark[i][k] = 1;
            f(i+1);
            mark[i][k] = 0;
        }
    }
}

int main(){
    cin>>n;
    f(1);
    cout<<"The ways of combination "<<cnt<<endl;
}
