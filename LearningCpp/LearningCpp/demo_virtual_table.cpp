#include<iostream>

using namespace std;

class Base {
public:
    virtual void f() { cout << "Base::f" << endl; }
    virtual void g() { cout << "Base::g" << endl; }
    virtual void h() { cout << "Base::h" << endl; }
    long num = 505050;
    long num2 = 888888899;
};

typedef void(*Fun)(void);

void print()
{
    cout << "print fun" << endl;
}

int main()
{
    Base obj;
    Fun f = print; // 两个应该相连，但是看起来后定义的变量，地址在最前边

    // 后续假设obj跟p0地址相连，且p0正好在obj前边
    cout << "sizeof(long): " << sizeof(long) << endl; // 8
    cout << "sizeof(Base): " << sizeof(Base) << endl; // 8
    cout << "sizeof(obj): " << sizeof(obj) << endl; // 8
    cout << "sizeof(Fun): " << sizeof(Fun) << endl;
    cout << "sizeof(Fun *): " << sizeof(Fun *) << endl;
    cout << "f  地址：" << &f << endl;
    cout << "对象地址：" << &obj << endl;
    
    f(); // 调用函数
    Fun *p888 = &f;
    (*p888)();

    cout << "对象内存所在地址: " << &obj << endl;
    cout << "虚函数表指针位置：" << (long*)(&obj) << endl; // 虚函数表就存在对象开始地方
    // 取对象obj地址，起始地址8个字节就是指向虚函数表的指针
    Fun **pointer_to_vtable = (Fun **)(&obj);
    cout << "虚函数表地址" << *pointer_to_vtable << endl;

    Fun *pointer_to_1st_fun_in_vtable = *pointer_to_vtable;
    Fun *pointer_to_2nd_fun_in_vtable = *pointer_to_vtable + 1;
    (*pointer_to_1st_fun_in_vtable)(); // Base::f
    (*pointer_to_2nd_fun_in_vtable)(); // Base::g

    // 虚函数表之后，跟的就是变量了
    cout << "对象变量为: " << *((long *)(&obj) + 1) << endl;
    cout << "对象变量为: " << *((long *)(&obj) + 2) << endl;

    return 0;
}