//
//  main.c
//  InversionForCodeWars2017
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define population 4 // Mr.Wang + A + B + C
#define readsize (2 * 100 * population * 2)
//
// Merge subroutine.
//

void
MergeCountInv (int *fh, int *sh, int s, int *mm, long *Inn)
{
    int i, j, k;
    long count;
    int sizeF, sizeS;

    count = 0; // count inversions.
    *Inn = 0; // initialize returned inversion count.
    sizeF = s - s/2;
    sizeS = s/2;

    for (i = 0, j = 0, k = 0; k < s; k++) {

        //
        // if i not drained yet,
        //

        if (i < sizeF) {

            //
            // if j has been drained, then choose i
            //

            if (j >= sizeS) {
                mm[k] = fh[i];
                i++;
            } else {

                //
                // if j has not been drained
                //

                if (fh[i] < sh[j]) {

                    //
                    // and fh[i] < sh[j], choose i,
                    //

                    mm[k] = fh[i];
                    i++;
                } else if (fh[i] == sh[j]) {
                    mm[k] = fh[i];
                    i++;
                    k++;
                    mm[k] = sh[j];
                    j++;
                } else if (fh[i] > sh[j]) {
                    mm[k] = sh[j];
                    // Inversion! i<j and A[i]>A[j].
                    count = count + (sizeF - i) ;
                    j++;
                }
            }
        } else {
            mm[k] = sh[j];
            j++;
        }
    }
    *Inn = count;
    //printf ("%ld\n", *Inn);
    return;
}

//
// Given an input array of size "size", sort it and return the sorted array.
//
void
SortIt (int *target, int size, long *Inv)
{
    int i;
    int size1, size2;
    long leftInv, rightInv, splitInv;
    int *left;
    int *right;
    int *temp;

    leftInv = 0;
    rightInv = 0;
    splitInv = 0;
    *Inv = 0;

    if (size == 1) { // base case
        return;
    }

    temp = (int*)malloc (size * sizeof (int));

    size2 = size / 2;
    size1 = size - size2;

    left = (int*)malloc (size1 * sizeof (int));
    right = (int*)malloc (size2 * sizeof (int));

    for (i = 0; i < size1; i++) {
        left[i] = target[i];
    }
    for (i = 0; i < size2; i++) {
        right[i] = target[size1 + i];
    }
    SortIt (left, size1, &leftInv);
    SortIt (right, size2, &rightInv);

    MergeCountInv (left, right, size, temp, &splitInv);
    *Inv = leftInv + rightInv + splitInv;

    while (size != 0) {
        size--;
        target [size] = temp[size];
    }
    free (left);
    free (right);
    free (temp);
    return;
}


void shuffle(int *array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}


int main(int argc, const char * argv[])
{

    int collect;
    int firstArrayCollected;
    int num;
    char cur;

    int numberCounter;
    int arrayCounter;
    int arrayLength;


    char buffer[readsize] = {0};


    long ttInv[population - 1] = {0};
    int *arrayToBeSorted;


    collect = 0;
    firstArrayCollected = 0;
    num = 0;
    cur = '\0';

    numberCounter = 0;
    arrayCounter = 0;
    arrayLength = 0;

    arrayToBeSorted = NULL;

    //======================================================
    //
    // Generate exam input for the CodeWars 2017 problem.
    //
    //    int lengthOfArray = 60; // should not exceeds RAND_MAX
    //    int arrayToBeShuffled[population][lengthOfArray]; // songlists
    //    for (int i = 0; i < population; i++) {
    //        for (int j = 0; j < lengthOfArray; j++) {
    //            arrayToBeShuffled[i][j] = j + 1; // 1-based value in the array
    //        }
    //    }
    //    for (int i = 0; i < population; i++) {
    //        if(i == 0) continue;
    //        shuffle(arrayToBeShuffled[i], lengthOfArray);
    //    }
    //
    //    // printing out the input data.
    //    for(int i = 0; i < population; i++) {
    //        for (int j = 0; j < lengthOfArray; j++) {
    //            printf("%d",arrayToBeShuffled[i][j]);
    //            if(j == (lengthOfArray - 1)) {
    //                break;
    //            }
    //            printf(","); // seperator btw numbers in an array
    //        }
    //        if(i == (population - 1)) break;
    //        printf(";"); // seperator btw arrays
    //    }
    //======================================================




    fgets (buffer, readsize, stdin);

    //int inputLength = (int) strlen (buffer);
    for (int i = 0;i < readsize; i++) {

        cur = buffer[i];
        if (cur >= 0x30 && cur <= 0x39) {

            //
            // If get a digit, collect it in num.
            //
            num = num * 10 + (cur - 0x30);
            collect = 1;
        } else {

            // First see if any number is collected before this non-numeric character
            if (collect == 1) {
                if (arrayToBeSorted != NULL) {
                    arrayToBeSorted [numberCounter] = num;
//                    printf ("a[%d] = %d\n", numberCounter, arrayToBeSorted[numberCounter]);
                }
                numberCounter++;

                // reset
                num = 0;
                collect = 0;
            }

            // And then see what kind of non-numeric character is encountered
            if (cur == ',') {
                // Encountered a seperator btw numbers in an array
                continue;
            } else if ((cur == ';') || (cur == '\r' || cur == '\n' || cur == '\0')) {


                // Encountered a seperator between arrays
                if (firstArrayCollected == 0) {
                    firstArrayCollected = 1;
                    arrayLength = numberCounter;
//                    printf ("Determined array is %d long\n", arrayLength);
                    arrayToBeSorted = (int*)malloc (arrayLength * sizeof (int));
                } else {

//                    printf("\n\n\n");
//                    printf ("Before sorted, array is ..");
//                    for (int k = 0; k < arrayLength; k++) {
//                        printf ("%d, ", arrayToBeSorted[k]);
//                    }

                    SortIt(arrayToBeSorted, arrayLength, &(ttInv[arrayCounter]));
//                    printf("\n=========Inversion = %ld==============\n", ttInv[arrayCounter]);
                    arrayCounter++;

//                    printf ("After sorted, array is ..");
//                    for (int k = 0; k < arrayLength; k++) {
//                        printf ("%d, ", arrayToBeSorted[k]);
//                    }
//                    printf("\n\n\n");

                    memset (arrayToBeSorted, 0, arrayLength);

                }
                numberCounter = 0;
                // continue to the next array if any
                if (cur == ';') {
                    continue;
                } else {
                    break;
                }
            } else {
                // this should not happen
                break;
            }
        } // // got numeric char or not
    } // for loop

    long ori[3] = {ttInv[0], ttInv[1], ttInv[2]};
    int Answer[population - 1];

    long tempp;
    if (ttInv[0] > ttInv[1]) {
        tempp = ttInv[0];
        ttInv[0] = ttInv[1];
        ttInv[1] = tempp;
    }
    if (ttInv[0] > ttInv[2]) {
        tempp = ttInv[0];
        ttInv[0] = ttInv[2];
        ttInv[2] = tempp;
    }
    if (ttInv[1] > ttInv[2]) {
        tempp = ttInv[1];
        ttInv[1] = ttInv[2];
        ttInv[2] = tempp;
    }

    int indexVisited[3] = {0,0,0};
    for (int i = 0; i < population - 1; i++) {
        for (int j = 0; j < population - 1; j++) {
            if (ttInv[i] == ori[j]) {
                if (indexVisited[j] != 1) {
                    Answer[i] = 0x41 + j;
                    printf("%c", (char)(Answer[i]));
                    indexVisited[j]=1;
                }
            }
        }
    }

    free(arrayToBeSorted);

    return 0;
}
