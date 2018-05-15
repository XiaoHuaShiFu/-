/****************************ͷ�ļ���*********************************/
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <sstream>
#include <conio.h>
#include <windows.h> //Sleep()����,������ɫ
using namespace std;
/****************************ͷ�ļ���*********************************/


/****************************�궨����*********************************/
#define ERROR 0
#define OK 1
#define ElemType int
typedef struct auctionItem{
    long Id;//���
    char Category[20];//���
    char Name[30];//����
    char BiddingMode[5];//���ĺͰ���
    long TheHighestPrice;//��߼�
    char TheHighestBidder[30];//��߳�����
    long Evaluation;//����
    long StartingPrice;//���ļ�
    char OldAndNew[3];//�¾�
    char Description[101];//��Ʒ����
    char State[10];//��Ʒ״̬ �����У��ѳɽ�
    char Owner[30];//����
    struct auctionItem *next;
} auctionItem,*auctionItems;
typedef struct User{
    char Account[30];
    char Password[20];
    char Nickname[20];
    struct User *next;
}User,*Users;
/****************************�궨����*********************************/


/****************************ȫ�ֱ�����*******************************/
char Empty[6] = "Empty";
char a1[30] = "��������Ʒ���:";
char a2[30] = "��������Ʒ���:";
char a3[30] = "��������Ʒ����:";
char a4[30] = "��������Ʒ�۸�:";
char a5[30] = "��������Ʒ����:";
char a6[30] = "��������Ʒ�¾�:";
char a7[30] = "��������Ʒ����:";
char a8[30] = "��������Ʒ״̬:";
char a9[30] = "��������Ʒ������:";
char a10[30] = "��������Ʒ���ļ�:";
char a11[30] = "��������Ʒ����ģʽ:";
char b1[30] = "�������˺�:";
char b2[30] = "�������ǳ�:";
char b3[30] = "����������:";
char b4[30] = "���ٴ���������:";
char b5[30] = "������������:";
char b6[30] = "���ٴ�����������:";
char Traded[7] = "�ѳɽ�";
char Auctioning[7] = "������";
char Not[3] = "��";
char Auctioneer[13] = "�����й���Ա";
/****************************ȫ�ֱ�����*******************************/


/**************************ͨ�ú���������*****************************/
/*�Ƚ������ַ����Ƿ���ȣ���ȷ���1������ȷ���0*/
int Equal_Str(char str1[],char str2[]);

/*�����ַ������ȣ������ַ�������*/
int Len_Str(char str[]);

/*��ʱ������������λΪ����*/
void Delay(int seconds);

/*�����ʾ��������������*/
void Input_Int(long &Int,char prompt[]);

/*�����ʾ�������ַ���������*/
void Input_Str(char *Char,char prompt[]);

/*�����ʾ����������,�ɹ�¼�뷵��1��ʧ�ܷ���0*/
int Input_Password(char *Password,char prompt1[],char prompt2[]);

/*���θ�ֵ*/
void Assign_Int(long &Int,long Number);

/*�ַ����͸�ֵ*/
void Assign_Char(char *Char,char Str[]);

/*�����Ļ*/
void ClearScreen();
/**************************ͨ�ú���������*****************************/


/**************************��Ʒ����������*****************************/
/*��������Ʒ����*/
int AuctionItemQuantity(auctionItems Items);

/*����Ʒ��Ϣ�����ļ���*/
void AddAuctionItemToFile();

/*�����Ʒ��Ϣ*/
void AddAuctionItem(auctionItem &Item);

/*��ʼ������Ʒ����*/
void CreateAuctionList(auctionItems &Items);

/*��ӡ����Ʒ*/
int PrintAuctionItem(auctionItem Item);

/*��ӡ����Ʒ�б�*/
int PrintAuctionItems(auctionItems Items);

/*ɾ������Ʒ��ĳ����Ʒ������*/
int DeleteItem(auctionItems Items,long Id,auctionItem &Item);

/*ɾ����Ʒ��Ϣ����ӡɾ�����*/
void DeleteItemAndPrint(auctionItems &Items,long Id,auctionItem &Item);

/*�޸�ĳ������Ʒ����Ϣ*/
int ModifyItem(auctionItems &Items,long Id,auctionItem &PreItem,auctionItem &PostItem);

/*�޸�ĳ������Ʒ����Ϣ����ӡ*/
int ModifyItemAndPrint(auctionItems &Items,long Id,auctionItem &PreItem,auctionItem &PostItem);

/*ͨ��IdѰ����Ʒ���Ҳ�������0���ҵ�����1*/
int SearchById(auctionItems Items,long Id,auctionItem &Item);

/*ͨ��NameѰ����Ʒ���Ҳ�������0���ҵ�����1*/
int SearchByName(auctionItems Items,char Name[],auctionItem &Item);

/*ͨ��CategoryѰ����Ʒ���Ҳ�������0���ҵ������ҵ��ĸ���*/
int SearchByCategory(auctionItems Items,char Category[]);

/*ͨ��StateѰ����Ʒ���Ҳ�������0���ҵ������ҵ��ĸ���*/
int SearchByState(auctionItems Items,char State[]);

/*ͨ��TheHighestBidderѰ����Ʒ���Ҳ�������0���ҵ������ҵ��ĸ���*/
int SearchByTheHighestBidder(auctionItems Items,char TheHighestBidder[]);

/*ͨ��OwnerѰ����Ʒ���Ҳ�������0���ҵ������ҵ��ĸ���*/
int SearchByOwner(auctionItems Items,char Owner[]);

