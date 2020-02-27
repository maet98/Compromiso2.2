#include<bits/stdc++.h>
#include "BinaryTree.h"
#include "node.h"

using namespace std;

int main(int argc, char **argv){
    btree nuevo;

    nuevo.root->value = '^';
    node* o = nuevo.root->insertRight('~');
    o->insertRight('a');
    nuevo.root->insertLeft('b');
    cout << nuevo.value(nuevo.root);
}