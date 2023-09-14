#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
char First_Name[];
char Last_Name[];
char Username[];
char Password[];
int role;
}user ;

/*partie1*/
Void add_user(user u,user tab[],int*n);
int find_user(user u,user tab[],int n);
int delete_user(user u,user tab[],int n);
void update_user(user u,user tab[],int n);
void display_user_info(user u,user tab[],int n);
int check(user u,user tab[],int n);
/*partie 2*/
int student_number(int role, user tab[],int n);
