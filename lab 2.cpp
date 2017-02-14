/*
CIS22B
Lab 02
Name:
Program Description: This program will offer the user a menu choice to perform C-string operations.
The user will choose the desired string operation, input the requested arguments and get the
results displayed.
Pseudocode:
Display menu choices to user.
In a do-while loop, prompt user for a menu choice.
If choice is not valid:
Displays to user that choice was not valid.
Prompt if user wants to return to menu or exit.
If choice is valid:
Prompt user to input required arguments to perform operations.
Display results of operation to console.
Prompt if user wants to return to menu for new operation or exit.
If user requests new operation, return him back to menu.
Else, exits the program.
*/


#include <iostream>
#include <string>

using namespace std;

//Function prototypes:
void inputSingleString(char *string1, size_t size);
void inputDoubleString(char *string1, char *string2, size_t);
size_t stringLength(const char *charArrayFromMain);
char *stringNCopy(char *charArrayFromMain, const char*, size_t);
char* stringAdd(char *dest, const char *src);
int stringCompare(const char *firstWord, const char *secondWord);

int main()
{
	// C-string arrays for user input
	const size_t LENGTH = 21;
	char str1[2 * LENGTH] = "";   //double length, so str1 can hold str1 + str2
	char str2[LENGTH] = "";     // initialized both arrays filled with \0

								// To display the menu and get a choice from user
	cout << "Enter the number that corresponds to the string manipulation to be performed:\n\n"
		<< " 1. String length.\n"
		<< " 2. String copy\n"
		<< " 3. String concatenation\n"
		<< " 4. String comparison.\n\n";


	int choice = 0; //to hold the menu choice from 1-4

					//To give user the possibility to repeat the menu
	char again = 'y';

	do
	{
		cout << "Enter your choice and press [ENTER]: " << endl;
		cin >> choice;
		cin.clear();
		cin.ignore(1000, '\n');


		switch (choice)
		{
		case 1: // stringLength function
		{
			inputSingleString(str1, LENGTH);        // single word input
			size_t len = stringLength(str1);        // return word length to len variable
			cout << "Word has " << len << " characters \n";
			break;
		}
		case 2: // stringNCopy function
		{
			char *stringNCopyPointer = nullptr;
			size_t stringNCopyNumber = 0;
			inputSingleString(str2, LENGTH);       // single word input
			cout << "enter the number of characters to copy: ";

			cin >> stringNCopyNumber;
			while ((!stringNCopyNumber) || (stringNCopyNumber >= LENGTH)) //validation number of characters to be copied
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Only positive numbers between 1-" << LENGTH - 1 << " are valid. Re-enter number: ";
				cin >> stringNCopyNumber;
			}

			stringNCopyPointer = stringNCopy(str1, str2, stringNCopyNumber);  // returns n copied charaters from user input
			cout << "stringNCopy returns: " << stringNCopyPointer << endl;
			break;
		}

		case 3: // stringAdd function
		{
			inputDoubleString(str1, str2, LENGTH);     // double word input
			char *concatenatedWords = nullptr;
			concatenatedWords = stringAdd(str1, str2); // returns concatenated words
			cout << "stringAdd returns: " << concatenatedWords << endl;
			break;
		}

		case 4: // stringCompare function
		{
			inputDoubleString(str1, str2, LENGTH);     // double word input
			int comp = stringCompare(str1, str2);      // returns value of compared words
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
			cout << "This value is not a choice in this menu.\n" << "You must enter 1, 2, 3 or 4! \n";
		}
		}

		cout << "\nReturn to the menu? [Y/N]";

		cin >> again;
		cin.clear();

	} while (again == 'y' || again == 'Y');

	system("pause");

	return 0;
}



/* Single String Input Function:
Accepts one input string with a defined size limit, including space for the null terminator.
Inputted word is saved as a C-string to destination through a pointer. */
void inputSingleString(char *string1, size_t size)
{
	string s1;

	do
	{
		cout << "Enter a word with " << size - 1 << " or less characters: " << endl;
		cin >> s1;

		if (s1.size() > size - 1)             // to validate the maximum amount of characters allowed for the input;
			cout << "Word needs to be " << size - 1 << " or less characters!\n";

	} while (s1.size() > size - 1);           // loop while the user hasn't inputted a valid string

	stringNCopy(string1, s1.c_str(), size); // call own stringNCopy function to put inputed string into character array


}



/* Double String Input Function:
Accepts two input strings with a defined size limit, including space for the null terminator.
Inputted words are saved as a C-string to destination through pointers. */
void inputDoubleString(char *string1, char *string2, size_t size)
{
	string s1;

	do
	{
		cout << "Enter the first word with " << size - 1 << " or less characters: " << endl;
		cin >> s1;
		if (s1.size() > size - 1)            // to validate the maximum amount of characters allowed for the input;
			cout << "Word needs to be " << size - 1 << " or less characters!\n";
	} while (s1.size() > size - 1);           // loop while the user hasn't inputted a valid string

	stringNCopy(string1, s1.c_str(), size); // call own stringNCopy function to put inputed string into character array


											// do the same as above for the second word:
	do
	{
		cout << "Enter the second word with " << size - 1 << " or less characters: " << endl;
		cin >> s1;
		if (s1.size() > size - 1)
			cout << "Word needs to be " << size - 1 << " or less characters!\n";
	} while (s1.size() > size - 1);

	stringNCopy(string2, s1.c_str(), size);

}



size_t stringLength(const char *charArrayFromMain)
{
	// get an array address pointer, then use a loop to count the characters in the array until a null terminator is found
	// return the length of the array not counting the \0
	size_t count = 0;
	while (*(charArrayFromMain + count) != '\0')
	{
		count++; // Go to the next char in the string.
	}
	return count;
}



char *stringNCopy(char *destinationCharArray, const char *sourceCharArray, size_t stringNCopyNumber)
{
	// get the address for the source char array, the destination array, and a number sent from main
	// run the loop based on the number that was sent from main, or until a \0 is found
	// each time the loop runs, copy the character from the source array and put it in the destination array
	// add a \0 at the end of the destination array
	// return the memory address of the destination array
	size_t count = 0; // counter
	for (count = 0; count < stringNCopyNumber && (*(sourceCharArray + count) != '\0'); count++)
	{
		*(destinationCharArray + count) = *(sourceCharArray + count);
	}
	*(destinationCharArray + count) = '\0';      // Place a null character in
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
		firstWord++;                    //moves the destination word pointer to the position before its null terminator
		count++;
	}
	count++;
	while (*secondWord != '\0')
	{
		*firstWord++ = *secondWord++;  // appends the source characters to location pointed in destination word, until
									   // a null terminator is found in the source word.
		count++;
	}
	*(firstWord + count) = '\0';    // add a \0 at the end

	return returnValue;             // returns pointer to destination word
}





/* stringCompare String Comparison Function:
Mimics C-string comparison strcmp function.
Accepts two pointers to C-strings as arguments and returns an
int value that shows how the strings compare to each other. */
int stringCompare(const char *firstWord, const char *secondWord)
{
	while ((*firstWord != '\0') && (*firstWord == *secondWord)) // loops through firstWord until null terminator and compares
	{                                                           // each character of firstWord to secondWor
		firstWord++;
		secondWord++;
	}
	if ((*firstWord - *secondWord) > 0)         // firstWord is larger
		return 1;
	else if ((*firstWord - *secondWord) == 0)   // both words are identical
		return 0;
	else                                        // secondWord is larger
		return -1;
}
