//
// Created by XianY on 2022/7/15.
//

#include "UI.h"

CarInfoNode *Head;

void WelcomeMenu(CarInfoNode *head) {
    //��ʼ��ͷ�ڵ��ַ
    Head = head;
    while (true) {
        //������Ϣ���˵�
        ClearScreen();
        printf("%s", UI_BANNER);
        printf("%s", UI_WELCOME_MENU);
        //�û�����
        char input[10];
        UserInput(input);

        if (!strcmp(input, "0"))                //�˳�
            break;
        else if (!strcmp(input, "1")) {         //�û�ģʽ
            SetIsAdmin(false);
            UserMenu();
        } else if (!strcmp(input, "2")) {       //����Աģʽ
            if (!AdminLogin()) continue;        //��½��֤
            SetIsAdmin(true);
            AdminMenu();
        } else {                                //�������
            printf("%s", UI_INPUT_ERROR);
            getch();
        }
    }

    Pause("��лʹ��~");
    DeleteAllNode(head);
}

void UserMenu(void) {
    int currentPage = 0;
    char input[10];
    int maxPage;

    while (true) {
        //��ӡ��ǰҳ��
        PrintPage(Head, currentPage);
        printf("\n\r");
        printf("%s", UI_USER_MENU);

        //�ȴ��û�����
        printf("%s", UI_INPUT_TIP);
        int i = 0;
        while ((input[i] = (char) getche()) != '\r') {
            i++;
            if (i == 1 && (input[0] == '+' || input[0] == '-')) break;

        }
        input[i] = '\0';


        if (!strcmp(input, "+")) {                  //��һҳ
            currentPage++;
        } else if (!strcmp(input, "-")) {           //��һҳ
            currentPage--;
        } else if (!strcmp(input, "0")) {           //����
            break;
        } else if (!strcmp(input, "1")) {           //��ѯ
            SearchCarInfo();
        } else if (!strcmp(input, "2")) {           //����
            SortCarInfo();
        } else if (!strcmp(input, "3")) {           //ͳ��
            StatisticsCarInfo();
        } else if (input[0] == '~') {               //��ת
            char pageTo[10];
            strcpy(pageTo, &input[1]);
//            if (atoi(pageTo) - 1 > maxPage || atoi(pageTo) - 1 < 0) {
//                Pause("��ǰҳ�벻���ڣ�");
//                continue;
//            }
            currentPage = strtol(pageTo, NULL, 10) - 1;
        } else {                                       //��Ч����
            printf("%s", UI_INPUT_ERROR);
        }
        //ҳ���޷�
        maxPage = GetMaxPage(GetNodeCount(Head));
        LimitNumber(&currentPage, maxPage, 0);
    }
}

void AdminMenu(void) {
    int currentPage = 0;
    char input[10];
    int maxPage;

    while (true) {
        //��ӡ��ǰҳ��
        PrintPage(Head, currentPage);
        printf("\n\r");
        printf("%s", UI_ADMIN_MENU);

        //�ȴ��û�����
        printf("%s", UI_INPUT_TIP);
        int i = 0;
        while ((input[i] = (char) getche()) != '\r') {
            i++;
            if (i == 1 && (input[0] == '+' || input[0] == '-')) break;

        }
        input[i] = '\0';

        if (!strcmp(input, "+")) {                  //��һҳ
            currentPage++;
        } else if (!strcmp(input, "-")) {           //��һҳ
            currentPage--;
        } else if (!strcmp(input, "0")) {           //����
            break;
        } else if (!strcmp(input, "1")) {           //��ѯ
            SearchCarInfo();
        } else if (!strcmp(input, "2")) {           //����
            SortCarInfo();
        } else if (!strcmp(input, "3")) {           //ͳ��
            StatisticsCarInfo();
        } else if (!strcmp(input, "4")) {           //����
            AddCarInfo();
        } else if (!strcmp(input, "5")) {           //����
            SaveCarInfo();
        } else if (!strcmp(input, "6")) {           //����
            Settings();
        } else if (strlen(input) == 4) {        //ѡ��
            int id = strtol(input, NULL, 10);
            SelectCar(id);
        } else if (input[0] == '~') {               //��ת
            char pageTo[10];
            strcpy(pageTo, &input[1]);
//            if (atoi(pageTo) - 1 > maxPage || atoi(pageTo) - 1 < 0) {
//                Pause("��ǰҳ�벻���ڣ�");
//                continue;
//            }
            currentPage = strtol(pageTo, NULL, 10) - 1;
        } else {                                    //��Ч����
            printf("%s", UI_INPUT_ERROR);
        }
        //ҳ���޷�
        maxPage = GetMaxPage(GetNodeCount(Head));
        LimitNumber(&currentPage, maxPage, 0);
    }
}

