tree min(tree a) {
    while (a->left != NULL) {
        a = a->left;
    }
    return a;
}

tree deleteroot(tree a, int key) {
    if (a == NULL) {
        return NULL; 
    }

    if (key < a->node.number) {
        a->left = deleteroot(a->left, key); 
    } else if (key > a->node.number) {
        a->right = deleteroot(a->right, key);
    } else {
        

        
        if (a->left == NULL && a->right == NULL) {
            delete(a);
            return NULL;
        }

       
        if (a->left == NULL) {
            tree temp = a->right;
            delete (a);
            return temp;
        }
        if (a->right == NULL) {
            tree temp = a->left;
            delete (a);
            return temp;
        }

      
        tree minNode = a->right;
        while (minNode->left != NULL) {
            minNode = minNode->left;
        }

        a->node = minNode->node;

        a->right = deleteroot(a->right, minNode->drug.number);
    }

    return a;
}

tree deletefromtree(tree a, int key) {
	 tree p = nodesearch(a, key);
    if (p != NULL) {
        if (p->node.number == key) {
            a = deleteroot(p,key);
        } else {
            if (key < a->node.number) {
                p->left = deleteroot(p->left, key);
            }
            else {
                p->right = deleteroot(p->right, key);
            }
        }
    }
    return a;
}
