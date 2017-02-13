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
	char str1[55] = "";         //double length, so str1 can hold str1 + str2
	char str2[LENGTH] = "";  //  initialized  both arrays filled with \0

	char choice = '0';     //to hold the menu choice from 1-4
						   //Fabiane: by changing the choice variable to char (instead of int), some things didn't work that well when I tested it
						   //Example: If I typed 33, it accepted it as menu option 3, when it should have returned the default option
						   //You must have had a good reason to change it to char, but if not, could we make this an int again?

	int stringNCopyNumber = 0; //Fabiane: this variable isn't used in this scope (DELETE)
	int count = 0;  //  loop counter //Fabiane: this variable isn't used in this scope (DELETE)

					// To display the menu and get a choice from user
	cout << "Enter the number that corresponds to the string manipulation to be performed:\n\n"
		<< "    1. String length.\n"
		<< "    2. String copy\n"
		<< "    3. String concatenation\n"
		<< "    4. String comparison.\n\n";

	//To give user the possibility to repeat the menu
	char again = 'y';
	do
	{
		cout << "Enter your choice and press [ENTER]: " << endl;
		cin >> choice;
		cin.clear();
		cin.ignore();
		switch (choice)

		{
		case '1':  //  stringLength function
		{
			inputSingleString(str1, LENGTH);                    // single word input
			int len = stringLength(str1);                       // return word length to len variable
			cout << "Word has " << len << " characters \n";
			break;
		}

		case '2':  //  stringNCopy function
		{
			char *stringNCopyPointer = nullptr;
			count = 0;
			stringNCopyNumber = 0;
			inputSingleString(str2, LENGTH);
			cout << "enter the number of characters to copy: ";
			cin >> stringNCopyNumber;
			//stringNCopy(str1);
			stringNCopyPointer = stringNCopy(str1, str2, stringNCopyNumber);
			cout << "stringNCopy returns: ";  // clifford - added this is in

			while (*(stringNCopyPointer + count) != 0)
			{
				cout << *(stringNCopyPointer + count);
				count++;
			} //Fabiane: Is this loop really needed? For me worked with the C-string name alone.
			cout << endl;
			break;
		}

		case '3':  //  stringAdd function
		{
			inputDoubleString(str1, str2, LENGTH);   // double word input
			char *concatenatedWords = nullptr;
			concatenatedWords = stringAdd(str1, str2);         // returns concatenated words
			cout << "stringAdd returns: ";
			count = 0;
			while (*(concatenatedWords + count) != '\0')  // clifford - added this is in
			{
				cout << *(concatenatedWords + count);
				count++;
			} //Fabiane: Same as in previous case: is this loop really needed? Worked for me without it.
			cout << endl;
			break;
		}

		case '4':  //  stringCompare function
		{
			inputDoubleString(str1, str2, LENGTH);  // double word input
			int comp = stringCompare(str1, str2);  // returns value of compared words

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
			cin.ignore(10000, '\n');  //Fabiane: had to remove this line completely for keyboard input to work correctly
		}


		}

		cout << "\nManipulate another string? [Y/N]";
		cin.clear();
		cin.ignore(10000, '\n'); //Fabiane: had to remove this line same as above
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
	// get an array address pointer, then use a loop to count the characters in the array until a null terminator is found
	// return the length of the array not counting the \0

	int count = 0;
	while (*(charArrayFromMain + count) != '\0')
	{
		count++; // Go to the next char in the string.
	}
	return count;
}

char *stringNCopy(char *destinationCharArray, char *sourceCharArray, int stringNCopyNumber)
{
	//  get the address  for the source char array, the destination array, and a number sent from main
	//  run the loop based on the number that was sent from main, or until a \0 is found
	//  each time the loop runs, copy the character from the source array and put it in the destination array
	//  add a \0 at the end of the destination array
	//  return the memory address of the destination array

	int count = 0;  //  counter
	for (count = 0; count < stringNCopyNumber && (*(sourceCharArray + count) != '\0'); count++)
	{
		*(destinationCharArray + count) = *(sourceCharArray + count);
	}
	*(destinationCharArray + count) = '\0';  //  Place a null character in 

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
