#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<time.h>
#include<Windows.h>
#include<windows.h>
#include<conio.h>
#include<stdbool.h>

#define SIZE 54 
#define LEFT 75
#define RIGHT 77
#define TWO_SECOUND 2000 //2�� ������ 

typedef struct
{
    char name[15]; //�̸�
    char pw[7]; //��й�ȣ
    char gen[10]; //����
    char phone[20]; //�ڵ��� ��ȣ
}member;
member join[SIZE];

typedef struct
{
    char seat[4];
    char gen[10];
    int year;
    int mon;
    int day;
    int hour;
    int min;
}ssss;
ssss stime[SIZE];

typedef struct
{
    char rock[4]; //�繰��
    int year;
    int mon;
    int day;
    int hour;
    int min;
}rrrr;
rrrr rtime[SIZE];

typedef struct
{
    char phone[20];
    int smoney;
    int syear;
    int smon;
    int sday;
    int rmoney;
    int ryear;
    int rmon;
    int rday;
}srsr;
srsr sales[SIZE];

char Manager_name[15] = { "������" };
char Manager_pw[7] = { "5" };
char Manager_phone[20] = { "5" };
int count = 0; //ȸ�� ��ü ��
int scount = 0; //������� ī��Ʈ
int tmp; //���� � ȸ������ �α��ο��� i���� ������
int f_index = 0;
int e_index = 8;

void First(); //�ʱ� UI�Լ�
void goto_xy(int x, int y); //���� ��ġ �ű�� �Լ�
void gotoxy(int x, int y); //�Է� Ŀ�� �ű�� �Լ�
void Rect(int width, int height, int x, int y); //UI Ʋ�� �Ǵ� ����
void Rect1(int width, int height, int x, int y, char* msg);
void Rect2(int width, int height, int x, int y, char* msg);
void Rect3(int width, int height, int x, int y, char* msg); //�����ڿ� �ٷ� �ٴ� ���� 
void Rect4(int width, int height, int x, int y, char* msg);
void Rect5(int width, int height, int x, int y, char* msg);
void Rect6(int width, int hetihgt, int x, int y); //�繰��, �¼� UI(���� ����)
void Rect7(int width, int height, int x, int y, char* msg);
void Rect8(int width, int height, int x, int y, char* msg);
void Rect9(int width, int height, int x, int y, char* msg);
void Login(); //�α��� �Լ�
void Membership(); //ȸ������ �Լ�
void Membership1();
void Findpw();
void Alarm(char* msg); //�˸�
void Secound(); //�ι�°UI
void Seat(); //�¼� UI
void Seat1(); //�¼� ���� â���� �¼� ������ UI
void SeatUI();
void SeatCheck(); //�¼� ���� �޴�
void SeatTiket(); //�̿�� ���� �޴�
void RockUI(); //�޴�3���繰��
void RockCheck(); //�繰�� Ȯ��
void RockTiket(); //�繰�� �̿�� �޴�
void Rock(); //�繰�� UI (��� ���ִ��� ������ �Լ�)
void Tiket(); //�¼��̿�ǻ���� �繰�� �̿�ǻ����
void Choice();
void SeatTimeCheck(); //�¼��ܿ��ð��� ���Ҵ��� Ȯ���ϴ� �Լ�
void RockTimeCheck();
void MseatColor(); //���� �¼� ����ٲٱ�
void GseatColor(); //���� �¼� ����ٲٱ�
void RockColor(); //�繰�� ���� �ٲٱ�
void entryroom(); //�Խ�
void checkout(); //���
void ManagerUI(); //������ ���� UI
void Modify(); // ȸ�� ����Ʈ �����ִ� ��
void Modify1(); //ȸ������ �����ϴ� ��
void srsee(); //�¼� �繰�� Ȯ���ϴ� �Լ�
void ssee(); //�����ڰ� �¼� Ȯ���ϴ� �Լ�
void ssee1(); //������� ��� ����
void rsee(); //�����ڰ� �繰�� Ȯ��
void rsee1(); //�繰�Ի���ϰ��ִ� ȸ������ Ȯ��
void Managersales();
void ssearch();
void ssearch1();
void graph();
void file_member_read();
void file_seat_read();
void file_rock_read();
void file_member_write();
void file_sales_append();
void file_sales_read();

