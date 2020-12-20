#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>


/*
	created by qwerty
*/


#define SIZE 10
#define SIZE_PERSONAL 10
bool isStrong(char* str,int size)
{
	
	int upper=0, lower=0, special =0 ;
	for (int i = 0; i < size; ++i)
	{

		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
			upper++;
		else if (*(str + i) >= 'a' && *(str + i) <= 'z')
			lower++;
		else if ((*(str + i) >= '!' && *(str + i) <= '@'))
			special++;//special = special +num
		
	}
	bool flag = false;
	if (size >= 8)
		if (lower + upper >= 5)
			if (special >= 3)
				flag = true;
	else flag = false;
	if (flag) return true;
	return false;
}
// shuffle 

char* shaker(char* pass,int size)
{
	
	srand(time(NULL));
	for (int i =0; i<size; i++)
	{
		int j = rand() % size;
		int tmp = pass[i];
		pass[i] = pass[j];
		pass[j] = tmp;
		
	}

	return &pass;

}
// auto password generator
char* securePassword(char* chr)
{
	srand(time(NULL));
	for (int a = 0;a < SIZE;a++)
	{
		int k;
		go:	
		 k= 35+(rand() % 126);
		if (k >= 35 && k <= 126)
			chr[a] = k;
		else goto go;
	}
	return &chr;
}

// if you want own choose , you can use 
char* personalPassword(char* password)
{
	printf("How many capital-letter-(special or num) character?Enter the order.\n");
	int c, l, s;
	int g;
	go:
	scanf("%d %d %d", &c, &l, &s);
	if (c + l + s > SIZE_PERSONAL)
	{
		printf("Must be capital + leter + special <= %d\n ", SIZE_PERSONAL);
		goto go;
	}
	srand(time(NULL));
	for (int i = 0; i < SIZE_PERSONAL; ++i)
	{
		if (c + l + s == SIZE_PERSONAL)
		{
			for (int j =0;j<c;++j)
			{
				char capital = 'A' + (rand() % 26);
				password[j] = capital;

			}
			for (int k = 0; k < l; ++k)
			{
				char letter = 'a' + (rand() % 26);
				password[c+k] = letter;

			}
			for (int d = 0; d < s; d++)
			{
				char special = '!' + ((rand() % 31));
				password[c + l + d] = special;
			}	
		}
		if (c + l + s < SIZE_PERSONAL)
		{
			if (c == 0)
				c = SIZE_PERSONAL - (l + s);
			if (l == 0)
				l = SIZE_PERSONAL - (c + s);
			if (s == 0)
				s = SIZE_PERSONAL - (l + c);
			if (c != 0 && s != 0 && l != 0)
			{
				g= SIZE_PERSONAL - (c + l + s);
			}
			for (int j = 0; j < c; ++j)
			{
				char capital = 'A' + (rand() % 26);
				password[j] = capital;

			}
			for (int k = 0; k < l; ++k)
			{
				char letter = 'a' + (rand() % 26);
				password[c + k] = letter;

			}
			for (int d = 0; d < s; d++)
			{
				char special = '!' + ((rand() % 31));
				password[c + l + d] = special;
			}
			for (int d = 0; d < g; d++)
			{
				char special = '!' + ((rand() % 31));
				password[c + l +s+ d] = special;
			}			
		}
	}
	shaker(password,SIZE_PERSONAL);
	
}

void main()
{
	for(int i =2 ;i>1;)
	{
		printf("1- automatic password generator\n2- Customized Password Generator.\n0-EXIT\n9-CLEANER\n");
		int choose;
		scanf("%d", &choose);


		if (choose == 1)
		{
			char password[SIZE];
			securePassword(&password);
			bool b = isStrong(&password, SIZE);
			printf("\nYour password is:");
			for (int i = 0; i < SIZE; ++i)
				printf("%c", password[i]);
			printf("\n");
			b ? printf("\nYour password is STRONG!\n") : printf("\nYour password NOT SECURE! Please try again...\n");

		}

		if (choose == 2)
		{

			char passPersonal[SIZE_PERSONAL];
			printf("Your password is: ");
			personalPassword(&passPersonal);
			bool b = isStrong(&passPersonal, SIZE_PERSONAL);
			printf("Your customized Password is:");
			for (int i = 0; i < SIZE_PERSONAL; ++i)
				printf("%c", passPersonal[i]);
			b ? printf("\nYour password is STRONG!\n") : printf("\nYour password NOT SECURE! Please try again...\n");

		}
		if (choose == 0) break;
		if (choose == 9) system("CLS");


	}
	

	
	
	
	
}