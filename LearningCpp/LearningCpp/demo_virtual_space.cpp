#include <iostream>

namespace demo_virtual_space {

/*
 * 不是作为Base的类，没必要virtual destructor
 */
class A
{
public:
    int a;
};

class A1 : public A
{
public:
    ~A1() { std::cout << "a method" << std::endl; } // 函数不影响内存大小
};

class A2 : public A
{
public:
    virtual ~A2() { std::cout << "a virtual method" << std::endl; } // 虚函数增加虚函数表大小
};

int main999()
{
    std::cout << "Hello" << std::endl;
    A *p = new A;
    std::cout << "Size: " << sizeof(*p) << std::endl; // 4
    delete p;
    
    A1 *p1 = new A1;
    std::cout << "Size A1: " << sizeof(*p1) << std::endl; // 4
    delete p1;
    
    A2 *p2 = new A2;
    std::cout << "Size A2: " << sizeof(*p2) << std::endl; // 16
    delete p2;
    
    return 0;
}

}