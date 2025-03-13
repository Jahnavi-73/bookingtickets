#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
  int ticketnum;
  char name[30];
  struct node *next;
}*front=NULL,*rear=NULL,*top=NULL;
void bookticket(char name[],int tn){
  struct node *nn;
  nn=(struct node*)malloc(sizeof(struct node));
  nn->ticketnum=tn;
  strcpy(nn->name,name);
  nn->next=NULL;
  if(front==NULL){
    front=rear=nn;
  }else {
    rear->next=nn;
    rear=nn;
  }
printf("Ticket booked for %S\n %d\n",name,tn);
}
void displaytickets(){
  struct node *temp=front;
  if(front==NULL){
  printf("No Bookings\n");
  }else{
     printf("Booked tickets\n");
    while(temp!=NULL){
      printf("ticketnum: %d\n,name: %s\n",temp->ticketnum,temp->name);
      temp=temp->next;
  }
}
void cancelticket(){
  if(front==NULL){
  printf("NO bookings to cancel\n");
  }else{
    struct node *del;
    del=front;
    front=front->next;
    if(front==NULL){
      rear=NULL;
      return;
    }
    del->next=top;
    top=del;
    printf("The ticketnum %d cancelled for %s\n",del->ticketnum,del->name);
  }
}
void displaycancellation(){
  struct node *temp=top;
  if(top==NULL){
    printf("No cancelled tickets\n");
    return;
  }
  printf("Cancelled tickets\n");
  while(temp!=NULL)
      printf("ticketnum: %d\n,name: %s\n",temp->ticketnum,temp->name);
      temp=temp->next;
}
int main()
{
  int choice,tn=16325;
  char name[30];
  while(1){
    printf("//*****ONLINE TICKET BOOKING SYSTEM*****//");
    printf("1.bookticket\n");
    printf("2.displaytickets\n");
    printf("3.cancelticket\n");
    printf("4.displaycancellation\n");
    printf("5.Exit\n");
    printf("6.Enter choice: \n");
    scanf("%d",&choice);
      switch(choice){
        case 1:
            printf("Enter a Name: ");
            scanf("%s",name);
            bookticket(name,tn++);
            break;
        case 2:
            displaytickets();
            break;
        case 3:
            cancelticket();
            break;
        case 4:
            displaycancellation();
            break;
        case 5:
            printf("Thankyou\n");
            exit(0);
        default:
            printf("Invalid choice");
          
      }
  }  

}
