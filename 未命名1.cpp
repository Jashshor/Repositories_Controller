#include <stdio.h>  

#include <malloc.h>  
#include <string.h>  
#include <stdlib.h>                     
#include <windows.h>  
#define HEAD1 "          元器件管理系统                  \n"
#define HEAD2 "******************************************\n"
#define DATE "编号\t价格\t类型\t数目\t型号\t日期\t厂家\t封装\n"
#define LEN sizeof(struct component)  


struct component   
{
char name[10];   //编号
double num;      //价格
char type[10];   //类型
int no;          //数目
char model[30];  //型号
double date;     //日期
char factory[20];//厂家
char fz[10] ;    //封装
struct component *next;
};

int TOTAL_NUM = 0;
struct component *head = NULL;
void wrong();
void welcome (); //欢迎界面
void mainmenu (); //主界面
void record (); //记录数据
void insert(struct component *stu); //插入数据
void display(struct component *stu); //显示一个元器件的信息
void displayAll (); //显示所有元器件的信息
void query_by_num (); //按价格查询元器件信息
void freeAll (); //清空链表内容
void del (); //删除元器件信息
void change (); //更改元器件信息
void devise (struct component *p); //选择更改内容

int main (void)

{
	welcome ();
//显示主菜单
	mainmenu ();
	return 0;
}
//显示欢迎信息
void welcome ()
{
    printf (HEAD2);
    printf (HEAD1);
    printf("\n输入任意键进入主界面");
   getchar();

}

void wrong()
{
printf("error!请重新选择！\n");
getchar();
}

//系统主菜单
void mainmenu ()
{  
    int select;
    select = -1;
system("cls");   
    do
    {  
        printf (HEAD1);  
         
        printf ("          [1]----添加新的元器件       \n");
        printf ("          [2]----统计元器件总数       \n");
        printf ("          [3]----查询信息             \n");
        printf ("          [4]----删除元器件           \n");
        printf ("          [5]----修改元器件           \n");
        printf ("          [6]----退出系统     \n");
        printf ("请输入您的选择：");
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
system("cls");    /*清屏*/
p0 = (struct component *)malloc(LEN);
printf ("\n\n\n\n\n\n\n");
printf ("\t\t请输入元器件编号:");
scanf ("%s",p0->name);
printf ("\t\t请输入元器件价格:");
scanf ("%lf",&p0->num);
printf ("\t\t请输入元器件的类型:");
scanf ("%s",p0->type);
printf ("\t\t请输入元器件的数目:");
scanf ("%d",&p0->no);
printf ("\t\t请输入元器件的型号:");
scanf ("%s",p0->model);
printf ("\t\t请输入元器件的日期:");
scanf ("%lf",&p0->date);
printf ("\t\t请输入元器件的厂家:");
scanf ("%s",p0->factory);
printf ("\t\t请输入元器件的封装:");
scanf ("%s",p0->fz);
insert (p0);  //插入数据
printf ("该元器件的信息为:\n");
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
//浏览元器件信息
void display (struct component *p)
{
printf ("%s\t%.0lf\t%d\t%s\t%s\t%.0f\t%s\t%s\n", p->name, p->num, p->no, p->type, p->model, p->date, p->factory,p->fz);
}

void displayAll()
{
struct component *p;
printf("元器件总数:%d\n", TOTAL_NUM);
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
//按价格查询元器件信息
void query_by_num ()
{
int num;
struct component *p1;
printf("请输入元器件的价格：");
scanf("%ld", &num);
if(head==NULL)
{
  printf("无元器件记录！\n");
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
printf ("没有该元器件记录，请核对！");
   system("pause");
   system("cls"); 
}

/*------------------------------------删除元器件信息------------------------------------*/
void del ()
{
struct component *p1, *p2;
long int num;

if (head == NULL)
{
  system("cls");
  printf("无记录！请输入相关信息\n");
  getchar;
  return;
}
printf("请输入存在的编号：");
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
printf("没有找到此元器件！\n");
   
}
/*------------------------------------修改元器件信息------------------------------------*/
void change ()
{
struct component *p1, *p2;
long int num;
if (head == NULL)
{
  printf ("无元器件记录！\n");
  return;
}
printf ("请输入您要修改的元器件的价格：");
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
printf("没有该元器件记录，请核对！\n");
}
void devise (struct component *p)
{
int choice;
    choice = -1;
    do
    {
   
        printf("请选择您要修改的元器件的信息内容：\n");
        printf("+----------------------+\n");        
        printf("| 编号          请按 1 |\n");
        printf("| 价格          请按 2 |\n");
  printf("| 类型          请按 3 |\n");
  printf("| 数目   请按 4 |\n");
  printf("| 型号          请按 5 |\n");
  printf("| 日期          请按 6 |\n");
  printf("| 厂家   请按 7 |\n");
  printf("| 取消          请按 0 |\n");
        printf("+----------------------+\n");
        printf("请输入您的选择：");
        scanf("%d", &choice);
      
        switch (choice)
        {
            case 0:
    return;
            case 1:
                printf("请输入新编号：");
    scanf("%s", p->name);
                break;
            case 2:
                printf("请输入新价格：");
    scanf("%d", &p->num);
                break;
   case 3:
                printf("请输入新类型：");
    scanf("%s", p->type);
                break;
   case 4:
                printf("请输入新数目：");
    scanf("%s", &p->no);
                break;
   case 5:
                printf("请输入新型号：");
    scanf("%s", p->model);
                break;
   case 6:
                printf("请输入新日期：");
    scanf("%lf", &p->date);
                break;
   case 7:
                printf("请输入新：");
    scanf("%s", p->factory);
                break;
            default:
                printf("\n无效选项!");
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