void SearchCarInfo(void) {
    //��ʾ�˵�
    ClearScreen();
    printf("%s", UI_SEARCH_OPTIONS);

    int options[10] = {0};//�û������б�
    char convTemp[20] = {0};
    bool isInvalid = true;
    int count;
    while (isInvalid) {
        //�û�����
        printf("%s", UI_INPUT_TIP);
        count = 0;
        //��ȡ�������
        do {
            scanf("%s", convTemp);
            options[count] = strtol(convTemp, NULL, 10);
            count++;
        } while ((getchar()) != '\n');
        isInvalid = false;

        for (int i = 0; i < count; ++i) {
            //���� 0 -> ����
            if (options[i] == 0)
                return;
                //������Ч���� -> �ٴ�����
            else if (options[i] < 0 || options[i] > 10) {
                printf("%s", UI_INPUT_ERROR);
                isInvalid = true;
                getche();
            }
        }
    }

    for (int i = 0; i < count; ++i) {
        switch (options[i]) {
            //��Ʒ�Ʋ�ѯ
            case 1: {
                //��ȡ�û������ѯ����
                char brand[30];
                printf("����������ѯ��Ʒ���� >");
                scanf("%s", brand);
                //�����������������ݿɼ�����Ϊfalse
                for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                    if (strcmp(brand, node->data.Brand) != 0) node->isVisible = false;
                }
                break;
            }
                //���ͺŲ�ѯ
            case 2: {
                char model[30];
                printf("����������ѯ���ͺ� >");
                scanf("%s", model);
                for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                    if (strcmp(model, node->data.Model) != 0) node->isVisible = false;
                }
                break;
            }
                //��ԭ�۲�ѯ
            case 3: {
                float max, min;
                printf("����������ԭ�۷�Χ�����޼����� >");
                scanf("%f %f", &max, &min);
                for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                    if (node->data.OriPrice < min || node->data.OriPrice > max) node->isVisible = false;
                }
                break;
            }
                //�����۲�ѯ
            case 4: {
                float max, min;
                printf("������������۷�Χ�����޼����� >");
                scanf("%f %f", &max, &min);
                for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                    if (node->data.PurchasePrice < min || node->data.PurchasePrice > max) node->isVisible = false;
                }
                break;
            }
                //��ʵ�ۼ۲�ѯ
            case 5: {
                float max, min;
                printf("����������ʵ�ۼ۷�Χ�����޼����� >");
                scanf("%f %f", &max, &min);
                for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                    if (node->data.ActualPrice < min || node->data.ActualPrice > max) node->isVisible = false;
                }
                break;
            }
                //�������ѯ
            case 6: {
                int max, min;
                printf("���������복�䷶Χ�����޼����� >");
                scanf("%d %d", &max, &min);
                for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                    if (node->data.Age < min || node->data.Age > max) node->isVisible = false;
                }
                break;
            }
                //���Ƿ���޲�ѯ
            case 7: {
                char haveRepair;
                if (i != 0) getchar();
                printf("��ѡ���Ƿ����[Y/N] >");
                scanf("%c", &haveRepair);
                if (haveRepair == 'y') haveRepair = 'Y';
                if (haveRepair == 'n') haveRepair = 'N';
                for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                    if (node->data.HaveRepair != haveRepair) node->isVisible = false;
                }
                break;
            }
                //���Ƿ���ϲ�ѯ
            case 8: {
                char isFault;
                if (i != 0) getchar();
                printf("��ѡ���Ƿ����[Y/N] >");
                scanf("%c", &isFault);
                if (isFault == 'y') isFault = 'Y';
                if (isFault == 'n') isFault = 'N';
                for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                    if (node->data.IsFault != isFault) node->isVisible = false;
                }
                break;
            }
                //������״̬��ѯ
            case 9: {
                char status[7];
                printf("��ѡ����״̬[���/����/Ԥ��] >");
                scanf("%s", status);
                for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                    if (strcmp(status, node->data.Status) != 0) node->isVisible = false;
                }
                break;
            }
                //������ԱID��ѯ
            case 10: {
                int id;
                printf("����������ѯ������ԱID >");
                scanf("%d", &id);
                for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                    if (node->data.SalesPerson.Id != id) node->isVisible = false;
                }
                break;
            }
        }
    }

    //��ѯ����б��߼�
    int infoNum = GetNodeCount(Head);
    if (infoNum != 0) {
        int currentPage = 0;
        int maxPage;
        char input[10];
        while (true) {
            //��ӡ��ǰҳ������
            PrintPage(Head, currentPage);
            printf("\n\r");

            if (GetIsAdmin())printf("%s", UI_ADMIN_SEARCH_MENU);
            else printf("%s", UI_BACK_MENU);
            //�ȵ��û�����
            printf("%s", UI_INPUT_TIP);
            int i = 0;
            while ((input[i] = (char) getche()) != '\r') {
                i++;
                if (i == 1 && (input[0] == '+' || input[0] == '-')) break;

            }
            input[i] = '\0';

            if (!strcmp(input, "+")) {                      //��һҳ
                currentPage++;
            } else if (!strcmp(input, "-")) {               //��һҳ
                currentPage--;
            } else if (!strcmp(input, "0")) {               //����
                break;
            } else if (!strcmp(input, "1")) {               //����Աģʽ��ɾ��ȫ��
                if (!GetIsAdmin()) {                          //�ǹ���Ա����
                    printf("%s", UI_INPUT_ERROR);
                    getch();
                    continue;
                }
                //���κ˶�
                printf("%s", DELETE_VERIFY);
                UserInput(input);
                if (!strcmp(input, "y")) {
                    //����ɾ��"��ǰ�ɼ�������"->"��ѯ���"
                    for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                        if (node->isVisible) Head = DeleteNode(Head, node);
                    }
                    Pause("��ɾ�����в�ѯ�����");
                    break;
                }
                continue;
            } else if (input[0] == '~') {                   //��תҳ��
                char pageTo[10];
                strcpy(pageTo, &input[1]);
                currentPage = strtol(pageTo, NULL, 10) - 1;
            } else if (strlen(input) == 4) {             //ѡ��ָ����Ŷ��ֳ�
                if (!GetIsAdmin()) {                           //�ǹ���Ա����
                    printf("%s", UI_INPUT_ERROR);
                    getch();
                    continue;
                }
                int id = strtol(input, NULL, 10);
                SelectCar(id);
            } else {                                           //��Ч����
                printf("%s", UI_INPUT_ERROR);
                getch();
            }
            //ҳ���޷�
            printf("%d", GetNodeCount(Head));
            maxPage = GetMaxPage(GetNodeCount(Head));
            LimitNumber(&currentPage, maxPage, 0);
        }
    } else {                                                //��ѯ����б�Ϊ��
        Pause("���޽����");
    }
    ResetAllNode(Head);                                 //����ǰ�������пɼ���
}

