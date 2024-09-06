#include "HashTable.h"

list<string> HashTable::updateOrder;

HashTable::HashTable() : table(TABLE_SIZE) {}

size_t HashTable::hashFunction(const string &key) {
    return hash<string>()(key) % TABLE_SIZE;
}

int HashTable::findKey(const string &key) {
    int index = hashFunction(key);
    int original_index = index;

    while (!table[index].key.empty()) {
        if (table[index].key == key) {
            return index;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == original_index) {
            break;
        }
    }
    return -1;
}

void HashTable::insert(const string &key, int value) {
    int index = hashFunction(key);
    int original_index = index;

    while (!table[index].key.empty() && table[index].key != key) {
        index = (index + 1) % TABLE_SIZE;
        if (index == original_index) {
            cout << "Hash table is full" << endl;
            return;
        }
    }
    table[index].key = key;
    table[index].value = value;
}

void HashTable::remove(const string &key) {
    int index = findKey(key);
    if (index != -1) {
        table[index].key = "";
        table[index].value = -1;
    } else {
        cout << "Key not found" << endl;
    }
}

int HashTable::get(const string &key) {
    int index = findKey(key);
    if (index != -1) {
        return table[index].value;
    } else {
        cout << "Key not found" << endl;
    }
    return -1;
}

string HashTable::get_last() {
    return !updateOrder.empty() ? updateOrder.back() : "None";
}

string HashTable::get_first() {
    return !updateOrder.empty() ? updateOrder.front() : "None";
}
