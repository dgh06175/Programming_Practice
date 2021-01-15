#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
#define player 2
#define TYPE 4
#define NUM 13

const char* ctypes[TYPE] = { "��","��","��","��" };
const char* ntypes[NUM] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
//52���� ī�带 ���Ƿ� �迭 array[52]�� ���������� �ֱ�
void generate(int array[]);
//player1[7], player2[7]�� array�迭 0���� 13���� ���� �ֱ�
void change(int player1[], int player2[], int array[]);
//��ǻ���� �� ���� ***�� ��Ÿ���� ������ �� ��� ���� ī�� 3���� �����ϱ�
void open1(int player1[], int player2[]);
//������ ��� �������� �������� ����ϰ� �� ������ ������ ����
int bet();
//x������ ī�带 ����
void show(int player1[], int player2[], int x);
//��ǻ�Ϳ� ���� ī�� ��θ� ����
void showall(int player1[], int player2[]);
//��ǻ���� ī�尡 ���� �������� üũ
int made1(int player1[]);
//���� ī�尡 ���� �������� üũ
int made2(int player2[]);
//��ǻ���� ī�带 ������������ ����
void sort1(int player1[]);
//���� ī�带 ������������ ����
void sort2(int player2[]);
void swap(int* xp, int* yp);
//��ǻ���� ���հ� ���� ������ ���Ͽ� ���ڸ� ����
void winner(int result1, int result2);
//count1=��ǻ�Ͱ� �̱� Ƚ�� , count2=���� �̱� Ƚ��, count3=���º� Ƚ��
int count1 = 0, count2 = 0, count3 = 0;
void main()
{
    printf("================================================\n");
    printf("           ��Ŀ���� (Player 2�� ��)             \n");
    printf("================================================\n");
    srand((unsigned)time(NULL));
    while (1)
    {

        int b = 0;//bet�Լ��� �Է¹޴� b�� �ʱ�ȭ
        int result1 = 0, result2 = 0; // ��ǻ�Ϳ� ���� ������ �Է��Ҹ��� ���� �ʱ�ȭ
        int array[52] = { 0 };
        int player1[7];
        int player2[7];
        generate(array);
        change(player1, player2, array);
        open1(player1, player2);
        if (bet() == 1)//3���� ���µ� ��Ȳ���� ������ �ɰ� b==1�� �� ���� �۾� ����
        {
            show(player1, player2, 3);
            if (bet() == 1)
            {
                show(player1, player2, 4);
                if (bet() == 1)
                {
                    show(player1, player2, 5);
                    if (bet() == 1)
                    {
                        show(player1, player2, 6);
                        showall(player1, player2);
                        sort1(player1);
                        sort2(player2);
                        result1 = made1(player1);
                        result2 = made2(player2);
                        winner(result1, result2);
                    }
                }
            }


        }
    }


}

void generate(int array[])
{
    int i;
    for (i = 0; i < 52; i++)
    {
        while (1)
        {
            int n = 0;//�ߺ��� ī�尡 �ִ��� Ȯ���ϱ� ���� ���� �ʱ�ȭ
            array[i] = rand() % 52;
            if (i == 0) break;//ù��°�� �̰� �ߺ� ��� Ȯ�� ���ϰ� �� ��° ī�� �̱�
            for (int j = 0; j < i; j++)
                if (array[i] == array[j])
                    n++;
            if (n == 0)
                break;
        }
    }
}

void change(int player1[], int player2[], int array[])
{
    int i, j;
    for (i = 0; i < 7; i++)
        player1[i] = array[i];
    for (j = 0; j < 7; j++)
        player2[j] = array[j + 7];

}

void open1(int player1[], int player2[])
{
    int type1, num1, type2, num2;//type1�� player1�� ī���� ���, num1�� player1�� ī���� ����
    printf("     <Player 1 �� ī��>\n");
    type1 = player1[2] / NUM;//0="��",1="��",2="��",3="��"
    num1 = player1[2] % NUM;//0="A", 10="J", 11="Q", 12="K"
    printf("   ***   ***");
    printf("   %s %s\n", ctypes[type1], ntypes[num1]);
    printf("     <Player 2 �� ī��>\n");
    for (int i = 0; i < 3; i++)
    {
        type2 = player2[i] / NUM;
        num2 = player2[i] % NUM;
        printf("   %s %s", ctypes[type2], ntypes[num2]);
    }
}

int bet()
{
    printf("\n��� �ޱ� : 1     ���� ���� : 2     ����� �� ���� : 3\n");
    int b;
    scanf("%d", &b);

    if (b == 1)
    {
        printf("�� �徿 �� �޵��� �ϰڽ��ϴ�.\n\n");
        return 1;
    }
    else if (b == 2)
    {
        count1++;
        printf("��� ������ ����Ǿ����ϴ�.\n");
        printf("����� Player 1 ���� %d�� %d�� %d�� �Ͽ����ϴ�.\n\n", count2, count3, count1);
        exit(1);
        return 0;
    }
    else if (b == 3)
    {
        count1++;
        printf("Player 1 �Բ��� �¸��ϼ̽��ϴ�.\n\n");
        return 0;
    }
    return 0;
}

void show(int player1[], int player2[], int x)
{
    int type1, num1, type2, num2;
    printf("     <Player 1 �� ī��>\n");
    printf("   ***   ***");
    for (int i = 2; i <= x; i++)
    {
        type1 = player1[i] / NUM;
        num1 = player1[i] % NUM;
        printf("   %s %s", ctypes[type1], ntypes[num1]);
    }
    printf("\n");
    printf("     <Player 2 �� ī��>\n");
    for (int i = 0; i <= x; i++)
    {
        type2 = player2[i] / NUM;
        num2 = player2[i] % NUM;
        printf("   %s %s", ctypes[type2], ntypes[num2]);
    }

}

