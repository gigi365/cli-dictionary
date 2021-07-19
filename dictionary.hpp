#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <bits/stdc++.h>
using namespace std;

bool loadWords(string filename);
unsigned int hashWord(const string word);
string searchForWord(const string word);
bool unloadDictionary();
string stringToLower(string word);
long getDictionarySize();

#endif
