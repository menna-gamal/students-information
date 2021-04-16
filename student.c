#include <stdio.h>
#include <stdlib.h>
struct dateofbirth{
    int day,month,year;
    };
struct student{
    char name[50];
    int ID;
    struct dateofbirth DOB;
    int score;
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

    return 0;
}
