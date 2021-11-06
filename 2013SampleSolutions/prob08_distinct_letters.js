
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

function trim(s)
{
   return s.replace(/^\s+/g,'').replace(/\s+$/g,'');
};

function main()
{
    var line = readLine();
    while( line !== "." )
    {
        line = trim(line);
        var result = isDistinct( line );
        print( line + " " + result + " DISTINCT LETTERS" );
        line = readLine();
    }
};

function isDistinct( str )
{
    var isUsed = { };
    for( var i=0; i<str.length; i++ )
    {
        if( isUsed[str[i]] )
            return "DOES NOT USE";
        isUsed[str[i]] = true;
    }
    return "USES";
};

main();

