
//يارا محمود احمد على          Sec:4   BN:45
//منة الله جمال عيد               Sec:4    BN:24
//حياة جمال عبد الهادى         Sec:2    BN:4


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct dateofbirth{
    int day,month,year;
    };

 typedef struct student{
    char name[50];
    int ID;
    struct dateofbirth DOB;
    int score;
}std ;

struct node {
    std data;
    struct node *next;
}*head ,*tail,*pre ,*aft,*studentX;

void createList(int n);

int main()
{
 int n;
    printf("\n welcome to our student information system...\n\n");
    printf("Enter the total number of students: ");
    scanf("%d", &n);
    if(n==0){
        printf("There are no students found");
        }
        else
        {createList(n);}

    return 0;
}


void createList(int n)
{
    struct node *newNode, *temp,*pre,*aft,*studentX;
    int i;
    char x;
    int index;

    head = (struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }
    printf("\n Enter the information of student number 1:\n ");
    printf("The Name\n");
    scanf("%c",&x);
    fgets(head->data.name,sizeof(head-> data .name),stdin);
    printf("ID\n");
    scanf("%d",&head-> data .ID);
    printf("Enter Date of Birth in [D M Y] format: ");
    scanf("%d%d%d",&head-> data .DOB.day,&head-> data .DOB.month,&head-> data .DOB.year);
    printf("the score of the last year\n");
    scanf("%d",&head-> data .score);
    head-> next = NULL;
    temp = head;
    for(i=2; i<= n-1; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        if(newNode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }
        printf("\n Enter the information of student number %d: \n", i);
        printf("the Name\n");
         scanf("%c",&x);
    fgets(newNode-> data .name,sizeof(newNode-> data .name),stdin);
    printf("ID\n");
    scanf("%d",&newNode-> data.ID);
    printf("Enter Date of Birth in [D M Y] format: ");
    scanf("%d%d%d",&newNode-> data.DOB.day,&newNode-> data.DOB.month,&newNode-> data.DOB.year);
    printf("the score of the last year\n");
    scanf("%d",&newNode-> data.score);

        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next ;
    }
 tail = (struct node *)malloc(sizeof(struct node));
            temp->next = tail;
printf("\n Enter the information of student number %d:\n ", i);
        printf("the Name\n");
        scanf("%c",&x);
    fgets(tail-> data .name,sizeof(tail-> data .name),stdin);
    printf("ID\n");
    scanf("%d",&tail->data.ID);
    printf("Enter Date of Birth in [D M Y] format: ");
    scanf("%d%d%d",&tail->data.DOB.day,&tail->data.DOB.month,&tail->data.DOB.year);
    printf("the score of the last year\n");
    scanf("%d",&tail->data.score);

            tail->next = NULL;
            int order;

while (1){
    printf("If you want to insert new student enter number 1:\n If you want to exit the program enter 0 :\n ");
scanf("%d",&order);
if (order ==1){
 int k;
 n=n+1;
studentX = (struct node *)malloc(sizeof(struct node));
studentX ->next =NULL;
printf(" If you want to insert in the begin enter 1 \n If you want to insert in the middle enter 2 \n If you want to insert in the end enter 3 \n");
scanf("%d", &k);
if (k == 1){
studentX ->next = head;
 head = studentX;
 printf("Enter the information of the student that you want to insert \n");

    printf("the Name\n");
    scanf("%c",&x);
    fgets(head-> data .name,sizeof(head-> data .name),stdin);
    printf("ID\n");
    scanf("%d",&head->data.ID);
    printf("Enter Date of Birth in [D M Y] format: ");
    scanf("%d%d%d",&head->data.DOB.day,&head->data.DOB.month,&head->data.DOB.year);
    printf("score\n");
    scanf("%d",&head->data.score);
}
else if(k == 2){

    printf("what is the index ? \n");
    scanf("%d",&index);
     pre = head;
    for(i =0 ; i<index;i++){
     pre ->next =pre ;
    pre->next =aft ;
    studentX->next = aft ;
    pre->next = studentX;}

    printf("Enter the information of the student that you want to insert \n");
    printf("the Name\n");
    scanf("%c",&x);
    fgets(studentX-> data .name,sizeof(studentX-> data .name),stdin);
    printf("ID\n");
    scanf("%d",&studentX->data.ID);
    printf("Enter Date of Birth in [D M Y] format: ");
    scanf("%d%d%d",&studentX->data.DOB.day,&studentX->data.DOB.month,&studentX->data.DOB.year);
    printf("score\n");
    scanf("%d",&studentX->data.score);

    studentX->next=newNode;
}
else if (k == 3){
tail -> next = studentX;
tail =studentX;
printf("Enter the information of the student that you want to insert \n");

    printf("the Name\n");
    scanf("%c",&x);
    fgets(tail-> data .name,sizeof(tail-> data.name),stdin);
    printf("ID\n");
    scanf("%d",&tail->data.ID);
    printf("Enter Date of Birth in [D M Y] format: ");
    scanf("%d%d%d",&tail->data.DOB.day,&tail->data.DOB.month,&tail->data.DOB.year);
    printf("score\n");
    scanf("%d",&tail->data.score);
}
else {
    printf("Not Found");
}}
 else  break;     }
 if(head == NULL)
    {
        printf("List is empty.");
        return;
    }
    temp = head;
    printf("\n\n Desplaying Informations:\n");
        for(int i=0;i<n;i++){
    printf(" The informations of student number %d:\n",i+1);
    printf("The Name:%s",temp->data.name);
    printf("ID: %d\n", temp->data.ID);
    printf("Date of birth : %d/%d/%d \n", temp->data.DOB.day,temp->data.DOB.month,temp->data.DOB.year);
    printf("the score of the last year:  %d\n", temp->data.score);
     temp=temp->next;
    }
    printf("The total number of the students %d",n);
}
