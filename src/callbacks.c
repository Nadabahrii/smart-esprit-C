#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctionZA.h"
int specialite=1;

void sendmail(char body[])
{
        char cmd[1000];
        FILE *fp = fopen("mail.txt","w+"); // open it for writing.
        fprintf(fp,"%s\n",body);        // write body to it.
        fclose(fp);             // close it.

        sprintf(cmd,"curl smtps://smtp.gmail.com:465 -v --mail-from \"smartesprit86@gmail.com:&azerty123\" --mail-rcpt \"achref.zaier@esprit.tn\" --ssl -u smartesprit86@gmail.com:&azerty123 -T mail.txt -k --anyauth"); // prepare command.
        system(cmd);     // execute it.
}
void
on_buttonSignup_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{

FILE *f=NULL;
GtkWidget *fname;
GtkWidget *lname;
GtkWidget *uname;
GtkWidget *pw;
GtkWidget *spinbutton1;
GtkWidget *windowLogin;
GtkWidget *output;
char first_name[20];
char last_name[20];
char user_name[20];
char passw[20];
int r;
int trouve;
char ch[20];
fname=lookup_widget(objet,"entryFirstName");
lname=lookup_widget(objet,"entryLastName");
uname=lookup_widget(objet,"entryUsername");
pw=lookup_widget(objet,"entryPassword");

strcpy(first_name,gtk_entry_get_text(GTK_ENTRY(fname)));
strcpy(last_name,gtk_entry_get_text(GTK_ENTRY(lname)));
strcpy(user_name,gtk_entry_get_text(GTK_ENTRY(uname)));
strcpy(passw,gtk_entry_get_text(GTK_ENTRY(pw)));
r=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1));
trouve=verif(user_name ,passw);
if(trouve==1) 
{
output = lookup_widget(objet, "label72") ;
strcpy(ch,"*used !!");
gtk_label_set_text(GTK_LABEL(output),ch);
}
else
	{
		f=fopen("utlisateur.txt","a");
		if(f!=NULL)
		{
		fprintf(f,"%s %s %s %s %d \n",first_name,last_name,user_name,passw,r);
		fclose(f);
		windowLogin=create_Login();
		gtk_widget_show(windowLogin);
		}
	}



}



void
on_buttonLogin_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *username,*password, *windowAdmin , *output,*Login;
char user[20];
char pasw[20];
char ch[90];
int trouve ;
username = lookup_widget (objet, "entryUsername_Login");
password = lookup_widget (objet, "entryPassword_Login");

strcpy(user, gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(pasw, gtk_entry_get_text(GTK_ENTRY(password)));
trouve=verif(user,pasw);

if (trouve==1)
{
windowAdmin=create_Admin();
Login=lookup_widget(objet,"Login");
gtk_widget_destroy(Login);
gtk_widget_show(windowAdmin);
}
else 
{


output = lookup_widget(objet, "label6") ;
strcpy(ch,"User not found,create your account");
gtk_label_set_text(GTK_LABEL(output),ch);
}

}
int confirmation;
void
on_checkbuttonyes_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
	{
		confirmation=1;
	}
}


void
on_checkbuttonno_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
	{
		confirmation=0;
	}
}



void
on_Delete_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{	char ch[20];
	char ch1[20];
	char ch2[20];
	user u ;
	GtkWidget *input ,*output1 ,*output2;
	input=lookup_widget(objet,"entry10");     
	strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input)));
	if(confirmation==1)
	{	
		delete_user(ch);
		output1=lookup_widget(objet,"label102") ;
		strcpy(ch1,"sucessfully deleted");
		gtk_label_set_text(GTK_LABEL(output1),ch1);
		
	}
	if(confirmation==0)
	{
		output2=lookup_widget(objet,"label101") ;
		strcpy(ch2,"**please confirm !");
		gtk_label_set_text(GTK_LABEL(output2),ch2);
	}
}

void
on_button_search_clicked                     (GtkButton       *button,
                 	                       gpointer         user_data)
{
	GtkWidget *output ,*output1 ,*output2,*output3,*output4,*output5,*output6,*Window;	
	char ch[20];
	char ch1[20];
	char ch2[20];
	char ch3[20];
	char ch4[20];
	int ch5[20];
	char ch6[20];
	char ch7[20];
	int x ;
	user u ;
	GtkWidget *input ,*comboboxZA;
	FILE *f=NULL;
	f=fopen("utlisateur.txt","r");

	input=lookup_widget(button,"entry11");
	strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input)));
	x=find_user(ch); 
	comboboxZA=lookup_widget(button,"comboboxZA");
	strcpy(ch7,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxZA)));	
		
	if(f!=NULL)
	{
	if(x==1)
	{
		
		while(fscanf(f,"%s %s %s %s %d \n",ch1,ch2,ch3,ch4,&ch5)!=EOF)
		{
		if(strcmp(ch3,ch)==0)
		{
		//Window=create_Window2();
		//gtk_widget_show(Window);		
			if(strcmp("AllIInformation",ch7)==0)
			{
			output1 = lookup_widget(button, "label92") ;
			output2 = lookup_widget(button, "label93") ;
			output3 = lookup_widget(button, "label94") ;
			output4 = lookup_widget(button, "label95") ;
			output5 = lookup_widget(button, "label96") ;	
				
			gtk_label_set_text(GTK_LABEL(output1),ch1);
			gtk_label_set_text(GTK_LABEL(output2),ch2);
			gtk_label_set_text(GTK_LABEL(output3),ch3);
			gtk_label_set_text(GTK_LABEL(output4),ch4);
			sprintf(ch6,"%d",*ch5);
			gtk_label_set_text(GTK_LABEL(output5),ch6);
			}
			if(strcmp("ExistorNot",ch7)==0)
			{
				output6= lookup_widget(button, "label104") ;
				strcpy(ch1,"User found !");
				gtk_label_set_text(GTK_LABEL(output6),ch1);
			}
		}
		}
		
	}
	if(x==0)
	{
		output = lookup_widget(button, "label57") ;
		strcpy(ch1,"User not found");
		gtk_label_set_text(GTK_LABEL(output),ch1);
	}
	}
	
}

