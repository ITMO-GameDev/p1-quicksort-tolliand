#include "templates.h"

int main() {
    
    int a[10], b[100], c[20] = {1, 2, 3, 16,  4, 15, 5, 6, 17, 8, 9, 10, 11, 12, 13, 14, 7, 18, 19, 20};
    float d[25] = {3.8, 15, 0, 245, 131, 517, 38, 52.7, 312, -987, 56, 135, 781, 92, 3.8, 517, 86, 74, -47, 93, 595, 66, 37, 21, 63};
    float dd[15] = {3.8, 15, 0, 245, 131, 517, 38, 52.7, 312, -987, 56, 135, 781, 92, 3.8};
    char e[30] = {'a', 'b', 'g', 'h', 'd', 'u', 'y', 'f', 'z', 'i', 'a', 'b', 'g', 'h', 'd', 'u', 'y', 'f', 'z', 'i', 'a', 'b', 'g', 'h', 'd', 'u', 'y', 'f', 'z', 'i'};
    const auto comp = [](int a, int b) { return a < b; };
    const auto comp1 = [](float a, float b) { return a < b; };
    const auto comp2 = [](char a, char b) { return a < b; };
    
    std::cout << "a:\n";
    for(int i = 0; i < 10; i++){
        a[i] = 100 - i;
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
    quicksort(a + 0, a + 9, comp);
    for(int i = 0; i < 10; i++){
        std::cout << a[i] << " ";
    }
    std::cout << "\n\n\n";
    
    std::cout << "b:\n";
    for(int i = 0; i < 100; i++){
        b[i] = 100 - i;
        std::cout << b[i] << " ";
    }
    std::cout << "\n";
    quicksort(b + 0, b + 99, comp);
    for(int i = 0; i < 100; i++){
        std::cout << b[i] << " ";
    }
    std::cout << "\n\n\n";
    
    std::cout << "c:\n";
    for(int i = 0; i < 20; i++){
        std::cout << c[i] << " ";
    }
    std::cout << "\n";
    quicksort(c + 0, c + 19, comp);
    for(int i = 0; i < 20; i++){
        std::cout << c[i] << " ";
    }
    std::cout << "\n\n\n";
    
    std::cout << "d:\n";
    for(int i = 0; i < 25; i++){
        std::cout << d[i] << " ";
    }
    std::cout << "\n";
    quicksort(d + 0, d + 24, comp1);
    for(int i = 0; i < 25; i++){
        std::cout << d[i] << " ";
    }
    std::cout << "\n\n\n";
    
    std::cout << "dd:\n";
    for(int i = 0; i < 15; i++){
        std::cout << dd[i] << " ";
    }
    std::cout << "\n";
    quicksort(dd + 0, dd + 14, comp1);
    for(int i = 0; i < 15; i++){
        std::cout << dd[i] << " ";
    }
    std::cout << "\n\n\n";
    
    std::cout << "e:\n";
    for(int i = 0; i < 30; i++){
        std::cout << e[i] << " ";
    }
    std::cout << "\n";
    quicksort(e + 0, e + 29, comp2);
    for(int i = 0; i < 30; i++){
        std::cout << e[i] << " ";
    }
    std::cout << "\n";
    
    return 0;
}
