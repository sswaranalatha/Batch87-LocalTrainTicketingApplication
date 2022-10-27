#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>
#include "../header/header.h"

tr *start1,*new1,*ptr1,*prev1,*last1;
u *start,*new,*ptr,*prev,*last;
int ctr=0;
double fare1;
int add_data1()
{
        if((new1=(tr *)calloc(1,sizeof(tr)))==NULL)
        {
                printf("\nMemory Allocation failed\n");
                return EXIT_FAILURE;
        }
        while(1)
        {
                printf("Enter train number: ");
                scanf("%d",&new1->trno);
                if(new1->trno==0)
                {
                        printf("Train number can't be 0\n");
                        return EXIT_FAILURE;
                }
                if(start1)
                {
                        for(ptr1=start1;(ptr1) && ptr1->trno!=new1->trno;ptr1=ptr1->next);
                        if(ptr1)
                        {
                                printf("\nTrain number %d is duplicate",new1->trno);
                                continue;
                        }
                        else
                                break;
                }
                break;
        }
        while(1)
        {
                printf("\nEnter train name: ");
                scanf("%s",new1->name);
                int max_len=10;
                if(strlen(new1->name)>max_len)
                {
                        printf("\nTrain name should be less than 10 charcters");
                        continue;
                }
                if(isalpha_validation(new1->name))
                {
                        printf("\nTrain name should contain only characters");
                        continue;
                }
                else
                        break;
        }
        while(1)
        {
                printf("\nEnter source name: ");
                scanf("%s",new1->src);
                int max_len=10;
                if(strlen(new1->src)>max_len)
                {
                        printf("\nSource name should be less than 10 characters");
                        continue;
                }
                if(isalpha_validation(new1->src))
                {
                        printf("\nSource name should contain only characters");
                        continue;
                }
                break;
        }
        while(1)
        {
                printf("\nEnter destination name: ");
                scanf("%s",new1->dest);
                int max_len=10;
                if(strlen(new1->dest)>max_len)
                {
                        printf("\nDestination name should be less than 10 characters");
                        continue;
                }
                if(isalpha_validation(new1->dest))
                {
                        printf("\nDestination name should contains only characters");
                        continue;
                }
                break;
        }

        while(1)
        {
                printf("\nEnter the distance between source and destination: ");
                scanf("%f",&new1->dist);
                if((new1->dist <10) || (new1->dist >25))
                {
                        printf("\nDistance should be in the range of 10 km to 25 km");
                        continue;
                }
                else
                        break;
        }
        while(1)
        {
                printf("\nEnter the capacity of the train: ");
                scanf("%f",&new1->capacity);
                if((new1->capacity <100) || (new1->capacity >500))
                {
                        printf("\nCapacity should be in the range of 100 to 500");
                        continue;
                }
                else
                        break;
        }
        while(1)
        {
                printf("\nEnter the fare: ");
                scanf("%lf",&new1->fare);
                if((new1->fare <=5)||(new1->fare >=20))
                {
                        printf("\nFare should be in the range of 5 to 20");
                        continue;
                }
                else
                        break;
        }
        printf("\nTotal seats booked %d",new1->ctr);
        if(!start1)
        {
                start1=new1;
                new1->next=NULL;
        }
        else if(new1->trno<start1->trno)
        {
                new1->next=start1;
                start1=new1;
        }
        else
        {
                for(ptr1=start1;(ptr1) && ptr1->trno<new1->trno;prev1=ptr1,ptr1=ptr1->next);
                prev1->next=new1;
                new1->next=ptr1;
        }
        return EXIT_SUCCESS;
}

int view_data1()
{
        if(!start1)
        {
                printf("\nEMPTY LIST");
                return EXIT_FAILURE;
        }
        printf("\nTRAIN_NO    TRAIN_NAME    SOURCE    DESTINATION    DISTANCE    CAPACITY    FARE   TOTAL_BOOKINGS");
        for(ptr1=start1;(ptr1);ptr1=ptr1->next)
        {
                printf("\n%d----%s----%s----%s----%fkm----%f----%lfper_km----%d\n",ptr1->trno,ptr1->name,ptr1->src,ptr1->dest,ptr1->dist,ptr1->capacity,ptr1->fare,ptr1->ctr);
        }
        printf("\n");
        return EXIT_SUCCESS;
}

