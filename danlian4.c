#include <stdio.h>

#include <stdlib.h>

struct node
{
	int number;
	struct node *next;
};

typedef	struct node V_NODE;

V_NODE *init_circle(int n)
{
	int i = 0;
	V_NODE *head = NULL;
	V_NODE *p = NULL;
	
	head = p = malloc(sizeof(V_NODE));
	if(p == NULL)
	{
		perror("malloc");
		exit(0);
	}
	p->number = 1;
	p->next = NULL;

	for(i=1; i<n; i++)
	{
		p->next = malloc(sizeof(V_NODE));
		if(p->next == NULL)
		{
			perror("malloc");
			exit(0);
		}
		p->next->number = i+1;
		p->next->next = NULL;
		p = p->next;
	}
	p->next = head;

	return p;

}

void j_game(V_NODE *p_f)
{
	V_NODE *p = p_f->next;
	int interval = 4;
	int out_counter = 0;

	while(p != p->next)
	{
		out_counter++;
		if(out_counter == interval)
		{
			out_counter = 0;
			printf("%6d(out)\n", p->number);
			p_f->next = p->next;
			free(p);
			p = p_f->next;
		}
		else
		{
			printf("%6d", p->number);
			p = p->next;
			p_f = p_f->next;
		}
	}
	printf("%6d left\n", p->number);

}
int main(void)
{
	int n = 0;
	V_NODE *rear = NULL;
	
	printf("Please input n:\n");
	scanf("%d", &n);
	rear = init_circle(n);
	j_game(rear);
	return 0;
}
