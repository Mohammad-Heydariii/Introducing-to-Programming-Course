#include "functions.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int insert_std(std* head, char* name, char* password) {
	std* last = head;
	while (last->nextstd != NULL)
		last = last->nextstd;
	last->nextstd = (std*)malloc(sizeof(std));
	if (last->nextstd == NULL)
		return 0;
	last = last->nextstd;                                   //tolide student
	last->name = (char *)malloc(strlen(name) * sizeof(char));
	strcpy(last->name, name);
	last->password = (char *)malloc(strlen(password) * sizeof(char));
	strcpy(last->password, password);
	last->cnd = 0;
	last->grade = -1;

	last->nextstd = NULL;
	return 1;
}

int insert_prof(prof* head, char* name, char* password) {
	prof* last = head;
	while (last->nextprof != NULL)
		last = last->nextprof;                                  //tolide teacher 
	last->nextprof = (prof*)malloc(sizeof(prof));
	if (last->nextprof == NULL)
		return 0;
	last = last->nextprof;
	last->name = (char *)malloc(strlen(name) * sizeof(char));
	strcpy(last->name, name);
	last->password = (char *)malloc(strlen(password) * sizeof(char));
	strcpy(last->password, password);
	last->nextprof = NULL;
	last->newstd = (std*)malloc(sizeof(std));
	last->newstd->nextstd = NULL;
	return 1;
}

char* search_prof(char* user, prof * head_prof)
{
	int i = 0;
	prof* curr = head_prof->nextprof;
	while (curr != NULL)                                 //search teacher 
	{
		i++;
		if (strcmp(user, curr->name))
			curr = curr->nextprof;
		else return curr->password;
	}
	return NULL;
}

char* search_std(char* user, std * head_std)               //search student 
{
	int i = 0;
	std* curr = head_std->nextstd;
	while (curr != NULL)
	{
		i++;
		if (strcmp(user, curr->name))
			curr = curr->nextstd;

		else return curr->password;
	}
	return NULL;
}

int add_std_to_prof(prof* prof, char* name, char* password) {
	std* head_stds = prof->newstd;
	return insert_std(head_stds, name, password);
}                                                            //tabe gharardadan student dar teacher marbote

prof* get_profs(prof* head, int n) {
	prof* last = head;
	int i;
	for (i = 0; i<n; i++) {
		if (last->nextprof == NULL && i<n)
			return NULL;                       
		last = last->nextprof;
	}
	return last;
}

int search(char* user, prof* head_prof)                   //search mogheeiat teacher 
{
	int i = 0;
	prof* curr = head_prof->nextprof;
	while (curr != NULL)
	{
		i++;
		if (strcmp(user, curr->name))
			curr = curr->nextprof;
		else return i;
	}
	return 0;
}
 
void add_inform(char* user, int n, prof* head_prof)          //farayande accept
{
	int i = 0;
	prof* curr = head_prof;
	for (i; i <n; i++)
		curr = curr->nextprof;


	std* currs = curr->newstd->nextstd;
	while (currs != NULL)
	{

		if (strcmp(user, currs->name))
			currs = currs->nextstd;

		else
		{
			currs->cnd = 1;
			break;
		}
	}


}


add_grade(char* user, int n, prof*head_prof, char*grade)  //farayande grade
{
	int i = 0;
	prof* curr = head_prof;
	for (i = 0; i <n; i++)
		curr = curr->nextprof;


	std* currs = curr->newstd->nextstd;

	while (currs != NULL)
	{

		if (strcmp(user, currs->name)) {

			currs = currs->nextstd;
		}

		else
		{

			currs->grade = grade;
			break;

		}

	}


}

char*read_grade(char* user, int n, prof* head_prof)
{
	int i = 0;                      //read grade 
	prof* curr = head_prof;
	for (i = 0; i<n; i++)
		curr = curr->nextprof;


	std* currs = curr->newstd->nextstd;
	while (currs != NULL)
	{



		if (strcmp(user, currs->name))
			currs = currs->nextstd;

		else

			return currs->grade;

	}
	return NULL;

}

int search_toto(char* user, int n, prof* head_prof)     //search vojode student in teacher link list 
{
	int i = 0;
	prof* curr = head_prof;
	for (i = 0; i<n; i++)
		curr = curr->nextprof;


	std* currs = curr->newstd->nextstd;
	while (currs != NULL)
	{

		if (strcmp(user, currs->name))
			currs = currs->nextstd;

		else

			return 1;

	}
	return 0;

}

