#ifndef TEMPLATES_H
#define TEMPLATES_H

#include "templates.hpp"

/*template <typename T>
bool comp(const T &a, const T &b);*/

template<typename T>
void swap(T* a, T* b);

template <typename T> 
T median(T &a, T &b, T &c);

template <typename T>
int partition(T a[], T *first, T *last);

template <typename T, typename Compare>
void insertionSort(T *first, T *last, Compare comp);

template <typename T, typename Compare>
void quicksort(T a[], T *first, T *last, Compare comp);

#endif
