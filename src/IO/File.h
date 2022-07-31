//
// Created by XianY on 2022/6/10.
//

#ifndef CFINALWORK_FILE_H
#define CFINALWORK_FILE_H

#include "../Data/Data.h"
#include "../Core/includes.h"

/*!
 * @brief 从文件中读入二手车信息
 * @details 从指定路径的文件中读入二手车信息，并构建链表，返回链表头节点地址
 *
 * @param path 文件路径
 * @return 链表头节点地址
*/
CarInfoNode *ReadCarFromFile(const char *path);

/*!
 * @brief 获取文件行数
 * @details 获取指定路径的文件的行数
 *
 * @param path 文件路径
 * @return 文件行数
*/
__attribute__((unused)) int GetFileLines(const char *path);

/*!
 * @brief 从文件中读入字符串
 * @details 从指定路径的文件中读入字符串，并存入指定地址
 *
 * @param path 文件路径
 * @param content 目标字符串地址
*/
void ReadStrFromFile(const char *path, const char *content);

/*!
 * @brief 将二手车信息写入文件
 * @details 将给定的二手车链表的信息写入指定路径的文件中
 *
 * @param path 文件路径
 * @param head 二手车信息链表头节点地址
 * @return 保存结果（非0为失败）
*/
int SaveCarToFile(const char *path, const CarInfoNode *head);

/*!
 * @brief 将二字符串写入文件
 * @details 将给定的字符串写入指定路径的文件中
 *
 * @param path 文件路径
 * @param head 字符串地址
 * @return 保存结果（非0为失败）
*/
int SaveStrFromFile(const char *path, const char *content);

#endif //CFINALWORK_FILE_H
