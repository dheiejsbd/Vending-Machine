#include<stdio.h>
#include "Turboc.h"

int a;
char menu[] = { 'v','d','s','r','l','q','t','y' };
int price[] = { 100,200,300,51,156,12,8000,153 };
int gold = 0;




void chack();
void getMoney();
void outMoney();
void DrowMenu();
void getobj();




int main()
{
	DrowMenu();

	while (true)
	{
		chack();
		DrowMenu();
	}
	return 0;
}











void chack()
{
	scanf_s("%d", &a);

	switch (a)
	{
	case 0:
		getMoney();
		return;
	case 1:
		outMoney();
		return;
	}
	if (a > sizeof(menu) / sizeof(char) + 1)
		return;
	getobj();
}


void getMoney()
{
	clrscr();
	int g = 0;
	printf("돈을 투입하세요\n");



	scanf_s("%d", &g);


	if (g <= 0)
	{
		printf("0이하의 돈은 투입할 수 없습니다.");
		Sleep(1000);
	}
	else
	{
		gold += g;
		printf("%d원이 투입되었습니다.", g);
		Sleep(1000);
	}

}

void outMoney()
{
	clrscr();
	printf("%d원이 반환되었습니다.", gold);
	gold = 0;
	Sleep(1000);
}

void DrowMenu()
{
	clrscr();
	printf("메뉴           잔액 : %d        돈 투입 : 0    반환 : 1\n", gold);
	for (int i = 0; i < sizeof(menu) / sizeof(char); i++)
	{
		printf("%d : %c - %d원\n", i + 2, menu[i], price[i]);
	}
}

void getobj()
{
	printf("%c를 선택했습니다. 가격은 %d원 입니다.\n", menu[a - 2], price[a - 2]);
	Sleep(1000);
	if (gold > price[a - 2])
	{
		gold -= price[a - 2];
		printf("구매가 완료되었습니다. 잔액은 %d입니다.", gold);
	}
	else
	{
		printf("잔액이 부족합니다.");
	}

	Sleep(3000);
}