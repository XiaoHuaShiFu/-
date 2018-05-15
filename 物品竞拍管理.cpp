/****************************头文件区*********************************/
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <sstream>
#include <conio.h>
#include <windows.h> //Sleep()函数,字体颜色
using namespace std;
/****************************头文件区*********************************/


/****************************宏定义区*********************************/
#define ERROR 0
#define OK 1
#define ElemType int
typedef struct auctionItem{
    long Id;//编号
    char Category[20];//类别
    char Name[30];//名称
    char BiddingMode[5];//明拍和暗拍
    long TheHighestPrice;//最高价
    char TheHighestBidder[30];//最高出价者
    long Evaluation;//估价
    long StartingPrice;//起拍价
    char OldAndNew[3];//新旧
    char Description[101];//物品描述
    char State[10];//物品状态 竞拍中，已成交
    char Owner[30];//物主
    struct auctionItem *next;
} auctionItem,*auctionItems;
typedef struct User{
    char Account[30];
    char Password[20];
    char Nickname[20];
    struct User *next;
}User,*Users;
/****************************宏定义区*********************************/


/****************************全局变量区*******************************/
char Empty[6] = "Empty";
char a1[30] = "请输入物品编号:";
char a2[30] = "请输入物品类别:";
char a3[30] = "请输入物品名称:";
char a4[30] = "请输入物品价格:";
char a5[30] = "请输入物品估价:";
char a6[30] = "请输入物品新旧:";
char a7[30] = "请输入物品描述:";
char a8[30] = "请输入物品状态:";
char a9[30] = "请输入物品所有者:";
char a10[30] = "请输入物品起拍价:";
char a11[30] = "请输入物品拍卖模式:";
char b1[30] = "请输入账号:";
char b2[30] = "请输入昵称:";
char b3[30] = "请输入密码:";
char b4[30] = "请再次输入密码:";
char b5[30] = "请输入新密码:";
char b6[30] = "请再次输入新密码:";
char Traded[7] = "已成交";
char Auctioning[7] = "拍卖中";
char Not[3] = "无";
char Auctioneer[13] = "拍卖行管理员";
/****************************全局变量区*******************************/


/**************************通用函数声明区*****************************/
/*比较两个字符串是否相等，相等返回1，不相等返回0*/
int Equal_Str(char str1[],char str2[]);

/*计算字符串长度，返回字符串长度*/
int Len_Str(char str[]);

/*延时函数，参数单位为毫秒*/
void Delay(int seconds);

/*输出提示并输入整形数据*/
void Input_Int(long &Int,char prompt[]);

/*输出提示并输入字符串型数据*/
void Input_Str(char *Char,char prompt[]);

/*输出提示并输入密码,成功录入返回1，失败返回0*/
int Input_Password(char *Password,char prompt1[],char prompt2[]);

/*整形赋值*/
void Assign_Int(long &Int,long Number);

/*字符串型赋值*/
void Assign_Char(char *Char,char Str[]);

/*清空屏幕*/
void ClearScreen();
/**************************通用函数声明区*****************************/


/**************************物品函数声明区*****************************/
/*返回拍卖品数量*/
int AuctionItemQuantity(auctionItems Items);

/*把物品信息输入文件中*/
void AddAuctionItemToFile();

/*添加物品信息*/
void AddAuctionItem(auctionItem &Item);

/*初始化拍卖品链表*/
void CreateAuctionList(auctionItems &Items);

/*打印拍卖品*/
int PrintAuctionItem(auctionItem Item);

/*打印拍卖品列表*/
int PrintAuctionItems(auctionItems Items);

/*删除拍卖品中某个物品的数据*/
int DeleteItem(auctionItems Items,long Id,auctionItem &Item);

/*删除物品信息并打印删除结果*/
void DeleteItemAndPrint(auctionItems &Items,long Id,auctionItem &Item);

/*修改某个拍卖品的信息*/
int ModifyItem(auctionItems &Items,long Id,auctionItem &PreItem,auctionItem &PostItem);

/*修改某个拍卖品的信息并打印*/
int ModifyItemAndPrint(auctionItems &Items,long Id,auctionItem &PreItem,auctionItem &PostItem);

/*通过Id寻找物品，找不到返回0，找到返回1*/
int SearchById(auctionItems Items,long Id,auctionItem &Item);

/*通过Name寻找物品，找不到返回0，找到返回1*/
int SearchByName(auctionItems Items,char Name[],auctionItem &Item);

/*通过Category寻找物品，找不到返回0，找到返回找到的个数*/
int SearchByCategory(auctionItems Items,char Category[]);

/*通过State寻找物品，找不到返回0，找到返回找到的个数*/
int SearchByState(auctionItems Items,char State[]);

/*通过TheHighestBidder寻找物品，找不到返回0，找到返回找到的个数*/
int SearchByTheHighestBidder(auctionItems Items,char TheHighestBidder[]);

/*通过Owner寻找物品，找不到返回0，找到返回找到的个数*/
int SearchByOwner(auctionItems Items,char Owner[]);

/*返回当前拍卖行中拍卖品的最高拍卖价格*/
long TheHighestPriceInAuctionHouse(auctionItems Items,auctionItem &Item);

/*返回当前拍卖行中拍卖品的最低拍卖价格*/
long TheLowestPriceInAuctionHouse(auctionItems Items,auctionItem &Item);

/*返回当前拍卖行中拍卖品的总成交额*/
long TurnoverInAuctionHouse(auctionItems Items);

/*返回当前拍卖行中拍卖品的总成交数or正在拍卖数*/
int TurnoverNumberInAuctionHouse(auctionItems Items,char State[]);

/*开始拍卖，成功返回1，失败返回0*/
int  StartAuction(auctionItem &Item);

/*物品搜索页面*/
int SearchPage(auctionItems &Items,auctionItem &Item,User UserItem);

/*物品清单页面*/
int ItemsPage(auctionItems &Items,auctionItem &Item,User UserItem);

/*用户竞拍*/
int UserBid(auctionItems &Items,auctionItem &Item,User UserItem);

/*拍卖行大数据页面*/
int BigDataPage(auctionItems Items,Users UserItems,auctionItem Item);

/**************************物品函数声明区*****************************/


