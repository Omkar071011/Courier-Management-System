/* courier service management*/
/* Pralabh Agarwal */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct staff
{
	int s_code;
	char s_name[20];
	char s_add[50];
	char s_gender[7];
	char des[10];
	char s_pn[15];
	char s_dob[10];
};
struct Booking
{
	char se_name[20];
	char se_add[50];
	char se_pn[15];
	char se_city[15];
	char se_id[30];
	char re_name[20];
	char re_add[50];
	char re_pn[15];
	char re_city[15];
	char re_id[30];
	char c_date[10];
};
struct weight
{
	char wrange[15];
	int w_price;
};

struct location
{
	char location[50];
	int l_price;
};

struct type
{
	char ctype[15];
	int t_price;
};

struct courier
{
	int c_id;
	char c_name[20];
	char type[15];
	char location[50];
	char wrange[15];

};

typedef struct Booking bk;
typedef struct staff stf;
typedef struct weight wtg;
typedef struct location loc;
typedef struct type tp;
typedef struct courier cur;

int main()
{
	int staffDetails();
	int bookingDetails();
	int courierDetails();
	int otherDetails();
	int choice;
	system("clear");

	while(1)
	{

		printf("\n*****Choice Menu*****\n");
		printf("\n1. Staff Details");
		printf("\n2. Booking Details");
		printf("\n3. Courier Details");
		printf("\n4. Other Details");
		printf("\n0. Exit");

		printf("\n\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0:
				return(EXIT_SUCCESS);
			break;

		        case 1:
				staffDetails();
			break;

			case 2:
				bookingDetails();
			break;
			case 3:
				courierDetails();
			break;
			case 4:
				otherDetails();
			break;
		}

	}

}

int staffDetails()      
{
	void s_details();
	void s_view();
	void s_search();
	void s_remove();
	void s_update();
	int choice;

	while(1)
	{
		printf("\n\n\t~~~~~Choice Menu~~~~~\n");
		printf("\n\t1. Add Staff Details");
		printf("\n\t2. View Staff Details");
		printf("\n\t3. Remove Staff Details");
		printf("\n\t4. Search Staff Details");
		printf("\n\t5. Update Staff Details");
		printf("\n\t0. Exit Staff Details");

		printf("\n\n\tEnter Your Choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0:
				return(EXIT_SUCCESS);
			break;

			case 1:
				s_details();
			break;

			case 2:
				s_view();
			break;

			case 3:
				s_remove();
			break;

			case 4:
				s_search();
			break;

			case 5:
				s_update();
			break;

			default:
				printf("Invalid Choice!");
			break;
		}

	}

	printf("\n");
}
int bookingDetails()      
{
	void b_details();
	void b_view();
	void b_update();
	int choice;

	while(1)
	{
		printf("\n\n\t~~~~~Choice Menu~~~~~\n");
		printf("\n\t1. Add Booking Details");
		printf("\n\t2. View Booking Details");
		printf("\n\t3. Update Booking Details");
		printf("\n\t0. Exit ");

		printf("\n\n\tEnter Your Choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0:
				return(EXIT_SUCCESS);
			break;

			case 1:
				b_details();
			break;

			case 2:
				b_view();
			break;

			case 3:
				b_update();
			break;

			default:
				printf("Invalid Choice!");
			break;
		}

	}

	printf("\n");
}

void s_details()        
{
	FILE *s_file = NULL;
	stf sptr;

	s_file = fopen("staff.dat", "ab");

	if(s_file == NULL)
	{
		printf("\tSorry...Can't add staff details!");
	}

	else
	{
		printf("\n\t...Enter staff details...");

		printf("\n\n\tEmployee Code:        ");
		scanf("%d", &sptr.s_code);

		printf("\n\tEmployee Name:        ");
		scanf("\n");
		gets(sptr.s_name);

		printf("\n\tEmployee Address:     ");
		gets(sptr.s_add);

		printf("\n\tEmployee Gender:      ");
		gets(sptr.s_gender);

		printf("\n\tEmployee Designation: ");
		gets(sptr.des);

		printf("\n\tEmployee Phone number:");
		gets(sptr.s_pn);

		printf("\n\tEmployee Date Of Birth: ");
		gets(sptr.s_dob);

		fwrite(&sptr, sizeof(stf), 1, s_file);
		fclose(s_file);
	}
}