int main()
{
    system("mode con cols=142 lines=50");
    system("color E");
    file_member_read();
    file_seat_read();
    file_rock_read();
    file_sales_read();
    First();
}
void First()
{
    int input;
    Rect(60, 40, 40, 4);
    Rect1(58, 2, 41, 5, "���͵� ī��");
    Rect2(30, 2, 55, 19, "1. �α���");
    Rect2(30, 2, 55, 22, "2. ȸ�� ����");
    Rect2(30, 2, 55, 25, "3. ��й�ȣ ã��");
    Rect3(58, 2, 41, 7, "�޴� �Է� : ");
    gotoxy(78, 8);
    scanf("%d%*c", &input); //�޴� �Է�

    if (input == 1)
    {
        Login();
    }
    else if (input == 2)
    {
        Membership();
    }
    else if (input == 3)
    {
        Findpw();
    }
}
void Login()
{
    int menu, count_num = 0; //��ϵ� ȸ�� ��
    member input; //�α��� �Ҷ� �Է��ϴ� ����ü ����
    system("cls");
    Rect(60, 40, 40, 4);
    Rect1(58, 2, 41, 5, "1.ȸ�� �α��� 2.������ �α��� 3.�ڷΰ���");
    Rect3(58, 2, 41, 7, "�޴� �Է� : ");
    gotoxy(77, 8);
    scanf("%d", &menu);
    if (menu == 1)
    {
        gotoxy(47, 17);
        printf("��ȭ��ȣ [ ex) 010-xxxx-xxxx ]");
        gotoxy(46, 19);
        printf(" : ");
        scanf("%s", input.phone);
        getchar();
        gotoxy(47, 24);
        printf("��й�ȣ [ ex) 1234! (����4�� + !)]");
        gotoxy(46, 26);
        printf(" : ");
        scanf("%s", input.pw);
        goto_xy(0, 50);

        for (int j = 0; j < count; j++)
        {
            if ((strcmp(input.phone, join[j].phone) == 0) && (strcmp(input.pw, join[j].pw) == 0)) {
                tmp = j;
                count_num++;
                break;
            }
        }
        if (count_num == 1) {
            system("cls");
            Alarm("ȸ�� �α����� �Ϸ� �Ǿ����ϴ�.");
            RockTimeCheck();
            SeatTimeCheck();
            Secound();
        }
        else if (count_num == 0) {
            system("cls");
            Alarm("ȸ�� �α����� ���� �ϼ̽��ϴ�.");
            Login();
        }
    }
    else if (menu == 2)
    {
        gotoxy(47, 17);
        printf("��ȭ��ȣ [ ex) 010-xxxx-xxxx ]");
        gotoxy(46, 19);
        printf(" : ");
        scanf("%s", input.phone);
        gotoxy(47, 24);
        printf("��й�ȣ [ ex) 1234! (����4�� + !)]");
        gotoxy(46, 26);
        printf(" : ");
        scanf("%s", input.pw);
        goto_xy(0, 50);
        if ((strcmp(input.phone, Manager_phone) == 0) && (strcmp(input.pw, Manager_pw) == 0)) {
            Alarm("������ �α����� �Ϸ� �Ǿ����ϴ�.");
            ManagerUI();
        }
        else
        {
            Alarm("������ �α����� ���� �ϼ̽��ϴ�.");
            Login();
        }
    }
    else if (menu == 3)
    {
        First();
    }
    else
    {
        Login();
    }
}
void Membership()
{
    int i = 0; //��ϵ� ����� ��
    int j = 0, menu;

    system("cls");
    Rect(60, 40, 40, 4);
    Rect1(58, 2, 41, 5, "1.ȸ�� ����  2.�ڷΰ���");
    Rect3(58, 2, 41, 7, "�޴� �Է� : ");
    gotoxy(77, 8);
    scanf("%d%*c", &menu);
    if (menu == 1)
    {
        Membership1();
    }
    else if (menu == 2)
    {
        First();
    }
    else
    {
        Membership();
    }
}
void Membership1()
{
    member input;
    int a = 0;
    system("cls");
    Rect(60, 40, 40, 4);
    Rect1(58, 2, 41, 5, "ȸ�� ����");
    gotoxy(47, 14);
    printf("�̸� [ ex) ȫ�浿 ] ");
    gotoxy(46, 16);
    printf(" : ");
    scanf("%s", input.name);
    if (strlen(input.name) >= 7)
    {
        Alarm("���̵� ������ ���� �ʽ��ϴ�.");
        Membership1();
    }
    gotoxy(47, 20);
    printf("��й�ȣ [ ex) 1234! (����4�� + !)]");
    gotoxy(46, 22);
    printf(" : ");
    scanf("%s", input.pw);
    for (int i = 0; i < strlen(input.pw); i++)
    {
        if (strstr(input.pw, "!") != 0)
        {
            a++;
        }
    }
    if (a == 0)
    {
        Alarm("��й�ȣ ������ ���� �ʽ��ϴ�.");
        Membership1();
    }
    else if (strlen(input.pw) >= 6)
    {
        Alarm("��й�ȣ ������ ���� �ʽ��ϴ�.");
        Membership1();
    }
    gotoxy(47, 26);
    printf("���� [ ex) �� / �� ] ");
    gotoxy(46, 28);
    printf(" : ");
    scanf("%s", input.gen);
    gotoxy(47, 32);
    if ((strstr(input.gen, "����") != 0) || (strstr(input.gen, "��") != 0) || (strstr(input.gen, "����") != 0) || (strstr(input.gen, "��") != 0))
    {
    }
    else
    {
        Alarm("���� ������ ���� �ʽ��ϴ�.");
        Membership1();
    }
    if (strlen(input.gen) >= 6)
    {
        Alarm("���� ������ ���� �ʽ��ϴ�.");
        Membership1();
    }
    printf("��ȭ��ȣ [ ex) 010-xxxx-xxxx ]");
    gotoxy(46, 34);
    printf(" : ");
    scanf("%s", input.phone);
    for (int i = 0; i < strlen(input.phone); i++)
    {
        a = 0;
        if (strstr(input.phone, "-") != 0)
        {
            a++;
        }
    }
    if (a == 0)
    {
        Alarm("��ȭ��ȣ ������ ���� �ʽ��ϴ�.");
        Membership1();
    }
    else if (strlen(input.phone) >= 15)
    {
        Alarm("��ȭ��ȣ ������ ���� �ʽ��ϴ�.");
        Membership1();
    }
    system("cls");
    Alarm("ȸ�������� �Ϸ�Ǿ����ϴ�.");
    strcpy(join[count].name, input.name);
    strcpy(join[count].pw, input.pw);
    strcpy(join[count].phone, input.phone);
    strcpy(join[count].gen, input.gen);
    strcpy(stime[count].gen, input.gen);
    count++;

    FILE* fp = fopen("Member.txt", "a");
    fprintf(fp, "%s  ", input.name);
    fprintf(fp, "%s  ", input.pw);
    fprintf(fp, "%s  ", input.gen);
    fprintf(fp, "%s", input.phone);
    fprintf(fp, "\n");
    fclose(fp);

    FILE* fp1 = fopen("Seattime.txt", "a");
    fprintf(fp1, "%s  ", "0");
    fprintf(fp1, "%s ", input.gen);
    fprintf(fp1, "%d  ", 0);
    fprintf(fp1, "%d  ", 0);
    fprintf(fp1, "%d  ", 0);
    fprintf(fp1, "%d  ", 0);
    fprintf(fp1, "%d", 0);
    fprintf(fp1, "\n");
    fclose(fp1);

    FILE* fp2 = fopen("Rock.txt", "a");
    fprintf(fp2, "%s  ", "0");
    fprintf(fp2, "%d  ", 0);
    fprintf(fp2, "%d  ", 0);
    fprintf(fp2, "%d  ", 0);
    fprintf(fp2, "%d  ", 0);
    fprintf(fp2, "%d", 0);
    fprintf(fp2, "\n");
    fclose(fp2);
    First();
    goto_xy(0, 50);
}
void Findpw()
{
    int menu;
    member input;
    int i = 0;

    system("cls");
    Rect(60, 40, 40, 4);
    Rect1(58, 2, 41, 5, "1.��й�ȣ ã��  2.�ڷΰ���");
    Rect3(58, 2, 41, 7, "�޴� �Է� : ");
    gotoxy(77, 8);
    scanf("%d%*c", &menu);
    if (menu == 1)
    {
        gotoxy(47, 17);
        printf("�̸� [ ex) ȫ�浿 ] ");
        gotoxy(46, 19);
        printf(" : ");
        scanf("%s", input.name);
        gotoxy(47, 24);
        printf("��ȭ��ȣ [ ex) 010-xxxx-xxxx ]");
        gotoxy(46, 26);
        printf(" : ");
        scanf("%s", input.phone);
        goto_xy(0, 50);
        for (int j = 0; j < count; j++)
        {
            if (strcmp(input.name, join[j].name) == 0 && strcmp(input.phone, join[j].phone) == 0)
            {
                system("cls");
                Rect(60, 20, 40, 4);
                Rect1(58, 2, 41, 5, "��й�ȣ ã��");
                gotoxy(59, 14);
                printf("��й�ȣ : %s", join[j].pw);
                goto_xy(0, 50);
                Sleep(TWO_SECOUND);
                First();
            }
        }
    }
    else if (menu == 2)
    {
        First();
    }
    else
    {
        Findpw();
    }
}
void Alarm(char* msg)
{
    system("cls");
    Rect(60, 20, 40, 4);
    Rect1(58, 2, 41, 5, "���͵� ī��");
    gotoxy(57, 14);
    printf("%s", msg);
    Sleep(TWO_SECOUND);
    system("cls");
}
void Seat1()
{
    //��������
    Rect5(5, 2, 6, 11, "A1"), Rect5(5, 2, 13, 11, "A2"), Rect5(5, 2, 20, 11, "A3"), Rect5(5, 2, 27, 11, "A4"), Rect5(5, 2, 34, 11, "A5");
    Rect5(5, 2, 41, 11, "A6"), Rect5(5, 2, 48, 11, "A7"), Rect5(5, 2, 55, 11, "A8"), Rect5(5, 2, 62, 11, "A9");
    Rect5(5, 2, 6, 14, "B1"), Rect5(5, 2, 13, 14, "B2"), Rect5(5, 2, 20, 14, "B3"), Rect5(5, 2, 27, 14, "B4"), Rect5(5, 2, 34, 14, "B5");
    Rect5(5, 2, 41, 14, "B6"), Rect5(5, 2, 48, 14, "B7"), Rect5(5, 2, 55, 14, "B8"), Rect5(5, 2, 62, 14, "B9");
    Rect5(5, 2, 6, 17, "C1"), Rect5(5, 2, 13, 17, "C2"), Rect5(5, 2, 20, 17, "C3"), Rect5(5, 2, 27, 17, "C4"), Rect5(5, 2, 34, 17, "C5");
    Rect5(5, 2, 41, 17, "C6"), Rect5(5, 2, 48, 17, "C7"), Rect5(5, 2, 55, 17, "C8"), Rect5(5, 2, 62, 17, "C9");
    Rect2(31, 2, 23, 20, "���� ����");
    //��������
    Rect5(5, 2, 6, 24, "A1"), Rect5(5, 2, 13, 24, "A2"), Rect5(5, 2, 20, 24, "A3"), Rect5(5, 2, 27, 24, "A4"), Rect5(5, 2, 34, 24, "A5");
    Rect5(5, 2, 41, 24, "A6"), Rect5(5, 2, 48, 24, "A7"), Rect5(5, 2, 55, 24, "A8"), Rect5(5, 2, 62, 24, "A9");
    Rect5(5, 2, 6, 27, "B1"), Rect5(5, 2, 13, 27, "B2"), Rect5(5, 2, 20, 27, "B3"), Rect5(5, 2, 27, 27, "B4"), Rect5(5, 2, 34, 27, "B5");
    Rect5(5, 2, 41, 27, "B6"), Rect5(5, 2, 48, 27, "B7"), Rect5(5, 2, 55, 27, "B8"), Rect5(5, 2, 62, 27, "B9");
    Rect5(5, 2, 6, 30, "C1"), Rect5(5, 2, 13, 30, "C2"), Rect5(5, 2, 20, 30, "C3"), Rect5(5, 2, 27, 30, "C4"), Rect5(5, 2, 34, 30, "C5");
    Rect5(5, 2, 41, 30, "C6"), Rect5(5, 2, 48, 30, "C7"), Rect5(5, 2, 55, 30, "C8"), Rect5(5, 2, 62, 30, "C9");
    Rect2(31, 2, 23, 33, "���� ����");

}
void SeatUI()
{
    int menu;
    system("cls");
    Rect(60, 40, 40, 4);

    Rect1(58, 2, 41, 5, "1.�¼� ���� 2.�¼� �̿�� ���� 3.�ڷΰ���");
    Rect3(58, 2, 41, 7, "�޴� �Է� : ");
    gotoxy(77, 8);
    scanf("%d%*c", &menu);
    if (menu == 1)
    {
        SeatCheck();
    }
    else if (menu == 2)
    {
        SeatTiket();
    }
    else if (menu == 3)
    {
        Secound();
    }
}
void SeatCheck()
{
    char input_seat[4] = "0";
    int i = 0;
    if (stime[tmp].year == 0)
    {
        system("cls");
        Alarm("�¼� �̿���� �����ϼ���.");
        Secound();
    }
    else
    {
        system("cls");
        Rect(72, 30, 1, 8);
        Rect(70, 14, 2, 10);
        Rect6(70, 13, 2, 23);
        Seat1();
        Rect(60, 40, 75, 4);
        Rect1(58, 2, 76, 5, "�¼� ����");
    }


    gotoxy(80, 15);
    printf("%s ȸ��", join[tmp].gen);
    MseatColor();
    GseatColor();

    gotoxy(80, 20);
    printf("�̸� : %s", join[tmp].name);
    gotoxy(80, 25);
    printf("���� �ð� : %d�� %d�� %d�� %d�� %d�� ���� ��� ����.", stime[tmp].year, stime[tmp].mon, stime[tmp].day, stime[tmp].hour, stime[tmp].min);
    gotoxy(80, 30);
    if (strcmp(stime[tmp].seat, "0") == 0)
    {
        printf("�¼� ���� : ");
        gotoxy(93, 30);
        scanf("%s%*c", input_seat);
        for (int i = 0; i < count; i++)
        {
            if ((strcmp(join[tmp].gen, "����") == 0 || (strcmp(join[tmp].gen, "��") == 0)))
            {
                if (strcmp(input_seat, stime[i].seat) == 0 && (strcmp(stime[i].gen, "����") == 0 || (strcmp(stime[i].gen, "��") == 0)))
                {
                    Alarm("����ִ� �¼��� �ƴմϴ�.");
                    SeatCheck();
                }
            }
            else if ((strcmp(join[tmp].gen, "����") == 0 || (strcmp(join[tmp].gen, "��") == 0)))
            {
                if (strcmp(input_seat, stime[i].seat) == 0 && (strcmp(stime[i].gen, "����") == 0 || (strcmp(stime[i].gen, "��") == 0)))
                {
                    Alarm("����ִ� �¼��� �ƴմϴ�.");
                    SeatCheck();
                }
            }
        }
    }
    else if (strcmp(stime[tmp].seat, "0") != 0)
    {
        char answer;
        printf("%s �¼��� �����ϼ̽��ϴ�. �����Ͻðڽ��ϱ�?(y/n) : ", stime[tmp].seat);
        scanf("%c%*c", &answer);
        if ((answer == 'y') || (answer == 'Y'))
        {
            gotoxy(80, 35);
            printf("�¼� ���� : ");
            gotoxy(93, 35);
            scanf("%s%*c", input_seat);
            for (int i = 0; i < count; i++)
            {
                if ((strcmp(join[tmp].gen, "����") == 0 || (strcmp(join[tmp].gen, "��") == 0)))
                {
                    if (strcmp(input_seat, stime[i].seat) == 0 && (strcmp(stime[i].gen, "����") == 0 || (strcmp(stime[i].gen, "��") == 0)))
                    {
                        Alarm("����ִ� �¼��� �ƴմϴ�.");
                        SeatCheck();
                    }
                }
                else if ((strcmp(join[tmp].gen, "����") == 0 || (strcmp(join[tmp].gen, "��") == 0)))
                {
                    if (strcmp(input_seat, stime[i].seat) == 0 && (strcmp(stime[i].gen, "����") == 0 || (strcmp(stime[i].gen, "��") == 0)))
                    {
                        Alarm("����ִ� �¼��� �ƴմϴ�.");
                        SeatCheck();
                    }
                }
            }
        }
        else if ((answer == 'n') || (answer == 'N'))
        {
            Choice();
        }
    }
    if ((strcmp(input_seat, "A1") == 0) || (strcmp(input_seat, "A2") == 0) || (strcmp(input_seat, "A3") == 0) || (strcmp(input_seat, "A4") == 0) || (strcmp(input_seat, "A5") == 0) || (strcmp(input_seat, "A6") == 0) || (strcmp(input_seat, "A7") == 0) || (strcmp(input_seat, "A8") == 0) || (strcmp(input_seat, "A9") == 0)
        || (strcmp(input_seat, "B1") == 0) || (strcmp(input_seat, "B2") == 0) || (strcmp(input_seat, "B3") == 0) || (strcmp(input_seat, "B4") == 0) || (strcmp(input_seat, "B5") == 0) || (strcmp(input_seat, "B6") == 0) || (strcmp(input_seat, "B7") == 0) || (strcmp(input_seat, "B8") == 0) || (strcmp(input_seat, "B9") == 0)
        || (strcmp(input_seat, "C1") == 0) || (strcmp(input_seat, "C2") == 0) || (strcmp(input_seat, "C3") == 0) || (strcmp(input_seat, "C4") == 0) || (strcmp(input_seat, "C5") == 0) || (strcmp(input_seat, "C6") == 0) || (strcmp(input_seat, "C7") == 0) || (strcmp(input_seat, "C8") == 0) || (strcmp(input_seat, "C9") == 0)
        )
    {
        if ((strcmp(input_seat, "A1") == 0)) strcpy(stime[tmp].seat, "A1");
        else if ((strcmp(input_seat, "A2") == 0))strcpy(stime[tmp].seat, "A2");
        else if ((strcmp(input_seat, "A3") == 0))strcpy(stime[tmp].seat, "A3");
        else if ((strcmp(input_seat, "A4") == 0))strcpy(stime[tmp].seat, "A4");
        else if ((strcmp(input_seat, "A5") == 0))strcpy(stime[tmp].seat, "A5");
        else if ((strcmp(input_seat, "A6") == 0))strcpy(stime[tmp].seat, "A6");
        else if ((strcmp(input_seat, "A7") == 0))strcpy(stime[tmp].seat, "A7");
        else if ((strcmp(input_seat, "A8") == 0))strcpy(stime[tmp].seat, "A8");
        else if ((strcmp(input_seat, "A9") == 0))strcpy(stime[tmp].seat, "A9");
        else if ((strcmp(input_seat, "B1") == 0))strcpy(stime[tmp].seat, "B1");
        else if ((strcmp(input_seat, "B2") == 0))strcpy(stime[tmp].seat, "B2");
        else if ((strcmp(input_seat, "B3") == 0))strcpy(stime[tmp].seat, "B3");
        else if ((strcmp(input_seat, "B4") == 0))strcpy(stime[tmp].seat, "B4");
        else if ((strcmp(input_seat, "B5") == 0))strcpy(stime[tmp].seat, "B5");
        else if ((strcmp(input_seat, "B6") == 0))strcpy(stime[tmp].seat, "B6");
        else if ((strcmp(input_seat, "B7") == 0))strcpy(stime[tmp].seat, "B7");
        else if ((strcmp(input_seat, "B8") == 0))strcpy(stime[tmp].seat, "B8");
        else if ((strcmp(input_seat, "B9") == 0))strcpy(stime[tmp].seat, "B9");
        else if ((strcmp(input_seat, "C1") == 0))strcpy(stime[tmp].seat, "C1");
        else if ((strcmp(input_seat, "C2") == 0))strcpy(stime[tmp].seat, "C2");
        else if ((strcmp(input_seat, "C3") == 0))strcpy(stime[tmp].seat, "C3");
        else if ((strcmp(input_seat, "C4") == 0))strcpy(stime[tmp].seat, "C4");
        else if ((strcmp(input_seat, "C5") == 0))strcpy(stime[tmp].seat, "C5");
        else if ((strcmp(input_seat, "C6") == 0))strcpy(stime[tmp].seat, "C6");
        else if ((strcmp(input_seat, "C7") == 0))strcpy(stime[tmp].seat, "C7");
        else if ((strcmp(input_seat, "C8") == 0))strcpy(stime[tmp].seat, "C8");
        else if ((strcmp(input_seat, "C9") == 0))strcpy(stime[tmp].seat, "C9");
        Alarm("�¼� ������ �Ϸ�Ǿ����ϴ�.");
        entryroom();
    }
    else
    {
        SeatCheck();
    }
    goto_xy(0, 50);
}
void SeatTiket()
{
    //���� �ð���ºκ�
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    //�ð� ���� �б�
    int i = 0;
    int menu;
    char input[10];
    int day;
    system("cls");
    Rect(60, 40, 40, 4);

    Rect1(58, 2, 41, 5, "�¼� �̿�� ����");
    gotoxy(77, 8);
    gotoxy(43, 13);
    printf("ȸ�� �̸� : %s", join[tmp].name);
    gotoxy(43, 16);
    if (stime[tmp].year == 0)
    {
        printf("�ܿ��ð��� �����ϴ�. �¼� �̿���� �������ּ���.");
    }
    else {
        printf("%d�� %d�� %d�� %d�� %d�� ���� ��� �����մϴ�.", stime[tmp].year, stime[tmp].mon, stime[tmp].day, stime[tmp].hour, stime[tmp].min);
    }
    gotoxy(43, 19);
    printf("�̿�� �Է� : ");
    gotoxy(43, 24);
    printf("�Ⱓ��");
    Rect5(15, 2, 43, 25, "7D 40000��"), Rect5(15, 2, 58, 25, "15D 80000��"), Rect5(15, 2, 73, 25, "30D 150000��");
    gotoxy(43, 34);
    printf("�ð���");
    Rect5(15, 2, 43, 35, "6H 2000��"), Rect5(15, 2, 58, 35, "12H 8000��"), Rect5(15, 2, 73, 35, "24H 10000��");
    gotoxy(57, 19);
    scanf("%s", input);

    if ((strcmp(input, "7D") == 0) || strcmp(input, "7d") == 0)
    {
        if (stime[tmp].year == 0)
        {
            stime[tmp].year = tm.tm_year + 1900;
            stime[tmp].mon = tm.tm_mon + 1;
            stime[tmp].day = tm.tm_mday + 7;
            stime[tmp].hour = tm.tm_hour;
            stime[tmp].min = tm.tm_min;

            sales[scount].smoney = 40000;
            sales[scount].syear = tm.tm_year + 1900;
            sales[scount].smon = tm.tm_mon + 1;
            sales[scount].sday = tm.tm_mday;
        }
        else
        {

            stime[tmp].day += 7;
            sales[scount].smoney = 40000;
            sales[scount].syear = tm.tm_year + 1900;
            sales[scount].smon = tm.tm_mon + 1;
            sales[scount].sday = tm.tm_mday;

        }
        if (stime[tmp].mon == 1 || stime[tmp].mon == 3 || stime[tmp].mon == 5 || stime[tmp].mon == 7 || stime[tmp].mon == 8 || stime[tmp].mon == 10 || stime[tmp].mon == 12)
        {
            if (stime[tmp].day > 31)
            {
                stime[tmp].day -= 31;
                stime[tmp].mon += 1;
            }
            else if (stime[tmp].mon == 12 && stime[tmp].day > 31)
            {
                stime[tmp].mon = 1;
                stime[tmp].day -= 31;
                stime[tmp].year += 1;
            }
        }
        else if (stime[tmp].mon == 4 || stime[tmp].mon == 6 || stime[tmp].mon == 9 || stime[tmp].mon == 11)
        {
            if (stime[tmp].day > 30)
            {
                stime[tmp].day -= 30;
                stime[tmp].mon += 1;
            }
        }
        else
        {
            if (stime[tmp].day > 28)
            {
                stime[tmp].day -= 28;
                stime[tmp].mon += 1;
            }
        }
        if (stime[tmp].mon == 13)
        {
            stime[tmp].mon = 1;
            stime[tmp].year += 1;
        }
        system("cls");
        Alarm("�̿�� ���Ű� �Ϸ�Ǿ����ϴ�.");
    }
    else if ((strcmp(input, "15D") == 0) || strcmp(input, "15d") == 0)
    {
        if (stime[tmp].year == 0)
        {
            stime[tmp].year = tm.tm_year + 1900;
            stime[tmp].mon = tm.tm_mon + 1;
            stime[tmp].day = tm.tm_mday + 15;
            stime[tmp].hour = tm.tm_hour;
            stime[tmp].min = tm.tm_min;

            sales[scount].smoney = 80000;
            sales[scount].syear = tm.tm_year + 1900;
            sales[scount].smon = tm.tm_mon + 1;
            sales[scount].sday = tm.tm_mday;
        }
        else
        {
            stime[tmp].day += 15;
            sales[scount].smoney = 80000;
            sales[scount].syear = tm.tm_year + 1900;
            sales[scount].smon = tm.tm_mon + 1;
            sales[scount].sday = tm.tm_mday;
        }
        if (stime[tmp].mon == 1 || stime[tmp].mon == 3 || stime[tmp].mon == 5 || stime[tmp].mon == 7 || stime[tmp].mon == 8 || stime[tmp].mon == 10 || stime[tmp].mon == 12)
        {
            if (stime[tmp].day > 31)
            {
                stime[tmp].day -= 31;
                stime[tmp].mon += 1;
            }
            else if (stime[tmp].mon == 12 && stime[tmp].day > 31)
            {
                stime[tmp].mon = 1;
                stime[tmp].day -= 31;
                stime[tmp].year += 1;
            }
        }
        else if (stime[tmp].mon == 4 || stime[tmp].mon == 6 || stime[tmp].mon == 9 || stime[tmp].mon == 11)
        {
            if (stime[tmp].day > 30)
            {
                stime[tmp].day -= 30;
                stime[tmp].mon += 1;
            }
        }
        else
        {
            if (stime[tmp].day > 28)
            {
                stime[tmp].day -= 28;
                stime[tmp].mon += 1;
            }
        }
        if (stime[tmp].mon == 13)
        {
            stime[tmp].mon = 1;
            stime[tmp].year += 1;
        }
        system("cls");
        Alarm("�̿�� ���Ű� �Ϸ�Ǿ����ϴ�.");
    }
    else if ((strcmp(input, "30D") == 0) || strcmp(input, "30d") == 0)
    {
        if (stime[tmp].year == 0)
        {
            stime[tmp].year = tm.tm_year + 1900;
            stime[tmp].mon = tm.tm_mon + 1;
            stime[tmp].day = tm.tm_mday + 30;
            stime[tmp].hour = tm.tm_hour;
            stime[tmp].min = tm.tm_min;

            sales[scount].smoney = 150000;
            sales[scount].syear = tm.tm_year + 1900;
            sales[scount].smon = tm.tm_mon + 1;
            sales[scount].sday = tm.tm_mday;
        }
        else
        {
            stime[tmp].day += 30;
            sales[scount].smoney = 150000;
            sales[scount].syear = tm.tm_year + 1900;
            sales[scount].smon = tm.tm_mon + 1;
            sales[scount].sday = tm.tm_mday;
        }
        if (stime[tmp].mon == 1 || stime[tmp].mon == 3 || stime[tmp].mon == 5 || stime[tmp].mon == 7 || stime[tmp].mon == 8 || stime[tmp].mon == 10 || stime[tmp].mon == 12)
        {
            if (stime[tmp].day > 31)
            {
                stime[tmp].day -= 31;
                stime[tmp].mon += 1;
            }
            else if (stime[tmp].mon == 12 && stime[tmp].day > 31)
            {
                stime[tmp].mon = 1;
                stime[tmp].day -= 31;
                stime[tmp].year += 1;
            }
        }
        else if (stime[tmp].mon == 4 || stime[tmp].mon == 6 || stime[tmp].mon == 9 || stime[tmp].mon == 11)
        {
            if (stime[tmp].day > 30)
            {
                stime[tmp].day -= 30;
                stime[tmp].mon += 1;
            }
        }
        else
        {
            if (stime[tmp].day > 28)
            {
                stime[tmp].day -= 28;
                stime[tmp].mon += 1;
            }
        }
        if (stime[tmp].mon == 13)
        {
            stime[tmp].mon = 1;
            stime[tmp].year += 1;
        }
        system("cls");
        Alarm("�̿�� ���Ű� �Ϸ�Ǿ����ϴ�.");
    }
    else if ((strcmp(input, "6H") == 0) || strcmp(input, "6h") == 0)
    {
        if (stime[tmp].year == 0)
        {
            stime[tmp].year = tm.tm_year + 1900;
            stime[tmp].mon = tm.tm_mon + 1;
            stime[tmp].day = tm.tm_mday;
            stime[tmp].hour = tm.tm_hour + 6;
            stime[tmp].min = tm.tm_min;

            sales[scount].smoney = 2000;
            sales[scount].syear = tm.tm_year + 1900;
            sales[scount].smon = tm.tm_mon + 1;
            sales[scount].sday = tm.tm_mday;
        }
        else
        {
            stime[tmp].hour += 6;
            sales[scount].smoney = 2000;
            sales[scount].syear = tm.tm_year + 1900;
            sales[scount].smon = tm.tm_mon + 1;
            sales[scount].sday = tm.tm_mday;
        }
        if (stime[tmp].hour >= 24)
        {
            stime[tmp].hour -= 24;
            stime[tmp].day += 1;
        }
        if (stime[tmp].mon == 1 || stime[tmp].mon == 3 || stime[tmp].mon == 5 || stime[tmp].mon == 7 || stime[tmp].mon == 8 || stime[tmp].mon == 10 || stime[tmp].mon == 12)
        {
            if (stime[tmp].day > 31)
            {
                stime[tmp].day -= 31;
                stime[tmp].mon += 1;
            }
            else if (stime[tmp].mon == 12 && stime[tmp].day > 31)
            {
                stime[tmp].mon = 1;
                stime[tmp].day -= 31;
                stime[tmp].year += 1;
            }
        }
        else if (stime[tmp].mon == 4 || stime[tmp].mon == 6 || stime[tmp].mon == 9 || stime[tmp].mon == 11)
        {
            if (stime[tmp].day > 30)
            {
                stime[tmp].day -= 30;
                stime[tmp].mon += 1;
            }
        }
        else
        {
            if (stime[tmp].day > 28)
            {
                stime[tmp].day -= 28;
                stime[tmp].mon += 1;
            }
        }
        if (stime[tmp].mon == 13)
        {
            stime[tmp].mon = 1;
            stime[tmp].year += 1;
        }
        system("cls");
        Alarm("�̿�� ���Ű� �Ϸ�Ǿ����ϴ�.");
    }
    else if ((strcmp(input, "12H") == 0) || strcmp(input, "12h") == 0)
    {
        if (stime[tmp].year == 0)
        {
            stime[tmp].year = tm.tm_year + 1900;
            stime[tmp].mon = tm.tm_mon + 1;
            stime[tmp].day = tm.tm_mday;
            stime[tmp].hour = tm.tm_hour + 12;
            stime[tmp].min = tm.tm_min;

            sales[scount].smoney = 8000;
            sales[scount].syear = tm.tm_year + 1900;
            sales[scount].smon = tm.tm_mon + 1;
            sales[scount].sday = tm.tm_mday;
        }
        else
        {
            stime[tmp].hour += 12;
            sales[scount].smoney = 8000;
            sales[scount].syear = tm.tm_year + 1900;
            sales[scount].smon = tm.tm_mon + 1;
            sales[scount].sday = tm.tm_mday;
        }
        if (stime[tmp].hour >= 24)
        {
            stime[tmp].hour -= 24;
            stime[tmp].day += 1;
        }
        if (stime[tmp].mon == 1 || stime[tmp].mon == 3 || stime[tmp].mon == 5 || stime[tmp].mon == 7 || stime[tmp].mon == 8 || stime[tmp].mon == 10 || stime[tmp].mon == 12)
        {
            if (stime[tmp].day > 31)
            {
                stime[tmp].day -= 31;
                stime[tmp].mon += 1;
            }
            else if (stime[tmp].mon == 12 && stime[tmp].day > 31)
            {
                stime[tmp].mon = 1;
                stime[tmp].day -= 31;
                stime[tmp].year += 1;
            }
        }
        else if (stime[tmp].mon == 4 || stime[tmp].mon == 6 || stime[tmp].mon == 9 || stime[tmp].mon == 11)
        {
            if (stime[tmp].day > 30)
            {
                stime[tmp].day -= 30;
                stime[tmp].mon += 1;
            }
        }
        else
        {
            if (stime[tmp].day > 28)
            {
                stime[tmp].day -= 28;
                stime[tmp].mon += 1;
            }
        }
        if (stime[tmp].mon == 13)
        {
            stime[tmp].mon = 1;
            stime[tmp].year += 1;
        }
        system("cls");
        Alarm("�̿�� ���Ű� �Ϸ�Ǿ����ϴ�.");
    }
    else if ((strcmp(input, "24H") == 0) || strcmp(input, "24h") == 0)
    {
        if (stime[tmp].year == 0)
        {
            stime[tmp].year = tm.tm_year + 1900;
            stime[tmp].mon = tm.tm_mon + 1;
            stime[tmp].day = tm.tm_mday;
            stime[tmp].hour = tm.tm_hour + 24;
            stime[tmp].min = tm.tm_min;

            sales[scount].smoney = 10000;
            sales[scount].syear = tm.tm_year + 1900;
            sales[scount].smon = tm.tm_mon + 1;
            sales[scount].sday = tm.tm_mday;
        }
        else
        {
            stime[tmp].hour += 24;
            sales[scount].smoney = 10000;
            sales[scount].syear = tm.tm_year + 1900;
            sales[scount].smon = tm.tm_mon + 1;
            sales[scount].sday = tm.tm_mday;
        }
        if (stime[tmp].hour >= 24)
        {
            stime[tmp].hour -= 24;
            stime[tmp].day += 1;
        }
        if (stime[tmp].mon == 1 || stime[tmp].mon == 3 || stime[tmp].mon == 5 || stime[tmp].mon == 7 || stime[tmp].mon == 8 || stime[tmp].mon == 10 || stime[tmp].mon == 12)
        {
            if (stime[tmp].day > 31)
            {
                stime[tmp].day -= 31;
                stime[tmp].mon += 1;
            }
            else if (stime[tmp].mon == 12 && stime[tmp].day > 31)
            {
                stime[tmp].mon = 1;
                stime[tmp].day -= 31;
                stime[tmp].year += 1;
            }
        }
        else if (stime[tmp].mon == 4 || stime[tmp].mon == 6 || stime[tmp].mon == 9 || stime[tmp].mon == 11)
        {
            if (stime[tmp].day > 30)
            {
                stime[tmp].day -= 30;
                stime[tmp].mon += 1;
            }
        }
        else
        {
            if (stime[tmp].day > 28)
            {
                stime[tmp].day -= 28;
                stime[tmp].mon += 1;
            }
        }
        if (stime[tmp].mon == 13)
        {
            stime[tmp].mon = 1;
            stime[tmp].year += 1;
        }
        system("cls");
        Alarm("�̿�� ���Ű� �Ϸ�Ǿ����ϴ�.");
    }

    FILE* fp1 = fopen("Seattime.txt", "w");
    for (int i = 0; i < count; i++)
    {
        fprintf(fp1, "%s  ", stime[i].seat);
        fprintf(fp1, "%s  ", stime[i].gen);
        fprintf(fp1, "%d  ", stime[i].year);
        fprintf(fp1, "%d  ", stime[i].mon);
        fprintf(fp1, "%d  ", stime[i].day);
        fprintf(fp1, "%d  ", stime[i].hour);
        fprintf(fp1, "%d", stime[i].min);
        fprintf(fp1, "\n");
    }
    fclose(fp1);
    file_sales_append();
    Secound();
}
void RockUI()
{
    int menu;
    system("cls");
    Rect(60, 40, 40, 4);

    Rect1(58, 2, 41, 5, "1.�繰�� ���� 2.�繰�� �̿�� ���� 3.����");
    Rect3(58, 2, 41, 7, "�޴� �Է� : ");
    gotoxy(77, 8);
    scanf("%d%*c", &menu);

    if (menu == 1)
    {
        system("cls");
        RockCheck();
    }
    else if (menu == 2)
    {
        RockTiket();
    }
    else if (menu == 3)
    {
        Secound();
    }
}
void Rock()
{
    Rect5(5, 2, 6, 11, "A1"), Rect5(5, 2, 13, 11, "A2"), Rect5(5, 2, 20, 11, "A3"), Rect5(5, 2, 27, 11, "A4"), Rect5(5, 2, 34, 11, "A5");
    Rect5(5, 2, 41, 11, "A6"), Rect5(5, 2, 48, 11, "A7"), Rect5(5, 2, 55, 11, "A8"), Rect5(5, 2, 62, 11, "A9");
    Rect5(5, 2, 6, 14, "B1"), Rect5(5, 2, 13, 14, "B2"), Rect5(5, 2, 20, 14, "B3"), Rect5(5, 2, 27, 14, "B4"), Rect5(5, 2, 34, 14, "B5");
    Rect5(5, 2, 41, 14, "B6"), Rect5(5, 2, 48, 14, "B7"), Rect5(5, 2, 55, 14, "B8"), Rect5(5, 2, 62, 14, "B9");
    Rect5(5, 2, 6, 17, "C1"), Rect5(5, 2, 13, 17, "C2"), Rect5(5, 2, 20, 17, "C3"), Rect5(5, 2, 27, 17, "C4"), Rect5(5, 2, 34, 17, "C5");
    Rect5(5, 2, 41, 17, "C6"), Rect5(5, 2, 48, 17, "C7"), Rect5(5, 2, 55, 17, "C8"), Rect5(5, 2, 62, 17, "C9");
    Rect2(31, 2, 23, 20, "�繰�� 1");

    Rect5(5, 2, 6, 24, "D1"), Rect5(5, 2, 13, 24, "D2"), Rect5(5, 2, 20, 24, "D3"), Rect5(5, 2, 27, 24, "D4"), Rect5(5, 2, 34, 24, "D5");
    Rect5(5, 2, 41, 24, "D6"), Rect5(5, 2, 48, 24, "D7"), Rect5(5, 2, 55, 24, "D8"), Rect5(5, 2, 62, 24, "D9");
    Rect5(5, 2, 6, 27, "E1"), Rect5(5, 2, 13, 27, "E2"), Rect5(5, 2, 20, 27, "E3"), Rect5(5, 2, 27, 27, "E4"), Rect5(5, 2, 34, 27, "E5");
    Rect5(5, 2, 41, 27, "E6"), Rect5(5, 2, 48, 27, "E7"), Rect5(5, 2, 55, 27, "E8"), Rect5(5, 2, 62, 27, "E9");
    Rect5(5, 2, 6, 30, "F1"), Rect5(5, 2, 13, 30, "F2"), Rect5(5, 2, 20, 30, "F3"), Rect5(5, 2, 27, 30, "F4"), Rect5(5, 2, 34, 30, "F5");
    Rect5(5, 2, 41, 30, "F6"), Rect5(5, 2, 48, 30, "F7"), Rect5(5, 2, 55, 30, "F8"), Rect5(5, 2, 62, 30, "F9");
    Rect2(31, 2, 23, 33, "�繰�� 2");
}
void RockCheck()
{
    char input_rock[4] = "0";
    int i = 0;
    if (rtime[tmp].year == 0)
    {
        system("cls");
        Alarm("�繰�� �̿���� �����ϼ���.");
        Secound();
    }
    else
    {
        system("cls");
        Rect(72, 30, 1, 8);
        Rect(70, 14, 2, 10);
        Rect6(70, 13, 2, 23);
        Rock();
        Rect(60, 40, 75, 4);
        Rect1(58, 2, 76, 5, "�繰�� ����");

        if (strcmp(join[tmp].gen, "����") == 0 || strcmp(join[tmp].gen, "��") == 0)
        {
            gotoxy(80, 15);
            printf("���� ȸ��");
        }
        else if (strcmp(join[tmp].gen, "����") == 0 || strcmp(join[tmp].gen, "��") == 0)
        {
            gotoxy(80, 15);
            printf("���� ȸ��");
        }
        RockColor();
        gotoxy(80, 20);
        printf("�̸� : %s", join[tmp].name);
        gotoxy(80, 25);
        printf("���� �ð� : %d�� %d�� %d�� %d�� %d�� ���� ��� ����", rtime[tmp].year, rtime[tmp].mon, rtime[tmp].day, rtime[tmp].hour, rtime[tmp].min);
        gotoxy(80, 30);
        if (strcmp(rtime[tmp].rock, "0") != 0)
        {
            char answer;
            printf("%s �繰���� �����ϼ̽��ϴ�. �����Ͻðڽ��ϱ�?(y/n) : ", rtime[tmp].rock);
            scanf("%c%*c", &answer);
            if ((answer == 'y') || (answer == 'Y'))
            {
                gotoxy(80, 35);
                printf("�繰�� ���� : ");
                gotoxy(94, 35);
                scanf("%s", input_rock);
                for (i = 0; i < SIZE; i++)
                {
                    if (strcmp(input_rock, rtime[i].rock) == 0)
                    {
                        Alarm("����ִ� �繰���� �ƴմϴ�.");
                        RockCheck();
                    }
                }
            }
            else if ((answer == 'n') || (answer == 'N'))
            {
                Choice();
            }

        }
        else if (strcmp(input_rock, "0") == 0)
        {
            printf("�繰�� ���� : ");
            gotoxy(94, 30);
            scanf("%s", input_rock);
            for (i = 0; i < SIZE; i++)
            {
                if (strcmp(input_rock, rtime[i].rock) == 0)
                {
                    Alarm("����ִ� �繰���� �ƴմϴ�.");
                    RockCheck();
                }
            }
        }
        if ((strcmp(input_rock, "A1") == 0) || (strcmp(input_rock, "A2") == 0) || (strcmp(input_rock, "A3") == 0) || (strcmp(input_rock, "A4") == 0) || (strcmp(input_rock, "A5") == 0) || (strcmp(input_rock, "A6") == 0) || (strcmp(input_rock, "A7") == 0) || (strcmp(input_rock, "A8") == 0) || (strcmp(input_rock, "A9") == 0)
            || (strcmp(input_rock, "B1") == 0) || (strcmp(input_rock, "B2") == 0) || (strcmp(input_rock, "B3") == 0) || (strcmp(input_rock, "B4") == 0) || (strcmp(input_rock, "B5") == 0) || (strcmp(input_rock, "B6") == 0) || (strcmp(input_rock, "B7") == 0) || (strcmp(input_rock, "B8") == 0) || (strcmp(input_rock, "B9") == 0)
            || (strcmp(input_rock, "C1") == 0) || (strcmp(input_rock, "C2") == 0) || (strcmp(input_rock, "C3") == 0) || (strcmp(input_rock, "C4") == 0) || (strcmp(input_rock, "C5") == 0) || (strcmp(input_rock, "C6") == 0) || (strcmp(input_rock, "C7") == 0) || (strcmp(input_rock, "C8") == 0) || (strcmp(input_rock, "C9") == 0)
            || (strcmp(input_rock, "D1") == 0) || (strcmp(input_rock, "D2") == 0) || (strcmp(input_rock, "D3") == 0) || (strcmp(input_rock, "D4") == 0) || (strcmp(input_rock, "D5") == 0) || (strcmp(input_rock, "D6") == 0) || (strcmp(input_rock, "D7") == 0) || (strcmp(input_rock, "D8") == 0) || (strcmp(input_rock, "D9") == 0)
            || (strcmp(input_rock, "E1") == 0) || (strcmp(input_rock, "E2") == 0) || (strcmp(input_rock, "E3") == 0) || (strcmp(input_rock, "E4") == 0) || (strcmp(input_rock, "E5") == 0) || (strcmp(input_rock, "E6") == 0) || (strcmp(input_rock, "E7") == 0) || (strcmp(input_rock, "E8") == 0) || (strcmp(input_rock, "E9") == 0)
            || (strcmp(input_rock, "F1") == 0) || (strcmp(input_rock, "F2") == 0) || (strcmp(input_rock, "F3") == 0) || (strcmp(input_rock, "F4") == 0) || (strcmp(input_rock, "F5") == 0) || (strcmp(input_rock, "F6") == 0) || (strcmp(input_rock, "F7") == 0) || (strcmp(input_rock, "F8") == 0) || (strcmp(input_rock, "F9") == 0)
            )
        {
            if ((strcmp(input_rock, "A1") == 0)) strcpy(rtime[tmp].rock, "A1");
            else if ((strcmp(input_rock, "A2") == 0))strcpy(rtime[tmp].rock, "A2");
            else if ((strcmp(input_rock, "A3") == 0))strcpy(rtime[tmp].rock, "A3");
            else if ((strcmp(input_rock, "A4") == 0))strcpy(rtime[tmp].rock, "A4");
            else if ((strcmp(input_rock, "A5") == 0))strcpy(rtime[tmp].rock, "A5");
            else if ((strcmp(input_rock, "A6") == 0))strcpy(rtime[tmp].rock, "A6");
            else if ((strcmp(input_rock, "A7") == 0))strcpy(rtime[tmp].rock, "A7");
            else if ((strcmp(input_rock, "A8") == 0))strcpy(rtime[tmp].rock, "A8");
            else if ((strcmp(input_rock, "A9") == 0))strcpy(rtime[tmp].rock, "A9");
            else if ((strcmp(input_rock, "B1") == 0))strcpy(rtime[tmp].rock, "B1");
            else if ((strcmp(input_rock, "B2") == 0))strcpy(rtime[tmp].rock, "B2");
            else if ((strcmp(input_rock, "B3") == 0))strcpy(rtime[tmp].rock, "B3");
            else if ((strcmp(input_rock, "B4") == 0))strcpy(rtime[tmp].rock, "B4");
            else if ((strcmp(input_rock, "B5") == 0))strcpy(rtime[tmp].rock, "B5");
            else if ((strcmp(input_rock, "B6") == 0))strcpy(rtime[tmp].rock, "B6");
            else if ((strcmp(input_rock, "B7") == 0))strcpy(rtime[tmp].rock, "B7");
            else if ((strcmp(input_rock, "B8") == 0))strcpy(rtime[tmp].rock, "B8");
            else if ((strcmp(input_rock, "B9") == 0))strcpy(rtime[tmp].rock, "B9");
            else if ((strcmp(input_rock, "C1") == 0))strcpy(rtime[tmp].rock, "C1");
            else if ((strcmp(input_rock, "C2") == 0))strcpy(rtime[tmp].rock, "C2");
            else if ((strcmp(input_rock, "C3") == 0))strcpy(rtime[tmp].rock, "C3");
            else if ((strcmp(input_rock, "C4") == 0))strcpy(rtime[tmp].rock, "C4");
            else if ((strcmp(input_rock, "C5") == 0))strcpy(rtime[tmp].rock, "C5");
            else if ((strcmp(input_rock, "C6") == 0))strcpy(rtime[tmp].rock, "C6");
            else if ((strcmp(input_rock, "C7") == 0))strcpy(rtime[tmp].rock, "C7");
            else if ((strcmp(input_rock, "C8") == 0))strcpy(rtime[tmp].rock, "C8");
            else if ((strcmp(input_rock, "C9") == 0))strcpy(rtime[tmp].rock, "C9");
            else if ((strcmp(input_rock, "D1") == 0))strcpy(rtime[tmp].rock, "D1");
            else if ((strcmp(input_rock, "D2") == 0))strcpy(rtime[tmp].rock, "D2");
            else if ((strcmp(input_rock, "D3") == 0))strcpy(rtime[tmp].rock, "D3");
            else if ((strcmp(input_rock, "D4") == 0))strcpy(rtime[tmp].rock, "D4");
            else if ((strcmp(input_rock, "D5") == 0))strcpy(rtime[tmp].rock, "D5");
            else if ((strcmp(input_rock, "D6") == 0))strcpy(rtime[tmp].rock, "D6");
            else if ((strcmp(input_rock, "D7") == 0))strcpy(rtime[tmp].rock, "D7");
            else if ((strcmp(input_rock, "D8") == 0))strcpy(rtime[tmp].rock, "D8");
            else if ((strcmp(input_rock, "D9") == 0))strcpy(rtime[tmp].rock, "D9");
            else if ((strcmp(input_rock, "E1") == 0))strcpy(rtime[tmp].rock, "E1");
            else if ((strcmp(input_rock, "E2") == 0))strcpy(rtime[tmp].rock, "E2");
            else if ((strcmp(input_rock, "E3") == 0))strcpy(rtime[tmp].rock, "E3");
            else if ((strcmp(input_rock, "E4") == 0))strcpy(rtime[tmp].rock, "E4");
            else if ((strcmp(input_rock, "E5") == 0))strcpy(rtime[tmp].rock, "E5");
            else if ((strcmp(input_rock, "E6") == 0))strcpy(rtime[tmp].rock, "E6");
            else if ((strcmp(input_rock, "E7") == 0))strcpy(rtime[tmp].rock, "E7");
            else if ((strcmp(input_rock, "E8") == 0))strcpy(rtime[tmp].rock, "E8");
            else if ((strcmp(input_rock, "E9") == 0))strcpy(rtime[tmp].rock, "E9");
            else if ((strcmp(input_rock, "F1") == 0))strcpy(rtime[tmp].rock, "F1");
            else if ((strcmp(input_rock, "F2") == 0))strcpy(rtime[tmp].rock, "F2");
            else if ((strcmp(input_rock, "F3") == 0))strcpy(rtime[tmp].rock, "F3");
            else if ((strcmp(input_rock, "F4") == 0))strcpy(rtime[tmp].rock, "F4");
            else if ((strcmp(input_rock, "F5") == 0))strcpy(rtime[tmp].rock, "F5");
            else if ((strcmp(input_rock, "F6") == 0))strcpy(rtime[tmp].rock, "F6");
            else if ((strcmp(input_rock, "F7") == 0))strcpy(rtime[tmp].rock, "F7");
            else if ((strcmp(input_rock, "F8") == 0))strcpy(rtime[tmp].rock, "F8");
            else if ((strcmp(input_rock, "F9") == 0))strcpy(rtime[tmp].rock, "F9");


            FILE* fp1 = fopen("Rock.txt", "w");
            for (int i = 0; i < count; i++)
            {
                fprintf(fp1, "%s  ", rtime[i].rock);
                fprintf(fp1, "%d  ", rtime[i].year);
                fprintf(fp1, "%d  ", rtime[i].mon);
                fprintf(fp1, "%d  ", rtime[i].day);
                fprintf(fp1, "%d  ", rtime[i].hour);
                fprintf(fp1, "%d", rtime[i].min);
                fprintf(fp1, "\n");
            }
            fclose(fp1);
            system("cls");
            Alarm("�繰�� ������ �Ϸ�Ǿ����ϴ�.");
            Secound();
        }
    }
}
void RockTiket()
{
    time_t a = time(NULL);
    struct tm ta = *localtime(&a);

    int menu;
    char input[10];
    system("cls");
    Rect(60, 40, 40, 4);

    Rect1(58, 2, 41, 5, "�繰�� �̿�� ����");
    gotoxy(77, 8);
    gotoxy(43, 13);
    printf("ȸ�� �̸� : %s", join[tmp].name);
    gotoxy(43, 16);
    if (rtime[tmp].year == 0)
    {
        printf("�ܿ��ð��� �����ϴ�. �繰�� �̿���� �������ּ���.");
    }
    else {
        printf("%d�� %d�� %d�� %d�� %d�� ���� ��� �����մϴ�.", rtime[tmp].year, rtime[tmp].mon, rtime[tmp].day, rtime[tmp].hour, rtime[tmp].min);
    }
    gotoxy(43, 19);
    printf("�̿�� �Է� : ");
    gotoxy(43, 24);
    printf("�Ⱓ��");
    Rect5(15, 2, 43, 25, "7D 40000��"), Rect5(15, 2, 58, 25, "15D 80000��"), Rect5(15, 2, 73, 25, "30D 150000��");
    gotoxy(43, 34);
    printf("�ð���");
    Rect5(15, 2, 43, 35, "6H 2000��"), Rect5(15, 2, 58, 35, "12H 8000��"), Rect5(15, 2, 73, 35, "24H 10000��");
    gotoxy(57, 19);
    scanf("%s", input);

    if ((strcmp(input, "7D") == 0) || strcmp(input, "7d") == 0)
    {
        if (rtime[tmp].year == 0)
        {
            rtime[tmp].year = ta.tm_year + 1900;
            rtime[tmp].mon = ta.tm_mon + 1;
            rtime[tmp].day = ta.tm_mday + 7;
            rtime[tmp].hour = ta.tm_hour;
            rtime[tmp].min = ta.tm_min;

            sales[scount].rmoney = 40000;
            sales[scount].ryear = ta.tm_year + 1900;
            sales[scount].rmon = ta.tm_mon + 1;
            sales[scount].rday = ta.tm_mday;
        }
        else
        {
            rtime[tmp].day += 7;
            sales[scount].rmoney = 40000;
            sales[scount].ryear = ta.tm_year + 1900;
            sales[scount].rmon = ta.tm_mon + 1;
            sales[scount].rday = ta.tm_mday;
        }
        if (rtime[tmp].mon == 1 || rtime[tmp].mon == 3 || rtime[tmp].mon == 5 || rtime[tmp].mon == 7 || rtime[tmp].mon == 8 || rtime[tmp].mon == 10 || rtime[tmp].mon == 12)
        {
            if (rtime[tmp].day > 31)
            {
                rtime[tmp].day -= 31;
                rtime[tmp].mon += 1;
            }
            else if (rtime[tmp].mon == 12 && rtime[tmp].day > 31)
            {
                rtime[tmp].mon = 1;
                rtime[tmp].day -= 31;
                rtime[tmp].year += 1;
            }
        }
        else if (rtime[tmp].mon == 4 || rtime[tmp].mon == 6 || rtime[tmp].mon == 9 || rtime[tmp].mon == 11)
        {
            if (rtime[tmp].day > 30)
            {
                rtime[tmp].day -= 30;
                rtime[tmp].mon += 1;
            }
        }
        else
        {
            if (rtime[tmp].day > 28)
            {
                rtime[tmp].day -= 28;
                rtime[tmp].mon += 1;
            }
        }
        if (rtime[tmp].mon == 13)
        {
            rtime[tmp].mon = 1;
            rtime[tmp].year += 1;
        }
        system("cls");
        Alarm("�̿�� ���Ű� �Ϸ�Ǿ����ϴ�.");
    }
    else if ((strcmp(input, "15D") == 0) || strcmp(input, "15d") == 0)
    {
        if (rtime[tmp].year == 0)
        {
            rtime[tmp].year = ta.tm_year + 1900;
            rtime[tmp].mon = ta.tm_mon + 1;
            rtime[tmp].day = ta.tm_mday + 15;
            rtime[tmp].hour = ta.tm_hour;
            rtime[tmp].min = ta.tm_min;

            sales[scount].rmoney = 80000;
            sales[scount].ryear = ta.tm_year + 1900;
            sales[scount].rmon = ta.tm_mon + 1;
            sales[scount].rday = ta.tm_mday;
        }
        else
        {
            rtime[tmp].day += 15;

            sales[scount].rmoney = 80000;
            sales[scount].ryear = ta.tm_year + 1900;
            sales[scount].rmon = ta.tm_mon + 1;
            sales[scount].rday = ta.tm_mday;
        }
        if (rtime[tmp].mon == 1 || rtime[tmp].mon == 3 || rtime[tmp].mon == 5 || rtime[tmp].mon == 7 || rtime[tmp].mon == 8 || rtime[tmp].mon == 10 || rtime[tmp].mon == 12)
        {
            if (rtime[tmp].day > 31)
            {
                rtime[tmp].day -= 31;
                rtime[tmp].mon += 1;
            }
            else if (rtime[tmp].mon == 12 && rtime[tmp].day > 31)
            {
                rtime[tmp].mon = 1;
                rtime[tmp].day -= 31;
                rtime[tmp].year += 1;
            }
        }
        else if (rtime[tmp].mon == 4 || rtime[tmp].mon == 6 || rtime[tmp].mon == 9 || rtime[tmp].mon == 11)
        {
            if (rtime[tmp].day > 30)
            {
                rtime[tmp].day -= 30;
                rtime[tmp].mon += 1;
            }
        }
        else
        {
            if (rtime[tmp].day > 28)
            {
                rtime[tmp].day -= 28;
                rtime[tmp].mon += 1;
            }
        }
        if (rtime[tmp].mon == 13)
        {
            rtime[tmp].mon = 1;
            rtime[tmp].year += 1;
        }
        system("cls");
        Alarm("�̿�� ���Ű� �Ϸ�Ǿ����ϴ�.");
    }
    else if ((strcmp(input, "30D") == 0) || strcmp(input, "30d") == 0)
    {
        if (rtime[tmp].year == 0)
        {
            rtime[tmp].year = ta.tm_year + 1900;
            rtime[tmp].mon = ta.tm_mon + 1;
            rtime[tmp].day = ta.tm_mday + 30;
            rtime[tmp].hour = ta.tm_hour;
            rtime[tmp].min = ta.tm_min;

            sales[scount].rmoney = 150000;
            sales[scount].ryear = ta.tm_year + 1900;
            sales[scount].rmon = ta.tm_mon + 1;
            sales[scount].rday = ta.tm_mday;
        }
        else
        {
            rtime[tmp].day += 30;

            sales[scount].rmoney = 150000;
            sales[scount].ryear = ta.tm_year + 1900;
            sales[scount].rmon = ta.tm_mon + 1;
            sales[scount].rday = ta.tm_mday;
        }
        if (rtime[tmp].mon == 1 || rtime[tmp].mon == 3 || rtime[tmp].mon == 5 || rtime[tmp].mon == 7 || rtime[tmp].mon == 8 || rtime[tmp].mon == 10 || rtime[tmp].mon == 12)
        {
            if (rtime[tmp].day > 31)
            {
                rtime[tmp].day -= 31;
                rtime[tmp].mon += 1;
            }
            else if (rtime[tmp].mon == 12 && rtime[tmp].day > 31)
            {
                rtime[tmp].mon = 1;
                rtime[tmp].day -= 31;
                rtime[tmp].year += 1;
            }
        }
        else if (rtime[tmp].mon == 4 || rtime[tmp].mon == 6 || rtime[tmp].mon == 9 || rtime[tmp].mon == 11)
        {
            if (rtime[tmp].day > 30)
            {
                rtime[tmp].day -= 30;
                rtime[tmp].mon += 1;
            }
        }
        else
        {
            if (rtime[tmp].day > 28)
            {
                rtime[tmp].day -= 28;
                rtime[tmp].mon += 1;
            }
        }
        if (rtime[tmp].mon == 13)
        {
            rtime[tmp].mon = 1;
            rtime[tmp].year += 1;
        }
        system("cls");
        Alarm("�̿�� ���Ű� �Ϸ�Ǿ����ϴ�.");
    }
    else if ((strcmp(input, "6H") == 0) || strcmp(input, "6h") == 0)
    {
        if (rtime[tmp].year == 0)
        {
            rtime[tmp].year = ta.tm_year + 1900;
            rtime[tmp].mon = ta.tm_mon + 1;
            rtime[tmp].day = ta.tm_mday;
            rtime[tmp].hour = ta.tm_hour + 6;
            rtime[tmp].min = ta.tm_min;

            sales[scount].rmoney = 2000;
            sales[scount].ryear = ta.tm_year + 1900;
            sales[scount].rmon = ta.tm_mon + 1;
            sales[scount].rday = ta.tm_mday;
        }
        else
        {
            rtime[tmp].hour += 6;

            sales[scount].rmoney = 2000;
            sales[scount].ryear = ta.tm_year + 1900;
            sales[scount].rmon = ta.tm_mon + 1;
            sales[scount].rday = ta.tm_mday;
        }
        if (rtime[tmp].hour >= 24)
        {
            rtime[tmp].hour -= 24;
            rtime[tmp].day += 1;
        }
        if (rtime[tmp].mon == 1 || rtime[tmp].mon == 3 || rtime[tmp].mon == 5 || rtime[tmp].mon == 7 || rtime[tmp].mon == 8 || rtime[tmp].mon == 10 || rtime[tmp].mon == 12)
        {
            if (rtime[tmp].day > 31)
            {
                rtime[tmp].day -= 31;
                rtime[tmp].mon += 1;
            }
            else if (rtime[tmp].mon == 12 && rtime[tmp].day > 31)
            {
                rtime[tmp].mon = 1;
                rtime[tmp].day -= 31;
                rtime[tmp].year += 1;
            }
        }
        else if (rtime[tmp].mon == 4 || rtime[tmp].mon == 6 || rtime[tmp].mon == 9 || rtime[tmp].mon == 11)
        {
            if (rtime[tmp].day > 30)
            {
                rtime[tmp].day -= 30;
                rtime[tmp].mon += 1;
            }
        }
        else
        {
            if (rtime[tmp].day > 28)
            {
                rtime[tmp].day -= 28;
                rtime[tmp].mon += 1;
            }
        }
        if (rtime[tmp].mon == 13)
        {
            rtime[tmp].mon = 1;
            rtime[tmp].year += 1;
        }
        system("cls");
        Alarm("�̿�� ���Ű� �Ϸ�Ǿ����ϴ�.");
    }
    else if ((strcmp(input, "12H") == 0) || strcmp(input, "12h") == 0)
    {
        if (rtime[tmp].year == 0)
        {
            rtime[tmp].year = ta.tm_year + 1900;
            rtime[tmp].mon = ta.tm_mon + 1;
            rtime[tmp].day = ta.tm_mday;
            rtime[tmp].hour = ta.tm_hour + 12;
            rtime[tmp].min = ta.tm_min;

            sales[scount].rmoney = 8000;
            sales[scount].ryear = ta.tm_year + 1900;
            sales[scount].rmon = ta.tm_mon + 1;
            sales[scount].rday = ta.tm_mday;
        }
        else
        {
            rtime[tmp].hour += 12;

            sales[scount].rmoney = 8000;
            sales[scount].ryear = ta.tm_year + 1900;
            sales[scount].rmon = ta.tm_mon + 1;
            sales[scount].rday = ta.tm_mday;
        }
        if (rtime[tmp].hour >= 24)
        {
            rtime[tmp].hour -= 24;
            rtime[tmp].day += 1;
        }
        if (rtime[tmp].mon == 1 || rtime[tmp].mon == 3 || rtime[tmp].mon == 5 || rtime[tmp].mon == 7 || rtime[tmp].mon == 8 || rtime[tmp].mon == 10 || rtime[tmp].mon == 12)
        {
            if (rtime[tmp].day > 31)
            {
                rtime[tmp].day -= 31;
                rtime[tmp].mon += 1;
            }
            else if (rtime[tmp].mon == 12 && rtime[tmp].day > 31)
            {
                rtime[tmp].mon = 1;
                rtime[tmp].day -= 31;
                rtime[tmp].year += 1;
            }
        }
        else if (rtime[tmp].mon == 4 || rtime[tmp].mon == 6 || rtime[tmp].mon == 9 || rtime[tmp].mon == 11)
        {
            if (rtime[tmp].day > 30)
            {
                rtime[tmp].day -= 30;
                rtime[tmp].mon += 1;
            }
        }
        else
        {
            if (rtime[tmp].day > 28)
            {
                rtime[tmp].day -= 28;
                rtime[tmp].mon += 1;
            }
        }
        if (rtime[tmp].mon == 13)
        {
            rtime[tmp].mon = 1;
            rtime[tmp].year += 1;
        }
        system("cls");
        Alarm("�̿�� ���Ű� �Ϸ�Ǿ����ϴ�.");
    }
    else if ((strcmp(input, "24H") == 0) || strcmp(input, "24h") == 0)
    {
        if (rtime[tmp].year == 0)
        {
            rtime[tmp].year = ta.tm_year + 1900;
            rtime[tmp].mon = ta.tm_mon + 1;
            rtime[tmp].day = ta.tm_mday;
            rtime[tmp].hour = ta.tm_hour + 24;
            rtime[tmp].min = ta.tm_min;

            sales[scount].rmoney = 10000;
            sales[scount].ryear = ta.tm_year + 1900;
            sales[scount].rmon = ta.tm_mon + 1;
            sales[scount].rday = ta.tm_mday;
        }
        else
        {
            rtime[tmp].hour += 24;

            sales[scount].rmoney = 10000;
            sales[scount].ryear = ta.tm_year + 1900;
            sales[scount].rmon = ta.tm_mon + 1;
            sales[scount].rday = ta.tm_mday;
        }
        if (rtime[tmp].hour >= 24)
        {
            rtime[tmp].hour -= 24;
            rtime[tmp].day += 1;
        }
        if (rtime[tmp].mon == 1 || rtime[tmp].mon == 3 || rtime[tmp].mon == 5 || rtime[tmp].mon == 7 || rtime[tmp].mon == 8 || rtime[tmp].mon == 10 || rtime[tmp].mon == 12)
        {
            if (rtime[tmp].day > 31)
            {
                rtime[tmp].day -= 31;
                rtime[tmp].mon += 1;
            }
            else if (rtime[tmp].mon == 12 && rtime[tmp].day > 31)
            {
                rtime[tmp].mon = 1;
                rtime[tmp].day -= 31;
                rtime[tmp].year += 1;
            }
        }
        else if (rtime[tmp].mon == 4 || rtime[tmp].mon == 6 || rtime[tmp].mon == 9 || rtime[tmp].mon == 11)
        {
            if (rtime[tmp].day > 30)
            {
                rtime[tmp].day -= 30;
                rtime[tmp].mon += 1;
            }
        }
        else
        {
            if (rtime[tmp].day > 28)
            {
                rtime[tmp].day -= 28;
                rtime[tmp].mon += 1;
            }
        }
        if (rtime[tmp].mon == 13)
        {
            rtime[tmp].mon = 1;
            rtime[tmp].year += 1;
        }
        system("cls");
        Alarm("�̿�� ���Ű� �Ϸ�Ǿ����ϴ�.");
    }
    FILE* fp1 = fopen("Rock.txt", "w");
    for (int i = 0; i < count; i++)
    {
        fprintf(fp1, "%s  ", rtime[i].rock);
        fprintf(fp1, "%d  ", rtime[i].year);
        fprintf(fp1, "%d  ", rtime[i].mon);
        fprintf(fp1, "%d  ", rtime[i].day);
        fprintf(fp1, "%d  ", rtime[i].hour);
        fprintf(fp1, "%d", rtime[i].min);
        fprintf(fp1, "\n");
    }
    fclose(fp1);
    file_sales_append();
    Secound();
}
void Secound()
{
    int menu;
    system("cls");
    Rect(60, 40, 40, 4);

    Rect1(58, 2, 41, 5, "1.�̿�� 2.�ڸ����� 3.��� 4.�ڷΰ���");
    Rect3(58, 2, 41, 7, "�޴� �Է� : ");
    gotoxy(77, 8);
    scanf("%d%*c", &menu);
    if (menu == 1)
    {
        Tiket();
    }
    else if (menu == 2)
    {
        Choice();
    }
    else if (menu == 3)
    {
        checkout();
    }
    else if (menu == 4)
    {
        First();
    }
    else
    {
        Secound();
    }

}
void Tiket()
{
    int menu;
    system("cls");
    Rect(60, 40, 40, 4);

    Rect1(58, 2, 41, 5, "1.�¼� �̿�� 2.�繰�� �̿�� 3.�ڷΰ���");
    Rect3(58, 2, 41, 7, "�޴� �Է� : ");
    gotoxy(77, 8);
    scanf("%d%*c", &menu);
    if (menu == 1)
    {
        SeatTiket();
    }
    else if (menu == 2)
    {
        RockTiket();
    }
    else if (menu == 3)
    {
        Secound();
    }
    else
    {
        Tiket();
    }
}
void Choice()
{
    int menu;
    system("cls");
    Rect(60, 40, 40, 4);

    Rect1(58, 2, 41, 5, "1.�¼� ���� 2.�繰�� ���� 3.�ڷΰ���");
    Rect3(58, 2, 41, 7, "�޴� �Է� : ");
    gotoxy(77, 8);
    scanf("%d%*c", &menu);

    if (menu == 1)
    {
        SeatCheck();
    }
    else if (menu == 2)
    {
        RockCheck();
    }
    else
    {
        Secound();
    }
}
void SeatTimeCheck()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    if ((strcmp(join[tmp].gen, "����") == 0) || (strcmp(join[tmp].gen, "��") == 0))
    {
        if (tm.tm_year + 1900 > stime[tmp].year) //�⵵�� �Ѿ������ ������ ��¥�� ����
        {
            strcpy(stime[tmp].seat, "0");
            strcpy(stime[tmp].gen, "����");
            stime[tmp].year = 0;
            stime[tmp].mon = 0;
            stime[tmp].day = 0;
            stime[tmp].hour = 0;
            stime[tmp].min = 0;
        }
        else if ((tm.tm_year + 1900 == stime[tmp].year) && (tm.tm_mon + 1 > stime[tmp].mon)) //�⵵�� ������ ���� �Ѿ��� ��� ������ ��¥�� ����
        {
            strcpy(stime[tmp].seat, "0");
            strcpy(stime[tmp].gen, "����");
            stime[tmp].year = 0;
            stime[tmp].mon = 0;
            stime[tmp].day = 0;
            stime[tmp].hour = 0;
            stime[tmp].min = 0;
        }
        else if ((tm.tm_year + 1900 == stime[tmp].year) && (tm.tm_mon + 1 == stime[tmp].mon) && (tm.tm_mday > stime[tmp].day)) //�⵵�� ���� ������ ���� �Ѿ��� ��� ������ ��¥�� ����
        {
            strcpy(stime[tmp].seat, "0");
            strcpy(stime[tmp].gen, "����");
            stime[tmp].year = 0;
            stime[tmp].mon = 0;
            stime[tmp].day = 0;
            stime[tmp].hour = 0;
            stime[tmp].min = 0;
        }
        else if ((tm.tm_year + 1900 == stime[tmp].year) && (tm.tm_mon + 1 == stime[tmp].mon) && (tm.tm_mday == stime[tmp].day) && (tm.tm_hour > stime[tmp].hour)) //��,��,���� ������ �ð��� ������ ����
        {
            strcpy(stime[tmp].seat, "0");
            strcpy(stime[tmp].gen, "����");
            stime[tmp].year = 0;
            stime[tmp].mon = 0;
            stime[tmp].day = 0;
            stime[tmp].hour = 0;
            stime[tmp].min = 0;
        }
        else if ((tm.tm_year + 1900 == stime[tmp].year) && (tm.tm_mon + 1 == stime[tmp].mon) && (tm.tm_mday == stime[tmp].day) && (tm.tm_hour > stime[tmp].hour) && (tm.tm_min > stime[tmp].min)) //��,��,��, �ô� ������ ���� ������ ����
        {
            strcpy(stime[tmp].seat, "0");
            strcpy(stime[tmp].gen, "����");
            stime[tmp].year = 0;
            stime[tmp].mon = 0;
            stime[tmp].day = 0;
            stime[tmp].hour = 0;
            stime[tmp].min = 0;
        }
        FILE* fp2 = fopen("Seattime.txt", "w");
        for (int i = 0; i < count; i++)
        {
            fprintf(fp2, "%s  ", stime[i].seat);
            fprintf(fp2, "%s  ", stime[i].gen);
            fprintf(fp2, "%d  ", stime[i].year);
            fprintf(fp2, "%d  ", stime[i].mon);
            fprintf(fp2, "%d  ", stime[i].day);
            fprintf(fp2, "%d  ", stime[i].hour);
            fprintf(fp2, "%d", stime[i].min);
            fprintf(fp2, "\n");
        }
        fclose(fp2);
    }
    else if ((strcmp(join[tmp].gen, "����") == 0) || (strcmp(join[tmp].gen, "��") == 0))
    {
        if (tm.tm_year + 1900 > stime[tmp].year) //�⵵�� �Ѿ������ ������ ��¥�� ����
        {
            strcpy(stime[tmp].seat, "0");
            strcpy(stime[tmp].gen, "����");
            stime[tmp].year = 0;
            stime[tmp].mon = 0;
            stime[tmp].day = 0;
            stime[tmp].hour = 0;
            stime[tmp].min = 0;
        }
        else if ((tm.tm_year + 1900 == stime[tmp].year) && (tm.tm_mon + 1 > stime[tmp].mon)) //�⵵�� ������ ���� �Ѿ��� ��� ������ ��¥�� ����
        {
            strcpy(stime[tmp].seat, "0");
            strcpy(stime[tmp].gen, "����");
            stime[tmp].year = 0;
            stime[tmp].mon = 0;
            stime[tmp].day = 0;
            stime[tmp].hour = 0;
            stime[tmp].min = 0;
        }
        else if ((tm.tm_year + 1900 == stime[tmp].year) && (tm.tm_mon + 1 == stime[tmp].mon) && (tm.tm_mday > stime[tmp].day)) //�⵵�� ���� ������ ���� �Ѿ��� ��� ������ ��¥�� ����
        {
            strcpy(stime[tmp].seat, "0");
            strcpy(stime[tmp].gen, "����");
            stime[tmp].year = 0;
            stime[tmp].mon = 0;
            stime[tmp].day = 0;
            stime[tmp].hour = 0;
            stime[tmp].min = 0;
        }
        else if ((tm.tm_year + 1900 == stime[tmp].year) && (tm.tm_mon + 1 == stime[tmp].mon) && (tm.tm_mday == stime[tmp].day) && (tm.tm_hour > stime[tmp].hour)) //��,��,���� ������ �ð��� ������ ����
        {
            strcpy(stime[tmp].seat, "0");
            strcpy(stime[tmp].gen, "����");
            stime[tmp].year = 0;
            stime[tmp].mon = 0;
            stime[tmp].day = 0;
            stime[tmp].hour = 0;
            stime[tmp].min = 0;
        }
        else if ((tm.tm_year + 1900 == stime[tmp].year) && (tm.tm_mon + 1 == stime[tmp].mon) && (tm.tm_mday == stime[tmp].day) && (tm.tm_hour > stime[tmp].hour) && (tm.tm_min > stime[tmp].min)) //��,��,��, �ô� ������ ���� ������ ����
        {
            strcpy(stime[tmp].seat, "0");
            strcpy(stime[tmp].gen, "����");
            stime[tmp].year = 0;
            stime[tmp].mon = 0;
            stime[tmp].day = 0;
            stime[tmp].hour = 0;
            stime[tmp].min = 0;
        }
        FILE* fp2 = fopen("Seattime.txt", "w");
        for (int i = 0; i < count; i++)
        {
            fprintf(fp2, "%s  ", stime[i].seat);
            fprintf(fp2, "%s  ", stime[i].gen);
            fprintf(fp2, "%d  ", stime[i].year);
            fprintf(fp2, "%d  ", stime[i].mon);
            fprintf(fp2, "%d  ", stime[i].day);
            fprintf(fp2, "%d  ", stime[i].hour);
            fprintf(fp2, "%d ", stime[i].min);
            fprintf(fp2, "\n");
        }
        fclose(fp2);
    }
}
void RockTimeCheck()
{
    time_t b = time(NULL);
    struct tm tm = *localtime(&b);
    if (tm.tm_year + 1900 > rtime[tmp].year) //�⵵�� �Ѿ������ ������ ��¥�� ����
    {
        strcpy(rtime[tmp].rock, "0");
        rtime[tmp].year = 0;
        rtime[tmp].mon = 0;
        rtime[tmp].day = 0;
        rtime[tmp].hour = 0;
        rtime[tmp].min = 0;
    }
    if ((tm.tm_year + 1900 == rtime[tmp].year) && (tm.tm_mon + 1 > rtime[tmp].mon)) //�⵵�� ������ ���� �Ѿ��� ��� ������ ��¥�� ����
    {
        strcpy(rtime[tmp].rock, "0");
        rtime[tmp].year = 0;
        rtime[tmp].mon = 0;
        rtime[tmp].day = 0;
        rtime[tmp].hour = 0;
        rtime[tmp].min = 0;
    }
    else if ((tm.tm_year + 1900 == rtime[tmp].year) && (tm.tm_mon + 1 == rtime[tmp].mon) && (tm.tm_mday > rtime[tmp].day)) //�⵵�� ���� ������ ���� �Ѿ��� ��� ������ ��¥�� ����
    {
        strcpy(rtime[tmp].rock, "0");
        rtime[tmp].year = 0;
        rtime[tmp].mon = 0;
        rtime[tmp].day = 0;
        rtime[tmp].hour = 0;
        rtime[tmp].min = 0;
    }
    else if ((tm.tm_year + 1900 == rtime[tmp].year) && (tm.tm_mon + 1 == rtime[tmp].mon) && (tm.tm_mday == rtime[tmp].day) && (tm.tm_hour > rtime[tmp].hour)) //��,��,���� ������ �ð��� ������ ����
    {
        strcpy(rtime[tmp].rock, "0");
        rtime[tmp].year = 0;
        rtime[tmp].mon = 0;
        rtime[tmp].day = 0;
        rtime[tmp].hour = 0;
        rtime[tmp].min = 0;
    }
    else if ((tm.tm_year + 1900 == rtime[tmp].year) && (tm.tm_mon + 1 == rtime[tmp].mon) && (tm.tm_mday == rtime[tmp].day) && (tm.tm_hour == rtime[tmp].hour) && (tm.tm_min > rtime[tmp].min)) //��,��,��,�ô� ������ ���� ������ �ð��� ����
    {
        strcpy(rtime[tmp].rock, "0");
        rtime[tmp].year = 0;
        rtime[tmp].mon = 0;
        rtime[tmp].day = 0;
        rtime[tmp].hour = 0;
        rtime[tmp].min = 0;
    }

    FILE* fp2 = fopen("Rock.txt", "w");
    for (int i = 0; i < count; i++)
    {
        fprintf(fp2, "%s  ", rtime[i].rock);
        fprintf(fp2, "%d  ", rtime[i].year);
        fprintf(fp2, "%d  ", rtime[i].mon);
        fprintf(fp2, "%d  ", rtime[i].day);
        fprintf(fp2, "%d  ", rtime[i].hour);
        fprintf(fp2, "%d", rtime[i].min);
        fprintf(fp2, "\n");
    }
    fclose(fp2);
}
void MseatColor()
{
    for (int i = 0; i < count; i++)
    {
        if ((strcmp(join[i].gen, "����") == 0) || (strcmp(join[i].gen, "��") == 0))
        {
            if (strcmp(stime[i].seat, "A1") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 6, 11, "A1");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "A2") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 13, 11, "A2");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "A3") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 20, 11, "A3");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "A4") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 27, 11, "A4");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "A5") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 34, 11, "A5");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "A6") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 41, 11, "A6");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "A7") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 48, 11, "A7");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "A8") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 55, 11, "A8");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "A9") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 62, 11, "A9");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "B1") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 6, 14, "B1");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "B2") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 13, 14, "B2");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "B3") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 20, 14, "B3");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "B4") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 27, 14, "B4");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "B5") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 34, 14, "B5");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "B6") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 41, 14, "B6");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "B7") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 48, 14, "B7");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "B8") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 55, 14, "B8");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "B9") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 62, 14, "B9");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "C1") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 6, 17, "C1");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "C2") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 13, 17, "C2");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "C3") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 20, 17, "C3");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "C4") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 27, 17, "C4");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "C5") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 34, 17, "C5");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "C6") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 41, 17, "C6");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "C7") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 48, 17, "C7");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "C8") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 55, 17, "C8");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "C9") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                Rect5(5, 2, 62, 17, "C9");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
        }
    }
}
void GseatColor()
{
    for (int i = 0; i < count; i++)
    {
        if ((strcmp(join[i].gen, "����") == 0) || (strcmp(join[i].gen, "��") == 0)) {
            if (strcmp(stime[i].seat, "A1") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 6, 24, "A1");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "A2") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 13, 24, "A2");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "A3") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 20, 24, "A3");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "A4") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 27, 24, "A4");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "A5") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 34, 24, "A5");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "A6") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 41, 24, "A6");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "A7") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 48, 24, "A7");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "A8") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 55, 24, "A8");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "A9") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 62, 24, "A9");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "B1") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 6, 27, "B1");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "B2") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 13, 27, "B2");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "B3") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 20, 27, "B3");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "B4") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 27, 27, "B4");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "B5") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 34, 27, "B5");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "B6") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 41, 27, "B6");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "B7") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 48, 27, "B7");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "B8") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 55, 27, "B8");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "B9") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 62, 27, "B9");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "C1") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 6, 30, "C1");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "C2") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 13, 30, "C2");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "C3") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 20, 30, "C3");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "C4") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 27, 30, "C4");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "C5") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 34, 30, "C5");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "C6") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 41, 30, "C6");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "C7") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 48, 30, "C7");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "C8") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 55, 30, "C8");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
            if (strcmp(stime[i].seat, "C9") == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                Rect5(5, 2, 62, 30, "C9");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            }
        }
    }
}
void RockColor()
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(rtime[i].rock, "A1") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 6, 11, "A1");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "A2") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 13, 11, "A2");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "A3") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 20, 11, "A3");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "A4") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 27, 11, "A4");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "A5") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 34, 11, "A5");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "A6") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 41, 11, "A6");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "A7") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 48, 11, "A7");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "A8") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 55, 11, "A8");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "A9") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 62, 11, "A9");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "B1") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 6, 14, "B1");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "B2") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 13, 14, "B2");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "B3") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 20, 14, "B3");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "B4") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 27, 14, "B4");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "B5") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 34, 14, "B5");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "B6") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 41, 14, "B6");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "B7") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 48, 14, "B7");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "B8") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 55, 14, "B8");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "B9") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 62, 14, "B9");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "C1") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 6, 17, "C1");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "C2") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 13, 17, "C2");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "C3") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 20, 17, "C3");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "C4") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 27, 17, "C4");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "C5") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 34, 17, "C5");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "C6") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 41, 17, "C6");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "C7") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 48, 17, "C7");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "C8") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 55, 17, "C8");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "C9") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 62, 17, "C9");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "D1") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 6, 24, "D1");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "D2") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 13, 24, "D2");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "D3") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 20, 24, "D3");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "D4") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 27, 24, "D4");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "D5") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 34, 24, "D5");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "D6") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 41, 24, "D6");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "D7") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 48, 24, "D7");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "D8") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 55, 24, "D8");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "D9") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 62, 24, "D9");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "E1") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 6, 27, "E1");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "E2") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 13, 27, "E2");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "E3") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 20, 27, "E3");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "E4") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 27, 27, "E4");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "E5") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 34, 27, "E5");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "E6") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 41, 27, "E6");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "E7") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 48, 27, "E7");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "E8") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 55, 27, "E8");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "E9") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 62, 27, "E9");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "F1") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 6, 30, "F1");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "F2") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 13, 30, "F2");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "F3") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 20, 30, "F3");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "F4") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 27, 30, "F4");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "F5") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 34, 30, "F5");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "F6") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 41, 30, "F6");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "F7") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 48, 30, "F7");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "F8") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 55, 30, "F8");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        if (strcmp(rtime[i].rock, "F9") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            Rect5(5, 2, 62, 30, "F9");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
    }
}
void entryroom()
{
    char input;
    system("cls");
    Rect(60, 40, 40, 4);
    Rect1(58, 2, 41, 5, "�Խ�");
    if ((strcmp(join[tmp].gen, "����") == 0) || (strcmp(join[tmp].gen, "��") == 0))
    {
        gotoxy(45, 13);
        printf("���� ȸ��");
        gotoxy(45, 18);
        printf("ȸ�� �̸� : %s", join[tmp].name);
        gotoxy(45, 23);
        printf("�¼� ��ȣ : %s", stime[tmp].seat);
        gotoxy(45, 28);
        printf("���� �ð� : %d�� %d�� %d�� %d�� %d�� ���� ��� ����.", stime[tmp].year, stime[tmp].mon, stime[tmp].day, stime[tmp].hour, stime[tmp].min);
        gotoxy(45, 33);
        printf("�Խ��Ͻðڽ��ϱ�?(y/n) : ");
        gotoxy(70, 33);
        scanf("%s", &input);
        if ((input == 'y') || (input == 'y'))
        {
            Alarm("�Խ��� �Ϸ�Ǿ����ϴ�!");
            FILE* fp1 = fopen("Seattime.txt", "w");
            for (int i = 0; i < count; i++)
            {
                fprintf(fp1, "%s  ", stime[i].seat);
                fprintf(fp1, "%s  ", stime[i].gen);
                fprintf(fp1, "%d  ", stime[i].year);
                fprintf(fp1, "%d  ", stime[i].mon);
                fprintf(fp1, "%d  ", stime[i].day);
                fprintf(fp1, "%d  ", stime[i].hour);
                fprintf(fp1, "%d", stime[i].min);
                fprintf(fp1, "\n");
            }
            fclose(fp1);
            Secound();
        }
        else if ((input == 'n') || (input == 'N'))
        {
            Alarm("�Խ��� ��ҵǾ����ϴ�!");
            strcpy(stime[tmp].seat, "0");
            FILE* fp2 = fopen("Seattime.txt", "w");
            for (int i = 0; i < count; i++)
            {
                fprintf(fp2, "%s  ", stime[i].seat);
                fprintf(fp2, "%s  ", stime[i].gen);
                fprintf(fp2, "%d  ", stime[i].year);
                fprintf(fp2, "%d  ", stime[i].mon);
                fprintf(fp2, "%d  ", stime[i].day);
                fprintf(fp2, "%d  ", stime[i].hour);
                fprintf(fp2, "%d", stime[i].min);
                fprintf(fp2, "\n");
                Secound();
            }
            fclose(fp2);
        }
        else
        {
            Alarm("�ٽ� �Է����ּ���!");
            entryroom();
        }
    }
    else if ((strcmp(join[tmp].gen, "����") == 0) || (strcmp(join[tmp].gen, "��") == 0))
    {
        gotoxy(45, 13);
        printf("���� ȸ��");
        gotoxy(45, 18);
        printf("ȸ�� �̸� : %s", join[tmp].name);
        gotoxy(45, 23);
        printf("�¼� ��ȣ : %s", stime[tmp].seat);
        gotoxy(45, 28);
        printf("���� �ð� : %d�� %d�� %d�� %d�� %d�� ���� ��� ����.", stime[tmp].year, stime[tmp].mon, stime[tmp].day, stime[tmp].hour, stime[tmp].min);
        gotoxy(45, 33);
        printf("�Խ��Ͻðڽ��ϱ�?(y/n) : ");
        gotoxy(70, 33);
        scanf("%c", &input);
        if ((input == 'y') || (input == 'Y'))
        {
            Alarm("�Խ��� �Ϸ�Ǿ����ϴ�!");
            FILE* fp1 = fopen("Seattime.txt", "w");
            for (int i = 0; i < count; i++)
            {
                fprintf(fp1, "%s  ", stime[i].seat);
                fprintf(fp1, "%s  ", stime[i].gen);
                fprintf(fp1, "%d  ", stime[i].year);
                fprintf(fp1, "%d  ", stime[i].mon);
                fprintf(fp1, "%d  ", stime[i].day);
                fprintf(fp1, "%d  ", stime[i].hour);
                fprintf(fp1, "%d", stime[i].min);
                fprintf(fp1, "\n");
            }
            fclose(fp1);
            Secound();
        }
        else if ((input == 'n') || (input == 'N'))
        {
            Alarm("�Խ��� ��ҵǾ����ϴ�!");
            strcpy(stime[tmp].seat, "0");
            FILE* fp2 = fopen("Seattime.txt", "w");
            for (int i = 0; i < count; i++)
            {
                fprintf(fp2, "%s  ", stime[tmp].seat);
                fprintf(fp2, "%s  ", stime[i].gen);
                fprintf(fp2, "%d  ", stime[i].year);
                fprintf(fp2, "%d  ", stime[i].mon);
                fprintf(fp2, "%d  ", stime[i].day);
                fprintf(fp2, "%d  ", stime[i].hour);
                fprintf(fp2, "%d", stime[i].min);
                fprintf(fp2, "\n");
                Secound();
            }
            fclose(fp2);
        }
        else
        {
            Alarm("�ٽ� �Է����ּ���!");
            entryroom();
        }
    }
}
void checkout()
{
    char input;
    system("cls");
    Rect(60, 40, 40, 4);
    Rect1(58, 2, 41, 5, "���");
    if ((strcmp(join[tmp].gen, "����") == 0) || (strcmp(join[tmp].gen, "��") == 0))
    {
        gotoxy(45, 13);
        printf("���� ȸ��");
        gotoxy(45, 18);
        printf("ȸ�� �̸� : %s", join[tmp].name);
        gotoxy(45, 23);
        printf("�¼� ��ȣ : %s", stime[tmp].seat);
        gotoxy(45, 28);
        printf("���� �ð� : %d�� %d�� %d�� %d�� %d�� ���� ��� ����.", stime[tmp].year, stime[tmp].mon, stime[tmp].day, stime[tmp].hour, stime[tmp].min);
        gotoxy(45, 33);
        printf("����Ͻðڽ��ϱ�?(y/n) : ");
        gotoxy(70, 33);
        scanf("%s", &input);
        if ((input == 'y') || (input == 'y'))
        {
            Alarm("����� �Ϸ�Ǿ����ϴ�!");
            strcpy(stime[tmp].seat, "0");
            FILE* fp1 = fopen("Seattime.txt", "w");
            for (int i = 0; i < count; i++)
            {
                fprintf(fp1, "%s  ", stime[i].seat);
                fprintf(fp1, "%s  ", stime[i].gen);
                fprintf(fp1, "%d  ", stime[i].year);
                fprintf(fp1, "%d  ", stime[i].mon);
                fprintf(fp1, "%d  ", stime[i].day);
                fprintf(fp1, "%d  ", stime[i].hour);
                fprintf(fp1, "%d", stime[i].min);
                fprintf(fp1, "\n");
            }
            fclose(fp1);
            First();
        }
        else if ((input == 'n') || (input == 'N'))
        {
            Alarm("����� ��ҵǾ����ϴ�!");
            Secound();
        }
        else
        {
            Alarm("�ٽ� �Է����ּ���!");
            checkout();
        }
    }
    else if ((strcmp(join[tmp].gen, "����") == 0) || (strcmp(join[tmp].gen, "��") == 0))
    {
        gotoxy(45, 13);
        printf("���� ȸ��");
        gotoxy(45, 18);
        printf("ȸ�� �̸� : %s", join[tmp].name);
        gotoxy(45, 23);
        printf("�¼� ��ȣ : %s", stime[tmp].seat);
        gotoxy(45, 28);
        printf("���� �ð� : %d�� %d�� %d�� %d�� %d�� ���� ��� ����.", stime[tmp].year, stime[tmp].mon, stime[tmp].day, stime[tmp].hour, stime[tmp].min);
        gotoxy(45, 33);
        printf("����Ͻðڽ��ϱ�?(y/n) : ");
        gotoxy(70, 33);
        scanf("%s", &input);
        if ((input == 'y') || (input == 'y'))
        {
            Alarm("����� �Ϸ�Ǿ����ϴ�!");
            strcpy(stime[tmp].seat, "0");
            FILE* fp1 = fopen("Seattime.txt", "w");
            for (int i = 0; i < count; i++)
            {
                fprintf(fp1, "%s  ", stime[i].seat);
                fprintf(fp1, "%s  ", stime[i].gen);
                fprintf(fp1, "%d  ", stime[i].year);
                fprintf(fp1, "%d  ", stime[i].mon);
                fprintf(fp1, "%d  ", stime[i].day);
                fprintf(fp1, "%d  ", stime[i].hour);
                fprintf(fp1, "%d", stime[i].min);
                fprintf(fp1, "\n");
            }
            fclose(fp1);
            First();
        }
        else if ((input == 'n') || (input == 'N'))
        {
            Alarm("����� ��ҵǾ����ϴ�!");
            Secound();
        }
        else
        {
            Alarm("�ٽ� �Է����ּ���!");
            checkout();
        }
    }
}
void ManagerUI()
{
    int menu;
    system("cls");
    Rect(60, 40, 40, 4);
    Rect4(58, 2, 41, 5, "1.ȸ�� ���� 2.�¼�,�繰�� ���� 3.���� 4.����");
    Rect3(58, 2, 41, 7, "�޴� �Է� : ");
    gotoxy(77, 8);
    scanf("%d%*c", &menu);
    if (menu == 1)
    {
        Modify();
    }
    else if (menu == 2)
    {
        srsee();
    }
    else if (menu == 3)
    {
        Managersales();
    }
    else if (menu == 4)
    {
        First();
    }
    else
    {
        ManagerUI();
    }
}
void Modify()
{
    int line = 0;
    int line1 = 0;
    int key = 0;
    system("cls");
    Rect(64, 40, 1, 4);
    Rect(62, 32, 2, 11);
    Rect(64, 40, 70, 4);
    Rect(62, 32, 71, 11);
    Rect7(60, 2, 72, 12, "  �̸�   ����\t    ��ȭ��ȣ\t       �¼�  �繰��");
    Rect7(60, 2, 3, 12, "  �̸�   ����\t    ��ȭ��ȣ\t       �¼�  �繰��");
    Rect8(62, 2, 2, 5, "1.ȸ�� ���� ���� 2. �ڷΰ���");
    Rect9(62, 2, 2, 7, "�޴� �Է� : ");
    gotoxy(88, 10);
    printf("���� ������ ->(RIGHT), ���� ������ <-(LEFT)");

    for (int i = f_index; i <= count; i++) //y=15, 2�� ����
    {
        if (i >= f_index && i <= e_index) {
            gotoxy(5, line + 15 + (line + 1) * 2);
            printf("%s", join[i].name);
            gotoxy(13, line + 15 + (line + 1) * 2);
            printf("%s", join[i].gen);
            gotoxy(25, line + 15 + (line + 1) * 2);
            printf("%s", join[i].phone);
            gotoxy(47, line + 15 + (line + 1) * 2);
            if ((strcmp(join[i].gen, "����") == 0 || strcmp(join[i].gen, "��") == 0))
            {
                printf("%s", stime[i].seat);
            }
            else if ((strcmp(join[i].gen, "����") == 0 || strcmp(join[i].gen, "��") == 0))
            {
                printf("%s", stime[i].seat);
            }
            gotoxy(55, line + 15 + (line + 1) * 2);
            printf("%s", rtime[i].rock);
            line++;
        }
        if ((i >= f_index + 9) && (i <= e_index + 9)) {
            gotoxy(74, line1 + 15 + (line1 + 1) * 2);
            printf("%s", join[i].name);
            gotoxy(82, line1 + 15 + (line1 + 1) * 2);
            printf("%s", join[i].gen);
            gotoxy(94, line1 + 15 + (line1 + 1) * 2);
            printf("%s", join[i].phone);
            gotoxy(116, line1 + 15 + (line1 + 1) * 2);
            if ((strcmp(join[i].gen, "����") == 0 || strcmp(join[i].gen, "��") == 0))
            {
                printf("%s", stime[i].seat);
            }
            else if ((strcmp(join[i].gen, "����") == 0 || strcmp(join[i].gen, "��") == 0))
            {
                printf("%s", stime[i].seat);
            }
            gotoxy(124, line1 + 15 + (line1 + 1) * 2);
            printf("%s", rtime[i].rock);
            line1++;
        }
    }
    while (1) {
        if (_kbhit())
        {
            key = _getch();
            switch (key) {
            case 49:
                key = 0;
                system("cls");
                Modify1();
                break;
            case 50:
                key = 0;
                system("cls");
                ManagerUI();
                break;
            case LEFT:
                key = 0;
                f_index -= 18;
                e_index -= 18;
                Modify();
                break;
            case RIGHT:
                key = 0;
                f_index += 18;
                e_index += 18;
                Modify();
                break;
            }
        }
    }
}
void Modify1()
{
    int menu;
    char input_phone[15] = { "" };
    bool flag = false;
    system("cls");
    Rect(60, 40, 40, 4);
    Rect(58, 35, 41, 8);
    Rect4(58, 2, 41, 5, "ȸ�� ���� ����");
    gotoxy(45, 14);
    printf("��ȭ��ȣ : ");
    gotoxy(57, 14);
    scanf("%s%*c", input_phone);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(input_phone, join[i].phone) == 0)
        {
            flag = true;
            gotoxy(45, 17);
            printf("������ ���� : ");
            gotoxy(45, 19);
            printf("(1.�̸�, 2.��ȭ ��ȣ, 3.��й�ȣ)");
            gotoxy(59, 17);
            scanf("%d", &menu);
            if (menu == 1)
            {
                gotoxy(45, 23);
                printf("�̸� ����: ");
                gotoxy(56, 23);
                scanf("%s", join[i].name);
                file_member_write();
                Alarm("ȸ�� ���� ������ �Ϸ�Ǿ����ϴ�.");
                Modify();

            }
            else if (menu == 2)
            {
                gotoxy(45, 23);
                printf("��ȭ��ȣ ���� : ");
                gotoxy(62, 23);
                scanf("%s", join[i].phone);
                file_member_write();
                Alarm("ȸ�� ���� ������ �Ϸ�Ǿ����ϴ�.");
                Modify();
            }
            else if (menu == 3)
            {
                gotoxy(45, 23);
                printf("��й�ȣ ���� : ");
                gotoxy(62, 23);
                scanf("%s", join[i].pw);
                file_member_write();
                Alarm("ȸ�� ���� ������ �Ϸ�Ǿ����ϴ�.");
                Modify();
            }
            else if (menu == 12)
            {
                gotoxy(45, 23);
                printf("�̸� ����: ");
                gotoxy(56, 23);
                scanf("%s", join[i].name);
                gotoxy(45, 28);
                printf("��ȭ��ȣ ���� : ");
                gotoxy(62, 28);
                scanf("%s", join[i].phone);
                file_member_write();
                Alarm("������ �Ϸ�Ǿ����ϴ�.");
                Modify();
            }
            else if (menu == 13)
            {
                gotoxy(45, 23);
                printf("�̸� ����: ");
                gotoxy(56, 23);
                scanf("%s", join[i].name);
                gotoxy(45, 28);
                printf("��й�ȣ ���� : ");
                gotoxy(62, 28);
                scanf("%s", join[i].pw);
                file_member_write();
                Alarm("������ �Ϸ�Ǿ����ϴ�.");
                Modify();
            }
            else if (menu == 23)
            {
                gotoxy(45, 23);
                printf("��ȭ��ȣ ����: ");
                gotoxy(62, 23);
                scanf("%s", join[i].phone);
                gotoxy(45, 28);
                printf("��й�ȣ ���� : ");
                gotoxy(62, 28);
                scanf("%s", join[i].pw);
                file_member_write();
                Alarm("������ �Ϸ�Ǿ����ϴ�.");
                Modify();
            }
            else if (menu == 123)
            {
                gotoxy(45, 23);
                printf("�̸� ����: ");
                gotoxy(56, 23);
                scanf("%s", join[i].name);
                gotoxy(45, 28);
                printf("��ȭ��ȣ ���� : ");
                gotoxy(62, 28);
                scanf("%s", join[i].phone);
                gotoxy(45, 33);
                printf("��й�ȣ ���� : ");
                gotoxy(62, 33);
                scanf("%s", join[i].pw);
                file_member_write();
                Alarm("������ �Ϸ�Ǿ����ϴ�.");
                Modify();
            }
            else
            {
                Alarm("�ٽ� �Է��� �ּ���");
                Modify1();
            }
        }
    }
    if (flag == false)
    {
        Alarm("��ȭ��ȣ�� �ٽ� �Է��ϼ���");
        Modify1();
    }

}
void srsee()
{
    int menu;
    system("cls");
    Rect(60, 40, 40, 4);
    Rect1(58, 2, 41, 5, "1.�¼� Ȯ�� 2.�繰�� Ȯ�� 3.�ڷΰ���");
    Rect3(58, 2, 41, 7, "�޴� �Է� : ");
    gotoxy(77, 8);
    scanf("%d", &menu);
    if (menu == 1)
    {
        ssee();
    }
    else if (menu == 2)
    {
        rsee();
    }
    else if (menu == 3)
    {
        ManagerUI();
    }
}
void ssee()
{
    int menu1;

    system("cls");
    Rect(71, 30, 2, 8);
    Rect(69, 14, 3, 10);
    Rect6(69, 13, 3, 23);
    Seat1();
    MseatColor();
    GseatColor();
    Rect(60, 40, 75, 4);
    Rect1(58, 2, 76, 5, "1.�¼� Ȯ�� 2.�ڷΰ���");
    Rect3(58, 2, 76, 7, "�޴� �Է� : ");
    gotoxy(113, 8);
    scanf("%d", &menu1);
    if (menu1 == 1)
    {
        ssee1();
    }
    else if (menu1 == 2)
    {
        srsee();
    }
    else
    {
        ssee1();
    }
}
void ssee1()
{
    char input_gen[5] = { "" };
    char input_seat[5] = { "" };
    int temp = 0;
    char comp[3];
    int count_num = 0;
    int count_num1 = 0;
    gotoxy(80, 15);
    printf("���� or ���� : ");
    gotoxy(95, 15);
    scanf("%s", input_gen);
    gotoxy(80, 20);
    printf("�¼� ��ȣ �Է� : ");
    gotoxy(97, 20);
    scanf("%s", input_seat);
    for (int i = 0; i < count; i++)
    {
        if ((strcmp(input_gen, "����") == 0) || (strcmp(input_gen, "��") == 0))
        {
            if (strcmp(input_seat, stime[i].seat) == 0 && (strcmp(stime[i].gen, "����") == 0 || (strcmp(stime[i].gen, "��") == 0)))
            {
                temp = i;
                count_num++;
                break;
            }
        }
        else if ((strcmp(input_gen, "����") == 0) || (strcmp(input_gen, "��") == 0))
        {
            if (strcmp(input_seat, stime[i].seat) == 0 && (strcmp(stime[i].gen, "����") == 0 || (strcmp(stime[i].gen, "��") == 0)))
            {
                temp = i;
                count_num++;
                break;
            }
        }
        else {
            Alarm("������ �ٽ� �Է��ϼ���");
            ssee();
        }
    }
    if (count_num == 0)
    {
        Alarm("�¼���ȣ�� �ٽ� �Է��ϼ���");
        ssee();
    }
    gotoxy(80, 25);
    printf("ȸ�� �̸� : %s", join[temp].name);
    gotoxy(80, 30);
    printf("�¼� ���� �ð� : %d�� %d�� %d�� %d�� %d��", stime[temp].year, stime[temp].mon, stime[temp].day, stime[temp].hour, stime[temp].min);
    gotoxy(80, 35);
    printf("���� ����� ��Ű�ðڽ��ϱ�?(y/n) : ");
    gotoxy(114, 35);
    scanf("%s", comp);
    if ((strcmp(comp, "y") == 0) || (strcmp(comp, "Y") == 0))
    {
        Alarm("���� ����� �Ϸ�Ǿ����ϴ�.");
        if ((strcmp(join[temp].gen, "����") == 0) || (strcmp(join[temp].gen, "��") == 0))
        {
            strcpy(stime[temp].seat, "0");
            FILE* fp2 = fopen("Seattime.txt", "w");
            for (int i = 0; i < count; i++)
            {
                fprintf(fp2, "%s  ", stime[i].seat);
                fprintf(fp2, "%s  ", stime[i].gen);
                fprintf(fp2, "%d  ", stime[i].year);
                fprintf(fp2, "%d  ", stime[i].mon);
                fprintf(fp2, "%d  ", stime[i].day);
                fprintf(fp2, "%d  ", stime[i].hour);
                fprintf(fp2, "%d", stime[i].min);
                fprintf(fp2, "\n");
            }
            fclose(fp2);
        }
        else if ((strcmp(join[temp].gen, "����") == 0) || (strcmp(join[temp].gen, "��") == 0))
        {
            strcpy(stime[temp].seat, "0");
            FILE* fp2 = fopen("Seattime.txt", "w");
            for (int i = 0; i < count; i++)
            {
                fprintf(fp2, "%s  ", stime[i].seat);
                fprintf(fp2, "%s  ", stime[i].gen);
                fprintf(fp2, "%d  ", stime[i].year);
                fprintf(fp2, "%d  ", stime[i].mon);
                fprintf(fp2, "%d  ", stime[i].day);
                fprintf(fp2, "%d  ", stime[i].hour);
                fprintf(fp2, "%d", stime[i].min);
                fprintf(fp2, "\n");
            }
            fclose(fp2);
        }
        srsee();
    }
    else if ((strcmp(comp, "n") == 0) || (strcmp(comp, "N") == 0))
    {
        Alarm("���� ����� ����ϼ̽��ϴ�.");
        ssee();
    }
}
void rsee()
{
    int menu;
    system("cls");
    Rect(71, 30, 2, 8);
    Rect(69, 14, 3, 10);
    Rect6(69, 13, 3, 23);
    Rock();
    RockColor();
    Rect(60, 40, 75, 4);
    Rect1(58, 2, 76, 5, "1.�繰�� Ȯ�� 2.�ڷΰ���");
    Rect3(58, 2, 76, 7, "�޴� �Է� : ");
    gotoxy(113, 8);
    scanf("%d", &menu);
    if (menu == 1)
    {
        rsee1();
    }
    else if (menu == 2)
    {
        srsee();
    }
    else
    {
        rsee();
    }
}
void rsee1()
{
    char input_rock[5] = { "" };
    int temp = 0;
    char comp[3];
    int count_num = 0;

    gotoxy(80, 15);
    printf("�繰�� ��ȣ �Է� : ");
    gotoxy(100, 15);
    scanf("%s", input_rock);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(input_rock, rtime[i].rock) == 0)
        {
            temp = i;
            count_num++;
            break;
        }
    }
    if (count_num == 0)
    {
        Alarm("�繰�� ��ȣ�� �ٽ� �Է��ϼ���.");
        rsee();
    }
    gotoxy(80, 20);
    printf("ȸ�� �̸� : %s", join[temp].name);
    gotoxy(80, 25);
    printf("�¼� ���� �ð� : %d�� %d�� %d�� %d�� %d��", rtime[temp].year, rtime[temp].mon, rtime[temp].day, rtime[temp].hour, rtime[temp].min);
    gotoxy(80, 30);
    printf("�ٸ� �繰�� ������ ���ðڽ��ϱ�? (y/n) : ");
    gotoxy(122, 30);
    scanf("%s", &comp);
    if ((strcmp(comp, "y") == 0) || (strcmp(comp, "Y") == 0))
    {
        system("cls");
        rsee();
    }
    else if ((strcmp(comp, "n") == 0) || (strcmp(comp, "N") == 0))
    {
        Alarm("�繰�� Ȯ���� �����մϴ�.");
        ManagerUI();
    }
    else
    {
        rsee1();
    }
}
void Managersales()
{
    int menu;
    system("cls");
    Rect(60, 40, 40, 4);
    Rect1(58, 2, 41, 5, "1.�˻� 2.�׷��� 3.�ڷ� ����");
    Rect3(58, 2, 41, 7, "�޴� �Է� : ");
    gotoxy(77, 8);
    scanf("%d", &menu);
    if (menu == 1)
    {
        ssearch();
    }
    else if (menu == 2)
    {
        graph();
    }
    else if (menu == 3)
    {
        ManagerUI();
    }
}