/**************************用户函数声明区*****************************/
/*向文件添加用户信息*/
void AddUserToFile(User &UserItem);

/*添加用户信息*/
void AddUser(User &UserItem);

/*新用户注册*/
void Register(Users UserItems,User UserItem);

/*删除用户信息*/
int DeleteUser(Users UserItems,char *UserAccount,User &UserItem);

/*删除用户信息后并重新创建链表*/
int DeleteUserAndCreateList(Users &UserItems,char *UserAccount,User &UserItem);

/*初始化用户链表*/
void CreateUserList(Users &UserItems);

/*通过Account寻找用户，找不到返回0，找到返回1*/
int SearchByAccount(Users UserItems,char Account[],User &UserItem);

/*通过Nickname寻找用户，找不到返回0，找到返回1*/
int SearchByNickname(Users UserItems,char Nickname[],User &UserItem);

/*用户登录，成功返回1，密码错误返回-1，账号不存在返回0*/
int UserLog(Users UserItems,User &UserItem);

/*用户登录并打印UI页面,成功返回1，失败返回0*/
int UserLogPrint(Users UserItems,User &UserItem);

/*打印用户信息*/
void PrintUser(User UserItem);

/*打印用户信息列表*/
int PrintUsers(Users UserItems);

/*返回当前拍卖行中的用户数*/
int UserNumberInAuctionHouse(Users UserItems);

/*修改密码函数*/
int ModifyUserPassword(Users &UserItems,char *Account,char *Password);

/*修改密码页面*/
int ModifyPasswordPage(Users &UserItems,User &UserItem);
/**************************用户函数声明区*****************************/


/*****************************UI声明区********************************/
/*打印页面头*/
void Page_Head(char *Title);

/*首页选项卡*/
void InitPrintHomePage();

/*首页打印*/
void PrintHomePage(void (*Selection)());

/*首页登录框*/
void LogPrintHomePage();

/*新用户注册页面*/
void RegisterPage();

/*主页*/
void PrintIndexPage();

/*主页物品搜索页*/
void PrintIndex_SearchPage();

/*物品清单页面*/
void PrintIndex_ItemsPage();

/*打印拍卖行大数据页面*/
void PrintIndex_BigDataPage();

/*打印我的页面*/
void PrintMyPage();

/*打印我的竞拍页面*/
void PrintMyAuctions(auctionItems Items,User UserItem);

/*字体、背景初始化*/
void InitBackgroundAndFont();
/*****************************UI声明区********************************/


/****************************通用函数区*******************************/
/*比较两个字符串是否相等，相等返回1，不相等返回0*/
int Equal_Str(char str1[],char str2[]){
    if(strcmp(str1,str2) == 0) return 1;
    return 0;
}

/*计算字符串长度，返回字符串长度*/
int Len_Str(char str[]){
    return strlen(str);
}

/*延时函数，参数单位为毫秒*/
void Delay(int seconds){
    Sleep(seconds);
}

/*输出提示并输入整形数据*/
void Input_Int(long &Int,char prompt[]){
    if(Equal_Str(prompt,Empty)){
        scanf("%ld",&Int);
    }
    else{
        cout << prompt;
        scanf("%ld",&Int);
    }
}

/*输出提示并输入字符串型数据*/
void Input_Str(char *Char,char prompt[]){
    if(Equal_Str(prompt,Empty)){
        scanf("%s",Char);
    }
    else{
        cout << prompt;
        scanf("%s",Char);
    }
}

/*输出提示并输入密码,成功录入返回1，失败返回0*/
//如何删除backspace删除屏幕显示的一个星星符还未解决
int Input_Password(char *Password,char prompt1[],char prompt2[]){
    int idx = 0;
    char c,FirstInput[20],SecondInput[20];
    cout << prompt1;
    while((c = getch()) != '\r'){
//        if(c == '\b'){
//             if(idx != 0){
//                cout << '\b';
//                idx--;
//                continue;
//             }
//             else{
//                continue;
//             }
//        }
        FirstInput[idx++] = c;
        cout << '*';
    }
    FirstInput[idx] = '\0';
    cout << endl << prompt2;
    idx = 0;
    while((c = getch()) != '\r'){
//        if(c == '\b'){
//             if(idx != 0){
//                cout << '\b';
//                idx--;
//                continue;
//             }
//             else{
//                continue;
//             }
//        }
        SecondInput[idx++] = c;
        cout << '*';
    }
    SecondInput[idx] = '\0';
    cout << endl;
    if(Equal_Str(FirstInput,SecondInput)){
        Assign_Char(Password,FirstInput);
        return 1;
    }
    else return 0;
}

/*整形赋值*/
void Assign_Int(long &Int,long Number){
    Int = Number;
}

/*字符串型赋值*/
void Assign_Char(char *Char,char *Str){
    strcpy(Char,Str);
}

/*清空屏幕*/
void ClearScreen(){
    system("cls");
}
/****************************通用函数区*******************************/


/****************************拍卖品链表操作区*******************************/

/*返回拍卖品数量*/
int AuctionItemQuantity(auctionItems Items){
    int Quantity = 0;
    while(Items -> next){
        Items = Items -> next;
        Quantity++;
    }
    return Quantity;
}

/*把物品信息输入文件中*/
void AddAuctionItemToFile(auctionItem &Item){
    FILE *fp;
    fp=fopen("auctionItems_DataBase.txt","a+");
    fwrite(&Item,sizeof(auctionItem),1,fp);
    fclose(fp);
}

/*添加物品信息*/
void AddAuctionItem(auctionItem &Item){
    Input_Int(Item.Id,a1);
    Input_Str(Item.Category,a2);
    Input_Str(Item.Name,a3);
    Input_Str(Item.BiddingMode,a11);
    Assign_Int(Item.TheHighestPrice,0);
    Assign_Char(Item.TheHighestBidder,Not);
    Input_Int(Item.Evaluation,a5);
    Input_Int(Item.StartingPrice,a10);
    Input_Str(Item.OldAndNew,a6);
    Input_Str(Item.Description,a7);
    Assign_Char(Item.State,Auctioning);
    Assign_Char(Item.Owner,Auctioneer);
}

