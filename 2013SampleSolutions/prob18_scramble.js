
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

/// @class  WordText
/// @brief  the role of this class is to read the text and scramble it
function WordText()
{
    this.charList = [ ];
    this.matrix = [ ];
    var numRows = parseInt( readLine() );
    this.readLines();
    this.scramble( numRows );
    this.print( numRows );
    this.getNumRows = function()
    {
        return this.matrix.length;
    };
    this.getNumCols = function()
    {
        return this.matrix[0].length;
    };
};

/// @brief  read the lines of text
WordText.prototype.readLines = function()
{
    var numLines = parseInt( readLine() );
    for( var i=0; i<numLines; i++ )
    {
        var line = readLine();
        // print( "> " + i + " " + line );
        for( var j=0; j<line.length; j++ )
        {
            var c = line[j].toUpperCase();
            if( c.match( /[A-Z]/ ) )
                this.charList.push(c);
        }
    }
};

/// @brief scramble the text by rewriting it top-to-bottom, left-to-right
WordText.prototype.scramble = function( numRows )
{
    for( var r=0; r<numRows; r++ )
    {
        this.matrix.push( [ ] );
    }
    var row = 0;
    for( var i=0; i<this.charList.length; i++ )
    {
        this.matrix[ row++ ].push( this.charList[i] );
        row %= numRows;
    }
    // add "padding" to make the matrix a rectangle
    while( row < numRows )
    {
        // the ~ character won't match any words,
        // so it won't affect the results
        this.matrix[ row++ ].push( "~" );
    }
};

/// @brief print the matrix. useful for debugging.
WordText.prototype.print = function( numRows )
{
    for( var row=0; row<numRows; row++ )
    {
        var line = "";
        for( var col=0; col<this.matrix[row].length; col++ )
            line += this.matrix[row][col];
        print( line );
    }
};

/// @class  Finder
/// @brief  this class implements the search algorithm
function Finder( oWordText )
{
    this.oWordText = oWordText;
};

/// @brief  find a word in the matrix
Finder.prototype.find = function( word )
{
    var NOTFOUND = "NOT FOUND";
    var result = NOTFOUND;
    for( var row=0; row<this.oWordText.getNumRows(); row++ )
    {
        for( var col=0; col<this.oWordText.getNumCols(); col++ )
        {
            if( this.oWordText.matrix[row][col] === word[0] &&
                this.scan( word, row, col ) )
            {
                if( result === NOTFOUND )
                    result = row + " " + col;
                else
                    result += ", " + row + " " + col;
            }
        }
    }
    return result;
};

/// @brief  verify that a row,column pair is a valid location in the matrix
Finder.prototype.rcValid = function( row, col )
{
    return( row >= 0 && row < this.oWordText.getNumRows() &&
            col >= 0 && col < this.oWordText.getNumCols() );
};

/// @brief  scan for a sepeific word from a given location
Finder.prototype.scan = function( word, row, col )
{
    var vectors =
    [
        { dr:  0, dc:  1 },
        { dr:  0, dc: -1 },
        { dr:  1, dc:  0 },
        { dr: -1, dc:  0 },
        { dr:  1, dc:  1 },
        { dr: -1, dc:  1 },
        { dr:  1, dc: -1 },
        { dr: -1, dc: -1 }
    ];
    var found = false;
    for( var v=0; !found && v<vectors.length; v++ )
    {
        var r=row, c=col;
        var matches = 0;
        for( var i=0; this.rcValid(r,c) && i<word.length; i++ )
        {
            if( this.oWordText.matrix[r][c] === word[i] )
            {
                ++matches;
            }
            r += vectors[v].dr;
            c += vectors[v].dc;
        }
        found = ( matches === word.length );
    }
    return found;
};


function main()
{
    var oFinder = new Finder( new WordText() );
    var numWords = parseInt( readLine() );
    for( var i=0; i<numWords; i++ )
    {
        var word = trim( readLine() );
        print( word + " " + oFinder.find( word ) );
    }
};

main();
