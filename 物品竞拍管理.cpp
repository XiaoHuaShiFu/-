/****************************ͷ�ļ���*********************************/
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <sstream>
#include <conio.h>
#include <windows.h> //Sleep()����
using namespace std;
/****************************ͷ�ļ���*********************************/


/****************************�궨����*********************************/
#define ERROR 0
#define OK 1
#define ElemType int
typedef struct auctionItem{
    int Id;//���
    char Category[20];//���
    char Name[30];//����
    int TheHighestPrice;//��߼�
    int Evaluation;//����
//    long int StartingPrice;//���ļ�
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
char b1[30] = "�������˺�:";
char b2[30] = "�������ǳ�:";
char b3[30] = "����������:";
char b4[30] = "���ٴ���������:";
char b5[30] = "������������:";
char b6[30] = "���ٴ�����������:";
/****************************ȫ�ֱ�����*******************************/


/****************************����������*******************************/
/*�Ƚ������ַ����Ƿ���ȣ���ȷ���1������ȷ���0*/
int Equal_Str(char str1[],char str2[]);

/*�����ַ������ȣ������ַ�������*/
int Len_Str(char str[]);

/*��ʱ������������λΪ����*/
void Delay(int seconds);

/*�����ʾ��������������*/
void Input_Int(int &variable,char prompt[]);

/*�����ʾ�������ַ���������*/
void Input_Str(char *variable,char prompt[]);


/*�����ʾ����������,�ɹ�¼�뷵��1��ʧ�ܷ���0*/
int Input_Password(char *Password,char prompt1[],char prompt2[]);

/*���θ�ֵ*/
void Assign_Int(int &variable,int Number);

/*�ַ����͸�ֵ*/
void Assign_Char(char *variable,char Str[]);

/*�����Ļ*/
void ClearScreen();

/*��������Ʒ����*/
int AuctionItemQuantity(auctionItems Items);

/*����Ʒ��Ϣ�����ļ���*/
void AddAuctionItemToFile();

/*��ʼ������Ʒ����*/
void CreateAuctionList(auctionItems &Items);

/*��ӡ����Ʒ*/
int PrintAuctionItem(auctionItem Item);

/*��ӡ����Ʒ�б�*/
int PrintAuctionItems(auctionItems Items);

/*ɾ������Ʒ��ĳ����Ʒ������*/
int DeleteItem(auctionItems Items,int Id,auctionItem &Item);

/*ɾ����Ʒ��Ϣ����ӡɾ�����*/
void DeleteItemAndPrint(auctionItems &Items,int Id,auctionItem &Item);

/*�޸�ĳ������Ʒ����Ϣ*/
int ModifyItem(auctionItems &Items,int Id,auctionItem &PreItem,auctionItem &PostItem);

/*�޸�ĳ������Ʒ����Ϣ����ӡ*/
int ModifyItemAndPrint(auctionItems &Items,int Id,auctionItem &PreItem,auctionItem &PostItem);

/*ͨ��IdѰ����Ʒ���Ҳ�������0���ҵ�����1*/
int SearchById(auctionItems Items,int Id,auctionItem &Item);

/*ͨ��NameѰ����Ʒ���Ҳ�������0���ҵ�����1*/
int SearchByName(auctionItems Items,char Name[],auctionItem &Item);

/*ͨ��CategoryѰ����Ʒ���Ҳ�������0���ҵ������ҵ��ĸ���*/
int SearchByCategory(auctionItems Items,char Category[]);

/*ͨ��StateѰ����Ʒ���Ҳ�������0���ҵ������ҵ��ĸ���*/
int SearchByState(auctionItems Items,char State[]);

/*ͨ��OwnerѰ����Ʒ���Ҳ�������0���ҵ������ҵ��ĸ���*/
int SearchByOwner(auctionItems Items,char Owner[]);

/*���ص�ǰ������������Ʒ����������۸�*/
int TheHighestPriceInAuctionHouse(auctionItems Items,auctionItem &Item);

/*���ص�ǰ������������Ʒ����������۸�*/
int TheLowestPriceInAuctionHouse(auctionItems Items,auctionItem &Item);

/*���ص�ǰ������������Ʒ���ܳɽ���*/
int TurnoverInAuctionHouse(auctionItems Items);

/*���ص�ǰ������������Ʒ���ܳɽ���or����������*/
int TurnoverNumberInAuctionHouse(auctionItems Items,char State[]);

/*���ļ�����û���Ϣ*/
void AddUserToFile(User &UserItem);

/*ɾ���û���Ϣ*/
int DeleteUser(Users UserItems,char *UserAccount,User &UserItem);

/*��ʼ���û�����*/
void CreateUserList(Users &UserItems);

/*ͨ��AccountѰ���û����Ҳ�������0���ҵ�����1*/
int SearchByAccount(Users UserItems,char Account[],User &UserItem);

/*�û���¼���ɹ�����1��������󷵻�-1���˺Ų����ڷ���0*/
int UserLog(Users UserItems,User &UserItem);

/*��ӡ�û���Ϣ*/
void PrintUser(User UserItem);

/*��ӡ�û���Ϣ�б�*/
int PrintUsers(Users UserItems);

/*�޸����뺯��*/
int ModifyUserPassword(Users &UserItems,char *Account);
/****************************����������*******************************/


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
void Input_Int(int &Int,char prompt[]){
    if(Equal_Str(prompt,Empty)){
        scanf("%d",&Int);
    }
    else{
        cout << prompt;
        scanf("%d",&Int);
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
        FirstInput[idx++] = c;
        cout << '*';
    }
    cout << endl << prompt2;
    idx = 0;
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
        SecondInput[idx++] = c;
        cout << '*';
    }
    cout << endl;
    if(Equal_Str(FirstInput,SecondInput)){
        Assign_Char(Password,FirstInput);
        return 1;
    }
    else return 0;
}

