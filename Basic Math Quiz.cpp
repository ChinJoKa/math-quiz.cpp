#include<iostream>
#include<stdlib.h>
#include<time.h>
#define Max 10
using namespace std;
char displayMenu();
int randomInt(int, int);
void generateOperands(char, int[], int[]);
long int displayProblem(int, int);
bool isCorrect(int, int);
void displayMessage(bool, char[], int, int);
void displayFinalResults(int, int);
void main(void)
{
	int i, j, t, f, temp, flag;
	srand(time(NULL));
	int A[Max], B[Max], D[Max];
	char C[Max], E[Max], YN;
	char Difficulty;
	bool TF;
	do {
		flag = 0;
		while (true)
		{
			Difficulty = displayMenu();
			if (Difficulty == 'E' || Difficulty == 'e' || Difficulty == 'M' || Difficulty == 'm' || Difficulty == 'A' || Difficulty == 'a')
				break;
			else
			{
				system("cls");
				cout << "Wrong entry. Please just pick <E>, <M> or <A>" << endl;
			}
		}
		generateOperands(Difficulty, A, B);
		for (i = 0; i < Max; i++)
		{
			D[i] = displayProblem(A[i], B[i]);
			for (j = 0; j < 2; j++)
			{
				cin >> temp;
				TF = isCorrect(temp, D[i]);
				displayMessage(TF, E, i, j);
				if (TF == 1)
					break;
			}
		}
		t = 0;
		f = 0;
		for (i = 0; i < Max; i++)
		{
			if (E[i] == 'T')
				t++;
			if (E[i] == 'F')
				f++;
		}

		displayFinalResults(t, f);
		cout << "Do you want to try again? <Y> if not enter a random entry" << endl;
		cin >> YN;
		if (YN == 'Y' || YN == 'y')
		{
			flag = 1;
			system("cls");
		}
		else
			cout << "See you again next time." << endl;
	} while (flag == 1);
	cout << endl << endl;
	system("pause");
}
char displayMenu()
{
	char Difficulty;
	cout << "Welcome to the basic math quiz. " << endl << "There is 3 difficulty level. Choose one of them." << endl;
	cout << "1. Easy <E>" << endl << "2. Moderate <M>" << endl << "3. Advanced <A>" << endl << "Enter <E>, <M> or <A> :";
	cin >> Difficulty;
	return Difficulty;
}
int randomInt(int min, int max)
{
	int temp;
	temp = rand() % max + min;
	if (temp > max)
		temp -= min;
	return temp;
}
void generateOperands(char dif, int N1[], int N2[])
{
	int i, j;
	if (dif == 'E' || dif == 'e')
	{
		for (i = 0; i < Max; i++)
		{
			N1[i] = randomInt(0, 10);
			N2[i] = randomInt(0, 10);
		}
	}
	else if (dif == 'M' || dif == 'm')
	{
		for (i = 0; i < Max; i++)
		{
			N1[i] = randomInt(10, 99);
			N2[i] = randomInt(10, 99);
		}
	}
	else if (dif == 'A' || dif == 'a')
	{
		for (i = 0; i < Max; i++)
		{
			N1[i] = randomInt(1000, 9999);
			N2[i] = randomInt(1000, 9999);
		}
	}
}
long int displayProblem(int a, int b)
{
	char op;
	int temp;
	temp = rand() % 10;
	temp = temp % 2;
	if (temp == 0)
		op = '+';
	if (temp == 1)
		op = '-';
	cout << a << op << b << "= ";
	if (op == '+')
		return a + b;
	if (op == '-')
		return a - b;
}
bool isCorrect(int a, int b)
{
	bool c;
	c = (a == b);
	return c;
}
void displayMessage(bool TF, char E[], int a, int j)
{

	if (TF == 1)
	{
		cout << "That is correct" << endl;
		E[a] = 'T';
	}
	else if (TF == 0 && j == 0)
		cout << "That is wrong you have 1 more chance" << endl;
	else if (TF == 0 && j == 1)
	{
		cout << "That is wrong" << endl;
		E[a] = 'F';
	}
}
void displayFinalResults(int t, int f)
{
	cout << "You have " << t << " correct answer(s) and " << f << " false answer(s)" << endl;
}
