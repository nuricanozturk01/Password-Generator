#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*
	created by qwerty
*/

#define SIZE 9
#define SIZE_PERSONAL 10
// shuffle 
char* shaker(char* pass)
{
	
	srand(time(NULL));
	for (int i =0; i< SIZE_PERSONAL; ++i)
	{
		
		int j = rand() % SIZE_PERSONAL;
		pass[i] ^= pass[j];
		pass[j] ^= pass[i];
		pass[i] ^= pass[j];
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
	shaker(password);
	
}

void main()
{
	printf("1- automatic password generator\n2- Customized Password Generator.\n");
	int choose;
	scanf("%d", &choose);
	if (choose == 1)
	{
		char password[SIZE];
		securePassword(&password);
		printf("Your password is: ");
		for (int i = 0; i < SIZE; ++i)
			printf("%c", password[i]);
	}
	if (choose == 2)
	{
		
		char passPersonal[SIZE_PERSONAL];
		printf("Your password is: ");
		personalPassword(&passPersonal);
		printf("Your customized Password is: ");
		for (int i = 0; i < SIZE_PERSONAL; ++i)
			printf("%c", passPersonal[i]);
	}
	
	
	
}