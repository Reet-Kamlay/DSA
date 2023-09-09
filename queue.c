#include<stdio.h>
int queue[10];
int r=-1;
int f=-1;
void enqueue(int size,int value){
    if(r==size-1){
        printf("Queue Full\n");
    }
    else{
        if(r==-1){
            f=r=0;
        }
        else{
            r=r+1;
        }
        queue[r]=value;
    }
}
int dequeue(){
    if(f==-1){
        printf("Queue Empty\n");
    }
    else{
        printf("%d\n",queue[f]);
        if(f==r){
            f=r=-1;
        }
        else{
            f=f+1;
        }
    }
}
void display(){
    for(int i=f;i<=r;i++){
        printf("%d\n",queue[i]);
    }
}
int main(){
    int size=5;
    int value,ch;
    label:
    printf("Enter the corrosponding value for executing operations (ENQUEUE:1,DEQUEUE:2,DISPLAY:3): ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("Enter the value you want to insert: ");
        scanf("%d",&value);
        enqueue(size,value);
        break;
    case 2:
        dequeue();
        break;
    case 3:
        display();
        break;
    default:
        printf("Wrong value.\n");
        break;
    }
    goto label;
    return 0;
}