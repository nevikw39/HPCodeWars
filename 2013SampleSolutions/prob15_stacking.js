
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

var DEBUG = false;

function main()
{
    var stacks = [ [], [] ];
    var n = parseInt( readToken() );
    for( var i=0; i<n; i++ )
    {
        var package = readPackage();
        var fit0 = willFit( stacks[0], package );
        var fit1 = willFit( stacks[1], package );

        if(DEBUG) print( "package " + package.tag + (fit0?" fits":" doesn't fit") + " on stack 0" ); 
        if(DEBUG) print( "package " + package.tag + (fit1?" fits":" doesn't fit") + " on stack 1" ); 
        
        var dA0 = areaDiff( stacks[0], package );
        var dA1 = areaDiff( stacks[1], package );

        var stackIndex = 0;
        if( !fit0 && !fit1 )
        {
            if( stackHeight( stacks[1] ) > stackHeight( stacks[0] ) )
                stackIndex = 1;
            if(DEBUG) print( "load stack " + stackIndex + " NO FIT" );
            loadStack( stacks[ stackIndex ] );
            stacks[ stackIndex ] = [ ];
            if(DEBUG) printTruck();
        }

        else if( fit0 && !fit1 )
            stackIndex = 0;

        else if( !fit0 && fit1 )
            stackIndex = 1;

        else if( dA1 < dA0 )
            stackIndex = 1;

        stacks[ stackIndex ].push( package );

        if(DEBUG) for( var j=0; j<2; j++ )
        {
            var s = "stack " + j + ": ";
            for( var k=0; k<stacks[j].length; k++ )
                s += stacks[j][k].tag + " ";
            print( s );
        }
    }
    var lastStack = 1;
    if( stackHeight( stacks[1] ) > stackHeight( stacks[0] ) )
        lastStack = 0;
    loadStack( stacks[ 1-lastStack ] );
    loadStack( stacks[ lastStack ] );
    printTruck();
};

var truck = [ ];

function printTruck()
{
    if(DEBUG) print( "TRUCK" );
    for( var i=0; i<truck.length; i++ )
    {
        var s = "   ";
        var stack = truck[i];
        for( var j=0; j<stack.length; j++ )
            s += stack[j].tag + " ";
        print( s );
    }
};

function loadStack( stack )
{
    if( stack.length > 0 )
        truck.push( stack );
}

function stackHeight( stack )
{
    var height = 0;
    for( var i=0; i<stack.length; i++ )
        height  += stack[i].height;
    return height;
}

function willFit( stack, package )
{
    if( stack.length === 0 )
        return true;

    if( stackHeight( stack ) + package.height > 200 )
        return false;

    var top = stack[ stack.length - 1 ];

    if( package.length <= top.length &&
        package.width <= top.width )
        return true;

    // rotate the package
    var temp = package.length;
    package.length = package.width;
    package.width  = temp;
    
    if( package.length <= top.length &&
        package.width <= top.width )
        return true;

    return false;
};

function areaDiff( stack, package )
{
    var stackArea = 120 * 120;
    var packageArea = package.length * package.width;
    if( stack.length > 0 )
    {
        var top = stack[ stack.length-1 ];
        stackArea = top.length * top.width;
    }
    return stackArea - packageArea;
};

function readPackage()
{
    var package = { };
    package.tag = readToken();
    package.length = parseInt( readToken() );
    package.width  = parseInt( readToken() );
    package.height = parseInt( readToken() );
    return package;
};

main();