/*初始化拍卖品链表*/
void CreateAuctionList(auctionItems &Items){
    FILE *fp;
    fp = fopen("auctionItems_DataBase.txt","rb");
    auctionItems Pointer,PointerBridge ;//head指针为链表的头结点，是找到链表的唯一依据，如果head指针丢失，那么整个链表就找不到了;p指针总是指向新申请的结点;q指针总是指向尾节点
    auctionItem temp;//定义结构体别名
    Items = (auctionItems)malloc(sizeof(auctionItem));
    Items->next = NULL;
    Pointer = (auctionItems)malloc(sizeof(auctionItem));  // p指向新开辟的节点内存
    Pointer = Items;    //开辟头结点内存      头结点中没有学生成绩信息
    while(fread(&temp,sizeof(auctionItem),1,fp)!=0){//从文件中读结构体块
        PointerBridge = (auctionItems)malloc(sizeof(auctionItem)); // p指向新开辟的节点内存
        Assign_Int(PointerBridge -> Id,temp.Id);
        Assign_Char(PointerBridge -> Category,temp.Category);
        Assign_Char(PointerBridge -> Name,temp.Name);
        Assign_Char(PointerBridge -> BiddingMode,temp.BiddingMode);
        Assign_Int(PointerBridge -> TheHighestPrice,temp.TheHighestPrice);
        Assign_Char(PointerBridge -> TheHighestBidder,temp.TheHighestBidder);
        Assign_Int(PointerBridge -> Evaluation,temp.Evaluation);
        Assign_Int(PointerBridge -> StartingPrice,temp.StartingPrice);
        Assign_Char(PointerBridge -> OldAndNew,temp.OldAndNew);
        Assign_Char(PointerBridge -> Description,temp.Description);
        Assign_Char(PointerBridge -> State,temp.State);
        Assign_Char(PointerBridge -> Owner,temp.Owner);
        PointerBridge->next = Pointer -> next;
        Pointer->next = PointerBridge;
        Pointer = PointerBridge;
    }
    fclose(fp);
}

/*打印拍卖品，返回1*/
int PrintAuctionItem(auctionItem Item){
    cout << "                     ";
    cout << "-------------------------" << endl;
    cout << "                     ";
    cout << "------物品信息如下-------" << endl ;
    cout << "                     ";
    cout << " 编号：" << Item.Id << endl ;
    cout << "                     ";
    cout << " 类型：" << Item.Category << endl ;
    cout << "                     ";
    cout << " 名称：" << Item.Name << endl ;
    cout << "                     ";
    cout << " 拍卖方式：" << Item.BiddingMode << endl ;
    cout << "                     ";
    cout << " 最高价：" << Item.TheHighestPrice << endl ;
    cout << "                     ";
    cout << " 最高出价者：" << Item.TheHighestBidder << endl ;
    cout << "                     ";
    cout << " 估价：" << Item.Evaluation << endl ;
    cout << "                     ";
    cout << " 起拍价：" << Item.StartingPrice << endl ;
    cout << "                     ";
    cout << " 新旧：" << Item.OldAndNew << endl ;
    cout << "                     ";
    cout << " 描述：" << Item.Description << endl ;
    cout << "                     ";
    cout << " 状态：" << Item.State << endl ;
    cout << "                     ";
    cout << " 拥有者：" << Item.Owner << endl ;
    cout << "                     ";
    cout << "---From Auction By XHSF--" << endl ;
    cout << "                     ";
    cout << "-------------------------" << endl;
    return 1;
}

/*打印拍卖品列表，空表返回0，打印成功返回1*/
int PrintAuctionItems(auctionItems Items){
    if(Items->next == NULL) return 0;
    while(Items->next != NULL){
        Items = Items->next;
        PrintAuctionItem(*Items);
    }
    return 1;
}

/*删除拍卖品中某个物品的数据，原文件为空返回-2，
找不到要删除的物品返回-1，文件打开失败返回0，修改成功返回1*/
int DeleteItem(auctionItems Items,long Id,auctionItem &Item){
    int Flag = 0;
    FILE *Prototype,*Temporary;
    Prototype = fopen("auctionItems_DataBase.txt","rb");
    Temporary = fopen("auctionItems_DataBase_Temporary.txt","a+");
    if(Prototype == NULL || Temporary == NULL){
        fclose(Prototype);
        fclose(Temporary);
        return 0; //排除打开文件失败
    }
    if(Items->next == NULL){
        fclose(Prototype);
        fclose(Temporary);
        return -2;//排除原链表为空
    }
    while(Items->next != NULL){
        Items = Items->next;
        if(Items -> Id != Id) fwrite(&*Items,sizeof(auctionItem),1,Temporary);//把不是要删除的节点写入临时文件
        else{
            Item = *Items;//返回要删除节点的信息
            Flag = 1;
        }
    }
    fclose(Prototype);
    fclose(Temporary);
    remove("auctionItems_DataBase.txt");//删除原文件
    rename("auctionItems_DataBase_Temporary.txt","auctionItems_DataBase.txt");//把临时文件名改为原文件名
    if(Flag == 0) return -1; //如果没有找到所要的编号 则返回1
    return 1;//找到则返回1
}

/*删除物品信息并打印删除结果，删除失败返回0，删除成功返回1*/
void DeleteItemAndPrint(auctionItems &Items,long Id,auctionItem &Item){
    int ReturnValue = DeleteItem(Items,Id,Item);
    if(ReturnValue == -2){
        cout << "原文件为空" << endl;
//        return 0;
    }
    else if(ReturnValue == -1){
        cout << "找不到编号为" << Id << "的物品" << endl;
//        return 0;
    }
    else if(ReturnValue == 0){
        cout << "文件打开失败" << endl;
//        return 0;
    }
    else{
        CreateAuctionList(Items);
        cout << "-----------删除后文件列表-----------" << endl;
        PrintAuctionItems(Items);
        cout << "-----------删除的物品信息-----------" << endl;
        PrintAuctionItem(Item);
//        return 1;
    }
}

