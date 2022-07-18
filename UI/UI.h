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
 * @brief �û�ģʽ�˵�
*/
void UserMenu();

/*!
 * @brief ����Աģʽ�˵�
*/
void AdminMenu();

/*!
 * @brief ���˵��˵�
 *
 * @param head ���ֳ���������ͷ�ڵ��ַ
*/
void WelcomeMenu(CarInfoNode *head);

/*!
 * @brief ��ѯ�˵�
*/
void SearchCarInfo();

/*!
 * @brief ����˵�
*/
void SortCarInfo();

/*!
 * @brief ���Ӳ˵�
*/
void AddCarInfo();

/*!
 * @brief ͳ�Ʋ˵�
*/
void StatisticsCarInfo();

/*!
 * @brief ����˵�
*/
void SaveCarInfo();

/*!
 * @brief ѡ��˵�
 *
 * @param id ѡ��ID
*/
void SelectCar(int id);

/*!
 * @brief �������ò˵�
*/
void Settings();

#endif //CFINALWORK_UI_H
