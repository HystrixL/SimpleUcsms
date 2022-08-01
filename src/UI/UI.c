//
// Created by XianY on 2022/7/15.
//

#include "UI.h"

CarInfoNode *Head;

void WelcomeMenu(CarInfoNode *head) {
    //初始化头节点地址
    Head = head;
    while (true) {
        //程序信息及菜单
        ClearScreen();
        printf("%s", UI_BANNER);
        printf("%s", UI_WELCOME_MENU);
        //用户输入
        char input[10];
        UserInput(input);

        if (!strcmp(input, "0"))                //退出
            break;
        else if (!strcmp(input, "1")) {         //用户模式
            SetIsAdmin(false);
            UserMenu();
        } else if (!strcmp(input, "2")) {       //管理员模式
            if (!AdminLogin()) continue;        //登陆验证
            SetIsAdmin(true);
            AdminMenu();
        } else {                                //输入错误
            printf("%s", UI_INPUT_ERROR);
            getch();
        }
    }

    Pause("感谢使用~");
    DeleteAllNode(head);
}

void UserMenu(void) {
    int currentPage = 0;
    char input[10];
    int maxPage;

    while (true) {
        //打印当前页面
        PrintPage(Head, currentPage);
        printf("\n\r");
        printf("%s", UI_USER_MENU);

        //等待用户输入
        printf("%s", UI_INPUT_TIP);
        int i = 0;
        while ((input[i] = (char) getche()) != '\r') {
            i++;
            if (i == 1 && (input[0] == '+' || input[0] == '-')) break;

        }
        input[i] = '\0';


        if (!strcmp(input, "+")) {                  //下一页
            currentPage++;
        } else if (!strcmp(input, "-")) {           //上一页
            currentPage--;
        } else if (!strcmp(input, "0")) {           //返回
            break;
        } else if (!strcmp(input, "1")) {           //查询
            SearchCarInfo();
        } else if (!strcmp(input, "2")) {           //排序
            SortCarInfo();
        } else if (!strcmp(input, "3")) {           //统计
            StatisticsCarInfo();
        } else if (input[0] == '~') {               //跳转
            char pageTo[10];
            strcpy(pageTo, &input[1]);
//            if (atoi(pageTo) - 1 > maxPage || atoi(pageTo) - 1 < 0) {
//                Pause("当前页码不存在！");
//                continue;
//            }
            currentPage = strtol(pageTo, NULL, 10) - 1;
        } else {                                       //无效输入
            printf("%s", UI_INPUT_ERROR);
        }
        //页面限幅
        maxPage = GetMaxPage(GetNodeCount(Head));
        LimitNumber(&currentPage, maxPage, 0);
    }
}

void AdminMenu(void) {
    int currentPage = 0;
    char input[10];
    int maxPage;

    while (true) {
        //打印当前页面
        PrintPage(Head, currentPage);
        printf("\n\r");
        printf("%s", UI_ADMIN_MENU);

        //等待用户输入
        printf("%s", UI_INPUT_TIP);
        int i = 0;
        while ((input[i] = (char) getche()) != '\r') {
            i++;
            if (i == 1 && (input[0] == '+' || input[0] == '-')) break;

        }
        input[i] = '\0';

        if (!strcmp(input, "+")) {                  //下一页
            currentPage++;
        } else if (!strcmp(input, "-")) {           //上一页
            currentPage--;
        } else if (!strcmp(input, "0")) {           //返回
            break;
        } else if (!strcmp(input, "1")) {           //查询
            SearchCarInfo();
        } else if (!strcmp(input, "2")) {           //排序
            SortCarInfo();
        } else if (!strcmp(input, "3")) {           //统计
            StatisticsCarInfo();
        } else if (!strcmp(input, "4")) {           //新增
            AddCarInfo();
        } else if (!strcmp(input, "5")) {           //保存
            SaveCarInfo();
        } else if (!strcmp(input, "6")) {           //设置
            Settings();
        } else if (strlen(input) == 4) {        //选择
            int id = strtol(input, NULL, 10);
            SelectCar(id);
        } else if (input[0] == '~') {               //跳转
            char pageTo[10];
            strcpy(pageTo, &input[1]);
//            if (atoi(pageTo) - 1 > maxPage || atoi(pageTo) - 1 < 0) {
//                Pause("当前页码不存在！");
//                continue;
//            }
            currentPage = strtol(pageTo, NULL, 10) - 1;
        } else {                                    //无效输入
            printf("%s", UI_INPUT_ERROR);
        }
        //页面限幅
        maxPage = GetMaxPage(GetNodeCount(Head));
        LimitNumber(&currentPage, maxPage, 0);
    }
}