/*修改某个拍卖品的信息，如果成功修改返回1，找不到要修改的物品返回0*/
int ModifyItem(auctionItems &Items,long Id,auctionItem &PreItem,auctionItem &PostItem){
    if(DeleteItem(Items,Id,PreItem) == -2){//删除原物品信息
        cout << "----------------找不到要修改的物品-----------------" << endl;
        return 0;
    }
    AddAuctionItemToFile(PostItem);//输入修改后的信息
    CreateAuctionList(Items);//重新初始化链表
    return 1;
}

/*修改某个拍卖品的信息并打印，如果成功修改返回1，修改失败返回0*/
int ModifyItemAndPrint(auctionItems &Items,long Id,auctionItem &PreItem,auctionItem &PostItem){
    if(ModifyItem(Items,4,PreItem,PostItem)){
        cout << "-------------打印修改前物品的信息---------------" <<endl;
        PrintAuctionItem(PreItem);
        cout << "-------------打印修改后物品的信息---------------" <<endl;
        PrintAuctionItem(PostItem);
        return 1;
    }
    return 0;
}

/*通过Id寻找物品，找不到返回0，找到返回1*/
int SearchById(auctionItems Items,long Id,auctionItem &Item){
    while(Items -> next != NULL){
        Items = Items -> next;
        if(Items -> Id == Id){
            Item = *Items;
            return 1;
        }
    }
    return 0;
}

/*通过Name寻找物品，找不到返回0，找到返回1*/
int SearchByName(auctionItems Items,char Name[],auctionItem &Item){
    while(Items -> next != NULL){
        Items = Items -> next;
        if(Equal_Str(Items->Name,Name)){
            Item = *Items;
            return 1;
        }
    }
    return 0;
}

/*通过Category寻找物品，找不到返回0，找到返回找到的个数*/
int SearchByCategory(auctionItems Items,char Category[]){
    int Quantity = 0;
    while(Items -> next != NULL){
        Items = Items -> next;
        if(Equal_Str(Items->Category,Category)){
            Quantity++;
            PrintAuctionItem(*Items);
        }
    }
    return Quantity;
}

/*通过State寻找物品，找不到返回0，找到返回找到的个数*/
int SearchByState(auctionItems Items,char State[]){
    int Quantity = 0;
    while(Items -> next != NULL){
        Items = Items -> next;
        if(Equal_Str(Items->State,State)){
            Quantity++;
            PrintAuctionItem(*Items);
        }
    }
    return Quantity;
}

/*通过TheHighestBidder寻找物品，找不到返回0，找到返回找到的个数*/
int SearchByTheHighestBidder(auctionItems Items,char TheHighestBidder[]){
    int Quantity = 0;
    while(Items -> next != NULL){
        Items = Items -> next;
        if(Equal_Str(Items->TheHighestBidder,TheHighestBidder)){
            Quantity++;
            PrintAuctionItem(*Items);
        }
    }
    return Quantity;
}

/*通过Owner寻找物品，找不到返回0，找到返回找到的个数*/
int SearchByOwner(auctionItems Items,char Owner[]){
    int Quantity = 0;
    while(Items -> next != NULL){
        Items = Items -> next;
        if(Equal_Str(Items->Owner,Owner)){
            Quantity++;
            PrintAuctionItem(*Items);
        }
    }
    return Quantity;
}

/*返回当前拍卖行中拍卖品的最高拍卖价格*/
long TheHighestPriceInAuctionHouse(auctionItems Items,auctionItem &Item){
    long HighestPrice = 0;
    while(Items -> next != NULL){
        Items = Items -> next;
        if(Items -> TheHighestPrice >= HighestPrice && Equal_Str(Items -> State,Traded)){
            HighestPrice = Items -> TheHighestPrice;
            Item = *Items;
        }
    }
    return HighestPrice;
}

/*返回当前拍卖行中拍卖品的最低拍卖价格*/
long TheLowestPriceInAuctionHouse(auctionItems Items,auctionItem &Item){
    long LowestPrice = 0;
    while(Items -> next != NULL){
        Items = Items -> next;
        if(Items -> TheHighestPrice <= LowestPrice && Equal_Str(Items -> State,Traded)){
            LowestPrice = Items -> TheHighestPrice;
            Item = *Items;
        }
    }
    return LowestPrice;
}

/*返回当前拍卖行中拍卖品的总成交额*/
long TurnoverInAuctionHouse(auctionItems Items){
    long Turnover = 0;
    while(Items -> next != NULL){
        Items = Items -> next;
        if(Equal_Str(Items -> State,Traded)) Turnover += (Items -> TheHighestPrice);
    }
    return Turnover;
}

/*返回当前拍卖行中拍卖品的总成交数or正在拍卖数*/
int TurnoverNumberInAuctionHouse(auctionItems Items,char State[]){
    long TurnoverNumber = 0;
    while(Items -> next != NULL){
        Items = Items -> next;
        if(Equal_Str(Items -> State,State)) TurnoverNumber++;
    }
    return TurnoverNumber;
}

/*开始拍卖，成功返回1，失败返回0*/
int  StartAuction(auctionItems &Items,auctionItem &Item){
    if(Item.TheHighestPrice >= Item.StartingPrice){
        DeleteItem(Items,Item.Id,Item);
        Assign_Char(Item.Owner,Item.TheHighestBidder);
        Assign_Char(Item.State,Traded);
        FILE *fp;
        fp=fopen("auctionItems_DataBase.txt","a+");
        fwrite(&Item,sizeof(auctionItem),1,fp);
        fclose(fp);
        CreateAuctionList(Items);//重新初始化链表
        return 1;//拍卖成功返回1
    }
    else{
        return 0;//拍卖失败
    }
}

/*用户竞拍，出价成功返回1，失败返回0*/
int UserBid(auctionItems &Items,auctionItem &Item,User UserItem){
    long Price;
    cout << endl << endl << "                     ";
    cout << "------物品信息如下-------" << endl ;
    cout << "                     ";
    cout << " 当前物品最高价：" << Item.TheHighestPrice << endl;
    cout << "                     ";
    cout << " 当前物品起拍价：" << Item.StartingPrice << endl;
    cout << "                     ";
    cout << " 当前物品估价：" << Item.Evaluation << endl;
    cout << "                     ";
    cout << " 请输入您的出价：";
    scanf("%ld",&Price);
    if(Price > Item.TheHighestPrice && Price > Item.StartingPrice){
        DeleteItem(Items,Item.Id,Item);
        Assign_Char(Item.TheHighestBidder,UserItem.Nickname);
        Assign_Int(Item.TheHighestPrice,Price);
        FILE *fp;
        fp=fopen("auctionItems_DataBase.txt","a+");
        fwrite(&Item,sizeof(auctionItem),1,fp);
        fclose(fp);
        CreateAuctionList(Items);//重新初始化链表
        return 1;//出价成功返回1
    }
    else{
        return 0;//
    }
}

