//
// Created by XianY on 2022/6/30.
//

#include "Data.h"


void AppendNode(CarInfoNode *head, CarInfo carInfo) {
    if (head == NULL) return;

    CarInfoNode *ptr = (CarInfoNode *) calloc(1, sizeof(carInfo));
    ptr->data = carInfo;
    ptr->isVisible = true;

    CarInfoNode *pp = head;

    while (pp->next != NULL) {
        pp = pp->next;
    }

    pp->next = ptr;
    ptr->prior = pp;
}

void LinkList(CarInfoNode *head1, CarInfoNode *head2) {
    if (head1 == NULL || head2 == NULL) return;

    CarInfoNode *ptr = head1;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = head2;
    head2->prior = ptr;
}

CarInfoNode *DeleteNode(CarInfoNode *head, CarInfoNode *node) {
    if (node == NULL || head == NULL) return head;

    CarInfoNode *ptr = head;
    while (ptr != node && ptr != NULL) {
        ptr = ptr->next;
    }

    if (ptr == NULL) return head;//查无目标

    if (ptr->prior != NULL) //非头节点
        ptr->prior->next = ptr->next;
    else
        head = ptr->next;
    if (ptr->next != NULL) //非尾节点
        ptr->next->prior = ptr->prior;

    free(ptr);
    return head;
}

CarInfoNode *SelectNode(CarInfoNode *head, int id) {
    if (head == NULL) return NULL;

    CarInfoNode *ptr = head;
    while (ptr->next != NULL && ptr->data.Id != id) {
        ptr = ptr->next;
    }

    if (ptr->data.Id == id) return ptr;
    return NULL;
}

void SwitchNode(CarInfoNode *node1, CarInfoNode *node2) {
    if (node1 == NULL || node2 == NULL) return;

    CarInfo dataTemp = node1->data;
    node1->data = node2->data;
    node2->data = dataTemp;

    bool statusTemp = node1->isVisible;
    node1->isVisible = node2->isVisible;
    node2->isVisible = statusTemp;
}

void ResetAllNode(CarInfoNode *head) {
    for (CarInfoNode *node = head; node != NULL; node = node->next) {
        node->isVisible = true;
    }
}

void DeleteAllNode(CarInfoNode *head) {
    if (head == NULL) return;

    CarInfoNode *ptr = head;

    while (ptr->next != NULL) {
        ptr = ptr->next;
        free(ptr->prior);
    }

    free(ptr);
}

int GetNodeCount(CarInfoNode *head) {
    int num = 0;
    for (CarInfoNode *node = head; node != NULL; node = node->next) {
        if (node->isVisible) ++num;
    }
    return num;
}

int GetMaxPage(int infoNum) {
    return (infoNum - 1) / 10;
}