//
// Created by XianY on 2022/6/10.
//

#include "File.h"

CarInfoNode *ReadCarFromFile(const char *path) {
    //打开文件，准备读取
    FILE *file;
    file = fopen(path, "r");

    if (file == NULL) {
        return NULL;
    };

    CarInfoNode *head = NULL;
    CarInfoNode *ptr, *pp;

    while (!feof(file)) {

        //创建头节点
        if (head == NULL) {
            head = (CarInfoNode *) malloc(sizeof(CarInfoNode));
            head->next = NULL;
            head->prior = NULL;
            pp = head;
            ptr = head;
        } else {//创建非头节点
            ptr = (CarInfoNode *) malloc(sizeof(CarInfoNode));
            ptr->next = NULL;
            ptr->prior = NULL;
        }
        //读入数据
        int t = fscanf(file, DATA_INPUT_FORMAT,
                       &ptr->data.Id, ptr->data.Brand, ptr->data.Model,
                       &ptr->data.OriPrice, &ptr->data.PurchasePrice, &ptr->data.ActualPrice,
                       &ptr->data.Mileage, &ptr->data.Age, &ptr->data.HaveRepair, &ptr->data.IsFault, ptr->data.Status,
                       &ptr->data.Date.Year, &ptr->data.Date.Mouth, &ptr->data.Date.Day,
                       ptr->data.Seller.Name, &ptr->data.Seller.EstimatedPrice,
                       ptr->data.SalesPerson.Name, &ptr->data.SalesPerson.Id,
                       ptr->data.Customer.Name, ptr->data.Customer.PhoneNumber,
                       ptr->data.Handler);
        ptr->isVisible = true;

        //与前置节点相连
        if (ptr != head) {
            pp->next = ptr;
            ptr->prior = pp;
            pp = pp->next;
        }
    }
    fclose(file);

    return head;
}

int SaveCarToFile(const char *path, const CarInfoNode *head) {
    if (head == NULL) return 0;
    //打开文件，准备写入
    FILE *file;
    file = fopen(path, "w");

    if (file == NULL) {
        return 1;
    };

    for (const CarInfoNode *node = head; node != NULL; node = node->next) {
        //非首条信息时进行换行，可确保文件头尾无多余换行符
        if (node != head)fprintf(file, "\n");
        //写入数据
        fprintf(file, DATA_INPUT_FORMAT,
                node->data.Id, node->data.Brand, node->data.Model,
                node->data.OriPrice, node->data.PurchasePrice, node->data.ActualPrice,
                node->data.Mileage, node->data.Age, node->data.HaveRepair, node->data.IsFault, node->data.Status,
                node->data.Date.Year, node->data.Date.Mouth, node->data.Date.Day,
                node->data.Seller.Name, node->data.Seller.EstimatedPrice,
                node->data.SalesPerson.Name, node->data.SalesPerson.Id,
                node->data.Customer.Name, node->data.Customer.PhoneNumber,
                node->data.Handler);
    }

    fclose(file);

    return 0;
}

__attribute__((unused)) int GetFileLines(const char *path) {
    FILE *file;
    file = fopen(path, "r");

    if (file == NULL) return -1;

    int i = 0;
    while (!feof(file)) {
        int t = fscanf(file, "");
        i++;
    }
    fclose(file);

    return i;
}

void ReadStrFromFile(const char *path, const char *content) {
    //打开文件，准备读取
    FILE *file;
    file = fopen(path, "r");

    if (file == NULL) {
        return;
    };
    //读取字符串
    int t = fscanf(file, "%s", content);

    fclose(file);
}

int SaveStrFromFile(const char *path, const char *content) {
    //打开文件，准备写入
    FILE *file;
    file = fopen(path, "w");

    if (file == NULL) {
        return 1;
    };
    //写入字符串
    fprintf(file, "%s", content);

    fclose(file);
    return 0;
}