void SearchCarInfo(void) {
    //显示菜单
    ClearScreen();
    printf("%s", UI_SEARCH_OPTIONS);

    int options[10] = {0};//用户输入列表
    char convTemp[20] = {0};
    bool isInvalid = true;
    int count;
    while (isInvalid) {
        //用户输入
        printf("%s", UI_INPUT_TIP);
        count = 0;
        //获取多个输入
        do {
            scanf("%s", convTemp);
            options[count] = strtol(convTemp, NULL, 10);
            count++;
        } while ((getchar()) != '\n');
        isInvalid = false;

        for (int i = 0; i < count; ++i) {
            //存在 0 -> 返回
            if (options[i] == 0)
                return;
                //存在无效输入 -> 再次输入
            else if (options[i] < 0 || options[i] > 10) {
                printf("%s", UI_INPUT_ERROR);
                isInvalid = true;
                getche();
            }
        }
    }

    for (int i = 0; i < count; ++i) {
        switch (options[i]) {
            //按品牌查询
            case 1: {
                //获取用户输入查询条件
                char brand[30];
                printf("请输入欲查询的品牌名 >");
                scanf("%s", brand);
                //将不符合条件的数据可见性置为false
                for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                    if (strcmp(brand, node->data.Brand) != 0) node->isVisible = false;
                }
                break;
            }
                //按型号查询
            case 2: {
                char model[30];
                printf("请输入欲查询的型号 >");
                scanf("%s", model);
                for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                    if (strcmp(model, node->data.Model) != 0) node->isVisible = false;
                }
                break;
            }
                //按原价查询
            case 3: {
                float max, min;
                printf("请依次输入原价范围的上限及下限 >");
                scanf("%f %f", &max, &min);
                for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                    if (node->data.OriPrice < min || node->data.OriPrice > max) node->isVisible = false;
                }
                break;
            }
                //按进价查询
            case 4: {
                float max, min;
                printf("请依次输入进价范围的上限及下限 >");
                scanf("%f %f", &max, &min);
                for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                    if (node->data.PurchasePrice < min || node->data.PurchasePrice > max) node->isVisible = false;
                }
                break;
            }
                //按实售价查询
            case 5: {
                float max, min;
                printf("请依次输入实售价范围的上限及下限 >");
                scanf("%f %f", &max, &min);
                for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                    if (node->data.ActualPrice < min || node->data.ActualPrice > max) node->isVisible = false;
                }
                break;
            }
                //按车龄查询
            case 6: {
                int max, min;
                printf("请依次输入车龄范围的上限及下限 >");
                scanf("%d %d", &max, &min);
                for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                    if (node->data.Age < min || node->data.Age > max) node->isVisible = false;
                }
                break;
            }
                //按是否大修查询
            case 7: {
                char haveRepair;
                if (i != 0) getchar();
                printf("请选择是否大修[Y/N] >");
                scanf("%c", &haveRepair);
                if (haveRepair == 'y') haveRepair = 'Y';
                if (haveRepair == 'n') haveRepair = 'N';
                for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                    if (node->data.HaveRepair != haveRepair) node->isVisible = false;
                }
                break;
            }
                //按是否故障查询
            case 8: {
                char isFault;
                if (i != 0) getchar();
                printf("请选择是否故障[Y/N] >");
                scanf("%c", &isFault);
                if (isFault == 'y') isFault = 'Y';
                if (isFault == 'n') isFault = 'N';
                for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                    if (node->data.IsFault != isFault) node->isVisible = false;
                }
                break;
            }
                //按车辆状态查询
            case 9: {
                char status[7];
                printf("请选择车辆状态[入库/出库/预定] >");
                scanf("%s", status);
                for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                    if (strcmp(status, node->data.Status) != 0) node->isVisible = false;
                }
                break;
            }
                //按销售员ID查询
            case 10: {
                int id;
                printf("请输入欲查询的销售员ID >");
                scanf("%d", &id);
                for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                    if (node->data.SalesPerson.Id != id) node->isVisible = false;
                }
                break;
            }
        }
    }

    //查询结果列表逻辑
    int infoNum = GetNodeCount(Head);
    if (infoNum != 0) {
        int currentPage = 0;
        int maxPage;
        char input[10];
        while (true) {
            //打印当前页面数据
            PrintPage(Head, currentPage);
            printf("\n\r");

            if (GetIsAdmin())printf("%s", UI_ADMIN_SEARCH_MENU);
            else printf("%s", UI_BACK_MENU);
            //等到用户输入
            printf("%s", UI_INPUT_TIP);
            int i = 0;
            while ((input[i] = (char) getche()) != '\r') {
                i++;
                if (i == 1 && (input[0] == '+' || input[0] == '-')) break;

            }
            input[i] = '\0';

            if (!strcmp(input, "+")) {                      //下一页
                currentPage++;
            } else if (!strcmp(input, "-")) {               //上一页
                currentPage--;
            } else if (!strcmp(input, "0")) {               //返回
                break;
            } else if (!strcmp(input, "1")) {               //管理员模式下删除全部
                if (!GetIsAdmin()) {                          //非管理员错误
                    printf("%s", UI_INPUT_ERROR);
                    getch();
                    continue;
                }
                //二次核对
                printf("%s", DELETE_VERIFY);
                UserInput(input);
                if (!strcmp(input, "y")) {
                    //遍历删除"当前可见的数据"->"查询结果"
                    for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                        if (node->isVisible) Head = DeleteNode(Head, node);
                    }
                    Pause("已删除所有查询结果！");
                    break;
                }
                continue;
            } else if (input[0] == '~') {                   //跳转页面
                char pageTo[10];
                strcpy(pageTo, &input[1]);
                currentPage = strtol(pageTo, NULL, 10) - 1;
            } else if (strlen(input) == 4) {             //选择指定编号二手车
                if (!GetIsAdmin()) {                           //非管理员错误
                    printf("%s", UI_INPUT_ERROR);
                    getch();
                    continue;
                }
                int id = strtol(input, NULL, 10);
                SelectCar(id);
            } else {                                           //无效输入
                printf("%s", UI_INPUT_ERROR);
                getch();
            }
            //页码限幅
            printf("%d", GetNodeCount(Head));
            maxPage = GetMaxPage(GetNodeCount(Head));
            LimitNumber(&currentPage, maxPage, 0);
        }
    } else {                                                //查询结果列表为空
        Pause("查无结果！");
    }
    ResetAllNode(Head);                                 //返回前重置所有可见性
}

