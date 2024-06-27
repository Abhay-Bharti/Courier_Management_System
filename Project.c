#include <stdio.h>
#include <string.h>

void login();
int menuadministrator();
int menuclient();
void addParcel();
void updateParcels();
void searchParcel();
void markplaced();
void displayParcels();
void postman();

#define MAX_LEN 100 // define maximum length of name and address
int id = 0;         // initialize parcel ID to 0 global variable

int main()
{
    login();
    return 0;
}

void login()
{
    long long int arr[][50] = {{1234567890, 1234}, {9876543210, 2345}};
    long long int a, c;
    printf("ENTER USERNAME: ");
    scanf("%lld", &a);
    printf("ENTER PASSWORD: ");
    scanf("%lld", &c);
    int b = 100, i;
    for (i = 0; i <= 1; i++)
    {
        if (arr[i][0] == a)
        {
            b = i;
            break;
        }
    }
    if (c == arr[b][1])
    {
        if (arr[b][0] == arr[1][0])
        {
            printf("---- YOU ARE LOGGED IN AS ADMINISTRATOR ----\n");
            menuadministrator();
        }
        else if (arr[b][0] == arr[0][0])
        {
            printf("---- YOU ARE LOGGED IN AS CLIENT ----\n");
            menuclient();
        }
    }
    else
        printf("WRONG USERNAME OR PASSWORD!");
}

