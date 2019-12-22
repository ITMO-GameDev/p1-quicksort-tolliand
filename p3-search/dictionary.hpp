#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <iostream>

template <typename K, typename V> 
Dictionary<K,V>::Dictionary() : aSize(0){
};

template <typename K, typename V> 
Dictionary<K,V>::~Dictionary(){
};

template <typename K, typename V> 
void Dictionary<K,V>::put(const K& key, const V& value){
    dict.insert(key, value);
    aSize++;
    return;
};

template <typename K, typename V> 
void Dictionary<K,V>::remove(const K& key){
    if(contains(key)){
        dict.remove(key);
        aSize--;
    }
    return;
};

template <typename K, typename V> 
bool Dictionary<K,V>::contains(const K& key){
    return dict.search(key) != nullptr;
};

template <typename K, typename V> 
const V& Dictionary<K,V>::operator[](const K& key) const{
    V* tmp = dict.search(key);
    if(tmp != nullptr){
        return *tmp;
    }
    return *new V();
};

template <typename K, typename V> 
V& Dictionary<K,V>::operator[](const K& key){
    V* tmp = dict.search(key);

    if (tmp != nullptr){
        return *tmp;
    }
    V& defaultV = *new V();
    dict.insert(key, defaultV);

    return defaultV;
};

template <typename K, typename V> 
int Dictionary<K,V>::size() const{
    return aSize;
};

template <typename K, typename V>
Dictionary<K,V>::Iterator::Iterator(RBTree<K,V>& dictRef) : dictRef(dictRef){
    currentNode = dictRef.root;
    iteratorRoot = dictRef.root;
    lastNode = currentNode;

    while (lastNode->right != nullptr){
        lastNode = lastNode->right;
    }
    if (lastNode->left != nullptr){
        lastNode = lastNode->left;
    }
    shouldGoDown = true;
};

template<typename K, typename V>
const K& Dictionary<K,V>::Iterator::key() const {
    return currentNode->key;
};

template<typename K, typename V>
const V& Dictionary<K,V>::Iterator::get() const {
    return currentNode->value;
};

template<typename K, typename V>
void Dictionary<K,V>::Iterator::set(const V& value){
    currentNode->value = value;
    return;
};

template<typename K, typename V>
void Dictionary<K,V>::Iterator::next(){
    if(shouldGoDown){
        if(currentNode->left != nullptr){
            currentNode = currentNode->left;
        } else {
            shouldGoDown = false;
        }
    }

    if(!shouldGoDown){
        while (true){
            typename RBTree<K, V>::Node* tmp = currentNode;
            if(currentNode == iteratorRoot){
                break;
            }
            currentNode = currentNode->parent;
            if (currentNode->right != nullptr && currentNode->right != tmp){
                break;
            }
        }
        if(currentNode == iteratorRoot){
            iteratorRoot = currentNode->right;
        }
        currentNode = currentNode->right;
        shouldGoDown = true;
    }
    
    return;
};

template<typename K, typename V>
void Dictionary<K,V>::Iterator::prev(){
    if(currentNode == currentNode->parent->left){
        currentNode = currentNode->parent;
    } else {
        if(currentNode->parent->left == nullptr){
            currentNode = currentNode->parent;
        } else {
            currentNode = currentNode->parent->left;
            while(currentNode->right != nullptr){
                currentNode = currentNode->right;
            }
        }
    }
    return;
};

template<typename K, typename V>
bool Dictionary<K,V>::Iterator::hasNext() const {
    return currentNode != lastNode;
};

template<typename K, typename V>
bool Dictionary<K,V>::Iterator::hasPrev() const {
    return currentNode != dictRef.root;
};

template <typename K, typename V>
typename Dictionary<K, V>::Iterator Dictionary<K, V>::iterator(){
    return *(new Iterator(this->dict));
};

template <typename K, typename V>
const typename Dictionary<K, V>::Iterator Dictionary<K, V>::iterator() const{
    return *(new Iterator(this->dict));
};

#endif
