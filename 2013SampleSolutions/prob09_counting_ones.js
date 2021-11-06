
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

// do not try to use both readLine and readToken in the same program!!!!
function readToken()
{
   var value = 0;
   var token = "";
   /* skip whitespace */
   do
   {
      value = System['in'].read();
   } while( value >=0 && value <= 32 );
   /* get the token */
   while( value > 32 )
   {
      token += String.fromCharCode( value );
      value = System['in'].read();
   }
   postChar = String.fromCharCode( value );
   return token;
};

function trim(s)
{
   return s.replace(/^\s+/g,'').replace(/\s+$/g,'');
};

function main()
{
    var n = parseInt( readLine() );
    while( n !== -1 )
    {
        print( countOnes(n) );
        n = parseInt( readLine() );
    }
};

function countOnes( n )
{
    var count = 1;
    for( var m=2; m<=n; m++ )
    {
        var mstr = "" + m;
        for( var i=0; i<mstr.length; i++ )
            count += ( mstr[i] === "1" ) ? 1 : 0;
    }
    return count;
}

main();