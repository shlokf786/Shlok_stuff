// count_digits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<stdio.h>

using namespace std;
char arr[20000];
char *numbers;
int *frq;
int sz;
int i, j, k, l, m, f = 0;
void set_nd_delete_dublicate()
{
	for ( i = 0; i< sz; i++)//this is to copy all the input array to the numbers array 
	{
		numbers[i] = arr[i];
		frq[i] = 1;
	}
	//this will check all the elements of number array by all other elements 
	//and over-write the dublicate element if found and count that number also
	for (i = 0; i < sz; i++)
	{
		for (j = i + 1; j < sz; j++)
		{
			if (numbers[i] == numbers[j])
			{
				for (k = j; k < sz; k++)
				{
					numbers[k] = numbers[k + 1];
				}
				sz--;
			}
		}
		
	}
}
int main()
{
	char ch;
	do {
		system("cls");
		cout << "Enter numbers : ";
		i = 0;
		char c;
		do {
			c = _getche();
			switch (c)		//this will check if the user enter a number only we cannot use isnum() as it inpute is a charecter only
			{
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '0': {
						if ((int)c != 13)		//check if the use press enter key or not if yes then stop getting input 
						{
							arr[i] = c;
							i++;
							sz = i;		//this is used to set the array size then we can use the the integer 'i' again
						}
						else
						{
							  break;
						}

					  }
					  break;
			default: { 
					  cout << "\nInvalid input Exiting Program ....";
					  cout<<"\n\n\nPress any key to continue.....";
					  _getch();
				      exit(0); 
					 }
			}
		} while (1);
		system("cls");
	
		//this is just to print the inputed  array
		cout << "\nInputted array is ";
		for (k = 0; k < i; k++)
			cout << arr[k] << ",";

		cout << endl;

		//this will assing the size of the inputed string to numbers and frquency array
		numbers = (char *)malloc(sz*sizeof(char));
		frq = (int *)malloc(sz*sizeof(int));

		set_nd_delete_dublicate();
		cout << endl;
		
		//this is just to print the data in tabular form
		cout << "Numbers\tFrequency\n";
		for (l = 0; l < sz; l++)
			cout << "   " << numbers[l] << "\t   " << frq[l] << endl;

		cout << "\nDo You want to do it again press y or press n : ";
		ch = _getche();
		
		//this will check if that if the user press n and y key only in not then exit
		if ((ch != 'n' || ch != 'N') || (ch != 'y' || ch != 'Y'))
			cout << "\nInvalid input exiting program .....";
		
		//this will free the memory alocated dynamically
		free(numbers);
		free(frq);
	} while (ch == 'y' || ch == 'Y');
	
	cout << "\n\nThank you\n\n\n\n\nPress any key to continue.....";
	_getch();
	return 0;
}