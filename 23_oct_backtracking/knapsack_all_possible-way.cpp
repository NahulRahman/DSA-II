#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
int arr[N], brr[N];

void f(int pos, int price, int wt){
    if(pos == -1){
        if(wt <= 4) cout<<price<<"\n";
        return;
    }
    f(pos - 1, price, wt);
    f(pos - 1, price + arr[pos], wt + brr[pos]);
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i]>>brr[i];
    f(n-1, 0, 0);
}
