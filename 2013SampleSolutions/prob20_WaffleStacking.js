
"use strict";

importPackage(java.io);
importPackage(java.lang);
var stdin = new BufferedReader( new InputStreamReader(System['in']) );

function readLine()
{
    // stdin.readLine() returns a Java String. yuck.
    // convert it to a JavaScript string
    return String( stdin.readLine() );
};

function trim(s)
{
   return s.replace(/^\s+/g,'').replace(/\s+$/g,'');
};

// enumerate turns an array of strings (read from input) into an array of integers
function enumerate(a)
{
   for( var i=0; i<a.length; i++ )
       if( typeof( a[i] ) === "string" )
           a[i] = parseInt( a[i] );
   return a;
};

// getPermutations produces an array of rows, where each row is
// a unique permutation of the numbers 1 through N
function getPermutations( items, n )
{
    var list = [ ];
    if( n === 1 )
    {
        for( var i=0; i<items.length; i++ )
            list.push( [ items[i] ] );
    }
    else
    {
        for( var i=0; i<items.length; i++ )
        {
            var subItems = [ ];
            for( var j=0; j<items.length; j++ )
            {
                if( i !== j )
                    subItems.push( items[j] );
            }
            var subList = getPermutations( subItems, n-1 );
            for( var s=0; s<subList.length; s++ )
                subList[s].push( items[i] );
            list = list.concat( subList );
        }
    }
    return list;
};

//validateRow verifies that a single row of the grid matches the clues 
function validateRow( rowData, size, L, R )
{
    var max;
    var left = 1;
    max = rowData[0];
    for( var i=1; i<size; i++ )
    {
        if( rowData[i] > max )
        {
            max = rowData[i];
            ++left;
        }
    }
    var right = 1;
    max = rowData[size-1];
    for( var i=size-2; i>=0; i-- )
    {
        if( rowData[i] > max )
        {
            max = rowData[i];
            ++right;
        }
    }
    return ( left === L && right === R );
};

// validateCol verifies that a single column of the grid matches the clues 
function validateCol( grid, size, colNum, T, B )
{
    var max;
    var top = 1;
    max = grid[0][colNum];
    for( var i=1; i<size; i++ )
    {
        if( grid[i][colNum] > max )
        {
            max = grid[i][colNum];
            ++top;
        }
    }
    var bottom = 1;
    max = grid[size-1][colNum];
    for( var i=size-2; i>=0; i-- )
    {
        if( grid[i][colNum] > max )
        {
            max = grid[i][colNum];
            ++bottom;
        }
    }
    return ( top === T && bottom === B );
};

// hasUniqueColumns verifies that there are no duplicate numbers in any column 
function hasUniqueColumns( grid, numRows, numCols )
{
    var isUnique = true;
    for( var c=0; c<numCols && isUnique; c++ )
    {
        for( var r=0; r<numRows && isUnique; r++ )
        {
            for( var r2=r+1; r2<numRows && isUnique; r2++ )
                isUnique = ( grid[r][c] !== grid[r2][c] );
        }
    }
    return isUnique;
};

// getGrid is a recursive function that searches for a solution
// parameters:
//    grid - the current solution grid (may be incomplete)
//    rowPermutations - the pre-computed set of row permutations
//    size - the grid size
//    L, R, T, B - arrays of the clues; left, right, top, bottom
function getGrid( grid, rowPermutations, row, size, L, R, T, B )
{
    var success = false;
    // if row equals size, then the grid is completely filled in and all of
    // the columns need to be verified. if the column verification passes,
    // then the solution is correct.
    if( row === size )
    {
    	success = true;
        for( var col=0; col<size && success; col++ )
        {
            success = validateCol( grid, size, col, T[col], B[col] );
        }
    }
    else
    {
        // try every permutation for the current row
        for( var p=0; !success && p<rowPermutations.length; p++ )
        {
            // validate the permutation before adding it to the grid
            // this is the second optimization: validate this part of the
            // solution early and so avoid lots of incorrect guesses.
            if( validateRow( rowPermutations[p], size, L[row], R[row] ) )
            {
                grid[row] = rowPermutations[p];
                // check to make sure all the values in each column are unique
                // this is the third optimization
                if( hasUniqueColumns( grid, row+1, size ) )
                    success = getGrid( grid, rowPermutations, row+1, size, L, R, T, B );
                // for( var r=0; r<=row; r++ )
                //     print( grid[r] );
                // print( success ? "SUCCESS" : "FAIL" );
                if( !success ) grid[row] = [ 0, 0, 0, 0, 0 ]; // useful for debugging
            }
        }
    }
    return success;
};

function unitTest()
{
    var testGrid =
        [
            [ 1,3,2,4,5 ],
            [ 5,2,4,3,1 ],
            [ 2,1,3,5,4 ],
            [ 4,5,1,2,3 ],
            [ 3,4,5,1,2 ]
        ];
    var size = 5;
    var T = [ 2, 2, 3, 2, 1 ];
    var L = [ 4, 1, 3, 2, 3 ];
    var R = [ 1, 4, 2, 2, 2 ];
    var B = [ 3, 2, 1, 3, 4 ];

    print( "UNIQUE: " + ( hasUniqueColumns(testGrid,5,5) ? "PASS" : "FAIL" ) );
    for( var i=0; i<5; i++ )
        print( "ROW" + i + ": " + ( validateRow( testGrid[i], size, L[i], R[i] ) ? "PASS" : "FAIL" ) );
    for( var i=0; i<5; i++ )
        print( "COL" + i + ": " + ( validateCol( testGrid, size, i, T, B ) ? "PASS" : "FAIL" ) );
};

main();

function main()
{
    var i, size = parseInt( readLine() );

    var T = enumerate( trim( readLine() ).split(/\s/) );
    var L = enumerate( trim( readLine() ).split(/\s/) );
    var R = enumerate( trim( readLine() ).split(/\s/) );
    var B = enumerate( trim( readLine() ).split(/\s/) );

    // on one hand, a brute force algorithm would take too long to execute.
    // on the other hand, I'm too lazy to devise an elegant solution.
    // so this is a divide-and-conquer approach to brute force that reduces
    // the search space by several orders of magnitude so the program will
    // find a solution in seconds instead of days.

    // make an array of number from 1 to N
    var sourceItems = [ ];
    for( i=0; i<size; i++ )
        sourceItems.push(i+1);

    // now make a list of all possible permutations of the number 1 to N
    // this is the first optimization: the search is limited to rows of
    // unique combinations of the numbers 1 to N
    var rowPermutations = getPermutations( sourceItems, size );

    var grid = [ [], [], [], [], [] ];
    // search for combinations of rows that match the clues L, R, T, B 
    getGrid( grid, rowPermutations, 0, size, L, R, T, B );

    for( var row=0; row<size; row++ )
        print( grid[row] );
        
};
