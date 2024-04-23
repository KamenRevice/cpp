/*
 * @Description:https://mp.weixin.qq.com/s/e5TlFOP3M7HiavoHMPH7-g
 * @Version: 0.1
 * @Autor: kaiju
 * @Date: 2024-04-23 13:18:14
 * @LastEditors: kaiju
 * @LastEditTime: 2024-04-23 13:27:07
 */
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>

void fun(char** p) {
    *p = (char*)malloc(100);
}

int main() {
    char* p = NULL;
    fun(&p);
    free(p);
    if (p != NULL) {
        strcpy(p, "hello world");
        printf(p);
    }
}