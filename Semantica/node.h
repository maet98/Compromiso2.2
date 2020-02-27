struct node{
	char value;
	node *left;
	node *right;

    node* insertRight(char key){
        if(right == NULL){
            right = new node;
            right->value = key;
        }
        else{
            right->value = key;
        }
        return right;
    }

    node* insertLeft(char key){
        if(left == NULL){
            left = new node;
            left->value = key;
        }
        else{
            left->value = key;
        }
        return left;
    }
};