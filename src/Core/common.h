//
// Created by XianY on 2022/6/10.
//

#ifndef CFINALWORK_COMMON_H
#define CFINALWORK_COMMON_H

#include "includes.h"
#include "../User/Permission.h"

/*!
 * @brief 初始化
 * @details 初始化二手车登记系统，并返回存储的信息链表头首地址

  * @return 存储的双向链表头节点地址
*/
CarInfoNode *Init();

/*!
 * @brief 数字限幅
 * @details 将给定数据限幅在最大值与最小值之间
 *
 * @param source 被限幅数据地址
 * @param max 最大值
 * @param min 最小值
*/
void LimitNumber(int *source, int max, int min);

/*!
 * @brief 比较日期大小
 * @details 比较给定两个日期大小，返回日期2是否大于日期1
 *
 * @param date1 日期1
 * @param date2 日期2
 * @returns 日期2是否大于日期1
*/
bool DateCompare(Date date1, Date date2);

#define GET_LENGTH(ARR) ((sizeof(ARR))/(sizeof((*ARR))))

#endif //CFINALWORK_COMMON_H