/*���ص�ǰ������������Ʒ����������۸�*/
long TheHighestPriceInAuctionHouse(auctionItems Items,auctionItem &Item);

/*���ص�ǰ������������Ʒ����������۸�*/
long TheLowestPriceInAuctionHouse(auctionItems Items,auctionItem &Item);

/*���ص�ǰ������������Ʒ���ܳɽ���*/
long TurnoverInAuctionHouse(auctionItems Items);

/*���ص�ǰ������������Ʒ���ܳɽ���or����������*/
int TurnoverNumberInAuctionHouse(auctionItems Items,char State[]);

/*��ʼ�������ɹ�����1��ʧ�ܷ���0*/
int  StartAuction(auctionItem &Item);

/*��Ʒ����ҳ��*/
int SearchPage(auctionItems &Items,auctionItem &Item,User UserItem);

/*��Ʒ�嵥ҳ��*/
int ItemsPage(auctionItems &Items,auctionItem &Item,User UserItem);

/*�û�����*/
int UserBid(auctionItems &Items,auctionItem &Item,User UserItem);

/*�����д�����ҳ��*/
int BigDataPage(auctionItems Items,Users UserItems,auctionItem Item);

/**************************��Ʒ����������*****************************/


/**************************�û�����������*****************************/
/*���ļ�����û���Ϣ*/
void AddUserToFile(User &UserItem);

/*����û���Ϣ*/
void AddUser(User &UserItem);

/*���û�ע��*/
void Register(Users UserItems,User UserItem);

/*ɾ���û���Ϣ*/
int DeleteUser(Users UserItems,char *UserAccount,User &UserItem);

/*ɾ���û���Ϣ�����´�������*/
int DeleteUserAndCreateList(Users &UserItems,char *UserAccount,User &UserItem);

/*��ʼ���û�����*/
void CreateUserList(Users &UserItems);

/*ͨ��AccountѰ���û����Ҳ�������0���ҵ�����1*/
int SearchByAccount(Users UserItems,char Account[],User &UserItem);

/*ͨ��NicknameѰ���û����Ҳ�������0���ҵ�����1*/
int SearchByNickname(Users UserItems,char Nickname[],User &UserItem);

/*�û���¼���ɹ�����1��������󷵻�-1���˺Ų����ڷ���0*/
int UserLog(Users UserItems,User &UserItem);

/*�û���¼����ӡUIҳ��,�ɹ�����1��ʧ�ܷ���0*/
int UserLogPrint(Users UserItems,User &UserItem);

/*��ӡ�û���Ϣ*/
void PrintUser(User UserItem);

/*��ӡ�û���Ϣ�б�*/
int PrintUsers(Users UserItems);

/*���ص�ǰ�������е��û���*/
int UserNumberInAuctionHouse(Users UserItems);

/*�޸����뺯��*/
int ModifyUserPassword(Users &UserItems,char *Account,char *Password);

/*�޸�����ҳ��*/
int ModifyPasswordPage(Users &UserItems,User &UserItem);
/**************************�û�����������*****************************/


/*****************************UI������********************************/
/*��ӡҳ��ͷ*/
void Page_Head(char *Title);

/*��ҳѡ�*/
void InitPrintHomePage();

/*��ҳ��ӡ*/
void PrintHomePage(void (*Selection)());

/*��ҳ��¼��*/
void LogPrintHomePage();

/*���û�ע��ҳ��*/
void RegisterPage();

/*��ҳ*/
void PrintIndexPage();

/*��ҳ��Ʒ����ҳ*/
void PrintIndex_SearchPage();

/*��Ʒ�嵥ҳ��*/
void PrintIndex_ItemsPage();

/*��ӡ�����д�����ҳ��*/
void PrintIndex_BigDataPage();

/*��ӡ�ҵ�ҳ��*/
void PrintMyPage();

/*��ӡ�ҵľ���ҳ��*/
void PrintMyAuctions(auctionItems Items,User UserItem);

/*���塢������ʼ��*/
void InitBackgroundAndFont();
/*****************************UI������********************************/


/****************************ͨ�ú�����*******************************/
/*�Ƚ������ַ����Ƿ���ȣ���ȷ���1������ȷ���0*/
int Equal_Str(char str1[],char str2[]){
    if(strcmp(str1,str2) == 0) return 1;
    return 0;
}

/*�����ַ������ȣ������ַ�������*/
int Len_Str(char str[]){
    return strlen(str);
}

/*��ʱ������������λΪ����*/
void Delay(int seconds){
    Sleep(seconds);
}

/*�����ʾ��������������*/
void Input_Int(long &Int,char prompt[]){
    if(Equal_Str(prompt,Empty)){
        scanf("%ld",&Int);
    }
    else{
        cout << prompt;
        scanf("%ld",&Int);
    }
}

/*�����ʾ�������ַ���������*/
void Input_Str(char *Char,char prompt[]){
    if(Equal_Str(prompt,Empty)){
        scanf("%s",Char);
    }
    else{
        cout << prompt;
        scanf("%s",Char);
    }
}

/*�����ʾ����������,�ɹ�¼�뷵��1��ʧ�ܷ���0*/
//���ɾ��backspaceɾ����Ļ��ʾ��һ�����Ƿ���δ���
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

/*���θ�ֵ*/
void Assign_Int(long &Int,long Number){
    Int = Number;
}

/*�ַ����͸�ֵ*/
void Assign_Char(char *Char,char *Str){
    strcpy(Char,Str);
}

/*�����Ļ*/
void ClearScreen(){
    system("cls");
}
/****************************ͨ�ú�����*******************************/


/****************************����Ʒ���������*******************************/

