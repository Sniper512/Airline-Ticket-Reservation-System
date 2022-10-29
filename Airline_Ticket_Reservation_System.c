#include <stdio.h>
void FirstClass(int seats[], int size)
{
    int num = 0;
    printf("Select Seat number (1-30):   ");
    scanf("%d", &num);
    if (num > 30 || num < 1)
    {
        printf("Wrong Seat number.\n");
    }
    else
    {
        num--;
        seats[num] = 1;
    }
}
void EconomyClass(int seats[], int size)
{
    int num = 0;
    printf("Select Seat number (31-100):   ");
    scanf("%d", &num);
    if (num < 31 || num > 100)
    {
        printf("Wrong Seat number.\n");
    }
    else
    {
        num--;
        seats[num] = 1;
    }
}
void Ticket(int seats[], int size)
{
    printf("Select Type of Class:(1 for First Class and 2 for Economy Class).\n");
    int class = 0;
    scanf("%d", &class);
    if (class == 1)
    {
        FirstClass(seats, size);
    }
    else if (class == 2)
    {
        EconomyClass(seats, size);
    }
    else
    {
        printf("Wrong input.\n");
    }
}
void Display(int seats[],int size)
{
    for(int i=0;i<size;i++)
    {
        if(i%10==0)
        {
            printf("\n");
        }
      printf("%d ",seats[i]);   
    }
}
int main()
{
    int seats[100] = {0};
    int flag = 1;
    int input = 0;
    printf("\n***************Welcome to Airline Ticket Reservation System.******************\n");
    while (flag)
    {
        printf("\n1)-Book a Ticket.\n");
        printf("2)-Print Ticket's Availibility Chart.\n");
        printf("3)-Exit\n");
        printf("Choose from above: ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            Ticket(seats, 100);
            break;
        case 2:
        Display(seats,100);
        break;
        default:
            break;
        }
    }

    return 0;
}