int  edit_data1()
{
        int trtrno;
        while(1)
        {
                printf("Enter train number for editing: ");
                scanf("%d",&trtrno);
                if(trtrno==0)
                {
                        printf("\nTrain number can't be 0");
                        return EXIT_FAILURE;
                }
                break;
        }
        for(ptr1=start1;(ptr1) && ptr1->trno!=trtrno;ptr1=ptr1->next);
        if(!ptr1)
        {
                printf("\nTrain number %d not found",trtrno);
                return EXIT_FAILURE;
        }
        printf("Old train name is %s\nSource name is %s\nDestination name is %s\nDistance is %fkm\nCapacity is %f\nFare is %lfper_km",ptr1->name,ptr1->src,ptr1->dest,ptr1->dist,ptr1->capacity,ptr1->fare);
        while(1)
        {
                printf("\nEnter train name: ");
                scanf("%s",ptr1->name);
                int max_len=10;
                if(strlen(ptr1->name)>max_len)
                {
                        printf("\nTrain name should be less than 10 characters");
                        continue;
                }
                if(isalpha_validation(ptr1->name))
                {
                        printf("\nTrain name should have only characters");
                        continue;
                }
                else
                        break;
        }
        while(1)
        {
                printf("\nEnter source name: ");
                scanf("%s",ptr1->src);
                int max_len=10;
                if(strlen(ptr1->src)>max_len)
                {
                        printf("\nSource name should be less than 10 characters");
                        continue;
                }
                if(isalpha_validation(ptr1->src))
                {
                        printf("\nSource name should contains only characters");
                        continue;
                }
                break;
        }
        while(1)
        {
                printf("\nEnter destination name: ");
                scanf("%s",ptr1->dest);
                int max_len=10;
                if(strlen(ptr1->dest)>max_len)
                {
                        printf("\nDestination name should be less than 10 characters");
                        continue;
                }
                if(isalpha_validation(ptr1->dest))
                {
                        printf("\nDestination name should contains only characters");
                        continue;
                }
                break;
        }
        while(1)
        {
                printf("\nEnter the distance between source and destination: ");
                scanf("%f",&ptr1->dist);
                if((ptr1->dist <10) || (ptr1->dist >25))
                {
                        printf("\nDistance in the range of 10 km to 25 km");
                        continue;
                }
                else
                        break;
        }
        while(1)
        {
                printf("\nEnter the capacity of the train: ");
                scanf("%f",&ptr1->capacity);
                if((ptr1->capacity <100) || (ptr1->capacity >500))
                {
                        printf("\nCapacity should be in the range of 100 to 500");
                        continue;
                }
                else
                        break;
        }
        while(1)
        {
                printf("\nEnter the fare: ");
                scanf("%lf",&ptr1->fare);
                if((ptr1->fare <=5)||(ptr1->fare >=20))
                {
                        printf("\nFare should be in the range of 5 to 20");
                        continue;
                }
                else
                        break;
        }
        return EXIT_SUCCESS;
}

int delete_data1()
{
        int mtrno;
        while(1)
        {
                printf("\nEnter train number for deleting: ");
                scanf("%d",&mtrno);
                if(mtrno==0)
                {
                        printf("\nTrain number can't be 0");
                        return EXIT_FAILURE;
                }
                break;
        }
        if(mtrno==start1->trno)
        {
                ptr1=start1;
                start1=start1->next;
                free(ptr1);
        }
        else
        {
                for(ptr1=start1;(ptr1) && ptr1->trno!=mtrno;prev1=ptr1,ptr1=ptr1->next);
                if(!ptr1)
                {
                        printf("\nTrain number %d not found for deletion",mtrno);
                        return EXIT_FAILURE;
                }
                prev1->next=ptr1->next;
                free(ptr1);
        }
        return EXIT_SUCCESS;
}

int isalpha_validation(char *str)
{
        for(char *p=str;*p!='\0';p++)
        {
                if(!isalpha(*p))
                {
                        return 1;
                }
        }
        return 0;
}