/*��������Ʒ����*/
int AuctionItemQuantity(auctionItems Items){
    int Quantity = 0;
    while(Items -> next){
        Items = Items -> next;
        Quantity++;
    }
    return Quantity;
}

/*����Ʒ��Ϣ�����ļ���*/
void AddAuctionItemToFile(auctionItem &Item){
    FILE *fp;
    fp=fopen("auctionItems_DataBase.txt","a+");
    fwrite(&Item,sizeof(auctionItem),1,fp);
    fclose(fp);
}

/*�����Ʒ��Ϣ*/
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

/*��ʼ������Ʒ����*/
void CreateAuctionList(auctionItems &Items){
    FILE *fp;
    fp = fopen("auctionItems_DataBase.txt","rb");
    auctionItems Pointer,PointerBridge ;//headָ��Ϊ�����ͷ��㣬���ҵ������Ψһ���ݣ����headָ�붪ʧ����ô����������Ҳ�����;pָ������ָ��������Ľ��;qָ������ָ��β�ڵ�
    auctionItem temp;//����ṹ�����
    Items = (auctionItems)malloc(sizeof(auctionItem));
    Items->next = NULL;
    Pointer = (auctionItems)malloc(sizeof(auctionItem));  // pָ���¿��ٵĽڵ��ڴ�
    Pointer = Items;    //����ͷ����ڴ�      ͷ�����û��ѧ���ɼ���Ϣ
    while(fread(&temp,sizeof(auctionItem),1,fp)!=0){//���ļ��ж��ṹ���
        PointerBridge = (auctionItems)malloc(sizeof(auctionItem)); // pָ���¿��ٵĽڵ��ڴ�
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

/*��ӡ����Ʒ������1*/
int PrintAuctionItem(auctionItem Item){
    cout << "                     ";
    cout << "-------------------------" << endl;
    cout << "                     ";
    cout << "------��Ʒ��Ϣ����-------" << endl ;
    cout << "                     ";
    cout << " ��ţ�" << Item.Id << endl ;
    cout << "                     ";
    cout << " ���ͣ�" << Item.Category << endl ;
    cout << "                     ";
    cout << " ���ƣ�" << Item.Name << endl ;
    cout << "                     ";
    cout << " ������ʽ��" << Item.BiddingMode << endl ;
    cout << "                     ";
    cout << " ��߼ۣ�" << Item.TheHighestPrice << endl ;
    cout << "                     ";
    cout << " ��߳����ߣ�" << Item.TheHighestBidder << endl ;
    cout << "                     ";
    cout << " ���ۣ�" << Item.Evaluation << endl ;
    cout << "                     ";
    cout << " ���ļۣ�" << Item.StartingPrice << endl ;
    cout << "                     ";
    cout << " �¾ɣ�" << Item.OldAndNew << endl ;
    cout << "                     ";
    cout << " ������" << Item.Description << endl ;
    cout << "                     ";
    cout << " ״̬��" << Item.State << endl ;
    cout << "                     ";
    cout << " ӵ���ߣ�" << Item.Owner << endl ;
    cout << "                     ";
    cout << "---From Auction By XHSF--" << endl ;
    cout << "                     ";
    cout << "-------------------------" << endl;
    return 1;
}

/*��ӡ����Ʒ�б��ձ���0����ӡ�ɹ�����1*/
int PrintAuctionItems(auctionItems Items){
    if(Items->next == NULL) return 0;
    while(Items->next != NULL){
        Items = Items->next;
        PrintAuctionItem(*Items);
    }
    return 1;
}

/*ɾ������Ʒ��ĳ����Ʒ�����ݣ�ԭ�ļ�Ϊ�շ���-2��
�Ҳ���Ҫɾ������Ʒ����-1���ļ���ʧ�ܷ���0���޸ĳɹ�����1*/
int DeleteItem(auctionItems Items,long Id,auctionItem &Item){
    int Flag = 0;
    FILE *Prototype,*Temporary;
    Prototype = fopen("auctionItems_DataBase.txt","rb");
    Temporary = fopen("auctionItems_DataBase_Temporary.txt","a+");
    if(Prototype == NULL || Temporary == NULL){
        fclose(Prototype);
        fclose(Temporary);
        return 0; //�ų����ļ�ʧ��
    }
    if(Items->next == NULL){
        fclose(Prototype);
        fclose(Temporary);
        return -2;//�ų�ԭ����Ϊ��
    }
    while(Items->next != NULL){
        Items = Items->next;
        if(Items -> Id != Id) fwrite(&*Items,sizeof(auctionItem),1,Temporary);//�Ѳ���Ҫɾ���Ľڵ�д����ʱ�ļ�
        else{
            Item = *Items;//����Ҫɾ���ڵ����Ϣ
            Flag = 1;
        }
    }
    fclose(Prototype);
    fclose(Temporary);
    remove("auctionItems_DataBase.txt");//ɾ��ԭ�ļ�
    rename("auctionItems_DataBase_Temporary.txt","auctionItems_DataBase.txt");//����ʱ�ļ�����Ϊԭ�ļ���
    if(Flag == 0) return -1; //���û���ҵ���Ҫ�ı�� �򷵻�1
    return 1;//�ҵ��򷵻�1
}

/*ɾ����Ʒ��Ϣ����ӡɾ�������ɾ��ʧ�ܷ���0��ɾ���ɹ�����1*/
void DeleteItemAndPrint(auctionItems &Items,long Id,auctionItem &Item){
    int ReturnValue = DeleteItem(Items,Id,Item);
    if(ReturnValue == -2){
        cout << "ԭ�ļ�Ϊ��" << endl;
//        return 0;
    }
    else if(ReturnValue == -1){
        cout << "�Ҳ������Ϊ" << Id << "����Ʒ" << endl;
//        return 0;
    }
    else if(ReturnValue == 0){
        cout << "�ļ���ʧ��" << endl;
//        return 0;
    }
    else{
        CreateAuctionList(Items);
        cout << "-----------ɾ�����ļ��б�-----------" << endl;
        PrintAuctionItems(Items);
        cout << "-----------ɾ������Ʒ��Ϣ-----------" << endl;
        PrintAuctionItem(Item);
//        return 1;
    }
}

/*�޸�ĳ������Ʒ����Ϣ������ɹ��޸ķ���1���Ҳ���Ҫ�޸ĵ���Ʒ����0*/
int ModifyItem(auctionItems &Items,long Id,auctionItem &PreItem,auctionItem &PostItem){
    if(DeleteItem(Items,Id,PreItem) == -2){//ɾ��ԭ��Ʒ��Ϣ
        cout << "----------------�Ҳ���Ҫ�޸ĵ���Ʒ-----------------" << endl;
        return 0;
    }
    AddAuctionItemToFile(PostItem);//�����޸ĺ����Ϣ
    CreateAuctionList(Items);//���³�ʼ������
    return 1;
}

/*�޸�ĳ������Ʒ����Ϣ����ӡ������ɹ��޸ķ���1���޸�ʧ�ܷ���0*/
int ModifyItemAndPrint(auctionItems &Items,long Id,auctionItem &PreItem,auctionItem &PostItem){
    if(ModifyItem(Items,4,PreItem,PostItem)){
        cout << "-------------��ӡ�޸�ǰ��Ʒ����Ϣ---------------" <<endl;
        PrintAuctionItem(PreItem);
        cout << "-------------��ӡ�޸ĺ���Ʒ����Ϣ---------------" <<endl;
        PrintAuctionItem(PostItem);
        return 1;
    }
    return 0;
}

/*ͨ��IdѰ����Ʒ���Ҳ�������0���ҵ�����1*/
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

/*ͨ��NameѰ����Ʒ���Ҳ�������0���ҵ�����1*/
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

/*ͨ��CategoryѰ����Ʒ���Ҳ�������0���ҵ������ҵ��ĸ���*/
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

/*ͨ��StateѰ����Ʒ���Ҳ�������0���ҵ������ҵ��ĸ���*/
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

/*ͨ��TheHighestBidderѰ����Ʒ���Ҳ�������0���ҵ������ҵ��ĸ���*/
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

/*ͨ��OwnerѰ����Ʒ���Ҳ�������0���ҵ������ҵ��ĸ���*/
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

/*���ص�ǰ������������Ʒ����������۸�*/
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

/*���ص�ǰ������������Ʒ����������۸�*/
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

/*���ص�ǰ������������Ʒ���ܳɽ���*/
long TurnoverInAuctionHouse(auctionItems Items){
    long Turnover = 0;
    while(Items -> next != NULL){
        Items = Items -> next;
        if(Equal_Str(Items -> State,Traded)) Turnover += (Items -> TheHighestPrice);
    }
    return Turnover;
}

/*���ص�ǰ������������Ʒ���ܳɽ���or����������*/
int TurnoverNumberInAuctionHouse(auctionItems Items,char State[]){
    long TurnoverNumber = 0;
    while(Items -> next != NULL){
        Items = Items -> next;
        if(Equal_Str(Items -> State,State)) TurnoverNumber++;
    }
    return TurnoverNumber;
}

/*��ʼ�������ɹ�����1��ʧ�ܷ���0*/
int  StartAuction(auctionItems &Items,auctionItem &Item){
    if(Item.TheHighestPrice >= Item.StartingPrice){
        DeleteItem(Items,Item.Id,Item);
        Assign_Char(Item.Owner,Item.TheHighestBidder);
        Assign_Char(Item.State,Traded);
        FILE *fp;
        fp=fopen("auctionItems_DataBase.txt","a+");
        fwrite(&Item,sizeof(auctionItem),1,fp);
        fclose(fp);
        CreateAuctionList(Items);//���³�ʼ������
        return 1;//�����ɹ�����1
    }
    else{
        return 0;//����ʧ��
    }
}

/*�û����ģ����۳ɹ�����1��ʧ�ܷ���0*/
int UserBid(auctionItems &Items,auctionItem &Item,User UserItem){
    long Price;
    cout << endl << endl << "                     ";
    cout << "------��Ʒ��Ϣ����-------" << endl ;
    cout << "                     ";
    cout << " ��ǰ��Ʒ��߼ۣ�" << Item.TheHighestPrice << endl;
    cout << "                     ";
    cout << " ��ǰ��Ʒ���ļۣ�" << Item.StartingPrice << endl;
    cout << "                     ";
    cout << " ��ǰ��Ʒ���ۣ�" << Item.Evaluation << endl;
    cout << "                     ";
    cout << " ���������ĳ��ۣ�";
    scanf("%ld",&Price);
    if(Price > Item.TheHighestPrice && Price > Item.StartingPrice){
        DeleteItem(Items,Item.Id,Item);
        Assign_Char(Item.TheHighestBidder,UserItem.Nickname);
        Assign_Int(Item.TheHighestPrice,Price);
        FILE *fp;
        fp=fopen("auctionItems_DataBase.txt","a+");
        fwrite(&Item,sizeof(auctionItem),1,fp);
        fclose(fp);
        CreateAuctionList(Items);//���³�ʼ������
        return 1;//���۳ɹ�����1
    }
    else{
        return 0;//
    }
}

/*��Ʒ����ҳ��*/
int SearchPage(auctionItems &Items,auctionItem &Item,User UserItem){
    PrintIndex_SearchPage();
    char Selection;
    Selection = getch();
    char TITLE[20] = "    ��Ʒ����";
    int Id;
    char Name[30],Category[20];
    switch(Selection){
        case '1':
                Page_Head(TITLE);
                cout << "                     ";
                cout << "   ��������Ʒ��ţ�";
                scanf("%ld",&Id);
                if(SearchById(Items,Id,Item)){
                    PrintAuctionItem(Item);
                    cout << "                     ";
                    cout <<"��1���о��ģ���2������ҳ";
                    Selection = getch();
                    switch(Selection){
                        case '1':
                                if(UserBid(Items,Item,UserItem)){
                                    cout << "                     ";
                                    cout <<"���ĳɹ���1��󷵻���ҳ";
                                    Delay(1000);
                                    return 1;
                                }else{
                                    cout << "                     ";
                                    cout <<"����ʧ�ܣ�1��󷵻���ҳ";
                                    Delay(1000);
                                    return 1;
                                }
                                break;
                        case '2':return 1;break;
                    }

                }else{
                    cout << "                     ";
                    cout <<"����ʧ�ܣ�1��󷵻���ҳ";
                    Delay(1000);
                    return 1;
                }
                break;
        case '2':
                Page_Head(TITLE);
                cout << "                     ";
                cout << "   ��������Ʒ���";
                scanf("%s",Category);
                if(SearchByCategory(Items,Category)){
                    cout << "                     ";
                    cout <<"��1���о��ģ���2������ҳ";
                    Selection = getch();
                    switch(Selection){
                        case '1':
                                cout << endl << "                     ";
                                cout << "   ��������Ʒ��ţ�";
                                scanf("%ld",&Id);
                                SearchById(Items,Id,Item);
                                if(UserBid(Items,Item,UserItem)){
                                    cout << "                     ";
                                    cout <<"���ĳɹ���1��󷵻���ҳ";
                                    Delay(1000);
                                    return 1;
                                }else{
                                    cout << "                     ";
                                    cout <<"����ʧ�ܣ�1��󷵻���ҳ";
                                    Delay(1000);
                                    return 1;
                                }
                                break;
                        case '2':return 1;break;
                    }

                }else{
                    cout << "                     ";
                    cout <<"����ʧ�ܣ�1��󷵻���ҳ";
                    Delay(1000);
                    return 1;
                }
                break;
        case '3':
                Page_Head(TITLE);
                cout << "                     ";
                cout << "   ��������Ʒ���ƣ�";
                scanf("%s",Name);
                if(SearchByName(Items,Name,Item)){
                    PrintAuctionItem(Item);
                    cout << "                     ";
                    cout <<"��1���о��ģ���2������ҳ";
                    Selection = getch();
                    switch(Selection){
                        case '1':
                                if(UserBid(Items,Item,UserItem)){
                                    cout << "                     ";
                                    cout <<"���ĳɹ���1��󷵻���ҳ";
                                    Delay(1000);
                                    return 1;
                                }else{
                                    cout << "                     ";
                                    cout <<"����ʧ�ܣ�1��󷵻���ҳ";
                                    Delay(1000);
                                    return 1;
                                }
                                break;
                        case '2':return 1;break;
                    }

                }else{
                    cout << "                     ";
                    cout <<"����ʧ�ܣ�1��󷵻���ҳ";
                    Delay(1000);
                    return 1;
                }
                break;
        case '4':
                return 1;
                break;
    }
}

/*��Ʒ�嵥ҳ��*/
int ItemsPage(auctionItems &Items,auctionItem &Item,User UserItem){
    PrintIndex_ItemsPage();
    PrintAuctionItems(Items);
    char Selection;
    int Id;
    cout << endl << "                     ";
    cout << "  ��ѡ��Ҫ���еĲ�����" << endl << endl;
    cout << "                     ";
    cout << "      1.���о���"    << endl << endl;
    cout << "                     ";
    cout << "      2.������ҳ"    << endl << endl;
    Selection = getch();
    switch(Selection){
        case '1':
                cout << "                     ";
                cout << "   ��������Ʒ��ţ�";
                scanf("%ld",&Id);
                if(SearchById(Items,Id,Item)){
                    if(UserBid(Items,Item,UserItem)){
                        cout << "                     ";
                        cout <<"���ĳɹ���1��󷵻���ҳ";
                        Delay(1000);
                        return 1;
                    }else{
                        cout << "                     ";
                        cout <<"����ʧ�ܣ�1��󷵻���ҳ";
                        Delay(1000);
                        return 1;
                    }
                }else{
                    cout << "                     ";
                    cout <<"��Ʒ�����ڣ�1��󷵻���ҳ";
                    Delay(1000);
                    return 1;
                }
                break;
        case '2':
                return 1;
                break;
    }
}

/*�����д�����ҳ��*/
int BigDataPage(auctionItems Items,Users UserItems,auctionItem Item){
    PrintIndex_BigDataPage();
    char Selection;
    char State1[7] = "�ѳɽ�";
    char State2[7] = "������";
    cout << "                     ";
    cout << "-------------------------" << endl;
    cout << "                     ";
    cout << "                       " << endl ;
    cout << "                     ";
    cout << " Welcome to �����д����� " << endl << endl;
    cout << "                     ";
    cout << "-------------------------" << endl;
    cout << "                     ";
    cout << "��ǰ�������û������ǣ� " << UserNumberInAuctionHouse(UserItems) << endl;
    cout << "                     ";
//    cout << "-------------------------" << endl;
//    cout << "                     ";
//    TheHighestPriceInAuctionHouse(Items,Item);
//    cout << "  ��ǰ��߼۸������Ʒ��"  << endl;
//    cout << "                     ";
//    cout << "*********" << Item.Name <<"**********" << endl;
//    cout << "                     ";
//    cout << "*****�ɽ���Ϊ��" << Item.TheHighestPrice << "*****"<< endl;
//    cout << "                     ";
//    cout << "-------------------------" << endl;
//    cout << "                     ";
//    TheLowestPriceInAuctionHouse(Items,Item);
//    cout << "  ��ǰ��ͼ۸������Ʒ�� " << endl;
//    cout << "                     ";
//    cout << "*********" << Item.Name <<"**********" << endl;
//    cout << "                     ";
//    cout << "*****�ɽ���Ϊ��" << Item.TheHighestPrice << "*****" << endl;
//    cout << "                     ";
    cout << "-------------------------" << endl;
    cout << "                     ";
    cout << "��ǰ����������Ʒ���ǣ�" << TurnoverNumberInAuctionHouse(Items,State1) << endl;
    cout << "                     ";
    cout << "-------------------------" << endl;
    cout << "                     ";
    cout << "��ǰ�����е���Ʒ���ǣ�" << TurnoverNumberInAuctionHouse(Items,State2) << endl;
    cout << "                     ";
    cout << "-------------------------" << endl;
    cout << "                     ";
    cout << "��ǰ�����е��ܽ��׶��ǣ�" << TurnoverInAuctionHouse(Items) << endl;
    cout << "                     ";
    cout << "-------------------------" << endl << endl << endl;
    cout << endl << "                     ";
    cout << "    �������������ҳ     " << endl << endl;
    cout << "____________________________________________________________________" << endl ;
    cout << "                     ";
    cout << "    2018.5.3 By XHSF      " << endl << endl << endl<< endl;
    Selection = getch();
    return 1;
}

/****************************����Ʒ���������*******************************/


/****************************�û����������*********************************/
/*���ļ�����û���Ϣ*/
void AddUserToFile(User &UserItem){
    FILE *fp;
    fp = fopen("Users_DataBase.txt","a+");
    fwrite(&UserItem,sizeof(User),1,fp);
    fclose(fp);
}

/*����û���Ϣ*/
void AddUser(User &UserItem){
    Input_Str(UserItem.Account,b1);
    Input_Str(UserItem.Nickname,b2);
    Input_Password(UserItem.Password,b3,b4);
}

/*���û�ע��*/
void Register(Users UserItems,User UserItem){
    int FlagAccount = 0,FlagPassword = 6,FlagNickname = 4,idx = 0;
    char Password[20],Account[30],Nickname[30],c;
    do{
        RegisterPage();
        if(FlagAccount){
            cout << "                     ";
            cout << "   ���˺��ѱ�ע��    " << endl << endl;
        }
        if(FlagPassword < 6){
            cout << "                     ";
            cout << "����Ӧ���ڵ���6���ַ�" << endl << endl;
        }
        if(FlagNickname < 4){
            cout << "                     ";
            cout << "�ǳ�Ӧ���ڵ���4���ַ�" << endl << endl;
        }
        cout << "                     ";
        cout << "�ǳƣ�" ;
        scanf("%s",Nickname);
        cout<< endl << endl  << "                     ";
        cout << "�˺ţ�" ;
        scanf("%s",Account);
        cout<< endl << endl  << "                     ";
        cout  << "���룺" ;
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
    cout << "ע���У���Ⱥ򡣡��� " << endl ;
    Delay(1000);
}

/*ɾ���û���Ϣ*/
int DeleteUser(Users UserItems,char *UserAccount,User &UserItem){
    int Flag = 0;
    FILE *Prototype,*Temporary;
    Prototype = fopen("Users_DataBase.txt","rb");
    Temporary = fopen("Users_DataBase_Temporary.txt","a+");
    if(Prototype == NULL || Temporary == NULL){
        fclose(Prototype);
        fclose(Temporary);
        return 0; //�ų����ļ�ʧ��
    }
    if(UserItems->next == NULL){
        fclose(Prototype);
        fclose(Temporary);
        return -2;//�ų�ԭ����Ϊ��
    }
    while(UserItems->next != NULL){
        UserItems = UserItems->next;
        if(!Equal_Str(UserItems->Account,UserAccount)) fwrite(&*UserItems,sizeof(User),1,Temporary);//�Ѳ���Ҫɾ���Ľڵ�д����ʱ�ļ�
        else{
            UserItem = *UserItems;//����Ҫɾ���ڵ����Ϣ
            Flag = 1;
        }
    }
    fclose(Prototype);
    fclose(Temporary);
    remove("Users_DataBase.txt");//ɾ��ԭ�ļ�
    rename("Users_DataBase_Temporary.txt","Users_DataBase.txt");//����ʱ�ļ�����Ϊԭ�ļ���
    if(Flag == 0) return -1; //���û���ҵ���Ҫɾ���ı�� �򷵻�1
    return 1;//�ҵ��򷵻�1
}

/*ɾ���û���Ϣ�����´�������*/
int DeleteUserAndCreateList(Users &UserItems,char *UserAccount,User &UserItem){
    int ReturnValue = DeleteUser(UserItems,UserAccount,UserItem);
    CreateUserList(UserItems);
    return ReturnValue;
}

/*��ʼ���û�����*/
void CreateUserList(Users &UserItems){
    FILE *fp;
    fp = fopen("Users_DataBase.txt","rb");
    Users Pointer,PointerBridge ;//headָ��Ϊ�����ͷ��㣬���ҵ������Ψһ���ݣ����headָ�붪ʧ����ô����������Ҳ�����;pָ������ָ��������Ľ��;qָ������ָ��β�ڵ�
    User temp;//����ṹ�����
    UserItems = (Users)malloc(sizeof(User));
    UserItems->next = NULL;
    Pointer = (Users)malloc(sizeof(User));  // pָ���¿��ٵĽڵ��ڴ�
    Pointer = UserItems;    //����ͷ����ڴ�      ͷ�����û��ѧ���ɼ���Ϣ
    while(fread(&temp,sizeof(User),1,fp)!=0){//���ļ��ж��ṹ���
        PointerBridge = (Users)malloc(sizeof(User)); // pָ���¿��ٵĽڵ��ڴ�
        Assign_Char(PointerBridge -> Account,temp.Account);
        Assign_Char(PointerBridge -> Nickname,temp.Nickname);
        Assign_Char(PointerBridge -> Password,temp.Password);
        PointerBridge->next = Pointer -> next;
        Pointer->next = PointerBridge;
        Pointer = PointerBridge;
    }
    fclose(fp);
}

/*ͨ��AccountѰ���û����Ҳ�������0���ҵ�����1*/
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

/*ͨ��NicknameѰ���û����Ҳ�������0���ҵ�����1*/
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

/*���ص�ǰ�������е��û���*/
int UserNumberInAuctionHouse(Users UserItems){
    long UserNumber = 0;
    while(UserItems -> next != NULL){
        UserItems = UserItems -> next;
        UserNumber++;
    }
    return UserNumber;
}

/*��ӡ�û���Ϣ*/
void PrintUser(User UserItem){
    cout << "------------------------" << endl;
    cout << UserItem.Account << endl;
    cout << UserItem.Nickname << endl;
    cout << UserItem.Password << endl;
    cout << "------------------------" << endl;
}

/*��ӡ�û���Ϣ�б�*/
int PrintUsers(Users UserItems){
    if(UserItems->next == NULL) return 0;
    while(UserItems->next != NULL){
        UserItems = UserItems->next;
        PrintUser(*UserItems);
    }
    return 1;
}

/*�û���¼���ɹ�����1��������󷵻�-1���˺Ų����ڷ���0*/
int UserLog(Users UserItems,User &UserItem,char *Account,char *Password){
    if(SearchByAccount(UserItems,Account,UserItem)){
        if(Equal_Str(Password,UserItem.Password)) return 1;//��¼�ɹ�
        else return -1;//�������
    }
    return 0;//�˺Ų�����
}

/*�û���¼����ӡUIҳ��,�ɹ�����1��ʧ�ܷ���0*/
int UserLogPrint(Users UserItems,User &UserItem){
    int FlagLog = 1,idx = 0;
        char Password[20],Account[30],c;
        do{
            LogPrintHomePage();
            if(FlagLog!=1){
                cout << "                        ";
                cout << "������˺Ŵ��������µ�¼" << endl ;
            }
            cout<< endl << endl  << "                     ";
            cout << "�˺ţ�" ;
            scanf("%s",Account);
            cout<< endl << endl  << "                     ";
            cout  << "���룺" ;
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
        cout << "  ��¼�У���ȴ�...  " << endl;
        Delay(500);
}

/*�޸����뺯��*/
int ModifyUserPassword(Users &UserItems,char *Account,char *Password){

    User UserItem;
    DeleteUser(UserItems,Account,UserItem);
    Assign_Char(UserItem.Password,Password);
    FILE *fp;
    fp = fopen("Users_DataBase.txt","a+");
    fwrite(&UserItem,sizeof(User),1,fp);
    CreateUserList(UserItems);//���³�ʼ������
    fclose(fp);
    return 1;
}

/*�޸�����ҳ��*/
int ModifyPasswordPage(Users &UserItems,User &UserItem){
    char TITLE[20] = "    �޸�����";
    char Password[20];
    Page_Head(TITLE);
    int idx = 0;
    char c,FirstInput[20],SecondInput[20];
    cout << "                     ";
    cout << "   ������ԭ���룺" ;
    while((c = getch()) != '\r'){
        FirstInput[idx++] = c;
        cout << '*';
    }
    FirstInput[idx] = '\0';
    idx = 0;
    cout << endl << endl << "                     ";
    cout << "   �����������룺";
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
        cout << "�����޸ĳɹ���1��󷵻��ҵĽ��棺";
        Delay(1000);
        return 1;
    }
    else{
        cout << "                     ";
        cout << "ԭ�����������1��󷵻��ҵĽ��棺";
        Delay(1000);
        return 1;
    }
}

/****************************�û����������*********************************/


/*******************************UI������************************************/
/*��ӡҳ��ͷ*/
void Page_Head(char *Title){
    ClearScreen();
    cout << endl << "                     ";
    cout << "Auction management system" << endl;
    cout << "                         ";
    cout << Title << endl;
    cout << "____________________________________________________________________" << endl << endl << endl<< endl;
}

/*��ҳ��ӡ*/
void PrintHomePage(void (*Selection)()){
    char TITLE[20] = "��Ʒ���Ĺ���ϵͳ";
    Page_Head(TITLE);
    cout << "                     ";
    cout << "-------------------------" << endl;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "Welcome to ���Ĺ���ϵͳ" << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    Selection();
}

/*��ҳѡ�*/
void InitPrintHomePage(){
    cout << "                     ";
    cout << "|" << "  ��ѡ��Ҫ���еĲ����� " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "        1.��¼         " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "     2.���û�ע��      " << "|" << endl ;
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

/*��ҳ��¼��*/
void LogPrintHomePage(){
    char TITLE[20] = "    ��½����";
    Page_Head(TITLE);
}

/*���û�ע��ҳ��*/
void RegisterPage(){
    char TITLE[20] = "    ע��ҳ��";
    Page_Head(TITLE);
}

/*��ҳ*/
void PrintIndexPage(){
    char TITLE[20] = "      ��ҳ";
    Page_Head(TITLE);
    cout << "                     ";
    cout << "-------------------------" << endl;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "    Welcome to ��ҳ    " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "  ��ѡ��Ҫ���еĲ����� " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "      1.��Ʒ����       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "      2.��Ʒ�嵥       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "    3.�����д�����     " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "   4.�������Աҳ��    " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "    5.�����ҵ�ҳ��     " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "-------------------------" << endl << endl << endl;
    cout << "____________________________________________________________________" << endl ;
    cout << "                     ";
    cout << "    2018.5.3 By XHSF      " << endl << endl << endl<< endl;
}

/*��ӡ��Ʒ����ҳ*/
void PrintIndex_SearchPage(){
    char TITLE[20] = "    ��Ʒ����";
    Page_Head(TITLE);
    cout << "                     ";
    cout << "-------------------------" << endl;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "  Welcome to ����ҳ��  " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "   ��ѡ�����������ͣ�  " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "       1.�������      " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "       2.�������      " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "     3.��Ʒ��������    " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "       4.������ҳ      " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "-------------------------" << endl << endl << endl;
    cout << "____________________________________________________________________" << endl ;
    cout << "                     ";
    cout << "    2018.5.3 By XHSF      " << endl << endl << endl<< endl;
}

/*��ӡ��Ʒ�嵥ҳ��*/
void PrintIndex_ItemsPage(){
    char TITLE[20] = "    ��Ʒ�嵥";
    Page_Head(TITLE);
}

/*��ӡ�����д�����ҳ��*/
void PrintIndex_BigDataPage(){
    char TITLE[20] = "   �����д�����";
    Page_Head(TITLE);
}

/*��ӡ�ҵ�ҳ��*/
void PrintMyPage(){
    char TITLE[20] = "     �ҵ�ҳ��";
    Page_Head(TITLE);
    cout << "                     ";
    cout << "-------------------------" << endl;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "  Welcome to �ҵ�ҳ��  " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "  ��ѡ��Ҫ���еĲ����� " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "      1.�޸�����       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "      2.�ҵľ���       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "      3.�˳���¼       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "      4.������ҳ       " << "|" << endl ;
    cout << "                     ";
    cout << "|" << "                       " << "|" << endl ;
    cout << "                     ";
    cout << "-------------------------" << endl << endl << endl;
    cout << "____________________________________________________________________" << endl ;
    cout << "                     ";
    cout << "    2018.5.3 By XHSF      " << endl << endl << endl<< endl;
}

/*��ӡ�ҵľ���ҳ��*/
void PrintMyAuctions(auctionItems Items,User UserItem){
    char TITLE[20] = "     �ҵľ���";
    Page_Head(TITLE);
    SearchByTheHighestBidder(Items,UserItem.Nickname);
    cout << endl << "                     ";
    cout << "  ������������ҵ�ҳ�� "<< endl ;
    getch();
}

/*���塢������ʼ��*/
void InitBackgroundAndFont(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);//��ʼ������
    system("color F8");//��ʼ������
}
/*******************************UI������************************************/

int main()
{
    /*******************************����������************************************/
    auctionItems Items;//�û���
    auctionItem Item;//�û�
    auctionItem PreItem,PostItem;//�û���Ϣ�޸�ǰ��
    User UserItem;//�û�
    Users UserItems;//�û���
    char selection;//����ѡ��
    int FlagIndex = 0;
    /*******************************����������************************************/

    /*******************************��ʼ����************************************/
    InitBackgroundAndFont();
    CreateUserList(UserItems);
    CreateAuctionList(Items);
    /*******************************��ʼ����************************************/


//    AddAuctionItem(Item);
//    AddAuctionItemToFile(Item);
//    AddAuctionItem(Item);
//    AddAuctionItemToFile(Item);
//    AddAuctionItem(Item);
//    AddAuctionItemToFile(Item);
//    AddUser(UserItem);
//    AddUserToFile(UserItem);




    /*****************************ҳ�������********************************/

    /*************��¼ҳ��*************/
    LogPage:
        PrintHomePage(InitPrintHomePage);
        selection = getch();
        if(selection == '1'){
            UserLogPrint(UserItems,UserItem);
        }
        else if(selection == '2'){
            Register(UserItems,UserItem);
        }
    /*************��¼ҳ��*************/
    /***************��ҳ***************/
    IndexPage:
        PrintIndexPage();
        if(FlagIndex == 1){
            cout << "                     ";
            cout << " ѡ����������ѡ�����" << endl ;
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
    /***************��ҳ***************/
    /***************����Աҳ��***************/
    ManagerPage:
    /***************����Աҳ��***************/
    /***************�ҵ�ҳ��***************/
    MyPage:
        PrintMyPage();
        if(FlagIndex == 1){
            cout << "                     ";
            cout << " ѡ����������ѡ�����" << endl ;
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
                    cout << "  �˳���¼�У���Ⱥ�..." << endl ;
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
    /***************�ҵ�ҳ��***************/

    /*******************************ҳ�������************************************/



}
