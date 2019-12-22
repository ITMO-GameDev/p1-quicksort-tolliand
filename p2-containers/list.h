#ifndef LIST_H
#define LIST_H

template<typename T>
class List final{
    
    class Iterator{
    public: 
        Iterator(Array<T>& a);
        const T& get() const;
        void set(const T& value);
        void insert(const T& value);
        void remove();
        void next();
        void prev();
        void toIndex(int index);
        bool hasNext() const;
        bool hasPrev() const;
        
    };
    
public:
    List();
    ~List();
    
    void insert_head(const T& value);
    void insert_tail(const T& value);
    void remove_head();
    void remove_tail();
    const T& head() const;
    const T& tail() const;
    int size() const;
    Iterator iterator();
    const Iterator interator() const;
};

#include "list.hpp"

#endif
