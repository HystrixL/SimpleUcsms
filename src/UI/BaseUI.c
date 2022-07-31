//
// Created by XianY on 2022/7/15.
//


#include "BaseUI.h"

void Pause(char *tip) {
    ClearScreen();
    printf("%s\n\r", tip);
    PrintDividerBar(43);
    printf("�����������������");
    getch();
}

void PrintDividerBar(int length) {
    for (int i = 0; i < length; ++i) {
        printf("%s", DIVIDER_BAR_CHAR);
    }
    printf("\n\r");
}

void UserInput(char *input) {
    printf("%s", UI_INPUT_TIP);
    scanf("%s", input);
}

void EncryptInput(char *input) {
    printf("%s", UI_INPUT_TIP);
    int i = 0;

    while (1) {
        char c = (char) getch();
        if (c == '\r') break;
        if (c == '\b') {
            if (i > 0) {
                input[--i] = '\0';
                printf("\b \b");
            }
            continue;
        }
        input[i++] = c;
        printf("*");
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
    printf("%s", UI_INFO_HEADER);
    printf("\n\r");
    //��ʾ���ֳ�������Ϣ
    for (int i = 0; i < 10 && node != NULL; node = node->next) {
        if (node->isVisible) {
            PrintCarInfo(node);
            ++i;
        }
    }
    //��ʾҳ��
    PrintDividerBar(200);
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