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
 * @brief ��ʾ��ͣҳ�漰��ʾ
 * @details ��������ͣ����ʾ��ʾ�����û���������������
 *
 * @param tip ��ʾ�����ַ���
*/
void Pause(char *tip);

/*!
 * @brief �û�����ӿ�
 * @details ��ʾ������ʾ�������ȴ��û����룬���û����뱣����ָ���ַ�����
 *
 * @param input �����ַ���
*/
void UserInput(char *input);

/*!
 * @brief �û���������ӿ�
 * @details ��ʾ������ʾ�������ȴ��û����룬�������ݽ������أ����û����뱣����ָ���ַ�����
 *
 * @param input �����ַ���
*/
void EncryptInput(char *input);

/*!
 * @brief ���ָ��ҳ��
 * @details ����������ֳ�����������ָ��ҳ��������
 *
 * @param head ���ֳ���������ͷ�ڵ��ַ
 * @param page ҳ��
*/
void PrintPage(CarInfoNode *head, int page);

/*!
 * @brief ���ָ�����ֳ�����
 * @details ����������ֳ���������ڵ������
 *
 * @param node ���ֳ���������ڵ��ַ
*/
void PrintCarInfo(CarInfoNode *node);

void PrintDividerBar(int length);

#endif //CFINALWORK_BASEUI_H