char* read(FILE* f) {                                    //read za file
	char* s = malloc(sizeof(char));
	*s = fgetc(f);
	int i = 0;
	while (*(s + i) != ' ' && *(s + i) != '\n'&&*(s + i) != EOF) {
		i++;
		s = (char*)realloc(s, sizeof(char)*(i + 1));
		s[i] = fgetc(f);
	}
	if (*(s + i) == EOF&& i == 0)
		return NULL;
	s[i] = NULL;
	return s;
}
           
char* request_list(int n, prof* head_prof)   //print request list
{
	int i = 0;
	prof* curr = head_prof;
	for (i = 0; i <n; i++)
		curr = curr->nextprof;


	std* currs = curr->newstd->nextstd;
	while (currs != NULL)
	{

		if (currs->cnd == 0)
		{
			printf("%s\n", currs->name);
		}
		currs = currs->nextstd;
	}

}

void read_accept(prof* head_prof)                   //write accept & request in file
{
	FILE*fg = fopen("request.txt", "w");
	FILE*fk = fopen("accept.txt", "w");
	prof*curr = head_prof->nextprof;
	while (curr != NULL) {

		fprintf(fg, "%s $\n", curr->name);
		fprintf(fk, "%s $ $\n", curr->name);

		std* currs = curr->newstd->nextstd;
		while (currs != NULL)
		{

			if (currs->cnd != 0) {
				fprintf(fk, "%s ", currs->name);
				fprintf(fk, "%s ", currs->password);
				fprintf(fk, "%s\n", currs->grade);


				currs = currs->nextstd;
			}

			else
			{
				fprintf(fg, "%s ", currs->name);
				fprintf(fg, "%s\n", currs->password);
				currs = currs->nextstd;
			}

		}

		curr = curr->nextprof;

	}
	fclose(fg);
	fclose(fk);

}


void read_stu(std* head_std)                       // write student 
{
	FILE*fp = fopen("student.txt", "w");
	std* currs = head_std->nextstd;
	while (currs != NULL)
	{
		fprintf(fp, "%s ", currs->name);
		fprintf(fp, "%s\n", currs->password);
		currs = currs->nextstd;
	}

	fclose(fp);

}

void read_tch(prof* head_prof)
{                                                     // write teacher 

	FILE*fc = fopen("teacher.txt", "w");
	prof* currs = head_prof->nextprof;
	while (currs != NULL)
	{

		fprintf(fc, "%s ", currs->name);
		fprintf(fc, "%s\n", currs->password);
		currs = currs->nextprof;

	}
	fclose(fc);
}

void teachers_list(prof* head_prof, char *user)
{                                                      //print teacher list

	
	prof*curr = head_prof->nextprof;
	while (curr != NULL) {




		std* currs = curr->newstd->nextstd;
		while (currs != NULL)
		{
			if (!strcmp(user, currs->name))
			{

				if (currs->cnd != 0) {
					printf("%s\n",curr->name);
					currs = currs->nextstd;
				}

				else
				{
					currs = currs->nextstd;
				}

			}

		}

		curr = curr->nextprof;

	}



}

void emtiaz(prof* head_prof, char *user)
{                                                        //emtiazi
	float c = 0;
	int i = 0;
	prof*curr = head_prof->nextprof;

	while (curr != NULL) {




		std* currs = curr->newstd->nextstd;
		while (currs != NULL)
		{
			if (!strcmp(user, currs->name))
			{

				if (currs->cnd != 0) {
					printf("%s ", curr->name);
					printf("%s\n", currs->grade);
					float b = atof(currs->grade);

					c = b + c;


					currs = currs->nextstd;
				}

				else
				{
					currs = currs->nextstd;
				}

			}

		}

		curr = curr->nextprof;
		i++;

	}


	printf("%f\n", c / i);
}

char** input(int *count)
{
	int length = 1;
	char c = NULL;                                             //tabe voorody
	char **p = NULL;
	char s1[] = "signup_teacher", s2[] = "signup_student";
	int i;
	char c2 = NULL;

	length = 1;
	*count = 0;
	p = NULL;
	p = (char**)malloc(sizeof(char*));
	p[0] = (char*)malloc(sizeof(char));


	while (c2 != '\n')
	{
		c2 = getchar();
		if (c2 == ' ')
		{
			length = 1;
			(*count)++;
			p = (char**)realloc(p, (*count + 1) * sizeof(char*));
			p[*count] = (char*)malloc(sizeof(char));
			continue;
		}

		p[*count][length - 1] = c2;
		p[*count] = realloc(p[*count], sizeof(char)*(length + 1));
		p[*count][length] = '\0';
		length++;

	}
	p[*count][length - 2] = '\0';
	(*count)++;
	printf("\n");
	return p;
}


