#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>


//main()
//{
//	double f;
//	double *pd = &f;
//	int i;
//	int *pi = &i;
//	printf("pi�� ��+1�� %d �Դϴ�.", ++pi);
//	pi = (int*)pd;
//	printf("pi�� ��+1�� %d �Դϴ�.", ++pi);
//}


//void swap(int *px, int *py)
//{
//	int tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//main()
//{
//	int a = 10, b = 20;
//	swap(&a, &b);
//	printf("a = %d\nb = %d", a, b);
//}


//void swap(int *px, int *py)
//{
//	int tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//main()
//{
//	int array[2] = { 10, 20 };
//	swap(array, array + 1);
//	printf("a = %d\nb = %d", array[0], array[1]);
//}


//main()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	printf("array = %d \narray+1 = %d \narray+2 = %d \n*array = %d \n*array+1 = %d \n&array = %d \narray[1] = %d\n", array, array + 1, array + 2, *array, *array + 1, &array, array[1]);
//}


//main()
//{
//	int i;
//	int *p;
//	p = &i;
//	scanf_s("%d", p);
//	printf("%d", i);
//}


//main()
//{
//	int array[] = { 1,2,3,4,5 };
//	for (int i = 0; i++; i < 5)
//		printf("%d ", array[i]);
//	printf("\n");
//	for (int i = 0; i++; i < 5)
//		printf("%d ", *(array+i+1));
//}


//main()
//{
//	int *p;
//	int a[] = { 1,2,3,4,5,6 };
//	p = a;
//	for (int i = 0; i < 6; i++)
//	{
//		printf("%d ", *p++);
//	} 
//}


//void getsensordata(int *p)
//{
//	printf("�����͸� �Է��Ͻÿ� : ");
//	scanf_s("%d", &p[0]);
//	printf("�����͸� �Է��Ͻÿ� : ");
//	scanf_s("%d", &p[1]);
//	printf("�����͸� �Է��Ͻÿ� : ");
//	scanf_s("%d", &p[2]);
//}
//
//main()
//{
//	int *p;
//	int sensordata[3];
//	getsensordata(sensordata);
//	p = sensordata;
//	printf("����Ÿ1 : %d\n", *sensordata);
//	printf("����Ÿ2 : %d\n", *(++p));
//	printf("����Ÿ3 : %d\n", *(sensordata + 2));
//}


//main()
//{
//	int a[] = { 10,20,30,40,50,60,70,80,90,100 };
//	int* p = a;
//	printf("%d ", *(a+8));
//	printf("%d ", a[8]);
//	printf("%d ", *p++);
//	printf("%d ", *p++);
//	printf("%d ", *p++);
//}

//main()
//{
//	int x = 6;
//	int *p = &x;
//	printf("%d\n", --(*p));
//	printf("%d\n", (*p)++);
//}


//main() 
//{
//	int *p = (int*)1000;
//	double *q = (double*)2000;
//	printf("%d\n", (int)(p + 2));
//	printf("%d\n", (int)(q + 1));
//}


//main()
//{
//	char a[] = "abc\0";
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%c", a[i]);
//	}
//	printf("\n");
//
//	char b[4] = "abcd";
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%s", b);
//	}
//	printf("\n");
//
//	char c[4] = {'a','b','c','d'};
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%c", c[i]);
//	}
//	printf("\n");
//
//	char d[5] = { 'A','B','C','D' };
//	int i = 0;
//	while (d[i] != '\0')
//	{
//		printf("%c", d[i]);
//		i++;
//	}
//	printf("\n\n%d",i);
//}


//main()
//{
//	char a[] = "abc\0";
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d��° �迭 : %c\n", i, a[i]);
//	}
//}


//main()
//{
//	char a[] = "abc";
//	char b[] = "def";
//	char c[] = "igh";
//	printf(a, b, c);
//}


//main()
//{
//	int i;
//	char a[] = "The Chungbuk University";
//	char b[100];
//	for (i = 0; a[i] != 0; i++)
//		b[i] = a[i];
//	b[i] = '\0';
//	printf(b);
//}

