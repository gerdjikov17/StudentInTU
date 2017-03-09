//programa za timperaturiiii

#include <stdio.h>
#include <string.h>

void read_File(float *temp);
float average_temp(float *temp);
float quaters_Temp(float *temp, int *p);

int main()
{
	float temp[12];
	float avgTemp=0,quaterTemp=0;
	char Months[12][20] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
	int i = 0, p[3];
	
	read_File( temp );
	avgTemp = average_temp( temp );
	
	printf("Temperatures for every month of the year:\n");
	for(i=0;i<12;i++)
	{
		printf("%s : %.1f\n",Months[i],temp[i]);
	}
	printf("\n\nAverage temperature for the year : %.1f",avgTemp);
	
	printf("\nEnter three months you want to get average temperature of :");
	scanf("%d%d%d",&p[0],&p[1],&p[2]);
	quaterTemp=quaters_Temp( temp , p);
	printf("Average temperature for months : %s, %s and %s is : %.1f",Months[p[0]-1],Months[p[1]-1],Months[p[2]-1],quaterTemp);
}


void read_File(float *temp)
{
	FILE *fp;
	fp=fopen("temperatures.txt","r");
	int i=0;
	while(!feof(fp))
	{
		fscanf(fp,"%f",&temp[i]);
		i++;
	}
	fclose(fp);
}

float average_temp(float *temp)
{
	int i=0;
	int averageTemp=0;
	for(i=0;i<12;i++)
	{
		averageTemp+=temp[i];
	}
	return averageTemp/12;
}

float quaters_Temp(float *temp, int *p)
{
	int i=0;
	float quaterTemp=0;
  	for(i=0;i<3;i++)

	{
    quaterTemp+=temp[p[i]];
	}
	return quaterTemp/3;
}
