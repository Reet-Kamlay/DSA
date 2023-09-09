#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}*head=NULL,*temp,*ptr,*p,*n,*car;
void create(){
    int value;
    printf("Enter the value of the first node: ");
    scanf("%d",&value);
    struct node* newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    head=newnode;
}
void insert_at_beginning(){
    int data;
    if(head==NULL){
        printf("You have not created the first node\nFirst create it\n");
        create();
    }
    else{
        printf("Enter the value of node for inserting it: ");
        scanf("%d",&data);
        struct node* newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->next=NULL;
        newnode->next=head;
        head=newnode;
    }
}
void insert_at_end(){
    int data;
    if(head==NULL){
        printf("You have not created the first node\nFirst create it\n");
        create();
    }
    else{
        printf("Enter the value of the node: ");
        scanf("%d",&data);
        struct node* newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->next=NULL;
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        
    }
}
void delete_from_beginning(){
    if(head==NULL){
        printf("Nothing to delete\n");
    }
    else if(head->next==NULL){
        printf("Head node is going to be deleted\n");
        temp=head;
        head=NULL;
        printf("The value of the head node is: %d\n",temp->data);
        free(temp);
    }
    else{
        temp=head;
        head=head->next;
        printf("The value of the deleted node is: %d\n",temp->data);
        free(temp);
    }
}
void delete_from_end(){
    if(head==NULL){
        printf("Nothing to delete\n");
    }
    else if(head->next==NULL){
        printf("Head node is going to be deleted\n");
        temp=head;
        head=NULL;
        printf("The value of the head node is: %d\n",temp->data);
        free(temp);
    }
    else{
        ptr=head;
        while(ptr->next->next!=NULL){
            ptr=ptr->next;
        }
        temp=ptr->next;
        ptr->next=NULL;
        printf("The value of the node you deleted is: %d\n",temp->data);
        free(temp);
    }
}
void reverse_list(){
    if(head==NULL){
        printf("The list is empty\nNothing to reverse\n");
    }
    p=NULL;
    car=head;
    while(car!=NULL){
        n=car->next;
        car->next=p;
        p=car;
        car=n;
    }
    head=p;
}
void insert_after_value(){
    int value1,value2;
    if(head==NULL){
        printf("list is empty\nGiven value could not be found\n");
    }
    else{
        printf("Enter the value after which you want to insert the node: ");
        scanf("%d",&value1);
        printf("Enter the value of the inserting node: ");
        scanf("%d",&value2);
        ptr=head;
        while(ptr->data!=value1){
            ptr=ptr->next;
        }
        if(ptr->data!=value1){
            printf("Given value not found\n");
        }
        else{
            struct node* newnode=(struct node *)malloc(sizeof(struct node));
            newnode->data=value2;
            newnode->next=ptr->next;
            ptr->next=newnode;
        }
    }
}
void delete_after_value(){
    int value;
    printf("The value after which you want to delete :");
    scanf("%d",&value);
    if(head==NULL){
        printf("Nothing to delete\n");
    }
    else{
        ptr=head;
        while(ptr->data!=value){
            ptr=ptr->next;
        }
        if(ptr->next==NULL){
            printf("There is nothing to delete after your given value\n");
        }
        else if(ptr->data!=value){
            printf("Value not found after which you want to delete\n");
        }
        else{
            temp=ptr->next;
            ptr->next=temp->next;
            printf("The value of the deleted node is: %d\n",temp->data);
            free(temp);
        }
    }
}
void display(){
    ptr=head;
    printf("Displaying whole list:\n");
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    int ch;
    while(1){
        printf("-------------Enter the code for performing different operations--------------\n1:Insert at beginning\n2:Insert at end\n3:Delete from beginning\n4:Delete from end\n5:Reversing the list\n6:Insert after a value\n7:Delete after a value\n8:For exit\n9:For creating first node\n10:For display\n-------------Enter your choice-------------\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                insert_at_beginning();
                break;
            case 2:
                insert_at_end();
                break;
            case 3:
                delete_from_beginning();
                break;
            case 4:
                delete_from_end();
                break;
            case 5:
                reverse_list();
                break;
            case 6:
                insert_after_value();
                break;
            case 7:
                delete_after_value();
                break;
            case 8:
                exit(1);
                break;
            case 9:
                create();
                break;
            case 10:
                display();
                break;
            default:
                printf("Wrong Choice\n");
        }
    }
    return 0;
}