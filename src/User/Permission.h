//
// Created by XianY on 2022/6/10.
//

#ifndef CFINALWORK_PERMISSION_H
#define CFINALWORK_PERMISSION_H

#include "../Core/includes.h"
#include "../IO/File.h"
#include "../UI/BaseUI.h"

/*!
 * @brief 设置管理员模式
 *
 * @param input 是否为管理员模式
*/
void SetIsAdmin(bool input);

/*!
 * @brief 获取管理员模式
 *
 * @return 是否为管理员模式
*/
bool GetIsAdmin();

/*!
 * @brief 获取密码
 *
 * @return 密码字符串
*/
char *GetPassword();

/*!
 * @brief 读取密码
 * @details 从密码文件中读取管理员密码
*/
void ReadPassword();

/*!
 * @brief 写入密码
 * @details 将密码写入保存文件中
 *
 * @return 写入结果（非0为失败）
*/
int WritePassword();

/*!
 * @brief 修改密码UI
 * @details 显示修改密码UI
 *
 * @return 修改结果（非0为失败）
*/
int ChangePassword();

#endif //CFINALWORK_PERMISSION_H
