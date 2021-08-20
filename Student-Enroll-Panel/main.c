#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "functions.h"

int main()
{
	int v = 0;
	char ch = NULL;
	char*nam = (char*)malloc(v);
	char* temp;
	char*flag;
	char*sad;                                        //tarife moteghayer ha 
	int change = 0;
	prof head_teacher;
	head_teacher.nextprof = NULL;
	std head_student;
	head_student.nextstd = NULL;

	int t = 0, z = 0, i, w = 0, x = 0, l = 0, a = 0, b = 0, d = 0, u = 0, o = 0, y = 0, j = 0, k = 0;
	char c = NULL;
	char **p = NULL;
	int f = 0;
	char s1[] = "signup_teacher", s2[] = "signup_student", s3[] = "logout", s4[] = "request_course", s5[] = "exit", s6[] = "requests_list", s7[] = "login_student", s8[] = "login_teacher", s9[] = "show_grade", s10[] = "accept", s11[] = "grade", s12[] = "teachers_list", s13[] = "show_grades";
	int log = 0;
	FILE *fp;
	FILE *fc;
	FILE*fk;
	fk = fopen("accept.txt", "r");
	fp = fopen("student.txt", "r");
	fc = fopen("teacher.txt", "r");                     //tarife file ha
	FILE*fg = fopen("request.txt", "r");
	char*te = (char*)malloc(sizeof(char));
	char*fe = (char*)malloc(sizeof(char));
	char*be = (char*)malloc(sizeof(char));

	while (1) {

		te = read(fp);                                         //read az file
		fe = read(fp);
		if (te == NULL || fe == NULL)
			break;
		insert_std(&head_student, te, fe);
	}

	while (1) {
		                                                     //read az file
		te = read(fc);
		fe = read(fc);
		if (te == NULL || fe == NULL)
			break;
		insert_prof(&head_teacher, te, fe);
	}
	int q;
	int checker = 0;
	while (1){
		if (checker == 0)
		{
			te = read(fg);
			fe = read(fg);
		}                                                            //read az file
		if (te == NULL || fe == NULL)
			break;

		if (!strcmp(fe, "$")){
			q = search(te, &head_teacher);
			te = read(fg);
			fe = read(fg);

			if (te == NULL || fe == NULL)
				break;

			if (!strcmp(fe, "$")){
				q = search(te, &head_teacher);
				te = read(fg);
				fe = read(fg);
				checker = 1;
				continue;
			}
			else
			{
				checker = 0;
			}
		}
		add_std_to_prof(get_profs(&head_teacher, q), te, fe);
	}

	checker = 0;
	while (1){


		if (checker == 0)
		{
			te = read(fk);
			fe = read(fk);
			be = read(fk);
		}
		if (te == NULL || fe == NULL || be == NULL)
			break;

		if (!strcmp(be, "$")){
			q = search(te, &head_teacher);                                    //read az file
			te = read(fk);
			fe = read(fk);
			be = read(fk);
			
			if (te == NULL || fe == NULL || be == NULL)
				break;
			if (!strcmp(be, "$")){
				q = search(te, &head_teacher);
				te = read(fk);
				fe = read(fk);
				be = read(fk);
				checker = 1;
				continue;
			}
			else
			{
				checker = 0;
			}
		}
		add_std_to_prof(get_profs(&head_teacher, q), te, fe);
		add_inform(te, q, &head_teacher);
		add_grade(te, q, &head_teacher, be);
	}

	while (l != 4) {                         //while koly barname

		f++;

		z = 0, t = 0, w = 0, x = 0, l = 0;
		p = NULL;

		int count;
		p = input(&count);

		if (!strcmp(p[0], s1)) {
			t = 14;
		}

		else if (!strcmp(p[0], s2)) {
			z = 14;
		}


		else if (!strcmp(p[0], s4)) {
			x = 14;
		}
		else if (!strcmp(p[0], s3)) {
			w = 6;
		}                                               //shorote vorody barname 

		else if (!strcmp(p[0], s5)) {
			l = 4;
		}

		else if (!strcmp(p[0], s6)) {
			a = 12;
		}

		else if (!strcmp(p[0], s7)) {
			b = 13;
		}

		else if (!strcmp(p[0], s8)) {
			d = 13;
		}

		else if (!strcmp(p[0], s9)) {
			u = 10;
		}

		else if (!strcmp(p[0], s10)) {
			o = 6;
		}

		else if (!strcmp(p[0], s11)) {
			y = 5;
		}

		else if (!strcmp(p[0], s12)) {
			j = 12;
		}

		else if (!strcmp(p[0], s13)) {
			k = 11;
		}

		else
			printf("false input\n");
		if (t == 14)
		{
			if (search_prof(p[1], &head_teacher) == NULL) {
				if (log == 0) {                                      //tarife shorote barname va dastor ha
					if (count < 3)                                             
					{
						printf("you must ENTER three input.\n");
						continue;
					}
					temp = p[1];
					flag = p[2];
					insert_prof(&head_teacher, p[1], p[2]);
					printf("teacher %s is added", p[1]);
					printf("\n");
					log = 1;
				}
				else
				{
					printf("You must log out.\n");
				}
			}
			else
			{
				printf("dade tekrary\n");
			}

		}
		if (z == 14) {
			if (search_std(p[1], &head_student) == NULL) {
				if (log == 0) {
					if (count < 3)
					{                                                     
						printf("you must ENTER three input.\n");
						continue;                                        //tarife shorote barname va dastor ha
					}
					temp = p[1];
					flag = p[2];
					insert_std(&head_student, p[1], p[2]);
					printf("student %s is added", p[1]);
					printf("\n");
					log = 2;
				}
				else
				{
					printf("You must log out.\n");
				}
			}
			else
			{
				printf("dade tekrary\n");
			}

		}
		if (w == 6)                                           //tarife shorote barname va dastor ha
		{
			if (log != 0)
			{
				log = 0;
				printf("you are logged out successfully!\n");
			}
			else
			{
				printf("you didn't sign in!\n");
			}
		}
		                                        //tarife shorote barname va dastor ha
		if (x == 14)
		{
			if (log == 2) {
				if (count < 2)
				{
					printf("you must ENTER three input.\n");
					continue;
				}

				if (search_prof(p[1], &head_teacher) == NULL) {
					printf("ostad nist\n");
				}
				
				if (search_prof(p[1], &head_teacher) != NULL) {
					printf("you requested the course\n");
					add_std_to_prof(get_profs(&head_teacher, search(p[1], &head_teacher)), temp, flag);
				}
			}
		}                                                   //tarife shorote barname va dastor ha


		if (l == 4)
		{
			read_stu(&head_student);
			read_tch(&head_teacher);
			read_accept(&head_teacher);
			exit(1);
		}

		if (a == 12)
		{
			if (log == 1) {
				printf("\trequest list\n---------------------\nusername: \n\n");
				search(temp, &head_teacher);
				request_list(search(temp, &head_teacher), &head_teacher);
			}
		}
		if (d == 13)
		{
			if (search_prof(p[1], &head_teacher) == NULL) {             //tarife shorote barname va dastor ha

				printf("user not found\n");
			}
			else {
				if (log == 0) {
					if (count < 3)
					{
						printf("you must ENTER three input.\n");
						continue;
					}
					if (!strcmp(search_prof(p[1], &head_teacher), p[2])) {
						printf("welcome back %s\n", p[1]);
						temp = p[1];
						flag = p[2];
						log = 1;
					}                                           //tarife shorote barname va dastor ha
					else {
						printf("wrong password or user\n");
						log = 0;
					}		
				}
			}
		} 
	                                      	//tarife shorote barname va dastor ha
		if (b == 13)
		{
			if (search_std(p[1], &head_student) == NULL) {

				printf("user not found\n");
			}
			else {
				if (log == 0) {
					if (count < 3)
					{
						printf("you must ENTER three input.\n");
						continue;
					}
					if (!strcmp(search_std(p[1], &head_student), p[2])) {
						temp = p[1];
						flag = p[2];
						printf("welcome back %s\n", p[1]);
						log = 2;
					}
					else {
						printf("wrong password or user\n");
						log = 0;
					}
				}	
			}
		}                                                //tarife shorote barname va dastor ha
		if (u == 10)
		{
			if (log == 2) {
				if (count < 2)
				{
					printf("you must ENTER three input.\n");
					continue;
				}
				if (search_prof(p[1], &head_teacher) != NULL) {
					if (search_toto(temp, search(p[1], &head_teacher), &head_teacher) == 1)
					{
						printf("nomrt ro bbin\n");
						sad = read_grade(temp, search(p[1], &head_teacher), &head_teacher);
						printf("%s\n", sad);
					}
					else {
						printf("doesnot request course\n");
					}
				}
				else                                           //tarife shorote barname va dastor ha
				{
					printf("teacher you intered not found");
				}
			}
		}
		if (o == 6)
		{
			if (log == 1) {
				if (count < 2)
				{
					printf("you must ENTER three input.\n");
					continue;
				}
				add_inform(p[1], search(temp, &head_teacher), &head_teacher);
				printf("bia ta accept konmt!\n");
			}
			change = 1;                                         //tarife shorote barname va dastor ha
		}
		if (y == 5)
		{
			if (change == 1) {
				if (log == 1) {
					if (count < 3)
					{
						printf("you must ENTER three input.\n");
						continue;
					}
					printf("nomre dade shod\n");
					add_grade(p[1], search(temp, &head_teacher), &head_teacher, p[2]);
				}
				change = 0;
			}
		}

		if (j == 12) {                                                    //tarife shorote barname va dastor ha

			if (log == 2) {

				teachers_list(&head_teacher, temp);


			}
		}

		if (k == 11) {

			if(log==2){

			emtiaz(&head_teacher, temp);                                      //tarife shorote barname va dastor ha


				}
		}
		z = 0; t = 0, x = 0, w = 0, l = 0, a = 0, b = 0, d = 0, u = 0, o = 0, y = 0;
	}
}

