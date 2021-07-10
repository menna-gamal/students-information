#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>

struct dateofbirth{
    int day,month,year;
    };
 typedef struct student{
    char name[50];
    int ID;
    struct dateofbirth DOB;
    int score;
}std;

struct node {
    std data;
    struct node *next;
}*head ,*tail,*pre ,*aft,*studentX;

void createList(int n);

 void readinfo (int  index,std *studentInformation );

int main()
{
    int num;
    int key;  //to define the way which we will store with
    int ins;   // to know the user will insert or not
    int ins_place;
    int finalNumber;
    printf("...welcome to our student information system...\n\n");

    printf("please enter the students number\n");
    scanf("%d", &num);
    finalNumber = num;
    printf("Do you want to store information using dynamic array or linked lists?\n");
    printf("If you want dynamic array enter 1\n");
    printf("If you want linked lists enter 2\n");
    scanf("%d",&key);

    if (key==1) {
    std* allStudents = (std*)malloc( num*sizeof(std));
    if (allStudents == NULL){
      fprintf(stderr,"Array not allocated!");
      return 1;
    }
    for (int i=0; i< num ;i++){
    readinfo (i,&allStudents[i]);
    }
    printf("Data stored successfully\n\n");
    while(1){

    printf("Do you want to insert new student ?\n");
    printf("1:Insert student \n2:Exit \n");
    scanf("%d",&ins);

    if (ins==1){
            finalNumber += 1;
            allStudents=realloc(allStudents,finalNumber);

             printf("Enter place that you want to insert in : ");
             scanf("%d",&ins_place);

             if (allStudents == NULL){
                  fprintf(stderr,"Array not allocated!");
                  return 1;
              }
            if (ins_place<=finalNumber){
            if(ins_place == 1){
                    clock_t t;
            t = clock();

            for(int i=finalNumber-1; i>0;i--){
                    allStudents[i]=allStudents[i-1];
                }
                   readinfo (0,&allStudents[0]);
                   t = clock() -t;
                   double time_taken = ((double)t)/CLOCKS_PER_SEC;
            printf("Insertion took %f seconds to execute\n",time_taken);
            }
              else if(ins_place == finalNumber ){
                  clock_t t;
            t = clock();
            finalNumber=num+1;
             readinfo (finalNumber -1,&allStudents[finalNumber -1]);
                 t = clock() -t;
                   double time_taken = ((double)t)/CLOCKS_PER_SEC;
            printf("Insertion took %f seconds to execute\n",time_taken);
            }
            else
            {
                 clock_t t;
            t = clock();
                 for(int i=finalNumber-1; i >=ins_place ;i--){
                    allStudents[i]=allStudents[i-1];
                }
                readinfo (ins_place-1,&allStudents[ins_place-1]);
                    t = clock() -t;
                   double time_taken = ((double)t)/CLOCKS_PER_SEC;
            printf("Insertion took %f seconds to execute\n",time_taken);
            }

            }
            else{
                 printf("you entered wrong value\n");
            }
    }
    else if(ins == 2){
                        break;
                     }
            else
                {
               printf("you entered wrong value\n\n");
                }
    }
    printf("\n\n Displaying Informations:\n");
    for (int i=0; i < finalNumber ;i++){
    printf("Information of student %d \n\n",i+1);
    printf("Name:%s \n", allStudents[i].name);
    printf("ID :%d \n",allStudents[i].ID);
    printf(" Date of Birth in [D M Y] format: %d/ %d/ %d \n",allStudents[i].DOB.day,allStudents[i].DOB.month,allStudents[i].DOB.year);
    printf("score of the last year: %d\n",allStudents[i].score);
    printf("\n");
    }
        printf("\nThe total number of the students %d\n\n",finalNumber);
        printf("size of structure =%d\n\n",finalNumber*sizeof(std));
        free(allStudents);
    }
    else if(key == 2)
    {
       createList(num);
    }
    else{
        printf("you entered wrong value\n");
    }
    return 0;
}

void readinfo (int index , std *studentInformation){
    char temp;
    printf("name of student %d: \n ",(index+1));
    scanf("%c",&temp);   //to avoid compiler to store either enter or null into the string’s first character and string input terminates.
    fgets(studentInformation->name , sizeof(studentInformation->name),stdin);
    printf("ID :\n");
    scanf("%d",&studentInformation->ID);
    printf("Enter Date of Birth in [D M Y] format: \n");
    scanf("%d%d%d",&studentInformation->DOB.day,&studentInformation->DOB.month,&studentInformation->DOB.year);
    printf("score of the last year: \n");
    scanf("%d",&studentInformation->score);
    printf("\n");
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
        clock_t t;
t = clock();
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
    t = clock() -t;
                   double time_taken = ((double)t)/CLOCKS_PER_SEC;
            printf("Insertion took %f seconds to execute\n",time_taken);
}
else if(k == 2){
     clock_t t;
t = clock();
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
t = clock() -t;
                   double time_taken = ((double)t)/CLOCKS_PER_SEC;
            printf("Insertion took %f seconds to execute\n",time_taken);
}
else if (k == 3){
         clock_t t;
t = clock();
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
    t = clock() -t;
                   double time_taken = ((double)t)/CLOCKS_PER_SEC;
            printf("Insertion took %f seconds to execute\n",time_taken);
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
    printf("\n\n Displaying Informations:\n");
        for(int i=0;i<n;i++){
    printf(" The informations of student number %d:\n",i+1);
    printf("The Name:%s",temp->data.name);
    printf("ID: %d\n", temp->data.ID);
    printf("Date of birth : %d/%d/%d \n", temp->data.DOB.day,temp->data.DOB.month,temp->data.DOB.year);
    printf("the score of the last year:  %d\n", temp->data.score);
     temp=temp->next;
    }
    printf("The total number of the students %d\n\n",n);
    printf("size of structure = %d\n\n ",n*sizeof(std));
    printf("size of node %d",sizeof(struct node));
}
