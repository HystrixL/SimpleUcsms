//
// Created by XianY on 2022/6/10.
//

#ifndef CFINALWORK_DEFINITION_H
#define CFINALWORK_DEFINITION_H

//���ڽṹ��
struct Date {
    int Year;
    int Mouth;
    int Day;
};
typedef struct Date Date;

//���������ʽ��
#define DATA_INPUT_FORMAT "%d %s %s %f %f %f %d %d %c %c %s %d/%02d/%02d %s %f %s %d %s %s %s"
//���������ʽ��
#define DATA_OUTPUT_FORMAT "%-6d %-12s %-12s %-10.2f %-10.2f %-15.2f %-9d %-9d %-10c %-8c %-7s %d/%02d/%02d     %-10s %-13.2f %-9s %-8d %-7s %-16s %s"
//�����ļ�·��
#define DATA_PATH ".\\data\\data.txt"
//�����ļ�·��
#define PWD_PATH ".\\data\\pwd.txt"
//������볤��
#define MAX_PWD_LENGTH 20

#endif //CFINALWORK_DEFINITION_H
