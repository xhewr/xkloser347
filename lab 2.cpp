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
Prompt user to imput arguments to perform operations.
Display results of operation to user.
Prompt if user wants to return to menu for new operation or exit.
If user requests new operation, return him back to menu.
Else, exists the program.
*/


#include <iostream>
using namespace std;

//Function prototypes:
void inputSingleString(char *string1, const int size);
void inputDoubleString(char *string1, char *string2, const int size);
int stringLength(char *charArrayFromMain);
char *stringNCopy(char *charArrayFromMain);
char* stringAdd(char *dest, const char *src);
int stringCompare(const char *firstWord, const char *secondWord);

int main()
{
	// C-string arrays for user input
	const int LENGTH = 25;
	char str1[55] = {};         //double length, so str1 can hold str1 + str2
	char str2[LENGTH] = {};  //  clifford - I was having errors here with the output, so I intialized both arrays filled with \0
				 //  also added a few extra to the array sizes to pad for some unforseen problems. 

	int choice = 0;     //to hold the menu choice from 1-4
	int count = 0;  // clifford - loop counter

						// To display the menu and get a choice from user
	cout << "Enter the number that corresponds to the string manipulation to be performed:\n\n"
		<< "    1. String lenght.\n"
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
		case 1:  //  stringLength function
		{
			inputSingleString(str1, LENGTH);                    // single word input
			int len = stringLength(str1);                       // return word lenght to len variable
			cout << "Word has " << len << " characters \n";
			break;
		}

		case 2:  //  stringNCopy function
		{
			/*FF: This function takes 3 parameters (2 string pointers + 1 int) for the amount of
			characters to be copied from source to destination. I used single input string
			because your function only took a single input and I wanted to test the menu. */
			char *stringNCopyPointer = nullptr;
			count = 0;
			inputSingleString(str1, LENGTH);
			//stringNCopy(str1);
			stringNCopyPointer = stringNCopy(str1);
			cout << "stringNCopy returns: ";  // clifford - added this is in
			while (*(stringNCopyPointer + count) != 0)
			{
				cout << *(stringNCopyPointer + count);
				count++;
			}
			cout << endl;
			break;
		}

		case 3:  //  stringAdd function
		{
			inputDoubleString(str1, str2, LENGTH);   // double word input
			stringAdd(str1, str2);                   // returns concatenated words
			cout << "Here are your concatenated words: ";
			count = 0;
			while (*(str1 + count) != '\0')  // clifford - added this is in
			{
				cout << *(str1 + count);
				count++;
			}
			cout << endl;
			break;
		}

		case 4:  //  stringCompare function
		{
			inputDoubleString(str1, str2, LENGTH);  // double word input
			int comp = stringCompare(str1, str2);  // returns value of compared words

			if (comp == 0)
				cout << "You inputed identical words.";

			else if (comp > 0)
				cout << "The words are different: '" << str2 << "' comes before '" << str1 << "' alphabetically\n";

			else
				cout << "The words are different: '" << str1 << "' comes before '" << str2 << "' alphabetically\n";
			break;
		}

		default: 
		{
			cout << choice << " is not a choice in this menu.\n" << "You must enter 1, 2, 3 or 4! \n";
		}


		}

		cout << "\nManipulate another string? [Y/N]";
		cin >> again;
		cin.clear();

	} while (again == 'y' || again == 'Y');

	//  clifford - having trouble trying to delete dynamically created memory that is NOT in an array

	//delete[]charPointer;  // free up the memory again
	//for (count = 0; count < (stringLengthReturnValue + 1); count++)
	//{
	//	delete (charPointer + count);
	//}
	//charPointer = nullptr;

	//cin.get();
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
	cout << "Enter a first word with 20 or less characters: " << endl;
	cin.getline(string1, size);
	cin.clear();
	cout << "Enter a second word with 20 or less characters: " << endl;
	cin.getline(string2, size);
	cin.clear();
}

int stringLength(char *charArrayFromMain)
{
	// get an array adress pointer, then use a loop to count the characters in the array until a null terminator is found
	// return the length of the array not counting the \0

	int count = 0;
	while (*(charArrayFromMain + count) != '\0')
	{
		count++; // Go to the next char in the string.
	}
	return count;
}

char *stringNCopy(char *charArrayFromMain)
{
	// I wrote this function with out using arrays as per instructed.
	// uses a loop to count how many characters are in the array and creates a new char each time the loop runs
	// another loops copies the char array sent from main into the new chars made in this function
	// returns the memory location

	int count = 0;  // loop counter
	char *returnPointer = nullptr;

	while (*(charArrayFromMain + count) != '\0')  // this is the same as tempPointer = new char[count], only with out an array
	{
		returnPointer = new char;
		count++;
	}
	returnPointer = new char;  // +1 new char for the \0
	count++;  // increment the counter

	//cout << *(returnPointer) << endl;
	//returnPointer -= count;

	for (count = 0; *(charArrayFromMain + count) != '\0'; count++)
	{
		*(returnPointer + count) = *(charArrayFromMain + count);
	}
	*(returnPointer + count) = '\0'; // Place a null character in 

	return returnPointer;
}


char *stringNCopyWithArray(char *charArrayFromMain)  // I wll ask which one we should use
{
	// get the array from main, then call stringLength function to the get size.
	// create a pointer, then make it point to a char array the size of stringLength + 1
	// run a loop to fill the new chars with the chars sent from the main function
	// return the pointer's memory location

	int count = 0;  // loop counter

	while (*(charArrayFromMain + count) != '\0')  //  get the number of chars before the \0
	{
		count++;
	}

	const int ARRAYSIZE = count + 1;  // the plus one is for the \0 to be added
	char *arrayPointer = nullptr;  // create memory pointer for the start of the array
	arrayPointer = new char[ARRAYSIZE];  // create a character array to copy the characters into

	for (count = 0; *(charArrayFromMain + count) != '\0'; count++)  // run the loop to copy one char array into the other char array
	{
		*(arrayPointer + count) = *(charArrayFromMain + count);
	}
	*(arrayPointer + count) = '\0'; // Place a null character in 

	return arrayPointer;
}

/*stringAdd String Concatenation Function:
Duplicates C-string concatenation strcat function.
Acceppts two pointers to C-strings as arguments and copies the contents
of secondWord to firstWord.*/
char* stringAdd(char *firstWord, const char *secondWord)
{
	int count = 0;
	while (*firstWord != '\0')
	{
		firstWord++;			//moves the destination word pointer to the position before its null terminator
		count++;
	}
	count++;
	while (*secondWord != '\0')
	{
		*firstWord++ = *secondWord++;	// appends the source characters to location pointed in destination word, untill
										// a null terminator is found in the source word.
		count++;
	}
	*(firstWord + count) = '\0';
	return firstWord;			// returns pointer to destination word

}


/* stringCompare String Comparison Function:
Mimics C-string camparison strcmp function.
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