void SortCarInfo(void) {
    //显示排序菜单
    ClearScreen();
    printf("%s", UI_SORT_OPTIONS);

    char input;
    bool isDescend = false;

    while (true) {
        //等待用户输入
        char raw_input[3];
        UserInput(raw_input);

        if (raw_input[0] == '!') {              //前导"!"降序
            isDescend = true;
            input = raw_input[1];
        } else {                                //正常升序
            input = raw_input[0];
        }

        if (input < '0' || input > '9') {       //无效输入
            printf("%s", UI_INPUT_ERROR);
        } else if (input == '0')                //返回
            return;
        else                                    //完成输入
            break;
    }

    ClearScreen();

    //排序逻辑（选择排序）
    for (CarInfoNode *i = Head; i != NULL; i = i->next) {
        CarInfoNode *min = i;
        for (CarInfoNode *j = i->next; j != NULL; j = j->next) {
            bool isMin = false;
            switch (input) {
                case '1'://按编号排序
                    isMin = (j->data.Id < min->data.Id);
                    break;
                case '2'://按品牌排序
                    isMin = (strcmp(min->data.Brand, j->data.Brand) > 0);
                    break;
                case '3'://按里程排序
                    isMin = (j->data.Mileage < min->data.Mileage);
                    break;
                case '4'://按原价排序
                    isMin = (j->data.OriPrice < min->data.OriPrice);
                    break;
                case '5'://按进价排序
                    isMin = (j->data.PurchasePrice < min->data.PurchasePrice);
                    break;
                case '6'://按实售价排序
                    isMin = (j->data.ActualPrice < min->data.ActualPrice);
                    break;
                case '7'://按车龄排序
                    isMin = (j->data.Age < min->data.Age);
                    break;
                case '8'://按日期排序
                    isMin = DateCompare(j->data.Date, min->data.Date);
                    break;
                case '9'://按销售员ID排序
                    isMin = j->data.SalesPerson.Id < min->data.SalesPerson.Id;
                    break;
                default:
                    break;
            }
            if (isDescend) isMin = !isMin;//降序反转

            if (isMin) {
                min = j;
            }
        }
        //交换节点数据
        if (min != i) {
            SwitchNode(min, i);
        }
    }
}

