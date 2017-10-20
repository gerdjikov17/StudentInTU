/*author Gerdzhikov
Program to find number of characters in comments and number of characters in identifiers
using text files*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void inputKeyboard()
{
    FILE *tempFile;
    tempFile = fopen("temp.txt", "w");
    char inputString[300];

    while(strcmp(inputString, "stop\n") != 0)
    {
        fgets(inputString, 299, stdin);
        fprintf(tempFile, "%s", inputString);
    }
    fclose(tempFile);
}
int read_until_char_into (FILE *f, char c) {
   // read file until c is found a
   int ch;
   int i = 0;
   while ((ch=fgetc(f)) != c && !feof(f))
   {
	i++;	
   }
return i;
}

int comments(const char *filename) {
  FILE *f = fopen(filename, "r");
  int c;
  int i=0;
  int S=0;
  if (f) {
    while (!feof(f)) {
      read_until_char_into(f, '/');
      c = fgetc(f);
      if (c == '*') {
        while (!feof(f)) { 
          i = read_until_char_into(f, '*');
          S = S + i;
          if ((c=fgetc(f)) == '/') { 

            break;
          }
        }
      } else if (c == '/') {
         i = read_until_char_into(f, '\n');
         S = S + i;
         // print buffer
      }
    }

    fclose(f);
  }
  return S;
}

int string(const char *filename) {
  FILE *f = fopen(filename, "r");
  int c;
  int i=0;
  int S=0;
  if (f) {
    while (!feof(f)) {
      read_until_char_into(f, '(');
      c = fgetc(f);
      if (c == '"') {
        while (!feof(f)) { 
          i = read_until_char_into(f, '"');
          S = S + i;
          if ((c=fgetc(f)) == ')') { 

            break;
          }
        }
      }
    }

    fclose(f);
  }
  return S;
}

int numbers(const char *filename)
{
	FILE *f = fopen(filename, "r");
  int c;
  char op[10]= {'='};
  int i=0;
  int S=0;
  if (f) {
    while (!feof(f)) {
    	c=fgetc(f);
   	if(c>= ' ' && c<= '?')S--;
	if(c>= '{' && c<='~')S--;
	else{
		S++;
	}
  }
  }
  return S;
}

int Identifiers(const char *filename)
{
	int symbols = comments(filename);
	int strings = string(filename);
	int identifiers = numbers(filename);
	identifiers= identifiers-(symbols+strings);
//	printf("Symbols in comments are : %d\n", symbols);
//	printf("Symbols in the strings are : %d\n", strings);
//	printf("Symbols in identifiers : %d\n",allchars);
	return identifiers;
}
void TheMenu(int n)
{
    FILE *fp;
    char InputFile[55];
    char OutputFile[55];

    switch(n)
    {
    case 1:
        printf("Enter input file and output file name: ");
        scanf("%s", InputFile);
        scanf("%s",OutputFile);

        fp = fopen(OutputFile, "w");

        fprintf(fp, "Number of characters in comments: %d\nNumber of characters in identifiers: %d\n", comments(InputFile), Identifiers(InputFile));
        fclose(fp);
        break;
    case 2:
        printf("Enter input file: ");
        scanf("%s", InputFile);

        printf("Number of characters in comments: %d\nNumber of characters in identifiers: %d\n", comments(InputFile), Identifiers(InputFile));
        break;
    case 3:
        printf("Enter output file name:\n");
        scanf("%s", OutputFile);

        printf("Enter input. Write stop to stop\n");
        inputKeyboard();

        fp = fopen(OutputFile, "w");

        fprintf(fp, "Number of characters in comments: %d\nNumber of characters in identifiers: %d\n", comments("temp.txt"), Identifiers("temp.txt"));
        fclose(fp);
        break;
    case 4:
        printf("Enter input. Write 'stop' to stop\n");
        inputKeyboard();

        printf("Number of characters in comments: %d\nNumber of characters in identifiers: %d\n", comments("temp.txt"), Identifiers("temp.txt"));
        break;
    default:
        printf("Invalid number. Try again\n");
        main();
        break;
    }
}
int main()
{
    int menu;

    printf("Choose option\n1 - Read from file and output result in file\n2 - Read from file and output result in console\n3 - Read from keyboard and output in file\n4 - Read from keyboard and output in console\n");
    scanf("%d", &menu);
    TheMenu(menu);
    return 0;
}