/*物品搜索页面*/
int SearchPage(auctionItems &Items,auctionItem &Item,User UserItem){
    PrintIndex_SearchPage();
    char Selection;
    Selection = getch();
    char TITLE[20] = "    物品搜索";
    int Id;
    char Name[30],Category[20];
    switch(Selection){
        case '1':
                Page_Head(TITLE);
                cout << "                     ";
                cout << "   请输入物品编号：";
                scanf("%ld",&Id);
                if(SearchById(Items,Id,Item)){
                    PrintAuctionItem(Item);
                    cout << "                     ";
                    cout <<"按1进行竞拍，按2返回主页";
                    Selection = getch();
                    switch(Selection){
                        case '1':
                                if(UserBid(Items,Item,UserItem)){
                                    cout << "                     ";
                                    cout <<"竞拍成功，1秒后返回主页";
                                    Delay(1000);
                                    return 1;
                                }else{
                                    cout << "                     ";
                                    cout <<"竞拍失败，1秒后返回主页";
                                    Delay(1000);
                                    return 1;
                                }
                                break;
                        case '2':return 1;break;
                    }

                }else{
                    cout << "                     ";
                    cout <<"搜索失败，1秒后返回主页";
                    Delay(1000);
                    return 1;
                }
                break;
        case '2':
                Page_Head(TITLE);
                cout << "                     ";
                cout << "   请输入物品类别：";
                scanf("%s",Category);
                if(SearchByCategory(Items,Category)){
                    cout << "                     ";
                    cout <<"按1进行竞拍，按2返回主页";
                    Selection = getch();
                    switch(Selection){
                        case '1':
                                cout << endl << "                     ";
                                cout << "   请输入物品编号：";
                                scanf("%ld",&Id);
                                SearchById(Items,Id,Item);
                                if(UserBid(Items,Item,UserItem)){
                                    cout << "                     ";
                                    cout <<"竞拍成功，1秒后返回主页";
                                    Delay(1000);
                                    return 1;
                                }else{
                                    cout << "                     ";
                                    cout <<"竞拍失败，1秒后返回主页";
                                    Delay(1000);
                                    return 1;
                                }
                                break;
                        case '2':return 1;break;
                    }

                }else{
                    cout << "                     ";
                    cout <<"搜索失败，1秒后返回主页";
                    Delay(1000);
                    return 1;
                }
                break;
        case '3':
                Page_Head(TITLE);
                cout << "                     ";
                cout << "   请输入物品名称：";
                scanf("%s",Name);
                if(SearchByName(Items,Name,Item)){
                    PrintAuctionItem(Item);
                    cout << "                     ";
                    cout <<"按1进行竞拍，按2返回主页";
                    Selection = getch();
                    switch(Selection){
                        case '1':
                                if(UserBid(Items,Item,UserItem)){
                                    cout << "                     ";
                                    cout <<"竞拍成功，1秒后返回主页";
                                    Delay(1000);
                                    return 1;
                                }else{
                                    cout << "                     ";
                                    cout <<"竞拍失败，1秒后返回主页";
                                    Delay(1000);
                                    return 1;
                                }
                                break;
                        case '2':return 1;break;
                    }

                }else{
                    cout << "                     ";
                    cout <<"搜索失败，1秒后返回主页";
                    Delay(1000);
                    return 1;
                }
                break;
        case '4':
                return 1;
                break;
    }
}

/*物品清单页面*/
int ItemsPage(auctionItems &Items,auctionItem &Item,User UserItem){
    PrintIndex_ItemsPage();
    PrintAuctionItems(Items);
    char Selection;
    int Id;
    cout << endl << "                     ";
    cout << "  请选择要进行的操作：" << endl << endl;
    cout << "                     ";
    cout << "      1.进行竞拍"    << endl << endl;
    cout << "                     ";
    cout << "      2.返回主页"    << endl << endl;
    Selection = getch();
    switch(Selection){
        case '1':
                cout << "                     ";
                cout << "   请输入物品编号：";
                scanf("%ld",&Id);
                if(SearchById(Items,Id,Item)){
                    if(UserBid(Items,Item,UserItem)){
                        cout << "                     ";
                        cout <<"竞拍成功，1秒后返回主页";
                        Delay(1000);
                        return 1;
                    }else{
                        cout << "                     ";
                        cout <<"竞拍失败，1秒后返回主页";
                        Delay(1000);
                        return 1;
                    }
                }else{
                    cout << "                     ";
                    cout <<"物品不存在，1秒后返回主页";
                    Delay(1000);
                    return 1;
                }
                break;
        case '2':
                return 1;
                break;
    }
}

