/* The prototype for this project is as follws
1.Include files & structure & functions.
2.variable declartion & then ask wheteher it is user or admin using switch
3. User:- 1.Run loop untill user says no. And in loop add the functions
           Then exist
4. Admin:- 1.ASk a pass & validate
        2. Run loop untill admin says no
5. Define function of admin*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void view_booking();
void make_booking();
void find_room();
void find_name();
void checkout_guest();
void timing();
void view_room();

FILE *view;
FILE *enter;
FILE *fp;
FILE *time;

struct hotel
{
    char name[25];
    char room[3];
    char plan[6];
    char aadhar_no[20];
    char fast[5];
};

int main()
{
    int c1, c2, c3;
    struct hotel h;
    char user_entry[5] = {'y'};
    char admin_entry[5] = {'y'};

    printf("\n\n\t\t*******************************************************\n");
    printf("\t\t*                                                     *\n");
    printf("\t\t*       ------------------------------------          *\n");
    printf("\t\t*            WELCOME TO Rang Tarang Hotel             *\n");
    printf("\t\t*       ------------------------------------          *\n");
    printf("\t\t*                                                     *\n");
    printf("\t\t*******************************************************\n\n\n");

    printf(">>>>>>>>>>>>Enter 1 for admin access<<<<<<<<<<<\n");
    printf(">>>>>>>>>>>>Enter 2 for user access<<<<<<<<<<<<<\n");
    scanf("%d", &c1);

    switch (c1)
    {
    case 1:
    {
        char entry[20];
        char copy[20];
        FILE *pass;
        printf("Hello admin!!Please enter your password to continue----->");
        char ch;
        int i = 0;
        while (1)
        {
            ch = getch();
            if (ch == 13)
            {
                entry[i] = '\0';
                break;
            }
            else if (ch == 8)
            {
                if (i > 0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            else if (ch == 9 || ch == 32)
            {
                continue;
            }
            else
            {
                entry[i] = ch;
                i++;
                printf("*");
            }
        }
        pass = fopen("pass.txt", "r");
        fscanf(pass, "%s", copy);
        if (strcmp(entry, copy) == 0)
        {
            printf("\nYour are successfully logined!!!!!\n");
            while (admin_entry[0] == 'y')
            {
                printf("\nEnter:-\n1 to view booking requests\n2 to view available rooms\n3 to make booking\n4 to do the chekout of guest\n");
                printf("5 to find details by room number\n6 to find details using the name\n7 to add time\n");
                scanf("%d", &c2);
                switch (c2)
                {
                case 1:
                {
                    view_booking();
                    break;
                }
                case 2:
                {
                    view_room();
                    break;
                }
                case 3:
                {
                    make_booking();
                    break;
                }
                case 4:
                {
                    checkout_guest();
                    break;
                }
                case 5:
                {
                    find_room();
                    break;
                }
                case 6:
                {

                    find_name();
                    break;
                }
                case 7:
                {
                    timing();
                    break;
                }
                default:
                {
                    printf("Invalid choice!!!!!!Please enter correct number\n");
                    break;
                }
                }
                printf("\nPress y if you want to continue & if no then press n\n");
                scanf("%s", admin_entry);
                if (strcmp(admin_entry, "y") == 0)
                {
                    continue;
                }

                else if (strcmp(admin_entry, "n") == 0)
                {
                    printf("Exiting! Thank you to use this system\n");
                }
                else
                {
                    printf("Invalid choice\n");
                }
            }
        }
        else
            printf("\nSorry password is wrong!!!!!Try Again\n");

        break;
    }
    case 2:
    {
        while (user_entry[0] == 'y')
        {
            printf("\n\n####### Hello User!We hope your day is good ########\n");
            printf("Enter:\n1 for checking available rooms\n2 for Making Booking Request\n3 for Adding the time of leaving & coming to hotel\n");
            scanf("%d", &c3);

            switch (c3)
            {
            case 1:
            {
                printf("\nFollowing are the plans in hotel\n");
                FILE *ptr;
                char c;
                ptr = fopen("plan.txt", "r");
                c = fgetc(ptr);
                while (c != EOF)
                {
                    printf("%c", c);
                    c = fgetc(ptr);
                }
                fclose(ptr);
                view_room();
                break;
            }
            case 2:
            {
                printf("\nEnter your full name----->\n");
                fflush(stdin);
                gets(h.name);
                printf("\nEnter room number which you want----->\n");
                fflush(stdin);
                gets(h.room);
                printf("\nEnter the plan which you want to take----->\n");
                fflush(stdin);
                gets(h.plan);
                printf("\nEnter the Aaadhar No with space like 2219 3645 1256----->\n");
                fflush(stdin);
                gets(h.aadhar_no);
                printf("\nEnter yes if breakfast is included or no if not included----->\n");
                fflush(stdin);
                gets(h.fast);

                fp = fopen("request.txt", "a");
                fprintf(fp, "\n%s,%s,%s,%s,%s,", h.name, h.room, h.plan, h.aadhar_no, h.fast);

                fclose(fp);
                printf("Successfuly request is recorded\n");
                break;
            }
            case 3:
            {
                timing();
                break;
            }

            default:
            {
                printf("Invalid choice\n");
                break;
            }
            }
            printf("\nPress y if you want to continue & if no then press n\n");
            scanf("%s", user_entry);
            if (strcmp(user_entry, "y") == 0)
            {
                continue;
            }

            else if (strcmp(user_entry, "n") == 0)
            {
                printf("Exiting! Thank you to use this system\n");
            }
            else
            {
                printf("Invalid choice\n");
            }
            break;
        }
    }
    }

    return 0;
}
//Add the timing
void timing()
{
    char choice, number[5];
    int ch;
    int a = 0;
    struct hotel h;
    time = fopen("timing.txt", "a");
    enter = fopen("booking.txt", "r");
    printf("\nEnter:-\nL if your are living\nc if your coming to the hotel\n");
    fflush(stdin);
    scanf("%c", &choice);
    printf("\nEnter your room number------>");
    scanf("%s", number);
    do
    {

        fscanf(enter, "%[^,]%*c", h.name);
        fscanf(enter, "%[^,]%*c", h.room);
        fscanf(enter, "%[^,]%*c", h.plan);
        fscanf(enter, "%[^,]%*c", h.aadhar_no);
        fscanf(enter, "%[^,]%*c", h.fast);
        if ((strcmp(number, h.room)) == 0)
        {
            a = 1;
            if (choice == 'l' || choice == 'L')
            {

                fprintf(time, "\n%s*****%s******* %s****** Leave", __DATE__, __TIME__, number);
                printf("Time is aaded successfully\n");
            }
            else if (choice == 'c' || choice == 'C')
            {
                fprintf(time, "\n%s****** %s****** %s****** Come", __DATE__, __TIME__, number);
                printf("Time is aaded successfully\n");
            }
            else
            {
                printf("\nInvalid Choice!\n");
                printf("Enter only L or C!!!!!!!!!!!\n");
            }
            break;
        }
        else
        {
            continue;
        }

        /*printf("%s\n ",h.name);
        printf("%s\n ",h.room);
        printf("%s\n",h.plan);
        printf("%s\n",h.aadhar_no);
        printf("%s\n",h.fast);*/

    } while ((ch = getc(enter)) != EOF);
    if (a == 0)
    {
        printf("%s room number is not booked by anyone!!!!!\n", number);
        printf("Enter the correct room number\n");
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    }

    fclose(time);
}
//To view room
void view_room()
{

    printf("\n\nFollowing are the available rooms \n");
    char c[5];
    int a = 0;
    view = fopen("rooms.txt", "r");
    while (fscanf(view, "%s", c) != -1)
    {
        printf("%s\t", c);
        a++;
        if (a % 10 == 0)
        {
            printf("\n");
        }
    }
    fclose(view);
}
//To view booking request
void view_booking()
{
    char c;
    fp = fopen("request.txt", "r");
    printf("\n********Requests for booking********\n\n");
    printf("Name of the guest ### Room Number ### Plan Taken ### Aadhar Number ### Breakfast icluded\n\n");
    c = fgetc(fp);
    while (c != EOF)
    {
        printf("%c", c);
        c = getc(fp);
    }
    printf("\n");
    fclose(fp);
}
//To make booking
void make_booking()
{
    FILE *tmp1;
    FILE *tmp2;
    int ch;
    int a = 0;
    char number[5];
    struct hotel h;
    printf("Enter the name of guest------>\n");
    fflush(stdin);
    gets(h.name);
    printf("Enter the room number------->\n");
    fflush(stdin);
    gets(h.room);
    view = fopen("rooms.txt", "r");
    do
    {

        fscanf(enter, "%s", number);

        if ((strcmp(number, h.room)) == 0)
        {
            a = 1;
            printf("\nEnter the guset name----->\n");
            fflush(stdin);
            gets(h.name);
            printf("\nEnter the room number----->\n");
            fflush(stdin);
            gets(h.room);

            printf("\nEnter the plan----->\n");
            fflush(stdin);
            gets(h.plan);
            printf("\nEnter the aadhar number----->\n");
            fflush(stdin);
            gets(h.aadhar_no);
            printf("\nEnter yes if brekfast is included or if not then enter no----->\n");
            fflush(stdin);
            gets(h.fast);

            enter = fopen("booking.txt", "a");
            fprintf(enter, "\n%s,%s,%s,%s,%s,", h.name, h.room, h.plan, h.aadhar_no, h.fast);
            printf("\nBooking is done");
            fclose(enter);

            //Removing the room from availbale
            char remove_room[3];
            strcpy(remove_room, h.room);
            tmp2 = fopen("tmp2.txt", "a");
            view = fopen("rooms.txt", "r");
            while ((fscanf(view, "%s", h.room) != -1))
            {
                if (strcmp(remove_room, h.room) != 0)
                {
                    fprintf(tmp2, "\n%s", h.room);
                }
            }
            fclose(view);
            fclose(tmp2);
            remove("rooms.txt");
            rename("tmp2.txt", "rooms.txt");
        }
        else
        {
            continue;
        }

        /*printf("%s\n ",h.name);
        printf("%s\n ",h.room);
        printf("%s\n",h.plan);
        printf("%s\n",h.aadhar_no);
        printf("%s\n",h.fast);*/

    } while ((ch = getc(enter)) != EOF);
    if (a == 0)
    {
        printf("%s room number is not available!!!!!!!\n", h.room);
    }
}
//To find details using the name
void find_name()
{
    char entered_name[20];
    int a = 0;
    int ch;
    struct hotel h;
    printf("\nEnter guest name to find -->\n");
    fflush(stdin);
    gets(entered_name);

    enter = fopen("booking.txt", "a+");
    do
    {

        fscanf(enter, "%[^,]%*c", h.name);
        fscanf(enter, "%[^,]%*c", h.room);
        fscanf(enter, "%[^,]%*c", h.plan);
        fscanf(enter, "%[^,]%*c", h.aadhar_no);
        fscanf(enter, "%[^,]%*c", h.fast);
        if ((strcmp(entered_name, h.name)) == 0)
        {
            a = 1;
            printf("\nGuest found\n");
            printf("Details are as follows:-\n");
            printf("Name of guest is:-%s\n", h.name);
            printf("Room Number is:-%s\n", h.room);
            printf("Plan taken by guest:-%s\n", h.plan);
            printf("Aadhar Number is:-%s\n", h.aadhar_no);
            printf("Breakfast is included or not:-%s\n", h.fast);
            break;
        }
        else
        {
            continue;
        }

        /* printf("%s\n ",h.name);
        printf("%s\n ",h.room);
        printf("%s\n",h.wifi_plan);
        printf("%s\n",h.aadhar_no);
        printf("%s\n",h.fast);*/

    } while ((ch = getc(enter)) != EOF);
    if (a == 0)
    {
        printf("Guest does not found!!!!!\n");
    }

    fclose(enter);
}
//To find using the room
void find_room()
{
    char room[4];
    int ch;
    int a = 0;
    struct hotel h;
    printf("\nEnter the room number---->\n");
    fflush(stdin);
    gets(room);
    enter = fopen("booking.txt", "a+");
    do
    {

        fscanf(enter, "%[^,]%*c", h.name);
        fscanf(enter, "%[^,]%*c", h.room);
        fscanf(enter, "%[^,]%*c", h.plan);
        fscanf(enter, "%[^,]%*c", h.aadhar_no);
        fscanf(enter, "%[^,]%*c", h.fast);
        if ((strcmp(room, h.room)) == 0)
        {
            a = 1;
            printf("\nGuest found\n");
            printf("Details are as follows:-\n");
            printf("Name of guest is:-%s\n", h.name);
            printf("Room Number is:-%s\n", h.room);
            printf("Plan taken:-%s\n", h.plan);
            printf("Aadhar Number is:-%s\n", h.aadhar_no);
            printf("Breakfast is included or not:-%s\n", h.fast);
            break;
        }
        else
        {
            continue;
        }

        /*printf("%s\n ",h.name);
        printf("%s\n ",h.room);
        printf("%s\n",h.plan);
        printf("%s\n",h.aadhar_no);
        printf("%s\n",h.fast);*/

    } while ((ch = getc(enter)) != EOF);
    if (a == 0)
    {
        printf("Guest does not found!!!!!\n");
    }

    fclose(enter);
}
//Making Checkout
void checkout_guest()
{
    struct hotel h;
    char name[25];
    char room[3];
    FILE *tmp;
    int ch, a = 0;
    printf("\nEnter the name to checkout------>\n");
    fflush(stdin);
    gets(name);
    printf("\nEnter the room number to checkout------>\n");
    fflush(stdin);
    gets(room);
    enter = fopen("booking.txt", "r");
    do
    {
        fscanf(enter, "%[^,]%*c", h.name);
        fscanf(enter, "%[^,]%*c", h.room);
        fscanf(enter, "%[^,]%*c", h.plan);
        fscanf(enter, "%[^,]%*c", h.aadhar_no);
        fscanf(enter, "%[^,]%*c", h.fast);
        if (strcmp(room, h.room) == 0)
        {
            a = 1;
            //Removing Name from the booking
            tmp = fopen("tmp.txt", "a+");
            do
            {
                fscanf(enter, "%[^,]%*c", h.name);
                fscanf(enter, "%[^,]%*c", h.room);
                fscanf(enter, "%[^,]%*c", h.plan);
                fscanf(enter, "%[^,]%*c", h.aadhar_no);
                fscanf(enter, "%[^,]%*c", h.fast);
                if ((strcmp(h.name, name)) != 0)
                {
                    fprintf(tmp, "\n%s,%s,%s,%s,%s,", h.name, h.room, h.plan, h.aadhar_no, h.fast);
                    continue;
                }
                /*else
        {
            break;
        }*/
            } while ((ch = fgetc(enter)) != EOF);
            fclose(enter);
            fclose(tmp);
            remove("booking.txt");
            rename("tmp.txt", "booking.txt");
            printf("\nCheckout is successful\n");

            //Adding room number
            view = fopen("rooms.txt", "a");
            fprintf(view, "\n%s", room);
            printf("\nRoom Number %s is now available\n", room);
            break;
        }
        else
        {
            continue;
        }
    } while ((ch = fgetc(enter)) != EOF);
    if (a == 0)
    {
        printf("%s room number is not booked by anyone!!!!\n", room);
        printf("Enter the correct room number\n");
    }
}