//
// Created by XianY on 2022/6/10.
//

#ifndef CFINALWORK_CARINFO_H
#define CFINALWORK_CARINFO_H

#include "../Core/includes.h"

//二手车卖家结构体
typedef struct {
    char Name[20];                      //卖家姓名
    float EstimatedPrice;               //卖家预期售价
} CarSeller;

//二手车销售员结构体
typedef struct {
    char Name[20];                     //销售员姓名
    int Id;                            //销售员ID
} CarSalesPerson;

//二手车客户结构体
typedef struct {
    char Name[20];                      //客户姓名
    char PhoneNumber[12];               //客户电话
} CarCustomer;

//二手车数据结构体
typedef struct CarInfo {
    int Id;                             //编号
    char Brand[30];                     //品牌
    char Model[30];                     //型号
    float OriPrice;                     //原价
    float PurchasePrice;                //进价
    float ActualPrice;                  //实售价
    int Mileage;                        //里程
    int Age;                            //车龄
    char HaveRepair;                    //是否有大修 Y/N
    char IsFault;                       //是否有故障 Y/N
    char Status[7];                     //车辆状态
    Date Date;                          //日期
    CarSeller Seller;                   //卖家
    CarSalesPerson SalesPerson;         //销售员
    CarCustomer Customer;               //客户
    char Handler[20];                   //经手人
} CarInfo;

#endif //CFINALWORK_CARINFO_H