void SortCarInfo(void) {
    //��ʾ����˵�
    ClearScreen();
    printf("%s", UI_SORT_OPTIONS);

    char input;
    bool isDescend = false;

    while (true) {
        //�ȴ��û�����
        char raw_input[3];
        UserInput(raw_input);

        if (raw_input[0] == '!') {              //ǰ��"!"����
            isDescend = true;
            input = raw_input[1];
        } else {                                //��������
            input = raw_input[0];
        }

        if (input < '0' || input > '9') {       //��Ч����
            printf("%s", UI_INPUT_ERROR);
        } else if (input == '0')                //����
            return;
        else                                    //�������
            break;
    }

    ClearScreen();

    //�����߼���ѡ������
    for (CarInfoNode *i = Head; i != NULL; i = i->next) {
        CarInfoNode *min = i;
        for (CarInfoNode *j = i->next; j != NULL; j = j->next) {
            bool isMin = false;
            switch (input) {
                case '1'://���������
                    isMin = (j->data.Id < min->data.Id);
                    break;
                case '2'://��Ʒ������
                    isMin = (strcmp(min->data.Brand, j->data.Brand) > 0);
                    break;
                case '3'://���������
                    isMin = (j->data.Mileage < min->data.Mileage);
                    break;
                case '4'://��ԭ������
                    isMin = (j->data.OriPrice < min->data.OriPrice);
                    break;
                case '5'://����������
                    isMin = (j->data.PurchasePrice < min->data.PurchasePrice);
                    break;
                case '6'://��ʵ�ۼ�����
                    isMin = (j->data.ActualPrice < min->data.ActualPrice);
                    break;
                case '7'://����������
                    isMin = (j->data.Age < min->data.Age);
                    break;
                case '8'://����������
                    isMin = DateCompare(j->data.Date, min->data.Date);
                    break;
                case '9'://������ԱID����
                    isMin = j->data.SalesPerson.Id < min->data.SalesPerson.Id;
                    break;
                default:
                    break;
            }
            if (isDescend) isMin = !isMin;//����ת

            if (isMin) {
                min = j;
            }
        }
        //�����ڵ�����
        if (min != i) {
            SwitchNode(min, i);
        }
    }
}