/*拍卖行大数据页面*/
int BigDataPage(auctionItems Items,Users UserItems,auctionItem Item){
    PrintIndex_BigDataPage();
    char Selection;
    char State1[7] = "已成交";
    char State2[7] = "拍卖中";
    cout << "                     ";
    cout << "-------------------------" << endl;
    cout << "                     ";
    cout << "                       " << endl ;
    cout << "                     ";
    cout << " Welcome to 拍卖行大数据 " << endl << endl;
    cout << "                     ";
    cout << "-------------------------" << endl;
    cout << "                     ";
    cout << "当前拍卖行用户总数是： " << UserNumberInAuctionHouse(UserItems) << endl;
    cout << "                     ";
//    cout << "-------------------------" << endl;
//    cout << "                     ";
//    TheHighestPriceInAuctionHouse(Items,Item);
//    cout << "  当前最高价格的拍卖品是"  << endl;
//    cout << "                     ";
//    cout << "*********" << Item.Name <<"**********" << endl;
//    cout << "                     ";
//    cout << "*****成交价为：" << Item.TheHighestPrice << "*****"<< endl;
//    cout << "                     ";
//    cout << "-------------------------" << endl;
//    cout << "                     ";
//    TheLowestPriceInAuctionHouse(Items,Item);
//    cout << "  当前最低价格的拍卖品是 " << endl;
//    cout << "                     ";
//    cout << "*********" << Item.Name <<"**********" << endl;
//    cout << "                     ";
//    cout << "*****成交价为：" << Item.TheHighestPrice << "*****" << endl;
//    cout << "                     ";
    cout << "-------------------------" << endl;
    cout << "                     ";
    cout << "当前已拍卖的物品数是：" << TurnoverNumberInAuctionHouse(Items,State1) << endl;
    cout << "                     ";
    cout << "-------------------------" << endl;
    cout << "                     ";
    cout << "当前拍卖中的物品数是：" << TurnoverNumberInAuctionHouse(Items,State2) << endl;
    cout << "                     ";
    cout << "-------------------------" << endl;
    cout << "                     ";
    cout << "当前拍卖行的总交易额是：" << TurnoverInAuctionHouse(Items) << endl;
    cout << "                     ";
    cout << "-------------------------" << endl << endl << endl;
    cout << endl << "                     ";
    cout << "    按任意键返回主页     " << endl << endl;
    cout << "____________________________________________________________________" << endl ;
    cout << "                     ";
    cout << "    2018.5.3 By XHSF      " << endl << endl << endl<< endl;
    Selection = getch();
    return 1;
}

/****************************拍卖品链表操作区*******************************/


/****************************用户链表操作区*********************************/
/*向文件添加用户信息*/
void AddUserToFile(User &UserItem){
    FILE *fp;
    fp = fopen("Users_DataBase.txt","a+");
    fwrite(&UserItem,sizeof(User),1,fp);
    fclose(fp);
}

/*添加用户信息*/
void AddUser(User &UserItem){
    Input_Str(UserItem.Account,b1);
    Input_Str(UserItem.Nickname,b2);
    Input_Password(UserItem.Password,b3,b4);
}

/*新用户注册*/
void Register(Users UserItems,User UserItem){
    int FlagAccount = 0,FlagPassword = 6,FlagNickname = 4,idx = 0;
    char Password[20],Account[30],Nickname[30],c;
    do{
        RegisterPage();
        if(FlagAccount){
            cout << "                     ";
            cout << "   该账号已被注册    " << endl << endl;
        }
        if(FlagPassword < 6){
            cout << "                     ";
            cout << "密码应大于等于6个字符" << endl << endl;
        }
        if(FlagNickname < 4){
            cout << "                     ";
            cout << "昵称应大于等于4个字符" << endl << endl;
        }
        cout << "                     ";
        cout << "昵称：" ;
        scanf("%s",Nickname);
        cout<< endl << endl  << "                     ";
        cout << "账号：" ;
        scanf("%s",Account);
        cout<< endl << endl  << "                     ";
        cout  << "密码：" ;
        while((c = getch()) != '\r'){
        if(c == '\b'){
            if(idx != 0){
                cout << '\b';
                idx--;
                continue;
                }
                else{
                    continue;
                }
            }
            Password[idx++] = c;
            cout << '*';
        }
        Password[idx] = '\0';
        cout <<  endl ;
        FlagNickname = Len_Str(Nickname);
        FlagAccount = SearchByAccount(UserItems,Account,UserItem);
        FlagPassword = Len_Str(Password);
    }while(FlagAccount || FlagPassword < 6 || FlagNickname < 4);
    Assign_Char(UserItem.Nickname,Nickname);
    Assign_Char(UserItem.Account,Account);
    Assign_Char(UserItem.Password,Password);
    AddUserToFile(UserItem);
    cout << "                     ";
    cout << "注册中，请等候。。。 " << endl ;
    Delay(1000);
}

/*删除用户信息*/
int DeleteUser(Users UserItems,char *UserAccount,User &UserItem){
    int Flag = 0;
    FILE *Prototype,*Temporary;
    Prototype = fopen("Users_DataBase.txt","rb");
    Temporary = fopen("Users_DataBase_Temporary.txt","a+");
    if(Prototype == NULL || Temporary == NULL){
        fclose(Prototype);
        fclose(Temporary);
        return 0; //排除打开文件失败
    }
    if(UserItems->next == NULL){
        fclose(Prototype);
        fclose(Temporary);
        return -2;//排除原链表为空
    }
    while(UserItems->next != NULL){
        UserItems = UserItems->next;
        if(!Equal_Str(UserItems->Account,UserAccount)) fwrite(&*UserItems,sizeof(User),1,Temporary);//把不是要删除的节点写入临时文件
        else{
            UserItem = *UserItems;//返回要删除节点的信息
            Flag = 1;
        }
    }
    fclose(Prototype);
    fclose(Temporary);
    remove("Users_DataBase.txt");//删除原文件
    rename("Users_DataBase_Temporary.txt","Users_DataBase.txt");//把临时文件名改为原文件名
    if(Flag == 0) return -1; //如果没有找到所要删除的编号 则返回1
    return 1;//找到则返回1
}

/*删除用户信息后并重新创建链表*/
int DeleteUserAndCreateList(Users &UserItems,char *UserAccount,User &UserItem){
    int ReturnValue = DeleteUser(UserItems,UserAccount,UserItem);
    CreateUserList(UserItems);
    return ReturnValue;
}

/*初始化用户链表*/
void CreateUserList(Users &UserItems){
    FILE *fp;
    fp = fopen("Users_DataBase.txt","rb");
    Users Pointer,PointerBridge ;//head指针为链表的头结点，是找到链表的唯一依据，如果head指针丢失，那么整个链表就找不到了;p指针总是指向新申请的结点;q指针总是指向尾节点
    User temp;//定义结构体别名
    UserItems = (Users)malloc(sizeof(User));
    UserItems->next = NULL;
    Pointer = (Users)malloc(sizeof(User));  // p指向新开辟的节点内存
    Pointer = UserItems;    //开辟头结点内存      头结点中没有学生成绩信息
    while(fread(&temp,sizeof(User),1,fp)!=0){//从文件中读结构体块
        PointerBridge = (Users)malloc(sizeof(User)); // p指向新开辟的节点内存
        Assign_Char(PointerBridge -> Account,temp.Account);
        Assign_Char(PointerBridge -> Nickname,temp.Nickname);
        Assign_Char(PointerBridge -> Password,temp.Password);
        PointerBridge->next = Pointer -> next;
        Pointer->next = PointerBridge;
        Pointer = PointerBridge;
    }
    fclose(fp);
}

