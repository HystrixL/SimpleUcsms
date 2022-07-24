//
// Created by XianY on 2022/7/15.
//

#ifndef CFINALWORK_UI_H
#define CFINALWORK_UI_H

#include "../Core/includes.h"
#include "../Core/common.h"
#include "BaseUI.h"
#include "../User/Login.h"

/*!
 * @brief 用户模式菜单
*/
void UserMenu();

/*!
 * @brief 管理员模式菜单
*/
void AdminMenu();

/*!
 * @brief 主菜单菜单
 *
 * @param head 二手车数据链表头节点地址
*/
void WelcomeMenu(CarInfoNode *head);

/*!
 * @brief 查询菜单
*/
void SearchCarInfo();

/*!
 * @brief 排序菜单
*/
void SortCarInfo();

/*!
 * @brief 增加菜单
*/
void AddCarInfo();

/*!
 * @brief 统计菜单
*/
void StatisticsCarInfo();

/*!
 * @brief 保存菜单
*/
void SaveCarInfo();

/*!
 * @brief 选择菜单
 *
 * @param id 选中ID
*/
void SelectCar(int id);

/*!
 * @brief 更多设置菜单
*/
void Settings();

#endif //CFINALWORK_UI_H