void StatisticsCarInfo(void) {
    //��ʾͳ��ѡ��˵�
    ClearScreen();
    printf("%s", UI_STATISTICS_OPTIONS);

    while (true) {
        //�ȴ��û�����
        char input[2];
        UserInput(input);

        if (!strcmp(input, "1")) {//ͳ�ƶ��ֳ�����������
            float sumProfits = 0;
            for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                if (node->data.ActualPrice != -1)
                    sumProfits += (node->data.ActualPrice - node->data.PurchasePrice);
            }
            printf("���ֳ�����������Ϊ: %.2f ��Ԫ", sumProfits);
        } else if (!strcmp(input, "2")) {//ͳ������Ԥ���ۼ���ʵ���ۼ�ƽ����ֵ
            float sumDiff = 0;
            int count = 0;
            for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                if (node->data.ActualPrice != -1) {
                    sumDiff += (node->data.Seller.EstimatedPrice - node->data.ActualPrice);
                    count++;
                }
            }
            float aveDiff = sumDiff / (float) count;
            printf("����Ԥ���ۼ���ʵ���ۼ�ƽ����ֵΪ: %.2f ��Ԫ", aveDiff);
        } else if (!strcmp(input, "3")) {//ͳ�Ƴ�����ֵ�泵��ƽ������ֵ
            float sumDiff = 0;
            int count = 0;
            for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                if (node->data.ActualPrice != -1) {
                    sumDiff += (node->data.OriPrice - node->data.ActualPrice) / (float) node->data.Age;
                    count++;
                }
            }
            float aveDiff = sumDiff / (float) count;
            printf("������ֵ�泵��ƽ������ֵΪ: %.2f ��Ԫ/��", aveDiff);
        } else if (!strcmp(input, "0")) {//����
            break;
        } else {//��Ч����
            printf("%s", UI_INPUT_ERROR);
        }
    }
}

void AddCarInfo(void) {
    //��ʾ���ѡ���б�
    ClearScreen();
    printf("%s", UI_ADD_CAR_OPTION);
    while (true) {
        //�ȴ��û�����
        char input[5];
        UserInput(input);
        if (!strcmp(input, "1")) {//��ӵ�����Ϣ
            printf("�����������ʾ������ֳ���Ϣ��");
            printf("%s", UI_INFO_INPUT_TIP);//������ʾ
            printf("\n\r");

            CarInfo carInfo;
            //�û������¶��ֳ���Ϣ
            scanf(DATA_INPUT_FORMAT,
                  &carInfo.Id, carInfo.Brand, carInfo.Model,
                  &carInfo.OriPrice, &carInfo.PurchasePrice, &carInfo.ActualPrice,
                  &carInfo.Mileage, &carInfo.Age, &carInfo.HaveRepair, &carInfo.IsFault, carInfo.Status,
                  &carInfo.Date.Year, &carInfo.Date.Mouth, &carInfo.Date.Day,
                  carInfo.Seller.Name, &carInfo.Seller.EstimatedPrice,
                  carInfo.SalesPerson.Name, &carInfo.SalesPerson.Id,
                  carInfo.Customer.Name, carInfo.Customer.PhoneNumber,
                  carInfo.Handler);
            //β��׷�ӽڵ�
            AppendNode(Head, carInfo);
            Pause("�����ɣ�");
            return;
        } else if (!strcmp(input, "2")) {//����ļ�
            char path[40];
            printf("���������ӵ������ļ�·����");
            UserInput(path);
            //���ļ��ж�ȡ���ݲ����ӽڵ�
            CarInfoNode *sedHead = ReadCarFromFile(path);
            LinkList(Head, sedHead);
            Pause("�����ɣ�");
            return;
        } else if (!strcmp(input, "0")) {//����
            return;
        } else {//��Ч����
            printf("%s", UI_INPUT_ERROR);
        }
    }
}