/*通过Account寻找用户，找不到返回0，找到返回1*/
int SearchByAccount(Users UserItems,char Account[],User &UserItem){
    while(UserItems -> next != NULL){
        UserItems = UserItems -> next;
        if(Equal_Str(UserItems->Account,Account)){
            UserItem = *UserItems;
            return 1;
        }
    }
    return 0;
}

/*通过Nickname寻找用户，找不到返回0，找到返回1*/
int SearchByNickname(Users UserItems,char Nickname[],User &UserItem){
    while(UserItems -> next != NULL){
        UserItems = UserItems -> next;
        if(Equal_Str(UserItems->Nickname,Nickname)){
            UserItem = *UserItems;
            return 1;
        }
    }
    return 0;
}

/*返回当前拍卖行中的用户数*/
int UserNumberInAuctionHouse(Users UserItems){
    long UserNumber = 0;
    while(UserItems -> next != NULL){
        UserItems = UserItems -> next;
        UserNumber++;
    }
    return UserNumber;
}

/*打印用户信息*/
void PrintUser(User UserItem){
    cout << "------------------------" << endl;
    cout << UserItem.Account << endl;
    cout << UserItem.Nickname << endl;
    cout << UserItem.Password << endl;
    cout << "------------------------" << endl;
}

/*打印用户信息列表*/
int PrintUsers(Users UserItems){
    if(UserItems->next == NULL) return 0;
    while(UserItems->next != NULL){
        UserItems = UserItems->next;
        PrintUser(*UserItems);
    }
    return 1;
}

/*用户登录，成功返回1，密码错误返回-1，账号不存在返回0*/
int UserLog(Users UserItems,User &UserItem,char *Account,char *Password){
    if(SearchByAccount(UserItems,Account,UserItem)){
        if(Equal_Str(Password,UserItem.Password)) return 1;//登录成功
        else return -1;//密码错误
    }
    return 0;//账号不存在
}

/*用户登录并打印UI页面,成功返回1，失败返回0*/
int UserLogPrint(Users UserItems,User &UserItem){
    int FlagLog = 1,idx = 0;
        char Password[20],Account[30],c;
        do{
            LogPrintHomePage();
            if(FlagLog!=1){
                cout << "                        ";
                cout << "密码或账号错误，请重新登录" << endl ;
            }
            cout<< endl << endl  << "                     ";
            cout << "账号：" ;
            scanf("%s",Account);
            cout<< endl << endl  << "                     ";
            cout  << "密码：" ;
            while((c = getch()) != '\r'){
            if(c == '\b'){
                if(idx != 0){
                    cout << '\b';
                    idx--;
                    continue;
                    }
                    else{
                        continue;
                    }
                }
                Password[idx++] = c;
                cout << '*';
            }
            Password[idx] = '\0';
            cout <<  endl ;
            FlagLog = UserLog(UserItems,UserItem,Account,Password);
        }while(FlagLog != 1);
        cout << endl << endl << endl ;
        cout << "                     ";
        cout << "  登录中，请等待...  " << endl;
        Delay(500);
}

/*修改密码函数*/
int ModifyUserPassword(Users &UserItems,char *Account,char *Password){

    User UserItem;
    DeleteUser(UserItems,Account,UserItem);
    Assign_Char(UserItem.Password,Password);
    FILE *fp;
    fp = fopen("Users_DataBase.txt","a+");
    fwrite(&UserItem,sizeof(User),1,fp);
    CreateUserList(UserItems);//重新初始化链表
    fclose(fp);
    return 1;
}

/*修改密码页面*/
int ModifyPasswordPage(Users &UserItems,User &UserItem){
    char TITLE[20] = "    修改密码";
    char Password[20];
    Page_Head(TITLE);
    int idx = 0;
    char c,FirstInput[20],SecondInput[20];
    cout << "                     ";
    cout << "   请输入原密码：" ;
    while((c = getch()) != '\r'){
        FirstInput[idx++] = c;
        cout << '*';
    }
    FirstInput[idx] = '\0';
    idx = 0;
    cout << endl << endl << "                     ";
    cout << "   请输入新密码：";
    while((c = getch()) != '\r'){
        SecondInput[idx++] = c;
        cout << '*';
    }
    SecondInput[idx] = '\0';
    cout << endl;
    if(Equal_Str(FirstInput,UserItem.Password)){
        Assign_Char(Password,SecondInput);
        ModifyUserPassword(UserItems,UserItem.Account,Password);
        cout << endl << endl << "                  ";
        cout << "密码修改成功，1秒后返回我的界面：";
        Delay(1000);
        return 1;
    }
    else{
        cout << "                     ";
        cout << "原密码输入错误，1秒后返回我的界面：";
        Delay(1000);
        return 1;
    }
}

/****************************用户链表操作区*********************************/


/*******************************UI操作区************************************/
/*打印页面头*/
void Page_Head(char *Title){
    ClearScreen();
    cout << endl << "                     ";
    cout << "Auction management system" << endl;
    cout << "                         ";
    cout << Title << endl;
    cout << "____________________________________________________________________" << endl << endl << endl<< endl;
}

/*首页打印*/
void PrintHomePage(void (*Selection)()){
    char TITLE[20] = "物品竞拍管理系统";
    Page_Head(TITLE);
    cout << "                     ";
    cout << "-------------------------" << endl;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "Welcome to 竞拍管理系统" << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    Selection();
}

/*首页选项卡*/
void InitPrintHomePage(){
    cout << "                     ";
    cout << "|" << "  请选择要进行的操作： " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "        1.登录         " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "     2.新用户注册      " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout <<"-------------------------" << endl << endl << endl ;
    cout << "____________________________________________________________________" << endl ;
    cout << "                     ";
    cout << "    2018.5.3 By XHSF      " << endl << endl << endl<< endl;
}

