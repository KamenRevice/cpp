/*
 * @Description: 
 * @Version: 0.1
 * @Autor: kaiju
 * @Date: 2024-04-23 16:03:38
 * @LastEditors: kaiju
 * @LastEditTime: 2024-04-24 20:02:01
 */
#include<stdio.h>
#include<windows.h>

DWORD WINAPI ThreadProc(LPVOID lpParameter) {
    for (int i = 0;i < 100;i++) {
        Sleep(500);
        printf("++++++++++++%d\n", i);
    }
    return 0;
}

int main() {
    HANDLE hThread;
    hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
    CloseHandle(hThread);

    for (int i = 0;i < 100;i++) {
        Sleep(500);
        printf("------------%d\n", i);
    }
    return 0;
}