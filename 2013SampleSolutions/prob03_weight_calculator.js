
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

function readData( data )
{
    data.name = readToken();
    data.weight = parseFloat( readToken() );
    data.body = readToken();
    data.factor = parseFloat( readToken() );
    return ( data.name !== "END" );
};

function convert( data )
{
    return data.weight * data.factor;
};

function main()
{
    var data = { };
    while( readData( data ) )
    {
        var weight = convert( data );
        print( "On " + data.body + ", " + data.name + " would weigh " + weight + " pounds." );
    }
};


main();
