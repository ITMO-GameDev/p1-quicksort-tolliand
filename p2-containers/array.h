#ifndef ARRAY_H
#define ARRAY_H

template<typename T>
class Array final{
    
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
    private:
        int index;
        Array<T>& array;
    };
    
public:
    Array();
    Array(int capacity);
    Array(const Array &other);
    Array(Array &&other) noexcept;
    ~Array();
    
    void insert(const T& value);
    void insert(int index, const T& value);
    void remove(int index);
    void extend(int extCapacity);
    const T& operator[](int index) const;
    T& operator[](int index);
    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;
    int size() const;
    Iterator iterator();
    const Iterator iterator() const;
    
private: 
    T* array;
    const static int stdCapacity = 8;
    const static int extCapacity = 2;
    int capacity;
    int aSize;
    
};

#include "array.hpp"

#endif
