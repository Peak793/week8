#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct subject {
	char name[10];
	float midterm;
	float final;
	float credit;
};
float sumCredit(struct subject *sub,int n)
{
	float sum = 0;
	for (int i = 0; i < n; i++)
		sum += sub[i].credit;
	return sum;
}
void calculateGrade(struct subject *sub,int n) {
	for (int i = 0; i < n; i++)
	{
		if (sub[i].midterm <= 100 && sub[i].midterm >= 80)
			sub[i].midterm = 4;
		else if (sub[i].midterm < 80 && sub[i].midterm >= 75)
			sub[i].midterm = 3.5;
		else if (sub[i].midterm < 75 && sub[i].midterm >= 70)
			sub[i].midterm = 3.0;
		else if (sub[i].midterm < 70 && sub[i].midterm >= 65)
			sub[i].midterm = 2.5;
		else if (sub[i].midterm < 65 && sub[i].midterm >= 60)
			sub[i].midterm = 2.0;
		else if (sub[i].midterm < 60 && sub[i].midterm >= 55)
			sub[i].midterm = 1.5;
		else if (sub[i].midterm < 55 && sub[i].midterm >= 50)
			sub[i].midterm = 1.0;
		else
			sub[i].midterm = 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (sub[i].final <= 100 && sub[i].final >= 80)
			sub[i].final = 4;
		else if (sub[i].final < 80 && sub[i].final >= 75)
			sub[i].final = 3.5;
		else if (sub[i].final < 75 && sub[i].final >= 70)
			sub[i].final = 3.0;
		else if (sub[i].final < 70 && sub[i].final >= 65)
			sub[i].final = 2.5;
		else if (sub[i].final < 65 && sub[i].final >= 60)
			sub[i].final = 2.0;
		else if (sub[i].final < 60 && sub[i].final >= 55)
			sub[i].final = 1.5;
		else if (sub[i].final < 55 && sub[i].final >= 50)
			sub[i].final = 1.0;
		else
			sub[i].final = 0;
	}
}
int main() {
	int n=0;
	printf("Enter the number of subject : ");
	scanf_s("%d",&n);
	if (n < 1)
	{
		printf("Error");
		return 0;
	}
	struct subject* sub;
	sub = (struct subject*)malloc(n * sizeof(struct subject));
	for (int i = 0; i < n; i++)
	{
		printf("%d : ", i + 1);
		scanf("%s", sub[i].name);
	}

	printf("\n---------------------------------------\n");
	printf("Enter the credit of the following subject\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("%s : ",sub[i].name);
		scanf("%f",&sub[i].credit);
		if (sub[i].credit < 1)
		{
			printf("Error");
			return 0;
		}
	}
	float creditSum = sumCredit(sub,n);
	printf("\n---------------------------------------\n");
	printf("Enter the score of the following subject\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("%s :\n", sub[i].name);
		printf("   midterm score = ");
		scanf("%f",&sub[i].midterm);
		printf("   finalterm score = ");
		scanf("%f", &sub[i].final);
		if (sub[i].midterm < 0 || sub[i].midterm>100 || sub[i].final < 0 || sub[i].final >100)
		{
			printf("Error"); 
			return 0;
		}
	}
	calculateGrade(sub,n);
	float sum = 0;
	float sum2 = 0;
	for (int i = 0; i < n; i++) {
		sum += (sub[i].midterm * sub[i].credit);
	}
	float midtermGrade = sum / creditSum;
	for (int i = 0; i < n; i++) {
		sum2 += (sub[i].final * sub[i].credit);
	}
	float finalGrade = sum2 / creditSum;
	float yourGrade = (midtermGrade + finalGrade)/2;
	printf("\n\nYour grade is %f", yourGrade);
	return 0;
}