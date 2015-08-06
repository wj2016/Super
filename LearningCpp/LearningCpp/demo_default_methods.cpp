#include <iostream>

/*
 * 学习一下默认生成的4个函数，写法比较简单粗糙，只为演示何时被调用
 */
class A
{
public:
    int a;

    // default constructor
    A() {
        std::cout << "A()   default constructor" << std::endl;
        a = 999;
    }

    // copy constructor
    A(const A& obj) {
        std::cout << "A copy constructor" << std::endl;
        a = obj.a;
    }

    // copy assignment
    A& operator=(const A& obj) {
        std::cout << "A = copy assignment" << std::endl;
        a = obj.a;
        return *this;
    }
    
    // destructor
    ~A() {
        std::cout << "~A()  destructor, a = " << a << std::endl;
    }
};

// 参数就为普通对象类型，会调用到copy constructor构造临时对象，函数返回的时候还要再调用destrctor
void print1(A obj)
{
    std::cout << "AAA: " << obj.a << std::endl;
}
// 如果传引用的话，就不会调用到copy constructor了
void print2(A& obj)
{
    std::cout << "AAA: " << obj.a << std::endl;
}

int main()
{
    std::cout << "====" << std::endl;
    A *pa = new A;
    delete pa;

    std::cout << "====" << std::endl;
    A *pa2 = new A;
    pa2->a = 555;
    A a(*pa2);
    delete pa2;
    
    std::cout << "====" << std::endl;
    A *pa3 = new A;
    pa3->a = 3333;
    A a3;      // default constructor
    a3 = *pa3; // copy assignment
    delete pa3;

    std::cout << "====" << std::endl;
    A a4;
    std::cout << "print1" << std::endl;
    print1(a4);
    std::cout << "print2" << std::endl;
    print2(a4);
    std::cout << "----DONE-----" << std::endl;
    return 0;
}