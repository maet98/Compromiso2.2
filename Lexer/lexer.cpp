#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <strings.h>
#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <regex>
#include <list>
#include "lexer.h"

using namespace std;

vector<string> split(string input)
{
    string ac = "";
    vector<string> ans;
    for (char x : input)
    {
        if (x == ' ')
        {
            ans.emplace_back(ac);
            ac.clear();
        }
        else
        {
            ac.push_back(x);
        }
    }
    ans.emplace_back(ac);
    return ans;
}

bool lexer(vector<string> inputSplitted)
{
    map<string, int> mapper;
    map<string, int>::iterator it;

    mapper["~"] = negacion;
    mapper["^"] = conjuncion;
    mapper[">"] = implicacion;
    mapper["V"] = disyuncion;

    for (int i = 0; i < inputSplitted.size(); ++i)
    {
        if(mapper.count(inputSplitted[i])||getAtomLabel(inputSplitted[i])) continue;
        return false;
    }
}

bool getAtomLabel(string inputSplitted){

    if(inputSplitted[0] >='a' && inputSplitted[0]<='z')
        return true;
    else
        return false;
}