void s_view()          
	FILE *s_file = NULL;
	stf sptr;
	int cn=0;

	s_file = fopen("staff.dat", "rb");

	if(s_file == NULL)
	{
		printf("\tSorry...Can't view staff details!");
	}

	else
	{

		fread(&sptr, sizeof(stf), 1, s_file);

		while(!feof(s_file))
		{
			printf("\n\t...Staff Details of each Enterd Employees...\n");


			printf("\n\tEmployee Code:          %d", sptr.s_code);
			printf("\n\tEmployee Name:          %s", sptr.s_name);
			printf("\n\tEmployee Address:       %s", sptr.s_add);
			printf("\n\tEmployee Gender:        %s", sptr.s_gender);
			printf("\n\tEmployee Designation:   %s", sptr.des);
			printf("\n\tEmployee Phone number:  %s", sptr.s_pn);
			printf("\n\tEmployee Date of birth: %s", sptr.s_dob);
			printf("\n");
			cn++;
			fread(&sptr, sizeof(stf), 1, s_file);
		}
		if(cn>0)
			fclose(s_file);
		else
		{
			printf("\tThere is no record of any employee\n");
			fclose(s_file);
		}
	}

	printf("\n");
}

void s_search()        
{
	int s_code,cn=0;
	stf sptr;
	FILE *s_file = NULL;

	printf("\n\tEnter Employee Code: ");
	scanf("%d", &s_code);

	s_file = fopen("staff.dat", "rb");

	if(s_file == NULL)
	{
		printf("\tSorry...Can't search staff details!");
	}

	else
	{
		while(!feof(s_file))
		{
			fread(&sptr, sizeof(stf), 1, s_file);

			if(sptr.s_code == s_code)
			{
				printf("\n\t...Staff Details of Searched Employee...\n");

				printf("\n\tEmployee Code:          %d", sptr.s_code);
				printf("\n\tEmployee Name:          %s", sptr.s_name);
				printf("\n\tEmployee Address:       %s", sptr.s_add);
				printf("\n\tEmployee Gender:        %s", sptr.s_gender);
				printf("\n\tEmployee Designation:   %s", sptr.des);
				printf("\n\tEmployee Phone number:  %s", sptr.s_pn);
				printf("\n\tEmployee Date of birth: %s", sptr.s_dob);

				cn++;
				break;
			}
		}
		if(cn==1)
				fclose(s_file);
		else
		{
				printf("\n\tNone of the number matches this employee...");
				fclose(s_file);
		}
	}

	printf("\n");
}
void s_remove()                                  
{
	FILE *s_file=NULL;
	FILE *temp_file=NULL;
	int found=0,s_code;
	stf sptr;

	printf("\nEnter employee no: ");
    	scanf("%d", &s_code);

	s_file = fopen("staff.dat", "rb");

	temp_file=fopen("temp.dat", "wb");

	if(s_file == NULL)
	{
		printf("\tSorry...Can't search staff details!");
	}

	else
	{
	    	fread(&sptr, sizeof(stf), 1, s_file);
	while(!feof(s_file))
	{

		if (sptr.s_code == s_code)
			printf("\tA record with requested name found and deleted.\n\n");
		else
		{
			fwrite(&sptr, sizeof(stf), 1, temp_file);
		}
		fread(&sptr, sizeof(stf), 1, s_file);
	}

	fclose(s_file);
	fclose(temp_file);

	remove("staff.dat");
	rename("temp.dat", "staff.dat");
	}
}
void s_update()
{
	int s_code , cn=0;
	stf sptr;
	FILE *s_file = NULL;
	FILE *temp_file = NULL;

	s_file = fopen("staff.dat", "rb");
	temp_file = fopen("temp.dat", "ab");

	printf("Enter Employee Code: ");
	scanf("%d", &s_code);

	if(s_file == NULL)
	{
		printf("\tSorry...Can't search staff details!");
	}

	else
	{
		fread(&sptr, sizeof(stf), 1, s_file);

		while(!feof(s_file))
		{
			if(s_code == sptr.s_code)
			{
				printf("\nEnter staff details ");
				printf("\n\n\tEmployee Code:        ");
				scanf("%d", &sptr.s_code);

				printf("\n\tEmployee Name:        ");
				scanf("\n");
				gets(sptr.s_name);

				printf("\n\tEmployee Address:     ");
				gets(sptr.s_add);

				printf("\n\tEmployee Gender:      ");
				gets(sptr.s_gender);

				printf("\n\tEmployee Designation: ");
				gets(sptr.des);

				printf("\n\tEmployee Phone number:");
				gets(sptr.s_pn);

				printf("\n\tEmployee Date Of Birth: ");
				gets(sptr.s_dob);

				cn++;

				fwrite(&sptr, sizeof(stf), 1, temp_file);
			}

			else
			{
				fwrite(&sptr, sizeof(stf), 1, temp_file);
			}
				fread(&sptr, sizeof(stf), 1, s_file);

	       }
			if(cn>=1)
			{
			fclose(temp_file);
			fclose(s_file);
			}
			else
			{
				printf("Sorry..... NO record found");
				fclose(temp_file);
				fclose(s_file);
			}
			remove("staff.dat");
			rename("temp.dat","staff.dat");
        }
}

