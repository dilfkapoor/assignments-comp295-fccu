#include<iostream>
#include<conio.h>
using namespace std;

void upmove(int a[4][4])
{
	int i, j, x, y;
	for (j = 0;j < 4;j++)
	{
		x = 0, y = j;
		for (i = 1;i < 4;i++)
		{
			if (a[i][j] != 0)
			{
				if (a[i - 1][j] == 0 || a[i - 1][j] == a[i][j])
				{
					if (a[x][y] == a[i][j])
					{
						a[x][y] *= 2;
						a[i][j] = 0;
					}
					else
					{
						if (a[x][y] == 0)
						{
							a[x][y] = a[i][j];
							a[i][j] = 0;
						}
						else
						{
							a[++x][y] = a[i][j];
							a[i][j] = 0;
						}
					}
				}
				else x++;
			}
		}
	}
}

void downmove(int a[4][4])
{
	int i, j, x, y;
	for (j = 0;j < 4;j++)
	{
		x = 3, y = j;
		for (i = 2;i >= 0;i--)
		{
			if (a[i][j] != 0)
			{
				if (a[i + 1][j] == 0 || a[i + 1][j] == a[i][j])
				{
					if (a[x][y] == a[i][j])
					{
						a[x][y] *= 2;
						a[i][j] = 0;
					}
					else
					{
						if (a[x][y] == 0)
						{
							a[x][y] = a[i][j];
							a[i][j] = 0;
						}
						else
						{
							a[--x][y] = a[i][j];
							a[i][j] = 0;
						}
					}
				}
				else x--;
			}
		}
	}
}

void leftmove(int a[4][4])
{
	int i, j, x, y;
	for (i = 0;i < 4;i++)
	{
		x = i, y = 0;
		for (j = 1;j < 4;j++)
		{
			if (a[i][j] != 0)
			{
				if (a[i][j - 1] == 0 || a[i][j - 1] == a[i][j])
				{
					if (a[x][y] == a[i][j])
					{
						a[x][y] *= 2;
						a[i][j] = 0;
					}
					else
					{
						if (a[x][y] == 0)
						{
							a[x][y] = a[i][j];
							a[i][j] = 0;
						}
						else
						{
							a[x][++y] = a[i][j];
							a[i][j] = 0;
						}
					}
				}
				else y++;
			}
		}
	}
}

void rightmove(int a[4][4])
{
	int i, j, x, y;
	for (i = 0;i < 4;i++)
	{
		x = i, y = 3;
		for (j = 2;j >= 0;j--)
		{
			if (a[i][j] != 0)
			{
				if (a[i][j + 1] == 0 || a[i][j + 1] == a[i][j])
				{
					if (a[x][y] == a[i][j])
					{
						a[x][y] *= 2;
						a[i][j] = 0;
					}
					else
					{
						if (a[x][y] == 0)
						{
							a[x][y] = a[i][j];
							a[i][j] = 0;
						}
						else
						{
							a[x][--y] = a[i][j];
							a[i][j] = 0;
						}
					}
				}
				else y--;
			}
		}
	}
}

void addblock(int a[4][4])
{
	int x, y;
	srand(time(0));
	while (1)
	{
		x = rand() % 4;
		y = rand() % 4;
		if (a[x][y] == 0)
		{
			a[x][y] = pow(2, x % 2 + 1);
			break;
		}
	}

}

void disp(int a[4][4])
{
	cout << "\n\t\tPress M anytime to quit the game";
	cout << "\n\n\n\n";
	int i, j;
	for (i = 0;i < 4;i++)
	{
		cout << "\t\t\t\t-----------------\n\t\t\t\t";
		for (j = 0;j < 4;j++)
		{
			if (a[i][j] == 0) cout << "|   ";
			else
				cout << "| " << a[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << "\t\t\t\t-----------------\n";
}

int check(int tmp[4][4], int a[4][4])
{
	int fl = 1, i, j;
	for (i = 0;i < 4;i++)
		for (j = 0;j < 4;j++)
			if (tmp[i][j] != a[i][j])
			{
				fl = 0;
				break;
			}
	return fl;
}

int checkover(int a[4][4])
{
	int fl = 0, gl = 0, i, j;
	for (i = 0;i < 4;i++)
		for (j = 0;j < 4;j++)
			if (a[i][j] == 0)
			{
				fl = 1;
				break;
			}

	for (i = 0;i < 3;i++)
		for (j = 0;j < 3;j++)
			if (a[i + 1][j] == a[i][j] || a[i][j + 1] == a[i][j])
			{
				gl = 1;
				break;
			}

	if (fl || gl) return 1;
	else return 0;
}

int main()
{
	char b;
	cout << "\n\n\n\n\t\t\t2048 GAME\n\n\n\t\tPress A to continue" << endl;
	cout << "                Press B for instructions " << endl;
	cout << "                Press C to exit " << endl;
	cin >> b;
	if (b == 'B')
	{
		cout << "If you select the program will ask you to choose a number between 1 and 100.\n You have a maximum of 7 tries to guess the correct number.\nAfter each guess, the program will tell you if your guess is higher or lower than the correct number.\nIf you guess the correct number within 7 tries, you win the game.\nIf you are unable to guess the correct number within 7 tries, you lose the game.\nAfter the game ends, you will have the option to play again or quit the game.\nIf you select Quit, the program will exit." << endl;
		cout << "Enter A to play the game again " << endl;
		cin >> b;
	}
	if (b == 'C')
	{
		return 0;
	}
	system("cls");
	int i1, i2, i3, i4, i, j;
	int a[4][4] = { 0 }, tmp[4][4] = { 0 };
	srand(time(0));
	i1 = rand() % 4;
	i2 = rand() % 4;
	while (1)
	{
		i3 = rand() % 4;
		i4 = rand() % 4;
		if (i3 != i1 && i4 != i2) break;
	}
	a[i1][i2] = 2;
	a[i3][i4] = 4;
	disp(a);

	char chec;
	while (1)
	{
		for (i = 0;i < 4;i++)
			for (j = 0;j < 4;j++)
				tmp[i][j] = a[i][j];
		cin >> chec;
		system("cls");
		if (chec == 'A') upmove(a);
		if (chec == 'Z') downmove(a);
		if (chec == 'W') leftmove(a);
		if (chec == 'D') rightmove(a);
		if (chec == 'M') break;

		if (!check(tmp, a))
			addblock(a);
		disp(a);
		char end;
		if (!checkover(a))
		{
			cout << "\n\n\t\t\tGAME OVER!!\n\n\n";
			cin >> end;
			break;
		}
	}
	return 0;
}