//
// Created by XianY on 2022/7/15.
//

#include "Login.h"

bool AdminLogin() {
    //用户加密输入
    printf("\n\r请输入您的管理员密码");
    char inputPwd[MAX_PWD_LENGTH];
    EncryptInput(inputPwd);
    if (!strcmp(inputPwd, GetPassword())) {//验证密码
        printf("\n\r密码正确！请按任意键继续~");
        getch();
        return true;
    } else {
        printf("\n\r密码错误！请检查后重新输入。");
        getch();
        return false;
    }
}