void StatisticsCarInfo(void) {
    //显示统计选项菜单
    ClearScreen();
    printf("%s", UI_STATISTICS_OPTIONS);

    while (true) {
        //等待用户输入
        char input[2];
        UserInput(input);

        if (!strcmp(input, "1")) {//统计二手车销售总利润
            float sumProfits = 0;
            for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                if (node->data.ActualPrice != -1)
                    sumProfits += (node->data.ActualPrice - node->data.PurchasePrice);
            }
            printf("二手车销售总利润为: %.2f 万元", sumProfits);
        } else if (!strcmp(input, "2")) {//统计卖家预估售价与实际售价平均差值
            float sumDiff = 0;
            int count = 0;
            for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                if (node->data.ActualPrice != -1) {
                    sumDiff += (node->data.Seller.EstimatedPrice - node->data.ActualPrice);
                    count++;
                }
            }
            float aveDiff = sumDiff / (float) count;
            printf("卖家预估售价与实际售价平均差值为: %.2f 万元", aveDiff);
        } else if (!strcmp(input, "3")) {//统计车辆价值随车龄平均降低值
            float sumDiff = 0;
            int count = 0;
            for (CarInfoNode *node = Head; node != NULL; node = node->next) {
                if (node->data.ActualPrice != -1) {
                    sumDiff += (node->data.OriPrice - node->data.ActualPrice) / (float) node->data.Age;
                    count++;
                }
            }
            float aveDiff = sumDiff / (float) count;
            printf("车辆价值随车龄平均降低值为: %.2f 万元/年", aveDiff);
        } else if (!strcmp(input, "0")) {//返回
            break;
        } else {//无效输入
            printf("%s", UI_INPUT_ERROR);
        }
    }
}

void AddCarInfo(void) {
    //显示添加选项列表
    ClearScreen();
    printf("%s", UI_ADD_CAR_OPTION);
    while (true) {
        //等待用户输入
        char input[5];
        UserInput(input);
        if (!strcmp(input, "1")) {//添加单条信息
            printf("请根据以下提示输入二手车信息：");
            printf("%s", UI_INFO_INPUT_TIP);//内容提示
            printf("\n\r");

            CarInfo carInfo;
            //用户输入新二手车信息
            scanf(DATA_INPUT_FORMAT,
                  &carInfo.Id, carInfo.Brand, carInfo.Model,
                  &carInfo.OriPrice, &carInfo.PurchasePrice, &carInfo.ActualPrice,
                  &carInfo.Mileage, &carInfo.Age, &carInfo.HaveRepair, &carInfo.IsFault, carInfo.Status,
                  &carInfo.Date.Year, &carInfo.Date.Mouth, &carInfo.Date.Day,
                  carInfo.Seller.Name, &carInfo.Seller.EstimatedPrice,
                  carInfo.SalesPerson.Name, &carInfo.SalesPerson.Id,
                  carInfo.Customer.Name, carInfo.Customer.PhoneNumber,
                  carInfo.Handler);
            //尾部追加节点
            AppendNode(Head, carInfo);
            Pause("添加完成！");
            return;
        } else if (!strcmp(input, "2")) {//添加文件
            char path[40];
            printf("请输入待添加的数据文件路径：");
            UserInput(path);
            //从文件中读取内容并链接节点
            CarInfoNode *sedHead = ReadCarFromFile(path);
            LinkList(Head, sedHead);
            Pause("添加完成！");
            return;
        } else if (!strcmp(input, "0")) {//返回
            return;
        } else {//无效输入
            printf("%s", UI_INPUT_ERROR);
        }
    }
}

