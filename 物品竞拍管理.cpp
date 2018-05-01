/****************************头文件区*********************************/
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <sstream>
#include <windows.h> //Sleep()函数
using namespace std;
/****************************头文件区*********************************/


/****************************宏定义区*********************************/
#define ERROR 0
#define OK 1
#define ElemType int
typedef struct auctionItem
{
    int Id;//编号
    char Category[20];//类别
    char Name[30];//名称
    int TheHighestPrice;//最高价
    int Evaluation;//估价
//    long int StartingPrice;//起拍价
    char OldAndNew[3];//新旧
    char Description[101];//物品描述
    char State[10];//物品状态 竞拍中，已成交
    char Owner[30];//物主
    struct auctionItem *next;
} auctionItem,*auctionItems;
/****************************宏定义区*********************************/


/****************************全局变量区*******************************/
char Empty[6] = "Empty";
/****************************全局变量区*******************************/


/****************************函数声明区*******************************/
/*比较两个字符串是否相等，相等返回1，不相等返回0*/
int Equal_Str(char str1[],char str2[]);

/*计算字符串长度，返回字符串长度*/
int Len_Str(char str[]);

/*延时函数，参数单位为毫秒*/
void Delay(int seconds);

/*输出提示并输入整形数据*/
void Input_Int(int &variable,char prompt[]);

/*输出提示并输入字符串型数据*/
void Input_Str(char *variable,char prompt[]);

/*整形赋值*/
void Assign_Int(int &variable,int Number);

/*字符串型赋值*/
void Assign_Char(char *variable,char Str[]);

/*返回拍卖品数量*/
int AuctionItemQuantity(auctionItems Items);

/*把物品信息输入文件中*/
void InputAuctionItemToFile();

/*初始化拍卖品链表*/
void CreateList(auctionItems &Items);

/*打印拍卖品*/
int PrintAuctionItem(auctionItem Item);

/*打印拍卖品列表*/
int PrintAuctionItems(auctionItems Items);

/*删除拍卖品中某个物品的数据*/
int DeleteItem(auctionItems Items,int Id,auctionItem &Item);

/*删除物品信息并打印删除结果*/
void DeleteItemAndPrint(auctionItems &Items,int Id,auctionItem &Item);

/*修改某个拍卖品的信息*/
int ModifyItem(auctionItems &Items,int Id,auctionItem &PreItem,auctionItem &PostItem);

/*修改某个拍卖品的信息并打印*/
int ModifyItemAndPrint(auctionItems &Items,int Id,auctionItem &PreItem,auctionItem &PostItem);

/*通过Id寻找物品，找不到返回0，找到返回1*/
int SearchById(auctionItems Items,int Id,auctionItem &Item);

/*通过Name寻找物品，找不到返回0，找到返回1*/
int SearchByName(auctionItems Items,char Name[],auctionItem &Item);

/*通过Category寻找物品，找不到返回0，找到返回找到的个数*/
int SearchByCategory(auctionItems Items,char Category[]);

/*通过State寻找物品，找不到返回0，找到返回找到的个数*/
int SearchByState(auctionItems Items,char State[]);

/*通过Owner寻找物品，找不到返回0，找到返回找到的个数*/
int SearchByOwner(auctionItems Items,char Owner[]);

/*返回当前拍卖行中拍卖品的最高拍卖价格*/
int TheHighestPriceInAuctionHouse(auctionItems Items,auctionItem &Item);

/*返回当前拍卖行中拍卖品的最低拍卖价格*/
int TheLowestPriceInAuctionHouse(auctionItems Items,auctionItem &Item);

/*返回当前拍卖行中拍卖品的总成交额*/
int TurnoverInAuctionHouse(auctionItems Items);

/*返回当前拍卖行中拍卖品的总成交数or正在拍卖数*/
int TurnoverNumberInAuctionHouse(auctionItems Items,char State[]);
/****************************函数声明区*******************************/


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
void Input_Int(int &variable,char prompt[]){
    if(Equal_Str(prompt,Empty)){
        scanf("%d",&variable);
    }
    else{
        printf("%s",prompt);
        scanf("%d",&variable);
    }
}

/*输出提示并输入字符串型数据*/
void Input_Str(char *variable,char prompt[]){
    if(Equal_Str(prompt,Empty)){
        scanf("%s",variable);
    }
    else{
        printf("%s",prompt);
        scanf("%s",variable);
    }
}

/*整形赋值*/
void Assign_Int(int &variable,int Number){
    variable = Number;
}

/*字符串型赋值*/
void Assign_Char(char *variable,char Str[]){
    strcpy(variable,Str);
}

/*打印操作提示*/
void OperationPrompt(){
}
/****************************通用函数区*******************************/


/****************************链表操作区*******************************/

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
void InputAuctionItemToFile(auctionItem &Item){
    char a1[30] = "请输入物品编号:";
    char a2[30] = "请输入物品类别:";
    char a3[30] = "请输入物品名称:";
    char a4[30] = "请输入物品价格:";
    char a5[30] = "请输入物品估价:";
    char a6[30] = "请输入物品新旧:";
    char a7[30] = "请输入物品描述:";
    char a8[30] = "请输入物品状态:";
    char a9[30] = "请输入物品所有者:";
    FILE *fp;
    fp=fopen("auctionItems_dataBase.txt","a+");
    Input_Int(Item.Id,a1);
    Input_Str(Item.Category,a2);
    Input_Str(Item.Name,a3);
    Input_Int(Item.TheHighestPrice,a4);
    Input_Int(Item.Evaluation,a5);
    Input_Str(Item.OldAndNew,a6);
    Input_Str(Item.Description,a7);
    Input_Str(Item.State,a8);
    Input_Str(Item.Owner,a9);
    fwrite(&Item,sizeof(auctionItem),1,fp);
    fclose(fp);
}

