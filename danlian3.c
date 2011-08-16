#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct student
{
    int year;
    char name[20];
    struct student *next;
};
typedef struct student STU;
void *create_link(int n)
{
    STU *p=NULL;
    STU *head=NULL;
    int i=0;
    p=head=malloc(sizeof(STU));

    if (p==NULL)
    {
        perror("create");
        exit(0);
    }

    p->year=1;
    strcpy(p->name , "wnag");
    p->next=NULL;
    for (i = 0; i < n; i++)
    {
        p->next=malloc(sizeof(STU));
        if (p->next==NULL)
        {
            perror("create");
            exit(0);
        }
        p->next->year=i+1;
        strcpy(p->next->name , "wang");
        p->next->next=NULL;
        p=p->next;
    }
    return head;
}

void printf_link(STU *p)
{
    while(p!=NULL)
    
    {
    printf("%-5d  %s\n", p->year,p->name);
    p=p->next;
    }
}
int main(int argc, const char *argv[])
{
    STU *head=NULL;
    head=create_link(10);
    printf_link(head);
    return 0;
}