/*首页登录框*/
void LogPrintHomePage(){
    char TITLE[20] = "    登陆界面";
    Page_Head(TITLE);
}

/*新用户注册页面*/
void RegisterPage(){
    char TITLE[20] = "    注册页面";
    Page_Head(TITLE);
}

/*主页*/
void PrintIndexPage(){
    char TITLE[20] = "      主页";
    Page_Head(TITLE);
    cout << "                     ";
    cout << "-------------------------" << endl;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "    Welcome to 主页    " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "  请选择要进行的操作： " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "      1.物品搜索       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "      2.物品清单       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "    3.拍卖行大数据     " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "   4.进入管理员页面    " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "    5.进入我的页面     " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "-------------------------" << endl << endl << endl;
    cout << "____________________________________________________________________" << endl ;
    cout << "                     ";
    cout << "    2018.5.3 By XHSF      " << endl << endl << endl<< endl;
}

/*打印物品搜索页*/
void PrintIndex_SearchPage(){
    char TITLE[20] = "    物品搜索";
    Page_Head(TITLE);
    cout << "                     ";
    cout << "-------------------------" << endl;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "  Welcome to 搜索页面  " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "   请选择搜索的类型：  " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "       1.编号搜索      " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "       2.类别搜索      " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "     3.物品名称搜索    " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "       4.返回主页      " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "-------------------------" << endl << endl << endl;
    cout << "____________________________________________________________________" << endl ;
    cout << "                     ";
    cout << "    2018.5.3 By XHSF      " << endl << endl << endl<< endl;
}

/*打印物品清单页面*/
void PrintIndex_ItemsPage(){
    char TITLE[20] = "    物品清单";
    Page_Head(TITLE);
}

/*打印拍卖行大数据页面*/
void PrintIndex_BigDataPage(){
    char TITLE[20] = "   拍卖行大数据";
    Page_Head(TITLE);
}

/*打印我的页面*/
void PrintMyPage(){
    char TITLE[20] = "     我的页面";
    Page_Head(TITLE);
    cout << "                     ";
    cout << "-------------------------" << endl;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "  Welcome to 我的页面  " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "  请选择要进行的操作： " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "      1.修改密码       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "      2.我的竞拍       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "      3.退出登录       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "      4.返回主页       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "-------------------------" << endl << endl << endl;
    cout << "____________________________________________________________________" << endl ;
    cout << "                     ";
    cout << "    2018.5.3 By XHSF      " << endl << endl << endl<< endl;
}

/*打印我的竞拍页面*/
void PrintMyAuctions(auctionItems Items,User UserItem){
    char TITLE[20] = "     我的竞拍";
    Page_Head(TITLE);
    SearchByTheHighestBidder(Items,UserItem.Nickname);
    cout << endl << "                     ";
    cout << "  按任意键返回我的页面 "<< endl ;
    getch();
}

/*字体、背景初始化*/
void InitBackgroundAndFont(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);//初始化字体
    system("color F8");//初始化背景
}
/*******************************UI操作区************************************/

int main()
{
    /*******************************变量定义区************************************/
    auctionItems Items;//用户表
    auctionItem Item;//用户
    auctionItem PreItem,PostItem;//用户信息修改前后
    User UserItem;//用户
    Users UserItems;//用户表
    char selection;//操作选择
    int FlagIndex = 0;
    /*******************************变量定义区************************************/

    /*******************************初始化区************************************/
    InitBackgroundAndFont();
    CreateUserList(UserItems);
    CreateAuctionList(Items);
    /*******************************初始化区************************************/


//    AddAuctionItem(Item);
//    AddAuctionItemToFile(Item);
//    AddAuctionItem(Item);
//    AddAuctionItemToFile(Item);
//    AddAuctionItem(Item);
//    AddAuctionItemToFile(Item);
//    AddUser(UserItem);
//    AddUserToFile(UserItem);




    /*****************************页面操作区********************************/

    /*************登录页面*************/
    LogPage:
        PrintHomePage(InitPrintHomePage);
        selection = getch();
        if(selection == '1'){
            UserLogPrint(UserItems,UserItem);
        }
        else if(selection == '2'){
            Register(UserItems,UserItem);
        }
    /*************登录页面*************/
    /***************主页***************/
    IndexPage:
        PrintIndexPage();
        if(FlagIndex == 1){
            cout << "                     ";
            cout << " 选择错误，请从新选择操作" << endl ;
        }
        selection = getch();
        switch(selection){
            case '1':
                    FlagIndex = 0;
                    if(SearchPage(Items,Item,UserItem)==1){
                        goto IndexPage;
                    }
                    break;
            case '2':
                    FlagIndex = 0;
                    if(ItemsPage(Items,Item,UserItem)){
                        goto IndexPage;
                    }
                    break;
            case '3':
                    FlagIndex = 0;
                    if(BigDataPage(Items,UserItems,Item)){
                        goto IndexPage;
                    }
                    break;
            case '4':
                    FlagIndex = 0;
                    goto ManagerPage;
                    break;
            case '5':
                    FlagIndex = 0;
                    goto MyPage;
                    break;
            default:
                    FlagIndex = 1;
                    goto IndexPage;
        }
    /***************主页***************/
    /***************管理员页面***************/
    ManagerPage:
    /***************管理员页面***************/
    /***************我的页面***************/
    MyPage:
        PrintMyPage();
        if(FlagIndex == 1){
            cout << "                     ";
            cout << " 选择错误，请从新选择操作" << endl ;
        }
        selection = getch();
        switch(selection){
            case '1':
                    ModifyPasswordPage(UserItems,UserItem);
                    FlagIndex = 0;
                    goto MyPage;
                    break;
            case '2':
                    PrintMyAuctions(Items,UserItem);
                    FlagIndex = 0;
                    goto MyPage;
                    break;
            case '3':
                    FlagIndex = 0;
                    cout << "                     ";
                    cout << "  退出登录中，请等候..." << endl ;
                    Delay(1000);
                    goto LogPage;
                    break;
            case '4':
                    FlagIndex = 0;
                    goto IndexPage;
                    break;
            default:
                    FlagIndex = 1;
                    goto MyPage;
        }
    /***************我的页面***************/

    /*******************************页面操作区************************************/



}
