#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <conio.h>
#include <Windows.h>
void main()
{
    int a,t=0,z=0;
    char pcCMD[255];
    clock_t start, end, pause; 
    double duration;
    time_t now;
    struct tm *lt;
	
    
    printf("\n\n\n");
    printf("\t\t\t\t\tC���Գ���ϵͳv1.4.2\n");
    printf("\t\t\t\t\t���ߣ� @��ͥ��\n");
    printf("\t\t\t\t\t����֧�֣�@������ @Microsoft\n");
    printf("\t\t\t\t\t���֧�֣�@����ʦ��æ\n");
    
    do{
        printf("\n������һ����������Ϊ����:");
        scanf("%d",&a);
        if(a<=0){
            printf("\n����������������룡");
        }
    }while(a<=0);
    
srand(time(0));
a = rand() % 102 + 1;

sprintf(pcCMD, "D:\\C���\\%d.pdf",a);
printf("\n��鵽�˵�%d����\n",a);
ShellExecute(NULL,"open",pcCMD,NULL,NULL,SW_SHOWNORMAL);

sprintf(pcCMD, "D:\\C���\\%d.c",a);
ShellExecute(NULL,"open",pcCMD,NULL,NULL,SW_SHOWNORMAL);

start = clock();
pause = 0; 
while(1)
{
if(kbhit()) 
{
char ch = getch(); 
if(ch == 27) 
{
break; 
}
else if(ch == 'p' || ch == 'P') 
{
printf("\n��ͣ��ʱ�������������...\n"); 
clock_t temp = clock(); 
getch(); 
pause += clock() - temp; 
}
else 
{
printf("\n��Ч�����룬�밴ESC�˳���P��ͣ...\n"); 
}
}
end = clock();
duration = (double)(end - start - pause) / CLOCKS_PER_SEC; 
int minute = duration / 60;
int second = (int)duration % 60;
int millisecond = (int)(duration * 1000) % 1000;
printf("\r���Ѿ�����%d:%d:%d ", minute, second, millisecond);
Sleep(100);
}

end = clock();
duration = (double)(end - start - pause) / CLOCKS_PER_SEC; 
int minute = duration / 60;
int second = (int)duration % 60;
int millisecond = (int)(duration * 1000) % 1000;

printf("\n���ܹ�����%d:%d:%d�����������\n", minute, second, millisecond);


printf("\n��������˳�����...\n");
getch();

}
