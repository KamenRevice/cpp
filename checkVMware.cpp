/*
 * @Description: 检查是否运行在虚拟机
 * @Version: 0.1
 * @Autor: kaiju
 * @Date: 2023-09-04 15:34:17
 * @LastEditors: kaiju
 * @LastEditTime: 2024-04-10 14:40:29
 */
#include <stdio.h>
#include <stdlib.h>

struct idtr
{
    unsigned short limit;
    unsigned int base;
} __attribute__((packed));

unsigned int get_addr_idt()
{
    struct idtr idtr;
    asm("sidt %0"
        : "=m"(idtr));
    return idtr.base;
}

int main(int argc, char **argv)
{
    printf("============================\n");
    unsigned int ptr_idt;
    ptr_idt = get_addr_idt();
    printf("IDT address: %p \n", ptr_idt);
    if ((ptr_idt >> 24) == 0xc0)
    {
        printf("Real linux\n");
    }
    else
    {
        printf("VMware\n");
    }
    printf("==============\n");
    return 0;
}