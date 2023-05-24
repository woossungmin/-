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
#define TWO_SECOUND 2000 //2초 딜레이 

typedef struct
{
    char name[15]; //이름
    char pw[7]; //비밀번호
    char gen[10]; //성별
    char phone[20]; //핸드폰 번호
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
    char rock[4]; //사물함
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

char Manager_name[15] = { "관리자" };
char Manager_pw[7] = { "5" };
char Manager_phone[20] = { "5" };
int count = 0; //회원 전체 수
int scount = 0; //매출관련 카운트
int tmp; //현재 어떤 회원인지 로그인에서 i값을 저장함
int f_index = 0;
int e_index = 8;

void First(); //초기 UI함수
void goto_xy(int x, int y); //상자 위치 옮기는 함수
void gotoxy(int x, int y); //입력 커서 옮기는 함수
void Rect(int width, int height, int x, int y); //UI 틀이 되는 상자
void Rect1(int width, int height, int x, int y, char* msg);
void Rect2(int width, int height, int x, int y, char* msg);
void Rect3(int width, int height, int x, int y, char* msg); //윗상자와 바로 붙는 상자 
void Rect4(int width, int height, int x, int y, char* msg);
void Rect5(int width, int height, int x, int y, char* msg);
void Rect6(int width, int hetihgt, int x, int y); //사물함, 좌석 UI(안쪽 상자)
void Rect7(int width, int height, int x, int y, char* msg);
void Rect8(int width, int height, int x, int y, char* msg);
void Rect9(int width, int height, int x, int y, char* msg);
void Login(); //로그인 함수
void Membership(); //회원가입 함수
void Membership1();
void Findpw();
void Alarm(char* msg); //알림
void Secound(); //두번째UI
void Seat(); //좌석 UI
void Seat1(); //좌석 선택 창에서 좌석 보여줄 UI
void SeatUI();
void SeatCheck(); //좌석 선택 메뉴
void SeatTiket(); //이용권 구매 메뉴
void RockUI(); //메뉴3번사물함
void RockCheck(); //사물함 확인
void RockTiket(); //사물함 이용권 메뉴
void Rock(); //사물함 UI (어디가 차있는지 보여줄 함수)
void Tiket(); //좌석이용권살건지 사물함 이용권살건지
void Choice();
void SeatTimeCheck(); //좌석잔여시간이 남았는지 확인하는 함수
void RockTimeCheck();
void MseatColor(); //남자 좌석 색상바꾸기
void GseatColor(); //여자 좌석 생상바꾸기
void RockColor(); //사물함 색상 바꾸기
void entryroom(); //입실
void checkout(); //퇴실
void ManagerUI(); //관리자 시작 UI
void Modify(); // 회원 리스트 보여주는 곳
void Modify1(); //회원정보 수정하는 곳
void srsee(); //좌석 사물함 확인하는 함수
void ssee(); //관리자가 좌석 확인하는 함수
void ssee1(); //강제퇴실 기능 포함
void rsee(); //관리자가 사물함 확인
void rsee1(); //사물함사용하고있는 회원정보 확인
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
    Rect1(58, 2, 41, 5, "스터디 카페");
    Rect2(30, 2, 55, 19, "1. 로그인");
    Rect2(30, 2, 55, 22, "2. 회원 가입");
    Rect2(30, 2, 55, 25, "3. 비밀번호 찾기");
    Rect3(58, 2, 41, 7, "메뉴 입력 : ");
    gotoxy(78, 8);
    scanf("%d%*c", &input); //메뉴 입력

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
    int menu, count_num = 0; //등록된 회원 수
    member input; //로그인 할때 입력하는 구조체 변수
    system("cls");
    Rect(60, 40, 40, 4);
    Rect1(58, 2, 41, 5, "1.회원 로그인 2.관리자 로그인 3.뒤로가기");
    Rect3(58, 2, 41, 7, "메뉴 입력 : ");
    gotoxy(77, 8);
    scanf("%d", &menu);
    if (menu == 1)
    {
        gotoxy(47, 17);
        printf("전화번호 [ ex) 010-xxxx-xxxx ]");
        gotoxy(46, 19);
        printf(" : ");
        scanf("%s", input.phone);
        getchar();
        gotoxy(47, 24);
        printf("비밀번호 [ ex) 1234! (숫자4개 + !)]");
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
            Alarm("회원 로그인이 완료 되었습니다.");
            RockTimeCheck();
            SeatTimeCheck();
            Secound();
        }
        else if (count_num == 0) {
            system("cls");
            Alarm("회원 로그인을 실패 하셨습니다.");
            Login();
        }
    }
    else if (menu == 2)
    {
        gotoxy(47, 17);
        printf("전화번호 [ ex) 010-xxxx-xxxx ]");
        gotoxy(46, 19);
        printf(" : ");
        scanf("%s", input.phone);
        gotoxy(47, 24);
        printf("비밀번호 [ ex) 1234! (숫자4개 + !)]");
        gotoxy(46, 26);
        printf(" : ");
        scanf("%s", input.pw);
        goto_xy(0, 50);
        if ((strcmp(input.phone, Manager_phone) == 0) && (strcmp(input.pw, Manager_pw) == 0)) {
            Alarm("관리자 로그인이 완료 되었습니다.");
            ManagerUI();
        }
        else
        {
            Alarm("관리자 로그인을 실패 하셨습니다.");
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
    int i = 0; //등록된 사용자 수
    int j = 0, menu;

    system("cls");
    Rect(60, 40, 40, 4);
    Rect1(58, 2, 41, 5, "1.회원 가입  2.뒤로가기");
    Rect3(58, 2, 41, 7, "메뉴 입력 : ");
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
    Rect1(58, 2, 41, 5, "회원 가입");
    gotoxy(47, 14);
    printf("이름 [ ex) 홍길동 ] ");
    gotoxy(46, 16);
    printf(" : ");
    scanf("%s", input.name);
    if (strlen(input.name) >= 7)
    {
        Alarm("아이디 형식이 옳지 않습니다.");
        Membership1();
    }
    gotoxy(47, 20);
    printf("비밀번호 [ ex) 1234! (숫자4개 + !)]");
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
        Alarm("비밀번호 형식이 옳지 않습니다.");
        Membership1();
    }
    else if (strlen(input.pw) >= 6)
    {
        Alarm("비밀번호 형식이 옳지 않습니다.");
        Membership1();
    }
    gotoxy(47, 26);
    printf("성별 [ ex) 남 / 여 ] ");
    gotoxy(46, 28);
    printf(" : ");
    scanf("%s", input.gen);
    gotoxy(47, 32);
    if ((strstr(input.gen, "남자") != 0) || (strstr(input.gen, "남") != 0) || (strstr(input.gen, "여자") != 0) || (strstr(input.gen, "여") != 0))
    {
    }
    else
    {
        Alarm("성별 형식이 옳지 않습니다.");
        Membership1();
    }
    if (strlen(input.gen) >= 6)
    {
        Alarm("성별 형식이 옳지 않습니다.");
        Membership1();
    }
    printf("전화번호 [ ex) 010-xxxx-xxxx ]");
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
        Alarm("전화번호 형식이 옳지 않습니다.");
        Membership1();
    }
    else if (strlen(input.phone) >= 15)
    {
        Alarm("전화번호 형식이 옳지 않습니다.");
        Membership1();
    }
    system("cls");
    Alarm("회원가입이 완료되었습니다.");
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
    Rect1(58, 2, 41, 5, "1.비밀번호 찾기  2.뒤로가기");
    Rect3(58, 2, 41, 7, "메뉴 입력 : ");
    gotoxy(77, 8);
    scanf("%d%*c", &menu);
    if (menu == 1)
    {
        gotoxy(47, 17);
        printf("이름 [ ex) 홍길동 ] ");
        gotoxy(46, 19);
        printf(" : ");
        scanf("%s", input.name);
        gotoxy(47, 24);
        printf("전화번호 [ ex) 010-xxxx-xxxx ]");
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
                Rect1(58, 2, 41, 5, "비밀번호 찾기");
                gotoxy(59, 14);
                printf("비밀번호 : %s", join[j].pw);
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
    Rect1(58, 2, 41, 5, "스터디 카페");
    gotoxy(57, 14);
    printf("%s", msg);
    Sleep(TWO_SECOUND);
    system("cls");
}
void Seat1()
{
    //남성전용
    Rect5(5, 2, 6, 11, "A1"), Rect5(5, 2, 13, 11, "A2"), Rect5(5, 2, 20, 11, "A3"), Rect5(5, 2, 27, 11, "A4"), Rect5(5, 2, 34, 11, "A5");
    Rect5(5, 2, 41, 11, "A6"), Rect5(5, 2, 48, 11, "A7"), Rect5(5, 2, 55, 11, "A8"), Rect5(5, 2, 62, 11, "A9");
    Rect5(5, 2, 6, 14, "B1"), Rect5(5, 2, 13, 14, "B2"), Rect5(5, 2, 20, 14, "B3"), Rect5(5, 2, 27, 14, "B4"), Rect5(5, 2, 34, 14, "B5");
    Rect5(5, 2, 41, 14, "B6"), Rect5(5, 2, 48, 14, "B7"), Rect5(5, 2, 55, 14, "B8"), Rect5(5, 2, 62, 14, "B9");
    Rect5(5, 2, 6, 17, "C1"), Rect5(5, 2, 13, 17, "C2"), Rect5(5, 2, 20, 17, "C3"), Rect5(5, 2, 27, 17, "C4"), Rect5(5, 2, 34, 17, "C5");
    Rect5(5, 2, 41, 17, "C6"), Rect5(5, 2, 48, 17, "C7"), Rect5(5, 2, 55, 17, "C8"), Rect5(5, 2, 62, 17, "C9");
    Rect2(31, 2, 23, 20, "남성 전용");
    //여성전용
    Rect5(5, 2, 6, 24, "A1"), Rect5(5, 2, 13, 24, "A2"), Rect5(5, 2, 20, 24, "A3"), Rect5(5, 2, 27, 24, "A4"), Rect5(5, 2, 34, 24, "A5");
    Rect5(5, 2, 41, 24, "A6"), Rect5(5, 2, 48, 24, "A7"), Rect5(5, 2, 55, 24, "A8"), Rect5(5, 2, 62, 24, "A9");
    Rect5(5, 2, 6, 27, "B1"), Rect5(5, 2, 13, 27, "B2"), Rect5(5, 2, 20, 27, "B3"), Rect5(5, 2, 27, 27, "B4"), Rect5(5, 2, 34, 27, "B5");
    Rect5(5, 2, 41, 27, "B6"), Rect5(5, 2, 48, 27, "B7"), Rect5(5, 2, 55, 27, "B8"), Rect5(5, 2, 62, 27, "B9");
    Rect5(5, 2, 6, 30, "C1"), Rect5(5, 2, 13, 30, "C2"), Rect5(5, 2, 20, 30, "C3"), Rect5(5, 2, 27, 30, "C4"), Rect5(5, 2, 34, 30, "C5");
    Rect5(5, 2, 41, 30, "C6"), Rect5(5, 2, 48, 30, "C7"), Rect5(5, 2, 55, 30, "C8"), Rect5(5, 2, 62, 30, "C9");
    Rect2(31, 2, 23, 33, "여성 전용");

}
void SeatUI()
{
    int menu;
    system("cls");
    Rect(60, 40, 40, 4);

    Rect1(58, 2, 41, 5, "1.좌석 선택 2.좌석 이용권 구매 3.뒤로가기");
    Rect3(58, 2, 41, 7, "메뉴 입력 : ");
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
        Alarm("좌석 이용권을 구매하세요.");
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
        Rect1(58, 2, 76, 5, "좌석 선택");
    }


    gotoxy(80, 15);
    printf("%s 회원", join[tmp].gen);
    MseatColor();
    GseatColor();

    gotoxy(80, 20);
    printf("이름 : %s", join[tmp].name);
    gotoxy(80, 25);
    printf("만료 시간 : %d년 %d월 %d일 %d시 %d분 까지 사용 가능.", stime[tmp].year, stime[tmp].mon, stime[tmp].day, stime[tmp].hour, stime[tmp].min);
    gotoxy(80, 30);
    if (strcmp(stime[tmp].seat, "0") == 0)
    {
        printf("좌석 선택 : ");
        gotoxy(93, 30);
        scanf("%s%*c", input_seat);
        for (int i = 0; i < count; i++)
        {
            if ((strcmp(join[tmp].gen, "남자") == 0 || (strcmp(join[tmp].gen, "남") == 0)))
            {
                if (strcmp(input_seat, stime[i].seat) == 0 && (strcmp(stime[i].gen, "남자") == 0 || (strcmp(stime[i].gen, "남") == 0)))
                {
                    Alarm("비어있는 좌석이 아닙니다.");
                    SeatCheck();
                }
            }
            else if ((strcmp(join[tmp].gen, "여자") == 0 || (strcmp(join[tmp].gen, "여") == 0)))
            {
                if (strcmp(input_seat, stime[i].seat) == 0 && (strcmp(stime[i].gen, "여자") == 0 || (strcmp(stime[i].gen, "여") == 0)))
                {
                    Alarm("비어있는 좌석이 아닙니다.");
                    SeatCheck();
                }
            }
        }
    }
    else if (strcmp(stime[tmp].seat, "0") != 0)
    {
        char answer;
        printf("%s 좌석을 선택하셨습니다. 변경하시겠습니까?(y/n) : ", stime[tmp].seat);
        scanf("%c%*c", &answer);
        if ((answer == 'y') || (answer == 'Y'))
        {
            gotoxy(80, 35);
            printf("좌석 선택 : ");
            gotoxy(93, 35);
            scanf("%s%*c", input_seat);
            for (int i = 0; i < count; i++)
            {
                if ((strcmp(join[tmp].gen, "남자") == 0 || (strcmp(join[tmp].gen, "남") == 0)))
                {
                    if (strcmp(input_seat, stime[i].seat) == 0 && (strcmp(stime[i].gen, "남자") == 0 || (strcmp(stime[i].gen, "남") == 0)))
                    {
                        Alarm("비어있는 좌석이 아닙니다.");
                        SeatCheck();
                    }
                }
                else if ((strcmp(join[tmp].gen, "여자") == 0 || (strcmp(join[tmp].gen, "여") == 0)))
                {
                    if (strcmp(input_seat, stime[i].seat) == 0 && (strcmp(stime[i].gen, "여자") == 0 || (strcmp(stime[i].gen, "여") == 0)))
                    {
                        Alarm("비어있는 좌석이 아닙니다.");
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
        Alarm("좌석 선택이 완료되었습니다.");
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
    //현재 시간재는부분
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    //시간 파일 읽기
    int i = 0;
    int menu;
    char input[10];
    int day;
    system("cls");
    Rect(60, 40, 40, 4);

    Rect1(58, 2, 41, 5, "좌석 이용권 구매");
    gotoxy(77, 8);
    gotoxy(43, 13);
    printf("회원 이름 : %s", join[tmp].name);
    gotoxy(43, 16);
    if (stime[tmp].year == 0)
    {
        printf("잔여시간이 없습니다. 좌석 이용권을 구매해주세요.");
    }
    else {
        printf("%d년 %d월 %d일 %d시 %d분 까지 사용 가능합니다.", stime[tmp].year, stime[tmp].mon, stime[tmp].day, stime[tmp].hour, stime[tmp].min);
    }
    gotoxy(43, 19);
    printf("이용권 입력 : ");
    gotoxy(43, 24);
    printf("기간제");
    Rect5(15, 2, 43, 25, "7D 40000원"), Rect5(15, 2, 58, 25, "15D 80000원"), Rect5(15, 2, 73, 25, "30D 150000원");
    gotoxy(43, 34);
    printf("시간제");
    Rect5(15, 2, 43, 35, "6H 2000원"), Rect5(15, 2, 58, 35, "12H 8000원"), Rect5(15, 2, 73, 35, "24H 10000원");
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
        Alarm("이용권 구매가 완료되었습니다.");
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
        Alarm("이용권 구매가 완료되었습니다.");
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
        Alarm("이용권 구매가 완료되었습니다.");
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
        Alarm("이용권 구매가 완료되었습니다.");
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
        Alarm("이용권 구매가 완료되었습니다.");
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
        Alarm("이용권 구매가 완료되었습니다.");
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

    Rect1(58, 2, 41, 5, "1.사물함 선택 2.사물함 이용권 구매 3.종료");
    Rect3(58, 2, 41, 7, "메뉴 입력 : ");
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
    Rect2(31, 2, 23, 20, "사물함 1");

    Rect5(5, 2, 6, 24, "D1"), Rect5(5, 2, 13, 24, "D2"), Rect5(5, 2, 20, 24, "D3"), Rect5(5, 2, 27, 24, "D4"), Rect5(5, 2, 34, 24, "D5");
    Rect5(5, 2, 41, 24, "D6"), Rect5(5, 2, 48, 24, "D7"), Rect5(5, 2, 55, 24, "D8"), Rect5(5, 2, 62, 24, "D9");
    Rect5(5, 2, 6, 27, "E1"), Rect5(5, 2, 13, 27, "E2"), Rect5(5, 2, 20, 27, "E3"), Rect5(5, 2, 27, 27, "E4"), Rect5(5, 2, 34, 27, "E5");
    Rect5(5, 2, 41, 27, "E6"), Rect5(5, 2, 48, 27, "E7"), Rect5(5, 2, 55, 27, "E8"), Rect5(5, 2, 62, 27, "E9");
    Rect5(5, 2, 6, 30, "F1"), Rect5(5, 2, 13, 30, "F2"), Rect5(5, 2, 20, 30, "F3"), Rect5(5, 2, 27, 30, "F4"), Rect5(5, 2, 34, 30, "F5");
    Rect5(5, 2, 41, 30, "F6"), Rect5(5, 2, 48, 30, "F7"), Rect5(5, 2, 55, 30, "F8"), Rect5(5, 2, 62, 30, "F9");
    Rect2(31, 2, 23, 33, "사물함 2");
}
void RockCheck()
{
    char input_rock[4] = "0";
    int i = 0;
    if (rtime[tmp].year == 0)
    {
        system("cls");
        Alarm("사물함 이용권을 구매하세요.");
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
        Rect1(58, 2, 76, 5, "사물함 선택");

        if (strcmp(join[tmp].gen, "남자") == 0 || strcmp(join[tmp].gen, "남") == 0)
        {
            gotoxy(80, 15);
            printf("남성 회원");
        }
        else if (strcmp(join[tmp].gen, "여자") == 0 || strcmp(join[tmp].gen, "여") == 0)
        {
            gotoxy(80, 15);
            printf("여성 회원");
        }
        RockColor();
        gotoxy(80, 20);
        printf("이름 : %s", join[tmp].name);
        gotoxy(80, 25);
        printf("만료 시간 : %d년 %d월 %d일 %d시 %d분 까지 사용 가능", rtime[tmp].year, rtime[tmp].mon, rtime[tmp].day, rtime[tmp].hour, rtime[tmp].min);
        gotoxy(80, 30);
        if (strcmp(rtime[tmp].rock, "0") != 0)
        {
            char answer;
            printf("%s 사물함을 선택하셨습니다. 변경하시겠습니까?(y/n) : ", rtime[tmp].rock);
            scanf("%c%*c", &answer);
            if ((answer == 'y') || (answer == 'Y'))
            {
                gotoxy(80, 35);
                printf("사물함 선택 : ");
                gotoxy(94, 35);
                scanf("%s", input_rock);
                for (i = 0; i < SIZE; i++)
                {
                    if (strcmp(input_rock, rtime[i].rock) == 0)
                    {
                        Alarm("비어있는 사물함이 아닙니다.");
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
            printf("사물함 선택 : ");
            gotoxy(94, 30);
            scanf("%s", input_rock);
            for (i = 0; i < SIZE; i++)
            {
                if (strcmp(input_rock, rtime[i].rock) == 0)
                {
                    Alarm("비어있는 사물함이 아닙니다.");
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
            Alarm("사물함 선택이 완료되었습니다.");
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

    Rect1(58, 2, 41, 5, "사물함 이용권 구매");
    gotoxy(77, 8);
    gotoxy(43, 13);
    printf("회원 이름 : %s", join[tmp].name);
    gotoxy(43, 16);
    if (rtime[tmp].year == 0)
    {
        printf("잔여시간이 없습니다. 사물함 이용권을 구매해주세요.");
    }
    else {
        printf("%d년 %d월 %d일 %d시 %d분 까지 사용 가능합니다.", rtime[tmp].year, rtime[tmp].mon, rtime[tmp].day, rtime[tmp].hour, rtime[tmp].min);
    }
    gotoxy(43, 19);
    printf("이용권 입력 : ");
    gotoxy(43, 24);
    printf("기간제");
    Rect5(15, 2, 43, 25, "7D 40000원"), Rect5(15, 2, 58, 25, "15D 80000원"), Rect5(15, 2, 73, 25, "30D 150000원");
    gotoxy(43, 34);
    printf("시간제");
    Rect5(15, 2, 43, 35, "6H 2000원"), Rect5(15, 2, 58, 35, "12H 8000원"), Rect5(15, 2, 73, 35, "24H 10000원");
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
        Alarm("이용권 구매가 완료되었습니다.");
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
        Alarm("이용권 구매가 완료되었습니다.");
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
        Alarm("이용권 구매가 완료되었습니다.");
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
        Alarm("이용권 구매가 완료되었습니다.");
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
        Alarm("이용권 구매가 완료되었습니다.");
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
        Alarm("이용권 구매가 완료되었습니다.");
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

    Rect1(58, 2, 41, 5, "1.이용권 2.자리선택 3.퇴실 4.뒤로가기");
    Rect3(58, 2, 41, 7, "메뉴 입력 : ");
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

    Rect1(58, 2, 41, 5, "1.좌석 이용권 2.사물함 이용권 3.뒤로가기");
    Rect3(58, 2, 41, 7, "메뉴 입력 : ");
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

    Rect1(58, 2, 41, 5, "1.좌석 선택 2.사물함 선택 3.뒤로가기");
    Rect3(58, 2, 41, 7, "메뉴 입력 : ");
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

    if ((strcmp(join[tmp].gen, "남자") == 0) || (strcmp(join[tmp].gen, "남") == 0))
    {
        if (tm.tm_year + 1900 > stime[tmp].year) //년도가 넘었을경우 무조건 날짜가 지남
        {
            strcpy(stime[tmp].seat, "0");
            strcpy(stime[tmp].gen, "남자");
            stime[tmp].year = 0;
            stime[tmp].mon = 0;
            stime[tmp].day = 0;
            stime[tmp].hour = 0;
            stime[tmp].min = 0;
        }
        else if ((tm.tm_year + 1900 == stime[tmp].year) && (tm.tm_mon + 1 > stime[tmp].mon)) //년도는 같지만 월이 넘었을 경우 무조건 날짜가 지남
        {
            strcpy(stime[tmp].seat, "0");
            strcpy(stime[tmp].gen, "남자");
            stime[tmp].year = 0;
            stime[tmp].mon = 0;
            stime[tmp].day = 0;
            stime[tmp].hour = 0;
            stime[tmp].min = 0;
        }
        else if ((tm.tm_year + 1900 == stime[tmp].year) && (tm.tm_mon + 1 == stime[tmp].mon) && (tm.tm_mday > stime[tmp].day)) //년도와 월은 같지만 일이 넘었을 경우 무조건 날짜가 지남
        {
            strcpy(stime[tmp].seat, "0");
            strcpy(stime[tmp].gen, "남자");
            stime[tmp].year = 0;
            stime[tmp].mon = 0;
            stime[tmp].day = 0;
            stime[tmp].hour = 0;
            stime[tmp].min = 0;
        }
        else if ((tm.tm_year + 1900 == stime[tmp].year) && (tm.tm_mon + 1 == stime[tmp].mon) && (tm.tm_mday == stime[tmp].day) && (tm.tm_hour > stime[tmp].hour)) //년,월,일은 같지만 시간이 넘으면 지남
        {
            strcpy(stime[tmp].seat, "0");
            strcpy(stime[tmp].gen, "남자");
            stime[tmp].year = 0;
            stime[tmp].mon = 0;
            stime[tmp].day = 0;
            stime[tmp].hour = 0;
            stime[tmp].min = 0;
        }
        else if ((tm.tm_year + 1900 == stime[tmp].year) && (tm.tm_mon + 1 == stime[tmp].mon) && (tm.tm_mday == stime[tmp].day) && (tm.tm_hour > stime[tmp].hour) && (tm.tm_min > stime[tmp].min)) //년,월,일, 시는 같지만 분이 넘으면 지남
        {
            strcpy(stime[tmp].seat, "0");
            strcpy(stime[tmp].gen, "남자");
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
    else if ((strcmp(join[tmp].gen, "여자") == 0) || (strcmp(join[tmp].gen, "여") == 0))
    {
        if (tm.tm_year + 1900 > stime[tmp].year) //년도가 넘었을경우 무조건 날짜가 지남
        {
            strcpy(stime[tmp].seat, "0");
            strcpy(stime[tmp].gen, "여자");
            stime[tmp].year = 0;
            stime[tmp].mon = 0;
            stime[tmp].day = 0;
            stime[tmp].hour = 0;
            stime[tmp].min = 0;
        }
        else if ((tm.tm_year + 1900 == stime[tmp].year) && (tm.tm_mon + 1 > stime[tmp].mon)) //년도는 같지만 월이 넘었을 경우 무조건 날짜가 지남
        {
            strcpy(stime[tmp].seat, "0");
            strcpy(stime[tmp].gen, "여자");
            stime[tmp].year = 0;
            stime[tmp].mon = 0;
            stime[tmp].day = 0;
            stime[tmp].hour = 0;
            stime[tmp].min = 0;
        }
        else if ((tm.tm_year + 1900 == stime[tmp].year) && (tm.tm_mon + 1 == stime[tmp].mon) && (tm.tm_mday > stime[tmp].day)) //년도와 월은 같지만 일이 넘었을 경우 무조건 날짜가 지남
        {
            strcpy(stime[tmp].seat, "0");
            strcpy(stime[tmp].gen, "여자");
            stime[tmp].year = 0;
            stime[tmp].mon = 0;
            stime[tmp].day = 0;
            stime[tmp].hour = 0;
            stime[tmp].min = 0;
        }
        else if ((tm.tm_year + 1900 == stime[tmp].year) && (tm.tm_mon + 1 == stime[tmp].mon) && (tm.tm_mday == stime[tmp].day) && (tm.tm_hour > stime[tmp].hour)) //년,월,일은 같지만 시간이 넘으면 지남
        {
            strcpy(stime[tmp].seat, "0");
            strcpy(stime[tmp].gen, "여자");
            stime[tmp].year = 0;
            stime[tmp].mon = 0;
            stime[tmp].day = 0;
            stime[tmp].hour = 0;
            stime[tmp].min = 0;
        }
        else if ((tm.tm_year + 1900 == stime[tmp].year) && (tm.tm_mon + 1 == stime[tmp].mon) && (tm.tm_mday == stime[tmp].day) && (tm.tm_hour > stime[tmp].hour) && (tm.tm_min > stime[tmp].min)) //년,월,일, 시는 같지만 분이 넘으면 지남
        {
            strcpy(stime[tmp].seat, "0");
            strcpy(stime[tmp].gen, "여자");
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
    if (tm.tm_year + 1900 > rtime[tmp].year) //년도가 넘었을경우 무조건 날짜가 지남
    {
        strcpy(rtime[tmp].rock, "0");
        rtime[tmp].year = 0;
        rtime[tmp].mon = 0;
        rtime[tmp].day = 0;
        rtime[tmp].hour = 0;
        rtime[tmp].min = 0;
    }
    if ((tm.tm_year + 1900 == rtime[tmp].year) && (tm.tm_mon + 1 > rtime[tmp].mon)) //년도는 같지만 월이 넘었을 경우 무조건 날짜가 지남
    {
        strcpy(rtime[tmp].rock, "0");
        rtime[tmp].year = 0;
        rtime[tmp].mon = 0;
        rtime[tmp].day = 0;
        rtime[tmp].hour = 0;
        rtime[tmp].min = 0;
    }
    else if ((tm.tm_year + 1900 == rtime[tmp].year) && (tm.tm_mon + 1 == rtime[tmp].mon) && (tm.tm_mday > rtime[tmp].day)) //년도와 월은 같지만 일이 넘었을 경우 무조건 날짜가 지남
    {
        strcpy(rtime[tmp].rock, "0");
        rtime[tmp].year = 0;
        rtime[tmp].mon = 0;
        rtime[tmp].day = 0;
        rtime[tmp].hour = 0;
        rtime[tmp].min = 0;
    }
    else if ((tm.tm_year + 1900 == rtime[tmp].year) && (tm.tm_mon + 1 == rtime[tmp].mon) && (tm.tm_mday == rtime[tmp].day) && (tm.tm_hour > rtime[tmp].hour)) //년,월,일은 같지만 시간이 넘으면 지남
    {
        strcpy(rtime[tmp].rock, "0");
        rtime[tmp].year = 0;
        rtime[tmp].mon = 0;
        rtime[tmp].day = 0;
        rtime[tmp].hour = 0;
        rtime[tmp].min = 0;
    }
    else if ((tm.tm_year + 1900 == rtime[tmp].year) && (tm.tm_mon + 1 == rtime[tmp].mon) && (tm.tm_mday == rtime[tmp].day) && (tm.tm_hour == rtime[tmp].hour) && (tm.tm_min > rtime[tmp].min)) //년,월,일,시는 같지만 분이 넘으면 시간이 지남
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
        if ((strcmp(join[i].gen, "남자") == 0) || (strcmp(join[i].gen, "남") == 0))
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
        if ((strcmp(join[i].gen, "여자") == 0) || (strcmp(join[i].gen, "여") == 0)) {
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
    Rect1(58, 2, 41, 5, "입실");
    if ((strcmp(join[tmp].gen, "남자") == 0) || (strcmp(join[tmp].gen, "남") == 0))
    {
        gotoxy(45, 13);
        printf("남성 회원");
        gotoxy(45, 18);
        printf("회원 이름 : %s", join[tmp].name);
        gotoxy(45, 23);
        printf("좌석 번호 : %s", stime[tmp].seat);
        gotoxy(45, 28);
        printf("만료 시간 : %d년 %d월 %d일 %d시 %d분 까지 사용 가능.", stime[tmp].year, stime[tmp].mon, stime[tmp].day, stime[tmp].hour, stime[tmp].min);
        gotoxy(45, 33);
        printf("입실하시겠습니까?(y/n) : ");
        gotoxy(70, 33);
        scanf("%s", &input);
        if ((input == 'y') || (input == 'y'))
        {
            Alarm("입실이 완료되었습니다!");
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
            Alarm("입실이 취소되었습니다!");
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
            Alarm("다시 입력해주세요!");
            entryroom();
        }
    }
    else if ((strcmp(join[tmp].gen, "여자") == 0) || (strcmp(join[tmp].gen, "여") == 0))
    {
        gotoxy(45, 13);
        printf("여성 회원");
        gotoxy(45, 18);
        printf("회원 이름 : %s", join[tmp].name);
        gotoxy(45, 23);
        printf("좌석 번호 : %s", stime[tmp].seat);
        gotoxy(45, 28);
        printf("만료 시간 : %d년 %d월 %d일 %d시 %d분 까지 사용 가능.", stime[tmp].year, stime[tmp].mon, stime[tmp].day, stime[tmp].hour, stime[tmp].min);
        gotoxy(45, 33);
        printf("입실하시겠습니까?(y/n) : ");
        gotoxy(70, 33);
        scanf("%c", &input);
        if ((input == 'y') || (input == 'Y'))
        {
            Alarm("입실이 완료되었습니다!");
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
            Alarm("입실이 취소되었습니다!");
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
            Alarm("다시 입력해주세요!");
            entryroom();
        }
    }
}
void checkout()
{
    char input;
    system("cls");
    Rect(60, 40, 40, 4);
    Rect1(58, 2, 41, 5, "퇴실");
    if ((strcmp(join[tmp].gen, "남자") == 0) || (strcmp(join[tmp].gen, "남") == 0))
    {
        gotoxy(45, 13);
        printf("남성 회원");
        gotoxy(45, 18);
        printf("회원 이름 : %s", join[tmp].name);
        gotoxy(45, 23);
        printf("좌석 번호 : %s", stime[tmp].seat);
        gotoxy(45, 28);
        printf("만료 시간 : %d년 %d월 %d일 %d시 %d분 까지 사용 가능.", stime[tmp].year, stime[tmp].mon, stime[tmp].day, stime[tmp].hour, stime[tmp].min);
        gotoxy(45, 33);
        printf("퇴실하시겠습니까?(y/n) : ");
        gotoxy(70, 33);
        scanf("%s", &input);
        if ((input == 'y') || (input == 'y'))
        {
            Alarm("퇴실이 완료되었습니다!");
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
            Alarm("퇴실이 취소되었습니다!");
            Secound();
        }
        else
        {
            Alarm("다시 입력해주세요!");
            checkout();
        }
    }
    else if ((strcmp(join[tmp].gen, "여자") == 0) || (strcmp(join[tmp].gen, "여") == 0))
    {
        gotoxy(45, 13);
        printf("여성 회원");
        gotoxy(45, 18);
        printf("회원 이름 : %s", join[tmp].name);
        gotoxy(45, 23);
        printf("좌석 번호 : %s", stime[tmp].seat);
        gotoxy(45, 28);
        printf("만료 시간 : %d년 %d월 %d일 %d시 %d분 까지 사용 가능.", stime[tmp].year, stime[tmp].mon, stime[tmp].day, stime[tmp].hour, stime[tmp].min);
        gotoxy(45, 33);
        printf("퇴실하시겠습니까?(y/n) : ");
        gotoxy(70, 33);
        scanf("%s", &input);
        if ((input == 'y') || (input == 'y'))
        {
            Alarm("퇴실이 완료되었습니다!");
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
            Alarm("퇴실이 취소되었습니다!");
            Secound();
        }
        else
        {
            Alarm("다시 입력해주세요!");
            checkout();
        }
    }
}
void ManagerUI()
{
    int menu;
    system("cls");
    Rect(60, 40, 40, 4);
    Rect4(58, 2, 41, 5, "1.회원 정보 2.좌석,사물함 관리 3.매출 4.종료");
    Rect3(58, 2, 41, 7, "메뉴 입력 : ");
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
    Rect7(60, 2, 72, 12, "  이름   성별\t    전화번호\t       좌석  사물함");
    Rect7(60, 2, 3, 12, "  이름   성별\t    전화번호\t       좌석  사물함");
    Rect8(62, 2, 2, 5, "1.회원 정보 수정 2. 뒤로가기");
    Rect9(62, 2, 2, 7, "메뉴 입력 : ");
    gotoxy(88, 10);
    printf("다음 페이지 ->(RIGHT), 이전 페이지 <-(LEFT)");

    for (int i = f_index; i <= count; i++) //y=15, 2씩 증가
    {
        if (i >= f_index && i <= e_index) {
            gotoxy(5, line + 15 + (line + 1) * 2);
            printf("%s", join[i].name);
            gotoxy(13, line + 15 + (line + 1) * 2);
            printf("%s", join[i].gen);
            gotoxy(25, line + 15 + (line + 1) * 2);
            printf("%s", join[i].phone);
            gotoxy(47, line + 15 + (line + 1) * 2);
            if ((strcmp(join[i].gen, "남자") == 0 || strcmp(join[i].gen, "남") == 0))
            {
                printf("%s", stime[i].seat);
            }
            else if ((strcmp(join[i].gen, "여자") == 0 || strcmp(join[i].gen, "여") == 0))
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
            if ((strcmp(join[i].gen, "남자") == 0 || strcmp(join[i].gen, "남") == 0))
            {
                printf("%s", stime[i].seat);
            }
            else if ((strcmp(join[i].gen, "여자") == 0 || strcmp(join[i].gen, "여") == 0))
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
    Rect4(58, 2, 41, 5, "회원 정보 수정");
    gotoxy(45, 14);
    printf("전화번호 : ");
    gotoxy(57, 14);
    scanf("%s%*c", input_phone);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(input_phone, join[i].phone) == 0)
        {
            flag = true;
            gotoxy(45, 17);
            printf("수정할 정보 : ");
            gotoxy(45, 19);
            printf("(1.이름, 2.전화 번호, 3.비밀번호)");
            gotoxy(59, 17);
            scanf("%d", &menu);
            if (menu == 1)
            {
                gotoxy(45, 23);
                printf("이름 수정: ");
                gotoxy(56, 23);
                scanf("%s", join[i].name);
                file_member_write();
                Alarm("회원 정보 수정이 완료되었습니다.");
                Modify();

            }
            else if (menu == 2)
            {
                gotoxy(45, 23);
                printf("전화번호 수정 : ");
                gotoxy(62, 23);
                scanf("%s", join[i].phone);
                file_member_write();
                Alarm("회원 정보 수정이 완료되었습니다.");
                Modify();
            }
            else if (menu == 3)
            {
                gotoxy(45, 23);
                printf("비밀번호 수정 : ");
                gotoxy(62, 23);
                scanf("%s", join[i].pw);
                file_member_write();
                Alarm("회원 정보 수정이 완료되었습니다.");
                Modify();
            }
            else if (menu == 12)
            {
                gotoxy(45, 23);
                printf("이름 수정: ");
                gotoxy(56, 23);
                scanf("%s", join[i].name);
                gotoxy(45, 28);
                printf("전화번호 수정 : ");
                gotoxy(62, 28);
                scanf("%s", join[i].phone);
                file_member_write();
                Alarm("수정이 완료되었습니다.");
                Modify();
            }
            else if (menu == 13)
            {
                gotoxy(45, 23);
                printf("이름 수정: ");
                gotoxy(56, 23);
                scanf("%s", join[i].name);
                gotoxy(45, 28);
                printf("비밀번호 수정 : ");
                gotoxy(62, 28);
                scanf("%s", join[i].pw);
                file_member_write();
                Alarm("수정이 완료되었습니다.");
                Modify();
            }
            else if (menu == 23)
            {
                gotoxy(45, 23);
                printf("전화번호 수정: ");
                gotoxy(62, 23);
                scanf("%s", join[i].phone);
                gotoxy(45, 28);
                printf("비밀번호 수정 : ");
                gotoxy(62, 28);
                scanf("%s", join[i].pw);
                file_member_write();
                Alarm("수정이 완료되었습니다.");
                Modify();
            }
            else if (menu == 123)
            {
                gotoxy(45, 23);
                printf("이름 수정: ");
                gotoxy(56, 23);
                scanf("%s", join[i].name);
                gotoxy(45, 28);
                printf("전화번호 수정 : ");
                gotoxy(62, 28);
                scanf("%s", join[i].phone);
                gotoxy(45, 33);
                printf("비밀번호 수정 : ");
                gotoxy(62, 33);
                scanf("%s", join[i].pw);
                file_member_write();
                Alarm("수정이 완료되었습니다.");
                Modify();
            }
            else
            {
                Alarm("다시 입력해 주세요");
                Modify1();
            }
        }
    }
    if (flag == false)
    {
        Alarm("전화번호를 다시 입력하세요");
        Modify1();
    }

}
void srsee()
{
    int menu;
    system("cls");
    Rect(60, 40, 40, 4);
    Rect1(58, 2, 41, 5, "1.좌석 확인 2.사물함 확인 3.뒤로가기");
    Rect3(58, 2, 41, 7, "메뉴 입력 : ");
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
    Rect1(58, 2, 76, 5, "1.좌석 확인 2.뒤로가기");
    Rect3(58, 2, 76, 7, "메뉴 입력 : ");
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
    printf("남자 or 여자 : ");
    gotoxy(95, 15);
    scanf("%s", input_gen);
    gotoxy(80, 20);
    printf("좌석 번호 입력 : ");
    gotoxy(97, 20);
    scanf("%s", input_seat);
    for (int i = 0; i < count; i++)
    {
        if ((strcmp(input_gen, "남자") == 0) || (strcmp(input_gen, "남") == 0))
        {
            if (strcmp(input_seat, stime[i].seat) == 0 && (strcmp(stime[i].gen, "남자") == 0 || (strcmp(stime[i].gen, "남") == 0)))
            {
                temp = i;
                count_num++;
                break;
            }
        }
        else if ((strcmp(input_gen, "여자") == 0) || (strcmp(input_gen, "여") == 0))
        {
            if (strcmp(input_seat, stime[i].seat) == 0 && (strcmp(stime[i].gen, "여자") == 0 || (strcmp(stime[i].gen, "여") == 0)))
            {
                temp = i;
                count_num++;
                break;
            }
        }
        else {
            Alarm("성별을 다시 입력하세요");
            ssee();
        }
    }
    if (count_num == 0)
    {
        Alarm("좌석번호를 다시 입력하세요");
        ssee();
    }
    gotoxy(80, 25);
    printf("회원 이름 : %s", join[temp].name);
    gotoxy(80, 30);
    printf("좌석 만료 시간 : %d년 %d월 %d일 %d시 %d분", stime[temp].year, stime[temp].mon, stime[temp].day, stime[temp].hour, stime[temp].min);
    gotoxy(80, 35);
    printf("강제 퇴실을 시키시겠습니까?(y/n) : ");
    gotoxy(114, 35);
    scanf("%s", comp);
    if ((strcmp(comp, "y") == 0) || (strcmp(comp, "Y") == 0))
    {
        Alarm("강제 퇴실이 완료되었습니다.");
        if ((strcmp(join[temp].gen, "남자") == 0) || (strcmp(join[temp].gen, "남") == 0))
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
        else if ((strcmp(join[temp].gen, "여자") == 0) || (strcmp(join[temp].gen, "여") == 0))
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
        Alarm("강제 퇴실을 취소하셨습니다.");
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
    Rect1(58, 2, 76, 5, "1.사물함 확인 2.뒤로가기");
    Rect3(58, 2, 76, 7, "메뉴 입력 : ");
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
    printf("사물함 번호 입력 : ");
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
        Alarm("사물함 번호를 다시 입력하세요.");
        rsee();
    }
    gotoxy(80, 20);
    printf("회원 이름 : %s", join[temp].name);
    gotoxy(80, 25);
    printf("좌석 만료 시간 : %d년 %d월 %d일 %d시 %d분", rtime[temp].year, rtime[temp].mon, rtime[temp].day, rtime[temp].hour, rtime[temp].min);
    gotoxy(80, 30);
    printf("다른 사물함 정보를 보시겠습니까? (y/n) : ");
    gotoxy(122, 30);
    scanf("%s", &comp);
    if ((strcmp(comp, "y") == 0) || (strcmp(comp, "Y") == 0))
    {
        system("cls");
        rsee();
    }
    else if ((strcmp(comp, "n") == 0) || (strcmp(comp, "N") == 0))
    {
        Alarm("사물함 확인을 종료합니다.");
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
    Rect1(58, 2, 41, 5, "1.검색 2.그래프 3.뒤로 가기");
    Rect3(58, 2, 41, 7, "메뉴 입력 : ");
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
    Rect1(58, 2, 41, 5, "1.기간 검색  2.뒤로가기");
    Rect3(58, 2, 41, 7, "메뉴 입력 : ");
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
    Rect1(58, 2, 41, 5, "일 매출");
    gotoxy(47, 14);
    printf("시작 날짜 입력 : ");
    scanf("%d %d %d", &input_year, &input_month, &input_day);
    gotoxy(47, 16);
    printf("종료 날짜 입력 : ");
    scanf("%d %d %d", &input_year1, &input_month1, &input_day1);

    for (int i = 0; i < scount; i++) {
        if (input_year == input_year1) { //년도가 같을때
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
        if (input_year == input_year1) { //년도가 같을때
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
    printf("좌석 이용권 총액 : %d원", ssum);
    gotoxy(47, 25);
    printf("사물함 이용권 총액 : %d원", rsum);
    gotoxy(47, 30);
    printf(" %d년 %d월 %d일 ~ %d년 %d월 %d일 매출 : %d원\n", input_year, input_month, input_day, input_year1, input_month1, input_day1, ssum + rsum);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    gotoxy(47, 35);
    printf("다른 날짜 매출을 확인하시겠습니까?(y/n) : ");
    gotoxy(88, 35);
    scanf("%s", &menu);
    if ((strcmp(menu, "y") == 0 || strcmp(menu, "Y") == 0))
    {
        ssearch1();
    }
    else if ((strcmp(menu, "n") == 0 || strcmp(menu, "N") == 0))
    {
        Alarm("매출 확인을 종료합니다.");
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
    Rect1(58, 2, 41, 5, "매출 그래프");
    gotoxy(52, 30);
    for (int i = 10; i > 0; i = i--) {
        gotoxy(52, 30 - i);
        printf("%3d │", i * 10);  //5 자릿수 맞추기 최대 10000000점 세자리이므로 3d
        //i를 십만부터 시작, i에 십만을 곱하여 점수를 표현 
        for (int j = 0; j < cnt; j++) {
            int  num = arrscore[j] / 10;  //i와 값을 비교하기 위해 점수를 10으로 나눠줌
            if (num >= i) {  //점수를 10으로 나눈 값이 i보다 크거나 같을 때
                if (num == i) { printf("  ┌┐ "); }  //같으면 시작을 표시하는 ┌┐ 기호 출력
                else { printf("  ││ "); }  //0점을 만나기 전까지 ││ 기호 출력
            }
            else {
                printf("     ");
            }
        }
        printf("\n");
    }
    gotoxy(52, 30);
    printf("%3d └─", 0);  //0점 표시
    for (int i = 0; i < cnt; i++) {
        if (arrscore[i] != 0) {  //0점이 아닌 점수가 입력된 부분에만 ─┴┴─ 기호로 출력
            printf("─┴┴─ ");
        }
        else {
            printf("─────");  //0점이 입력된 부분에는 ───── 기호로 출력
        }
    }

    printf("\n");
    printf("      ");
    gotoxy(58, 32);
    for (int i = 18; i <= 22; i++) {
        printf(" %d년", i);
    }
    printf("\n");

    gotoxy(84, 20);
    printf("(단위 : 십만)");

    gotoxy(47, 15);
    printf("그래프 확인 종료(y/n) : ");
    gotoxy(71, 15);
    scanf("%s", &menu);

    if ((strcmp(menu, "y") == 0 || strcmp(menu, "Y") == 0))
    {
        Alarm("매출 통계를 종료합니다.");
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
    for (int i = 0; i < width; i++)//첫 가로 라인 그리기
    {
        if (i == 0) printf("┌");
        else if (i == width - 1) printf("┐\n");
        else printf("─");
    }
    goto_xy(x, y + 1);
    for (int j = 0; j < height; j++)//세로 라인 그리기
    {
        printf("│");
        for (int k = 0; k < width - 2; k++)
        {
            printf(" ");
        }
        printf("│");
        goto_xy(x, y + (j + 1));
    }
    for (int l = 0; l < width; l++)//마지막 가로 라인 그리기
    {
        if (l == 0) printf("└");
        else if (l == width - 1) printf("┘\n");
        else printf("─");
    }
} //사용
void Rect1(int width, int height, int x, int y, char* msg)
{
    goto_xy(x, y);
    for (int i = 0; i < width; i++)
    {
        if (i == 0) printf("┌");
        else if (i == width - 1) printf("┐\n");
        else printf("─");
    }
    goto_xy(x, y + 1);
    for (int j = 0; j < height; j++)
    {
        printf("│");
        for (int k = 0; k < width - 2; k++)
        {
            if (j == height / 2 && k == ((width)-strlen(msg)) / 2)
                printf("%s", msg);
            else printf(" ");
        }
        goto_xy(x + width - 1, y + 1); //안쪽 상자 오른쪽 선 하나 추가(수정할것)
        printf("│");
        goto_xy(x + width, y + 1); //바깥쪽 상자 오른쪽 선 하나 추가(수정할것)
        printf("│");
        goto_xy(x + width - 1, y + 1);
        printf("│");
        goto_xy(x, y + (j + 1));

    }
    for (int l = 0; l < width; l++)
    {
        if (l == 0) printf("└");
        else if (l == width - 1) printf("┘\n");
        else printf("─");
    }
    goto_xy(0, 50);
}
void Rect2(int width, int height, int x, int y, char* msg)
{
    goto_xy(x, y);
    for (int i = 0; i < width; i++)
    {
        if (i == 0) printf("┌");
        else if (i == width - 1) printf("┐\n");
        else printf("─");
    }
    goto_xy(x, y + 1);
    for (int j = 0; j < height; j++)
    {
        printf("│");
        for (int k = 0; k < width - 2; k++)
        {
            if (j == height / 2 && k == ((width)-strlen(msg)) / 2)
                printf("%s", msg);
            else printf(" ");
        }
        goto_xy(x + width - 1, y + 1); //안쪽 상자 오른쪽 선 하나 추가(수정할것)
        printf("│");
        goto_xy(x, y + (j + 1));
    }
    for (int l = 0; l < width; l++)
    {
        if (l == 0) printf("└");
        else if (l == width - 1) printf("┘\n");
        else printf("─");
    }
}
void Rect3(int width, int height, int x, int y, char* msg)
{
    goto_xy(x, y);
    for (int i = 0; i < width; i++)
    {
        if (i == 0) printf("├");
        else if (i == width - 1) printf("┤\n");
        else printf("─");
    }
    goto_xy(x, y + 1);
    for (int j = 0; j < height; j++)
    {
        printf("│");
        for (int k = 0; k < width - 2; k++)
        {
            if (j == height / 2 && k == ((width)-strlen(msg)) / 2)
                printf("%s", msg);
            else printf(" ");
        }
        goto_xy(x + width - 1, y + 1); //안쪽 상자 오른쪽 선 하나 추가(수정할것)
        printf("│");
        goto_xy(x + width, y + 1); //바깥쪽 상자 오른쪽 선 하나 추가(수정할것);
        printf("│");
        goto_xy(x, y + (j + 1));
    }
    for (int l = 0; l < width; l++)
    {
        if (l == 0) printf("└");
        else if (l == width - 1) printf("┘\n");
        else printf("─");
    }
    goto_xy(0, 40);
}
void Rect5(int width, int height, int x, int y, char* msg) //secoundUI 틀
{
    goto_xy(x, y);
    for (int i = 0; i < width; i++)
    {
        if (i == 0) printf("┌");
        else if (i == width - 1) printf("┐\n");
        else printf("─");
    }
    goto_xy(x, y + 1);
    for (int j = 0; j < height; j++)
    {
        printf("│");
        for (int k = 0; k < width - 2; k++)
        {
            if (j == height / 2 && k == ((width)-strlen(msg)) / 2)
                printf("%s", msg);
            else printf(" ");
        }
        goto_xy(x + width - 1, y + 1); //안쪽 상자 오른쪽 선 하나 추가(수정할것)
        printf("│");
        goto_xy(x + width - 1, y + 2); //바깥쪽 상자 오른쪽 선 하나 추가(수정할것)
        printf("│");
        goto_xy(x, y + (j + 1));

    }
    for (int l = 0; l < width; l++)
    {
        if (l == 0) printf("└");
        else if (l == width - 1) printf("┘\n");
        else printf("─");
    }
    goto_xy(0, 50);
}
void Rect4(int width, int height, int x, int y, char* msg) //secoundUI 틀
{
    goto_xy(x, y);
    for (int i = 0; i < width; i++)
    {
        if (i == 0) printf("┌");
        else if (i == width - 1) printf("┐\n");
        else printf("─");
    }
    goto_xy(x, y + 1);
    for (int j = 0; j < height; j++)
    {

        printf("│");
        for (int k = 0; k < width - 2; k++)
        {
            if (j == height / 2 && k == ((width)-strlen(msg)) / 2)
                printf("%s", msg);
            else printf(" ");
        }
        goto_xy(x + width, y + 1); //안쪽 상자 오른쪽 선 하나 추가(수정할것)
        printf("│");
        goto_xy(x + width - 1, y + 1);
        printf("│");
        goto_xy(x, y + (j + 1));

    }
    for (int l = 0; l < width; l++)
    {
        if (l == 0) printf("└");
        else if (l == width - 1) printf("┘\n");
        else printf("─");
    }
    goto_xy(0, 40);
}
void Rect6(int width, int height, int x, int y) //붙어있는 
{
    goto_xy(x, y);
    for (int i = 0; i < width; i++)//첫 가로 라인 그리기
    {
        if (i == 0) printf("├");
        else if (i == width - 1) printf("┤\n");
        else printf("─");
    }
    goto_xy(x, y + 1);
    for (int j = 0; j < height; j++)//세로 라인 그리기
    {
        printf("│");
        for (int k = 0; k < width - 2; k++)
        {
            printf(" ");
        }
        printf("│");
        goto_xy(x, y + (j + 1));
    }
    for (int l = 0; l < width; l++)//마지막 가로 라인 그리기
    {
        if (l == 0) printf("└");
        else if (l == width - 1) printf("┘\n");
        else printf("─");
    }
    goto_xy(0, 50); //콘솔창 문장 좌표 이동
}
void Rect7(int width, int height, int x, int y, char* msg) //secoundUI 틀
{
    goto_xy(x, y);
    for (int i = 0; i < width; i++)
    {
        if (i == 0) printf("┌");
        else if (i == width - 1) printf("┐\n");
        else printf("─");
    }
    goto_xy(x, y + 1);
    for (int j = 0; j < height; j++)
    {

        printf("│");
        printf("%s", msg);

        goto_xy(x + width, y + 1); //안쪽 상자 오른쪽 선 하나 추가(수정할것)
        printf("│");
        goto_xy(x + width - 1, y + 1);
        printf("│");
        goto_xy(x, y + (j + 1));

    }
    for (int l = 0; l < width; l++)
    {
        if (l == 0) printf("└");
        else if (l == width - 1) printf("┘\n");
        else printf("─");
    }
    goto_xy(0, 40);
}
void Rect8(int width, int height, int x, int y, char* msg)
{
    goto_xy(x, y);
    for (int i = 0; i < width; i++)
    {
        if (i == 0) printf("┌");
        else if (i == width - 1) printf("┐\n");
        else printf("─");
    }
    goto_xy(x, y + 1);
    for (int j = 0; j < height; j++)
    {

        printf("│");
        for (int k = 0; k < width - 2; k++)
        {
            if (j == height / 2 && k == ((width)-strlen(msg)) / 2)
                printf("%s", msg);
            else printf(" ");
        }
        goto_xy(x + width, y + 1); //안쪽 상자 오른쪽 선 하나 추가(수정할것)
        printf("│");
        goto_xy(x + width - 1, y + 1);
        printf("│");
        goto_xy(x + width + 6, y + 1);
        printf("│");
        goto_xy(x, y + (j + 1));

    }
    for (int l = 0; l < width; l++)
    {
        if (l == 0) printf("└");
        else if (l == width - 1) printf("┘\n");
        else printf("─");
    }
    goto_xy(0, 40);
}
void Rect9(int width, int height, int x, int y, char* msg)
{
    goto_xy(x, y);
    for (int i = 0; i < width; i++)
    {
        if (i == 0) printf("├");
        else if (i == width - 1) printf("┤\n");
        else printf("─");
    }
    goto_xy(x, y + 1);
    for (int j = 0; j < height; j++)
    {
        printf("│");
        for (int k = 0; k < width - 2; k++)
        {
            if (j == height / 2 && k == ((width)-strlen(msg)) / 2)
                printf("%s", msg);
            else printf(" ");
        }
        goto_xy(x + width - 1, y + 1); //안쪽 상자 오른쪽 선 하나 추가(수정할것)
        printf("│");
        goto_xy(x + width, y + 1); //바깥쪽 상자 오른쪽 선 하나 추가(수정할것);
        printf("│");
        goto_xy(x + width + 6, y + 1); //바깥쪽 상자 오른쪽 선 하나 추가(수정할것);
        printf("│");
        goto_xy(x, y + (j + 1));
    }
    for (int l = 0; l < width; l++)
    {
        if (l == 0) printf("└");
        else if (l == width - 1) printf("┘\n");
        else printf("─");
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