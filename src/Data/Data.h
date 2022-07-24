//
// Created by XianY on 2022/6/30.
//

#ifndef CFINALWORK_DATA_H
#define CFINALWORK_DATA_H

#include "../Core/includes.h"
#include "CarInfo.h"

//二手车链表节点结构体
struct CarInfoNode {
    struct CarInfoNode *prior;                  //前节点
    CarInfo data;                               //数据
    bool isVisible;                             //是否可见
    struct CarInfoNode *next;                   //后节点
};
typedef struct CarInfoNode CarInfoNode;

/*!
 * @brief 选中指定ID节点
 * @details 选择指定ID的节点，并返回其内存地址
 *
 * @param head 链表头节点地址
 * @param id 待选中ID
 * @return 指定链表节点地址
*/
CarInfoNode *SelectNode(CarInfoNode *head, int id);

/*!
 * @brief 删除链表指定节点
 * @details 删除链表指定地址节点，并返回新链表首地址
 *
 * @param head 链表头节点地址
 * @param node 待删除链表地址
 * @return 新链表头节点地址
*/
CarInfoNode *DeleteNode(CarInfoNode *head, CarInfoNode *node);

/*!
 * @brief 链接链表
 * @details 输入两个链表头地址，并将这两个链表依次连接起来
 *
 * @param fstHead 首个链表头地址
 * @param sedHead 第二个链表头地址
*/
void LinkList(CarInfoNode *fstHead, CarInfoNode *sedHead);

/*!
 * @brief 加入新结点
 * @details 输入链表头节点地址与新节点二手车信息结构体，并将该新节点增加在已有链表后
 *
 * @param head 链表头节点地址
 * @param carInfo 待新增的节点数据
*/
void AppendNode(CarInfoNode *head, CarInfo carInfo);

/*!
 * @brief 交换节点
 * @details 将输入的两个链表节点地址的数据交换
 *
 * @param fst 首个链表节点
 * @param sed 第二个链表节点
*/
void SwitchNode(CarInfoNode *fst, CarInfoNode *sed);

/*!
 * @brief 重置链表状态
 * @details 将整个链表的可见性isVisible重置为true
 *
 * @param head 链表头节点地址
*/
void ResetAllNode(CarInfoNode *head);

/*!
 * @brief 删除整个链表
 * @details 删除给定链表全部节点
 *
 * @param head 链表头节点地址
*/
void DeleteAllNode(CarInfoNode *head);

/*!
 * @brief 获取节点个数
 * @details 返回给定链表的节点数量
 *
 * @param head 链表头节点地址
  * @return 链表节点数量
*/
int GetNodeCount(CarInfoNode *head);

/*!
 * @brief 获取最大页数
 * @details 返回节点数量占用的最大页数
 *
 * @param infoNum 链表节点数量
 * @return 节点占用的最大页数
*/
int GetMaxPage(int infoNum);

#endif //CFINALWORK_DATA_H
