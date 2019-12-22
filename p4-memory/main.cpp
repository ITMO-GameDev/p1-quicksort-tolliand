#include "memoryalloc.h"

int main(){
        CH fl {1024};
        fl.init();
        fl.dumpStat();
        fl.dumpCH();
        void* a1 = fl.alloc(100);
        fl.dumpStat();
        fl.dumpCH();
        fl.free(a1);
        fl.dumpStat();
        fl.dumpCH();
        fl.free(a1);
        fl.dumpStat();
        fl.dumpCH();
        
               
        FSA fs {256, 5};
        fs.init();
        fs.dumpStat();
        void* b1 = fs.alloc(100);
        fs.dumpStat();
        void* b2 = fs.alloc(100);
        void* b3 = fs.alloc(100);
        fs.dumpStat();
        fs.free(b2);
        fs.dumpStat();
        void* b4 = fs.alloc(200);
        fs.dumpStat();
        fs.free(b1);
        fs.dumpStat();
        void* b5 = fs.alloc(100);
        fs.dumpStat();
        fs.free(b3);
        fs.dumpStat();
        fs.free(b4);
        fs.dumpStat();
        fs.free(b5);
        fs.dumpStat();
    
    std::cout << "Wow" << std::endl;
    
    return 0;
}
