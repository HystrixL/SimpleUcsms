//
// Created by XianY on 2022/7/15.
//

#include "Login.h"

bool AdminLogin() {
    //�û���������
    printf("\n\r���������Ĺ���Ա����");
    char inputPwd[MAX_PWD_LENGTH];
    EncryptInput(inputPwd);
    if (!strcmp(inputPwd, GetPassword())) {//��֤����
        printf("\n\r������ȷ���밴���������~");
        getch();
        return true;
    } else {
        printf("\n\r�������������������롣");
        getch();
        return false;
    }
}