#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include "lexer.h"

using namespace std;

int main(int argc, char **argv)
{
    string input = string(argv[1]);
    vector<string> inputSplitted = split(input);
    if(lexer(inputSplitted))
        cout << "Valid string";
    else
        cout << "Invalid string";
}