void showall(int player1[], int player2[])
{
    int i;
    int type1, num1, type2, num2;
    printf("\n��� ī�带 �����ϰڽ��ϴ�.\n\n");
    printf("   Player 1�� ī��:   ");
    for (i = 0; i < 7; i++)
    {
        type1 = player1[i] / NUM;
        num1 = player1[i] % NUM;
        printf("   %s %s", ctypes[type1], ntypes[num1]);
    }
    printf("\n");
    printf("   Player 2�� ī��:   ");
    for (i = 0; i < 7; i++)
    {
        type2 = player2[i] / NUM;
        num2 = player2[i] % NUM;
        printf("   %s %s", ctypes[type2], ntypes[num2]);
    }
    printf("\n");
}

int made1(int player1[])
{
    int check1 = 0;//�ߺ��� ���� ������ check�� �ϳ��� �����ϴµ� �� ���� check�� 0���� �ʱ�ȭ
    int i, j;
    int result1 = 0;
    for (i = 0; i < 6; i++)
    {
        for (j = i + 1; j < 7; j++)
            if (player1[i] % 13 == player1[j] % 13)
                check1++;
    }

    switch (check1)
    {
    case 1: result1 = 1;// �����
        break;
    case 2: result1 = 2;// �����
        break;
    case 3: result1 = 3;// Ʈ����
        break;
    case 4: result1 = 4;// Ǯ �Ͽ콺(�����+�����)
        break;
    case 6: result1 = 6;// �� ī��
        break;
    default:
        break;
    }
    int check2 = 0;// �÷����� üũ�ϱ� ���� check2������ 0���� �ʱ�ȭ
    for (int i = 0; i < 6; i++)
    {

        for (int j = i + 1; j < 7; j++)
            if (player1[i] / NUM == player1[j] / NUM)// NUM���� ���� ������ ����� ������ �Ǵ��Ѵ�
                check2++;
    }
    if (check2 == 10)
        result1 = 10;

    for (int k = 0; k < 3; k++)
        if ((player1[k] % 13) + 1 == player1[k+1] && (player1[k] % 13) + 2 == player1[k+2] && (player1[k] % 13) + 3 == player1[k+3] && (player1[k] % 13) + 4 == player1[k+4])
            result1 = 15;

    printf("Player 1�� ī��� : ");
    if (result1 == 1)// check1,check2�� ���ڸ� result1�� �־� case���� ��� ���
        printf("�����\n");
    else if (result1 == 2)
        printf("�����\n");
    else if (result1 == 3)
        printf("Ʈ����\n");
    else if (result1 == 4)
        printf("Ǯ �Ͽ콺\n");
    else if (result1 == 6)
        printf("��ī��\n");
    else if (result1 == 10)
        printf("�÷���\n");
    else if (result1 == 15)
        printf("��Ʈ����Ʈ\n");
    else if (result1 == 0)
        printf("ž\n");
    return result1;
}

int made2(int player2[])
{
    int check3 = 0;
    int i, j;
    int result2 = 0;
    for (i = 0; i < 6; i++)
    {
        for (j = i + 1; j < 7; j++)
            if (player2[i] % 13 == player2[j] % 13)
                check3++;
    }


    switch (check3)
    {
    case 1: result2 = 1;// �����
        break;
    case 2: result2 = 2;// �����
        break;
    case 3: result2 = 3;// Ʈ����
        break;
    case 4: result2 = 4;// Ǯ �Ͽ콺(�����+�����)
        break;
    case 6: result2 = 6;// �� ī��
        break;
    default:
        break;
    }
    int check4 = 0;
    for (int i = 0; i < 6; i++)
    {

        for (int j = i + 1; j < 7; j++)
            if (player2[i] / NUM == player2[j] / NUM)
                check4++;
    }
    if (check4 == 10)
        result2 = 10;
    printf("Player 2�� ī��� : ");
    if (result2 == 1)
        printf("�����\n");
    else if (result2 == 2)
        printf("�����\n");
    else if (result2 == 3)
        printf("Ʈ����\n");
    else if (result2 == 4)
        printf("Ǯ �Ͽ콺\n");
    else if (result2 == 6)
        printf("��ī��\n");
    else if (result2 == 10)
        printf("�÷���\n");
    else if (result2 == 0)
        printf("ž\n");
    return result2;
}

void swap(int* xp, int* yp)
{
    int temp;
    temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort1(int player1[])
{
    int n, m, minindex;//minindex�� �ּҰ��� ���� �ε���
    for (n = 0; n < 6; n++)
    {
        minindex = n;// n�� minindex�� �����س��� �� �����͵� �� ������ �� �� ���� ���ڰ� ������ swap
        for (m = n + 1; m < 7; m++)
            if (player1[minindex] > player1[m])
                minindex = m;
        swap(&player1[minindex], &player1[n]);
    }
}
void sort2(int player2[])
{
    int n, m, minindex;
    for (n = 0; n < 6; n++)
    {
        minindex = n;
        for (m = n + 1; m < 7; m++)
            if (player2[minindex] > player2[m])
                minindex = m;
        swap(&player2[minindex], &player2[n]);
    }
}

void winner(int result1, int result2)
{

    if (result1 > result2)
    {
        printf("\nPlayer 1�� �¸��Ͽ����ϴ�.\n\n");
        count1++;
    }
    else if (result1 == result2)
    {
        printf("\n\n���º� �Դϴ�.\n\n");
        count3++;
    }
    else
    {
        printf("\nPlayer 2�� �¸��Ͽ����ϴ�.\n\n");
        count2++;
    }
}