//
// Created by XianY on 2022/6/30.
//

#include "Data.h"


void AppendNode(CarInfoNode *head, CarInfo carInfo) {
    if (head == NULL) return;

    CarInfoNode *ptr = (CarInfoNode *) malloc(sizeof(carInfo));
    ptr->next = NULL;
    ptr->prior = NULL;
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
    if (node == NULL || head == NULL) return NULL;

    //头节点
    if (node == head) {
        CarInfoNode *ptr;
        CarInfoNode *pn;
        ptr = head;
        pn = ptr->next;
        pn->prior = NULL;
        free(ptr);
        return pn;
    }

    CarInfoNode *pp;
    CarInfoNode *ptr;
    CarInfoNode *pn;
    pp = head;

    while (pp->next != node && pp->next != NULL) {
        pp = pp->next;
    }

    if (pp->next == NULL) return head;

    ptr = pp->next;
    pn = ptr->next;

    if (pn != NULL) {//非尾节点
        pp->next = pn;
        pn->prior = pp;
    } else {//尾节点
        pp->next = NULL;
    }

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