#include "Core/includes.h"
#include "UI/UI.h"

int main() {
    //��ʼ��ϵͳ
    CarInfoNode *head = Init();
    //������ݶ������
    if (head == NULL) {
        Pause("��ʼ���ݶ���ʧ�ܣ����� .\\data\\data.txt ������");
        return 0;
    }
    //���ز˵�UI
    WelcomeMenu(head);

    return 0;
}