void b_details()        
{
	FILE *b_file = NULL;
	bk bptr;

	b_file = fopen("booking.dat", "ab");

	if(b_file == NULL)
	{
		printf("\tSorry...Can't add booking details!");
	}

	else
	{
		printf("\n\t...Enter booking details...");

		printf("\n\tSender Name:        ");
		scanf("\n");
		gets(bptr.se_name);

		printf("\n\tSender Address:     ");
		gets(bptr.se_add);

		printf("\n\tSender City:        ");
		gets(bptr.se_city);

		printf("\n\tSender Phone number:");
		gets(bptr.se_pn);

		printf("\n\tSender mailid:");
		gets(bptr.se_id);

		printf("\n\tReceiver Name:        ");
		scanf("\n");
		gets(bptr.re_name);

		printf("\n\tReceiver  Address:     ");
		gets(bptr.re_add);

		printf("\n\tReceiver  City:        ");
		gets(bptr.re_city);

		printf("\n\tReceiver  Phone number:");
		gets(bptr.re_pn);

		printf("\n\tReceiver  mailid:");
		gets(bptr.se_id);

		printf("\n\tDate of departure: ");
		gets(bptr.c_date);

		fwrite(&bptr, sizeof(bk), 1, b_file);
		fclose(b_file);
	}
}
void b_view()          
	FILE *b_file = NULL;
	bk bptr;
	int cn=0;

	b_file = fopen("booking.dat", "rb");

	if(b_file == NULL)
	{
		printf("\tSorry...Can't view booking details!");
	}

	else
	{

		fread(&bptr, sizeof(bk), 1, b_file);

		while(!feof(b_file))
		{
			printf("\n\t...Booking Details...\n");



			printf("\n\tSender Name:          	%s", bptr.se_name);
			printf("\n\tSender Address:       	%s", bptr.se_add);
			printf("\n\tSender City:       		%s", bptr.se_city);
			printf("\n\tSender Phone number:  	%s", bptr.se_pn);
			printf("\n\tSender mailid:       	%s", bptr.se_id);
			printf("\n\tReceiver Name:          	%s", bptr.re_name);
			printf("\n\tReceiver Address:       	%s", bptr.re_add);
			printf("\n\tReceiver City:       	%s", bptr.re_city);
			printf("\n\tReceiver Phone number:  	%s", bptr.re_pn);
			printf("\n\tReceiver mailid:       	%s", bptr.se_id);
			printf("\n\tDate of departure: 	%s", bptr.c_date);
			printf("\n");
			cn++;
			fread(&bptr, sizeof(bk), 1, b_file);
		}
		if(cn>0)
			fclose(b_file);
		else
		{
			printf("\tThere is no record\n");
			fclose(b_file);
		}
	}

	printf("\n");
}
void b_update()
{
	int cn=0;
	char y_name[20];
	bk bptr;
	FILE *b_file = NULL;
	FILE *update_file = NULL;

	b_file = fopen("booking.dat", "rb");
	update_file = fopen("update.dat", "ab");

	printf("\n\tSender Name:        ");
	scanf("\n");
	gets(y_name);


	if(b_file == NULL)
	{
		printf("\tSorry...Can't search booking details!");
	}

	else
	{
		fread(&bptr, sizeof(bk), 1, b_file);

		while(!feof(b_file))
		{
			if(strcmp(y_name,bptr.se_name)==0)
			{
				printf("\nEnter staff details ");

				printf("\n\tSender Name:        ");
				scanf("\n");
				gets(bptr.se_name);

				printf("\n\tSender Address:     ");
				gets(bptr.se_add);

				printf("\n\tSender City:        ");
				gets(bptr.se_city);

				printf("\n\tSender Phone number:");
				gets(bptr.se_pn);

				printf("\n\tSender mailid:");
				gets(bptr.se_id);

				printf("\n\tReceiver Name:        ");
				scanf("\n");
				gets(bptr.re_name);

				printf("\n\tReceiver  Address:     ");
				gets(bptr.re_add);

				printf("\n\tReceiver  City:        ");
				gets(bptr.re_city);

				printf("\n\tReceiver  Phone number:");
				gets(bptr.re_pn);

				printf("\n\tReciever email id:");
				gets(bptr.re_id);

				printf("\n\tDate of departure:");
				gets(bptr.c_date);

				cn++;
				fwrite(&bptr, sizeof(bk), 1, update_file);

			}
			else
			{
				fwrite(&bptr, sizeof(bk), 1, update_file);
			}

			fread(&bptr, sizeof(bk), 1, b_file);
		}

			if(cn>=1)
			{
			fclose(update_file);
			fclose(b_file);
			}
			else
			{
				printf("Sorry..... NO record found");
				fclose(update_file);
				fclose(b_file);
			}

		remove("booking.dat");
		rename("update.dat", "booking.dat");
	}
	printf("\n");
}

