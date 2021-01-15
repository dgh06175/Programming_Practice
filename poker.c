#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#pragma warning(disable:4996)

#define MAX_CARD_TYPE 4
#define MAX_CARD_NUM 13

void PrintCard(int, int, int);
void sort_array(int*);

const char* ctypes[MAX_CARD_TYPE] = { "��","��","��","��" };
const char* ntypes[MAX_CARD_NUM] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };

/* ī�� ���� ����ϴ� �Լ� */
void PrintCard(int lcnt, int ct, int cn)
{//                n��°,    0~3,   0~12
    printf("%2d��° ī�� %s%s\n", lcnt, ctypes[ct], ntypes[cn]);
}

/* ī����� ���ڼ����� ������������ �����ϴ� �Լ� */
void sort_array(int* array)
{
    int tmp;
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 5; j++)
            if (array[i] > array[j])
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
}

void main()
{
    int num, type;
    int array[5] = { -1,-1,-1,-1,-1 };
    char y = 0;
    int x;
    srand((unsigned)time(NULL));
    printf("ī�带 5�� �̴� ���α׷�\n");
    printf("Input number of player [1-5]: ");
    scanf("%d", &x);
    while (getchar() != '\n'); // ���� scanf���� ���� �ְ� ���ʹ����ٰ� \n���ڰ� ���ۿ� �����־ �Ʒ����� ������ ���Ƿ� ���۸� �����
    while (1)
    {
        if (y != 'z') // y == 'z' �� ��� ���α׷� ����
        {
            for (int l = 0; l < x; l++) // �Է��� x����ŭ ī��5���� ����
            {
                /* ī�� 5���� �������� �̴� �κ� */
                for (int i = 0; i < 5; i++) // 5�� �̴°Ŵϱ� 5��
                {
                    while (1) //�̹� �п� �ߺ��� ī�尡 �ִ���, �� �ִ��� �˻�
                    {
                        int n = 0;
                        array[i] = rand() % (MAX_CARD_TYPE * MAX_CARD_NUM); // array[i]�� 0~51 ����
                        if (i == 0) break; //i=0 �̸� ù��° ī�忩�� �ߺ��˻�,pair�˻� �� �ʿ䰡 �����ϱ� ���� Ż��
                        for (int j = 0; j < i; j++)
                        {
                            if (array[i] == array[j])n++; //�̾Ҵ� ī��� �ߺ��̸� �ٽû̾ƾ� �ϹǷ� �ߺ��� ��� n++�ؼ� ���߿� n�� 0�� �ƴϸ� �ٽ� ����
                            // if (array[i] % MAX_CARD_NUM == array[j] % MAX_CARD_NUM && n == 0) m++; //�̾Ҵ� ī��� ���ڰ� ������ pair�ϱ� m++ (��, �ߺ��� �ƴ� ��쿡) // �̰� pair������ �˻��ϴ� ���α׷��϶��� �ڵ�
                        }
                        if (n == 0) break; //n=0 �̸� �ߺ��� �ϳ��� �����ٴ� ���̹Ƿ� �ٽ� ���� �ʱ� ���� ���� Ż��(array[i]�� Ȯ��)
                    }
                    type = array[i] / MAX_CARD_NUM; // array[]���� � �� / MAX_CARD_MUM �� �� ī���� ���ڰ� �ȴ�
                    num = array[i] % MAX_CARD_NUM; // array[]���� � �� % MAX_CARD_MUM �� �� ī���� ���ڰ� �ȴ�
                    PrintCard(i + 1, type, num); // Printcard()�� ���°�� ���� ī�尡 ���Դ��� ����
                    //         n��°, 0~3, 0~12
                }
                //int array[5] = { 9, 23, 37, 25, 21}; // �ڵ��� ����ϱ� ���� ���Ƿ� ī�� �Է�

                /* �����, �����, Ʈ����, ��ī�� �˻��ϴ� �κ� */
                int pair[5] = { 0, }; // ��� �˻翡 ����� �迭 pair�� ����, ��� 0���� �ʱ�ȭ

                for (int i = 0; i < 4; i++) // i��° ī��� �� ���� ī�带 �˻��ϴ°Ŷ� i = 4(5��° ī��)�� �� �ʿ�� ��� i < 4
                {
                    for (int j = i + 1; j < 5; j++) // i��° ī�� �� �� ����ī����� ���ϴϱ� j = i + 1�̰�, 5��° ī��(j=4) ����
                        if (array[i] % MAX_CARD_NUM == array[j] % MAX_CARD_NUM) // i��° ī��� j��° ī���� ���ڰ� ������ pair[i]++ �̷��� �ϸ�
                            pair[i]++;                                          // ù��° ī���� ���ڷ� �� ������ pair[0] == 1, Ʈ������ ������ pair[0] == 2; ��ī�尡 ������ pair[0] == 3;
                }                                                               // �ι�° ī��� ����° ī���� ���ڷ� �� ���ͼ� ������ pair�迭 = { 0, 1, 1, 0, 0};
                
                int pair_count[4] = { 0, }; // pair[]�ȿ� �ִ� ���ڸ� ���� ���� �迭 pair_count[i] �� pair[] �ȿ� �ִ� i�� �����̴� ex) pair[]�� { 2, 0, 1, 1, 0 }��� pair_count�� { 2, 2, 1, 0 }�� �� (0�� 2��, 1�� 2��, 2�� 1��, 3�� 0��)
                for (int i = 0; i < 5; i++)
                    for (int j = 0; j < 4; j++)
                        if (pair[i] == j) pair_count[j]++;

                /* ��Ʈ����Ʈ �˻��ϴ� �κ� */
                /* ��Ʈ����Ʈ�� ����� ��
                0  1  2  3  4
                1  2  3  4  5
                2  3  4  5  6
                3  4  5  6  7
                4  5  6  7  8
                5  6  7  8  9
                6  7  8  9  10
                7  8  9  10 11
                8  9  10 11 12
                0  9  10 11 12
                */
                int straight = 0;
                int mountain = 0;
                int count = 0;
                int sorted_array[5]; // ��Ʈ����Ʈ�� �˻��Ϸ��� �����ؾ���
                for (int i = 0; i < 5; i++)
                    sorted_array[i] = array[i] % MAX_CARD_NUM;
                sort_array(sorted_array); // sort_array�� 5���� ī�忡�� ���ڸ� �̾Ƽ� ������������ ������ �迭�� �� ex) { 0, 5, 5, 8, 10 }
            
                if (sorted_array[1] + 1 == sorted_array[2])
                    if (sorted_array[2] + 1 == sorted_array[3])
                        if (sorted_array[3] + 1 == sorted_array[4])
                        {
                            if (sorted_array[0] + 1 == sorted_array[1])
                                straight = 1;
                            else if (sorted_array[1] == 9 && sorted_array[0] == 0) // 9 10 11 12 0 �� ���
                                mountain = 1;
                        }

                if (pair_count[0] == 4 && pair_count[1] == 1) printf(" one pair\n");             // pair[](����) == { 0, 0, 1, 0, 0 } , pair_count[](����) == { 4, 1, 0, 0 }
                else if (pair_count[0] == 3 && pair_count[1] == 2) printf(" two pair\n");        // pair[](����) == { 0, 1, 1, 0, 0 } , pair_count[](����) == { 3, 2, 0, 0 }
                else if (pair_count[0] == 3 && pair_count[1] == 1) printf(" three of a Kind\n"); // pair[](����) == { 2, 1, 0, 0, 0 } , pair_count[](����) == { 3, 1, 1, 0 }
                else if (pair_count[0] == 2 && pair_count[1] == 2) printf(" full house\n");      // pair[](����) == { 2, 1, 1, 0, 0 } , pair_count[](����) == { 2, 2, 1, 0 }
                else if (pair_count[0] == 2 && pair_count[1] == 1) printf(" four of a Kind\n");  // pair[](����) == { 3, 2, 1, 0, 0 } , pair_count[](����) == { 2, 1, 1, 1 }
                else if (straight == 1) printf(" straight\n");
                else if (mountain == 1) printf(" mountain\n");
                
                printf("\n");
            }
            printf("���͸� ������ ���������� �Ѿ�� z�� ������ ������ �����մϴ�.\n");
            scanf("%c", &y);
        }
        else // y == 'z' �� ���
            break;
    }
}