void SaveCarInfo(void) {
    ClearScreen();
    if (SaveCarToFile(DATA_PATH, Head)) {//保存数据并获取结果
        Pause("保存失败！请检查 .\\data\\data.txt");
    } else {
        Pause("保存成功！请检查 .\\data\\data.txt");
    }
}

void Settings(void) {
    //显示更多设置菜单
    ClearScreen();
    printf("%s", UI_MORE_SET_MENU);
    while (true) {
        char input[5];
        UserInput(input);
        if (!strcmp(input, "1")) {//修改密码
            if (ChangePassword() == Success) {//修改密码并获取结果
                Pause("密码修改成功！");
            } else {
                Pause("密码修改失败！");
            }
            return;
        } else if (!strcmp(input, "0")) {//返回
            return;
        } else {//无效输入
            printf("%s", UI_INPUT_ERROR);
        }
    }
}

void SelectCar(int id) {
    //尝试选中指定节点
    CarInfoNode *node = SelectNode(Head, id);
    if (node == NULL) {
        Pause("该编号二手车不存在！请检查后重新输入。");
        return;
    }

    while (true) {
        //显示详细信息菜单
        ClearScreen();
        printf("%s", UI_INFO_HEADER);
        printf("\n\r");
        PrintCarInfo(node);
        printf("\n\r");
        printf("%s", UI_SELECT_MENU);
        //等待用户输入
        char input[5];
        UserInput(input);
        if (!strcmp(input, "1")) {                                          //修改信息
            printf("%s", UI_CHANGE_OPTION);
            while (true) {
                UserInput(input);
                if (!strcmp(input, "1")) {                          //修改品牌
                    printf("请输入新品牌名：");
                    scanf("%s", node->data.Brand);
                } else if (!strcmp(input, "2")) {
                    printf("请输入新型号：");                  //修改型号
                    scanf("%s", node->data.Model);
                } else if (!strcmp(input, "3")) {
                    printf("请输入新原价：");                  //修改原价
                    scanf("%f", &node->data.OriPrice);
                } else if (!strcmp(input, "4")) {
                    printf("请输入新进价：");                  //修改进价
                    scanf("%f", &node->data.PurchasePrice);
                } else if (!strcmp(input, "5")) {
                    printf("请输入新实售价：");                 //修改实售价
                    scanf("%f", &node->data.ActualPrice);
                } else if (!strcmp(input, "6")) {
                    printf("请输入新车辆状态：");                //修改车辆状态
                    scanf("%s", node->data.Status);
                } else if (!strcmp(input, "0")) {                   //返回
                    break;
                } else {                                            //无效输入
                    printf("%s", UI_INPUT_ERROR);
                    continue;
                }
                Pause("二手车信息修改成功！");
                break;
            }
        } else if (!strcmp(input, "2")) {                                   //删除信息
            //二次核对
            printf("%s", DELETE_VERIFY);
            UserInput(input);
            if (!strcmp(input, "y")) {
                Head = DeleteNode(Head, node);
                Pause("已删除该条信息！");
                return;
            }
            continue;
        } else if (!strcmp(input, "0")) {                                   //返回
            return;
        } else {
            printf("%s", UI_INPUT_ERROR);                                 //无效输入
        }
    }

}