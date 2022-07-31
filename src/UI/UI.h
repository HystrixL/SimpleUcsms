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
void UserMenu(void);

/*!
 * @brief ����Աģʽ�˵�
*/
void AdminMenu(void);

/*!
 * @brief ���˵��˵�
 *
 * @param head ���ֳ���������ͷ�ڵ��ַ
*/
void WelcomeMenu(CarInfoNode *head);

/*!
 * @brief ��ѯ�˵�
*/
void SearchCarInfo(void);

/*!
 * @brief ����˵�
*/
void SortCarInfo(void);

/*!
 * @brief ���Ӳ˵�
*/
void AddCarInfo(void);

/*!
 * @brief ͳ�Ʋ˵�
*/
void StatisticsCarInfo(void);

/*!
 * @brief ����˵�
*/
void SaveCarInfo(void);

/*!
 * @brief ѡ��˵�
 *
 * @param id ѡ��ID
*/
void SelectCar(int id);

/*!
 * @brief �������ò˵�
*/
void Settings(void);

#endif //CFINALWORK_UI_H
