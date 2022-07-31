//
// Created by XianY on 2022/6/10.
//

#ifndef CFINALWORK_FILE_H
#define CFINALWORK_FILE_H

#include "../Data/Data.h"
#include "../Core/includes.h"

/*!
 * @brief ���ļ��ж�����ֳ���Ϣ
 * @details ��ָ��·�����ļ��ж�����ֳ���Ϣ��������������������ͷ�ڵ��ַ
 *
 * @param path �ļ�·��
 * @return ����ͷ�ڵ��ַ
*/
CarInfoNode *ReadCarFromFile(const char *path);

/*!
 * @brief ��ȡ�ļ�����
 * @details ��ȡָ��·�����ļ�������
 *
 * @param path �ļ�·��
 * @return �ļ�����
*/
__attribute__((unused)) int GetFileLines(const char *path);

/*!
 * @brief ���ļ��ж����ַ���
 * @details ��ָ��·�����ļ��ж����ַ�����������ָ����ַ
 *
 * @param path �ļ�·��
 * @param content Ŀ���ַ�����ַ
*/
void ReadStrFromFile(const char *path, const char *content);

/*!
 * @brief �����ֳ���Ϣд���ļ�
 * @details �������Ķ��ֳ��������Ϣд��ָ��·�����ļ���
 *
 * @param path �ļ�·��
 * @param head ���ֳ���Ϣ����ͷ�ڵ��ַ
 * @return ����������0Ϊʧ�ܣ�
*/
int SaveCarToFile(const char *path, const CarInfoNode *head);

/*!
 * @brief �����ַ���д���ļ�
 * @details ���������ַ���д��ָ��·�����ļ���
 *
 * @param path �ļ�·��
 * @param head �ַ�����ַ
 * @return ����������0Ϊʧ�ܣ�
*/
int SaveStrFromFile(const char *path, const char *content);

#endif //CFINALWORK_FILE_H
