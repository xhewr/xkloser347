#include <iostream>
using namespace std;

int stringLength(char *);
char *stringNCopy(char *);
//void stringAdd();
//void stringCompare();


int main()
{
	char choice;
	//cout << "Enter A, B, or C: ";
	//cin >> choice;
	/*switch (choice)
	{
		case 'a': cout << "You entered A.\n";
		{
			break;
		}
		case 'A': cout << "You entered A.\n";
		{
			break;
		}
		case 'b': cout << "You entered B.\n";
		{
			break;
		}
		case 'c': cout << "You entered C.\n";
		{
			break;
		}
		default: cout << "You did not enter A, B, or C!\n";
	}*/
	cout << "sending character array to stringLength function... \n";
	char test[99] = "12345678";
	int stringLengthReturnValue = stringLength(test);
	cout << "this is what stringLength returns: " << stringLengthReturnValue << endl;
	cout << "sending array to stringNCopy function... \n";
	char *charPointer = nullptr;
	charPointer = stringNCopy(test);
	cout << "this is what the stringNCopy returns: ";
	for (int count = 0; count < (stringLengthReturnValue + 2); count++)  // the +2 is for the the 'X' I added and the \0 
	{
		cout << *(charPointer + count);
	}

	delete []charPointer;  // free up the memory again
	charPointer = nullptr;
	cin.get();
	return 0;
}

int stringLength(char *charArrayFromMain)
{
	// get an array adress pointer, then use a loop to count the characters in the array until a null terminator is found
	// return the length of the array not counting the \0
	int count = 0;
	while (*charArrayFromMain != '\0')
	{
		//if (*strPtr == ch) // If the current character equals ch...
		//	count++; // ... increment the counter
		charArrayFromMain++;
		count++; // Go to the next char in the string.
	}
	//cout << "string has " << count << " length \n";
	return count;
}

char *stringNCopy(char *stringArrayFromMain)
{
	// get the array from main, then call stringLength function to the get size.
	// create a pointer, then make it point to a char array the size of stringLength + 2
	// the plus two becuase I add and 'X' and then the null char \0
	// return the pointer's memory location

	cout << "this is stringNCopy function... \n";  
	int count = 0;  // loop counter

	
	const int ARRAYSIZE = stringLength(stringArrayFromMain) + 2;  // the plus is the the extra X and the \0
	//arrayPointer = new char[stringLength(stringArrayFromMain) + 1];
	char *arrayPointer = nullptr;  // create memory pointer for the start of the array
	arrayPointer = new char[ARRAYSIZE];  // create a character array


	for (count = 0; *(stringArrayFromMain + count) != '\0'; count++)
	{
		*(arrayPointer + count) = *(stringArrayFromMain + count);
		cout << *(arrayPointer + count);
	}
	*(arrayPointer + count) = 'X'; // prove the function worked 
	//arrayPointer++;  // move the pointer one memory slot over
	count++; // add one to the counter
	*(arrayPointer + count) = '\0'; // Place a null character in 
	//count++;
	cout << endl;

	//cout << *arrayPointer << endl;
	//for (int x = 0; x < count; x++)
	//{
	//	cout << *arrayPointer;
	//	arrayPointer++;
	//}
	//cout << endl;
	//arrayPointer--;
	return arrayPointer;
	//delete []arrayPointer;  // free up the memory again
}

void stringAdd()
{
	cout << "stringAdd function \n";
}

void stringCompare()
{
	cout << "stringCompare function \n";
}