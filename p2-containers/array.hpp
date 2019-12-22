#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
Array<T>::Array() : capacity(stdCapacity), aSize(0) {
    array = new T[stdCapacity];
};

template <typename T>
Array<T>::Array(int capacity) : capacity(capacity), aSize(0) {
    array = new T[capacity];
};

template <typename T>
Array<T>::Array(const Array &other) : aSize(other.aSize), capacity(other.capacity){
    array = new T[capacity];

    for (int i = 0; i < aSize; i++){
        array[i] = other.array[i];
    }
};

template <typename T>
Array<T>::Array(Array &&other) noexcept : aSize(other.aSize), capacity(other.capacity){
       
    array = other.array;
    other.array = nullptr;
};

template <typename T>
Array<T>::~Array() {
    delete[] array;
};

template <typename T>
void Array<T>::insert(const T& value) {
    if(aSize == capacity){
        extend(capacity * extCapacity);
    }
    array[aSize] = value;
    aSize++;
    return;
};

template <typename T>
void Array<T>::insert(int index, const T& value) {
    if(aSize == capacity){
        extend(capacity * extCapacity);
    }
    if(index >= 0 && index <= aSize){
        for(int i = aSize; i > index; i--){
            array[i] = array[i - 1];
        }
        array[index] = value;
    } else {
        std::cout << "Wrong index\n";
        return;
    }
    aSize++;
    return;
};

template <typename T>
void Array<T>::remove(int index) {
    if(index >= 0 && index < aSize){
        for(int i = index; i < aSize - 1; i++){
            array[i] = std::move(array[i + 1]);
        }
    } else {
        std::cout << "Wrong index\n";
    }
    aSize--;
    return;
};

template <typename T>
const T& Array<T>::operator[](int index) const {
    if(index >= 0 && index < aSize){
        return array[index];
    }
    throw std::out_of_range("Oops\n");
};

template <typename T>
T& Array<T>::operator[](int index) {
    if(index >= 0 && index < aSize){
        return array[index];
    }
    throw std::out_of_range("Oops\n");
};

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    
    Array tmp(other);
    
    std::swap(array, tmp.array);
    std::swap(capacity, tmp.capacity);
    std::swap(aSize, tmp.aSize);
    
    return *this;
    
};

template <typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept {
    
    std::swap(array, other.array);
    std::swap(capacity, other.capacity);
    std::swap(aSize, other.aSize);
    
    return *this;
    
};

template <typename T>
int Array<T>::size() const {
    return aSize;
};

template <typename T>
void Array<T>::extend(int extCapacity)
{
    Array tmp(extCapacity);

    for (int i = 0; i < aSize; i++)
    {
        tmp.array[i] = std::move(array[i]);
    }

    tmp.aSize = aSize;
    std::swap(*this, tmp);
    
    return;
}

template <typename T>
Array<T>::Iterator::Iterator(Array<T>& a) : index(0), array(a){
};

template<typename T>
const T& Array<T>::Iterator::get() const {
    std::cout << "index: " << this->index << "\n";
    return array[index];
};

template<typename T>
void Array<T>::Iterator::set(const T& value){
    array[index] = value;
    return;
};

template<typename T>
void Array<T>::Iterator::insert(const T& value){
    array.insert(index, value);
    return;
};

template<typename T>
void Array<T>::Iterator::remove(){
    array.remove(index);
    return;
};

template<typename T>
void Array<T>::Iterator::next(){
    index++;
    std::cout << "index: " << this->index << "\n";
    return;
};

template<typename T>
void Array<T>::Iterator::prev(){
    index--;
    std::cout << "index: " << this->index << "\n";
    return;
};

template<typename T>
void Array<T>::Iterator::toIndex(int index){
    this->index = index;
    std::cout << "index: " << this->index << "\n";
    return;
};

template<typename T>
bool Array<T>::Iterator::hasNext() const{
    return index < array.size() - 1;
};

template<typename T>
bool Array<T>::Iterator::hasPrev() const{
    return index > 0;
};

template <typename T>
typename Array<T>::Iterator Array<T>::iterator(){
    Iterator iterator(*this);

    return iterator;
};

template <typename T>
const typename Array<T>::Iterator Array<T>::iterator() const{
    Iterator iterator(*this);

    return iterator;
};

#endif