int courierDetails()					
{
	void c_details();
	void c_view();
	void c_update();
	int choice;

	while(1)
	{
		printf("\nChoice Menu: ");
		printf("\n1. Add Details");
		printf("\n2. View Details");
		printf("\n3. Update Details");
		printf("\n0. Exit");

		printf("\nEnter Your Choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0:
				return(EXIT_SUCCESS);

			case 1:
				c_details();
			break;

			case 2:
				c_view();
			break;

			case 3:
				c_update();
			break;
		}
	}

	printf("\n");
}

void c_details()					
	void l_view();
	void w_view();
	void t_view();

	FILE *c_file = NULL;
	cur cptr;

	c_file = fopen("courier.dat", "ab");

	if(c_file == NULL)
	{
		printf("Can't add courier details!");
	}

	else
	{
		printf("\nEnter Courier Details");

		printf("\nCourier ID: ");
		scanf("%d", &cptr.c_id);

		printf("\nCourier name: ");
		scanf("\n");
		gets(cptr.c_name);

		t_view();
		printf("\nType: ");
		scanf("\n");
		gets(cptr.type);

		l_view();
		printf("\nLocation: ");
		scanf("\n");
		gets(cptr.location);

		w_view();
		printf("\nWeight Range: ");
		scanf("\n");
		gets(cptr.wrange);

		fwrite(&cptr, sizeof(cur), 1, c_file);
		fclose(c_file);
	}

	printf("\n");
}

