//
// Created by XianY on 2022/6/10.
//

#include "Permission.h"

static bool isAdmin = false;
static char password[MAX_PASSWORD_LENGTH];

void SetIsAdmin(bool input) {
    isAdmin = input;
}

bool GetIsAdmin() {
    return isAdmin;
}

char *GetPassword() {
    return password;
}

void ReadPassword() {
    ReadStrFromFile(PASSWORD_PATH, password);
}

OperationResult WritePassword() {
    return SaveStrFromFile(PASSWORD_PATH, password);
}

OperationResult ChangePassword() {
    printf("�����볤�� %d ���ڵ������룺", MAX_PASSWORD_LENGTH);
    scanf("%s", password);
    return WritePassword();
}