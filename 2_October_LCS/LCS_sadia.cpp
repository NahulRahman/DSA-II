#include<bits/stdc++.h>
using namespace std;
int C[50][50];
void init()
{
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<50;j++)
        {
            C[i][j]=-1;
        }
    }
}
int LCS(string x,string y,int i,int j)
{
    if(i==0||j==0)
    {
        C[i][j]=0;
        return C[i][j];
    }
    if(C[i][j]!=-1)
    {
        return C[i][j];
    }
    if(x[i-1]==y[j-1])
    {
        return C[i][j]=1+LCS(x,y,i-1,j-1);
    }
    /*if(x[i-1]!=y[j-1])
    {
        int ans=0;
        if(i-1>=0)
        {
            ans=max(ans,LCS(x,y,i-1,j));
        }
        if(j-1>=0)
        {
            ans=max(ans,LCS(x,y,i,j-1));
        }
        C[i][j]=ans;
        return C[i][j];
    }*/
    return C[i][j]=max(LCS(x,y,i,j-1),LCS(x,y,i-1,j));
}
int main()
{
    init();
    cout<<"Enter the text :";
    string x;
    cin>>x;
    cout<<"Enter the pattern :";
    string y;
    cin>>y;
    cout<<LCS(x,y,x.size(),y.size())<<"\n";
}