void c_view()					
{
	FILE *c_file = NULL;
	FILE *w_file = NULL;
	FILE *t_file = NULL;
	FILE *l_file = NULL;

	cur cptr;
	wtg wptr;
	loc lptr;
	tp tptr;

	int w_price;
	int t_price;
	int l_price;
	int sum;

	c_file = fopen("courier.dat", "rb");

	if(c_file == NULL)
	{
		printf("Can't view courier details");
	}

	else
	{
		fread(&cptr, sizeof(cur), 1, c_file);
		while(!feof(c_file))
		{
			printf("\nCourier ID: %d", cptr.c_id);
			printf("\nCourier Name: %s", cptr.c_name);
			printf("\nCourier Type: %s", cptr.type);
			printf("\nCourier Weight Range: %s", cptr.wrange);
			printf("\nLocation: %s", cptr.location);

			//Getting Price for given weight

			w_file = fopen("weight.dat", "rb");

			fread(&wptr, sizeof(wtg), 1, w_file);
			while(!feof(w_file))
			{
				if(strcmp(cptr.wrange, wptr.wrange) == 0)
				{
					w_price = wptr.w_price;
				}

				fread(&wptr, sizeof(wtg), 1, w_file);
			}
			fclose(w_file);

			//Getting Price for given type

			t_file = fopen("type.dat", "rb");

			fread(&tptr, sizeof(tp), 1, t_file);
			while(!feof(t_file))
			{
				if(strcmp(cptr.type, tptr.ctype) ==0)
				{
					t_price = tptr.t_price;
				}

				fread(&tptr, sizeof(tp), 1, t_file);
			}
			fclose(t_file);

			l_file = fopen("location.dat", "rb");

			fread(&lptr, sizeof(loc), 1, l_file);
			while(!feof(l_file))
			{
				if(strcmp(cptr.location, lptr.location) ==0)
				{
					l_price = lptr.l_price;
				}

				fread(&lptr, sizeof(loc), 1, l_file);
			}
			fclose(l_file);


			printf("\n\nTotal Amount is: %d", l_price+ w_price+ t_price);

			fread(&cptr, sizeof(cur), 1, c_file);

		}

		fclose(c_file);
	}

	printf("\n");
}
void c_update()				
{

	void l_view();
	void w_view();
	void t_view();
	int c_code,cn=0;
	cur cptr;
	FILE *c_file = NULL;
	FILE *temp_file = NULL;

	c_file = fopen("courier.dat", "rb");
	temp_file = fopen("temp.dat", "ab");

	printf("Enter courier id: ");
	scanf("%d", &c_code);

	if(c_file == NULL)
	{
		printf("Can't Update Data!");
	}

	else
	{
		fread(&cptr, sizeof(cur), 1, c_file);

		while(!feof(c_file))
		{
			if(c_code == cptr.c_id)
			{
				printf("\nCourier ID: ");
				scanf("%d", &cptr.c_id);

				printf("\nCourier name: ");
				scanf("\n");
				gets(cptr.c_name);

				t_view();
				printf("\nType: ");
				scanf("\n");
				gets(cptr.type);

				l_view();
				printf("\nLocation: ");
				scanf("\n");
				gets(cptr.location);

				w_view();
				printf("\nWeight Range: ");
				scanf("\n");
				gets(cptr.wrange);
				cn++;
				fwrite(&cptr, sizeof(cur), 1, temp_file);
			}

			else
			{
				fwrite(&cptr, sizeof(cur), 1, temp_file);
			}

			fread(&cptr, sizeof(cur), 1, c_file);
		}

			if(cn>=1)
			{
			fclose(temp_file);
			fclose(c_file);
			}
			else
			{
				printf("Sorry..... NO record found");
				fclose(temp_file);
				fclose(c_file);
			}

		remove("courier.dat");
		rename("temp.dat", "courier.dat");
	}

	printf("\n");
}


int otherDetails()					
{
	int Location();
	int Weight();

	int choice;

	while(1)
	{
		printf("\nChoice Menu");
		printf("\n1. Location Details");
		printf("\n2. Courier Type Details");
		printf("\n3. Courier Weight Details");
		printf("\n0. Exit");

		printf("\nEnter Your choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0:
				return(EXIT_SUCCESS);

			case 1:
				Location();
			break;

			case 2:
				Type();
			break;

			case 3:
				Weight();
			break;

			default:
				printf("Invalid Choice!");
			break;
		}
	}

	printf("\n");
}

int Location()					
{
	void l_details();
	void l_update();
	void l_view();

	int choice;

	while(1)
	{
		printf("\nChoice Menu: ");
		printf("\n1. Add Details");
		printf("\n2. View Details");
		printf("\n0. Exit");

		printf("\nEnter Your Choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0:
				return(EXIT_SUCCESS);

			case 1:
				l_details();
			break;

			case 2:
				l_view();
			break;

			default:
			break;
		}
	}

	printf("\n");
}

