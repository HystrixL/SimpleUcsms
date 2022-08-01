//
// Created by XianY on 2022/6/10.
//

#ifndef CFINALWORK_DEFINITION_H
#define CFINALWORK_DEFINITION_H

//日期结构体
typedef struct {
    int Year;
    int Mouth;
    int Day;
} Date;

typedef enum {
    Success = 0,
    Failure = 1
} OperationResult;

//数据输入格式符
#define DATA_INPUT_FORMAT "%d %s %s %f %f %f %d %d %c %c %s %d/%02d/%02d %s %f %s %d %s %s %s"
//数据输出格式符
#define DATA_OUTPUT_FORMAT "%-6d %-12s %-12s %-10.2f %-10.2f %-15.2f %-9d %-9d %-10c %-8c %-7s %d/%02d/%02d     %-10s %-13.2f %-9s %-8d %-7s %-16s %s"
//数据文件路径
#define DATA_PATH ".\\data\\data.txt"
//密码文件路径
#define PASSWORD_PATH ".\\data\\pwd.txt"
//最大密码长度
#define MAX_PASSWORD_LENGTH 20

#endif //CFINALWORK_DEFINITION_H