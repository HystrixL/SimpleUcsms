//
// Created by XianY on 2022/6/10.
//

#include "common.h"

CarInfoNode *Init() {
    //清除输出缓冲区
    setbuf(stdout, NULL);
    //清空屏幕
    ClearScreen();
    //读取密码
    ReadPassword();
    //读入数据
    return ReadCarFromFile(DATA_PATH);
}

void LimitNumber(int *source, int max, int min) {
    if (*source > max) *source = max;
    if (*source < min) *source = min;
}

bool DateCompare(Date date1, Date date2) {
    if (date1.Year < date2.Year) return true;
    else if (date1.Year == date2.Year) {
        if (date1.Mouth < date2.Mouth) return true;
        else if (date1.Mouth == date2.Mouth) {
            if (date1.Day < date2.Day) return true;
        }
    }
    return false;
}