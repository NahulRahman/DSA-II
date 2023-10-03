//LCS in tabulation method
#include <iostream>
#include <vector>
#include <string>

using namespace std;

pair<vector<vector<int> >,vector<vector<string> > > LCS(string X, string Y) {
    int m = X.length();
    int n = Y.length();

    vector<vector<int> > c(m + 1, vector<int>(n + 1, 0));
    vector<vector<string> > b(m + 1, vector<string>(n + 1, ""));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = "";
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = "1";
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = "2";
            }
        }
    }

    return make_pair(c, b);
}

void printAllLCS(vector<vector<string> >& b, string X, int i, int j, string currentLCS) {
    if (i == 0 || j == 0) {
        cout << currentLCS << endl;
        return;
    }

    if (b[i][j] == "") {
        printAllLCS(b, X, i - 1, j - 1, X[i - 1] + currentLCS);
    } else if (b[i][j] == "1") {
        printAllLCS(b, X, i - 1, j, currentLCS);
    } else {
        printAllLCS(b, X, i, j - 1, currentLCS);
    }
}

int main() {
        string X, Y;
        cout << "Enter the first string: ";
        cin >> X;
        cout << "Enter the second string: ";
        cin >> Y;

        pair<vector<vector<int> >, vector<vector<string> > > result = LCS(X, Y);
        vector<vector<int> >& c = result.first;
        vector<vector<string> >& b = result.second;

        int lengthOfLCS = c[X.length()][Y.length()];
        cout << "Length of Longest Common Subsequence: " << lengthOfLCS << endl;

        cout << "Longest Common Subsequences:" << endl;
        printAllLCS(b, X, X.length(), Y.length(), "");

        return 0;


}
