#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *head=NULL;


void insertAtBeginning( int value)
{
    struct Node *newNode;

    newNode=(struct Node*) malloc(sizeof(struct Node));

    newNode->data=value;
    newNode->prev=NULL;

    if(head == NULL)
    {
        newNode->next=NULL;
        head=newNode;
    }
    else
    {
        newNode->next=head;
        head=newNode;
    }

    printf("\n One node inserted at beginning !!\n");
}

void insertAtEnd(value)
{
    struct Node *newNode;

    newNode=(struct Node*) malloc(sizeof(struct Node));

    newNode->data=value;
    newNode->next=NULL;

    if(head == NULL)
    {
        newNode->prev=NULL;
        head=newNode;
    }
    else
    {
        struct Node *temp=head;

        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }

    printf("\n One node inserted at end !!\n");
}

void insertAnyPosition(value)
{
    struct Node *newNode;

    newNode=(struct Node*) malloc(sizeof(struct Node));

    newNode->data=value;

    if(head == NULL)
    {
        newNode->next=NULL;
        newNode->prev=NULL;
        head=newNode;
    }
    else
    {
        int location;
        printf("\n Enter insert position: ");
        scanf("%d",&location);

        struct Node *temp=head;

        for(int i=0; i<location; i++)
        {
            temp=temp->next;
        }
        newNode->next=temp->next;
        newNode->prev=temp;
        temp->next=newNode;
        temp->next->prev=newNode;

        printf("\n One node inserted!\n");
    }
}

void delete_first()
{


    if(head == NULL)
        printf("\nList is empty");
    else if(head->next == NULL)
    {
        head=NULL;
        free(head);
        printf("\n One node deleted !!\n");
    }
    else
    {
        struct Node *temp=head;
        head=temp->next;

        head->prev=NULL;
        free(temp);
        printf("\n One node deleted !!\n");
    }

}

void deleteAtEnd()
{
    if(head == NULL)
    {
        printf("\nList is empty");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        free(head);
        printf("\n One node deleted !!\n");
    }
    else
    {
        struct Node *temp=head;

        while(temp->next != NULL)
        {
            temp=temp->next;
        }

        temp->prev->next=NULL;
        free(temp);

        printf("\n One node deleted !!\n");
    }

}
void deleteAnyPosition()
{
    int p;
    printf("Delete position: ");
    scanf("%d",&p);

    if(head == NULL)
        printf("Can't possible\n");

    struct Node *temp=head,*temp1;

    for(int i=0; i<p; i++)
    {
        temp1=temp;
        temp=temp->next;
    }

    temp1->next=temp->next;
    temp->next->prev=temp1;
    free(temp);
    printf(" 1 node deleted! \n");
}

void display()
{
    if(head == NULL)
    {
        printf("\n List is empty !!");
    }
    else
    {
        struct Node *temp=head;

        printf("\n\nList elements are: \n");
        printf(" NULL <---");
        while(temp->next != NULL)
        {
            printf(" %d <====>",temp->data);
            temp=temp->next;
        }
        printf("%d ---> NULL\n",temp->data);
    }

}

bool search()
{
    int item,flag,i=0;
    printf("Enter searching value: ");
    scanf("%d",&item);

    if(head == NULL)
        printf("List is empty\n");
    else
    {
        struct Node *temp=head;
        while(temp != NULL)
        {
            if(temp->data==item)
                return true;
            temp=temp->next;
        }
        return false;
    }
}


int main()
{
    int choice,value,choice1,choice2;

    while(1)
    {
        printf("\n\n----- MENU ------");
        printf("\n 1. Insert");
        printf("\n 2. Delete");
        printf("\n 3. Display");
        printf("\n 4. Search");
        printf("\n 5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Insert value: ");
            scanf("%d",&value);
            while(1)
            {
mainMenu:

                printf("\n\n-- Where you want to insert --");
                printf("\n 1. Insert at began");
                printf("\n 2. Insert at end");
                printf("\n 3. Insert at any position");

                printf("\n Enter your choice: ");
                scanf("%d",&choice1);

                switch(choice1)
                {
                case 1:
                    insertAtBeginning(value);
                    break;
                case 2:
                    insertAtEnd(value);
                    break;
                case 3:
                    insertAnyPosition(value);
                    break;
                default:
                    printf("\n Invalid choice");
                    goto mainMenu;
                }
                goto subMenuEnd;
            }
subMenuEnd:
            break;
        case 2:
            while(1)
            {
mainMenu1:

                printf("\n\n-- Where you want to delete --");
                printf("\n 1. Delete at began");
                printf("\n 2. Delete at end");
                printf("\n 3. Delete at any position");

                printf("\n Enter your choice: ");
                scanf("%d",&choice1);

                switch(choice1)
                {
                case 1:
                    delete_first();
                    break;
                case 2:
                    deleteAtEnd();
                    break;
                case 3:
                    deleteAnyPosition();
                    break;
                default:
                    printf("\n Invalid choice");
                    goto mainMenu1;
                }
                goto subMenuEnd1;
            }
subMenuEnd1:

        case 3:
            display();
            break;
        case 4:
            search()? printf(" Item found \n") : printf(" Item Not found \n");
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\n Invalid choice");
            break;
        }
    }


    return 0;
}

