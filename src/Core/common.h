//
// Created by XianY on 2022/6/10.
//

#ifndef CFINALWORK_COMMON_H
#define CFINALWORK_COMMON_H

#include "includes.h"
#include "../User/Permission.h"

/*!
 * @brief ��ʼ��
 * @details ��ʼ�����ֳ��Ǽ�ϵͳ�������ش洢����Ϣ����ͷ�׵�ַ

  * @return �洢��˫������ͷ�ڵ��ַ
*/
CarInfoNode *Init();

/*!
 * @brief �����޷�
 * @details �����������޷������ֵ����Сֵ֮��
 *
 * @param source ���޷����ݵ�ַ
 * @param max ���ֵ
 * @param min ��Сֵ
*/
void LimitNumber(int *source, int max, int min);

/*!
 * @brief �Ƚ����ڴ�С
 * @details �Ƚϸ����������ڴ�С����������2�Ƿ��������1
 *
 * @param date1 ����1
 * @param date2 ����2
 * @returns ����2�Ƿ��������1
*/
bool DateCompare(Date date1, Date date2);

#define GET_LENGTH(ARR) ((sizeof(ARR))/(sizeof((*ARR))))

#endif //CFINALWORK_COMMON_H
