
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

// don't use readLine and readToken in the same program
function readToken()
{
   var value = 0;
   var token = "";
   // print("call System['in'].read()");
   /* skip whitespace */
   do
   {
      value = System['in'].read();
      // print(value);
   } while( value >=0 && value <= 32 );
   /* get the token */
   while( value > 32 )
   {
      token += String.fromCharCode( value );
      value = System['in'].read();
      // print(value);
   }
   // print( "token='" + token + "'" );
   return token;
};

function main()
{
    var n = parseInt( trim( readLine() ) );
    while( n >= 0 )
    {
        // print( "calculate Tribonacci( " + n + " )" );
        print( tribonacci(n) );
        n = parseInt( trim( readLine() ) );
    }
};

// we can achieve a significant time savings by recording
// previously calculated values of T[n] and then using
// those values instead of making recursive calls.
var T = { };

function tribonacci( n )
{
    // print( "n is " + n );

    if( n === 0 )
        return 0;

    if( n === 1 || n === 2 )
        return 1;

    if( !T[n] )
        T[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);

    return T[n];
};

main();
