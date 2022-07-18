//
// Created by XianY on 2022/6/10.
//

#include "Permission.h"

static bool isAdmin = false;
static char password[MAX_PWD_LENGTH];

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
    ReadStrFromFile(PWD_PATH, password);
}

int WritePassword() {
    if (SaveStrFromFile(PWD_PATH, password)) {
        return 1;
    } else {
        return 0;
    }
}

int ChangePassword() {
    printf("«Î ‰»Î–¬√‹¬Î(<=19◊÷∑˚)£∫");
    scanf("%s", password);
    return WritePassword();
}