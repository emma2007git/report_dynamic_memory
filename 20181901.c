#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
#include <stdlib.h>
#include <string.h>

typedef struct report
{
	char name[30]; 
	struct birth
	{
		int year;
		int month;
		int day;
	};
	char sex[30];
	char phonenum[11];
}REPORT;

int get_num(void);
void memory_error(REPORT * arr, int num);
void get_report(REPORT * arr[10], int num);
void print(REPORT*arr[10], int num);
void swap(REPORT*report1, REPORT*report2);
REPORT* order_by_name(REPORT*arr[10], int num);
REPORT* order_by_birth(REPORT*arr[10], int num);
void clearbuffer(void);

int main(void)
{
	int num;
	
	REPORT *arr[10];

	num = get_num();

	get_report(arr, num);

	memory_error(arr, num);

	printf("		--�Է��� ������� ���--\n\n");
	print(arr, num);
	printf("\n");

	printf("		--�̸� ������������ ���--\n\n");
	order_by_name(arr, num);
	print(arr, num);
	printf("\n");

	printf("	    --������� ������������ ���--\n\n");
	order_by_birth(arr, num);
	print(arr, num);
	printf("\n");

	for (int i = 0; i < num; i++)
		free(arr[i]);

	return 0;
}

int get_num(void)
{
	int num = 6;

	while (num < 7 || num >10)
	{
		printf("�Է��� ������ ������ �Է��Ͻÿ�:");
		scanf("%d", &num);

		if (num < 7 || num >10)
			printf("7~10�� �Է��Ͻÿ�\n");
	};

	printf("\n");
	return num;
}

void memory_error(REPORT *arr[10], int num)
{
	for(int i =0; i< num; i++)
		if (arr[i] == NULL)
		{
			printf("�޸� �Ҵ翡 ������ �ֽ��ϴ�.");
			exit(1); 
		}
}

void get_report(REPORT*arr[10], int num) 
{
	printf("������ �Է� ����: ������ 1999/01/01 ���� 01012345678\n\n");


	for (int x = 0; x < num; x++)
	{
		REPORT *preport = (REPORT*)malloc(sizeof(REPORT) * 1);

		printf("������ �Է�%d:", x + 1);	
		scanf("%s %4d/%02d/%02d %s %s", &((*preport).name), &((*preport).year), &((*preport).month), &((*preport).day), &((*preport).sex), &((*preport).phonenum));

		clearbuffer();

		arr[x] = preport;		
	}
	printf("\n");
}

void print(REPORT*arr[10], int num)
{
	printf("�̸�		�������		����		��ȭ��ȣ\n");

	for(int x=0; x<num; x++)
		printf("%s		%4d/%02d/%02d		%s		%s\n", (arr[x]->name), (arr[x] -> year), (arr[x] -> month), (arr[x] -> day),(arr[x] -> sex), (arr[x] -> phonenum));

}

void swap(REPORT*report1, REPORT*report2)
{
	REPORT temp;

	temp = *report1;
	*report1 = *report2;
	*report2 = temp;

}

REPORT* order_by_name(REPORT*arr[10], int num)
{
	int i, j;

	for(i=1;i<num;i++)
		for(j=i; j>0 && (strcmp((arr[j -1] -> name), (arr[j] -> name)) < 0); j--) 
			swap(arr[j - 1], arr[j]);

	return arr;
}

REPORT* order_by_birth(REPORT*arr[10], int num)
{
	for (int i = 1; i < num; i++)
		for (int j = i; j > 0; j--)
		{
			if ((arr[j- 1] -> year) > (arr[j] -> year))
				swap(arr[j - 1], arr[j]);

			if ((arr[j -1] -> year) == (arr[j] -> year))
				if ((arr[j - 1] -> month) > (arr[j] -> month))
					swap(arr[j - 1], arr[j]);

			if ((arr[j - 1] -> year == arr[j] -> year) && (arr[j - 1] -> month == arr[j] -> month))
				if (arr[j - 1] -> day > arr[j] -> day)
					swap(arr[j - 1], arr[j]);
		}

	return arr;
}

void clearbuffer(void) 
{
	while (getchar() != '\n');
}

