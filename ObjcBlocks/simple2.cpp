/*
 * 这个代码主要来源于simple.m然后配上命令
 * clang -fobjc-arc -rewrite-objc simple.m
 * 所做修改：
 * 1 去除掉不相干的无用代码
 * 2 改写（去除了export的部分）定义了_NSConcreteStackBlock
 * 3 刚开始直接运行的话，main函数中报错error: taking the address of a temporary object of type '__main_block_impl_0'
 * 然后也没看懂错误提示，也没弄明白怎么查看类型，就加了个临时变量，用auto定义，然后Xcode里断点，expr tempObj出来了
 * 结果类型就是刚才错误提示里已经说了的__main_block_impl_0
 * 之后就可以放入Xcode运行了
 */
#include <stdio.h>

void *_NSConcreteStackBlock[32];

struct __block_impl {
    void *isa;
    int Flags;
    int Reserved;
    void *FuncPtr;
};

struct __main_block_impl_0 {
    struct __block_impl impl;
    struct __main_block_desc_0* Desc;
    __main_block_impl_0(void *fp, struct __main_block_desc_0 *desc, int flags=0) { // 这里是构造函数，C++里可以用struct来表示类的概念
        impl.isa = &_NSConcreteStackBlock;
        impl.Flags = flags;
        impl.FuncPtr = fp;
        Desc = desc;
    }
};

static void __main_block_func_0(struct __main_block_impl_0 *__cself)
{
    printf("Block\n");
}

static struct __main_block_desc_0 {
    size_t reserved;
    size_t Block_size;
} __main_block_desc_0_DATA = { 0, sizeof(struct __main_block_impl_0)};

int main()
{
    __main_block_impl_0 tempObj = __main_block_impl_0((void *)__main_block_func_0, &__main_block_desc_0_DATA);
    void (*blk)(void) = (void (*)())&tempObj;
    ((void (*)(__block_impl *))((__block_impl *)blk)->FuncPtr)((__block_impl *)blk);
    return 0;
}
