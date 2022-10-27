#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "train_header.h"

int main()
{
        user_file_to_list();
        train_file_to_list();
        int ch2=0;
        while(ch2!=3)
        {

   
                printf("========================================================\n");
                printf("************WELCOME TO LOCAL TRAIN TICKETING************\n");
                printf("========================================================\n");
                printf("\n\n\t1.Admin Corner\n\t2.User Corner\n\t3.Exit");
                printf("\nEnter your choice: \n");
                scanf("%d",&ch2);
                switch(ch2)
                {
                        case 1:admin();
                               break;
                        case 2:user();
                               break;
                        case 3:break;
                        default:printf("\nINVALID CHOICE");
                }
        }
        train_list_to_file();
        user_list_to_file();
         return 1;
}

char admin_pswd[10]="abc";
int admin()
{
        char pswd[10];
        while(1)
        {

	        //system("clear");
                printf("\nEnter password: ");
                scanf("%s",pswd);
                if((strcmp(pswd,admin_pswd))==0)

                {
                        printf("\nCorrect password");
                        break;
                }
                else
                {
                        printf("\nWrong password, please try again!");
                        continue;
                }
        }
        int ch7=0;
        while(ch7!=4)
        {

               // system("clear");
                printf("\n_______________________________________");
                printf("\n************ADMIN CORNER************");
                printf("\n_______________________________________");
                printf("\n\n\t1.Maintain User\n\t2.Maintain Train\n\t3.Reports\n\t4.Back");
                printf("\nEnter your choice: ");
                scanf("%d",&ch7);
                switch(ch7)
                {
                        case 1:user_maintain();
                               break;
                        case 2:train();
                               break;
                        case 3:reports();
                               break;
                        case 4:break;
                        default:printf("\nINVALID CHOICE\n");
                }
        }
        return 1;
}

int user_maintain()
{
        int ch=0;
        while(ch!=5)
        {

	        //system("clear");
                printf("\n___________________________________________");
                printf("\n************USER DATABASE************");
                printf("\n___________________________________________");
                printf("\n\n\t1.Register Data\n\t2.Edit Data\n\t3.Delete Data\n\t4.View Data\n\t5.Exit");
                printf("\nEnter choice-");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:register_data();
                               break;
                        case 2:edit_data();
                               break;
                        case 3:delete_data();
                               break;
                        case 4:view_data();
                               break;
                        case 5:break;
                        default:printf("\nINVALID CHOICE\n");
                }
        }
        return 1;
}
int train()
{
        int ch1=0;
        while(ch1!=5)
        {

	        //system("clear");
                printf("\n____________________________________");
                printf("\n************TRAIN DATABASE************");
                printf("\n____________________________________");
                printf("\n\n\t1.Add Data\n\t2.Edit Data\n\t3.Delete Data\n\t4.View Data\n\t5.Exit");
                printf("\nEnter choice-");
                scanf("%d",&ch1);
                switch(ch1)
                {
                        case 1:add_data1();
                               break;
                        case 2:edit_data1();
                               break;
                        case 3:delete_data1();
                               break;
                        case 4:view_data1();
                               break;
                        case 5:break;
                        default:printf("\nInvalid choice\n");
                }
        }
        return 1;
}

int reports()
{
        int ch8=0;
        while(ch8!=3)
        {

	        //system("clear");
                printf("\n____________________________________");
                printf("\n************ADMIN DATABASE************");
                printf("\n____________________________________");
                printf("\n\n\t1.Max_booking report\n\t2.Minimum balance report\n\t3.Back");
                printf("\nEnter choice-");
                scanf("%d",&ch8);
                switch(ch8)
                {
                        case 1:mreport();
                               break;
                        case 2:min_bal_data();
                               break;
                        case 3:break;
                        default:printf("\nINVALID CHOICE\n");
                }
        }
        return 1;
}

int user()
{
        int ch5=0;
        while(ch5!=5)
        {

	        //system("clear");
                printf("\n_____________________________________");
                printf("\n************TRAIN DATABASE************");
                printf("\n_____________________________________");
                printf("\n\n\t1.Register Data\n\t2.Edit Data\n\t3.Make Journey\n\t4.Max_booking report\n\t5.Back");
                printf("\nEnter choice-");
                scanf("%d",&ch5);
                switch(ch5)
                {
                        case 1:register_data();
                               break;
                        case 2:edit_data();
                               break;
                        case 3:book_ticket();
                               break;
                        case 4:mreport();
                               break;
                        case 5:break;
                        default:printf("\nINVALID CHOICE\n");
                }
        }
        return 1;
}

