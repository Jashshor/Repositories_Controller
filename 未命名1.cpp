#include <stdio.h>  

#include <malloc.h>  
#include <string.h>  
#include <stdlib.h>                     
#include <windows.h>  
#define HEAD1 "          Ԫ��������ϵͳ                  \n"
#define HEAD2 "******************************************\n"
#define DATE "���\t�۸�\t����\t��Ŀ\t�ͺ�\t����\t����\t��װ\n"
#define LEN sizeof(struct component)  


struct component   
{
char name[10];   //���
double num;      //�۸�
char type[10];   //����
int no;          //��Ŀ
char model[30];  //�ͺ�
double date;     //����
char factory[20];//����
char fz[10] ;    //��װ
struct component *next;
};

int TOTAL_NUM = 0;
struct component *head = NULL;
void wrong();
void welcome (); //��ӭ����
void mainmenu (); //������
void record (); //��¼����
void insert(struct component *stu); //��������
void display(struct component *stu); //��ʾһ��Ԫ��������Ϣ
void displayAll (); //��ʾ����Ԫ��������Ϣ
void query_by_num (); //���۸��ѯԪ������Ϣ
void freeAll (); //�����������
void del (); //ɾ��Ԫ������Ϣ
void change (); //����Ԫ������Ϣ
void devise (struct component *p); //ѡ���������

int main (void)

{
	welcome ();
//��ʾ���˵�
	mainmenu ();
	return 0;
}
//��ʾ��ӭ��Ϣ
void welcome ()
{
    printf (HEAD2);
    printf (HEAD1);
    printf("\n�������������������");
   getchar();

}

void wrong()
{
printf("error!������ѡ��\n");
getchar();
}

//ϵͳ���˵�
void mainmenu ()
{  
    int select;
    select = -1;
system("cls");   
    do
    {  
        printf (HEAD1);  
         
        printf ("          [1]----����µ�Ԫ����       \n");
        printf ("          [2]----ͳ��Ԫ��������       \n");
        printf ("          [3]----��ѯ��Ϣ             \n");
        printf ("          [4]----ɾ��Ԫ����           \n");
        printf ("          [5]----�޸�Ԫ����           \n");
        printf ("          [6]----�˳�ϵͳ     \n");
        printf ("����������ѡ��");
        scanf ("%d", &select);
        switch (select)
        {
            case 6:
            
             getchar();
                break;
   case 1:
                record ();
                break;
   case 2:
                displayAll ();
                break;
   case 3:
                query_by_num ();
                break;  
   case 4:
                del ();
                break;
   case 5:
                change ();
                break;
            default:
                wrong();
                break;
        }
    }
    while (select != 6);
}

void record ()
{
struct component *p0;   
system("cls");    /*����*/
p0 = (struct component *)malloc(LEN);
printf ("\n\n\n\n\n\n\n");
printf ("\t\t������Ԫ�������:");
scanf ("%s",p0->name);
printf ("\t\t������Ԫ�����۸�:");
scanf ("%lf",&p0->num);
printf ("\t\t������Ԫ����������:");
scanf ("%s",p0->type);
printf ("\t\t������Ԫ��������Ŀ:");
scanf ("%d",&p0->no);
printf ("\t\t������Ԫ�������ͺ�:");
scanf ("%s",p0->model);
printf ("\t\t������Ԫ����������:");
scanf ("%lf",&p0->date);
printf ("\t\t������Ԫ�����ĳ���:");
scanf ("%s",p0->factory);
printf ("\t\t������Ԫ�����ķ�װ:");
scanf ("%s",p0->fz);
insert (p0);  //��������
printf ("��Ԫ��������ϢΪ:\n");
  printf ("-------------------------------------------------------------------------------\n");
printf (DATE);
display (p0);  
}
void insert (struct component *stu)
{   
struct component *p0, *p1, *p2;
p1 = head;
p0 = stu;

if (head == NULL)
{
  head = p0;
  p0->next = NULL;
}
else
{
  while ((p0->num > p1->num)&&(p1->next != NULL))
  {
   p2 = p1;
   p1 = p1->next;
  }
  if (p0->num <= p1->num)
  {
   if (head == p1)
   head = p0;
   else
   p2->next = p0;
   p0->next = p1;
  }
  else
  {
   p1->next = p0;
   p0->next = NULL;
  }  
}
TOTAL_NUM++;
  
}
//���Ԫ������Ϣ
void display (struct component *p)
{
printf ("%s\t%.0lf\t%d\t%s\t%s\t%.0f\t%s\t%s\n", p->name, p->num, p->no, p->type, p->model, p->date, p->factory,p->fz);
}