void ssearch()
{
    int menu;
    system("cls");
    Rect(60, 40, 40, 4);
    Rect1(58, 2, 41, 5, "1.�Ⱓ �˻�  2.�ڷΰ���");
    Rect3(58, 2, 41, 7, "�޴� �Է� : ");
    gotoxy(77, 8);
    scanf("%d%*c", &menu);
    if (menu == 1)
    {
        ssearch1();

    }
    else if (menu == 2)
    {
        Managersales();
    }
    else {
        ssearch();
    }
}
void ssearch1()
{
    char menu[5];
    int input_year, input_year1;
    int input_month, input_month1;
    int input_day, input_day1;
    int ssum = 0, rsum = 0;
    system("cls");
    Rect(60, 40, 40, 4);
    Rect1(58, 2, 41, 5, "�� ����");
    gotoxy(47, 14);
    printf("���� ��¥ �Է� : ");
    scanf("%d %d %d", &input_year, &input_month, &input_day);
    gotoxy(47, 16);
    printf("���� ��¥ �Է� : ");
    scanf("%d %d %d", &input_year1, &input_month1, &input_day1);

    for (int i = 0; i < scount; i++) {
        if (input_year == input_year1) { //�⵵�� ������
            if ((sales[i].smon >= input_month) && (sales[i].smon <= input_month1)) {
                if ((sales[i].sday >= input_day) && (sales[i].sday <= input_day1)) {
                    ssum += sales[i].smoney;
                }
            }
        }
        else if (input_year != input_year1) {
            if ((sales[i].syear == input_year) && (sales[i].smon >= input_month) && (sales[i].sday >= input_day)) {
                ssum += sales[i].smoney;
            }
            if ((sales[i].syear > input_year) && (sales[i].syear <= input_year1)) {
                if ((sales[i].syear == input_year1) && (sales[i].smon == input_month1) && (sales[i].sday >= input_day1)) {
                    break;
                }
                ssum += sales[i].smoney;
            }
        }
    }
    for (int i = 0; i < scount; i++) {
        if (input_year == input_year1) { //�⵵�� ������
            if ((sales[i].rmon >= input_month) && (sales[i].rmon <= input_month1)) {
                if ((sales[i].rday >= input_day) && (sales[i].rday <= input_day1)) {
                    rsum += sales[i].rmoney;
                }
            }
        }
        else if (input_year != input_year1) {
            if ((sales[i].ryear == input_year) && (sales[i].rmon >= input_month) && (sales[i].rday >= input_day)) {
                rsum += sales[i].rmoney;
            }
            if ((sales[i].ryear > input_year) && (sales[i].ryear <= input_year1)) {
                if ((sales[i].ryear == input_year1) && (sales[i].rmon == input_month1) && (sales[i].rday >= input_day1)) {
                    break;
                }
                rsum += sales[i].rmoney;
            }
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    gotoxy(47, 20);
    printf("�¼� �̿�� �Ѿ� : %d��", ssum);
    gotoxy(47, 25);
    printf("�繰�� �̿�� �Ѿ� : %d��", rsum);
    gotoxy(47, 30);
    printf(" %d�� %d�� %d�� ~ %d�� %d�� %d�� ���� : %d��\n", input_year, input_month, input_day, input_year1, input_month1, input_day1, ssum + rsum);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    gotoxy(47, 35);
    printf("�ٸ� ��¥ ������ Ȯ���Ͻðڽ��ϱ�?(y/n) : ");
    gotoxy(88, 35);
    scanf("%s", &menu);
    if ((strcmp(menu, "y") == 0 || strcmp(menu, "Y") == 0))
    {
        ssearch1();
    }
    else if ((strcmp(menu, "n") == 0 || strcmp(menu, "N") == 0))
    {
        Alarm("���� Ȯ���� �����մϴ�.");
        Managersales();
    }
}
void graph()
{
    char menu[4] = { "" };
    time_t tt = time(NULL);
    struct tm tm = *localtime(&tt);
    int arrscore[5] = { 0 };
    int cnt = 5;
    for (int j = 0; j < cnt; j++)
    {
        int year = tm.tm_year + 1896 + j;
        for (int i = 0; i <= scount; i++)
        {
            if (year == sales[i].syear)
            {
                arrscore[j] += sales[i].smoney;
            }
            else if (year == sales[i].ryear)
            {
                arrscore[j] += sales[i].rmoney;
            }
        }
        arrscore[j] /= 100000;
    }
    system("cls");
    Rect(60, 40, 40, 4);
    Rect1(58, 2, 41, 5, "���� �׷���");
    gotoxy(52, 30);
    for (int i = 10; i > 0; i = i--) {
        gotoxy(52, 30 - i);
        printf("%3d ��", i * 10);  //5 �ڸ��� ���߱� �ִ� 10000000�� ���ڸ��̹Ƿ� 3d
        //i�� �ʸ����� ����, i�� �ʸ��� ���Ͽ� ������ ǥ�� 
        for (int j = 0; j < cnt; j++) {
            int  num = arrscore[j] / 10;  //i�� ���� ���ϱ� ���� ������ 10���� ������
            if (num >= i) {  //������ 10���� ���� ���� i���� ũ�ų� ���� ��
                if (num == i) { printf("  ���� "); }  //������ ������ ǥ���ϴ� ���� ��ȣ ���
                else { printf("  ���� "); }  //0���� ������ ������ ���� ��ȣ ���
            }
            else {
                printf("     ");
            }
        }
        printf("\n");
    }
    gotoxy(52, 30);
    printf("%3d ����", 0);  //0�� ǥ��
    for (int i = 0; i < cnt; i++) {
        if (arrscore[i] != 0) {  //0���� �ƴ� ������ �Էµ� �κп��� �������� ��ȣ�� ���
            printf("�������� ");
        }
        else {
            printf("����������");  //0���� �Էµ� �κп��� ���������� ��ȣ�� ���
        }
    }

    printf("\n");
    printf("      ");
    gotoxy(58, 32);
    for (int i = 18; i <= 22; i++) {
        printf(" %d��", i);
    }
    printf("\n");

    gotoxy(84, 20);
    printf("(���� : �ʸ�)");

    gotoxy(47, 15);
    printf("�׷��� Ȯ�� ����(y/n) : ");
    gotoxy(71, 15);
    scanf("%s", &menu);

    if ((strcmp(menu, "y") == 0 || strcmp(menu, "Y") == 0))
    {
        Alarm("���� ��踦 �����մϴ�.");
        Managersales();
    }
    else if ((strcmp(menu, "n") == 0 || strcmp(menu, "N") == 0))
    {
        graph();
    }
}
void Rect(int width, int height, int x, int y)
{
    goto_xy(x, y);
    for (int i = 0; i < width; i++)//ù ���� ���� �׸���
    {
        if (i == 0) printf("��");
        else if (i == width - 1) printf("��\n");
        else printf("��");
    }
    goto_xy(x, y + 1);
    for (int j = 0; j < height; j++)//���� ���� �׸���
    {
        printf("��");
        for (int k = 0; k < width - 2; k++)
        {
            printf(" ");
        }
        printf("��");
        goto_xy(x, y + (j + 1));
    }
    for (int l = 0; l < width; l++)//������ ���� ���� �׸���
    {
        if (l == 0) printf("��");
        else if (l == width - 1) printf("��\n");
        else printf("��");
    }
} //���
void Rect1(int width, int height, int x, int y, char* msg)
{
    goto_xy(x, y);
    for (int i = 0; i < width; i++)
    {
        if (i == 0) printf("��");
        else if (i == width - 1) printf("��\n");
        else printf("��");
    }
    goto_xy(x, y + 1);
    for (int j = 0; j < height; j++)
    {
        printf("��");
        for (int k = 0; k < width - 2; k++)
        {
            if (j == height / 2 && k == ((width)-strlen(msg)) / 2)
                printf("%s", msg);
            else printf(" ");
        }
        goto_xy(x + width - 1, y + 1); //���� ���� ������ �� �ϳ� �߰�(�����Ұ�)
        printf("��");
        goto_xy(x + width, y + 1); //�ٱ��� ���� ������ �� �ϳ� �߰�(�����Ұ�)
        printf("��");
        goto_xy(x + width - 1, y + 1);
        printf("��");
        goto_xy(x, y + (j + 1));

    }
    for (int l = 0; l < width; l++)
    {
        if (l == 0) printf("��");
        else if (l == width - 1) printf("��\n");
        else printf("��");
    }
    goto_xy(0, 50);
}
void Rect2(int width, int height, int x, int y, char* msg)
{
    goto_xy(x, y);
    for (int i = 0; i < width; i++)
    {
        if (i == 0) printf("��");
        else if (i == width - 1) printf("��\n");
        else printf("��");
    }
    goto_xy(x, y + 1);
    for (int j = 0; j < height; j++)
    {
        printf("��");
        for (int k = 0; k < width - 2; k++)
        {
            if (j == height / 2 && k == ((width)-strlen(msg)) / 2)
                printf("%s", msg);
            else printf(" ");
        }
        goto_xy(x + width - 1, y + 1); //���� ���� ������ �� �ϳ� �߰�(�����Ұ�)
        printf("��");
        goto_xy(x, y + (j + 1));
    }
    for (int l = 0; l < width; l++)
    {
        if (l == 0) printf("��");
        else if (l == width - 1) printf("��\n");
        else printf("��");
    }
}
void Rect3(int width, int height, int x, int y, char* msg)
{
    goto_xy(x, y);
    for (int i = 0; i < width; i++)
    {
        if (i == 0) printf("��");
        else if (i == width - 1) printf("��\n");
        else printf("��");
    }
    goto_xy(x, y + 1);
    for (int j = 0; j < height; j++)
    {
        printf("��");
        for (int k = 0; k < width - 2; k++)
        {
            if (j == height / 2 && k == ((width)-strlen(msg)) / 2)
                printf("%s", msg);
            else printf(" ");
        }
        goto_xy(x + width - 1, y + 1); //���� ���� ������ �� �ϳ� �߰�(�����Ұ�)
        printf("��");
        goto_xy(x + width, y + 1); //�ٱ��� ���� ������ �� �ϳ� �߰�(�����Ұ�);
        printf("��");
        goto_xy(x, y + (j + 1));
    }
    for (int l = 0; l < width; l++)
    {
        if (l == 0) printf("��");
        else if (l == width - 1) printf("��\n");
        else printf("��");
    }
    goto_xy(0, 40);
}
void Rect5(int width, int height, int x, int y, char* msg) //secoundUI Ʋ
{
    goto_xy(x, y);
    for (int i = 0; i < width; i++)
    {
        if (i == 0) printf("��");
        else if (i == width - 1) printf("��\n");
        else printf("��");
    }
    goto_xy(x, y + 1);
    for (int j = 0; j < height; j++)
    {
        printf("��");
        for (int k = 0; k < width - 2; k++)
        {
            if (j == height / 2 && k == ((width)-strlen(msg)) / 2)
                printf("%s", msg);
            else printf(" ");
        }
        goto_xy(x + width - 1, y + 1); //���� ���� ������ �� �ϳ� �߰�(�����Ұ�)
        printf("��");
        goto_xy(x + width - 1, y + 2); //�ٱ��� ���� ������ �� �ϳ� �߰�(�����Ұ�)
        printf("��");
        goto_xy(x, y + (j + 1));

    }
    for (int l = 0; l < width; l++)
    {
        if (l == 0) printf("��");
        else if (l == width - 1) printf("��\n");
        else printf("��");
    }
    goto_xy(0, 50);
}
void Rect4(int width, int height, int x, int y, char* msg) //secoundUI Ʋ
{
    goto_xy(x, y);
    for (int i = 0; i < width; i++)
    {
        if (i == 0) printf("��");
        else if (i == width - 1) printf("��\n");
        else printf("��");
    }
    goto_xy(x, y + 1);
    for (int j = 0; j < height; j++)
    {

        printf("��");
        for (int k = 0; k < width - 2; k++)
        {
            if (j == height / 2 && k == ((width)-strlen(msg)) / 2)
                printf("%s", msg);
            else printf(" ");
        }
        goto_xy(x + width, y + 1); //���� ���� ������ �� �ϳ� �߰�(�����Ұ�)
        printf("��");
        goto_xy(x + width - 1, y + 1);
        printf("��");
        goto_xy(x, y + (j + 1));

    }
    for (int l = 0; l < width; l++)
    {
        if (l == 0) printf("��");
        else if (l == width - 1) printf("��\n");
        else printf("��");
    }
    goto_xy(0, 40);
}
void Rect6(int width, int height, int x, int y) //�پ��ִ� 
{
    goto_xy(x, y);
    for (int i = 0; i < width; i++)//ù ���� ���� �׸���
    {
        if (i == 0) printf("��");
        else if (i == width - 1) printf("��\n");
        else printf("��");
    }
    goto_xy(x, y + 1);
    for (int j = 0; j < height; j++)//���� ���� �׸���
    {
        printf("��");
        for (int k = 0; k < width - 2; k++)
        {
            printf(" ");
        }
        printf("��");
        goto_xy(x, y + (j + 1));
    }
    for (int l = 0; l < width; l++)//������ ���� ���� �׸���
    {
        if (l == 0) printf("��");
        else if (l == width - 1) printf("��\n");
        else printf("��");
    }
    goto_xy(0, 50); //�ܼ�â ���� ��ǥ �̵�
}
void Rect7(int width, int height, int x, int y, char* msg) //secoundUI Ʋ
{
    goto_xy(x, y);
    for (int i = 0; i < width; i++)
    {
        if (i == 0) printf("��");
        else if (i == width - 1) printf("��\n");
        else printf("��");
    }
    goto_xy(x, y + 1);
    for (int j = 0; j < height; j++)
    {

        printf("��");
        printf("%s", msg);

        goto_xy(x + width, y + 1); //���� ���� ������ �� �ϳ� �߰�(�����Ұ�)
        printf("��");
        goto_xy(x + width - 1, y + 1);
        printf("��");
        goto_xy(x, y + (j + 1));

    }
    for (int l = 0; l < width; l++)
    {
        if (l == 0) printf("��");
        else if (l == width - 1) printf("��\n");
        else printf("��");
    }
    goto_xy(0, 40);
}
void Rect8(int width, int height, int x, int y, char* msg)
{
    goto_xy(x, y);
    for (int i = 0; i < width; i++)
    {
        if (i == 0) printf("��");
        else if (i == width - 1) printf("��\n");
        else printf("��");
    }
    goto_xy(x, y + 1);
    for (int j = 0; j < height; j++)
    {

        printf("��");
        for (int k = 0; k < width - 2; k++)
        {
            if (j == height / 2 && k == ((width)-strlen(msg)) / 2)
                printf("%s", msg);
            else printf(" ");
        }
        goto_xy(x + width, y + 1); //���� ���� ������ �� �ϳ� �߰�(�����Ұ�)
        printf("��");
        goto_xy(x + width - 1, y + 1);
        printf("��");
        goto_xy(x + width + 6, y + 1);
        printf("��");
        goto_xy(x, y + (j + 1));

    }
    for (int l = 0; l < width; l++)
    {
        if (l == 0) printf("��");
        else if (l == width - 1) printf("��\n");
        else printf("��");
    }
    goto_xy(0, 40);
}
void Rect9(int width, int height, int x, int y, char* msg)
{
    goto_xy(x, y);
    for (int i = 0; i < width; i++)
    {
        if (i == 0) printf("��");
        else if (i == width - 1) printf("��\n");
        else printf("��");
    }
    goto_xy(x, y + 1);
    for (int j = 0; j < height; j++)
    {
        printf("��");
        for (int k = 0; k < width - 2; k++)
        {
            if (j == height / 2 && k == ((width)-strlen(msg)) / 2)
                printf("%s", msg);
            else printf(" ");
        }
        goto_xy(x + width - 1, y + 1); //���� ���� ������ �� �ϳ� �߰�(�����Ұ�)
        printf("��");
        goto_xy(x + width, y + 1); //�ٱ��� ���� ������ �� �ϳ� �߰�(�����Ұ�);
        printf("��");
        goto_xy(x + width + 6, y + 1); //�ٱ��� ���� ������ �� �ϳ� �߰�(�����Ұ�);
        printf("��");
        goto_xy(x, y + (j + 1));
    }
    for (int l = 0; l < width; l++)
    {
        if (l == 0) printf("��");
        else if (l == width - 1) printf("��\n");
        else printf("��");
    }
    goto_xy(0, 40);
}
void goto_xy(int x, int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}
void gotoxy(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void file_member_read()
{
    FILE* fp = fopen("Member.txt", "r");
    if (fp == NULL)
        return 0;
    while (1) {
        fscanf(fp, "%s  ", join[count].name);
        fscanf(fp, "%s  ", join[count].pw);
        fscanf(fp, "%s  ", join[count].gen);
        fscanf(fp, "%s", join[count].phone);
        if (feof(fp) != 0)
            break;
        count++;
    }
    fclose(fp);
}
void file_seat_read()
{
    int i = 0;
    FILE* fp = fopen("Seattime.txt", "r");
    if (fp == NULL)
        return 0;
    while (1) {
        fscanf(fp, "%s  ", stime[i].seat);
        fscanf(fp, "%s  ", stime[i].gen);
        fscanf(fp, "%d  ", &stime[i].year);
        fscanf(fp, "%d  ", &stime[i].mon);
        fscanf(fp, "%d  ", &stime[i].day);
        fscanf(fp, "%d  ", &stime[i].hour);
        fscanf(fp, "%d", &stime[i].min);
        if (feof(fp) != 0)
            break;
        i++;

    }
    fclose(fp);
}
void file_rock_read()
{
    int i = 0;
    FILE* fp = fopen("Rock.txt", "r");
    if (fp == NULL)
        return 0;
    while (1) {
        fscanf(fp, "%s  ", &rtime[i].rock);
        fscanf(fp, "%d  ", &rtime[i].year);
        fscanf(fp, "%d  ", &rtime[i].mon);
        fscanf(fp, "%d  ", &rtime[i].day);
        fscanf(fp, "%d  ", &rtime[i].hour);
        fscanf(fp, "%d", &rtime[i].min);
        if (feof(fp) != 0)
            break;
        i++;

    }
    fclose(fp);
}
void file_member_write()
{
    FILE* fp2 = fopen("Member.txt", "w");
    for (int i = 0; i < count; i++)
    {
        fprintf(fp2, "%s  ", join[i].name);
        fprintf(fp2, "%s  ", join[i].pw);
        fprintf(fp2, "%s  ", join[i].gen);
        fprintf(fp2, "%s", join[i].phone);
        fprintf(fp2, "\n");
    }
    fclose(fp2);

    FILE* fp1 = fopen("Seattime.txt", "w");
    for (int i = 0; i < count; i++)
    {
        fprintf(fp1, "%s  ", stime[i].seat);
        fprintf(fp1, "%s  ", stime[i].gen);
        fprintf(fp1, "%d  ", stime[i].year);
        fprintf(fp1, "%d  ", stime[i].mon);
        fprintf(fp1, "%d  ", stime[i].day);
        fprintf(fp1, "%d  ", stime[i].hour);
        fprintf(fp1, "%d", stime[i].min);
        fprintf(fp1, "\n");
    }
    fclose(fp1);
}
void file_sales_append()
{
    FILE* fp = fopen("Sales.txt", "a");
    fprintf(fp, "%s  ", join[tmp].phone);
    fprintf(fp, "%d  ", sales[scount].smoney);
    fprintf(fp, "%d  ", sales[scount].syear);
    fprintf(fp, "%d  ", sales[scount].smon);
    fprintf(fp, "%d  /", sales[scount].sday);
    fprintf(fp, "  %d  ", sales[scount].rmoney);
    fprintf(fp, "%d  ", sales[scount].ryear);
    fprintf(fp, "%d  ", sales[scount].rmon);
    fprintf(fp, "%d", sales[scount].rday);
    fprintf(fp, "\n");
    scount++;
    fclose(fp);
}
void file_sales_read()
{
    int i = 0;
    FILE* fp = fopen("Sales.txt", "r");
    if (fp == NULL)
        return 0;
    while (1) {
        fscanf(fp, "%s  ", &sales[scount].phone);
        fscanf(fp, "%d  ", &sales[scount].smoney);
        fscanf(fp, "%d  ", &sales[scount].syear);
        fscanf(fp, "%d  ", &sales[scount].smon);
        fscanf(fp, "%d  /", &sales[scount].sday);
        fscanf(fp, "  %d  ", &sales[scount].rmoney);
        fscanf(fp, "%d  ", &sales[scount].ryear);
        fscanf(fp, "%d  ", &sales[scount].rmon);
        fscanf(fp, "%d", &sales[scount].rday);
        if (feof(fp) != 0)
            break;
        scount++;

    }
    fclose(fp);
}