int register_data()
{
 if((new=(u *)calloc(1,sizeof(u)))==NULL)
        {
                printf("\nMemory allocation failed\n");
                return EXIT_FAILURE;
        }
        while(1)
        {
                int flag,aadno;
                //Taking input of aadhar no
                printf("\nEnter aadhar no:\n");
                scanf("%d",&aadno);
                for(ptr=start;(ptr);ptr=ptr->next)
                {
                        if(ptr->aadno==aadno)
                        {
                                flag=1;
                                break;
                        }
                }
                if(flag==1)
                {
                        printf("Aadhar number already exist");
                        return 0;
                }
                if(aadno<100000|| aadno>999999) //Checking if the length of the aadhar no should be 6 digits only else it will print invalid message
                {
                        printf("\nINVALID LENGTH\nLength should be of 6 digits");
                        continue;
                }
                else
                {
                        new->aadno=aadno;
                        break;
                }
        }
        while(1)
        {
                printf("\nEnter user_name: ");
                scanf("%s",new->name);
                int MAX_LEN=5;
                if(strlen(new->name)<MAX_LEN)
                {
                        printf("\nName should have more than 5 characters");
                        continue;
                }
                if(isalpha_validation(new->name))
                {
                        printf("\nName should contain only characters");
                        continue;
                }
                else
                        break;
        }
        while(1)
        {
                printf("\nEnter your password: ");
                scanf("%s",new->pswd);
                if((strlen(new->pswd)<=5)||(strlen(new->pswd)>=10))
                {
                        printf("\nYour password should be in the range of 5 to 10");
                        continue;
                }
                if(isalpha_validation(new->pswd))
                {
                        printf("\nPassword should contain only characters");
                        continue;
                }
                else
                        break;
        }
        while(1)
        {
                printf("\nEnter your phone number: ");
                scanf("%s",new->phno);
                if(strlen(new->phno)!=10)
                {
                        printf("\nPhone number should contain only 10 digits");
                        continue;

                }
                else
                        break;
        }
        while(1)
        {

                printf("\nEnter your gender(Female/Male/Pns): ");
                scanf("%s",new->gender);
                if(isalpha_validation(new->gender))
                {
                        printf("\nGender should be Female/Male/Pns");
                        continue;
                }
                if(((strcmp(new->gender,"Female"))==0) || ((strcmp(new->gender,"Male"))==0) || ((strcmp(new->gender,"Pns"))==0))
                {
                        printf("\nYour gender is %s",new->gender);
                        break;
                }
                else
                {
                        printf("\nInvalid Gender");
                        continue;
                }
        }
        while(1)
        {
                printf("\nEnter the amount to deposit: ");
                scanf("%lu",&new->deposit);
                int MAX_LEN=500;
                if(new->deposit<MAX_LEN)
                {
                        printf("\nSORRY! we cannot proceed with your registration");
                        printf("\nMinimum deposit should be 500");
                        continue;
                }
                else
			printf("\n REGISTRATION SUCCESSFUL\n");
                        break;
        }
        if(!start)
        {
                start=new;
                new->next=NULL;
        }
        else if(new->aadno<start->aadno)
        {
                new->next=start;
                start=new;
        }
        else
        {
                for(ptr=start;(ptr) && ptr->aadno<new->aadno;prev=ptr,ptr=ptr->next);
                prev->next=new;
                new->next=ptr;
        }
        return EXIT_SUCCESS;
}

int view_data()
{
        if(!start)
        {
                printf("\nEmpty List");
                return EXIT_FAILURE;
        }
        printf("\nAADHAR_NO       USER_NAME      PASSWORD      PHONE_NUMBER      GENDER      DEPOSIT");
        for(ptr=start;(ptr);ptr=ptr->next)
        {
                printf("\n   %d      %s       %s      %s      %s       %lu\n",ptr->aadno,ptr->name,ptr->pswd,ptr->phno,ptr->gender,ptr->deposit);
        }
        printf("\n");
        return EXIT_SUCCESS;
}