void displayAll()
{
struct component *p;
printf("Ԫ��������:%d\n", TOTAL_NUM);
p = head;
if (head != NULL)
{  
  system("cls");
  printf(DATE);
  printf("-------------------------------------------------------------------------------\n");
  do
  {
   display(p);
   p = p->next;
  }
  while(p != NULL);
}
printf ("\n");
   getchar();
}
//���۸��ѯԪ������Ϣ
void query_by_num ()
{
int num;
struct component *p1;
printf("������Ԫ�����ļ۸�");
scanf("%ld", &num);
if(head==NULL)
{
  printf("��Ԫ������¼��\n");
  return;
}
p1 = head;
while (num!=p1->num && p1->next!=NULL)
p1 = p1->next;
if (num == p1->num)
{
  printf (DATE);
  printf ("-------------------------------------------------------------------------------\n");
  display (p1);
}
else
printf ("û�и�Ԫ������¼����˶ԣ�");
   system("pause");
   system("cls"); 
}

/*------------------------------------ɾ��Ԫ������Ϣ------------------------------------*/
void del ()
{
struct component *p1, *p2;
long int num;

if (head == NULL)
{
  system("cls");
  printf("�޼�¼�������������Ϣ\n");
  getchar;
  return;
}
printf("��������ڵı�ţ�");
scanf("%ld", &num);
p1 = head;

while (num != p1->num && p1->next != NULL)
{
  p2 = p1;
  p1 = p1->next;  
}
if(num == p1->num)
{
  if(p1 == head)
  head = p1->next;
  else p2->next = p1->next;
  free(p1);
  TOTAL_NUM--;
}
else
printf("û���ҵ���Ԫ������\n");
   
}
/*------------------------------------�޸�Ԫ������Ϣ------------------------------------*/
void change ()
{
struct component *p1, *p2;
long int num;
if (head == NULL)
{
  printf ("��Ԫ������¼��\n");
  return;
}
printf ("��������Ҫ�޸ĵ�Ԫ�����ļ۸�");
scanf ("%ld", &num);
p1 = head;
while (num != p1->num && p1->next != NULL)
{
  p2 = p1;
  p1 = p1->next;  
}
if(num == p1->num)
devise (p1);
else
printf("û�и�Ԫ������¼����˶ԣ�\n");
}
void devise (struct component *p)
{
int choice;
    choice = -1;
    do
    {
   
        printf("��ѡ����Ҫ�޸ĵ�Ԫ��������Ϣ���ݣ�\n");
        printf("+----------------------+\n");        
        printf("| ���          �밴 1 |\n");
        printf("| �۸�          �밴 2 |\n");
  printf("| ����          �밴 3 |\n");
  printf("| ��Ŀ   �밴 4 |\n");
  printf("| �ͺ�          �밴 5 |\n");
  printf("| ����          �밴 6 |\n");
  printf("| ����   �밴 7 |\n");
  printf("| ȡ��          �밴 0 |\n");
        printf("+----------------------+\n");
        printf("����������ѡ��");
        scanf("%d", &choice);
      
        switch (choice)
        {
            case 0:
    return;
            case 1:
                printf("�������±�ţ�");
    scanf("%s", p->name);
                break;
            case 2:
                printf("�������¼۸�");
    scanf("%d", &p->num);
                break;
   case 3:
                printf("�����������ͣ�");
    scanf("%s", p->type);
                break;
   case 4:
                printf("����������Ŀ��");
    scanf("%s", &p->no);
                break;
   case 5:
                printf("���������ͺţ�");
    scanf("%s", p->model);
                break;
   case 6:
                printf("�����������ڣ�");
    scanf("%lf", &p->date);
                break;
   case 7:
                printf("�������£�");
    scanf("%s", p->factory);
                break;
            default:
                printf("\n��Чѡ��!");
                break;
        }
    }
    while(choice != 0);
}
typedef struct node
{
struct component date;
struct node*next;
}Node,*Link;
