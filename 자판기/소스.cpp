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
	printf("���� �����ϼ���\n");



	scanf_s("%d", &g);


	if (g <= 0)
	{
		printf("0������ ���� ������ �� �����ϴ�.");
		Sleep(1000);
	}
	else
	{
		gold += g;
		printf("%d���� ���ԵǾ����ϴ�.", g);
		Sleep(1000);
	}

}

void outMoney()
{
	clrscr();
	printf("%d���� ��ȯ�Ǿ����ϴ�.", gold);
	gold = 0;
	Sleep(1000);
}

void DrowMenu()
{
	clrscr();
	printf("�޴�           �ܾ� : %d        �� ���� : 0    ��ȯ : 1\n", gold);
	for (int i = 0; i < sizeof(menu) / sizeof(char); i++)
	{
		printf("%d : %c - %d��\n", i + 2, menu[i], price[i]);
	}
}

void getobj()
{
	printf("%c�� �����߽��ϴ�. ������ %d�� �Դϴ�.\n", menu[a - 2], price[a - 2]);
	Sleep(1000);
	if (gold > price[a - 2])
	{
		gold -= price[a - 2];
		printf("���Ű� �Ϸ�Ǿ����ϴ�. �ܾ��� %d�Դϴ�.", gold);
	}
	else
	{
		printf("�ܾ��� �����մϴ�.");
	}

	Sleep(3000);
}