int  edit_data()
{
        int  uaadno;
        while(1)
        {
                printf("\nEnter your aadhar number for editing: ");
                scanf("%d",&uaadno);
                if(uaadno==0)
                {
                        printf("\nAadhaar number can't be 0");
                        return EXIT_FAILURE;
                }
                break;
        }
        for(ptr=start;(ptr) && ptr->aadno!=uaadno;ptr=ptr->next);
        if(!ptr)
        {
                printf("\nAadhar number %d not found",uaadno);
                return EXIT_FAILURE;
        }
        printf("Old user name is %s\nPassword is %s\nPhone number  is %s\nGender  is %s\nDeposit money is %lu",ptr->name,ptr->pswd,ptr->phno,ptr->gender,ptr->deposit);
        while(1)
        {
                printf("\nEnter user name: ");
                scanf("%s",ptr->name);
                int MAX_LEN=5;
                if(strlen(ptr->name)<MAX_LEN)
                {
                        printf("Name should have more than 5 characters");
                        continue;
                }
                if(isalpha_validation(ptr->name))
                {
                        printf("\nName should contain only characters");
                        continue;
                }
                else
                        break;
        }
        while(1)
        {
                printf("\nEnter your password: ");
                scanf("%s",ptr->pswd);
                if((strlen(ptr->pswd)<=5)||(strlen(ptr->pswd)>=10))
                {
                        printf("\nYour password should be in the range of 5 to 10");
                        continue;
                }
                if(isalpha_validation(ptr->pswd))
                {
                        printf("\nPassword should contain only characters");
                        continue;
                }
                else
                        break;
        }
        while(1)
        {
                printf("\nEnter your phone number: ");
                scanf("%s",ptr->phno);
                if(strlen(ptr->phno)!=10)
                {
                        printf("\nPhone number should contain only 10 digits");
                        continue;

                }
                else
                        break;
        }
        while(1)
        {

                printf("Enter your gender(Female/Male/Pns): ");
                scanf("%s",ptr->gender);
                if(isalpha_validation(ptr->gender))
                {
                        printf("\nGender should be Female/Male/Pns");
                        continue;
                }
                if(((strcmp(ptr->gender,"Female"))==0) || ((strcmp(ptr->gender,"Male"))==0) || ((strcmp(ptr->gender,"Pns"))==0))
                {
                        printf("\nYour gender is %s",ptr->gender);
                        break;
                }
                else
                {
                        printf("\nInvalid Gender");
                        continue;
                }
        }
        while(1)
        {
                printf("\nEnter the amount to deposit: ");
                scanf("%lu",&ptr->deposit);
                int MAX_LEN=500;
                if(ptr->deposit<MAX_LEN)
                {
                        printf("SORRY! we cannot proceed with your edit");
                        printf("\nMinimum deposit should be 500");
                        continue;
                }
                else
                        break;
        }
        return EXIT_SUCCESS;
}

int delete_data()
{
        if(!start)
        {
                printf("\nEmpty List");
                return EXIT_FAILURE;
        }

        int uuaadno;
        while(1)
        {
                printf("\nEnter your aadhar no for editing: ");
                scanf("%d",&uuaadno);
                if(uuaadno==0)
                {
                        printf("\nAadhaar no can't be 0");
                        return EXIT_FAILURE;
                }
                break;
        }
        if(uuaadno==start->aadno)
        {
                ptr=start;
                start=start->next;
                free(ptr);
        }
        else
        {
                for(ptr=start;(ptr) && ptr->aadno!=uuaadno;prev=ptr,ptr=ptr->next);
                if(!ptr)
                {
                        printf("\nAadhar no %d not found for deletion",uuaadno);
                        return EXIT_FAILURE;
                }
                prev->next=ptr->next;
                free(ptr);
        }
        return EXIT_SUCCESS;
}

int user_file_to_list()
{
        FILE *p4;
        ud t1;
        if((p4=fopen("../data/myuser","rb"))==NULL)
        {
                printf("\nNO FILE EXIST");
                return EXIT_FAILURE;
        }
        fread(&t1,sizeof(ud),1,p4);
        while(!feof(p4))
        {
                if((new=(u *)calloc(1,sizeof(u)))==NULL)
                {
                        printf("\nMemory Allocation failed");
                        return EXIT_FAILURE;
                }
                new->aadno=t1.aadno;
                strcpy(new->name,t1.name);
                strcpy(new->pswd,t1.pswd);
                strcpy(new->phno,t1.phno);
                strcpy(new->gender,t1.gender);
                new->deposit=t1.deposit;
                if(!start)
                {
                        start=last=new;
                        new->next=NULL;
                }
                else
                {
                        last->next=new;
                        last=new;
                        new->next=NULL;
                }
                fread(&t1,sizeof(ud),1,p4);
        }
        fclose(p4);
        return EXIT_SUCCESS;
}

