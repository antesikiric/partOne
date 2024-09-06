#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;


const int TABLE_SIZE = 300007;

class HashTable {
    private:
        struct HashNode {
            string key;
            int value;
            HashNode(): key(""), value(-1) {}
        };
        vector<HashNode> table;
        size_t hashFunction(const string &key);
        int findKey(const string &key);
    
    public:
        static list<string> updateOrder;
        HashTable();
        void insert(const string &key, int value);
        void remove(const string &key);
        int get(const string &key);
        string get_last();
        string get_first();
};

#endif