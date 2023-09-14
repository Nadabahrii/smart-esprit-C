#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <gtk/gtk.h>
typedef struct
{
char First_Name[50];
char Last_Name[50];
char Username[50];
char Password[50];
int Role;
}user ;

/*partie1*/
void add_user(user u);
int find_user(char username[]);
void delete_user(char username[]);
void update_user(user u,char username[]);
void display_user_info(GtkWidget *liste);
int verif(char log[], char Pw[]);
/*partie 2*/
int student_number(int specialite);
void empty(GtkWidget *liste);
#endif // FONCTION_H_INCLUDED 