int user_list_to_file()
{
        ud t2;
        if(!start)
        {
                printf("\nLIST IS EMPTY");
                return EXIT_FAILURE;
        }
        FILE *p5;
        if((p5=fopen("../data/myuser","wb"))==NULL)
        {
                printf("\nNO FILE EXIST");
                return EXIT_FAILURE;
        }
        for(ptr=start;(ptr);prev=ptr,ptr=ptr->next)
        {
                t2.aadno=ptr->aadno;
                strcpy(t2.name,ptr->name);
                strcpy(t2.pswd,ptr->pswd);
                strcpy(t2.phno,ptr->phno);
                strcpy(t2.gender,ptr->gender);
                t2.deposit=ptr->deposit;
                fwrite(&t2,sizeof(ud),1,p5);
                free(prev);
        }
        fclose(p5);
        free(prev);
        return EXIT_SUCCESS;
}
int train_file_to_list()
{
        FILE *p3;
        td t1;
        if((p3=fopen("../data/mytrain","rb"))==NULL)
        {
                printf("\nNO FILE EXIST");
                return EXIT_FAILURE;
        }
        fread(&t1,sizeof(td),1,p3);
        while(!feof(p3))
        {
                if((new1=(tr *)calloc(1,sizeof(tr)))==NULL)
                {
                        printf("\nMemory Allocation failed");
                        return EXIT_FAILURE;
                }
                new1->trno=t1.trno;
                strcpy(new1->name,t1.name);
                strcpy(new1->src,t1.src);
                strcpy(new1->dest,t1.dest);
                new1->dist=t1.dist;
                new1->capacity=t1.capacity;
                new1->fare=t1.fare;
                new1->ctr=t1.ctr;
                if(!start1)
                {
                        start1=last1=new1;
                        new1->next=NULL;
                }
                else
                {
                        last1->next=new1;
                        last1=new1;
                        new1->next=NULL;
                }
                fread(&t1,sizeof(td),1,p3);
        }
        fclose(p3);
        return EXIT_SUCCESS;
}

