/*
   Room for an Argument

   Example input:
4
This is not an argument.
An argument is an intellectual process.
It is fair if you do not go.
The ferris wheel is not working.


   Example Output:
This is an argument.
An argument is not an intellectual process.
It is not fair if you do not go.
The ferris wheel is working.

*/

#include <string>
#include <iostream>

using namespace std;

char * is = "is";
char * not = "not";
char * notSpace = "not ";
char * spaceNot = " not";
char * space = " ";

void getNextWord(char * word, char *nextChar)
{
	int wordIndex=0;
	char m = getchar();

	while ( (m!=' ') && (m!='.') && (m!='\n'))
	{
		word[wordIndex++] = m;
		m = getchar();
	}
	*nextChar = m;
}

int main( int argc, char* argv[] )
{
	char word[80];
	int numLines;
	char m, m2;

	// Prompt
	cout << endl << "Input number of lines, then all the lines." << endl;

	cin >> numLines;
	numLines++; // Account for return after first entry.

	while (numLines) {
		memset (word, 0, sizeof(word));
		m=m2=0;

		//Scan for a word
	    getNextWord(word, &m);
		// Always print the word (likely empty if m is new line)
		cout << word;
		
		if (strcmp(word, is) != 0)
		{
			cout << m;
			if (m=='\n') numLines--;
			continue; // Not the word "is".  Print and continue loop
		}

		// Found "is".  Check for "not".
		memset (word, 0, sizeof(word));
		getNextWord(word, &m2);
		if (strcmp(word, not) != 0) // next word is not "not"
		{
			cout << spaceNot;  // add "not"
			cout << m << word; // Print the space and next word
		}
		// If we do find "not", we leave it out and just print the following character
		cout << m2; // Print the trailing character

		if (m=='\n') numLines--;
		if (m2=='\n') numLines--;
	}
	//cout << endl << "0 to exit: ";
	//cin >> numLines;
}