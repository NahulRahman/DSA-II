#include<bits/stdc++.h>
#define n 4
using namespace std;

int a[n+1][n+1];

bool is_safe(int i,int j)
{
        int row = i;
        int col = j;

        while(i>=1 || j>=1)
        {
            if(a[i][j]==1) return false;

            i--;j--;
        }

        i=row;j=col;

        while(i>=1)
        {
            if(a[i][j]==1) return false;

            i--;
        }

        i=row;j=col;

        while(i>=1 || j<n+1)
        {
            if(a[i][j]==1) return false;

            i--; j++;
        }

        return true;
}

void n_queen(int i)
{

    if(i==n+1)
    {

        for(int k=0;k<=n;k++)
        {
               for(int p=0;p<=n;p++)
            {
                cout<<a[k][p]<<" ";
            }
            cout<<endl;
        }

    }

    for(int j=1;j<=n;j++)
    {
        if(is_safe(i,j)==true)
        {
            a[i][j]=1;
            n_queen(i+1);
            a[i][j]=0;
        }

    }

}


int main()
{
    for(int i=0;i<=n;i++)
    {
           for(int j=0;j<=n;j++)
        {
            a[i][j]=0;
        }
    }

    n_queen(1);

//    for(int i=0;i<=n;i++)
//    {
//           for(int j=0;j<=n;j++)
//        {
//            cout<<a[i][j]<<" ";
//        }
//        cout<<endl;
//    }

}

