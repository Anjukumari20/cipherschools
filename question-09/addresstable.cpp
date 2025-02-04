#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DirectAddressTable {
private:
    vector<int> table;
    vector<bool> exists;
public:
    DirectAddressTable(int size) {
        table.resize(size, 0);
        exists.resize(size, false);
    }

    void insert(int key, int value) {
        table[key] = value;
        exists[key] = true;
    }

    string search(int key) {
        if (exists[key]) {
            return to_string(table[key]);
        } else {
            return "NOT FOUND";
        }
    }

    void remove(int key) {
        exists[key] = false;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    DirectAddressTable dat(n);

    for (int i = 0; i < q; i++) {
        string operation;
        cin >> operation;
        if (operation == "INSERT") {
            int key, value;
            cin >> key >> value;
            dat.insert(key, value);
        } else if (operation == "SEARCH") {
            int key;
            cin >> key;
            cout << dat.search(key) << endl;
        } else if (operation == "DELETE") {
            int key;
            cin >> key;
            dat.remove(key);
        }
    }
    return 0;
}
