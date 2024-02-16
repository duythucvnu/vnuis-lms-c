#include <stdio.h>
#include <time.h>
#include<string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define MAX_YR  9999
#define MIN_YR  1900
//structure to store book information
struct Book
{
	char bookID[4];
	char name_of_book[30];
	char author[30];
	char category[10];
	char price[10];
	char location[3];
	char available[3];
	char view[8];
}bookinfo;
struct Record
{
	char name[30];
	char studentID[9];
	char bookID[4];
	char book[30];
	char borrow_date[11];
	char return_date[11];
}record;
//structure to store account
struct Account
{
	char user[20];
	char pass[20];
}act;
//structure to store date
struct Date
{
    int yyyy;
    int mm;
    int dd;
}d;
FILE *fp=NULL;
// Function to check leap year.
//Function returns 1 if leap year
struct tm *ts;
//Current date
void date(){
	char buffer[32];
	int cd,cm,cy;
    size_t last;
    time_t timestamp = time(NULL);
    ts   = localtime(&timestamp);
    last = strftime(buffer, 32, "%A", ts);
    buffer[last] = '\0';
	
    printf("\n\t%s, %d/%d/%d\n", buffer, ts->tm_mday, ts->tm_mon + 1, ts->tm_year + 1900);
}

void welcome()
{
    printf("\n\n\n\n\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                 LIBRARY                   =");
    printf("\n\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
    system("cls");
}

void lms(){
		printf("\n\n");
		printf("\n\t\t\t  ******************************************");
		printf("\n\t\t\t  *                                        *");
	    printf("\n\t\t\t  *        LIBRARY MANAGEMENT SYSTEM       *");
	    printf("\n\t\t\t  *                                        *");
	    printf("\n\t\t\t  ******************************************\n\n");
}
void add_book(int option){
	int i=1;
	system("cls");
	date();
	printf("\tHello, admin");
	printf("\n\n");
	printf("\n\t\t\t  ******************************************");
	printf("\n\t\t\t  *                                        *");
	printf("\n\t\t\t  *                 ADD BOOK               *");
	printf("\n\t\t\t  *                                        *");
	printf("\n\t\t\t  ******************************************\n\n");	
	if(option==1){
		while(i==1){
            printf("\n\n\tEnter book ID: ");
            fflush(stdin);
            scanf("%s", &bookinfo.bookID);
            printf("\n\tEnter name of book: ");
            fflush(stdin);
            scanf("%[^\n]",&bookinfo.name_of_book);
            printf("\n\tEnter author name: ");
            fflush(stdin);
            scanf("%[^\n]",&bookinfo.author);
            printf("\n\tEnter category: ");
            fflush(stdin);
            scanf("%s",&bookinfo.category);
            printf("\n\tEnter price: ");
            fflush(stdin);
            scanf("%s",&bookinfo.price);
            printf("\n\tEnter location: ");
            fflush(stdin);
            scanf("%s",&bookinfo.location);
            printf("\n\tEnter number of books left: ");
            fflush(stdin);
            scanf("%s",&bookinfo.available);
            strcpy(bookinfo.view,"0");
            fp=fopen("book.txt","ab+");
            fwrite(&bookinfo,sizeof(bookinfo),1,fp);
            fclose(fp);
            printf("\n\n\t\t\tAdd book successfully!!");
            printf("\n\n\t\t\t1. Countinue adding book");
            printf("\n\t\t\t2. Exit");
            printf("\n\n\tYour option => ");
            scanf("%d",&i);
            }
            system("cls");

    }
};
void search_book(int n){
	FILE *temporary,*tmp1,*tmp2;
	int i=1;
    int p=1;
    int size;
	int option=0;
	int view;
	char view2[8];
	char book[30];
    printf("\n\n");
	printf("\n\t\t\t  ******************************************");
	printf("\n\t\t\t  *                                        *");
	printf("\n\t\t\t  *               SEARCH BOOK              *");
	printf("\n\t\t\t  *                                        *");
	printf("\n\t\t\t  ******************************************\n\n");	
	printf("\n\n\t\t1. Search by Name");
    printf("\n\t\t2. Search by Category");
    printf("\n\t\t3. Search by ID");
    printf("\n\t\t4. Search by Author");
    printf("\n\t\t5. Search by Price (less than)");
    printf("\n\t\t6. Exit");
    printf("\n\n\t\tEnter Choice => ");
            fflush(stdin);
            scanf("%d",&option);
            if (option==1)
            {
                printf("\n\n\tEnter name of book: ");
                fflush(stdin);
                scanf("%[^\n]",&book);
                fp=fopen("book.txt","rb+");
                while(fread(&bookinfo,sizeof(bookinfo),1,fp)==1)
                {	
                    if (strcmp(bookinfo.name_of_book,book) ==0)
                    {
                    	p=0;
						printf("\n\tID: %s", bookinfo.bookID);
						printf("\n\tName: %s", bookinfo.name_of_book);
						printf("\n\tAuthor: %s", bookinfo.author);
						printf("\n\tCategory: %s", bookinfo.category);
						printf("\n\tPrice: %s",bookinfo.price);
						printf("\n\tLocation: %s", bookinfo.location);
						printf("\n\tAvailable: %s", bookinfo.available);
						printf("\n\tView: %s\n",bookinfo.view);
						getch();
						strcpy(view2, bookinfo.view);
						view = atoi(bookinfo.view);
						view+=1;
						itoa(view,bookinfo.view, 10);
						fp=fopen("book.txt","ab+");
						fwrite(&bookinfo,sizeof(bookinfo),1,fp);
						fclose(fp);
						fp=fopen("book.txt","rb");
			            temporary=fopen("tempfile.txt","wb");
			            while (fread(&bookinfo,sizeof(bookinfo),1,fp)==1)
				            {
				            	if (strcmp(bookinfo.name_of_book,book)==0&&strcmp(bookinfo.view,view2)==0)
				                {
				                    p=0;
				                    continue;
				                }
				                else
				                {
				                	fwrite(&bookinfo,sizeof(bookinfo),1,temporary);
				                }	                    
				            }
				        fclose(fp);
			            fclose(temporary);
			            tmp1=fopen("book.txt","wb");
			            tmp2=fopen("tempfile.txt","rb");
			            if (p==1){
			                printf("\n\n\t\tRECORD NOT FOUND");
			                goto G;}
			            else{
			                printf("\n\n\t\tRECORD SUCCESSFULLY  DELETED");
			                
							while (fread(&bookinfo,sizeof(bookinfo),1,tmp2)==1)
				            {
				                fwrite(&bookinfo,sizeof(bookinfo),1,tmp1);
			            	}
			            	if (NULL != tmp1) {
						    fseek (tmp1, 0, SEEK_END);
						    size = ftell(tmp1);
						
						    if (0 == size) {
						        while (fread(&bookinfo,sizeof(bookinfo),1,tmp2)==0)
				            {
				                fwrite(&bookinfo,sizeof(bookinfo),1,tmp1);
				                if(i==sizeof(bookinfo)/98)goto G;i++;
			            	}
						    	}
							}
						}
						G:
			            fclose(tmp1);
			            fclose(tmp2);
			                    }
			                }
			                if (p==1)
			                    printf("\n\nRECORD NOT FOUND");
			                printf("\n\n");
			                fflush(stdin);
			                fclose(fp);
			                if(n==1){
				            		system("cls");
				            		admin();	
								}
								if(n==2){
									system("cls");
				            		reader_menu();
								}
			                
            }
            if (option==2)
            {
            	printf("\n\tNovel\tTextbook\tManga\tGame\tMusic");
            	printf("\n\tHorror\tPsychology\tComedy\tDiary\tSport");
                printf("\n\n\tEnter category: ");
                fflush(stdin);
                scanf("%s",&book);
                fp=fopen("book.txt","rb+");
                while(fread(&bookinfo,sizeof(bookinfo),1,fp)==1)
                {	
                    if (strcmp(bookinfo.category,book) ==0)
                    {
                    	p=0;
						printf("\n\tID: %s", bookinfo.bookID);
						printf("\n\tName: %s", bookinfo.name_of_book);
						printf("\n\tAuthor: %s", bookinfo.author);
						printf("\n\tCategory: %s", bookinfo.category);
						printf("\n\tPrice: %s",bookinfo.price);
						printf("\n\tLocation: %s", bookinfo.location);
						printf("\n\tAvailable: %s", bookinfo.available);
						printf("\n\tView: %s",bookinfo.view);
                    }
                }
                if (p==1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(fp);
                system("cls");
            }
             if (option==3)
            {
                printf("\n\n\tEnter ID: ");
                fflush(stdin);
                scanf("%s",&book);
                fp=fopen("book.txt","rb+");
                while(fread(&bookinfo,sizeof(bookinfo),1,fp)==1)
                {	
                    if (strcmp(bookinfo.bookID,book) ==0)
                    {
                    	p=0;
						printf("\n\tID: %s", bookinfo.bookID);
						printf("\n\tName: %s", bookinfo.name_of_book);
						printf("\n\tAuthor: %s", bookinfo.author);
						printf("\n\tCategory: %s", bookinfo.category);
						printf("\n\tPrice: %s",bookinfo.price);
						printf("\n\tLocation: %s", bookinfo.location);
						printf("\n\tAvailable: %s", bookinfo.available);
						printf("\n\tView: %s",bookinfo.view);
                    }
                }
                if (p==1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(fp);
                system("cls");
            }
             if (option==4)
            {
                printf("\n\n\tEnter author: ");
                fflush(stdin);
                scanf("%s",&book);
                fp=fopen("book.txt","rb+");
                while(fread(&bookinfo,sizeof(bookinfo),1,fp)==1)
                {	
                    if (strcmp(bookinfo.author,book) ==0)
                    {
                    	p=0;
						printf("\n\tID: %s", bookinfo.bookID);
						printf("\n\tName: %s", bookinfo.name_of_book);
						printf("\n\tAuthor: %s", bookinfo.author);
						printf("\n\tCategory: %s", bookinfo.category);
						printf("\n\tPrice: %s",bookinfo.price);
						printf("\n\tLocation: %s", bookinfo.location);
						printf("\n\tAvailable: %s", bookinfo.available);
						printf("\n\tView: %s",bookinfo.view);
                    }
                }
                if (p==1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(fp);
                system("cls");
            }
             if (option==5){
             	int i=0;
             	int price;
                printf("\n\n\tEnter price (less than): ");
                fflush(stdin);
                scanf("%d",&price);
                fp=fopen("book.txt","rb+");
                while(fread(&bookinfo,sizeof(bookinfo),1,fp)==1)
                {	
                	i=atoi(bookinfo.price);
                    if (i<price)
                    {
                    	p=0;
						printf("\n\tID: %s", bookinfo.bookID);
						printf("\n\tName: %s", bookinfo.name_of_book);
						printf("\n\tAuthor: %s", bookinfo.author);
						printf("\n\tCategory: %s", bookinfo.category);
						printf("\n\tPrice: %s",bookinfo.price);
						printf("\n\tLocation: %s", bookinfo.location);
						printf("\n\tAvailable: %s", bookinfo.available);
						printf("\n\tView: %s",bookinfo.view);
                    }
                }
                if (p==1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(fp);
                system("cls");
            }
            else{
            	if(n==1){
            		system("cls");
            		admin();	
				}
				if(n==2){
					system("cls");
            		reader_menu();
				}
            	
			}
}
void edit_book(){
	FILE *temporary,*tmp1,*tmp2;
	int view;
	char view2[8];
	int i=1;
    int p=1;
    int size;
	char book[30];
    int choice;
    D:
	system("cls");
	date();
	printf("\tHello, admin");
	printf("\n\n");
	printf("\n\t\t\t  ******************************************");
	printf("\n\t\t\t  *                                        *");
	printf("\n\t\t\t  *                EDIT BOOK               *");
	printf("\n\t\t\t  *                                        *");
	printf("\n\t\t\t  ******************************************\n\n");	
    printf ("\n\n\n\t\tEnter Book Name for Editing: ");
    fflush(stdin);
    scanf("%[^\n]",&book);  
    fp = fopen ("book.txt", "ab+");
	while(fread(&bookinfo, sizeof(bookinfo), 1, fp)==1)
	{
		if( strcmp(book,bookinfo.name_of_book)==0)
	    {
			printf ("\n\t\tBook Found !");
			printf ("\n\n\t\tBook ID = %s ",bookinfo.bookID);
			printf ("\n\t\tBook Name = %s ",bookinfo.name_of_book);
			printf ("\n\t\tAuthor Name = %s ",bookinfo.author);
			printf ("\n\t\tCategory = %s ",bookinfo.category);
			printf ("\n\t\tLocation = %s ",bookinfo.location);
			printf ("\n\t\tPrice = %s ",bookinfo.price);
			printf ("\n\t\tAvailable = %s ",bookinfo.available);
	        while(TRUE)
	        {
	        	printf("\n\n\t\t1. Update Name");
	            printf("\n\t\t2. Update ID");
	            printf("\n\t\t3. Update Category");
	            printf("\n\t\t4. Update Author");
	            printf("\n\t\t5. Update Location");
	            printf("\n\t\t6. Update Price");
	            printf("\n\t\t7. Update Available");
	            printf("\n\t\t8. Save and exit");
	            printf("\n\n\t\t\tEnter choice =>  ");
	            scanf("%d",&choice);
	
	            switch(choice)
	            {
	            case 1:
	                printf("\nEnter New Name of Book: ");
	                fflush(stdin);
	                scanf("%[^\n]",bookinfo.name_of_book);
	                break;
	            case 2:	
	                printf("\nEnter New ID: ");
	                fflush(stdin);
	                scanf("%s",bookinfo.bookID);
	                break;
	            case 3:	
	                printf("\nEnter New Category: ");
	                fflush(stdin);
	                scanf("%s",bookinfo.category);
	                break;
	            case 4:	
	                printf("\nEnter New Author: ");
	                fflush(stdin);
	                scanf("%[^\n]",bookinfo.author);
	                break;
	            case 5:	
	                printf("\nEnter New Location: ");
	                fflush(stdin);
	                scanf("%s",bookinfo.location);	                
	                break;
	            case 6:	
	                printf("\nEnter New Price: ");
	                fflush(stdin);
	                scanf("%s",bookinfo.price);
	                break;
	            case 7:	
	                printf("\nEnter New Location: ");
	                fflush(stdin);
	                scanf("%s",bookinfo.available);
	                break;
	            case 8:
	            	strcpy(view2, bookinfo.view);
						view = atoi(bookinfo.view);
						view+=1;
						itoa(view,bookinfo.view, 10);
	            	fseek(fp,-sizeof(bookinfo),SEEK_CUR);
	                fwrite(&bookinfo,sizeof(bookinfo),1,fp);
	                fclose(fp);
	                
	                fp=fopen("book.txt","rb");
            temporary=fopen("tempfile.txt","wb");
            while (fread(&bookinfo,sizeof(bookinfo),1,fp)==1)
	            {
	            	if (strcmp(bookinfo.name_of_book,book)==0&&strcmp(bookinfo.view,view2)==0)
	                {
	                    p=0;
	                    continue;
	                }
	                else
	                {
	                	fwrite(&bookinfo,sizeof(bookinfo),1,temporary);
	                }	                    
	            }
	        fclose(fp);
            fclose(temporary);
            tmp1=fopen("book.txt","wb");
            tmp2=fopen("tempfile.txt","rb");
            if (p==1){
                printf("\n\n\t\tRECORD NOT FOUND");
                goto F;}
            else{
                printf("\n\n\t\tMODIFY SUCCESSFULLY");
                
				while (fread(&bookinfo,sizeof(bookinfo),1,tmp2)==1)
	            {
	                fwrite(&bookinfo,sizeof(bookinfo),1,tmp1);
            	}
            	if (NULL != tmp1) {
			    fseek (tmp1, 0, SEEK_END);
			    size = ftell(tmp1);
			
			    if (0 == size) {
			        while (fread(&bookinfo,sizeof(bookinfo),1,tmp2)==0)
	            {
	                fwrite(&bookinfo,sizeof(bookinfo),1,tmp1);
	                if(i==sizeof(bookinfo)/98)goto F;i++;
            	}
			    	}
				}
			}
			F:
            fclose(tmp1);
            fclose(tmp2);
	                system("cls");
	                admin();	
	                break;
	            default:
	                printf("\n\t\tInvalid input!! Try again ...");
	            }
	        }
		}
		else
		printf("\n\n\t\t\t\tBook Not Found");
    	getch();
		system("cls");
    	admin();
	}


};
void delete_book(){
	FILE *temporary,*tmp1,*tmp2;
	int i=1;
    int p=1;
    int size;
    char book[30];
    system("cls");
	date();
	printf("\tHello, admin");
	printf("\n\n");
	printf("\n\t\t\t  ******************************************");
	printf("\n\t\t\t  *                                        *");
	printf("\n\t\t\t  *                DELETE BOOK             *");
	printf("\n\t\t\t  *                                        *");
	printf("\n\t\t\t  ******************************************\n\n");	
     		fp=fopen("book.txt","rb");
            temporary=fopen("tempfile.txt","wb");
            printf("\n\n\t\tEnter name of book to delete: ");
            fflush(stdin);
            scanf("%[^\n]",&book);
            while (fread(&bookinfo,sizeof(bookinfo),1,fp)==1)
	            {
	            	if (strcmp(bookinfo.name_of_book,book)==0)
	                {
	                    p=0;
	                    continue;
	                }
	                else
	                {
	                	fwrite(&bookinfo,sizeof(bookinfo),1,temporary);
	                }	                    
	            }
	        fclose(fp);
            fclose(temporary);
            if (p==1){
                printf("\n\n\t\tRECORD NOT FOUND");
                system("cls");
                getch();
                admin();}
            else{
                printf("\n\n\t\tRECORD SUCCESSFULLY  DELETED");
                tmp1=fopen("book.txt","wb");
            	tmp2=fopen("tempfile.txt","rb");
				while (fread(&bookinfo,sizeof(bookinfo),1,tmp2)==1)
	            {
	                fwrite(&bookinfo,sizeof(bookinfo),1,tmp1);
            	}
            	if (NULL != tmp1) {
			    fseek (tmp1, 0, SEEK_END);
			    size = ftell(tmp1);			
			    if (0 == size) {
			        while (fread(&bookinfo,sizeof(bookinfo),1,tmp2)==0)
	            {
	                fwrite(&bookinfo,sizeof(bookinfo),1,tmp1);
	                if(i==sizeof(bookinfo)/98){
						fclose(tmp1);
	            		fclose(tmp2);goto E;
					}i++;
            	}
			    	}
			    	fclose(tmp1);
            		fclose(tmp2);
				}
			}
			E:
            fclose(tmp1);
            fclose(tmp2);
            printf("\n\n");
            fflush(stdin);
            getch();
            system("cls");
            admin();
}
void add_record(){
			int i=1;
			system("cls");
			date();
			printf("\tHello, admin");
			printf("\n\n");
			printf("\n\t\t\t  ******************************************");
			printf("\n\t\t\t  *                                        *");
			printf("\n\t\t\t  *                 ADD RECORD             *");
			printf("\n\t\t\t  *                                        *");
			printf("\n\t\t\t  ******************************************\n\n");
			while(i==1){
            printf("\n\n\tEnter student name: ");
            fflush(stdin);
            scanf("%[^\n]", &record.name);
            printf("\n\tEnter student ID: ");
            fflush(stdin);
            scanf("%s",&record.studentID);
            printf("\n\tEnter book ID: ");
            fflush(stdin);
            scanf("%s",&record.bookID);
            printf("\n\tEnter name of book: ");
            fflush(stdin);
            scanf("%[^\n]",&record.book);
            printf("\n\tEnter borrow date: ");
            fflush(stdin);
            scanf("%s",&record.borrow_date);
            printf("\n\tEnter return date: ");
            fflush(stdin);
            scanf("%s",&record.return_date);
            fp=fopen("record.txt","ab+");
            fwrite(&record,sizeof(record),1,fp);
            fclose(fp);
            printf("\n\n\t\t\tAdd record successfully!!");
            printf("\n\n\t\t\t1. Countinue adding record");
            printf("\n\t\t\t2. Exit");
            printf("\n\n\tYour option => ");
            scanf("%d",&i);
            }
            system("cls");
        	admin();
               
};
void modify_record(){
	FILE *temporary,*tmp1,*tmp2;
	int i=1;
    int p=1;
    int size;
	char book[30];
    int choice;
    D:
	system("cls");
	date();
	printf("\tHello, admin");
	printf("\n\n");
	printf("\n\t\t\t  ******************************************");
	printf("\n\t\t\t  *                                        *");
	printf("\n\t\t\t  *               EDIT RECORD              *");
	printf("\n\t\t\t  *                                        *");
	printf("\n\t\t\t  ******************************************\n\n");	
    printf ("\n\n\n\t\tEnter Student Name Editing: ");
    fflush(stdin);
    scanf("%[^\n]",&book);  
    fp = fopen ("record.txt", "ab+");
	while(fread(&record, sizeof(record), 1, fp)==1)
	{
		if( strcmp(book,record.name)==0)
	    {
	    	p=0;
			printf ("\n\t\tRecord Found!");
			printf("\n\tStudent ID: %s", record.studentID);
			printf("\n\tStudent Name: %s", record.name);
			printf("\n\tBook ID: %s", record.bookID);
			printf("\n\tBook: %s", record.book);
			printf("\n\tBorrow Date: %s",record.borrow_date);
			printf("\n\tReturn Date: %s\n", record.return_date);
			getch();
	        while(TRUE)
	        {
	        	printf("\n\n\t\t1. Update Student ID");
	            printf("\n\t\t2. Update Student Name");
	            printf("\n\t\t3. Update Book ID");
	            printf("\n\t\t4. Update Book Name");
	            printf("\n\t\t5. Update Borrow Date");
	            printf("\n\t\t6. Update Return Date");
	            printf("\n\t\t7. Save and exit");
	            printf("\n\n\t\t\tEnter choice =>  ");
	            scanf("%d",&choice);
	            switch(choice)
	            {
	            case 1:
	                printf("\nEnter New Student ID: ");
	                fflush(stdin);
	                scanf("%[^\n]",record.studentID);
	                break;
	            case 2:	
	                printf("\nEnter New Student Name: ");
	                fflush(stdin);
	                scanf("%[^\n]",record.name);
	                break;
	            case 3:	
	                printf("\nEnter New Book ID: ");
	                fflush(stdin);
	                scanf("%s",record.bookID);
	                break;
	            case 4:	
	                printf("\nEnter New Book Name: ");
	                fflush(stdin);
	                scanf("%[^\n]",record.book);
	                break;
	            case 5:	
	                printf("\nEnter New Borrow Date: ");
	                fflush(stdin);
	                scanf("%s",record.borrow_date);	                
	                break;
	            case 6:	
	                printf("\nEnter New Return Date: ");
	                fflush(stdin);
	                scanf("%s", record.return_date);
	                break;
	            case 7:
	            	fseek(fp,-sizeof(record),SEEK_CUR);
	                fwrite(&record,sizeof(record),1,fp);
	                fclose(fp);
	                system("cls");
	                admin();
	            };
	        }  
		}
	}
	if(p==1)
		printf("\n\n\t\tRecord not found...");
		getch();
		system("cls");
		admin();	
};
void search_record(){
	FILE *temporary,*tmp1,*tmp2;
	int i=1;
    int p=1;
    int size;
	int option=0;
	int view;
	char view2[8];
	char book[30];
	system("cls");
	date();
	printf("\tHello, admin");
	printf("\n\n");
	printf("\n\t\t\t  ******************************************");
	printf("\n\t\t\t  *                                        *");
	printf("\n\t\t\t  *              SEARCH RECORD             *");
	printf("\n\t\t\t  *                                        *");
	printf("\n\t\t\t  ******************************************\n\n");	
	printf("\n\n\t\t1. Search by Student ID");
    printf("\n\t\t2. Search by Student Name");
    printf("\n\t\t3. Search by Book ID");
    printf("\n\t\t4. Search outdated record");
    printf("\n\t\t5. Exit");
    printf("\n\n\t\tEnter Choice => ");
            fflush(stdin);
            scanf("%d",&option);
            if (option==1)
            {
                printf("\n\n\tEnter Student ID: ");
                fflush(stdin);
                scanf("%s",&book);
                fp=fopen("record.txt","rb+");
                while(fread(&record,sizeof(record),1,fp)==1)
                {	
                    if (strcmp(record.studentID,book) ==0)
                    {
                    	p=0;
						printf("\n\tStudent ID: %s", record.studentID);
						printf("\n\tStudent Name: %s", record.name);
						printf("\n\tBook ID: %s", record.bookID);
						printf("\n\tBook: %s", record.book);
						printf("\n\tBorrow Date: %s",record.borrow_date);
						printf("\n\tReturn Date: %s\n", record.return_date);
						getch();
            		}
				}
				if (p==1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(fp);
                system("cls");
			}
            if (option==2)
            {
                printf("\n\n\tEnter Student Name: ");
                fflush(stdin);
                scanf("%s",&book);
                fp=fopen("record.txt","rb+");
                while(fread(&record,sizeof(record),1,fp)==1)
                {	
                    if (strcmp(record.name,book) ==0)
                    {
                    	p=0;
						printf("\n\tStudent ID: %s", record.studentID);
						printf("\n\tStudent Name: %s", record.name);
						printf("\n\tBook ID: %s", record.bookID);
						printf("\n\tBook: %s", record.book);
						printf("\n\tBorrow Date: %s",record.borrow_date);
						printf("\n\tReturn date: %s\n", record.return_date);
						getch();
            		}
				}
				if (p==1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(fp);
                system("cls");
			}
			if (option==3)
            {
                printf("\n\n\tEnter Book ID: ");
                fflush(stdin);
                scanf("%s",&book);
                fp=fopen("record.txt","rb+");
                while(fread(&record,sizeof(record),1,fp)==1)
                {	
                    if (strcmp(record.bookID,book) ==0)
                    {
                    	p=0;
						printf("\n\tStudent ID: %s", record.studentID);
						printf("\n\tStudent Name: %s", record.name);
						printf("\n\tBook ID: %s", record.bookID);
						printf("\n\tBook: %s", record.book);
						printf("\n\tBorrow Date: %s",record.borrow_date);
						printf("\n\tReturn date: %s\n", record.return_date);
						getch();     
            		}
				}
				if (p==1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(fp);
                system("cls");
			}
			if (option==4)
            {
            	char buffer[32];
				int cd,cm,cy;
			    size_t last;
			    time_t timestamp = time(NULL);
			    ts   = localtime(&timestamp);
			    last = strftime(buffer, 32, "%A", ts);
			    buffer[last] = '\0';
			    cd=ts->tm_mday;
			    cm=ts->tm_mon + 1;
			    cy=ts->tm_year + 1900;
            	int d,m,y;
            	char time[10];
                printf("\n\n\tThe current date: %d/%d/%d", cd,cm,cy);
                fflush(stdin);
                fp=fopen("record.txt","rb+");
                while(fread(&record,sizeof(record),1,fp)==1)
                {
                	strcpy(time,record.return_date);
                	d=(time[0]-48)*10+(time[1]-48);
                	m=(time[3]-48)*10+(time[4]-48);
                	y=(time[6]-48)*1000+(time[7]-48)*100+(time[8]-48)*10+(time[9]-48);
					if (y<cy)
                    {
                    	p=0;
						printf("\n\tStudent ID: %s", record.studentID);
						printf("\n\tStudent Name: %s", record.name);
						printf("\n\tBook ID: %s", record.bookID);
						printf("\n\tBook: %s", record.book);
						printf("\n\tBorrow Date: %s",record.borrow_date);
						printf("\n\tReturn date: %s\n", record.return_date);
						getch();     
            		}
            		if(y==cy){
						if(m<cm){
							p=0;
							printf("\n\tStudent ID: %s", record.studentID);
							printf("\n\tStudent Name: %s", record.name);
							printf("\n\tBook ID: %s", record.bookID);
							printf("\n\tBook: %s", record.book);
							printf("\n\tBorrow Date: %s",record.borrow_date);
							printf("\n\tReturn date: %s\n", record.return_date);
							getch();
						}
						if(m==cm){
							if(d<cd){
								p=0;
								printf("\n\tStudent ID: %s", record.studentID);
								printf("\n\tStudent Name: %s", record.name);
								printf("\n\tBook ID: %s", record.bookID);
								printf("\n\tBook: %s", record.book);
								printf("\n\tBorrow Date: %s",record.borrow_date);
								printf("\n\tReturn date: %s\n", record.return_date);
								getch();
							}
						}
					}
				}
				if (p==1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(fp);
                system("cls");
			}
		admin();
};
void delete_record(){
	FILE *temporary,*tmp1,*tmp2;
	int i=1;
    int p=1;
    int size;
    char book[30];
    system("cls");
	date();
	printf("\tHello, admin");
	printf("\n\n");
	printf("\n\t\t\t  ******************************************");
	printf("\n\t\t\t  *                                        *");
	printf("\n\t\t\t  *               DELETE RECORD            *");
	printf("\n\t\t\t  *                                        *");
	printf("\n\t\t\t  ******************************************\n\n");	
     		fp=fopen("record.txt","rb");
            temporary=fopen("tempfile.txt","wb");
            printf("\n\n\t\tEnter student ID to delete: ");
            fflush(stdin);
            scanf("%[^\n]",&book);
            while (fread(&record,sizeof(record),1,fp)==1)
	            {
	            	if (strcmp(record.studentID,book)==0)
	                {
	                    p=0;
	                    continue;
	                }
	                else
	                {
	                	fwrite(&record,sizeof(record),1,temporary);
	                }	                    
	            }
	        fclose(fp);
            fclose(temporary);
            if (p==1){
                printf("\n\n\t\tRECORD NOT FOUND");
                system("cls");
                getch();
                admin();}
            else{
                printf("\n\n\t\tRECORD SUCCESSFULLY  DELETED");
                tmp1=fopen("record.txt","wb");
            	tmp2=fopen("tempfile.txt","rb");
				while (fread(&record,sizeof(record),1,tmp2)==1)
	            {
	                fwrite(&record,sizeof(record),1,tmp1);
            	}
            	if (NULL != tmp1) {
			    fseek (tmp1, 0, SEEK_END);
			    size = ftell(tmp1);			
			    if (0 == size) {
			        while (fread(&record,sizeof(record),1,tmp2)==0)
	            {
	                fwrite(&record,sizeof(record),1,tmp1);
	                if(i==sizeof(record)/95){
					fclose(tmp1);
            		fclose(tmp2);
					goto E;
					}i++;
            	}fclose(tmp1);
            		fclose(tmp2);
			    	}
			    	
				}
			}
			E:
            
            printf("\n\n");
            fflush(stdin);
            getch();
            system("cls");
            admin();	
};
void trending_book(){
	system("cls");
	int view,max1=0,max2=0,max3=0;
	char max11[30],max12[30],max13[30];
	fp=fopen("book.txt","rb");
	while(fread(&bookinfo,sizeof(bookinfo),1,fp)==1)
                {	
                	view=atoi(bookinfo.view);
                    if (max1<=view)
                    {
                    	max3=max2;
                    	max2=max1;
                    	max1=view;
                    	strcpy(max13,max12);
                    	strcpy(max12,max11);
                    	strcpy(max11,bookinfo.name_of_book);
                    }
                }
    date();
    	printf("\tHi, %s",act.user);
    	printf("\n\n");
		printf("\n\t\t\t  ******************************************");
		printf("\n\t\t\t  *                                        *");
	    printf("\n\t\t\t  *              TRENDING BOOKS            *");
	    printf("\n\t\t\t  *                                        *");
	    printf("\n\t\t\t  ******************************************\n\n");
	    printf("\n\t\t\t   %-30s  View","Name");
		printf("\n\n\t\t\t1. %-30s  %d",max11,max1);
		printf("\n\n\t\t\t2. %-30s  %d",max12,max2);
		printf("\n\n\t\t\t3. %-30s  %d",max13,max3);
		getch();
		system("cls");
};

void reader_menu()
{
	int n=2;
    int choice = 0;
    do
    {
    	date();
    	printf("\tHi, %s",act.user);
    	printf("\n\n");
		printf("\n\t\t\t  ******************************************");
		printf("\n\t\t\t  *                                        *");
	    printf("\n\t\t\t  *               READER MENU              *");
	    printf("\n\t\t\t  *                                        *");
	    printf("\n\t\t\t  ******************************************\n\n");
        printf("\n\n\n\t\t\t1. Trending Books");
        printf("\n\t\t\t2. Search Books");
        printf("\n\t\t\t3. Sign out");
        printf("\n\t\t\t4. Exit");
        printf("\n\n\n\t\t\tEnter choice => ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                trending_book();
                break;
            case 2:
            	system("cls");
            	date();
				printf("\tHi, %s",act.user);
                search_book(n);
                break;

            case 3:
            system("cls");
            login();
            break;
            case 4:
            exit(0);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
            getch();
    };} while (choice!=0);
    
}

// returns 1 if given date is valid.
int CheckDate()
{
    int status; //variable to check status
    //get date year,month and day from user
    H:
    status=1;
    printf("\n\t Enter return date (day/month/year): ");
    scanf("%d/%d/%d", &d.dd,&d.mm,&d.yyyy);
        printf("\n-------------------------------------------------\n");
    //check date validity
    
    //check range of year,month and day
    if (d.yyyy > MAX_YR ||
            d.yyyy < MIN_YR)
        status = 0;
    if (d.mm < 1 || d.mm > 12)
        status = 0;
    if (d.dd < 1 || d.dd > 31)
        status = 0;
    //Handle feb days in leap year
    if (d.mm == 2)
    {
        if (((d.yyyy % 4 == 0) && (d.yyyy % 100 != 0)) || (d.yyyy % 400 == 0)){
            if(d.dd <= 29&&d.dd >= 1)
            	status=1;
            else
            	status=0;}
        else{
            if(d.dd <= 28&&d.dd >= 1)
				status=1;
            else
            	status=0;}          	
    }
    //handle months which has only 30 days
    if (d.mm == 4 || d.mm == 6 ||
            d.mm == 9 || d.mm == 11){
        if(d.dd <= 30)
			status=1;
        else
            	status=0;
				}
    if(status !=0)
		    {
		        printf("\n\n The date is: %d/%d/%d",d.dd,d.mm,d.yyyy);
			}
		    
		    else{
		    	printf("\n\n Please enter a valid date!\n");
		        goto H;
			}  
}
void admin(){
		int option=0;
		int choice=0;
		int n=1;
		B:
		date();
		printf("\tHello, admin");
		lms();
        printf("\n\n\n\t\t\t1. Book Management");
        printf("\n\t\t\t2. Borrower Management");
        printf("\n\t\t\t3. Sign out");
        printf("\n\t\t\t4. Exit");
        printf("\n\n\n\t\t\tEnter choice => ");

        scanf("%d",&option);
        switch(option)
        {
        case 2:
            system("cls");
		 	date();
			printf("\tHello, admin");
			printf("\n\n");
			printf("\n\t\t\t  ******************************************");
			printf("\n\t\t\t  *                                        *");
			printf("\n\t\t\t  *            BORROWER MANAGEMENT         *");
			printf("\n\t\t\t  *                                        *");
			printf("\n\t\t\t  ******************************************\n\n");
		        printf("\n\n\n\t\t\t1. Add record");
		        printf("\n\t\t\t2. Modify record");
		        printf("\n\t\t\t3. Search record");
		        printf("\n\t\t\t4. Delete record");		
		        printf("\n\t\t\t5. Exit");
		        printf("\n\n\n\t\t\tEnter choice => ");
		
		        scanf("%d",&choice);
		        switch(choice)
		        {
		            case 1:
		                add_record(option);
		                break;
		            case 2:
		                modify_record();
		                break;
		            case 3:
		                search_record();
		                break;
		            case 4:
		                delete_record();
		                break;
		            case 5:
		            	system("cls");
		           goto B;
		            break;
		        default:
		            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
		            getch();
		    };
    
            break;
        case 1:
            system("cls");
		 	date();
			printf("\tHello, admin");
			printf("\n\n");
			printf("\n\t\t\t  ******************************************");
			printf("\n\t\t\t  *                                        *");
			printf("\n\t\t\t  *              BOOK MANAGEMENT           *");
			printf("\n\t\t\t  *                                        *");
			printf("\n\t\t\t  ******************************************\n\n");
		        printf("\n\n\n\t\t\t1. Add Books");
		        printf("\n\t\t\t2. Edit Books");
		        printf("\n\t\t\t3. Search Books");
		        printf("\n\t\t\t4. Delete Books");
		        printf("\n\t\t\t5. Exit");
		        printf("\n\n\n\t\t\tEnter choice => ");
		
		        scanf("%d",&choice);
		        switch(choice)
		        {
		            case 1:
		                add_book(option);
		                break;
		            case 2:
		                edit_book();
		                break;
		            case 3:
		            	system("cls");
						date();
					    printf("\tHi, admin");
		                search_book(n);
		                break;
		            case 4:
		                delete_book();
		                break;
					case 5:
						system("cls");
						goto B;
		        default:
		            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
		            getch();
		    };
		            break;
        case 3:
        	system("cls");
        	login();
		case 4:
        	exit(0);
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
            getch();
            goto B;
        }  
};	

void login()
{
	system("cls");
	char option;
	int i=0;
    char username[20],c=' ';
    char password[20];
	A:
	date();
	option=0;
	printf("\n\t\t\t  ******************************************");
	printf("\n\t\t\t  *                                        *");
    printf("\n\t\t\t  *                 LOGIN                  *");
    printf("\n\t\t\t  *                                        *");
    printf("\n\t\t\t  ******************************************\n\n");
    printf("\t\t\t 1. Log in			2. Sign up\n\n");
    printf("\tYour option: ");
	scanf("%s",&option);
	switch(option){
		case '1':
			C:
			i=0;
			printf(" \n\n\t\t  USERNAME: ");
			scanf("%s", &username); 
			printf(" \n\t\t  PASSWORD: ");
			while(i<20)
			{
			    password[i]=getch();
			    c=password[i];
			    if(c==13) break;
			    else printf("*");
			    i++;
			}break;
		case '2':
			printf(" \n\n\t\t  USERNAME: ");
			fflush(stdin);
			scanf("%[^\n]",&act.user);
			printf(" \n\n\t\t  PASSWORD: ");
			fflush(stdin);
			i=0;
			while (i<20) {
	    		if (kbhit) {
	            // fetch typed character into ch
	            password[i] = getch();
	            if ((int)password[i] == 13)
	                break;
	                printf("*");
	                i++;	
				}
			}
			password[i]='\0';
			strcpy(act.pass,password);
			fp=fopen("account.txt","ab+");
            fwrite(&act,sizeof(act),1,fp);
            fclose(fp);
            printf("\n\n\t\tCreate account successfully!!!");
            printf("\n\n\t\tPress any keys to login...");
            fflush(stdin);
            getch();
            system("cls");
            date();
		    printf("\n\t\t\t  ******************************************");
			printf("\n\t\t\t  *                                        *");
		    printf("\n\t\t\t  *                 LOGIN                  *");
		    printf("\n\t\t\t  *                                        *");
		    printf("\n\t\t\t  ******************************************\n\n");
            goto C;
		default:
			printf("\nYour option is invalid!\n");
			printf("Press any keys to try again ...");
			getch();
			system("cls");
			goto A;
	};  
	password[i]='\0';
	i=0;
	if(strcmp(username,"Vnuis")==0 && strcmp(password,"Vnu.edu.vn")==0){
		system("cls");
		welcome();
		admin();
	}
	else{	
            fp=fopen("account.txt","rb");
            while(fread(&act,sizeof(act),1,fp)==1)
            {
                if(strcmp(username,act.user) == 0 && strcmp(password, act.pass) ==0)
                {
                    system("cls");
                    welcome();
					reader_menu();                
                }
            }
			MessageBox(0, "Your username or password is wrong", "Notification", 0);
			printf("\n\n\n\n\t\tPress any keys to try again!!");
			getch();
			system("cls");
			goto A;
    }
};
	
int main(void)
{
	date();
	lms();
	printf("\n\n\n\n\n\n\t\t\t Press any keys to start ...");
	getch();
	login();
    return 0;
}
