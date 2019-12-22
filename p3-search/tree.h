#ifndef TREE_H
#define TREE_H

typedef enum {
    RED, 
    BLACK
} nodeColor;

template<typename K, typename V>
class RBTree final{
    
    template <typename, typename>
    friend class Dictionary;
public:
    V* search(const K& key);
    void insert(const K& key, const V& value);
    void remove(const K& key);
    
private:
    class Node{
    public:
        Node(const K& k, const V& val);
        K key;
        V value;
        nodeColor color;
        Node* left = nullptr;
        Node* right = nullptr;
        Node* parent = nullptr;
    };
    Node* root = nullptr;
    Node* insert(Node* n, const K& key, const V& value);
    Node* rotateLeft(Node* n);
    Node* rotateRight(Node* n);
    Node* moveRedLeft(Node* n);
    Node* moveRedRight(Node* n);
    void flipColors(Node* n);
    bool isRed(Node* n);
    Node* fixUp(Node* n);
    Node* deleteMin(Node* n);
    Node* minNode(Node* n);
    Node* remove(Node* n, const K& key);
};

#include "tree.hpp"

#endif
