#include<stdio.h>
#include<stdlib.h>
struct student{
    int roll;
    struct student * next;
};

struct student * createlist(struct student * start); 
void printlist(struct student *print); 
struct student * merge(struct student * head1,struct student * head2);
void sort(struct student * sort); 

int main(){
    struct student *head1, *head2;
    struct student *head;
    head = head1 = head2 = NULL;
    //head = createlist(head);
    int ch;
    do{
        printf("Enter choice: \n 1.create the First linked list \n 2. create the second linked list\n 3.sort the linked lists\n 4.Marge the linked list\n 5. Display the linked list\n  ENTER 0 to exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1: head1 = createlist(head);
            break;
            case 2: head = NULL;
            head2 = createlist(head);;
            break;
            case 3:
            if(head1!=NULL && head2!=NULL){
                sort(head1);
                sort(head2);
                break;
            }
            else if (head1==NULL){
                sort(head2);
                break;
            }
            else if (head2==NULL){
                sort(head1);
                break;
            }
            else{
                printf("List is Empty") ;   
                break;
            }
            case 4: head = merge(head1,head2);
            break;
            case 5: 
            if(head!=NULL){
                printlist(head);
                break;
            }
            else if(head1!=NULL && head2!=NULL){
                printlist(head1);
                printlist(head2);
                break;
            }
            else if(head1!=NULL){
                printlist(head1);
                break;
            }
            else if(head2!=NULL){
                printlist(head2);
                break;
            }
            else{
                printf("List is empty");
                break;
            }
            
            default: if(ch==0){
                    printf("Thank you for using\n");
                }
                else{
                    printf("Invalid Choice\n");
                }

        }
    }while(ch!=0);
}
struct student * createlist(struct student * start){
    struct student * newnode, *temp;
    //int choice=1;
    int number_of_nodes;
    int i=0;
    printf("Enter how many nodes do you want: ");
    scanf("%d", &number_of_nodes);
    while(i<number_of_nodes){
        newnode=(struct student *)malloc(sizeof(struct student));
        printf("Enter the roll of the student: ");
        scanf("%d", &newnode->roll);
        newnode->next=NULL;
        if(start==NULL){
            start=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        i++;
        /*printf("*************  Press 1 to CONTINUE, 0 to TERMINATE ************ ");
        scanf("%d", &choice);*/
    }
    return start;
}
void printlist(struct student *print){
    struct student *temp;
    temp=print;
    int count=0;
    while(temp!=NULL){
    count++;
    //printf("The ROLL NUMBER of the student of node %d is %d\n", count,temp->roll);
    printf("%d --> ", temp->roll);
    temp=temp->next;
    }
    printf("Total number of nodes are %d\n",count);
}
void sort(struct student * sort){
    struct student * p = sort;
    int i, j, count=0,var;
    while(p->next!=NULL){
        count++;
        p = p->next;
    }
    p = sort;
    struct student *newhead = sort;
    for(i=0;i<count;i++){
        p = sort;
        for(j=0;j<count;j++){
            if(p->roll > p->next->roll){
                var = p->roll;
                p->roll = p->next->roll;
                p->next->roll = var;
            }
            p=p->next;
        }
    }
}

struct student * merge(struct student * head1,struct student * head2){
    if(head1 == NULL){
        return head2;
    }
    else if (head2 == NULL){
        return head2;
    }
    struct student * p1 = head1;
    struct student *p2=head2;
    struct student * newhead= NULL;
    //struct student * newhead;
   
    if(p1->roll <= p2->roll){
        newhead = p1;
        p1= p1->next;
    }
    else{
        newhead = p2;
        p2=p2->next;
    }
    struct student * tempnode = newhead;
    //struct student *p3;
    while(p1!=NULL && p2!= NULL){
        if(p1->roll <= p2->roll){
            tempnode->next = p1;
            p1= p1->next;
        }
        else{
            tempnode->next= p2;
            p2=p2->next;
        }
        //tempnode->next = p3;
        tempnode = tempnode->next;
    }
    if(p1!=NULL){
        while(p1!=NULL){
            tempnode->next = p1;
            p1=p1->next;
        }
    }
    else if(p2!=NULL){
        while(p2 !=NULL){
            tempnode->next = p2;
            p2=p2->next; 
        }
    }
    return newhead;
}