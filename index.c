#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
struct vehiles 
{
    int number;
    char vechilename[100];
    char driver[100];
    char date[16];
}v;


int menu();
void bus();
void cycle();
void riksha();
void delete();
void showvechiles();
void showdetails();
int nor = 0, nob = 0, noc = 0, amount = 0, count = 0;
FILE *fp;
int main()
{
    while (1)
    {
        system("cls");
        int ch;
        printf("Enter your choice\n");
        printf("1. Enter bus\n");
        printf("2. Enter cycle\n");
        printf("3. Enter riksha\n");
        printf("4. Status\n");
        printf("5. delete data\n");
        printf("6. Show data\n");
        printf("7. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            bus();
            getch();
            break;

        case 2:
            cycle();
            getch();
            break;

        case 3:
            riksha();
            getch();
            break;
        case 4:
            showdetails();
            getch();
            break;
        case 5:
            delete ();
            getch();
            break;
        case 6:
            showvechiles();
            getch();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
void riksha()
{
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(v.date, myDate);

    fp = fopen("vechiles.txt", "ab");

    printf("Enter vehile Number: ");
    scanf("%d", &v.number);

    printf("Enter vechile name: ");
    fflush(stdin);
    gets(v.vechilename);

    printf("Enter driver name: ");
    fflush(stdin);
    gets(v.driver);


    fwrite(&v, sizeof(v), 1, fp);
    fclose(fp);
    nor++;
    amount = amount + 30;
    count++;
    printf("Entry Successfull\n");
}
void cycle()
{
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(v.date, myDate);

    fp = fopen("vechiles.txt", "ab");

    printf("Enter vehile Number: ");
    scanf("%d", &v.number);

    printf("Enter vechile name: ");
    fflush(stdin);
    gets(v.vechilename);

    printf("Enter driver name: ");
    fflush(stdin);
    gets(v.driver);


    fwrite(&v, sizeof(v), 1, fp);
    fclose(fp);
    noc++;
    amount = amount + 15;
    count++;
    printf("Entry Successfull\n");
}
void bus()
{
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(v.date, myDate);

    fp = fopen("vechiles.txt", "wb");

    printf("Enter vehile Number: ");
    scanf("%d", &v.number);

    printf("Enter vechile name: ");
    fflush(stdin);
    gets(v.vechilename);

    printf("Enter driver name: ");
    fflush(stdin);
    gets(v.driver);

    fwrite(&v, sizeof(v), 1, fp);
    fclose(fp);
    
    nob++;
    amount = amount + 70;
    count++;
    printf("Entry Successfull\n");
}

void delete()
{
    nob = 0;
    noc = 0;
    nor = 0;
    amount = 0;
    count = 0;
}

void showdetails()
{
    printf("Number of Bus = %d\n", nob);
    printf("Number of cycle = %d\n", noc);
    printf("Number of riksha = %d\n", nor);
    printf("Total number of vechiles = %d\n", count);
    printf("Total Gain amount = %d\n", amount);
}
void showvechiles(){

    system("cls");
    printf("<== Available Vechiles ==>\n\n");
    printf("%-20s %-30s %-20s %s\n\n", "Vechile Number", "Vechile Name", "Driver", "Date");

    fp = fopen("vechiles.txt", "rb");
    while(fread(&v, sizeof(v), 1, fp) == 1){
        printf("%-20d %-30s %-20s %s\n", v.number, v.vechilename, v.driver, v.date);
    }

    fclose(fp);
}