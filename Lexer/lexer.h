#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <strings.h>
#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <list>

enum simbol
{
    negacion,
    conjuncion,
    implicacion,
    disyuncion
};

using namespace std;

vector<string> split(string);
bool lexer(vector<string>);
bool getTokenLabel(int);
bool getAtomLabel(string);

#endif