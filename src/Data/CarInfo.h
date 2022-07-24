//
// Created by XianY on 2022/6/10.
//

#ifndef CFINALWORK_CARINFO_H
#define CFINALWORK_CARINFO_H

#include "../Core/includes.h"

//���ֳ����ҽṹ��
struct CarSeller {
    char Name[20];                      //��������
    float EstimatedPrice;               //����Ԥ���ۼ�
};
typedef struct CarSeller CarSeller;

//���ֳ�����Ա�ṹ��
struct CarSalesPerson {
    char Name[20];                     //����Ա����
    int Id;                            //����ԱID
};
typedef struct CarSalesPerson CarSalesPerson;

//���ֳ��ͻ��ṹ��
struct CarCustomer {
    char Name[20];                      //�ͻ�����
    char PhoneNumber[12];               //�ͻ��绰
};
typedef struct CarCustomer CarCustomer;

//���ֳ����ݽṹ��
struct CarInfo {
    int Id;                             //���
    char Brand[30];                     //Ʒ��
    char Model[30];                     //�ͺ�
    float OriPrice;                     //ԭ��
    float PurchasePrice;                //����
    float ActualPrice;                  //ʵ�ۼ�
    int Mileage;                        //���
    int Age;                            //����
    char HaveRepair;                    //�Ƿ��д��� Y/N
    char IsFault;                       //�Ƿ��й��� Y/N
    char Status[7];                     //����״̬
    Date Date;                          //����
    CarSeller Seller;                   //����
    CarSalesPerson SalesPerson;         //����Ա
    CarCustomer Customer;               //�ͻ�
    char Handler[20];                   //������
};
typedef struct CarInfo CarInfo;

#endif //CFINALWORK_CARINFO_H