int menuadministrator()
{
    int choice;
    do
    {
        printf("\n-------------------------\n");
        printf("Courier Management System\n");
        printf("-------------------------\n");
        printf("1. Add Parcel\n");
        printf("2. Update Parcel\n");
        printf("3. Search Parcel\n");
        printf("4. Display Parcels\n");
        printf("5. Mark Parcel as Delivered\n");
        printf("6. Postman Details\n");
        printf("7. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);


        switch (choice)
        {
        case 1:
            addParcel();
            break;
        case 2:
            updateParcels();
            break;
        case 3:
            searchParcel();
            break;
        case 4:
            displayParcels();
            break;
        case 5:
            markplaced();
            break;
        case 6:
            postman();
            break;
        case 7:
            printf("GOODBYE!\n"); // exit the program
            return 0;
        default:
            printf("INVALID CHOICE, PLEASE TRY AGAIN!.\n");
        }
    } while (1); // infinite loop until user chooses to exit
}

int menuclient()
{
    int choice;
    do
    {
        printf("Courier Management System\n");
        printf("-------------------------\n");
        printf("1. Add Parcel\n");
        printf("2. Search Parcel\n");
        printf("3. Display Parcels\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            addParcel();
            break;
        case 2:
            searchParcel();
            break;
        case 3:
            displayParcels();
            break;
        case 4:
            printf("GOODBYE!\n"); // exit the program
            return 0;
        default:
            printf("INVALID CHOICE, PLEASE TRY AGAIN.\n");
        }
    } while (1);
}

struct Parcel
{
    int id;
    char sender_name[50];
    char receiver_name[50];
    char sender_address[100];
    char receiver_address[100];
    char status[20];
};

int num_parcels = 0;
struct Parcel parcels[10];

void addParcel()
{
    if (num_parcels >= 10)
    {
        printf("MAX NUMBER OF PARCELS REACHED\n");
        return;
    }

    struct Parcel parcel;
    parcel.id = num_parcels + 1;

    printf("ENTER SENDER NAME: ");
    fflush(stdin);
    gets(parcel.sender_name);

    printf("ENTER SENDER ADDRESS: ");
    fflush(stdin);
    gets(parcel.sender_address);

    printf("ENTER RECIEVER NAME: ");
    fflush(stdin);
    gets(parcel.receiver_name);

    printf("ENTER RECIEVER ADDRESS: ");
    fflush(stdin);
    gets(parcel.receiver_address);

    strcpy(parcel.status, "NOT DELIEVERED");

    parcels[num_parcels] = parcel;
    num_parcels++;

    printf("PARCEL ADDED SUCCESSFULLY WITH ID %d\n", parcel.id);
}

void updateParcels()
{
    int id, b, i;
    char newentery[40];
    printf("ENTER PARCEL ID: ");
    scanf("%d", &id);
    printf("ENTER CHOICE: \n\n1. RECIEVER NAME\n2. RECIEVER ADDRESS\n");
    scanf("%d", &b);
    if (b == 1)
    {
        printf("ENTER RECEIVER NAME: ");
        fflush(stdin);
        gets(newentery);
        for (i = 0; i < num_parcels; i++)
        {
            if (parcels[i].id == id)
            {
                strcpy(parcels[i].receiver_name, newentery);
                printf("MODIFICATIONS SUCCESSFULL\n", id);
                return;
            }
        }
    }
    else if (b == 2)
    {
        printf("ENTER RECEIVER ADDRESS: ");
        fflush(stdin);
        gets(newentery);
        for (i = 0; i < num_parcels; i++)
        {
            if (parcels[i].id == id)
            {
                strcpy(parcels[i].receiver_address, newentery);
                printf("MODIFICATIONS SUCCESSFULL\n", id);
                return;
            }
            else
                printf("INVALID INPUT!\n");
        }
    }
}

void searchParcel()
{
    if (num_parcels == 0)
    {
        printf("NO PARCELS TO BE DISPLAYED\n");
        return;
    }
    else
    {
        int i, b, a;
        printf("ENTER PARCEL ID: ");
        scanf("%d", &a);
        printf("ID\tSender Name\tSender Address\tReceiver Name\tReceiver Address\tStatus\n");
        for (i = 0; i < num_parcels; i++)
        {
            if (parcels[i].id == a)
            {
                b = i;
                break;
            }
        }
        printf("%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", parcels[b].id, parcels[b].sender_name, parcels[b].sender_address, parcels[b].receiver_name, parcels[b].receiver_address, parcels[b].status);
    }
}

void displayParcels()
{
    if (num_parcels == 0)
    {
        printf("NO PARCELS TO BE DISPLAYED\n");
        return;
    }
    else
    {
        int i;
        printf("ID\tSender Name\tSender Address\tReceiver Name\tReceiver Address\tStatus\n");
        for (i = 0; i < num_parcels; i++)
        {
            printf("%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", parcels[i].id, parcels[i].sender_name, parcels[i].sender_address, parcels[i].receiver_name, parcels[i].receiver_address, parcels[i].status);
        }
    }
}

void markplaced()
{
    int id, i;
    printf("ENTER PARCEL ID TO BE MARK AS DELIEVERED: ");
    scanf("%d", &id);

    for (i = 0; i < num_parcels; i++)
    {
        if (parcels[i].id == id)
        {
            strcpy(parcels[i].status, "DELIEVERED");
            printf("PARCEL WITH ID %d MARK AS DELIEVERED\n", id);
            return;
        }
    }

    printf("NO PARCEL FOUND WITH ID %d\n", id);
}

void postman()
{
    FILE *f1;
    f1 = fopen("Postman.txt", "a+");
    struct postman
    {
        int id;
        char name[50];
        long int mobno;
    } p1[8];

    printf("1. ADD POSTMAN\n2. DISPLAY POSTMAN");
    int choice, x;
    printf("\nENTER CHOICE: ");
    scanf("%d", &choice);
    if (choice == 1)
    {

        int num, x;
        printf("ENTER NUMBER OF ENTRIES: ");
        scanf("%d", &num);

        for (x = 0; x < num; x++)
        {
            printf("ENTER POSTMAN ID: ");
            scanf("%d", &p1[x].id);
            printf("ENTER POSTMAN NAME: ");
            fflush(stdin);
            gets(p1[x].name);
            printf("ENTER POSTMAN MOBILE NUMBER: ");
            scanf("%d", &p1[x].mobno);
            fwrite(&p1[x], sizeof(p1[x]), 1, f1);
        }
        printf("RECORD SAVED SUCCESSFULLY");
        fclose(f1);
    }

    else if (choice == 2)
    {
        printf("ID\t\tPOSTMAN NAME\t\tMOBILE NUMBER");
        for (x = 0;; x++)
        {
            fread(&p1[x], sizeof(p1[x]), 1, f1);
            if (0 < p1[x].id && p1[x].id > 9)
            {
                break;
            }
            else
                printf("\n%d\t\t%s\t\t%d", p1[x].id, p1[x].name, p1[x].mobno);
        }
        fclose(f1);
    }
    else
    {
        printf("INVALID INPUT!");
    }
}