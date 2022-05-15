#include<stdio.h>

struct Country
{
	char name[100];
	int goldNum;
	int silverNum;
	int bronzeNum;
	int totalNum;
};
typedef struct Country Country;

void printCountry(Country c)
{
	printf("%s %d %d %d %d\n", c.name, c.goldNum, c.silverNum, c.bronzeNum, c.totalNum);
}

int main()
{
	Country c[8];
	FILE* fp = fopen("C:\\m.txt", "r");
	if (fp == NULL)
	{
		printf("Error!\n");
		return 0;
	}
	for (int i = 0; i < 8; i++)
	{
		fscanf(fp, "%s %d %d %d %d", c[i].name, &c[i].goldNum, &c[i].silverNum, &c[i].bronzeNum, &c[i].totalNum);
	}

	fclose(fp);
	Country min = c[0];
	for (int i = 0; i < 8; i++)
	{
		if (c[i].totalNum < min.totalNum)
		{
			min = c[i];
		}
	}
	printf("奖牌数最少的国家信息\n");
	printCountry(min);
	return 0;
}