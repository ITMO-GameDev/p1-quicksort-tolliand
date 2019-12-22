#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "tree.h"

template<typename K, typename V>
class Dictionary final{
    
    class Iterator{
    public: 
        Iterator(RBTree<K,V>& dictRef);
        const K& key() const;
        const V& get() const;
        void set(const V& value);
        void next();
        void prev();
        bool hasNext() const;
        bool hasPrev() const;
    private:
        int index;
        RBTree<K,V>& dictRef;
        typename RBTree<K, V>::Node* currentNode;
        typename RBTree<K, V>::Node* iteratorRoot;
        typename RBTree<K, V>::Node* lastNode;
        bool shouldGoDown;
    };
    
public:
    Dictionary();
    ~Dictionary();
    
    void put(const K& key, const V& value);
    void remove(const K& key);
    bool contains(const K& key);
    const V& operator[](const K& key) const;
    V& operator[](const K& key);
    int size() const;
    Iterator iterator();
    const Iterator iterator() const;
private:
    RBTree<K, V> dict;
    int aSize;
};

#include "dictionary.hpp"
    
#endif
