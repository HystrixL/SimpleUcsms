#include "UI/UI.h"

CarInfo test[5];


int main() {
    //��ʼ��ϵͳ
    CarInfoNode *head = Init();

    //���ز˵�UI
    WelcomeMenu(head);

    return 0;
}