void SaveCarInfo(void) {
    ClearScreen();
    if (SaveCarToFile(DATA_PATH, Head)) {//�������ݲ���ȡ���
        Pause("����ʧ�ܣ����� .\\data\\data.txt");
    } else {
        Pause("����ɹ������� .\\data\\data.txt");
    }
}

void Settings(void) {
    //��ʾ�������ò˵�
    ClearScreen();
    printf("%s", UI_MORE_SET_MENU);
    while (true) {
        char input[5];
        UserInput(input);
        if (!strcmp(input, "1")) {//�޸�����
            if (ChangePassword() == Success) {//�޸����벢��ȡ���
                Pause("�����޸ĳɹ���");
            } else {
                Pause("�����޸�ʧ�ܣ�");
            }
            return;
        } else if (!strcmp(input, "0")) {//����
            return;
        } else {//��Ч����
            printf("%s", UI_INPUT_ERROR);
        }
    }
}

void SelectCar(int id) {
    //����ѡ��ָ���ڵ�
    CarInfoNode *node = SelectNode(Head, id);
    if (node == NULL) {
        Pause("�ñ�Ŷ��ֳ������ڣ�������������롣");
        return;
    }

    while (true) {
        //��ʾ��ϸ��Ϣ�˵�
        ClearScreen();
        printf("%s", UI_INFO_HEADER);
        printf("\n\r");
        PrintCarInfo(node);
        printf("\n\r");
        printf("%s", UI_SELECT_MENU);
        //�ȴ��û�����
        char input[5];
        UserInput(input);
        if (!strcmp(input, "1")) {                                          //�޸���Ϣ
            printf("%s", UI_CHANGE_OPTION);
            while (true) {
                UserInput(input);
                if (!strcmp(input, "1")) {                          //�޸�Ʒ��
                    printf("��������Ʒ������");
                    scanf("%s", node->data.Brand);
                } else if (!strcmp(input, "2")) {
                    printf("���������ͺţ�");                  //�޸��ͺ�
                    scanf("%s", node->data.Model);
                } else if (!strcmp(input, "3")) {
                    printf("��������ԭ�ۣ�");                  //�޸�ԭ��
                    scanf("%f", &node->data.OriPrice);
                } else if (!strcmp(input, "4")) {
                    printf("�������½��ۣ�");                  //�޸Ľ���
                    scanf("%f", &node->data.PurchasePrice);
                } else if (!strcmp(input, "5")) {
                    printf("��������ʵ�ۼۣ�");                 //�޸�ʵ�ۼ�
                    scanf("%f", &node->data.ActualPrice);
                } else if (!strcmp(input, "6")) {
                    printf("�������³���״̬��");                //�޸ĳ���״̬
                    scanf("%s", node->data.Status);
                } else if (!strcmp(input, "0")) {                   //����
                    break;
                } else {                                            //��Ч����
                    printf("%s", UI_INPUT_ERROR);
                    continue;
                }
                Pause("���ֳ���Ϣ�޸ĳɹ���");
                break;
            }
        } else if (!strcmp(input, "2")) {                                   //ɾ����Ϣ
            //���κ˶�
            printf("%s", DELETE_VERIFY);
            UserInput(input);
            if (!strcmp(input, "y")) {
                Head = DeleteNode(Head, node);
                Pause("��ɾ��������Ϣ��");
                return;
            }
            continue;
        } else if (!strcmp(input, "0")) {                                   //����
            return;
        } else {
            printf("%s", UI_INPUT_ERROR);                                 //��Ч����
        }
    }

}