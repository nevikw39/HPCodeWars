#include <stdio.h>
#include <string.h>

#define CHARACTER_LOWER_CASE_A 0x41
#define CHARACTER_LOWER_CASE_Z 0x5a
#define CHARACTER_UPPER_CASE_A 0x61
#define CHARACTER_UPPER_CASE_Z 0x7a

int main(int argc, char *argv[]) {
  char index;
  char input[80] = "";
  
  //
  // Copy input string
  //
  strcpy (input, argv[1]);
  
  //
  // Revise input string once a character
  //
  for (index = 0; index < strlen (input); index++) {
    if (input[index] >= CHARACTER_LOWER_CASE_A && input[index] <= CHARACTER_LOWER_CASE_Z) {
      
      //
      // Revise lower case character
      //
      input[index] = CHARACTER_LOWER_CASE_Z - (input[index] - CHARACTER_LOWER_CASE_A);
    } else if (input[index] >= CHARACTER_UPPER_CASE_A && input[index] <= CHARACTER_UPPER_CASE_Z) {
      
      //
      // Revise upper case character
      //
      input[index] = CHARACTER_UPPER_CASE_Z - (input[index] - CHARACTER_UPPER_CASE_A);
    }
  }
  
  //
  // Output result
  //
  printf ("%s\n", input);
  
  return 0;
}
