#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct dateofbirth{
    int day,month,year;
    };
 typedef struct student{
    char name[50];
    int ID;
    struct dateofbirth DOB;
    int score;
<<<<<<< HEAD
}std;

//menna gamal
 void readinfo (int  index,std *studentInformation );

int main()
{
    int num;
    int key; //to define the way which we will store with
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

    printf("Do you want to insert new student ?\n");

            allStudents=realloc(allStudents,num+1);
              finalNumber=num+1;

             printf("Enter place that you want to insert in : ");
             scanf("%d",&ins_place);

             if (allStudents == NULL){
                  fprintf(stderr,"Array not allocated!");
                  return 1;
              }
            if (ins_place<=num){
            if(ins_place == 1){

            for(int i=num; i>0;i--){
                    allStudents[i]=allStudents[i-1];
                }
                   readinfo (0,&allStudents[0]);
            }
              else if(ins_place == num+1 ){

            finalNumber=num+1;
             readinfo (num,&allStudents[num]);
            }
            else
            {
                 for(int i=num; i >=ins_place ;i--){
                    allStudents[i]=allStudents[i-1];
                }
                readinfo (ins_place-1,&allStudents[ins_place-1]);
            }

            }
            else
            {
               printf("you entered wrong value\n");
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

        free(allStudents);
    }
    else if(key == 2)
    {
        //linked lists
    }
    else{
        printf("you entered wrong value\n");
    }
=======
}s;
int main()
{
    printf("...welcome to our student information system...\n");
    printf("please enter the student information\n");
    printf("name\n");
    fgets(s.name, sizeof(s.name), stdin);
    printf("ID\n");
    scanf("%d",&s.ID);
    printf("Enter Date of Birth in [D M Y] format: ");
    scanf("%d%d%d",&s.DOB.day,&s.DOB.month,&s.DOB.year);
    printf("score\n");
    scanf("%d",&s.score);
    printf("Displaying Information:\n");
    printf("Name: ");
    printf("%s", s.name);
    printf("ID: %d\n", s.ID);
    printf(" Date of birth : %02d/%02d/%02d: %d\n", s.DOB.day,s.DOB.month,s.DOB.year);
    printf("score:  %d\n", s.score);
>>>>>>> 6d9933a... menna

    return 0;
}

void readinfo (int index , std *studentInformation){
    char temp;
    printf("name of student %d: \n ",(index+1));
    scanf("%c",&temp);   //to avoid compiler to store either enter or null into the string’s first character and string input terminates.
    //scanf("%[^\n]",&studentInformation->name);
    fgets(studentInformation->name , sizeof(studentInformation->name),stdin);
    printf("ID :\n");
    scanf("%d",&studentInformation->ID);
    printf("Enter Date of Birth in [D M Y] format: \n");
    scanf("%d%d%d",&studentInformation->DOB.day,&studentInformation->DOB.month,&studentInformation->DOB.year);
    printf("score of the last year: \n");
    scanf("%d",&studentInformation->score);
    printf("\n");
}