void l_details()					
{
	FILE *l_file = NULL;
	loc lptr;

	l_file = fopen("location.dat", "ab");

	if(l_file == NULL)
	{
		printf("\nCan't add location details!");
	}

	else
	{
		printf("\nEnter location: ");
		scanf("\n");
		gets(lptr.location);

		printf("\nEnter price for above location: ");
		scanf("%d", &lptr.l_price);

		fwrite(&lptr, sizeof(loc), 1, l_file);
		fclose(l_file);
	}

	printf("\n");
}

void l_view()					
{
	FILE *l_file = NULL;
	loc lptr;

	l_file = fopen("location.dat", "rb");

	if(l_file == NULL)
	{
		printf("Can't view location details!");
	}

	else
	{
		fread(&lptr, sizeof(loc), 1, l_file);
		while(!feof(l_file))
		{


			printf("\nLoaction: %s", lptr.location);
			printf("\nPrice: %d", lptr.l_price);
			printf("\n");

			fread(&lptr, sizeof(loc), 1, l_file);
		}

		fclose(l_file);
	}

	printf("\n");
}

int Weight()					
{
	void w_details();
	void w_view();

	int choice;

	while(1)
	{
		printf("\nChoice Menu: ");
		printf("\n1. Add Details");
		printf("\n2. View Details");
		printf("\n0. Exit");

		printf("\nEnter Your Choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0:
				return(EXIT_SUCCESS);

			case 1:
				w_details();
			break;

			case 2:
				w_view();
			break;

			default:
			break;
		}
	}

	printf("\n");
}

void w_details()					
{
	FILE *w_file = NULL;
	wtg wptr;

	w_file = fopen("weight.dat", "ab");

	if(w_file == NULL)
	{
		printf("\nCan't add weight details!");
	}

	else
	{
		printf("\nEnter weight range(gm/kg): ");
		scanf("\n");
		gets(wptr.wrange);

		printf("\nEnter price for above weight range: ");
		scanf("%d", &wptr.w_price);

		fwrite(&wptr, sizeof(wtg), 1, w_file);
		fclose(w_file);
	}

	printf("\n");
}

void w_view()					
	FILE *w_file = NULL;
	wtg wptr;

	w_file = fopen("weight.dat", "rb");

	if(w_file == NULL)
	{
		printf("Can't view weight details!");
	}

	else
	{
		fread(&wptr, sizeof(wtg), 1, w_file);
		while(!feof(w_file))
		{


			printf("\nWeight Range: %s", wptr.wrange);
			printf("\nPrice: %d", wptr.w_price);
			printf("\n");

			fread(&wptr, sizeof(wtg), 1, w_file);
		}

		fclose(w_file);
	}

	printf("\n");
}

int Type()					
{
	void t_details();
	void t_view();

	int choice;

	while(1)
	{
		printf("\nChoice Menu: ");
		printf("\n1. Add Details");
		printf("\n2. View Details");
		printf("\n0. Exit");

		printf("\nEnter Your Choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0:
				return(EXIT_SUCCESS);

			case 1:
				t_details();
			break;

			case 2:
				t_view();
			break;

			default:
			break;
		}
	}

	printf("\n");
}

void t_details()					
{
	FILE *t_file = NULL;
	tp tptr;

	t_file = fopen("type.dat", "ab");

	if(t_file == NULL)
	{
		printf("\nCan't add courier type details!");
	}

	else
	{
		printf("\nEnter courier type: ");
		scanf("\n");
		gets(tptr.ctype);

		printf("\nEnter price for above type: ");
		scanf("%d", &tptr.t_price);

		fwrite(&tptr, sizeof(tp), 1, t_file);
		fclose(t_file);
	}

	printf("\n");
}

void t_view()					
{
	FILE *t_file = NULL;
	tp tptr;

	t_file = fopen("type.dat", "rb");

	if(t_file == NULL)
	{
		printf("Can't view courier type details!");
	}

	else
	{
		fread(&tptr, sizeof(tp), 1, t_file);

		while(!feof(t_file))
		{

			printf("\nCourier type: %s", tptr.ctype);
			printf("\nPrice: %d", tptr.t_price);
			printf("\n");

			fread(&tptr, sizeof(tp), 1, t_file);
		}

		fclose(t_file);
	}

	printf("\n");
}
