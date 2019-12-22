#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <iostream>

const int N = 14;

template<typename T>
void swap(T* a, T* b) {
    
	T tmp = *a;
	*a = *b;
	*b = tmp;
	return;
    
}

template <typename T> 
T median(T *a, T *b){
    
    T *c = a + (b - a) / 2;
	if (*a >= *b && *a <= *c){
		return *a;
    } else if (*b >= *a && *b <= *c){
		return *b;
    }
	return *c;
    
}

template <typename T, typename Compare>
int partition(T *first, T *last, Compare comp){
    
    int length = last - first + 1;
    T pivot = median(first, last);
    std::cout << "Pivot: " << pivot << "\n";
    
    int left = 0;
	int right = length - 1;
	while(left < right){
		//while(comp(first[left], pivot)){
        while(first[left] <=  pivot){
			left++;
        }
		//while(comp(pivot, first[right])){
        while(pivot < first[right]){
			right--;
        }
		if(left < right){
            std::cout << "changed " << first[left] << " " << first[right] << "\n";
			swap(&first[left], &first[right]);
			left++;
			right--;
		}
	}
	
	return left;
}

template <typename T, typename Compare>
void insertionSort(T *first, T *last, Compare comp) {
    
	int length = last - first + 1;
    
	for(int i = 1; i < length; i++){
		for(int j = i; j > 0 && !comp(*(first + j - 1), *(first + j)); j--){
			swap(first + j - 1, first + j);
        }
    }
    
    return;
}

template <typename T, typename Compare>
void quicksort(T *first, T *last, Compare comp){
    
    std::cout << "Entered quicksort with " << *first << " " << *last << " " << last - first + 1 << "\n";
    while(first < last){
        int partLength = last - first + 1;
        T *temp = first;
        while(temp <= last){
            std::cout << *temp << " ";
            temp++;
        }
        std::cout << "\n";
        
        if(partLength < N){
            insertionSort(first, last, comp);
            return;
        } else {
            int j = partition(first, last, comp);
             std::cout << "Part: " << j << "\n";
            
            if(j < (partLength - j)){
                quicksort(first, first + j - 1, comp);
                first = first + j;
            } else {
                quicksort(first + j, last, comp);
                last = first + j - 1;
            }
        }
    }
    
    return;
}

#endif
