
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
        var code = morseCode( line );
        var result = isPalindrome( code );
        print( trim(line) + " " + result + " a MCP" );
        line = readLine();
    }
};

var encoding =
{
    A : "*-",
    B : "-***",
    C : "-*-*",
    D : "-**",
    E : "*",
    F : "**-*",
    G : "--*",
    H : "****",
    I : "**",
    J : "*---",
    K : "-*-",
    L : "*-**",
    M : "--",
    N : "-*",
    O : "---",
    P : "*--*",
    Q : "--*-",
    R : "*-*",
    S : "***",
    T : "-",
    U : "**-",
    V : "***-",
    W : "*--",
    X : "-**-",
    Y : "-*--",
    Z : "--**"
};


function morseCode( s )
{
    var code = "";
    for( var i=0; i<s.length; i++ )
    {
        var c = s[i];
        if( c >= "A" && c <= "Z" )
            code += encoding[c];
    }    
    return code;
};

function isPalindrome( s )
{
    var L = s.length-1;
    for( var i=0; i<=L; i++ )
        if( s[i] !== s[L-i] )
            return "is *not*";
    return "is";
};

main();

