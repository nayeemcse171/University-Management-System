#include<stdio.h>
#include<string.h>
#include <windows.h>
#include<time.h>


struct node{

    char data[100];
    char syn[100];
    char ant[100];
    int ant1;
    int ant2;
    char ant3[100];
    char ant4[100];
    char ant5[100];
    char ant6[100];
    char ant8[100];
    struct  node *link;

};
struct node *head=NULL;
struct node *tail=NULL;
char password[10]={"12345"};

void delay (unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

///*************************CREATE PASSWOARD OPTION**************************

void Password()

   { system("cls");
   char d[25]=" Password Protected";

     system("cls");
   char ch,pass[10];
   int i=0,j;
   for(j=0;j<20;j++)
   {
       delay(50);
    printf("*");
   }
   for(j=0; j<20; j++)
   {
       delay(50);
    printf("%c",d[j]);
   }
   for(j=0;j<20;j++)
   {
       delay(50);
    printf("*");
   }

   printf("\nEnter Password:");

   while(ch!=13)
   {
       ch=getch();
       if(ch!=13 && ch!= 8)
       {
           putch('*');
           pass[i] = ch;
           i++;
       }
   }

   pass[i] = '\0';
   if(strcmp(pass,password)==0)
   {
       system ("cls");

       printf("Password Match");

       printf("Press Any Key To Continue...");
       getch();
   }
   else
   {
       system("cls");

       printf("\aWarning!! Incorrect Password");
       getch();
       Password();
   }
}

int creat_node(char ch[10],char ch1[50],char ch2[50],int ch3,int ch4,char ch5[50],char ch6[50],char ch7[50],char ch8[50],char ch10[50])
{
    struct node *NODE = (struct node*)malloc(sizeof(struct node));
    strcpy(NODE->data,ch);
    strcpy(NODE->syn,ch1);
    strcpy(NODE->ant,ch2);
    NODE->ant1=ch3;
    NODE->ant2=ch4;
    strcpy(NODE->ant3,ch5);
    strcpy(NODE->ant4,ch6);
    strcpy(NODE->ant5,ch7);
    strcpy(NODE->ant6,ch8);
    strcpy(NODE->ant8,ch10);
    NODE->link = NULL;
    if(head==NULL){
        head=tail=NODE;
    }
    else
    {
        tail->link = NODE;
        tail=NODE;
    }
}


///*****************************************Create Display Function*************************************

void display(){
  struct node *link = head;

  int i=0;
  while(link!=NULL){

    printf("\t\t\t\t%d.%s\n",++i,link->data);
    printf("\t\t\t\t-------------");
    printf("\n\t\t\tUniversity Categories :%s",link->syn);
    printf("\n\t\t\tCampus :%s",link->ant);
    printf("\n\t\t\tCampus Area :%d sq mi",link->ant1);
    printf("\n\t\t\tTotal Students :%d",link->ant2);
    printf("\n\t\t\tTotal Faculty :%s",link->ant3);
    printf("\n\t\t\tAvailable Course :%s",link->ant4);
    printf("\n\t\t\tMembership :%s",link->ant5);
    printf("\n\t\t\tBD Ranking :%s",link->ant6);
    printf("\n\t\t\tCampus Location:%s\n\n",link->ant8);
    link=link->link;
  }

}


///****************************Create Node Function Call For University Information ******************************

void creat(){
        creat_node("DIU","Private","Main & Permanent", 150, 22000,"Four","CSE SWE EEE BBA","IFLA EURAS KISS ITU"," 9th","Khagan Dattapara Savar");
        creat_node("AIUB","Private","Main & Permanent", 78, 16000,"Four","CSE SWE EEE BBA","CISCO IEEE ORACLE","8th","MKuratol Khilkhet");
        creat_node("IUBAT","Private","Main", 110, 20000, "Three","CSE SWE BBA","IFLA UMAP GUIDE"," 13th","Uttara Model Town");
        creat_node("IUB","Private","Main", 50, 11000,"Four","CSE SWE EEE BBA","EURAS IEEE CCSE ITU"," 4rth","Aftabuddin Ahmed Road");
        creat_node("ULAB","Private","Main", 34, 7000,"Three","CSE SWE BBA","IFLA EURAS ITU"," 15th","JighatolaDhanmondi");


}
///............................Create Search Function.................................

void search(char valu[10])
{
    struct node *item=head;
    while(item!=NULL)
    {
        if(strcmp(item->data,valu)==0){
            break;
        }
        else{
            item=item->link;
        }
    }
    if(item!=NULL){
        printf("University Name : %s \nUniversity Categories : %s \nCampus : %s \nCampus Area : %d \nTotal Students : %d \nTotal Faculty : %s \nAvailable Course : %s \nMembership : %s \nBD Ranking : %s \nCampus Location: %s",item->data,item->syn,item->ant,item->ant1,item->ant2,item->ant3,item->ant4,item->ant5,item->ant6,item->ant8);

    }
    else{
        printf("\nInformation not found");
    }
}
///....................Create Insert Function............................
int a;

void insert(){
    struct node *item=head,*loc=(struct node *)malloc(sizeof(struct node));
    char valu[50], value[50];

    char ch;
    printf("\t\tEnter Varsity Name what do you want to ADD: ");
    scanf("%c ",&ch);
    gets(valu);
    strcpy(loc->data,valu);
    printf("\t\tUniversity Categories: ");

     gets(value);
    strcpy(loc->syn,value);
    printf("\t\tCampus: ");

     gets(value);
    strcpy(loc->ant,value);
    printf("\t\tCampus Area: ");
    scanf("%d", &a);

    loc->ant1=a;
    printf("\t\tTotal Students: ");
    scanf("%d", &a);

     loc->ant2=a;
    printf("\t\tTotal Faculty: ");
    scanf("%c", &ch);
    gets(value);
    strcpy(loc->ant3,value);
    printf("\t\tAvailable Course: ");

     gets(value);
    strcpy(loc->ant4,value);
    printf("\t\tBD Membership: ");

     gets(value);
    strcpy(loc->ant5,value);
    printf("\t\tBD Ranking: ");

     gets(value);
    strcpy(loc->ant6,value);
    printf("\t\tCampus Location: ");

    gets(value);
    strcpy(loc->ant8,value);

    int choos;
    printf("\n");
    printf("Press (1) to add first position\nPress(2) to add after any Varsity:\n");
    scanf("%d", &choos);

    if(choos==2){
        printf("What Kind Of Varsity after you Add: ");
        scanf("%s",&valu);
        while(item!=NULL){
            if(strcmp(item->data,valu)==0){
                loc->link=item->link;
                item->link=loc;
                break;;
            }
            else{
                item=item->link;

            }
        }
    }
    else if(choos==1){
        loc->link=head;
        head=loc;
    }
    else{

    }
    display();
    printf("Enter any key to go to  the main menu:");
    getch();
}

///........................Create Delete Function.............................

void delete(){
    struct node *loc=head;
    struct node *locp = NULL;
    char val[100];
    printf("\nEnter the Varsity what you want to delete: ");
    scanf("%s",&val);
    while(loc!=NULL){
        if(strcmp(loc->data,val)==0)
            break;
        else{
            locp=loc;
            loc=loc->link;
        }
    }
    if(locp==NULL){
        head=loc->link;
    }
    else{
        if(locp!=NULL){
            locp->link=loc->link;
        }
        else{
            printf("Information not found!");
        }
    }
    display();
    printf("Enter any key to go to the main menu: ");
    getch();

}

///......................MAIN MENU.......................

int mainmenu(){
system("cls");
    int i;
      char ch[10];
    int a;

     struct node *item;
     printf("\n\t\t\xB2\xB2\xB2 Welcome To Bangladesh University Management system \xB2\xB2\xB2\n\n");
     printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU");
     printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
     printf("\n\n\t\t\xDB\xDB\xDB\xB2 1. Admin \n");
     printf("\n\n\t\t\xDB\xDB\xDB\xB2 2. User \n");
     printf("\n\n\t\t\xDB\xDB\xDB\xB2 3. About \n");
     printf("\n\n\t\t\xDB\xDB\xDB\xB2 4. Close The Application \n");
     printf("\n\n\t\t------------------------------------------\n");

     printf("\n\xDB\xDB\xDB\xB2 Enter Your Choice : ");
     scanf("%d", &a);

     if(a==1){

        system("cls");
        Password();
        system("cls");

       printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
       printf("\n\n\t\t\xDB\xDB\xDB\xB2 1. Add New University.  ");
       printf("\n\n\t\t\xDB\xDB\xDB\xB2 2. Delete Any University. ");
       printf("\n\n\t\t\xDB\xDB\xDB\xB2 3. Edit Any Varsity Information.");
       printf("\n\n\t\xDB\xB2 Enter Your Choice : ");
       switch(getch())
       {
       case '1':
        system("cls");
        insert();
        break;

       case '2':
        system("cls");
        delete();
        break;

       case '3':
        system("cls");
        edit();
        break;

       case'4':
           {
               system("cls");
               printf("\n\t\t Thanks For Using Our Program...!");
               printf("\n\t\t Made by......\n Shakib\n Nayeem\n Hridoy\n");
               printf("\n\tExiting in 5 second.........>");
               exit(0);
           }
       default:
        {
            printf("\n\t\tWrong Entry!! Press Any Key Back To Mainmenu : ");
            if(getch());
            mainmenu();
        }

        }
     }

     else if(a==2){
        system("cls");
        printf("\n\xDB\xDB\xDB\xB2 1. Search Varsity\n");
        printf("\n\xDB\xDB\xDB\xB2 2. Read Any Varsity Information\n");

        printf("\nEnter Your Choice : ");

        switch(getch())
        {
       case '1':
        system("cls");
        printf("\nWhich Varsity Are You Want To search : ");
        scanf("%s", &ch);
        search(ch);
        getch();
        break;

       case '2':
        system("cls");
        display();
        getch();
        break;

       default:
        {
            printf("\n\t\tWrong Enter!! Press Any Key Back To Mainmenu : ");
            getch();
            mainmenu();
        }
        }
     }
     else if(a==3){
        system("cls");
        printf("\n\t\t\xDB\xDB\xDB\xB2 1. About Software\n");
        printf("\n\t\t\xDB\xDB\xDB\xB2 2. About Admin\n");
        printf("\nEnter Your Choice : ");

        switch(getch())
        {
       case '1':
        system("cls");
            About_S();
            getch();
            break;

       case '2':
         system("cls");
         About_A();
         getch();
         break;

       default:
        printf("\n\t\tWrong Entry!! Press Any Key Back To Mainmenu : ");
        getch();
        mainmenu();
        }
     }
     else if(a==4){
        system("cls");
        printf("\n\n");
        printf("\t\tThanks For Using Our Program....!\n");
        printf("\t\tMade By.......\n\t\t\tShakib Shalim\t\t\tID:171-15-1171\n\t\t\tNayeem Khan\t\t\tID:171-15-1157\n\t\t\tHridoy Rasel\t\t\tID:171-15-1169\n");
        printf("\n\t\tExiting in 5 second..........>");
        exit(0);
     }
     else{
        printf("\aWrong Entry ! Please Re-Entered Correct Option");
        getch();
        mainmenu();
     }
     mainmenu();
}

///******************* About Software *******************

void About_S(){
    printf("\n\n\t\tWe have created the project using Data Structure & Link List which is called University Information Management System.\n\t\tIt contains the information about many varsities.\n\t\tYou can Insert,Delete,Search and Update any information of any varsity from this simulation. ");

}

///******************** About Admin *********************

void About_A(){

    printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Admin List \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\n");

    printf("\n\n\n\t\t Shakib Shalim Tonmoy \n\n");
    printf("\t\t\xB2\xB2\xB2 Software Engineer !\n\n");
    printf("\t\t\xB2\xB2\xB2 Daffodil International University.\n\n");
    printf("\t\t\xB2\xB2\xB2 Department Of Computer Science And Engineering..!\n\n");

    printf("\n\n\n\t\t Nayeem Khan \n\n");
    printf("\t\t\xB2\xB2\xB2 Data Analyst !\n\n");
    printf("\t\t\xB2\xB2\xB2 Daffodil International University.\n\n");
    printf("\t\t\xB2\xB2\xB2 Department Of Computer Science And Engineering..!\n\n");

    printf("\n\n\n\t\t Hridoy Mahmud Rasel \n\n");
    printf("\t\t\xB2\xB2\xB2 Data Analyst !\n\n");
    printf("\t\t\xB2\xB2\xB2 Daffodil International University.\n\n");
    printf("\t\t\xB2\xB2\xB2 Department Of Computer Science And Engineering..!\n\n");


}

///*************************** Edit Function *************************

int edit(){

      system("cls");
      struct node *item=head;
      display();
      printf("\nWrite The University Name What you Want To Edit : ");
      char eid[100],eid2[100];
      scanf("%s", &eid);
      while(item!=NULL){
        if(strcmp(item->data,eid)==0){
            break;
        }
        else{
            item=item->link;
        }
      }
      if (item==NULL){
        printf("Data Not Found !");
        getch();
        edit();
      }
      printf("\n Press (1) To Edit Varsity Name.\n");
      printf(" Press (2) To Edit University Categories.\n");
      printf(" Press (3) To Edit Campus.\n");
      printf(" Press (4) To Edit Campus Area.\n");
      printf(" Press (5) To Edit Total Students.\n");
      printf(" Press (6) To Edit Total Faculty.\n");
      printf(" Press (7) To Edit Available Course.\n");
      printf(" Press (8) To Edit Membership.\n");
      printf(" Press (9) To Edit BD Ranking.\n");
      printf(" Press (10) To Edit Campus Location.\n");
      printf(" Press (0) To Goto Main Menu\n");
      printf("Enter Your Choice : ");

      int valu;
          scanf("%d", &valu);

          switch(valu)
          {
          case 1:
            printf("Write The Update Varsity Catagories: ");
            scanf("%s", &eid2);
            strcpy(item->data,eid2);
            break;

         case 2:
            printf("Write The Update University Name : ");
            scanf("%s", &eid2);
            strcpy(item->syn,eid2);
            break;

        case 3:
            printf("Write The Update Campus : ");
            scanf("%s", &eid2);
            strcpy(item->ant,eid2);
            break;

        case 4:
            printf("Write The Update Campus Area : ");
            scanf("%s", &eid2);
            strcpy(item->ant1,eid2);
            break;

        case 5:
            printf("Write The Update Total Student : ");
            scanf("%s", &eid2);
            strcpy(item->ant2,eid2);
            break;

        case 6:
            printf("Write The Update Total Faculty : ");
            scanf("%s", &eid2);
            strcpy(item->ant3,eid2);
            break;

        case 7:
            printf("Write The Update Available Course : ");
            scanf("%s", &eid2);
            strcpy(item->ant4,eid2);
            break;

        case 8:
            printf("Write The Update Membership : ");
            scanf("%s", &eid2);
            strcpy(item->ant5,eid2);
            break;

        case 9:
            printf("Write The Update BD Ranking : ");
            scanf("%s", &eid2);
            strcpy(item->ant6,eid2);
            break;

        case 10:
            printf("Write The Update Campus Location : ");
            scanf("%s", &eid2);
            strcpy(item->ant8,eid2);
            break;

            case 0:
            mainmenu();
            break;

            default:
                system("cls");
                printf("Wrong Entry!! Press Any Key To Edit Again : ");
                getch();
                edit();
                break;
          }
      display();
      getch();
}


///................................. Main Function ................................

int main()
{
    creat();
    mainmenu();
    delay(5);
    getch();
    return 0;
}


///*******************************************  THE  END  ***************************************************






