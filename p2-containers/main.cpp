#include "array.h"
#include "list.h"

int main(){
    
    Array<int> a;
    Array<int> b = a;
    for(int i = 0; i < 10; i++){
        a.insert(i * 3);
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
    
    a.insert(4, 6);
    a.remove(0);
    
    for(int i = 0; i < a.size(); i++){
        std::cout << a[i] << " ";
    }
    
    std::cout << "\n";
    
    auto iterator = a.iterator();
    
    std::cout << iterator.get() << "\n";
    iterator.next();
    iterator.next();
    iterator.toIndex(a.size() - 1);
    std::cout << iterator.get() << "\n";
    iterator.remove();
    for(int i = 0; i < a.size(); i++){
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
    std::cout << iterator.get() << "\n";
    return 0;
};
