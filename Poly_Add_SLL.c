#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int coe;
	int exp;
	struct node *next;
};
void insert_poly (int val, int e, struct node **start)
{
	struct node *ptr, *new_node;
	new_node=(struct node *)malloc(sizeof(struct node *));
	new_node->coe=val;
	new_node->exp=e;
	new_node->next=NULL;
	if (*start==NULL)
		*start=new_node;
	else
	{
		ptr=*start;
		while(ptr->next != NULL)
			ptr=ptr->next;
		ptr->next=new_node;
	}
}

struct node *addnode (struct node *str, int co, int ex)
{
	str->coe = co;
	str->exp = ex;
	return str;
}

void addpoly (struct node *ptr1, struct node *ptr2, struct node **p3)
{
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node *));
	ptr->next=NULL;
	*p3=ptr;
	while (ptr1 != NULL && ptr2 != NULL) 
	{
        if (ptr1->exp > ptr2->exp)
		{
            ptr = addnode(ptr,ptr1->coe,ptr1->exp);
            ptr1 = ptr1->next;
        }
        else if (ptr1->exp < ptr2->exp)
		{
            ptr = addnode(ptr,ptr2->coe,ptr2->exp);
            ptr2 = ptr2->next;
        }
        else
		{
            ptr = addnode(ptr,ptr1->coe+ptr2->coe,ptr2->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if (ptr1 != NULL && ptr2 != NULL)
        {
        	ptr->next = (struct node *)malloc(sizeof(struct node *));
			ptr = ptr->next;
			ptr->next = NULL;	
		}
    }
    while(ptr1 != NULL || ptr2 != NULL) 
	{
		ptr->next = (struct node *)malloc(sizeof(struct node *));
		ptr = ptr->next;
		ptr->next = NULL;
		if(ptr1 != NULL)
		{
			ptr = addnode(ptr,ptr1->coe,ptr1->exp);
			ptr1 = ptr1->next;
		}
		if(ptr2 != NULL)
		{
			ptr = addnode(ptr,ptr2->coe,ptr2->exp);
			ptr2 = ptr2->next;
		}
	}
}

void display (struct node *ptr)
{
	while (ptr != NULL)
	{
		if(ptr->coe != 0)
			printf("%dx^%d",ptr->coe,ptr->exp);
		ptr = ptr->next;
        if (ptr != NULL && ptr->coe > 0)
            printf("+");
	}
}

int main ()
{
	struct node *ptr1=NULL,*ptr2=NULL,*p3=NULL;
	int c,e;
	char ch;
	printf("\nEnter first polynomial : \n");
	while(1)
	{
		printf("\nEnter the coefficient : ");
		scanf("%d",&c);
		printf("Enter the exponent : ");
		scanf("%d",&e);
		insert_poly(c,e,&ptr1);
		printf("\nWant to add another factor ?\n(n for no/Another other charecter for yes) : ");
		scanf(" %c",&ch);
		if (ch=='n')
			break;
	}
	printf("\nFirst Equation is : ");display(ptr1);
	printf("\nEnter second polynomial : \n");
	while(1)
	{
		printf("\nEnter the coefficient : ");
		scanf("%d",&c);
		printf("Enter the exponent : ");
		scanf("%d",&e);
		insert_poly(c,e,&ptr2);
		printf("\nWant to add another factor ?\n(n for no/Another other charecter for yes) : ");
		scanf(" %c",&ch);
		if (ch=='n')
			break;
	}
	printf("\nSecond Equation is : ");display(ptr2);
	addpoly(ptr1,ptr2,&p3);
	printf("\nFinal Equation after addition is : ");display(p3);
	return 0;
}
