#include <stdio.h>

void printTicket(int seat)
{
    printf("\n------------------------------------------\n\n");
    printf("Ticket Booked.\n");
    printf("Ticket Number:  %d\n", seat + 1);
    printf("Ticket Class: ");
    if (seat >= 0 && seat <= 29)
        printf("First Class.\n");
    else
    {
        printf("Economy Class.\n");
    }
}
void FirstClass(int seats[], int size)
{
    int num = 0;
    printf("Select Seat number (1-30):   ");
    scanf("%d", &num);
    if (num > 30 || num < 1)
    {
        printf("Wrong Seat number. Please select seat from your selected class.\n");
    }
    else
    {
        num--;
        if (seats[num] == 0)
        {
            seats[num] = 1;
            printTicket(num);
        }
        else
        {
            printf("Seat is already Booked.Please select another one.\n");
        }
    }
}
void EconomyClass(int seats[], int size)
{
    int num = 0;
    printf("Select Seat number (31-100):   ");
    scanf("%d", &num);
    if (num < 31 || num > 100)
    {
        printf("Wrong Seat number. Please select seat in your selected class.\n");
    }
    else
    {
        num--;
        if (seats[num] == 0)
        {
            seats[num] = 1;
            printTicket(num);
        }
        else
        {
            printf("Seat is already Booked.Please select another one.\n");
        }
    }
}
void CancelTicket(int seats[], int size)
{
    int class = 0;
    int seat = 0;
    printf("\nLets Cancel a Ticket for you.\n");
    printf("1)-First class\n");
    printf("2)-Economy class\n");
    printf("Please select the Class of Seat you want to cancel: ");
    scanf("%d", &class);
    if(class==1)
    {
        printf("First class selected.\n");
    }
    else if(class==2)
    {
       printf("Economy class selected.\n");
    }
    else if (class != 1 && class != 2)
    {
        printf("Wrong class Entered. Please select correct class.");
        return;
    }
    printf("Please Enter the Seat number of Ticket you want to cancel: ");
    scanf("%d", &seat);
    seat--;
    if ((class == 1 && seat > 30) || (class == 1 && seat < 0))
    {
        printf("\nSeat of Wrong Class Entered. Please select correct seat.");
        return;
    }
    if (seats[seat] == 0)
    {
        printf("\nSeat is already not been Booked. Please try again and Enter the booked seat number.\n");
    }
    else if (seats[seat] == 1)
    {
        seats[seat] = 0;
        printf("--------------------------------\n");
        printf("Seat is Successfully Canceled.");
    }
}
void Ticket(int seats[], int size)
{
    printf("\nLets Book a Ticket for You.\n");
    printf("Enter 1 for First Class\n");
    printf("Enter 2 for Economy Class.\n");
    printf("Select Type of Class: ");
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
        printf("Wrong type of Class selected. Please Try again and select from above. Thanks!\n");
    }
}
void Display(int seats[], int size)
{
    printf("\nThe Airline Seat Availibility Chart is:\n");
    for (int i = 0; i < size; i++)
    {
        if (i % 10 == 0)
        {
            printf("\n");
        }
        printf("%d ", seats[i]);
    }
}
int main()
{
    int seats[100] = {0};
    int flag = 1;
    int input = 0;
    printf("\n***************  Welcome to Airline Ticket Reservation System.  ******************\n");
    while (flag)
    {
        printf("\n------------------------------------------");
        printf("\nAirline Ticket Reservation System Options: \n");
        printf("\n1)-Book a Ticket.\n");
        printf("2)-Cancel a Booked Ticket.\n");
        printf("3)-Print Ticket's Availibility Chart.\n");
        printf("4)-Exit\n");
        printf("Choose from above: ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            Ticket(seats, 100);
            break;
        case 2:
            CancelTicket(seats, 100);
            break;
        case 3:
            Display(seats, 100);
            break;
        case 4:
            printf("Program Successfully closed.");
            flag = 0;
            break;
        default:
            printf("Wrong Input. Please Select from options availible above.\n");
            break;
        }
    }

    return 0;
}