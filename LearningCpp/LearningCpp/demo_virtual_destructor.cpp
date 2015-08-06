#include <iostream>

using namespace std;

/*
 * 演示virtual destructor
 */
class Base
{
public:
    virtual ~Base() // virtual destructor in base class
    {
        std::cout << "~Base" << std::endl;
    }
};

class Derived:public Base
{
public:
    ~Derived()
    {
        std::cout << "~Derived" << std::endl;
    }
};

class Base2
{
public:
    ~Base2() // not virtual destructor
    {
        std::cout << "~Base2" << std::endl;
    }
};

class Derived2:public Base2
{
public:
    ~Derived2()
    {
        std::cout << "~Derived2" << std::endl;
    }
};

int main()
{
    std::cout << "====" << std::endl;
    Derived *pd = new Derived; // 子类析构 => 父类析构
    delete pd;

    std::cout << "====" << std::endl;
    Base *pb = new Derived;    // 子类析构 => 父类析构
    delete pb;

    std::cout << "====" << std::endl;
    Base2 *pb2 = new Derived2; // 仅仅调用父类析构!!!
    delete pb2;

    return 0;
}