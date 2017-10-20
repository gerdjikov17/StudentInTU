//author Gerdzhikov
//Program that distributes course projects to different students and writes in file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
	
    int studentNumber[30];
    int kursovaNumber[25];
    int randomNumber, i = 0, j = 0;
	int scan;
	
	FILE * ASD;
	ASD = fopen("Kursovi.txt", "w");
	
	printf("How many students ?\n");
	scanf("%d", &scan);
	
    srand(time(NULL));
	
    while(i <= scan)
    {
        for(j = 0; j <= i; j++)
            {
                if(kursovaNumber[j] == randomNumber) 
                {
                	
                    randomNumber = rand()%25+1; 
                    j=0;
                }
            }

        kursovaNumber[i] = randomNumber;

        i++;
		
        if(i > 1) 
        {
            fprintf(ASD, "Student %d has project %d \n", i-1, randomNumber);
        }
        
    }
    fclose(ASD);
}