/*���θ�ֵ*/
void Assign_Int(int &Int,int Number){
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

/*��ӡ����Ʒ������1*/
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
int DeleteItem(auctionItems Items,int Id,auctionItem &Item){
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
void DeleteItemAndPrint(auctionItems &Items,int Id,auctionItem &Item){
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
int ModifyItem(auctionItems &Items,int Id,auctionItem &PreItem,auctionItem &PostItem){
    if(DeleteItem(Items,Id,PreItem) == -2){//ɾ��ԭ��Ʒ��Ϣ
        cout << "----------------�Ҳ���Ҫ�޸ĵ���Ʒ-----------------" << endl;
        return 0;
    }
    AddAuctionItemToFile(PostItem);//�����޸ĺ����Ϣ
    CreateAuctionList(Items);//���³�ʼ������
    return 1;
}

/*�޸�ĳ������Ʒ����Ϣ����ӡ������ɹ��޸ķ���1���޸�ʧ�ܷ���0*/
int ModifyItemAndPrint(auctionItems &Items,int Id,auctionItem &PreItem,auctionItem &PostItem){
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
int TheHighestPriceInAuctionHouse(auctionItems Items,auctionItem &Item){
    long int HighestPrice = 0;
    while(Items -> next != NULL){
        Items = Items -> next;
        if(Items -> TheHighestPrice >= HighestPrice && Equal_Str(Items -> State,"�ѳɽ�")){
            HighestPrice = Items -> TheHighestPrice;
            Item = *Items;
        }
    }
    return HighestPrice;
}

/*���ص�ǰ������������Ʒ����������۸�*/
int TheLowestPriceInAuctionHouse(auctionItems Items,auctionItem &Item){
    long int LowestPrice = 0;
    while(Items -> next != NULL){
        Items = Items -> next;
        if(Items -> TheHighestPrice <= LowestPrice && Equal_Str(Items -> State,"�ѳɽ�")){
            LowestPrice = Items -> TheHighestPrice;
            Item = *Items;
        }
    }
    return LowestPrice;
}

/*���ص�ǰ������������Ʒ���ܳɽ���*/
int TurnoverInAuctionHouse(auctionItems Items){
    long int Turnover = 0;
    while(Items -> next != NULL){
        Items = Items -> next;
        if(Equal_Str(Items -> State,"�ѳɽ�")) Turnover += (Items -> TheHighestPrice);
    }
    return Turnover;
}

/*���ص�ǰ������������Ʒ���ܳɽ���or����������*/
int TurnoverNumberInAuctionHouse(auctionItems Items,char State[]){
    long int TurnoverNumber = 0;
    while(Items -> next != NULL){
        Items = Items -> next;
        if(Equal_Str(Items -> State,State)) TurnoverNumber++;
    }
    return TurnoverNumber;
}


/****************************����Ʒ���������*******************************/


/****************************�û����������*********************************/
/*���ļ�����û���Ϣ*/
void AddUserToFile(User &UserItem){
    FILE *fp;
    fp = fopen("Users_DataBase.txt","a+");
    Input_Str(UserItem.Account,b1);
    Input_Str(UserItem.Nickname,b2);
    Input_Password(UserItem.Password,b3,b4);
    fwrite(&UserItem,sizeof(User),1,fp);
    fclose(fp);
}

/*ɾ���û���Ϣ*/
//δʵ����������������³�ʼ���б�
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
int UserLog(Users UserItems,User &UserItem){
    char Account[20],Password[20];
    cout << b1;
    scanf("%s",Account);
    cout << b3;
    scanf("%s",Password);
    if(SearchByAccount(UserItems,Account,UserItem)){
        if(Equal_Str(Password,UserItem.Password)) return 1;//��¼�ɹ�
        else return -1;//�������
    }
    return 0;//�˺Ų�����
}

/*�޸����뺯��*/
int ModifyUserPassword(Users &UserItems,char *Account){
    FILE *fp;
    fp = fopen("Users_DataBase.txt","a+");
    User UserItem;
    if(DeleteUser(UserItems,Account,UserItem) != 1){
        cout << "ɾ��ʧ��"<< endl;
        return 0;
    }
    Input_Password(UserItem.Password,b5,b6);
    fwrite(&UserItem,sizeof(User),1,fp);
    CreateUserList(UserItems);//���³�ʼ������
    fclose(fp);
    return 1;
}

/****************************�û����������*********************************/


int main()
{
    int Selector;
    auctionItems Items;
    auctionItem Item,PreItem,PostItem;
    User UserItem;
    Users UserItems;
    CreateUserList(UserItems);
    CreateAuctionList(Items);

//    AddAuctionItemToFile(Item);
//    AddAuctionItemToFile(Item);
//    AddAuctionItemToFile(Item);
//    AddAuctionItemToFile(Item);
//    AddAuctionItemToFile(Item);
//    AddAuctionItemToFile(Item);
//    AddUserToFile(UserItem);
//    AddUserToFile(UserItem);
//    AddUserToFile(UserItem);

    PrintUsers(UserItems);
    cout << "--------------------------" << endl;
//    ModifyUserPassword(UserItems,"XiaoHong");
    DeleteUser(UserItems,"BCd",UserItem);
    CreateUserList(UserItems);
    PrintUsers(UserItems);
//    if(UserLog(UserItems,UserItem) == 1){
//        PrintUser(UserItem);
//    }
//    else{
//        cout << "��¼ʧ��" << endl;
//    }



//    cout << "--------------��ǰ�б���Ϣ-------------" << endl;
//    if(!PrintAuctionItems(Items)){
//        cout << "��ǰ�������е���Ʒ" << endl;
//     }
//    DeleteItemAndPrint(Items,1,Item);
//    cout << "--------------��ǰ����Ʒ����------------" <<endl;
//    cout << AuctionItemQuantity(Items) << endl;
//    ModifyItemAndPrint(Items,0,PreItem,PostItem);
//    SearchById(Items,2,Item);
//    PrintAuctionItem(Item);
//    SearchByName(Items,"����",Item);
//    PrintAuctionItem(Item);
//    SearchByCategory(Items,"����");
//    SearchByOwner(Items,"С��");
//    cout << "----------�����߼۸�--------------" << endl;
//    TheHighestPriceInAuctionHouse(Items,Item);
//    PrintAuctionItem(Item);
//    TheLowestPriceInAuctionHouse(Items,Item);
//    PrintAuctionItem(Item);
//    cout << TurnoverNumberInAuctionHouse(Items,"�ѳɽ�") << endl;
//    SearchByState(Items,"������");


}
