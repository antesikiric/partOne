#include "HashTable.h"
#include "downloader.h"
#include "utils.h"
#include <iostream>


int main() {
    downloading("https://www.gutenberg.org/files/98/98-0.txt", "output.txt");
    HashTable hash_table;
    processFile("output.txt", hash_table);

    cout << "Most recently inserted key = " << hash_table.get_last() << endl;
    cout << "Least recently inserted key = " << hash_table.get_first() << endl;
}


