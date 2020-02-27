#include<bits/stdc++.h>

using namespace std;

struct node{
	char value;
	node *left;
	node *right;
};

class btree{
public:
	btree();
	~btree();

	void insert(int key);
	node* search(int key);
    node* insertRight(char key, node* leaf);
    node* insertLeft(char key, node* leaf);
	void destroy_tree();
    bool value(node* actual);

	node *root;
    bitset<27>alf;

private:
    bool evaluate(node* actual);
    void all(node* actual,vector<char>&letras);
	void destroy_tree(node *leaf);
	void insert(int key, node *leaf);
	node *search(int key, node *leaf);
    bool conditional(bool a, bool b);
    bool Union(bool pre, bool post, char simbolo);

};


btree::btree(){
	root = new node;
}

btree::~btree(){
	destroy_tree();
}

node* btree::insertRight(char key, node* leaf){
    if(leaf->right == NULL){
        leaf->right = new node;
        leaf->right->value = key;
    }
    else{
        leaf->right->value = key;
    }
    return leaf->right;
}

node* btree::insertLeft(char key, node* leaf){
    if(leaf->left == NULL){
        leaf->left = new node;
        leaf->left->value = key;
    }
    else{
        leaf->left->value = key;
    }
    return leaf->left;
}

void btree::destroy_tree(node *leaf){
	if(leaf != NULL){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::insert(int key, node *leaf){
	if(key < leaf->value){
		if(leaf->left != NULL){
			insert(key, leaf->left);
		}else{
			leaf->left = new node;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}else if(key >= leaf->value){
		if(leaf->right != NULL){
			insert(key, leaf->right);
		}else{
			leaf->right = new node;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}

}

void btree::insert(int key){
	if(root != NULL){
		insert(key, root);
	}else{
		root = new node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

void btree::destroy_tree(){
	destroy_tree(root);
}

void btree::all(node* actual,vector<char>&letras){
    if(actual->value >= 'a' && actual->value <='z'){
        letras.emplace_back(actual->value);
    }
    else{
        if(actual->left!= NULL) all(actual->left, letras);
        if(actual->right!= NULL) all(actual->right, letras);
    }
}

bool btree::value(node* actual){
    vector<char> letras;
    auto copy = actual;

    all(actual,letras);

    for(char i: letras){
        bool x;
        cout << "Valor de verdad para "<< i<< endl;
        cin >> x;
        alf[i-'a'] = x;
    }
    return evaluate(copy);
}

bool btree::evaluate(node* actual){
    if(actual->value >= 'a' && actual->value <='z'){
        return alf[actual->value-'a'];
    }
    else if(actual->value == '~'){
        return !alf[actual->right->value-'a'];
    }
    else{
        bool prop1 = evaluate(actual->left);
        bool prop2 = evaluate(actual->right);
        return Union(prop1,prop2,actual->value);
    }
}

bool btree::Union(bool pre, bool post, char simbolo) {
	bool resp;
	switch(simbolo){
		case '^':
			resp = pre && post;
			break;
		case 'V':
			resp = pre || post;
			break;
		case '>':
			resp = conditional(pre, post);	
			break;
	}
	return resp;
}



bool btree::conditional(bool a, bool b){
    if(a == true && b == false) return false;
    return true;
}

int main(){
    btree nuevo;

    nuevo.root->value = '^';
    
    auto o = nuevo.insertRight('V',nuevo.root);
    nuevo.insertRight('a',o);
    nuevo.insertLeft('c',o);
    nuevo.insertLeft('b',nuevo.root);
    
    cout << nuevo.value(nuevo.root);
    nuevo.destroy_tree();
}