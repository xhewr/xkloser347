/* Program Description: This program will offer the user a menu choice to perform C-string operations.
The user will choose the desired string operation, input the requested arguments and view the result
of the desired operations.
Pseudocode:
Display menu choices to user.
In a do-while loop, prompt user for a menu choice.
If choice is not valid:
Displays to user that choice was not valid.
Prompt if user wants to return to menu or exit.
If choice is valid:
Prompt user to input arguments to perform operations.
Display results of operation to user.
Prompt if user wants to return to menu for new operation or exit.
If user requests new operation, return him back to menu.
Else, exits the program.
*/


#include <iostream>
using namespace std;

//Function prototypes:
void inputSingleString(char *string1, const int size);
void inputDoubleString(char *string1, char *string2, const int size);
int stringLength(char *charArrayFromMain);
char *stringNCopy(char *charArrayFromMain, char*, int);
char* stringAdd(char *dest, const char *src);
int stringCompare(const char *firstWord, const char *secondWord);

int main()
{
	// C-string arrays for user input
	const int LENGTH = 21;
	char str1[55] = "";         //  double length, so str1 can hold str1 + str2
	char str2[LENGTH] = "";     //  initialized  both arrays filled with \0

	int choice = 0;  //  to hold the menu choice from 1-4
						//  clifford - choice is back to int with some input validation checks

	int count = 0;  //  clifford - I left this here because its used in more than one case

	//  display the menu and get a choice from user
	cout << "Enter the number that corresponds to the string manipulation to be performed:\n\n"
		<< "    1. String length.\n"
		<< "    2. String copy\n"
		<< "    3. String concatenation\n"
		<< "    4. String comparison.\n\n";

	//  give user the possibility to repeat the menu
	char again = 'y';
	do
	{
		cout << "Enter your choice and press [ENTER]: " << endl;
		cin >> choice;
		while (!cin || choice < 1 || choice > 4)  //  input validation.  To catch letters, negative numbers and other non-number characters
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Only numbers between 1 through 4 are valid. Enter a new number: ";
			cin >> choice;
		}
		cin.clear();
		cin.ignore();
		switch (choice)

		{
		case 1:  //  stringLength function
		{
			inputSingleString(str1, LENGTH);  //  single word input
			int len = stringLength(str1);  //  return word length to len variable
			cout << "Word has " << len << " characters \n";
			break;
		}

		case 2:  //  stringNCopy function
		{
			char *stringNCopyPointer = nullptr;
			int stringNCopyNumber = 0;
			inputSingleString(str2, LENGTH);
			cout << "enter the number of characters to copy: ";
			cin >> stringNCopyNumber;  
			while (!cin || stringNCopyNumber < 1 || stringNCopyNumber > 20)  //  input validation
			{
				cin.clear();
				cin.ignore();
				cout << "Only positive numbers between 1 through 20 are valid. Enter a new number: ";
				cin >> stringNCopyNumber;
			}
			stringNCopyPointer = stringNCopy(str1, str2, stringNCopyNumber);
			cout << "stringNCopy returns: ";
			count = 0;
			while (*(stringNCopyPointer + count) != '\0' || count < LENGTH)  // clifford - I added this if for what ever reason the loop might try to run forever.  makes me feel better
			{
				cout << *(stringNCopyPointer + count);
				count++;
			}
			cout << endl;
			break;
		}

		case 3:  //  stringAdd function
		{
			inputDoubleString(str1, str2, LENGTH);  //  double word input
			char *concatenatedWords = nullptr;
			concatenatedWords = stringAdd(str1, str2);  // returns concatenated words
			cout << "stringAdd returns: ";
			count = 0;
			while (*(concatenatedWords + count) != '\0' || count < LENGTH)  // clifford - more infinite loop protections
			{
				cout << *(concatenatedWords + count);
				count++;
			}
			cout << endl;
			break;
		}

		case 4:  //  stringCompare function
		{
			inputDoubleString(str1, str2, LENGTH);  //  double word input
			int comp = stringCompare(str1, str2);  //  returns value of compared words

			if (comp == 0)
				cout << "You inputted identical words.";

			else if (comp > 0)
				cout << "The words are different: '" << str2 << "' comes before '" << str1 << "' alphabetically\n";

			else
				cout << "The words are different: '" << str1 << "' comes before '" << str2 << "' alphabetically\n";
			break;
		}

		default:
		{
			cout << choice << " is not a choice in this menu.\n" << "You must enter 1, 2, 3 or 4! \n";
			cin.clear();
		}


		}

		cout << "\nManipulate another string? [Y/N]";
		cin >> again;
		cin.clear();

	} while (again == 'y' || again == 'Y');

	return 0;
}

