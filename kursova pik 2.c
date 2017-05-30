#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct _students{
	int number;
	char firstName[15];
	char secondName[15];
	char familyName[15];
	char faculty[10];
	char specialty[10];
	int group;
	int course;
	struct _students *next;
}students_t;
students_t *students;
students_t *root = NULL;
students_t *node = NULL;

void go_to_end();
void read_struct_file();
void menu();
void add_student();
void print_students();
void search_by_family_name();
void del_by_number();
void sort_by_group();
void save_students();
int compare(const void *a, const void *b);

int main()
{
	read_struct_file();
	menu();
}

void menu()
{
	int choice;
	printf("-----------------------------------------------------------------------------------------------\n");
	printf("1:Add student.\n2:Search student by family name.\n3:Delete student by number.\n4:Display students from specific group by alphabetical order.\n5:Display all students.\n6:Save the structure in binary file.\n0:Exit!\n");
	scanf("%d",&choice);
	switch (choice)
	{
		case 1:
			add_student();
			menu();
			break;
		case 2:
			search_by_family_name();
			menu();
			break;
		case 3:
			del_by_number();
			menu();
			break;
		case 4:
			sort_by_group();
			menu();
			break;
		case 5:
			print_students();
			menu();
			break;
		case 6:
			save_students();
			menu();
			break;
		case 0:
			exit(0);
		default : printf("Invalid option.Try again");
		menu();
			break;
	}
}

void read_struct_file()
{
	FILE *fp;
	fp=fopen("students.bin","rb");
	while(1)
	{
		if (root==NULL)
		{
			root = (students_t*) malloc(sizeof(students_t));
			if(fread(root,sizeof(students_t),1,fp)!=1) break;;
			node = root;
			root->next = NULL;
		}
		else
		{
			node->next = (students_t*) calloc(sizeof(students_t),1);
			node = node->next;
			if(fread(node,sizeof(students_t),1,fp)!=1) break;
		}
	}
	node->next= NULL;
	fclose(fp);
}

void add_student()
{
	go_to_end();
	node->next = (students_t*)calloc(sizeof(students_t),1);
	node=node->next;	
	printf("Write student's number:");
	scanf("%d",&node->number);
	printf("Write student's first name:");
	scanf("%s",node->firstName);
	printf("Write student's second name:");
	scanf("%s",node->secondName);
	printf("Write student's family name:");
	scanf("%s",node->familyName);
	printf("Write student's faculty:");
	scanf("%s",node->faculty);
	printf("Write student's specialty:");
	scanf("%s",node->specialty);
	printf("Write student's group:");
	scanf("%d",&node->group);
	printf("Write student's course:");
	scanf("%d",&node->course);
	
	node->next = NULL;
}

void print_students()
{
	if(root==NULL) exit(0);
	node = root;
	printf("Struct info:\n");
	while(1){
		printf("Student number :%d\nStudent first name:%s\nStudent second name:%s\nStudent family name:%s\nStudent faculty:%s\nStudent specialty:%s\nStudent group:%d\nStudent course:%d\n\n",node->number,node->firstName,node->secondName,node->familyName,node->faculty,node->specialty,node->group,node->course);
		node = node->next;
		if(node==NULL) break;
	}
}

void go_to_end()
{
	if(root==NULL) return;
	node=root;
		while(1)
		{
			if (node->next==NULL) break;
			else node=node->next;
		}
}

void search_by_family_name()
{
	char name[15];
	printf("Write student's name:");
	scanf("%s",name);
	node = root;
	while(node != NULL)
    {
        if(strcmp(node->familyName, name) == 0)
        {
            printf("\nStudent information:\n");
            printf("Student number :%d\nStudent first name:%s\nStudent second name:%s\nStudent family name:%s\nStudent faculty:%s\nStudent specialty:%s\nStudent group:%d\nStudent course:%d\n\n",node->number,node->firstName,node->secondName,node->familyName,node->faculty,node->specialty,node->group,node->course);
            break;
        }
        node = node->next;
        if(node==NULL) printf("No such name!\n");
    }
}

void del_by_number()
{
	students_t *prev;
	int number;
	int flag=0;
	printf("Write the student's number :");
	scanf("%d",&number);
	node=root;
	while(node!=NULL)
	{
		if(node->number==number)
		{
			flag=1;
			if(node == root)
            {
                root = node->next;
                free(node);
                printf("Student with number [%d] has been removed",number);
            }
            else
            {
                prev->next = node->next;
                free(node);
				printf("Student with number [%d] has been removed",number);
            }
        }
        prev = node;
        node = node->next;
	}
	if(flag==0) printf("No such student number!\n");
}

void sort_by_group()
{
	int group,i=0,j=0;
	char **names;
	printf("\nSort students by specific group.Write group:");
	scanf("%d",&group);
	node=root;
	names = (char**)calloc(sizeof(char),1);
	while(node!=NULL)
	{
		if(node->group==group)
		{
			names = (char**)realloc(names,i+1);
			names[i] = (char*)malloc(sizeof(node->firstName));
			names[i]=node->firstName;
			i++;
		}
		node=node->next;
	}
	if(i==0) printf("No such group!\n");
	else
	{
		qsort(names, i, sizeof(char*), compare);
		
	//	PRINTING SORTED STRUCTS
	
		printf("Students from group [%d] sorted alphabetically :\n",group);
		printf("=====================================================================================================================\n");
		for(j=0;j<i;j++)
		{
			node=root;
			while(node!=NULL)
			{
				if(strcmp(names[j],node->firstName)==0)
				{
	        		printf("Student number :%d\nStudent first name:%s\nStudent second name:%s\nStudent family name:%s\nStudent faculty:%s\nStudent specialty:%s\nStudent group:%d\nStudent course:%d\n\n",node->number,node->firstName,node->secondName,node->familyName,node->faculty,node->specialty,node->group,node->course);
				}
				node = node->next;
			}		
		}
	}
}

int compare(const void *a, const void *b)
{
    const char *pa = *(const char**)a;
    const char *pb = *(const char**)b;

    return strcmp(pa,pb);
}

void save_students()
{
	FILE *fp;
	fp = fopen("students.bin","wb");
	node=root;
	while(node->next!=NULL)
	{	
			fwrite(node,sizeof(students_t),1,fp);
			node=node->next;
	}
	fclose(fp);
}
