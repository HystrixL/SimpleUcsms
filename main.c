#include "Core/includes.h"
#include "UI/UI.h"

int main() {
    //初始化系统
    CarInfoNode *head = Init();
    //检查数据读入情况
    if (head == NULL) {
        Pause("初始数据读入失败！请检查 .\\data\\data.txt 后再试");
        return 0;
    }
    //加载菜单UI
    WelcomeMenu(head);

    return 0;
}