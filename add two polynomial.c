#include<stdio.h>
#include<stdlib.h>
struct node{
    int expo;
    float coef;
    struct node* link;
};

struct node *insert(struct node *head,int co,int ex){
    struct node*temp;
    struct node* newp=(struct node *)malloc (sizeof(struct node));
    newp->coef=co;
    newp->expo=ex;
    newp->link=NULL;
    if(head==NULL || ex>head->expo){
        newp->link=head;
        head=newp;
    }
    else{
        temp=head;
        while(temp!=NULL && temp->link->expo >ex){
            temp=temp->link;
        }
        newp->link=temp->link;
        temp->link=newp;
    }
    return head;
}    
struct node* create(struct node* head){
    int i,n;
    float coef;
    int expo;
    printf("enter no of terms:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
    printf("Enter coef%d :",i);
    scanf("%f",&coef);
    printf("enter expo%d :",i);
    scanf("%d",&expo);
    head=insert(head,coef,expo);
    }
    return head;
}
 void print(struct node* head){
     struct node* temp=head;
     if(head==NULL){
         printf("no polynomial");
     }
     else{
         while(temp!=NULL){
             printf("(%.2fx^%d)",temp->coef,temp->expo);
             temp=temp->link;
             if(temp!=NULL){
                 printf("+");
             }
            else{
                printf("\n");
            }     
        
         }
     }
     
 }
 struct node *polyadd(struct node *head1,struct node* head2){
     struct node*ptr1=head1;
     struct node*ptr2=head2;
     struct node*head3=NULL;
     while(ptr1!=NULL && ptr2!=NULL){
         if(ptr1->expo==ptr2->expo){
             head3=insert(head3,ptr1->coef+ptr2->coef,ptr1->expo);
                 ptr1=ptr1->link;
                 ptr2=ptr2->link;
             }
             else if(ptr1->expo>ptr2->expo){
                 head3=insert(head3,ptr1->coef,ptr1->expo);
                 ptr1=ptr1->link;
             }
            else {
                 head3=insert(head3,ptr2->coef,ptr2->expo);
                 ptr2=ptr2->link;
            }

    while (ptr1 != NULL) {
        head3 = insert(head3, ptr1->coef, ptr1->expo);
        ptr1 = ptr1->link;
    }

    while (ptr2 != NULL) {
        head3 = insert(head3, ptr2->coef, ptr2->expo);
        ptr2 = ptr2->link;
    }

    return head3;
     }
}
 
int main(){
    struct node *head1;
    struct node *head2;
    head2==NULL;
    head1==NULL;
    printf("enter the polynomial1:\n");
    head1=create(head1);
    print(head1);
    printf("enter the polynomial2:\n");
    head2=create(head2);
    print(head2);
    struct node *result=polyadd(head1,head2);
    printf("polynomial after addition is:");
    print(result);
}



