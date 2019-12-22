#ifndef TREE_HPP
#define TREE_HPP

template <typename K, typename V>
RBTree<K, V>::Node::Node(const K& k, const V& val) : key(k), value(val), color(RED){
};

template <typename K, typename V>
V* RBTree<K, V>::search(const K& key){
    
    Node* tmp = root;
    while (tmp != nullptr){
        if (key == tmp->key) {
            return &(tmp->value);
        } else if (key < tmp->key){
            tmp = tmp->left;
        } else if (key > tmp->key){
            tmp = tmp->right;
        }
    }

    return nullptr;
};

template <typename K, typename V>
void RBTree<K, V>::insert(const K& key, const V& value){
    root = insert(root, key, value);
    root->color = BLACK;
    return;
};

template <typename K, typename V>
void RBTree<K, V>::remove(const K& key){
    root = remove(root, key);
    if (root != nullptr){
        root->color = BLACK;
    }
    return;
};

template <typename K, typename V>
typename RBTree<K, V>::Node* RBTree<K, V>::insert(Node* n, const K& key, const V& value){
    if(n == nullptr){
        return new Node(key, value);
    }
    
    if(n->key == key){
        n->value = value;
    } else if(n->key > key){
        Node* tmp = insert(n->left, key, value);
        tmp->parent = n;
        n->left = tmp;
    } else {
        Node* tmp = insert(n->right, key, value);
        tmp->parent = n;
        n->right = tmp;
    }
    
    n = fixUp(n);
    
    return n;
};

template <typename K, typename V>
typename RBTree<K, V>::Node* RBTree<K, V>::rotateLeft(Node* n){
    Node* p = n->right;
    n->right = p->left;
    p->left = n;
    if(n->right != nullptr){
        n->right->parent = n;
    }
    p->parent = n->parent;
    n->parent = p;
    
    p->color = n->color;
    n->color = RED;
    
    return p;
};

template <typename K, typename V>
typename RBTree<K, V>::Node* RBTree<K, V>::rotateRight(Node* n){
    Node* p = n->left;
    n->left = p->right;
    p->right = n;
    if(n->left != nullptr){
        n->left->parent = n;
    }
    p->parent = n->parent;
    n->parent = p;
    
    p->color = n->color;
    n->color = RED;
    
    return p;
};

template <typename K, typename V>
typename RBTree<K, V>::Node* RBTree<K, V>::moveRedLeft(Node* n){
    flipColors(n);

    if(isRed(n->right->left)){
        n->right = rotateRight(n->right);
        n = rotateLeft(n);
        flipColors(n);
    }

    return n;
};

template <typename K, typename V>
typename RBTree<K, V>::Node* RBTree<K, V>::moveRedRight(Node* n){
    flipColors(n);

    if(isRed(n->left->left)){
        n = rotateRight(n);
        flipColors(n);
    }

    return n;
};

template <typename K, typename V>
void RBTree<K, V>::flipColors(Node* n){
    if(n->color == RED){
        n->color = BLACK;
    } else {
        n->color = RED;
    }
    if(n->right->color == RED){
        n->right->color = BLACK;
    } else {
        n->right->color = RED;
    }
    if(n->left->color == RED){
        n->left->color = BLACK;
    } else {
        n->left->color = RED;
    }
    return;
};

template <typename K, typename V>
bool RBTree<K, V>::isRed(Node* n){
    if(n == nullptr){
        return false;
    }
    return n->color == RED;
};

template <typename K, typename V>
typename RBTree<K, V>::Node* RBTree<K, V>::fixUp(Node* n){
    if(isRed(n->right) && !isRed(n->left)){
        n = rotateLeft(n);
    } 
    if(isRed(n->left) && isRed(n->left->left)){
        n = rotateRight(n);
    }
    if(isRed(n->left) && isRed(n->right)){
        flipColors(n);
    }
    
    return n;
};

template <typename K, typename V>
typename RBTree<K, V>::Node* RBTree<K, V>::deleteMin(Node* n){
    if (n->left == nullptr){
        return nullptr;
    }

    if (!isRed(n->left) && !isRed(n->left->left)){
        n = moveRedLeft(n);
    }

    n->left = deleteMin(n->left);

    return fixUp(n);
};

template <typename K, typename V>
typename RBTree<K, V>::Node* RBTree<K, V>::minNode(Node* n){
    return (n->left == nullptr) ? n : minNode(n->left);
};

template <typename K, typename V>
typename RBTree<K, V>::Node* RBTree<K, V>::remove(Node* n, const K& key){
    if(key < n->key){
        if(!isRed(n->left) && !isRed(n->left->left)){
            n = moveRedLeft(n);
        }
        n->left = remove(n->left, key);
    } else {
        if(isRed(n->left)){
            n = rotateRight(n);
        }
        if(key == n->key && n->right == nullptr){
            return nullptr;
        }

        if(!isRed(n->right) && !isRed(n->right->left)){
            n = moveRedRight(n);
        }

        if(key == n->key){
            Node* minN = minNode(n->right);
            n->value = minN->value;
            n->key = minN->key;
            n->right = deleteMin(n->right);
        } else {
            n->right = remove(n->right, key);
        }
    }

    return fixUp(n);
};

#endif
