/*此函数是学生管理系统，主函数有两个，一个时常规函数，一个用到来getchar(),
*




*/
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
    printf("please input tht number :\n");
    scanf("%d",&p_c->number);
    printf("please input the name :\n");
    scanf("%s",p_c->name);
    getchar();
    p_c->next=NULL;
    if (NULL==ptr)
    {
        return p_c;
    }
    if (p_c->number < head->number)
    {
        p_c->next=head;
        return p_c;
    }
    while((ptr->next!=NULL)&&(p_c->number > ptr->next->number))
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
    stu *temp=NULL;
    int i=0;
    printf("please input the delete number :\n");
    scanf("%d",&i);
    getchar();
    if(p==NULL)
    {
        printf("empty\n");
        return p;
    }
    if (p->number==i)
    {
        temp=p;/////////
        h=p=p->next;
        free(temp);
        return h;
    }
    while(p->next!=NULL)
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
    if(p==NULL)
    {
        printf("empty\n");
        return;
    }
    while(p!=NULL)
    {
        printf("%d     %s\n",p->number,p->name);    
        p=p->next;
    }
    return ;
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
void save_link(stu *p)
{
    FILE *fp=NULL;
    fp=fopen("1.txt","w+");
    if (fp==NULL) 
    {
        perror("open");
        exit(0);
    }
    while(p!=NULL)
    {
        fprintf(fp,"%d    %s\n",p->number,p->name);
        p=p->next;
    }
    fclose(fp);
}
/*
int main(int argc, const char *argv[])
{
    stu *head = NULL;
    char flag=1;
    int  choice=0;
    while(flag>0)
    {
        menu();
       // choice=getchar();
        scanf("%d", &choice);
       // getchar();
        
        switch(choice)
        {   
            case 1:head = add_link(head);break;
            case 2:head = delete_link(head);break;
            case 3:printf_link(head);break;
            case 4:save_link(head);break;
            case 5:flag=0;break;
            default : printf("num is no\n"); break;
        }
    }
    printf("\n");
    return 0;
}*/
int main(int argc, const char *argv[])/////用此主函数时，应该注意在输入函数中添加getchar(),用来消除缓冲区的回车键。。此函数中在插入 和 删除函数中都要用到。
{
    stu *head=NULL;
    char flag=1;
    char choice=0;
    
    while(flag>0)
    {
        menu();
        choice=getchar();
        getchar();
        switch(choice)
        {
            case '1':head=add_link(head);break;
            case '2':head=delete_link(head);break;
            case '3':printf_link(head);break;
            case '4':save_link(head);break;
            case '5':flag=0;break;
            default : printf("no number\n");break;
        }
    }
    printf("\n");
    return 0;
}
