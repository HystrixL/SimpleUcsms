//
// Created by XianY on 2022/6/30.
//

#ifndef CFINALWORK_DATA_H
#define CFINALWORK_DATA_H

#include "../Core/includes.h"
#include "CarInfo.h"

//���ֳ�����ڵ�ṹ��
struct CarInfoNode {
    struct CarInfoNode *prior;                  //ǰ�ڵ�
    CarInfo data;                               //����
    bool isVisible;                             //�Ƿ�ɼ�
    struct CarInfoNode *next;                   //��ڵ�
};
typedef struct CarInfoNode CarInfoNode;

/*!
 * @brief ѡ��ָ��ID�ڵ�
 * @details ѡ��ָ��ID�Ľڵ㣬���������ڴ��ַ
 *
 * @param head ����ͷ�ڵ��ַ
 * @param id ��ѡ��ID
 * @return ָ������ڵ��ַ
*/
CarInfoNode *SelectNode(CarInfoNode *head, int id);

/*!
 * @brief ɾ������ָ���ڵ�
 * @details ɾ������ָ����ַ�ڵ㣬�������������׵�ַ
 *
 * @param head ����ͷ�ڵ��ַ
 * @param node ��ɾ�������ַ
 * @return ������ͷ�ڵ��ַ
*/
CarInfoNode *DeleteNode(CarInfoNode *head, CarInfoNode *node);

/*!
 * @brief ��������
 * @details ������������ͷ��ַ����������������������������
 *
 * @param fstHead �׸�����ͷ��ַ
 * @param sedHead �ڶ�������ͷ��ַ
*/
void LinkList(CarInfoNode *fstHead, CarInfoNode *sedHead);

/*!
 * @brief �����½��
 * @details ��������ͷ�ڵ��ַ���½ڵ���ֳ���Ϣ�ṹ�壬�������½ڵ����������������
 *
 * @param head ����ͷ�ڵ��ַ
 * @param carInfo �������Ľڵ�����
*/
void AppendNode(CarInfoNode *head, CarInfo carInfo);

/*!
 * @brief �����ڵ�
 * @details ���������������ڵ��ַ�����ݽ���
 *
 * @param fst �׸�����ڵ�
 * @param sed �ڶ�������ڵ�
*/
void SwitchNode(CarInfoNode *fst, CarInfoNode *sed);

/*!
 * @brief ��������״̬
 * @details ����������Ŀɼ���isVisible����Ϊtrue
 *
 * @param head ����ͷ�ڵ��ַ
*/
void ResetAllNode(CarInfoNode *head);

/*!
 * @brief ɾ����������
 * @details ɾ����������ȫ���ڵ�
 *
 * @param head ����ͷ�ڵ��ַ
*/
void DeleteAllNode(CarInfoNode *head);

/*!
 * @brief ��ȡ�ڵ����
 * @details ���ظ�������Ľڵ�����
 *
 * @param head ����ͷ�ڵ��ַ
  * @return ����ڵ�����
*/
int GetNodeCount(CarInfoNode *head);

/*!
 * @brief ��ȡ���ҳ��
 * @details ���ؽڵ�����ռ�õ����ҳ��
 *
 * @param infoNum ����ڵ�����
 * @return �ڵ�ռ�õ����ҳ��
*/
int GetMaxPage(int infoNum);

#endif //CFINALWORK_DATA_H
