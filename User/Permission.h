//
// Created by XianY on 2022/6/10.
//

#ifndef CFINALWORK_PERMISSION_H
#define CFINALWORK_PERMISSION_H

#include "../Core/includes.h"
#include "../IO/File.h"
#include "../UI/BaseUI.h"

/*!
 * @brief ���ù���Աģʽ
 *
 * @param input �Ƿ�Ϊ����Աģʽ
*/
void SetIsAdmin(bool input);

/*!
 * @brief ��ȡ����Աģʽ
 *
 * @return �Ƿ�Ϊ����Աģʽ
*/
bool GetIsAdmin();

/*!
 * @brief ��ȡ����
 *
 * @return �����ַ���
*/
char *GetPassword();

/*!
 * @brief ��ȡ����
 * @details �������ļ��ж�ȡ����Ա����
*/
void ReadPassword();

/*!
 * @brief д������
 * @details ������д�뱣���ļ���
 *
 * @return д��������0Ϊʧ�ܣ�
*/
int WritePassword();

/*!
 * @brief �޸�����UI
 * @details ��ʾ�޸�����UI
 *
 * @return �޸Ľ������0Ϊʧ�ܣ�
*/
int ChangePassword();

#endif //CFINALWORK_PERMISSION_H
