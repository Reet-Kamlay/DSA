#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;
struct node *temp;

void insert()
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->next=NULL;
    printf("Enter the data in the linked list:");
    scanf("%d", &new_node->data);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
}

void display()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int ch;

    while (1)
    {

        printf("\n\n 1 for Insert ");
        printf("\n 2 for display");
        printf("\n\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(1);
        default:
            printf("Invalid choice");
        }
    }
}