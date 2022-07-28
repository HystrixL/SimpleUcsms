#include "UI/UI.h"

CarInfo test[5];


int main() {
    //初始化系统
    CarInfoNode *head = Init();

    //加载菜单UI
    WelcomeMenu(head);

    return 0;
}