//main()
//{
//	char *p = "hello world";
//	p = "HELLO WORLD";
//	printf(p);  
//}


//main()
//{
//	int a;
//	while ((a = getchar()) != EOF)
//		putchar(a);
//}

//#include <conio.h>
//main()
//{
//	int ch;
//	while ((ch = _getch()) != 'q')
//		_putch(ch);
//}

//main()
//{
//	char a[100];
//	gets_s(a, 100);
//	puts(a);
//}

//main()
//{
//	char a[100];
//	printf("������ �Է��Ͻÿ� : ");
//	gets_s(a, 100);
//	int count = 0, waiting = 1;
//	for (int i = 0; a[i] != 0; i++)
//	{
//		if (isalpha(a[i]))
//		{
//			if (waiting)
//			{
//				count += 1;
//				waiting = 0;
//			}
//
//		}
//		else
//			waiting = 1;
//	}
//
//
//	printf("�ܾ��� ������ %d�� �Դϴ�.\n", count);
//}


//main()
//{
//	char *t1, *t2;
//	char s[] = "Hello World";
//	t1 = strtok(s, " ");
//	t2 = strtok(NULL, " ");
//	printf("1��° ��ū�� %s �̰� �ι�° ��ū�� %s�Դϴ�.\n", t1, t2);
//}


//main()
//{
//	char s[] = "Man is immortal, because he has a soul";
//	char seps[] = " ,\t\n";
//	char *tok;
//	tok = strtok(s, seps);
//	while (tok != NULL)
//	{
//		printf("��ū : %s\n", tok);
//		tok = strtok(NULL, seps);
//	}
//}

//main()
//{
//	char *s[3] = { "abc","defff","dafeefa" };
//	for(int i = 0; i<3;i++)
//	printf("i��° ��Ҵ� %s �Դϴ�.\n", s[i]);
//}

//main()
//{
//	char dic[5][2][30] =
//	{
//		{"apple","���apple"},
//		{"book","åbook"},
//		{"cow","��cow"},
//		{"desk","å��desk"},
//		{"english","����english"}
//	};
//	char word[30];
//	printf("ã�� �ܾ �Է��Ͻÿ� : ");
//	scanf("%s",word);
//	int a = 0;
//	int i;
//	for (i = 0; i < 5; i++)
//	{ 
//		if (strcmp(dic[i][0], word) == 0)
//		{
//			a = 1;
//			break;
//		}
//	}
//	if (a==1)
//		printf("���� %s �Դϴ�.\n", dic[i][1]);
//	else
//		printf("ã���ô� �ܾ �����ϴ�.\n");
//}

//main()
//{
//	char a[100];
//	printf("��ȣȭ�� ���ڿ��� �Է��Ͻÿ� : ");
//	gets_s(a, 100);
//	for (int i = 0; a[i] != 0; i++)
//	{
//		if(a[i]>='A'&&a[i]<='z')
//		a[i] = toupper(a[i]) + 3;
//		if (a[i] > 'Z')
//			a[i] -= 26;
//	}
//	printf("\n��ȣȭ�� ���ڿ��� %s �Դϴ�.\n", a);
//}

//main()
//{
//	char solution[] = "wheel of fortune";
//	char blank[100];
//	char answer;
//	int count = 0;
//	
//
//for (int i = 0; i < 100; i++)
//{
//	if (solution[i] > 'A' && solution[i] < 'z')
//		blank[i] = '_';
//	else if (solution[i] == ' ')
//		blank[i] = ' ';
//	else
//		blank[i] = '\0';
//}
//	while (strcmp(blank, solution) != 0)
//	{
//		printf("%s\n\n", blank);
//		printf("����Ǵ� ���ĺ��� �Է��Ͻÿ� : ");
//		scanf_s(" %c", &answer, sizeof(char));
//		for (int i = 0; i < 16; i++)
//		{
//			if (answer == solution[i])
//			{
//				blank[i] = solution[i];
//			}
//		}
//		printf("\n\n");
//		count++;
//	}
//	printf("%s\n\n%d�� ���� ���߼̽��ϴ�.\n", blank, count);
//}

