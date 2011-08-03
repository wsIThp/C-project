#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct student
{
	int number;
	char name[20];
	struct student *next;
};

typedef	struct student STU;

STU *create_link(int n)
{
	int i = 0;
	STU *head = NULL;
	STU *p = NULL;

	head = p = malloc(sizeof(STU));
	if(p == NULL)
	{
		perror("create");
		exit(0);
	}
	p->number = 1;
	strcpy(p->name, "student");
	p->next = NULL;
	
	for(i=1; i<n; i++)
	{
		p->next = malloc(sizeof(STU));
		if(p->next == NULL)
		{
			perror("create");
			exit(0);
		}
		p->next->number = i+1;
		strcpy(p->next->name, "student");
		p->next->next = NULL;
		p = p->next;

	}

	return head;
}
STU *add_note(STU *p)
{
    STU *head=p;
    STU *p_c=NULL;
    p_c=malloc(sizeof(STU));
    if(p==NULL)
    {
        
    }
    if(p_c==NULL)
    {
        perror("create new");
        exit(0);
    }
    scanf("number%d",&p_c->number);
    scanf("name%s",p_c->name);
    p_c->next=NULL;

    while(p->next!=NULL)
    {
        if(p->next->number > p_c->number)
        {
            break;
        }

        p=p->next;
     
       
    }
        p_c->next=p->next;
        p->next=p_c;

    return head;
}
/*STU *remove_link(STU *q)
{
    int i;
    //STU *P=NULL;
    STU *ptr=NULL;
    scanf("%d",&i);
    q->next=ptr;
    while(ptr->number==q->next->number==i)    
    {
        q->next=ptr->next;
        free(ptr);
        return head; 
    }
}*/
STU *remove_link(STU *q)
{
    int i=0;
    STU *temp=NULL;
    STU *h=q;
    if(q==NULL)
    {
        printf("empty");
        return NULL;
    }
    scanf("%d",&i);

    if (q->number==i)
    {
        h=q->next;
        free(q);
        return h;
    }
    while(q->next!=NULL)
    {
        if(q->next->number==i)
        {
            break;
        }
        q=q->next;
     }
     if (q->next==NULL)
     {
         printf("no number\n");
         return h;
     }
    temp=q->next;  
    q->next=q->next->next;
    free(temp);
    return h;
}
void print_link(STU *p)
{
    if (p==NULL)
    {
        printf("empty");
    }
	while(p != NULL)
	{
		printf("%-5d  %s\n", p->number,p->name);
		p = p->next;
	}
}

int main(void)
{
	STU *head = NULL;
    
	head = create_link(10);
   //head=add_note(head);
    head =  remove_link(head);
	print_link(head);
	return 0;
}
