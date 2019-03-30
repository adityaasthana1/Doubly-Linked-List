#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<windows.h>
struct node
{
    struct node *prev ;
    int data ;
    struct node *next;
};
struct node *addition(struct node *start);
struct node *deletion(struct node *start);
int count_node(struct node *start);
void display_list(struct node *start);
void SetColor(int ForgC);
int main()
{
    int choice,count ;
    struct node *start = NULL;
    while(1)
    {
        SetColor(11);
        printf("\n\n1.Addition\n2.Deletion\n3.Count nodes\n4.Display List\n\n");
        scanf("%d", &choice );
        switch(choice)
        {
        case 1 :
            start = addition(start);
            break ;
        case 2 :
            start = deletion(start);
            break ;
        case 3 :
            count = count_node(start);
            printf("The size of the list is %d", count+1);
            break ;
        case 4 :
            display_list(start);
            break ;
        default :
            printf("\nEnter a valid choice.");
            break;
        }
    }
    system("cls");

    return 0 ;
}
struct node *addition(struct node *start)
{
    SetColor(12);
    int data, choice,position,i,node_data;
    struct node *p = start ;
    struct node *temp ;
    printf("1.Add at beginning\n2.Add at end.\n3.Add at position\n4.Add after.\n5.Add before. \n");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1 :
        printf("\nEnter the data : ");
        scanf("%d",&data);
        if(start==NULL)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = data ;
            temp->prev = NULL ;
            temp->next = NULL ;
            return temp ;
            break;
        }
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->prev = NULL ;
        temp->next = start ;
        start->prev = temp;
        start = temp;
        printf("\nNode Successfully Added\n");
        return start ;
        break ;
    case 2 :
        printf("\nEnter the data : ");
        scanf("%d",&data);
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data ;
        if(start == NULL)
        {
            start = temp ;
            temp->prev = NULL ;
            temp->next = NULL ;
            printf("\nSuccessfully Added.\n");
            return start ;
        }
        while(p->next!=NULL)
            p = p->next ;
        temp->next = NULL ;
        temp->prev = p ;
        p->next = temp ;
        return start ;
        break;
    case 3:
        printf("\nEnter the data : ");
        scanf("%d",&data);
        temp = (struct node *)malloc(sizeof(struct node));
        if(start==NULL)
        {
            temp->data = data;
            temp->prev = NULL ;
            temp->next = NULL ;
            printf("\nNode Successfully Added\n");
            return temp ;
            break;
        }
        else
        {
            printf("\nEnter the position : ");
            scanf("%d", &position);
            for(i=0 ; i < position-2 ; i++)
                p = p->next ;
            temp->data=data;
            temp->next = p->next;
            temp->prev = p ;
            p->next = temp ;
            printf("\nNode Successfully Added.\n");
            return start;
            break;
        }
    case 4:
        printf("\nEnter the data : ");
        scanf("%d",&data);
        temp = (struct node *)malloc(sizeof(struct node));
        if(start==NULL)
        {
            temp->data = data;
            temp->prev = NULL ;
            temp->next = NULL ;
            printf("\nNode Successfully Added\n");
            return temp ;
            break;
        }
        printf("\n\nInput node data.");
        scanf("%d",&node_data);
        while(p->data!=node_data);
        p = p->next ;
        temp->data = data;
        temp->next = p->next ;
        temp->prev = p ;
        p->next = temp ;
        return start;
        break;
    default :
        printf("\n\nEnter a valid choice.");
        return start;
        break;
    }
};
struct node *deletion(struct node *start)
{
    struct node *temp ;
    struct node *p = start;
    int choice ;
    int position,i,node_data ;
    printf("\n1.Delete first node.\n2.Delete last node\n3.Delete node at position.\n4.Delete by data.\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1 :
        if(start->next==NULL)
        {
            temp = start ;
            start = NULL ;
            free(temp);
            printf("\nNode successfully deleted.");
            return start ;
        }
        temp = start ;
        start = start->next;
        start->prev = NULL ;
        printf("\nNode successfully deleted.\n");
        return start ;
        break;
    case 2 :
        if(start == NULL)
        {
            printf("\nEmpty List\n");
            return start ;
        }
        if(start->next==NULL)
        {
            temp = start ;
            start = NULL ;
            free(temp);
            printf("Node Successfully deleted");
            return start;
        }
        while(p->next!=NULL)
            p = p->next;
        temp = p ;
        p->prev->next = NULL ;
        free(temp);
        printf("\nNode successfully deleted.\n");
        return start ;
        break ;
    case 3:
        printf("\nEnter the position.  ") ;
        scanf("%d",&position);
        if(position > count_node(start))
        {
            printf("\nOut of bound.\n");
            return start ;
        }
        if(start==NULL)
        {
            printf("\nEmpty List.\n");
            return start ;
        }
        if(position==1)
        {
            temp = start ;
            start = start->next ;
            free(temp);
            printf("successfully deleted.");
            return start ;
        }
        for(int i = 0 ; i < position-1 ; i++)
            p = p->next;
        if(p->next==NULL)
        {
            temp = p ;
            p->prev->next = NULL ;
            free(temp);
            printf("\nsuccessfully deleted.\n");
            return start;
        }
        temp = p ;
        p->prev->next = p ->next ;
        p->next->prev = p->prev;
        free(temp);
        printf("\nsuccessfully deleted.\n");
        return start ;
        break ;
    case 4:
        printf("\nEnter the node data  ");
        scanf("%d",&node_data);
        if(start == NULL)
        {
            printf("\nEmpty List.\n");
            return start ;
        }
        if(start->data == node_data && start->next==NULL);
        {
            temp = start ;
            start = NULL ;
            free(temp);
            printf("\nSuccessfully Deleted.\n");
            return start ;
        }
        printf("\nEnter the node data.  ");
        scanf("%d",&node_data);
        while(p->next!=NULL)
        {
            if(p->next->data==node_data)
            {
                temp = p->next ;
                p->next = p->next->next;
                p->next->prev = p ;
                free(temp);
                printf("\nsuccessfully deleted.\n");
                return start;
            }
        }
        printf("\ndata not found.\n");
        return start ;
    default:
        printf("\Enter a valid option.");
        return start ;
        break ;

    }
};

void display_list(struct node *start)
{
    printf("\n\n");
    if(start==NULL)
    {
        printf("\nEmpty List\n");
        return ;
    }
    struct node *p = start ;
    while(p!=NULL)
    {
        printf(" %d <-> ", p->data);
        p = p->next;
    }
}
int count_node(struct node *start)
{
    if(start==NULL)
    {
        printf("\nEmpty List.\n");
        return ;
    }
    int count = 0 ;
    struct node *p = start ;
    while(p->next!=NULL)
    {
        p = p->next;
        count++;
    }
    return count ;
}

void SetColor(int ForgC)
{
    WORD wcolor ;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi ;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wcolor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0f);
        SetConsoleTextAttribute(hStdOut, wcolor);
    }
    return ;
}