void
on_Update_Update_clicked                     (GtkWidget       *objet,
	                                        gpointer         user_data)
{
	
	user u ;
	char ch[20] ;
	GtkWidget *input1 , *input2 , *input3 ,*input4 , *spinbutton3 ;
	
	
	input1=lookup_widget(objet,"entry12");
	input2=lookup_widget(objet,"entry13");
	input3=lookup_widget(objet,"entry14");
	input4=lookup_widget(objet,"entry15");
	spinbutton3=lookup_widget(objet,"spinbutton3");

	strcpy(u.First_Name , gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(u.Last_Name , gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(u.Username , gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(u.Password , gtk_entry_get_text(GTK_ENTRY(input4)));
	u.Role=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton3));
	strcpy(ch , u.Username) ;
	update_user(u,ch) ;
}



void
on_add_add_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	char ch[20] ;
	int trouve ;	
	user u ;
	GtkWidget *input1 , *input2 , *input3 ,*input4 , *spinbutton1 ,*output ;
	
	
	input1=lookup_widget(objet,"entry6");
	input2=lookup_widget(objet,"entry7");
	input3=lookup_widget(objet,"entry8");
	input4=lookup_widget(objet,"entry9");
	spinbutton1=lookup_widget(objet,"spinbutton1");
	

	strcpy(u.First_Name , gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(u.Last_Name , gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(u.Username , gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(u.Password , gtk_entry_get_text(GTK_ENTRY(input4)));
	u.Role=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1));
	trouve=find_user(u.Username);
if(trouve==1) 
{
output = lookup_widget(objet, "label86") ;
strcpy(ch,"*used !!");
gtk_label_set_text(GTK_LABEL(output),ch);
}
else
	{
	add_user(u);
	sendmail("you have a new user");	
	}
	


}	


void
on_Display_add_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Admin;
	GtkWidget *Window1;
	GtkWidget *treeview1 ;
	
	

	Admin=lookup_widget(button,"Admin");
	gtk_widget_destroy(Admin);
	Window1=lookup_widget(button,"Window1") ;
	Window1=create_window1();

	gtk_widget_show(Window1) ;

	treeview1=lookup_widget(Window1 , "treeview1");
	
	display_user_info(treeview1);
	
}



void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter ;
	GtkCellRenderer *renderer;
	GtkListStore *store;
	gchar* First_Name ;
	gchar* Last_Name ;
	gchar* Username ; 
	gchar* Password ;
	gint* Role ;
	user u; 

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{
		gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &First_Name,1,&Last_Name,2,&Username,3,&Password,4,&Role,-1) ;

		strcpy(u.First_Name,First_Name);
		strcpy(u.Last_Name,Last_Name);
		strcpy(u.Username,Username);
		strcpy(u.Password,Password);
		u.Role=Role;
		
		display_user_info(treeview) ;
	}
	
}


void

on_Refrech_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1 ,*w1;
	GtkWidget *treeview1 ;

	
	w1=lookup_widget(objet,"window1");
	gtk_widget_hide(window1);	
	window1=create_window1() ;
	
	gtk_widget_show(window1);

	gtk_widget_hide(w1);
	treeview1=lookup_widget(window1,"treeview1");
	
	/*empty(treeview1);*/
	display_user_info(treeview1);
}


void
on_Back_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Admin , *window1 ;
	window1=lookup_widget(objet,"window1");	
	Admin=create_Admin();
	gtk_widget_destroy(window1);	
	gtk_widget_show(Admin);

}

































/*void
on_Add_clicked                         (GtkButton       *Button,
                                        gpointer         user_data)
{

}


void
on_Remove_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Update_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Find_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
}


void
on_Check_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_search_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_add_user_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Display_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}

void
on_Refresh_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}*/


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		specialite=1;
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		specialite=2;
}


void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		specialite=6;
}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		specialite=5;
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		specialite=4;
}


void
on_radiobutton7_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		specialite=7;
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		specialite=3;
}


int res=0;
void
on_calcul_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *output ;
char ch1[50];
char ch2[20];
int res;
	res=student_number(specialite);
	if(specialite==7)
	{
	res=student_number(1)+student_number(2)+student_number(3)+student_number(4)+student_number(5)+student_number(6);	
	}
	sprintf(ch2,"%d",res);
	output = lookup_widget(button, "label61") ;
	strcpy(ch1,"vous avez ::: ");
	gtk_label_set_text(GTK_LABEL(output),ch1);
	output = lookup_widget(button, "label63") ;
	gtk_label_set_text(GTK_LABEL(output),ch2);
	

	
}
int choix;

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
		choix=1;
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
		choix=2;
}


void
on_button4_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Sign_up , *Login ;
	Login=lookup_widget(objet,"Login");	
	Sign_up=create_Sign_up();
	gtk_widget_destroy(Login);	
	gtk_widget_show(Sign_up);
}


void
on_button6_Logout_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Login , *Admin ;
	Admin=lookup_widget(objet,"Admin");	
	Login=create_Login();
	gtk_widget_destroy(Admin);	
	gtk_widget_show(Login);
}



