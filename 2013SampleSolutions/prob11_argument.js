
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
    for( var i=0; i<n; i++ )
    {
        var line = readLine();
        line = line.replace( / is(.)(?!not)/g, " is ~NOXXORS~$1");
        line = line.replace( / is not([ .])/g, " is$1");
        line = line.replace( /~NOXXORS~/g, "not");
        print( line );
    }
};

main();

