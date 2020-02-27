#include<bits/stdc++.h>
#include"BinaryTree.h"

using namespace std;


int main(){
    btree nuevo;

    nuevo.root->value = '^';
    node* o = nuevo.root->insertRight('~');
    o->insertRight('a');
    nuevo.root->insertLeft('b');
    /*node* o = nuevo.root->insertRight('^');
    o->insertRight('a');
    nuevo.root->insertLeft('c');
    o->insertLeft('b');
    */
    cout << nuevo.value(nuevo.root);
}