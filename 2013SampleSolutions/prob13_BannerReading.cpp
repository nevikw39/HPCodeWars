/*
   Read Banner text (3x5 high characters) and decode

   Example input:
 ##  #  ##  ### # # ### ###  ##     ### ### ##  ###     ###  #   ## # #  ##
#   # # # # #   # # # # # # #         # # #  #    #     # # # # #   # # #  
#   # # # # ### # # ### ##   #      ### # #  #  ###     ##  # # #   ##   # 
#   # # # # #   ### # # # #   #     #   # #  #    #     # # # # #   # #   #
 ##  #  ##  ### # # # # # # ##      ### ### ### ###     # #  #   ## # # ## 

   Example Output:
   CODEWARS 2013 ROCKS
*/

#include <string>
#include <iostream>

using namespace std;

#define MAX_LETTER_ARRAY 37
char L[MAX_LETTER_ARRAY][5][3]; // Array of Banner Letters, one for each ASCII character
char banner[5][120];

void initLetters(void)
{
char * all[]={
"### ##  ### ### # # ### ### ### ### ### ",
"# #  #    #   # # # #   #     # # # # # ",
"# #  #  ### ### ### ### ###   # ### ### ",
"# #  #  #     #   #   # # #   # # #   # ",
"### ### ### ###   # ### ###   # ### ### ",
"### ###  ## ##  ### ###  ## # # ###   # # # #   # #      #  ### ### ###  ## ### # # # # # # # # # # ### ",
"# # # # #   # # #   #   #   # #  #    # # # #   ###     # # # # # # # # #    #  # # # # # # # # # #   # ",
"### ##  #   # # ### ### # # ###  #    # ##  #   # # ### # # ### ### ##   #   #  # # # # # #  #   #   #  ",
"# # # # #   # # #   #   # # # #  #  # # # # #   # # # # # # #     # # #   #  #  # # # # ### # #  #  #   ",
"# # ###  ## ##  ### #   ##  # # ### ### # # ### # # # #  #  #     # # # ##   #  ###  #  # # # #  #  ### "};


	int i,row,col, index;
	memset (L, ' ', sizeof(L));
	memset (banner, ' ', sizeof(banner));

	// Digits
	row=0;
	while (row<5)
	{
		i=0; col=0; index=0;
		do {
			L[i][row][col++] = all[row][index++];
			if (col==3)
			{ // next character
				i++; col=0; index++;
			}
		} while (i<=9); // Digits are in spots 0-9
		row++;
	}
	// spot 10 is a space

	// Letters
	while (row<10)
	{
		i=11; col=0; index=0;
		do {
			L[i][row-5][col++] = all[row][index++];
			if (col==3)
			{ // next character
				i++; col=0; index++;
			}
		} while (i<=36); // Letters are in spots 11-36
		row++;
	}
}

char findMatchingChar(int bannerLoc)
{
	int i,row,col;
	bool matchFound=false, match;
	char m='.';
	// Look through all characters
	for (i=0;(i<MAX_LETTER_ARRAY) && !matchFound;i++)
	{
		match=true; // start by assuming all 3x5 characters match.
		for (row=0;(row<5) && match; row++)
			for (col=0;(col<3) && match; col++)
				if (banner[row][bannerLoc+col] != L[i][row][col])
					match = false;
		matchFound = match;
	}

	if (matchFound)
	{
		i--;
		if (i<10) m = '0'+i;
		else if (i==10) m = ' ';
		else m = 'A'+i-11; // 11-36 are A-Z
	}
	return m;
}

#define DEBUG 1 // For debug print statements

int main( int argc, char* argv[] )
{
	int lineLength, row, col;
	char m;

	initLetters();

	// Prompt
	cout << endl << "Input the five banner lines." << endl;

	row=0; col=0; lineLength=0;	 

	while (row<5) // Read in full banner
	{
		m=getchar();
		if (m=='\n')
		{ 
			row++; 
			if (col>lineLength) lineLength=col;
			col=0;
		}
		else
		{
			banner[row][col++]=m;
		}
	}
	for (col=0;col<lineLength;col+=4)
	{
		cout << findMatchingChar(col);
	}

	cout << endl; // Print end of line

//	cout << "0 to end." <<endl;
//	cin >> col;
}