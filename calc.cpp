#include "Header.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
int main()
{
	stack Stack(200);
	int calc = 0, input = 0, choise;
	char wait; 
	while (1)
	{
		std::cout << "!" << calc << "\n1. +\n2. -\n3. Back\n4. Forward\n";
		std::cin >> choise;
		system("cls");
		switch (choise)
		{
		case 1:
			if (Stack.is_Full())
			{
				std::cout << "Stack overflow";
				while (1)
				{
					wait = getch();
					if (wait == 13) break;
				}
				system("cls");
				break;
			}
			std::cin >> input;
			calc = calc + input;
			Stack.push(0, input);
			Stack.clear(1);
			system("cls");
			break;
		case 2:
			if (Stack.is_Full())
			{
				std::cout << "Stack overflow";
				while (1)
				{
					wait = getch();
					if (wait == 13) break;
				}
				system("cls");
				break;
			}
			std::cin >> input;
			calc = calc + (-input);
			Stack.push(0, -input);
			Stack.clear(1);
			system("cls");
			break;
		case 3:
			if (Stack.is_Empty(0))
			{
				std::cout << "Stack is empty";
				while (1)
				{
					wait = getch();
					if (wait == 13) break;
				}
				system("cls");
				break;
			}
			input = Stack.pop(0);
			Stack.push(1, input);
			calc = calc - input;
			system("cls");
			break;
		case 4:
			if (Stack.is_Empty(1))
			{
				std::cout << "Stack is empty";
				while (1)
				{
					wait = getch();
					if (wait == 13) break;
				}
				system("cls");
				break;
			}
			input = Stack.pop(1);
			Stack.push(0, input);
			calc = calc + input;
			system("cls");
			break;
		}
	}
	return 0;
}
