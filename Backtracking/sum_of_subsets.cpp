//sum of subsets
#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
int arr[N], target;

int flag;
void f(int pos, vector<int> &v, int sum){
    if(sum == target){
        if(flag) cout<<", ";
        else flag = 1;
        cout<<"{ ";
        for(int i=0;i<v.size();i++) {
            cout<<v[i];
            if(i == v.size() - 1) cout<<" ";
            else cout<<", ";
        }
        cout<<"}";
        return;
    }
    if(pos == -1) return;
    f(pos - 1, v, sum);
    v.push_back(arr[pos]);
    f(pos - 1, v, sum + arr[pos]);
    v.pop_back();
}

int main(){
    int n;
    cin>>n>>target;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> v;
    f(n-1, v, 0);
}
/*
3 2
1 2 1
{ 2 }, { 1, 1 }
Process returned 0 (0x0)   execution time : 4.181 s
Press any key to continue.
*/
