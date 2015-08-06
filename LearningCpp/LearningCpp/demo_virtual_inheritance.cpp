#include <iostream>

/*
 * virtual继承
 */
class VA
{
public:
    int a;
};

class VB : virtual public VA // virtual 继承
{
public:
    int b;
};

class VB2 : virtual public VA // virtual 继承
{
public:
    int b2;
};

class VC : public VB, public VB2
{
public:
    int c;
};

// 非virtual继承的时候
class A
{
public:
    int a;
};

class B : public A
{
public:
    int b;
};

class B2 : public A
{
public:
    int b2;
};

class C : public B, public B2
{
public:
    int c;
};

int main999()
{
    std::cout << "" << std::endl;
    A a;
    std::cout << "size A: " << sizeof(a) << std::endl; // 4
    B b;
    std::cout << "size B: " << sizeof(b) << std::endl; // 8

    C c;
    // 非virtual继承的情况下 size == 20
    // 8 (A.a, B.b) + 8 (A.a, B2.b2) + 4
    std::cout << "size c: " << sizeof(c) << std::endl; // 20
    // c.a = 888;
    c.b = 5;
    c.b2 = 18;

    VA va;
    std::cout << "size vc: " << sizeof(va) << std::endl; // 4
    VB vb;
    std::cout << "size vc: " << sizeof(vb) << std::endl; // 16
    VC vc;
    // virtual继承情况下
    std::cout << "size vc: " << sizeof(vc) << std::endl; // 40
    vc.a = 10;
    vc.b = 20;
    vc.b2 = 100;

    return 0;
}