#include <bits/stdc++.h>
using namespace std;

// learn abot i-- just increase i dont chage i in previous call

char arr[100][100];

int c[100][100];
int lcs(string x, string y, int i, int j)
{
    if (i == 0 or j == 0) return c[i][j] = 0;
    if (c[i][j] != -1) return c[i][j];
    if (x[i - 1] == y[j - 1]) return c[i][j] = 1 + lcs(x, y, i - 1, j - 1); //arr[i][j] = 'c';
    else return c[i][j] = max(lcs(x, y, i - 1, j), lcs(x, y, i, j - 1));
}

int main()
{

    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            c[i][j] = -1;
        }
    }

    string x = "abcb", y = "bdc";
    cout << lcs(x, y, x.length(), y.length()) << endl;
}
