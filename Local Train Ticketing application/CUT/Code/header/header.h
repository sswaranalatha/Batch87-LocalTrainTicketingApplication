#ifndef TRAIN_HEADER_H
#define TRAIN_HEADER_H
#pragma pack(1)
typedef struct train
{
     int trno;
     char name[50];
     char src[50];
     char dest[50];
     float dist;
     float capacity;
     double fare;
     int ctr;
     struct train *next;
}tr;
typedef struct train_database
{
     int trno;
     char name[50];
     char src[50];
     char dest[50];
     float dist;
     float capacity;
     double fare;
     int ctr;

}td;


typedef struct user
{
     int aadno;
     char name[20];
     char phno[20];
     unsigned long deposit;
     char pswd[15];
     char gender[15];
     struct user *next;
}u;
typedef struct user_details
{
     int aadno;
     char name[20];
     char phno[20];
     unsigned long deposit;
     char pswd[15];
     char gender[15];

}ud;

int admin();
int user_maintain();
int register_data();
int edit_data();
int delete_data();
int view_data();
int train();
int add_data1();
int edit_data1();
int delete_data1();
int view_data1();
int reports();
int mreport();
int min_bal_data();
int user();
int book_ticket();
int daily_ticket();
int monthly_ticket();
int make_journey();
int train_file_to_list();
int train_list_to_file();
int check_digit();
int isalpha_validation();
int user_file_to_list();
int user_list_to_file();
#endif