//main()
//{
//	char a[100];
//	char b[100];
//	gets_s(a, 100);
//	for (int i = 0; i < 100; i++)
//	{
//		if (a[i] > 'A' && a[i] < 'z')
//			b[i] = '_';
//		else if (a[i] == ' ')
//			b[i] = ' ';
//		else
//			b[i] = '\0';
//	}
//	printf("%s", b);
//	
//}

//main()
//{
//	int n, x[5], y[5], temp, temp2;
//	FILE *fp = fopen("data.txt", "r");
//	fscanf(fp, "n=%d", &n);
//	for (int i = 0; i < 5; i++)
//	{
//		fscanf(fp, "\nx=%d y=%d", &x[i], &y[i]);
//	}
//
//	for (int i = 0; i < 5 - 1; i++)
//	{
//		for (int j = 0; j < 5 - 1 - i; j++)
//		{
//			if (y[j] > y[j + 1])
//			{
//				temp = y[j];
//				temp2 = x[j];
//				y[j] = y[j + 1];
//				x[j] = x[j + 1];
//				y[j + 1] = temp;
//				x[j + 1] = temp2;
//			}
//		}
//	}
//	for (int i = 4; i >= 0; i--)
//	{
//		printf("x=%d y=%d\n", x[i], y[i]);
//	}
//}

//main()
//{
//	char s1[] = "make";
//	char *s = "make";
//	int a;
//	printf("%d\n%d",sizeof(s1),strlen(s1));
//	printf("%d\n%d", sizeof(s), strlen(s));
//}

//main()
//{
//	char s[][10] = { "high","MIDDLE","LOW" };
//	printf("%s",s[1]);
//}

//main()
//{
//	char *p;
//	char s[] = "hello";
//	p = s + strlen(s) - 2;
//	while (p >= s)
//	{
//		printf("%s \n", p);
//		p--;
//	}
//}

struct srt {
	char *s;
	int len;
};

main()
{
	struct srt ALL[100];
	int i = 0;
	FILE *fp;
	if ((fp = fopen("let it be.txt", "r")) == NULL) {
		printf("������ ���� �����ϴ�.\n");
		exit(1);
	}
	while (feof(fp) != 1) 
	{
		fscanf(fp, "%s", ALL[i].s);
		ALL[i].len = strlen(ALL[i].s);
		i++;
	}
	
	for (int j = 0; j < i; j++)
		printf(ALL[i].s);


	/*struct srt x[100];
	x[0].s[0] = strtok(fscanf, " .\n");
	x[0].len = strlen(x[0].s[0]);
	for (int i = 1; fp == 0; i++)
	{
		if (feof(fp) == 1)
			break; 
		x[i].s[i] = strtok(NULL, " ");
		x[i].len = strlen(x[i].s[i]);
	}*/

}

//struct student {
//	char name[10];
//	int ��ȣ;
//	double ����;
//}s;
//
//void Print_str(struct student const *p1)
//{
//	printf("�л��� �̸� = %s, ��ȣ = %d, ���� = %.1f �Դϴ�.\n", (*p1).name, p1->��ȣ, p1->����);
//}
//
//
//main()
//{
//	struct student p;// = { "�̻���", 2019036020, 4.3 };
//	printf("�л��� �̸�, ��ȣ, ������ �Է��Ͻÿ� : ");
//	scanf("%s%d%lf", p.name, &p.��ȣ, &p.����);
//	Print_str(&p);
//}

//main()
//{
//	char p[10] = "�̻���";
//	puts(p);
//}

//main()
//{
//	int x;
//	scanf_s("%d\n", &x);
//	printf("%d", x);
//}
//
//main()
//{
//	char a[10];
//	char b[10];
//	int x = 0;
//	FILE *fp = fopen("let it be.txt", "r");
//	printf("ã���� �ܾ �Է��ϼ��� : ");
//	scanf("%s", a);
//	while (feof(fp) != 1)
//	{
//		fscanf(fp, "%s", b);
//		if (strcmp(a, b) == 0)
//			x++;
//	}
//	printf("%s �� %d�� �߰ߵǾ����ϴ�.\n", a, x);
//	fclose(fp);
//}