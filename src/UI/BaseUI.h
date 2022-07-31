//
// Created by XianY on 2022/7/15.
//

#ifndef CFINALWORK_BASEUI_H
#define CFINALWORK_BASEUI_H

#include "../Core/includes.h"
#include "../IO/Console.h"
#include "../Data/Data.h"
#include "UIString.h"

/*!
 * @brief 显示暂停页面及提示
 * @details 清屏后暂停并显示提示，当用户按下任意键后继续
 *
 * @param tip 提示内容字符串
*/
void Pause(char *tip);

/*!
 * @brief 用户输入接口
 * @details 显示输入提示符，并等待用户输入，将用户输入保存至指定字符串内
 *
 * @param input 保存字符串
*/
void UserInput(char *input);

/*!
 * @brief 用户加密输入接口
 * @details 显示输入提示符，并等待用户输入，输入内容将被隐藏，将用户输入保存至指定字符串内
 *
 * @param input 保存字符串
*/
void EncryptInput(char *input);

/*!
 * @brief 输出指定页面
 * @details 输出给定二手车数据链表中指定页数的内容
 *
 * @param head 二手车数据链表头节点地址
 * @param page 页码
*/
void PrintPage(CarInfoNode *head, int page);

/*!
 * @brief 输出指定二手车数据
 * @details 输出给定二手车数据链表节点的内容
 *
 * @param node 二手车数据链表节点地址
*/
void PrintCarInfo(CarInfoNode *node);

void PrintDividerBar(int length);

#endif //CFINALWORK_BASEUI_H
