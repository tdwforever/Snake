
#include<time.h>
#include<windows.h>
#define U 1
#define D 2
#define L 3 
#define R 4 
void Pos();
void creatmap();
void creatsnake();
int biteself();
void creatfood();
void cantcrosswall();
void snakemove();
void welcometogame();
void gamestart();
void caozuo();
typedef struct snake
{
int x;
int y;
struct snake *next;
}snake;
int score=0,add=10,maxscore=0;
int status,sleeptime=200;
snake *head,*food;
snake *q;
int endgamestatus=0;
void Pos(int x,int y)
{
    COORD pos;
HANDLE hOutput;
    pos.X=x;
    pos.Y=y;
    hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput,pos);
}
void creatmap()
{
    int i;
    for(i=0;i<58;i+=2)
    {
        Pos(i,0);
        printf("��");
        Pos(i,26);
        printf("��");
    }  
for(i=1;i<26;i++)
    {
        Pos(0,i);
        printf("��");                        
        Pos(56,i);
        printf("��");        
    }
}
void creatsnake()
{
snake *tail;
int i;
tail=(snake*)malloc(sizeof(snake));
tail->x=24;
tail->y=5;
tail->next=NULL;
for(i=1;i<=4;i++)
{
head=(snake*)malloc(sizeof(snake));
head->next=tail;
head->x=24+2*i;
head->y=5;
tail=head;
}
Pos(tail->x,tail->y);
printf("��");
tail=tail->next;
while(tail!=NULL)
{
Pos(tail->x,tail->y);
printf("��");
tail=tail->next;
}
}
int biteself()
{
    snake *self;
    self=head->next;
    while(self!=NULL)
    {
        if(self->x==head->x && self->y==head->y)
        {
            return 1;
        }
        self=self->next;
    }
    return 0;
}
void creatfood()
{
snake *food_1;
srand((unsigned)time(NULL));
food_1=(snake*)malloc(sizeof(snake));
while(food_1->x%2!=0)
{
food_1->x=rand()%52+2;
}
food_1->y=rand()%24+1;
q=head;
while(q->next==NULL)
    {
        if(q->x==food_1->x && q->y==food_1->y)
        {
            free(food_1);
            creatfood();
        }
        q=q->next;
    }
Pos(food_1->x,food_1->y);
    food=food_1;
    printf("��");
}
void cantcrosswall()
{  
    if(head->x==0 || head->x==56 ||head->y==0 || head->y==26)
    {
        endgamestatus=1;
    }
}
void snakemove()
{
snake * nexthead;
    cantcrosswall();
    
    nexthead=(snake*)malloc(sizeof(snake));
    if(status==U)
    {
        nexthead->x=head->x;
        nexthead->y=head->y-1;
        if(nexthead->x==food->x && nexthead->y==food->y)
        {
            nexthead->next=head;
            head=nexthead;
            q=head;
Pos(q->x,q->y);
printf("��");
q=q->next;
            while(q!=NULL)
            {
                Pos(q->x,q->y);
                printf("��");
                q=q->next;
            }
            score=score+add;
            creatfood();
        }
        else                                              
        {
            nexthead->next=head;
            head=nexthead;
            q=head;
Pos(q->x,q->y);
printf("��");
q=q->next;
            while(q->next->next!=NULL)
            {
                Pos(q->x,q->y);
                printf("��");
                q=q->next;        
            }
            Pos(q->next->x,q->next->y);
            printf("  ");
            free(q->next);
            q->next=NULL;
        }
    }
    if(status==D)
    {
        nexthead->x=head->x;
        nexthead->y=head->y+1;
        if(nexthead->x==food->x && nexthead->y==food->y)  
        {
            nexthead->next=head;
            head=nexthead;
            q=head;
Pos(q->x,q->y);
printf("��");
q=q->next;
            while(q!=NULL)
            {
                Pos(q->x,q->y);
                printf("��");
                q=q->next;
            }
            score=score+add;
            creatfood();
        }
        else                               
        {
            nexthead->next=head;
            head=nexthead;
            q=head;
Pos(q->x,q->y);
printf("��");
q=q->next;
            while(q->next->next!=NULL)
            {
                Pos(q->x,q->y);
                printf("��");
                q=q->next;        
            }
            Pos(q->next->x,q->next->y);
            printf("  ");
            free(q->next);
            q->next=NULL;
        }
    }
    if(status==L)
    {
        nexthead->x=head->x-2;
        nexthead->y=head->y;
        if(nexthead->x==food->x && nexthead->y==food->y)
        {
            nexthead->next=head;
            head=nexthead;
            q=head;
Pos(q->x,q->y);
printf("��");
q=q->next;
            while(q!=NULL)
            {
                Pos(q->x,q->y);
                printf("��");
                q=q->next;
            }
            score=score+add;
            creatfood();
        }
        else                              
        {
            nexthead->next=head;
            head=nexthead;
            q=head;
Pos(q->x,q->y);
printf("��");
q=q->next;
            while(q->next->next!=NULL)
            {
                Pos(q->x,q->y);
                printf("��");
                q=q->next;        
            }
            Pos(q->next->x,q->next->y);
            printf("  ");
            free(q->next);
            q->next=NULL;
        }
    }
    if(status==R)
    {
        nexthead->x=head->x+2;
        nexthead->y=head->y;
        if(nexthead->x==food->x && nexthead->y==food->y)
        {
            nexthead->next=head;
            head=nexthead;
            q=head;
Pos(q->x,q->y);
printf("��");
q=q->next;
            while(q!=NULL)
            {
                Pos(q->x,q->y);
                printf("��");
                q=q->next;
            }
            score=score+add;
            creatfood();
        }
        else                                    
        {
            nexthead->next=head;
            head=nexthead;
            q=head;
Pos(q->x,q->y);
printf("��");
q=q->next;  
            while(q->next->next!=NULL)
            {
                Pos(q->x,q->y);
                printf("��");
                q=q->next;        
            }
            Pos(q->next->x,q->next->y);
            printf("  ");
            free(q->next);
            q->next=NULL;
        }
    }
    if(biteself()==1)      
    {
        endgamestatus=2;
    }
}
void pause()
{
    while(1)
    {
        Sleep(300);
        if(GetAsyncKeyState(VK_SPACE))
        {
            break;
        }
    }
}
 
 
void welcometogame()
{  
Pos(40,12);
printf("��ӭ����̰ʳ����Ϸ��");
Pos(40,25);
system("pause");
system("cls");
}
 
 
void caozuo()
{
Pos(64,16);
    printf("������á�.��.��.���ֱ�����ߵ��ƶ�.");
Pos(64,18);
    printf("ESC ���˳���Ϸ.space����ͣ��Ϸ.");
Pos(64,20);
printf("F1:�����ߵ��˶��ٶ� F2���ӿ������ٶ�");
status=R;
while(1)
    {
        Pos(64,10);
        printf("�÷֣�%d  ",score);
        Pos(64,11);
        printf("ÿ��ʳ��÷֣�%d��",add);
Pos(64,12);
        printf("��߷֣�%d��",maxscore);
        if(GetAsyncKeyState(VK_UP) && status!=D)
        {
            status=U;
        }
        else if(GetAsyncKeyState(VK_DOWN) && status!=U)
        {
            status=D;
        }
        else if(GetAsyncKeyState(VK_LEFT)&& status!=R)
        {
            status=L;
        }
        else if(GetAsyncKeyState(VK_RIGHT)&& status!=L)
        {
            status=R;
        }
        else if(GetAsyncKeyState(VK_SPACE))
        {
            pause();
        }
        else if(GetAsyncKeyState(VK_ESCAPE))
        {
            endgamestatus=3;
            break;
        }
else if(GetAsyncKeyState(VK_F1))
        {
            if(sleeptime>=50)
            {
                sleeptime=sleeptime-30;
                add=add+2;
                if(sleeptime==320)
                {
                    add=2;
                }
            }
        }
        else if(GetAsyncKeyState(VK_F2))
        {
            if(sleeptime<350)
            {
                sleeptime=sleeptime+30;
                add=add-2;
                if(sleeptime==350)
                {
                    add=1; 
                }
            }
        }
Sleep(sleeptime);
        snakemove();
if(endgamestatus!=0)
{
system("cls");
Pos(24,12);
if(endgamestatus==1)
{
printf("�Բ�����ײ��ǽ��,��Ϸ����.");
}
else if(endgamestatus==2)
{
printf("�Բ�����ҧ���Լ���,��Ϸ����.");
}
else if(endgamestatus==3)
{
printf("����������Ϸ��");
}
Pos(24,13);
if(maxscore<score)
{
printf("��ϲ������˼�¼����Ϊ����߷֣�");
                  maxscore= score;
}
Pos(24,14);
printf("���ĵ÷���%d\n",score);
endgamestatus=0;
system("pause");
break;
}
}
}
void gamestart()
{
    system("mode con cols=100 lines=30");
    welcometogame();
    creatmap();
    creatsnake();
    creatfood();
}
int main()
{
while(1)
{
gamestart();
caozuo();
}
return 0;
}