int train_list_to_file()
{
        td t2;
        if(!start1)
        {
                printf("\nLIST IS EMPTY");
                return EXIT_FAILURE;
        }
        FILE *p2;
        if((p2=fopen("../data/mytrain","wb"))==NULL)
        {
                printf("\nNO FILE EXIST");
                return EXIT_FAILURE;
        }
        for(ptr1=start1;(ptr1);prev1=ptr1,ptr1=ptr1->next)
        {
                t2.trno=ptr1->trno;
                strcpy(t2.name,ptr1->name);
                strcpy(t2.src,ptr1->src);
                strcpy(t2.dest,ptr1->dest);
                t2.dist=ptr1->dist;
                t2.capacity=ptr1->capacity;
                t2.fare=ptr1->fare;
                t2.ctr=ptr1->ctr;
                fwrite(&t2,sizeof(td),1,p2);
                free(prev1);
        }
        fclose(p2);
        free(prev1);
        return EXIT_SUCCESS;
}
int book_ticket()
{

        int a,flag=0,flag1=0,no;
        char p[15];
        char s[50];
        char d[50];
        double rate=0;
        double f1;
        unsigned long deposit1=0;
        unsigned long deposit2;
        while(1)
        {


                while(1)
                {
                        printf("\nEnter your aadhar number: ");
                        scanf("%d",&a);
                        if(a==0)
                        {
                                printf("\nAadhaar number can't be 0");
                                return EXIT_FAILURE;
                        }
                        break;
                }

                while(1)
                {
                        printf("\nEnter your password: ");
                        scanf("%s",p);
                        if((strlen(p)<=5)||(strlen(p)>=10))
                        {
                                printf("\nPassword should be in the range of 5 to 10");
                                continue;
                        }
                        if(isalpha_validation(p))
                        {
                                printf("\nPassword should contain only characters");
                                continue;
                        }
                        else
                                break;
                }
                for(ptr=start;(ptr);ptr=ptr->next)
                {

                        if((strcmp(ptr->pswd,p)==0)&&(ptr->aadno==a))
                        {
                                flag=1;
                                break;
                        }


                }
                if(flag==1)
                {

                        printf("\nYour login is successful!!! Continue booking");
                        break;
                }
                else
                {
                        printf("\nINVALID DETAILS! try again");
                        return EXIT_FAILURE;
                }

        }
        while(1)
        {
                printf("\nEnter source name: ");
                scanf("%s",s);
                int max_len=10;
                if(strlen(s)>max_len)
                {
                        printf("\nSource name should be less than 10 characters");
                        continue;
                }
                if(isalpha_validation(s))
                {
                        printf("\nSource name should contain only characters");
                        continue;
                }
                break;
        }
        while(1)
        {
                printf("\nEnter destination name: ");
                scanf("%s",d);
                int max_len=10;
                if(strlen(d)>max_len)
                {
                        printf("\nDestination name should be less than 10 characters");
                        continue;
                }
                if(isalpha_validation(d))
                {
                        printf("\nDestination name should contain only characters");
                        continue;
                }
                break;

        }
        while(1)
        {
                for(ptr1=start1;(ptr1);ptr1=ptr1->next)
                {
                        if((strcmp(ptr1->src,s)==0) && (strcmp(ptr1->dest,d)==0))
                        {
                                printf("\nTRAIN_NO    TRAIN_NAME    SOURCE    DESTINATION    DISTANCE    CAPACITY    FARE");
                                printf("\n%d    %s    %s    %s    %fkm    %f    %lfper_km\n",ptr1->trno,ptr1->name,ptr1->src,ptr1->dest,ptr1->dist,ptr1->capacity,ptr1->fare);
                        }

                }
                printf("\nSelect train number: ");
                scanf("%d",&no);

                for(ptr1=start1;(ptr1);ptr1=ptr1->next)
                {

                        if((no==ptr1->trno) && (strcmp(ptr1->src,s)==0) && (strcmp(ptr1->dest,d)==0))
                        {
                                flag1=1;
                                break;
                        }
                }
                if(flag1==1)
                {
                        if(ptr1->capacity<ptr1->ctr)
                        {
                                printf("\nSORRY! the train is full");
                                break;
                        }
                        else
                        {
                                printf("\nYour train number is %d\nYour train name is %s",ptr1->trno,ptr1->name);
                                break;
                        }
                }

                else
                {
                        printf("\nINVALID DETAIL");
                        return EXIT_FAILURE;
                }
        }

        int ticket=0;
        int chc=0,chc1=0;
        double discount=20;
        double discount1;
        while(ticket!=3)
        {
                printf("\nChoose your ticket");
                printf("\n\t1.Daily ticket\n\t2.Monthly ticket\n\t3.Exit");
                printf("\nEnter your choice: ");
                scanf("%d",&ticket);
                switch(ticket)
                {
                        case 1:printf("\nWelcome to Daily ticket booking\nYour ticket rate details are here\n");
                               printf("\nTrain fare is %lfper_km\n",ptr1->fare);
                               fare1=ptr1->fare*ptr1->dist;
                               printf("Your fare per km for this train is %lf\n",fare1);
                               if(fare1>ptr->deposit)
                               {
                                       printf("TICKET DENIED");
                                       printf("\nYour balance is insufficient\nRe-deposit money to book yout ticket");
                                       return EXIT_FAILURE;
                               }

                               deposit1=((ptr->deposit)-(fare1));
                               ptr->deposit=deposit1;
                               printf("\nNow your balance is %lu\n",ptr->deposit);
                               if(ptr->deposit<=100)
                               {
                                       printf("\nYour deposit is less than 100rupees");
                                       printf("\n\t1.Re-deposit\n\t2.Exit");
                                       printf("\nEnter your choice: ");
                                       scanf("%d",&chc);
                                       switch(chc)
                                       {
                                               case 1:printf("\nEnter your re-deposit amount: ");
                                                      scanf("%lu",&deposit2);
                                                      ptr->deposit=ptr->deposit+deposit2;
                                                      printf("\nNow your balance is %lu\n",ptr->deposit);
                                                      break;
                                               case 2:break;
                                               default:printf("\nInvalid choice");
                                       }

                                       return EXIT_FAILURE;
                               }
                               ptr1->ctr=ptr1->ctr+1;
                               printf("***HAPPY JOURNEY***\n");
                               while(chc1!=3)
                               {
                                       printf("\n\t1.Printf Ticket\n\t2.Exit");
                                       printf("\nEnter your choice: ");
                                       scanf("%d",&chc1);
                                       switch(chc1)
                                       {
                                               case 1:make_journey();
                                                      break;
                                               case 2:break;
                                               default :printf("\nINVALID CHOICE");
                                       }
                                       return EXIT_FAILURE;
                               }
                               break;
                         case 2:printf("\nWelcome to monthly ticket booking\nYour ticket rate details are here");
                               fare1=ptr1->fare*ptr1->dist;
                               printf("Your fare for this train is %lfper_km\n",fare1);
                               f1=fare1*30;
                               printf("\nYour fare per km for this monthly ticket is %lf\n",f1);
                               discount1=((f1)*(discount/100));
                               printf("\nDiscount-%lf",discount1);
                               rate=f1-discount1;
                               printf("\nYour ticket rate is %lf\n",rate);
                               if(rate>ptr->deposit)
                               {
                                       printf("\nYour balance is insufficient\nYour ticket is denied");
                                       return EXIT_FAILURE;
                               }
                               deposit1=ptr->deposit-rate;
                               ptr->deposit=deposit1;
                               printf("\nNow your deposite is-%lu",ptr->deposit);
                               if(ptr->deposit<=100)
                               {
                                       printf("\nYour deposit is less than 100rupees\nRe-deposit money to book your ticket");
                                       printf("\n\t1.Redeposit\n\t2.Exit");
                                       printf("\nEnter your choice: ");
                                       scanf("%d",&chc);
                                       switch(chc)
                                       {
                                               case 1:printf("\nEnter your re-deposit amount: ");
                                                      scanf("%lu",&deposit2);
                                                      ptr->deposit=ptr->deposit+deposit2;
                                                      printf("\nNow your is balance is %lu",ptr->deposit);
                                                      break;
                                               case 2:break;
                                               default:printf("\nINVALID CHOICE");
                                       }
                                       return EXIT_FAILURE;
                               }
                               ptr1->ctr=ptr1->ctr+1;
                               printf("***HAPPY JOURNEY***\n");
                               while(chc1!=3)
                               {
                                       printf("\n\t1.Printf Ticket\n\t2.Exit");
                                       printf("\nEnter your choice: ");
                                       scanf("%d",&chc1);
                                       switch(chc1)
                                       {
                                               case 1:make_journey();
                                                      break;
                                               case 2:break;
                                               default :printf("\nINVALID CHOICE");
                                       }
                                       return EXIT_FAILURE;
                               }
                               break;
                        case 3:break;
                        default:printf("\nINVALID CHOICE");
                }
        }
        return EXIT_SUCCESS;

}

