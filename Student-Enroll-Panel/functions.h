#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student std;
typedef struct proffessor prof;

struct student {
	char* name;
	int  cnd;
	char* grade;
	char* password;
	std* nextstd;
};

struct proffessor {
	char* name;
	char* password;
	std* newstd;
	prof* nextprof;
};


int insert_std(std* head, char* name, char* password);

int insert_prof(prof* head, char* name, char* password);

char* search_prof(char* user, prof * head_prof);

char* search_std(char* user, std * head_std);

int add_std_to_prof(prof* prof, char* name, char* password);

prof* get_profs(prof* head, int n);

int search(char* user, prof* head_prof);

void add_inform(char* user, int n, prof* head_prof);

add_grade(char* user, int n, prof*head_prof, char*grade);

char*read_grade(char* user, int n, prof* head_prof);

int search_toto(char* user, int n, prof* head_prof);

char* read(FILE* f);

char* request_list(int n, prof* head_prof);

void read_accept(prof* head_prof);

void read_stu(std* head_std);

void read_tch(prof* head_prof);

void teachers_list(prof* head_prof, char *user);

void emtiaz(prof* head_prof, char *user);

char** input(int *count);

