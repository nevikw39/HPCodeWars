
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

main();

/* ********** */
function main()
{
    var keyTemp = [ ];

    for( var n=0; n<12; n++ )
        keyTemp[n] = parseFloat( readToken() );

    var iref = [ 10, 0, 1, 2, 3, 4, 5, 6, 7, 8 ];
    var ihash = 11;
    var istar = 9;
    
    var ambient = keyTemp[ istar ];
    var press1  = keyTemp[ ihash ];
    var dtemp   = press1 - ambient;
    // print( "ambient is " + ambient + ", dtemp is " + dtemp );
    var pressList = [ ];
    for( var i=0; i<10; i++ )
    {
        // print( "keytemp for number " + i + " is " + keyTemp[ iref[i] ] );
        var dkt = keyTemp[ iref[i] ] - ambient;
        // print( "keytemp - ambient is " + dkt );
        // print( "dkt / dtemp is " + dkt / dtemp );
        var count = Math.round( ( keyTemp[ iref[i] ] - ambient ) / dtemp );
        for( var j=0; j<count; j++ )
        pressList.push( i );
    }
    if( pressList.length !== 4 )
    {
        print( "ERROR: number of presses is " + pressList.length );
        return;
    }

    var combos = makeCombos( pressList, "" );
    combos.sort();
    var unique = [ combos[0] ];

    for( var i=1; i<combos.length; i++ )
        if( combos[i] !== combos[i-1] )
            unique.push( combos[i] );

    for( var i=0; i<unique.length; i++ )
        print( unique[i] );

};

function makeCombos( pressList, prefix )
{
    if( pressList.length === 1 )
        return [ prefix + pressList[0] ];
    else
    {
        var combos = [];
        for( var i=0; i<pressList.length; i++ )
        {
            var subPrefix = prefix + pressList[i]; 
            var subList = [];
            for( var j=0; j<pressList.length; j++ )
                if( i !== j )
                    subList.push( pressList[j] );
            combos = combos.concat( makeCombos( subList, subPrefix ) );
        }
        return combos;
    }
};


