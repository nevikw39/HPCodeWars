
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
    var x0, y0, x1, y1, x2, y2;
    var a, b, c, cosw, sinw, area;
    while( true )
    {
        x0 = parseFloat( readToken() );
        y0 = parseFloat( readToken() );
        x1 = parseFloat( readToken() );
        y1 = parseFloat( readToken() );
        x2 = parseFloat( readToken() );
        y2 = parseFloat( readToken() );
        if( x0 === 0 && y0 === 0 &&
            x1 === 0 && y1 === 0 &&
            x2 === 0 && y2 === 0 )
        {
            return;
        }
        a = distance( x0, y0, x1, y1 );
        b = distance( x2, y2, x1, y1 );
        c = distance( x0, y0, x2, y2 );
        cosw = ( a*a + b*b - c*c ) / ( 2 * a * b );
        sinw = Math.sqrt( 1 - cosw * cosw );
        area = ( a * b * sinw ) / 2;
        print( area );
    }
        
};

function distance( x0, y0, x1, y1 )
{
    var dx = x0 - x1;
    var dy = y0 - y1;
    return Math.sqrt( dx*dx + dy*dy ); 
};


main();