//
// Created by XianY on 2022/6/10.
//

#include "common.h"

CarInfoNode *Init() {
    //������������
    setbuf(stdout, NULL);
    //�����Ļ
    ClearScreen();
    //��ȡ����
    ReadPassword();
    //��������
    CarInfoNode *head = ReadCarFromFile(DATA_PATH);
    if (head == NULL) {
        char str[100];
        sprintf(str, "��ʼ���ݶ���ʧ�ܣ����� %s ������", DATA_PATH);
        Pause(str);
        exit(0);
    }
    return head;
}

void LimitNumber(int *source, int max, int min) {
    if (*source > max) *source = max;
    if (*source < min) *source = min;
}

bool DateCompare(Date date1, Date date2) {
    if (date1.Year < date2.Year) return true;
    else if (date1.Year == date2.Year) {
        if (date1.Mouth < date2.Mouth) return true;
        else if (date1.Mouth == date2.Mouth) {
            if (date1.Day < date2.Day) return true;
        }
    }
    return false;
}