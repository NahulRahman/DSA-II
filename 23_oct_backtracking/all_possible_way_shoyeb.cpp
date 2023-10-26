#include<bits/stdc++.h>
using namespace std;

int a[3];
int n,ts;

void back_track(int i,int s,vector<int> b)
{

    if(s==0)
    {
        for(int j=0; j<b.size(); j++)
        cout<<b[j]<<" ";
    }

    if(i==n ) return ;

    back_track(i+1 , s , b );
    b.push_back(a[i]);
    back_track(i+1 , s-a[i] , b );

}


int main()
{

    cin>>n>>ts;


    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector <int> b;
    back_track(0,ts,b);

}
