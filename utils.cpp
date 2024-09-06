#include "utils.h"
#include <fstream>
#include <algorithm>

using namespace std;


string cleanWord(const string &word) {
    string cleaned = "";
    for (char c : word) {
        if (isalnum(c)) {
            cleaned += c;
        }
    }
    return cleaned;
}

void processFile(const string &filename, HashTable &table) {
    ifstream file(filename);
    string word;
    while (file >> word) {
        word = cleanWord(word);
        if (word.empty()) continue;

        if (find(table.updateOrder.begin(), table.updateOrder.end(), word) != table.updateOrder.end()) {
            table.updateOrder.remove(word);
        }
        table.updateOrder.push_back(word);
    }
}