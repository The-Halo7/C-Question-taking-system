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
    printf("\t\t\t\t\tC语言抽题系统v1.4.2\n");
    printf("\t\t\t\t\t作者： @马庭博\n");
    printf("\t\t\t\t\t技术支持：@刘召旗 @Microsoft\n");
    printf("\t\t\t\t\t题库支持：@王老师很忙\n");
    
    do{
        printf("\n请输入一个正整数作为种子:");
        scanf("%d",&a);
        if(a<=0){
            printf("\n输入错误，请重新输入！");
        }
    }while(a<=0);
    
srand(time(0));
a = rand() % 102 + 1;

sprintf(pcCMD, "D:\\C题库\\%d.pdf",a);
printf("\n你抽到了第%d套题\n",a);
ShellExecute(NULL,"open",pcCMD,NULL,NULL,SW_SHOWNORMAL);

sprintf(pcCMD, "D:\\C题库\\%d.c",a);
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
printf("\n暂停计时，按任意键继续...\n"); 
clock_t temp = clock(); 
getch(); 
pause += clock() - temp; 
}
else 
{
printf("\n无效的输入，请按ESC退出或P暂停...\n"); 
}
}
end = clock();
duration = (double)(end - start - pause) / CLOCKS_PER_SEC; 
int minute = duration / 60;
int second = (int)duration % 60;
int millisecond = (int)(duration * 1000) % 1000;
printf("\r你已经用了%d:%d:%d ", minute, second, millisecond);
Sleep(100);
}

end = clock();
duration = (double)(end - start - pause) / CLOCKS_PER_SEC; 
int minute = duration / 60;
int second = (int)duration % 60;
int millisecond = (int)(duration * 1000) % 1000;

printf("\n你总共用了%d:%d:%d完成了这套题\n", minute, second, millisecond);


printf("\n按任意键退出程序...\n");
getch();

}
