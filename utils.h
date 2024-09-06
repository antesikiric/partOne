#ifndef UTILS_H
#define UTILS_H

#include "HashTable.h"
#include <string>

using namespace std;

string cleanWord(const string &word);
void processFile(const string &filename, HashTable &table);

#endif