#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char* card_number();
bool validity_test(char* card, int n);
void provider(char* card, int n);

int main()
{
	char* card = card_number();
	int n = strlen(card);
	bool valid = validity_test(card, n);
	if (valid == false)
	{
		printf("INVALID\n");
		return 0;
	}
	else
	{
		provider(card, n);
	}
	//printf("%s %d\n", card, n);

}

char* card_number()
{
	static char number[200];
	while (true)
	{
		printf("Please provide your card number:\n");
		scanf("%s", number);
		if (number[0]>47 && number[0]<58)
		{
			return number;
		}
	}
}

bool validity_test(char* card, int n)
{
	int k = n - 2;
	int i = n - 1;
	int sum1 = 0;
	int sum2 = 0;
	if (n>16)
	{
		return false;
	}
	while (k >= 0)
	{
		sum1 = sum1 + (((card[k] - 48) * 2) % 10) + (int)(((card[k] - 48) * 2) / 10);
		k = k - 2;
	}
	while (i >= 0)
	{
		sum2 = sum2 + card[i] - 48;
		i = i - 2;
	}
	int sum3 = sum2 + sum1;
	if (sum3 % 10 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void provider(char* card, int n)
{
	if (n == 15)
	{
		if (card[0] - 48 == 3 && card[1] - 48 == 7)
		{
			printf("AMEX\n");
		}
		else if (card[0] - 48 == 3 && card[1] - 48 == 4)
		{
			printf("AMEX\n");
		}
	}
	if (n == 16)
	{
		if (card[0] - 48 == 5 && card[1] - 48 == 1)
		{
			printf("MASTERCARD\n");
		}
		else if (card[0] - 48 == 5 && card[1] - 48 == 2)
		{
			printf("MASTERCARD\n");
		}
		else if (card[0] - 48 == 5 && card[1] - 48 == 3)
		{
			printf("MASTERCARD\n");
		}
		else if (card[0] - 48 == 5 && card[1] - 48 == 4)
		{
			printf("MASTERCARD\n");
		}
		else if (card[0] - 48 == 5 && card[1] - 48 == 5)
		{
			printf("MASTERCARD\n");
		}
		else if (card[0] - 48 == 4)
		{
			printf("VISA\n");
		}
	}
	if (n == 13 && card[0] == 4)
	{
		printf("VISA\n");
	}
	else
	{
		printf("INVALID\n");
	}
}