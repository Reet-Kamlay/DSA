#include<stdio.h>
int stack[100];
int top=-1;
void push(){
    int n;
    if(top==100-1){
        printf("Stack Overflow");
    }
    else{
        printf("Enter the value you want to insert: ");
        scanf("%d",&n);
        top++;
        stack[top]=n;
        printf("The element is been inserted in the stack.\n");
    }
    
}
void peek(){
    int n=stack[top];
    if(top==-1){
        printf("stack underflow");
    }
    else{
        printf("The topmost element is : %d\n",n);
    }
}
int pop(){
    int n=stack[top];
    if(top==-1){
        printf("Stack underflow");
    }
    else{
        top--;
        printf("The popped element is : %d\n",n);
    }
}
void display(){
    printf("The elements of the stack are:\n");
    for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}
int main(){
    int value;
    label:
    printf("Enter the corrosponding value for executing operations (PUSH:1,POP:2,PEEK:3,DISPLAY:4): ");
    scanf("%d",&value);
    switch(value)
    {
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        peek();
        break;
    case 4:
        display();
        break;
    default:
        printf("Wrong value.\n");
        break;
    }
    goto label;
    return 0;
}