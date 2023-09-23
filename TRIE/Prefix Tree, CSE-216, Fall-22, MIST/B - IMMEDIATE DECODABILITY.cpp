#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int setNumber = 1;
    while (true) {
        vector<string> codes;
        string code;

        while (cin >> code) {
            if (code == "9") {
                break;
            }
            codes.push_back(code);
        }

        if (codes.empty()) {
            break;
        }

        bool decodable = true;

        for (int i = 0; i < codes.size() - 1; i++) {
            for (int j = i + 1; j < codes.size(); j++) {
                if (codes[i] == codes[j].substr(0, codes[i].length()) || codes[j] == codes[i].substr(0, codes[j].length())) {
                    decodable = false;
                    break;
                }
            }
            if (!decodable) {
                break;
            }
        }

        cout << "Set " << setNumber << " is " << (decodable ? "immediately decodable" : "not immediately decodable") << endl;
        setNumber++;
    }

    return 0;
}
