/*inputs:

1 MIST
1 MIT
1 CSE
1 CSE
1 CE
1 MISTCSE
1 ME
1 EECE
1 ABC
1 ABC
1 AB

*/
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int EoW;
    Node* children[26];
    Node() {
        EoW = 0;
        for (int i = 0; i < 26; i++) {
            this->children[i] = NULL;
        }
    }
};

void trie_insert(Node* root, string s) {
    Node* current = root;
    for (char c : s) {
        int index = c - 'A'; // Assuming uppercase letters only
        if (!current->children[index]) {
            current->children[index] = new Node();
        }
        current = current->children[index];
    }
    current->EoW++;
}

int trie_search(Node* root, string s, int k = 0) {
    Node* current = root;
    for (char c : s) {
        int index = c - 'A'; // Assuming uppercase letters only
        if (!current->children[index]) {
            return 0; // Not found
        }
        current = current->children[index];
    }
    return current->EoW;
}

void printTRIEUtil(Node* root, string s) {
    if (root->EoW > 0) {
        cout << s << " (" << root->EoW << ")" << endl;
    }
    for (int i = 0; i < 26; i++) {
        if (root->children[i]) {
            char c = i + 'A'; // Assuming uppercase letters only
            printTRIEUtil(root->children[i], s + c);
        }
    }
}

void printTRIE(Node* root, string s = "") {
    printTRIEUtil(root, s);
}

int main() {
    Node* root = new Node();

    while (1) {
        cout << "1. Insert    2. Search    3. Delete   4. Lexicographical Sorting  5. Display Strings  6. End"
             << endl
             << endl;
        int choice;
        string x;
        cin >> choice;
        if (choice == 1) {
            cout << "Insert String: ";
            cin >> x;
            trie_insert(root, x);
            cout << x << " is inserted in the trie" << endl;
        } else if (choice == 2) {
            cout << "Enter string to search: ";
            cin >> x;
            if (trie_search(root, x) > 0)
                cout << x << " FOUND " << endl;
            else
                cout << x << " NOT FOUND " << endl;
        } else if (choice == 3) {
            cout << "Not yet implemented." << endl;
        } else if (choice == 4) {
            printTRIE(root);
        } else if (choice == 5) {
            printTRIE(root);
        } else if (choice == 6) {
            break;
        } else {
            cout << "Invalid Choice" << endl;
            break;
        }
        cout << endl;
    }
}

/*
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    bool isEndOfWord;
    map<char, Node*> children;

    Node() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* current = root;
        for (char ch : word) {
            if (!current->children[ch]) {
                current->children[ch] = new Node();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    bool search(string word) {
        Node* current = root;
        for (char ch : word) {
            if (!current->children[ch]) {
                return false;
            }
            current = current->children[ch];
        }
        return current->isEndOfWord;
    }
};

int main() {
    Trie trie;

    while (true) {
        cout << "1. Insert    2. Search    3. End" << endl << endl;
        int choice;
        string x;
        cin >> choice;

        if (choice == 1) {
            cout << "Insert String: ";
            cin >> x;
            trie.insert(x);
            cout << x << " is inserted in the trie" << endl;
        } else if (choice == 2) {
            cout << "Enter string to search: ";
            cin >> x;
            if (trie.search(x))
                cout << x << " FOUND " << endl;
            else
                cout << x << " NOT FOUND " << endl;
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid Choice" << endl;
            break;
        }
        cout << endl;
    }

    return 0;
}


*/

/*
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int EoW;
    Node* children[26];
    Node() {
        EoW = 0;
        for (int i = 0; i < 26; i++) {
            this->children[i] = NULL;
        }
    }
};

void trie_insert(Node* root, string s) {
    Node* current = root;
    for (char c : s) {
        int index = c - 'A'; // Assuming uppercase letters only
        if (!current->children[index]) {
            current->children[index] = new Node();
        }
        current = current->children[index];
    }
    current->EoW++;
}

int trie_search(Node* root, string s, int k = 0) {
    Node* current = root;
    for (char c : s) {
        int index = c - 'A'; // Assuming uppercase letters only
        if (!current->children[index]) {
            return 0; // Not found
        }
        current = current->children[index];
    }
    return current->EoW;
}

bool trie_delete(Node* root, string s, int idx = 0) {
    if (!root) return false;

    if (idx == s.length()) {
        if (root->EoW > 0) {
            root->EoW--;
            return true;
        }
        return false;
    }

    int index = s[idx] - 'A'; // Assuming uppercase letters only
    if (!root->children[index]) {
        return false; // Word not found
    }

    bool canDelete = trie_delete(root->children[index], s, idx + 1);

    if (canDelete && root->children[index]->EoW == 0) {
        delete root->children[index];
        root->children[index] = nullptr;
    }

    return canDelete;
}

void printTRIEUtil(Node* root, string s) {
    if (root->EoW > 0) {
        cout << s << " (" << root->EoW << ")" << endl;
    }
    for (int i = 0; i < 26; i++) {
        if (root->children[i]) {
            char c = i + 'A'; // Assuming uppercase letters only
            printTRIEUtil(root->children[i], s + c);
        }
    }
}

void printTRIE(Node* root, string s = "") {
    printTRIEUtil(root, s);
}

int main() {
    Node* root = new Node();

    while (1) {
        cout << "1. Insert    2. Search    3. Delete   4. Lexicographical Sorting  5. Display Strings  6. End"
             << endl
             << endl;
        int choice;
        string x;
        cin >> choice;
        if (choice == 1) {
            cout << "Insert String: ";
            cin >> x;
            trie_insert(root, x);
            cout << x << " is inserted in the trie" << endl;
        } else if (choice == 2) {
            cout << "Enter string to search: ";
            cin >> x;
            if (trie_search(root, x) > 0)
                cout << x << " FOUND " << endl;
            else
                cout << x << " NOT FOUND " << endl;
        } else if (choice == 3) {
            cout << "Enter string to delete: ";
            cin >> x;
            if (trie_delete(root, x))
                cout << x << " DELETED " << endl;
            else
                cout << x << " NOT FOUND " << endl;
        } else if (choice == 4) {
            printTRIE(root);
        } else if (choice == 5) {
            printTRIE(root);
        } else if (choice == 6) {
            break;
        } else {
            cout << "Invalid Choice" << endl;
            break;
        }
        cout << endl;
    }

    return 0;
}
*/





