//
// Created by XianY on 2022/7/15.
//


#include "BaseUI.h"

void Pause(char *tip) {
    ClearScreen();
    printf("%s\n\r", tip);
    printf("===========================================\n\r");
    printf("�����������������");
    getch();
}

void UserInput(char *input) {
    printf(UI_INPUT_TIP);
    scanf("%s", input);
}

void EncryptInput(char *input) {
    printf(UI_INPUT_TIP);
    int i = 0;
    //������������ʾתΪ'*'
    while ((input[i] = getch()) != '\r') {
        putch('*');
        i++;
    }
    input[i] = '\0';

}

void PrintPage(CarInfoNode *head, int page) {
    //��ת��ָ��ҳ
    struct CarInfoNode *node = head;
    for (int i = 0; i < page * 10;) {
        if (node == NULL) return;
        node = node->next;
        if (node->isVisible) ++i;
    }
    //��ʾ��ͷ
    ClearScreen();
    printf(UI_INFO_BAR);
    printf("\n\r");
    //��ʾ���ֳ�������Ϣ
    for (int i = 0; i < 10 && node != NULL; node = node->next) {
        if (node->isVisible) {
            PrintCarInfo(node);
            ++i;
        }
    }
    //��ʾҳ��
    printf("========================================================================================================================================================================================================\n\r");
    printf("%d/%d\n\r", page + 1, GetMaxPage(GetNodeCount(head)) + 1);
}

void PrintCarInfo(CarInfoNode *node) {
    printf(DATA_OUTPUT_FORMAT,
           node->data.Id, node->data.Brand, node->data.Model,
           node->data.OriPrice, node->data.PurchasePrice, node->data.ActualPrice,
           node->data.Mileage, node->data.Age, node->data.HaveRepair, node->data.IsFault, node->data.Status,
           node->data.Date.Year, node->data.Date.Mouth, node->data.Date.Day,
           node->data.Seller.Name, node->data.Seller.EstimatedPrice,
           node->data.SalesPerson.Name, node->data.SalesPerson.Id,
           node->data.Customer.Name, node->data.Customer.PhoneNumber,
           node->data.Handler);
    printf("\n\r");
}