
"use strict"

importPackage(java.io);
importPackage(java.lang);
var stdin = new BufferedReader( new InputStreamReader(System['in']) )

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

function Counter()
{
    this.counts = { };
    this.firsts = { };
};

Counter.prototype.increment = function( consonant, value )
{
    this.counts[ consonant ] = ( this.counts[ consonant ] || 0 ) + value;
    if( value === 3 )
    {
        this.firsts[ consonant ] = ( this.firsts[ consonant ] || 0 ) + 1;
    }
};

Counter.prototype.getFirst = function( consonant )
{
    return ( this.firsts[ consonant ] || 0 );
};

Counter.prototype.getMax = function()
{
    var key, max=0, firstCount=0;
    for( var keyName in this.counts )
    {
        if( this.counts[keyName] > max ||
                ( this.counts[keyName] === max && this.getFirst(keyName) > firstCount )  )
        {
            key = keyName;
            max = this.counts[keyName];
            firstCount = ( this.firsts[ keyName ] || 0 );
        }
        // if there is a tie then we return all candidates
        else if( this.counts[keyName] === max && this.getFirst(keyName) === firstCount )
        {
           key = key + " " + keyName;
        }
    }
    return key + " " + max;
};

main();

function main()
{
    var line = trim( readLine() ).toUpperCase();
    while( line[0] != "~" )
    {
        var words = line.split(/\s+/);
        var counter = new Counter();
        for( var i=0; i<words.length && words[i][0] !== '~'; i++ )
        {
            var word = words[i];
            var value = 3;
            for( var pos=0; pos<word.length; pos++ )
            {
                var c1 = word.substr( pos, 1 );
                var c2 = word.substr( pos+1, 1 );
                var s2 = word.substr( pos, 2 );
                var s3 = word.substr( pos, 3 );
                if( s3 === "TCH" )
                {
                    counter.increment( s3, value );
                    pos += 2;
                }
                else if( s2 === "CH" || s2 === "SH" || s2 === "TH" )
                {
                    counter.increment( s2, value );
                    ++pos;
                }
                else if( s2 === "CK" )
                {
                    counter.increment( "K", value );
                    ++pos;
                }
                else if( s2 === "GH" )
                {
                    counter.increment( "H", value );
                    ++pos;
                }
                else if( s2 === "WH" )
                {
                    counter.increment( "W", value );
                    ++pos;
                }
                else if( s3.match(/CC[AEIOUY]/) )
                {
                    counter.increment( "K", value );
                    value = 1;
                    if( s3.match(/CC[EIY]/) )
                        counter.increment( "S", value );
                    ++pos;
                }
                else if( s2.match(/C[EIY]/) )
                {
                    counter.increment( "S", value );
                }
                else if( c1 === c2 && c1.match(/[AEIOU]/) === null )
                { 
                    counter.increment( c1, value );
                    ++pos;
                }
                else if( c1 === "C" || c1 === "Q" )
                { 
                    counter.increment( "K", value );
                }
                else if( c1 === "X" )
                {
                    counter.increment( "K", value );
                    counter.increment( "S", value );
                }
                else if( !c1.match(/[AEIOU]/) )
                {
                    counter.increment( c1, value );
                }
                if( !c1.match(/[AEIOU]/) )
                {
                    value = 1;
                }
            }
        }
        print( counter.getMax() );
        line = trim( readLine() ).toUpperCase();
    }

};