int make_journey()
{
        printf("\nYOUR TRAIN TICKET IS HERE");
        printf("\nTrain number %d\nTrain name %s\nSource %s\nDestination %s\nDistance %fkm",ptr1->trno,ptr1->name,ptr1->src,ptr1->dest,ptr1->dist);
}

int mreport()
{

        if(!start)
        {
                printf("NO RECORDS AVAILABLE\n");
                return EXIT_FAILURE;
        }
        int max=0;
        int c;
        char *name;
        char *source,*destination;
        for(ptr1=start1;(ptr1);ptr1=ptr1->next)
        {
                if(ptr1->ctr > max)
                {
                        max=ptr1->ctr;
                        c=ptr1->trno;
                        name=ptr1->name;
                        source=ptr1->src;
                        destination=ptr1->dest;


                }
        }
        printf("\nTrain number %d\nTrain name %s\nSource name %s\nDestination %s\nTrain with maximum booking %d",c,name,source,destination,max);
}
int min_bal_data()
{

        if(!start)
        {
                printf("\nEMPTY LIST\n");
                return EXIT_FAILURE;
        }
        printf("\nAADHAR_NUMBER      USER_NAME      PHONE_NUMBER      GENDER       PASSWORD      DEPOSIT\n");
        for(ptr=start;(ptr);ptr=ptr->next)
        {
                if(ptr->deposit<=100)
                {
                        printf("\n%d------%s------%s------%s------%s------%lu",ptr->aadno,ptr->name,ptr->phno,ptr->gender,ptr->pswd,ptr->deposit);
                }

        }
        printf("\n");
        return EXIT_SUCCESS;
}


