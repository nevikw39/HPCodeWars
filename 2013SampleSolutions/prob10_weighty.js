
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
    while( true )
    {
        var sum = [];
        var total = 0;
        for( var i=0; i<10; i++ )
        {
            sum.push( parseInt( readToken() ) );
            total += sum[i];
        }
        if( total === 0 )
            break;
        sum.sort();
		print(sum[0]);
		print(sum[1]);
		print(sum[2]);
		print(sum[3]);
		print(sum[4]);
		print(sum[5]);
		print(sum[6]);
		print(sum[7]);
		print(sum[8]);
		print(sum[9]);
        var C = ( total ) / 4 - ( sum[0] + sum[9] );
        var A = sum[1] - C;
        var B = sum[0] - A;
        var E = sum[8] - C;
        var D = sum[9] - E;
        print( "" + A + " " + B + " " + C + " " + D + " " + E );
    }
};

main();