/* Single String Input Function:
Accepts one input string and size limit for that string, including the null terminator.
cin appends a maximum of size-1 characters to string1 + automatic null terminator. */
void inputSingleString(char *string1, const int size)
{
	cout << "Enter a word with 20 or less characters: " << endl;
	cin.getline(string1, size);
	cin.clear();
}

/* Double String Input Function:
Accepts two input strings from user and size limit for that string, including the null terminator.
cin appends a maximum of size-1 characters to each string variable + automatic null terminator. */
void inputDoubleString(char *string1, char *string2, const int size)
{
	cout << "Enter the first word using 20 or less characters: " << endl;
	cin.getline(string1, size);
	cin.clear();
	cout << "Enter the second word using 20 or less characters: " << endl;
	cin.getline(string2, size);
	cin.clear();

}

int stringLength(char *charArrayFromMain)
{
	//  get an array address pointer, then use a loop to count the characters in the array until a null terminator is found
	//  return the length of the array not counting the \0

	int count = 0;
	while (*(charArrayFromMain + count) != '\0')
	{
		count++;
	}
	return count;
}

char *stringNCopy(char *destinationCharArray, char *sourceCharArray, int stringNCopyNumber)
{
	//  get the address for the source char array, the destination array, and a number sent from main
	//  run the loop based on the number that was sent from main, or until a \0 is found
	//  each time the loop runs, copy the character from the source array and put it in the destination array
	//  add a \0 at the end of the destination array
	//  return the memory address of the destination array

	int count = 0;
	for (count = 0; count < stringNCopyNumber && (*(sourceCharArray + count) != '\0'); count++)
	{
		*(destinationCharArray + count) = *(sourceCharArray + count);
	}
	*(destinationCharArray + count) = '\0';

	return destinationCharArray;
}

/*stringAdd String Concatenation Function:
Duplicates C-string concatenation strcat function.
Acceppts two pointers to C-strings as arguments and copies the contents
of secondWord to firstWord.*/
char* stringAdd(char *firstWord, const char *secondWord)
{
	char *returnValue = firstWord;
	int count = 0;
	while (*firstWord != '\0')
	{
		firstWord++;			//moves the destination word pointer to the position before its null terminator
		count++;
	}
	count++;
	while (*secondWord != '\0')
	{
		*firstWord++ = *secondWord++;	// appends the source characters to location pointed in destination word, until
										// a null terminator is found in the source word.
		count++;
	}
	*(firstWord + count) = '\0';  //  add a \0 at the end
	return returnValue;			// returns pointer to destination word

}


/* stringCompare String Comparison Function:
Mimics C-string comparison  strcmp function.
Accepts two pointers to C-strings as arguments and returns an
int value that shows how the strings compare to each other. */
int stringCompare(const char *firstWord, const char *secondWord)
{
	while ((*firstWord != '\0') && (*firstWord == *secondWord))	// loops through firstWord until null terminator and compares
	{                                                           // each character of firstWord to secondWor
		firstWord++;
		secondWord++;
	}

	if ((*firstWord - *secondWord) > 0)		// firstWord is larger
		return 1;

	else if ((*firstWord - *secondWord) == 0)	// both words are identical
		return 0;

	else					// secondWord is larger
		return -1;

}
