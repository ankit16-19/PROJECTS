//project :- Placement cell

//*************************************Header files*****************************************************
#include <stdio.h>
#include <stdlib.h>
#include <windows.h> //for gotoxy()
#include <time.h>    //for gotoxy()
#include <string.h>
//************************************prototype functions*********************************************
void mainmenu(void);
void returnmainmenu(void);
void studentdatabase(void);
void adds(void);
void dels(void);
void edits(void);
void shows(void);
void searchs(void);
void companydatabase(void);
void addc(void);
void delc(void);
void editc(void);
void showc(void);
void searchc(void);
int getdata(void);
int getdatac(void);
void run(void);
void password(void);
int screening(void);
void result(void);
//---gotoxy declaration---
COORD coord = {0, 0}; // sets coordinates to 0,0
COORD max_res,cursor_size;
void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//---delay declaration---
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
//------------global files---------------------
FILE *fs,*fc,*t;


void write()
{
    fs=fopen("student.dat","r");
    if(fs == NULL)
    {
        fs = fopen("student.dat","w");
    }
    fclose(fs);

    fc=fopen("company.dat","r");
    if(fc == NULL)
    {
        fc = fopen("company.dat","w");
    }
    fclose(fc);
}
//************global variables****************

//student structure
struct student
{
    int branch;
    char id[10];
    char name[20];
    float cgpa;
    int projects;
    int internships;
    char email[30];
    int flag;
};
struct student s ;
//company structure
struct company
{
    int branch;
    char id[10];
    char name[20];
    float cgpa;
    int projects;
    int internships;
    char email[30];
    int flag;
};
struct company c ;
//********************************************************************starting program***************************************************************
int main()
{
    write();
    password();
    int getchar();
    return 0;
}
void mainmenu()
{
    system("cls");;
    gotoxy(20,1);
    char welcome[50]={"WELCOME TO PLACEMENT CELL, IIIT BHUBANESWAR."};
    int i;
    for(i=0;i<50;i++)
    {
        delay(10);
        printf("%c",welcome[i]);
    }
    gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2Main Menu\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,5);
    printf("\xDB\xDB\xDB 1. Student Database");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB 2. Company Database");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB 3. Run Placement cell with current inputs");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB 4. Close application");
    gotoxy(20,13);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,14);
    printf("Enter your choice:");
    int c = getchar();
    switch(c)
    {
    case '1':
        studentdatabase();
        break;
    case '2':
        companydatabase();
        break;
    case '3':
        run();
        break;
    case '4':
        system("cls");
        gotoxy(15,3);
        printf("---------------------------Project by Group 3--------------------------------");
        gotoxy(15,4);
        printf("Members:");
        gotoxy(15,6);
        printf("Abhipsha Das  (ETC/B216001)");
        gotoxy(15,8);
        printf("Bhumika Satpathy  (ETC/B216014)");
        gotoxy(15,10);
        printf("Grace Serraon  (ETC/B216051)");
        gotoxy(15,12);
        printf("Ananya Apurva (ETC/B2160--)");
        gotoxy(15,14);
        printf("Ankit Choudhary   (ETC/B216008)");
        gotoxy(15,16);
        printf("Exiting in 2 sec........");
        delay(2000);
        exit(0);
        break;
    default:
        gotoxy(15,3);
        printf("Wrong input Enter valid choice:");
        returnmainmenu();
        break;
    }
}
void returnmainmenu()
{
    system("cls");
    gotoxy(20,1);
    char welcome[50]={"WELCOME TO PLACEMENT CELL IIIT BHUBANESWAR"};
    int i;
    for(i=0;i<50;i++)
    {
        printf("%c",welcome[i]);
    }
    gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2Main Menu\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,5);
    printf("\xDB\xDB\xDB 1. Student Database");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB 2. Company Database");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB 3. Run Placement cell with current inputs");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB 4. Close application");
    gotoxy(20,13);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,14);
    printf("Enter your choice:");
    switch(getchar())
    {
    case '1':
        studentdatabase();
        break;
    case '2':
        companydatabase();
        break;
    case '3':
        run();
        break;
    case '4':
        system("cls");
        gotoxy(15,3);
        printf("---------------------------Project by Group 3--------------------------------");
        gotoxy(15,4);
        printf("Members:");
        gotoxy(15,6);
        printf("Abhipsha Das  (ETC/B2160--)");
        gotoxy(15,8);
        printf("Bhumika Satpathy  (ETC/B2160--)");
        gotoxy(15,10);
        printf("Grace Serraon  (ETC/B2160--)");
        gotoxy(15,12);
        printf("Ananya Apurva (ETC/B2160--)");
        gotoxy(15,14);
        printf("Ankit Choudhary   (ETC/B2160--)");
        gotoxy(15,16);
        printf("Exiting in 2 sec........");
        delay(2000);
        exit(0);
        break;
    default:
        gotoxy(15,3);
        printf("Wrong input Enter valid choice:");
        mainmenu();
        break;
    }
}
void password()
{
    system("cls");
    int i,m=15;
    for(i=0;i<10;i++)
    {
        delay(40);
        gotoxy(m,3);
        printf("*\xDB");
        gotoxy(m,4);
        printf("\xDB*");
        m=m+2;

    }
    char a[20]=" PASSWORD PROTECTED";
    for(i=0;i<20;i++)
    {
        delay(30);
        printf("%c",a[i]);
    }
    int n=54;
    for(i=0;i<10;i++)
    {
        delay(40);
        gotoxy(n,3);
        printf("*\xDB");
        gotoxy(n,4);
        printf("\xDB*");
        n=n+2;
    }
    gotoxy(15,10);
    printf("Enter password:");
    char ch;
    i=0;
    fflush(stdin);
    char pass[10],passkey[10]={"ad1619"};
    while(ch!=13)
    {
        ch = getch();
        if(ch!=13 && ch!=8)
        {
            printf("*");
            pass[i]=ch;
            i++;
        }
    }
    pass[i]='\0';
    if(strcmp(pass,passkey)==0)
    {
        gotoxy(15,11);
        printf("Password matched");
        gotoxy(15,12);
        printf("Logging in..........");
        delay(1000);
        mainmenu();
    }
    else
    {
        gotoxy(15,11);
        printf("\aWrong password!!!!!!");
        getchar();
        password();
    }
}
void studentdatabase()
{
    system("cls");
    gotoxy(15,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Student Data \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(15,5);
    printf("\xDB\xDB\xDB\xDB 1. Add data");
    gotoxy(15,7);
    printf("\xDB\xDB\xDB\xDB 2. Delete data");
    gotoxy(15,9);
    printf("\xDB\xDB\xDB\xDB 3. Modify data");
    gotoxy(15,11);
    printf("\xDB\xDB\xDB\xDB 4. Show data");
    gotoxy(15,13);
    printf("\xDB\xDB\xDB\xDB 5. Search data");
    gotoxy(15,15);
    printf("\xDB\xDB\xDB\xDB 0.Back to main menu");
    gotoxy(15,16);
    printf("Enter your choice");
    fflush(stdin);
    switch(getchar())
    {
        case '1':
            adds();
            break;
        case '2':
            dels();
            break;
        case '3':
            edits();
            break;
        case '4':
            shows();
            break;
        case '5':
            searchs();
            break;
        case '0' :
            returnmainmenu();
            break;
        default:
            {
                gotoxy(15,17);
                printf("Wrong input!!!!!Enter valid choice \a");
                delay(1000);
                studentdatabase();
                break;
            }
    }
}
void adds()
{
    system("cls");
    gotoxy(15,3);
    printf("\xB1\xB1\xB1\xB1\xB1 Add student details \xB1\xB1\xB1\xB1\xB1");gotoxy(15,5);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB Enter branch \xDB\xDB\xDB\xDB\xDB\xDB");gotoxy(15,7);
    printf("\xB2\xB2\xB2 1.CSE");gotoxy(15,9);
    printf("\xB2\xB2\xB2 2.ECE");gotoxy(15,11);
    printf("\xB2\xB2\xB2 3.IT");gotoxy(15,13);
    printf("\xB2\xB2\xB2 4.CE");gotoxy(15,15);
    printf("\xB2\xB2\xB2 5.EEE");gotoxy(15,17);
    printf("\xB2\xB2\xB2 9.Back");gotoxy(15,19);
    printf("\xB2\xB2\xB2 0.Main menu");gotoxy(15,21);
    printf("Enter your choice:");
    fflush(stdin);
    int c = getchar();
    switch(c)
    {
        case '1':
            system("cls");
            gotoxy(15,3);
            printf("Branch CSE Add student details:");
            s.branch=0;
            break;
        case '2':
            system("cls");
            gotoxy(15,3);
            printf("Branch ETC Add student details:");
            s.branch=1;
            break;
        case '3':
            system("cls");
            gotoxy(15,3);
            printf("Branch IT Add student details:");
            s.branch=2;
            break;
        case '4':
            system("cls");
            gotoxy(15,3);
            printf("Branch CE Add student details:");
            s.branch=3;
            break;
        case '5':
            system("cls");
            gotoxy(15,3);
            printf("Branch EEE Add student details:");
            s.branch=4;
            break;
        case '9':
            studentdatabase();
            break;
        case '0':
            returnmainmenu();
            break;
        default:
            printf("Wrong input !!!!Enter a valid input\a");
            delay(1000);
            adds();
    }
    fs = fopen("student.dat","a");
    fseek(fs,0,SEEK_END);
    if(getdata()==1)
    {

        fwrite(&s,sizeof(struct student),1,fs);
        printf("Data successfully added\n");
        printf("To add another data press y");
        fflush(stdin);
        char d = getchar();
        if(d=='y')
        {
            fclose(fs);
            adds();
        }
        if(d!='y')
        {
            fclose(fs);
            returnmainmenu();
        }
    }
    else
    {
        printf("error!!!\a");
        delay(50);
        fclose(fs);
        adds();
    }
}
int getdata()
{
    system("cls");
    fflush(stdin);
    gotoxy(15,4);
    printf("Enter name of the student:");
    gets(s.name);gotoxy(15,5);
    printf("Enter the ID of the student:");
    scanf("%s",&s.id);gotoxy(15,6);
    printf("Enter the CGPA:");
    scanf("%f",&s.cgpa);gotoxy(15,7);
    printf("Enter number of Projects:");
    scanf("%d",&s.projects);gotoxy(15,8);
    printf("Enter number of Internships:");
    scanf("%d",&s.internships);gotoxy(15,9);
    printf("Enter email:");
    scanf("%s",s.email);
    return 1;
}
void searchs()
{
    int c=0;
    system("cls");
    gotoxy(15,3);
    printf("\xB1\xB1\xB1\xB1\xB1 Search for student details \xB1\xB1\xB1\xB1\xB1");gotoxy(15,5);
    printf("\xDB\xDB\xDB Enter student ID to search student:");
    char d[10];
    scanf("%s",&d);
    fs = fopen("student.dat","rb+");
    while(fread(&s,sizeof(s),1,fs)==1)
    {
    printf("%s",s.id);
       if(strcmp(s.id,d)==0)
        {
            if(s.flag!=1)
            {  c++;
            gotoxy(15,7);
            printf("Record Found:");gotoxy(15,8);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
            gotoxy(15,10);
            printf("Name:");
            printf("%s",s.name);gotoxy(15,12);
            printf("ID:");
            printf("%s",s.id);gotoxy(15,14);
            printf("CGPA:");
            printf("%f",s.cgpa);gotoxy(15,16);
            printf("Projects:");
            printf("%d",s.projects);gotoxy(15,18);
            printf("Internships:");
            printf("%d",s.internships);gotoxy(15,20);
            printf("email:");
            printf("%s",s.email);
            getchar();
            studentdatabase();
            }
        }
        else
        {
            system("cls");gotoxy(15,3);
            printf("Record not found");
            delay(1000);
            studentdatabase();

        }
    }
        if(c==0)
        {
            system("cls");
            gotoxy(15,3);
            printf("Record not found!!!\a\n");
            delay(100);
            printf("Want to add this ID press 'y'");
            fflush(stdin);
            if(getchar()=='y')
                adds();
            else
                studentdatabase();
        }
        fclose(fs);
    }
void shows()
{
    system("cls");
    printf("Loading.......\n");
	fs = fopen("student.dat","r+");
    	while(fread(&s,sizeof(s),1,fs))
    	{printf("a");
                if(s.flag!=1)
                {
                    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
                    printf("Name:");
                    printf("%s\n",s.name);
                    printf("ID:");
                    printf("%s\n",s.id);
                    printf("CGPA:");
                    printf("%f\n",s.cgpa);
                    printf("Projects:");
                    printf("%d\n",s.projects);
                    printf("Internships:");
                    printf("%d\n",s.internships);
                    printf("email:");
                    printf("%s",s.email);
                    printf("\n");
                }
}
        fclose(fs);
        getchar();
        getchar();
        returnmainmenu();
}
void edits()
{
    system("cls");
    printf("Enter student id to edit:\n");
    char editid[10];
    scanf("%s",&editid);
    fs = fopen("student.dat","r+");
    printf("0 for CSE ||");printf("1 for ETC ||");printf("2 for IT ||");printf("3 for CE ||");printf("4 for EEE ||\n\n\n");
        while(fread(&s,sizeof(s),1,fs))
        {

            {
                if(strcmp(s.id,editid)==0)
                {
                    gotoxy(15,3);
                    printf("ID found want to edit press (y):");
                    char c;
                    fflush(stdin);
                    c = getchar();
                    if(c=='y')
                    {
                        gotoxy(15,5);
                        printf("what you want to edit:\n");gotoxy(15,6);
                        printf("\xDB\xDB\xDB 1. Branch:\n");gotoxy(15,7);
                        printf("\xDB\xDB\xDB 2. Name:\n");gotoxy(15,8);
                        printf("\xDB\xDB\xDB 3. CGPA:\n");gotoxy(15,9);
                        printf("\xDB\xDB\xDB 4. Projects:\n");gotoxy(15,10);
                        printf("\xDB\xDB\xDB 5. Internships:\n");
                        fflush(stdin);
                        int c = getchar();
                        switch(c)
                        {
                            case '1':
                            gotoxy(15,11);
                            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");gotoxy(15,12);
                            printf("Enter new branch\n");gotoxy(15,13);
                            scanf("%s",&s.branch);
                            break;

                            case '2':
                            gotoxy(15,11);
                            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");gotoxy(15,12);
                            printf("Enter new Name\n");gotoxy(15,13);
                            scanf("%s",&s.name);
                            break;

                            case '3':
                            gotoxy(15,11);
                            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");gotoxy(15,12);
                            printf("Enter new cgpa\n");gotoxy(15,13);
                            fflush(stdin);
                            scanf("%f",&s.cgpa);
                            break;

                            case '4':
                            gotoxy(15,11);
                            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");gotoxy(15,12);
                            printf("Enter no. of projects\n");gotoxy(15,13);
                            scanf("%d",&s.projects);
                            break;

                            case '5':
                            gotoxy(15,11);
                            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");gotoxy(15,12);
                            printf("Enter n. of internships\n");gotoxy(15,13);
                            scanf("%d",s.internships);
                            break;
                        }
                        fseek(fs,-1*(sizeof(struct student)),SEEK_CUR);
                        fwrite(&s,sizeof (s),1,fs);
                        fclose(fs);
                        printf("Data successfully saved:");
                        studentdatabase();

                    }

                    }
                    else
                    {

                        gotoxy(15,11);
                        printf("\aWrong input !!!!!Enter again\n");
                        fflush(stdin);
                        getchar();
                        studentdatabase();
                    }

                }
        }
    }
void dels()
{
    system("cls");
    gotoxy(15,3);
    printf("Enter students Id to Delete student data:" );
    fflush(stdin);
    char deleteid[10];
    scanf("%s",&deleteid);
    fs = fopen("student.dat","r+");
    getchar();
    while(fread(&s,sizeof (struct student),1,fs))
    {
        printf("a");
        if(strcmp(s.id,deleteid)==0)
           {
            printf("b");
            s.flag = 1;
            fseek(fs,-1*(sizeof (struct student)),SEEK_CUR);
            fwrite(&s,sizeof (s),1,fs);
            fclose(fs);
            printf("Id deleted successfully");
            printf("Want to delete another ID press 'y':");
            char ans = getchar();
            if(ans =='y')
            dels();
            else
            studentdatabase();
            break;
            }
          else
          {
            printf("\aId not in databases:");
            fflush(stdin);
            getchar();
            studentdatabase();
          }

    }
}

//************************************************************************************************************
//*****************************************************company functions**************************************
void companydatabase()
{
    system("cls");
    gotoxy(15,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Company Data \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(15,5);
    printf("\xDB\xDB\xDB\xDB 1. Add data");
    gotoxy(15,7);
    printf("\xDB\xDB\xDB\xDB 2. Delete data");
    gotoxy(15,9);
    printf("\xDB\xDB\xDB\xDB 3. Modify data");
    gotoxy(15,11);
    printf("\xDB\xDB\xDB\xDB 4. Show data");
    gotoxy(15,13);
    printf("\xDB\xDB\xDB\xDB 5. Search data");
    gotoxy(15,15);
    printf("\xDB\xDB\xDB\xDB 0.Back to main menu");
    gotoxy(15,16);
    printf("Enter your choice");
    fflush(stdin);
    switch(getchar())
    {
        case '1':
            addc();
            break;
        case '2':
            delc();
            break;
        case '3':
            editc();
            break;
        case '4':
            showc();
            break;
        case '5':
            searchc();
            break;
        case '0' :
            returnmainmenu();
            break;
        default:
            {
                gotoxy(15,17);
                printf("Wrong input!!!!!Enter valid choice \a");
                delay(1000);
                companydatabase();
                break;
            }
    }
}
void addc()
{
    system("cls");
    gotoxy(15,3);
    printf("\xB1\xB1\xB1\xB1\xB1 Add company details \xB1\xB1\xB1\xB1\xB1");gotoxy(15,5);
    fc = fopen("company.dat","ab");
    if(getdatac()==1)
    {

        fwrite(&c,sizeof(struct company),1,fc);
        printf("Data successfully added\n");
        fclose(fc);
        printf("To add another data press y");
        fflush(stdin);
        char d = getchar();
        if(d=='y')
            addc();
        if(d!='y')
            returnmainmenu();

    }
    else
    {
        printf("error!!!\a");
        delay(50);
        fclose(fc);
        addc();
    }

}
int getdatac()
{
    fflush(stdin);
    gotoxy(15,4);
    printf("Enter name of the company:");
    gets(c.name);gotoxy(15,5);
    printf("Enter the ID of the company:");
    gets(c.id);gotoxy(15,6);
    printf("Enter the CGPA:");
    scanf("%f",&c.cgpa);gotoxy(15,7);
    printf("Enter number of Projects:");
    scanf("%d",&c.projects);gotoxy(15,8);
    printf("Enter number of Internships:");
    scanf("%d",&c.internships);gotoxy(15,9);
    printf("Enter email:");
    scanf("%s",c.email);
    return 1;
}
void searchc()
{

    system("cls");
    gotoxy(15,3);
    printf("\xB1\xB1\xB1\xB1\xB1 Search for company details \xB1\xB1\xB1\xB1\xB1");gotoxy(15,5);
    printf("\xDB\xDB\xDB Enter company ID to search company:");
    char id[10];int d=0;
    scanf("%s",&id);
    fc = fopen("company.dat","r+");
    while(fread(&c,sizeof(c),1,fc))
    {
        if(strcmp(id,c.id)==0)
        {
            if(c.flag!=1)
            {d++;
            gotoxy(15,8);
            printf("Record Found:");
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
            gotoxy(15,10);
            printf("Name:");
            printf("%s",c.name);gotoxy(15,12);
            printf("ID:");
            printf("%s",c.id);gotoxy(15,14);
            printf("CGPA:");
            printf("%f",c.cgpa);gotoxy(15,16);
            printf("Projects:");
            printf("%d",c.projects);gotoxy(15,18);
            printf("Internships:");
            printf("%d",c.internships);gotoxy(15,20);
            printf("email:");
            printf("%s",c.email);
            fclose(fc);
            fflush(stdin);
            getchar();
            companydatabase();
            }
        }

    }
        if(d==0)
        {
            system("cls");
            gotoxy(15,3);
            printf("Record not found!!!\a\n");
            getchar();
            printf("Want to add this ID press 'y'");
            fflush(stdin);
            if(getchar()=='y')
                addc();
            else
                companydatabase();
    fclose(fc);
}
}
void showc()
{
    system("cls");
	int count=0;
    printf("LOading.......\n");
	fc = fopen("company.dat","r+");
    	while(fread(&c,sizeof(c),1,fc))
    	{
                if(c.flag!=1)
                {
                    count++;
                    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
                    printf("Name:");
                    printf("%s\n",c.name);
                    printf("ID:");
                    printf("%s\n",c.id);
                    printf("CGPA:");
                    printf("%f\n",c.cgpa);
                    printf("Projects:");
                    printf("%d\n",c.projects);
                    printf("Internships:");
                    printf("%d\n",c.internships);
                    printf("email:");
                    printf("%s",c.email);
                    printf("\n");

                }


        }
        getchar();
        if (count==0)
            printf("NO data to show");
        fclose(fc);
        fflush(stdin);
        getchar();
        companydatabase();
}
void editc()
{
    system("cls");
    printf("Enter company id to edit:\n");
    char editid[10];int d=0;
    scanf("%s",&editid);
    fc = fopen("company.dat","r+");
        while(fread(&c,sizeof(c),1,fc))
        {
            printf("a");
                if(strcmp(c.id,editid)==0)
                {
                    d++;
                    gotoxy(15,3);
                    if(c.flag!=1)
                    {
                    printf("ID found want to edit press (y):");
                    char z;
                    fflush(stdin);
                    z = getchar();
                    if(z=='y')
                    {
                        gotoxy(15,5);
                        printf("what you want to edit:\n");gotoxy(15,6);
                        printf("\xDB\xDB\xDB 1. Branch:\n");gotoxy(15,7);
                        printf("\xDB\xDB\xDB 2. Name:\n");gotoxy(15,8);
                        printf("\xDB\xDB\xDB 3. CGPA:\n");gotoxy(15,9);
                        printf("\xDB\xDB\xDB 4. Projects:\n");gotoxy(15,10);
                        printf("\xDB\xDB\xDB 5. Internships:\n");
                        fflush(stdin);
                        int z = getchar();
                        switch(z)
                        {
                            case '1':
                            gotoxy(15,11);
                            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
                            printf("Enter new branch\n");gotoxy(15,12);
                            scanf("%s",&c.branch);
                            break;

                            case '2':
                            gotoxy(15,11);
                            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
                            printf("Enter new Name\n");gotoxy(15,12);
                            fflush(stdin);
                            gets(c.name);
                            break;

                            case '3':
                            gotoxy(15,11);
                            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
                            printf("Enter new cgpa\n");gotoxy(15,12);
                            scanf("%f",&c.cgpa);
                            break;

                            case '4':
                            gotoxy(15,11);
                            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
                            printf("Enter no. of projects\n");gotoxy(15,12);
                            scanf("%d",c.projects);
                            break;

                            case '5':
                            gotoxy(15,11);
                            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
                            printf("Enter n. of internships\n");gotoxy(15,12);
                            scanf("%d",c.internships);
                            break;
                        }
                        fseek(fc,-1*(sizeof(struct company)),SEEK_CUR);
                        fwrite(&c,sizeof (c),1,fc);
                        fclose(fc);
                        printf("Data successfully saved:");
                        companydatabase();
                    }
                    else
                    {
                        fclose(fc);
                        getchar();
                        companydatabase();
                    }
                    }
                    else
                    {
                        fclose(fc);
                        printf("Id not found");
                        fflush(stdin);
                        getchar();
                        companydatabase();
                    }
                }

                }
                if(d==0)
                    {
                        gotoxy(15,11);
                        printf("\aWrong input !!!!!\n");
                        fflush(stdin);
                        getchar();
                        companydatabase();
                    }
                fclose(fc);
        }
void delc()
{
    system("cls");
    gotoxy(15,3);
    printf("Enter company Id to Delete company data:" );
    fflush(stdin);
    char deleteid[10];int d=0;
    scanf("%s",&deleteid);
    fc = fopen("company.dat","r+");
    getchar();
    while(fread(&c,sizeof (struct company),1,fc))
    {
        printf("a");
        if(strcmp(c.id,deleteid)==0)
           {d++;
            printf("b");
            c.flag = 1;
            fseek(fs,-1*(sizeof (struct company)),SEEK_CUR);
            fwrite(&c,sizeof (c),1,fc);
            fclose(fc);
            printf("Id deleted successfully");
            printf("Want to delete another ID press 'y':");
            char ans = getchar();
            if(ans =='y')
            dels();
            else
            companydatabase();
            break;
            }
    }
          if(d==0)
          {
            printf("\aId not in databases:");
            fclose(fc);
            fflush(stdin);
            getchar();
            companydatabase();
          }
}

//************************************************************************************************************************
//*********************************************run placement cell*********************************************************
int num=0,results[100];//global declaration for num. of student qualified
void run()
{
    fflush(stdin);
    system("cls");
    int i,n=15,m=74;
    for(i=0;i<60;i++)
    {
        delay(20);
        gotoxy(n,3);
        printf("\xB1");
        gotoxy(m,4);
        printf("\xDB");
        gotoxy(n,5);
        printf("\xB1");
        n++;
        m--;
    }
    n=4;
    for(i=0;i<20;i++)
    {
        delay(30);
        gotoxy(14,n);
        printf("\xDB");
        gotoxy(75,n);
        printf("\xDB");
        n++;
    }
    gotoxy(35,4);
    char word[20]="Placement Cell";
    for(i=0;i<strlen(word);i++)
    {
        delay(30);
        printf("%c",word[i]);
    }
    gotoxy(15,7);
    printf("Enter company id to start placement procedure");
    char id[10];
    scanf("%s",&id);
    int d=0;
    fc = fopen("company.dat","rb+");
    while(fread(&c,sizeof(c),1,fc))
    {
        if(strcmp(c.id,id)==0)
        {
            d++;
            gotoxy(15,9);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");gotoxy(15,10);
            printf("Name: %s",c.name);gotoxy(15,11);
            printf("ID: %s",c.id);gotoxy(15,12);
            printf("CGPA: %.2f",c.cgpa);gotoxy(15,13);
            printf("Projects: %d",c.projects);gotoxy(15,14);
            printf("Internships: %d",c.internships);
            break;
        }
    }
    if(d==0)
    {
        printf("No record found");
        getchar();
        returnmainmenu();
    }
    fs = fopen("student.dat","rb+");
    num=0;
    while(fread(&s,sizeof (s),1,fs))
    {
        int x = atoi(s.id);
        if(s.cgpa>=c.cgpa && s.projects>=c.projects && s.internships>=c.internships )
        {
            results[num]=x;
            num++;
        }
    }
    fclose(fs);
    fclose(fc);
    results[num]='\0';
    gotoxy(48,11);
    printf("students qualified: %d",num);
    gotoxy(48,13);
    printf("Want to see the list press y:");
    fflush(stdin);
    char ans = getchar();
    if(ans=='y')
        result();
        fflush(stdin);
        getchar();
        returnmainmenu();
}
void result()
{
    system("cls");
    int v=0,z;
    fs = fopen("student.dat","rb+");
    while(fread(&s,sizeof (s),1,fs))
    {
        z= atoi(s.id);
        for(v=0;v<num;v++)
        {
        if(z==results[v])
        {
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
            printf("Name: %s\n",s.name);
            printf("ID: %s\n",s.id);
            printf("CGPA: %.2f\n",s.cgpa);
            printf("Projects: %d\n",s.projects);
            printf("Internships: %d\n",s.internships);
            printf("\n");
        }
        }
    }
    fclose(fs);
}
