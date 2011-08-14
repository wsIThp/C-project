#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student 
{
    int number;
    char name[10];
    struct student *next;
};
typedef struct student stu;
stu *add_link(stu *head)
{
    stu *ptr=head;
    stu *p_c=NULL;
    p_c=malloc(sizeof(stu));
    if (p_c==NULL)
    {
        perror("create");
        exit(0);
    }
    printf("please input tht number :");
    scanf("%d",&p_c->number);
    printf("please input the name :");
    scanf("%s",p_c->name);
    p_c->next=NULL;
    if (NULL==ptr)
    {
        return p_c;
    }
    if (p_c->number<head->number)
    {
        p_c->next=head;
        return p_c;
    }
    printf("0");
    while((ptr->next!=NULL)&&(p_c->number>ptr->next->number))
    {
        ptr=ptr->next;
    }
    p_c->next=ptr->next;
    ptr->next=p_c;
    return head;
}
stu *delete_link(stu *p)
{
    stu *h=p;
    stu *temp;
    int i=0;
    scanf("%d",&i);
    if (p->number==i)
    {
        h=p->next;
        free(p);
        return h;
    }
    while(p!=NULL)
    {
        if (p->next->number==i)
        {
            break;
        }
        p=p->next;
    }
    if (p->next==NULL)
    {
        printf("no number \n");
        return h;
    }
    temp=p->next;
    p->next=p->next->next;
    free(temp);
    return h;
}
void printf_link(stu *p)
{
    while(p!=NULL)
    {
        printf("%d     %s",p->number,p->name);    
        p=p->next;
    }
}
char menu(void)
{
    puts("please make a choice");//只对字符窜的输出函数 ,自己有回车功能这里也可以用printf函数。
    puts("1. 添加");
    puts("2. 删除");
    puts("3. 打印");
    puts("4. 存储");
    puts("5. 退出");
}
int main(int argc, const char *argv[])
{
    stu *head = NULL;
    char flag=1;
    char choice=0;
    while(flag>0)
    {
        menu();
        choice=getchar();
        getchar();
        printf("%d\n",choice-48);
        //choice=choice-48;
        switch(choice-48)
        {   
            case 1:add_link(head);break;
            case 2:delete_link(head);break;
            case 3:printf_link(head);break;
            case 4:break;
            case 5:flag=0;break;
        }
    }
    //stu *h;
    //h =  add_link(head);

    printf_link(head);
    return 0;
}