/*初始化拍卖品链表*/
void CreateList(auctionItems &Items){
    FILE *fp;
    fp=fopen("auctionItems_dataBase.txt","rb");
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
        Assign_Int(PointerBridge -> TheHighestPrice,temp.TheHighestPrice);
        Assign_Int(PointerBridge -> Evaluation,temp.Evaluation);
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
    cout << "------------------------" << endl;
    cout << Item.Id << endl;
    cout << Item.Category << endl;
    cout << Item.Name << endl;
    cout << Item.TheHighestPrice << endl;
    cout << Item.Evaluation << endl;
    cout << Item.OldAndNew << endl;
    cout << Item.Description << endl;
    cout << Item.State << endl;
    cout << Item.Owner << endl;
    cout << "------------------------" << endl;
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
int DeleteItem(auctionItems Items,int Id,auctionItem &Item){
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
void DeleteItemAndPrint(auctionItems &Items,int Id,auctionItem &Item){
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
        CreateList(Items);
        cout << "-----------删除后文件列表-----------" << endl;
        PrintAuctionItems(Items);
        cout << "-----------删除的物品信息-----------" << endl;
        PrintAuctionItem(Item);
//        return 1;
    }
}

/*修改某个拍卖品的信息，如果成功修改返回1，找不到要修改的物品返回0*/
int ModifyItem(auctionItems &Items,int Id,auctionItem &PreItem,auctionItem &PostItem){
    if(DeleteItem(Items,Id,PreItem) == -2){//删除原物品信息
        cout << "----------------找不到要修改的物品-----------------" << endl;
        return 0;
    }
    InputAuctionItemToFile(PostItem);//输入修改后的信息
    CreateList(Items);//重新初始化链表
    return 1;
}

/*修改某个拍卖品的信息并打印，如果成功修改返回1，修改失败返回0*/
int ModifyItemAndPrint(auctionItems &Items,int Id,auctionItem &PreItem,auctionItem &PostItem){
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
int SearchById(auctionItems Items,int Id,auctionItem &Item){
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
int TheHighestPriceInAuctionHouse(auctionItems Items,auctionItem &Item){
    long int HighestPrice = 0;
    while(Items -> next != NULL){
        Items = Items -> next;
        if(Items -> TheHighestPrice >= HighestPrice && Equal_Str(Items -> State,"已成交")){
            HighestPrice = Items -> TheHighestPrice;
            Item = *Items;
        }
    }
    return HighestPrice;
}

/*返回当前拍卖行中拍卖品的最低拍卖价格*/
int TheLowestPriceInAuctionHouse(auctionItems Items,auctionItem &Item){
    long int LowestPrice = 0;
    while(Items -> next != NULL){
        Items = Items -> next;
        if(Items -> TheHighestPrice <= LowestPrice && Equal_Str(Items -> State,"已成交")){
            LowestPrice = Items -> TheHighestPrice;
            Item = *Items;
        }
    }
    return LowestPrice;
}

/*返回当前拍卖行中拍卖品的总成交额*/
int TurnoverInAuctionHouse(auctionItems Items){
    long int Turnover = 0;
    while(Items -> next != NULL){
        Items = Items -> next;
        if(Equal_Str(Items -> State,"已成交")) Turnover += (Items -> TheHighestPrice);
    }
    return Turnover;
}

/*返回当前拍卖行中拍卖品的总成交数or正在拍卖数*/
int TurnoverNumberInAuctionHouse(auctionItems Items,char State[]){
    long int TurnoverNumber = 0;
    while(Items -> next != NULL){
        Items = Items -> next;
        if(Equal_Str(Items -> State,State)) TurnoverNumber++;
    }
    return TurnoverNumber;
}


/****************************链表操作区*******************************/



int main()
{
    int Selector;
    auctionItems Items;
    auctionItem Item,PreItem,PostItem;

//    InputAuctionItemToFile(Item);
//    InputAuctionItemToFile(Item);
//    InputAuctionItemToFile(Item);
//    InputAuctionItemToFile(Item);
//    InputAuctionItemToFile(Item);
//    InputAuctionItemToFile(Item);



    CreateList(Items);
    cout << "--------------当前列表信息-------------" << endl;
    if(!PrintAuctionItems(Items)){
        cout << "当前无拍卖中的物品" << endl;
     }
//    DeleteItemAndPrint(Items,1,Item);
    cout << "--------------当前拍卖品数量------------" <<endl;
    cout << AuctionItemQuantity(Items) << endl;
//    ModifyItemAndPrint(Items,0,PreItem,PostItem);
    SearchById(Items,2,Item);
    PrintAuctionItem(Item);
    SearchByName(Items,"吉他",Item);
    PrintAuctionItem(Item);
    SearchByCategory(Items,"乐器");
    SearchByOwner(Items,"小花");
    cout << "----------最低最高价格--------------" << endl;
    TheHighestPriceInAuctionHouse(Items,Item);
    PrintAuctionItem(Item);
    TheLowestPriceInAuctionHouse(Items,Item);
    PrintAuctionItem(Item);
    cout << TurnoverNumberInAuctionHouse(Items,"已成交") << endl;
    SearchByState(Items,"拍卖中");
}
