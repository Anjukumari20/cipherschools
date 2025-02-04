#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class HashTableChaining {
private:
    vector<list<int>> table;
    int size;
public:
    HashTableChaining(int m) : size(m) {
        table.resize(m);
    }

    void insert(int key) {
        int index = key % size;
        table[index].push_back(key);
    }

    string search(int key) {
        int index = key % size;
        for (int val : table[index]) {
            if (val == key) return "FOUND";
        }
        return "NOT FOUND";
    }

    void remove(int key) {
        int index = key % size;
        table[index].remove(key);
    }
};

class HashTableOpenAddressing {
private:
    vector<int> table;
    vector<bool> occupied;
    int size;
public:
    HashTableOpenAddressing(int m) : size(m) {
        table.resize(m, -1);
        occupied.resize(m, false);
    }

    void insert(int key) {
        int index = key % size;
        while (occupied[index]) {
            index = (index + 1) % size;
        }
        table[index] = key;
        occupied[index] = true;
    }

    string search(int key) {
        int index = key % size;
        int start = index;
        while (occupied[index]) {
            if (table[index] == key) return "FOUND";
            index = (index + 1) % size;
            if (index == start) break;
        }
        return "NOT FOUND";
    }

    void remove(int key) {
        int index = key % size;
        int start = index;
        while (occupied[index]) {
            if (table[index] == key) {
                table[index] = -1;
                occupied[index] = false;
                return;
            }
            index = (index + 1) % size;
            if (index == start) break;
        }
    }
};

int main() {
    int m, q;
    string method;
    cin >> m >> method >> q;

    if (method == "CHAINING") {
        HashTableChaining hashTable(m);
        for (int i = 0; i < q; i++) {
            string operation;
            int key;
            cin >> operation >> key;
            if (operation == "INSERT") {
                hashTable.insert(key);
            } else if (operation == "SEARCH") {
                cout << hashTable.search(key) << endl;
            } else if (operation == "DELETE") {
                hashTable.remove(key);
            }
        }
    } else if (method == "OPEN_ADDRESSING") {
        HashTableOpenAddressing hashTable(m);
        for (int i = 0; i < q; i++) {
            string operation;
            int key;
            cin >> operation >> key;
            if (operation == "INSERT") {
                hashTable.insert(key);
            } else if (operation == "SEARCH") {
                cout << hashTable.search(key) << endl;
            } else if (operation == "DELETE") {
                hashTable.remove(key);
            }
        }
    }
    return 0;
}
