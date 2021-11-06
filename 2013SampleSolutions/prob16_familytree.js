
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

function App()
{
    var nodeGraph;
    this.main = function()
    {
        nodeGraph = new NodeGraph();
        ReadData();
        ProcessQueries();
    };
    function ReadData()
    {
        var n = parseInt( readToken() );
        if(DEBUG) print( n + " expressions" );
        for( var i=0; i<n; i++ )
        {
            var p1 = readToken();
            readToken();
            var p2 = readToken();
            readToken();
            nodeGraph.initialize( p1 );
            nodeGraph.initialize( p2 );
            var div = "";
            while( div !== "." )
            {
                var child = readToken();
                nodeGraph.addChild( p1, child );
                nodeGraph.addChild( p2, child );
                div = readToken();
            }
        }
        nodeGraph.linkParents();
    };
    function ProcessQueries()
    {
        var n = parseInt( readToken() );
        if(DEBUG) print( n + " queries" );
        for( var i=0; i<n; i++ )
        {
            var tag1 = readToken();
            var symbol = readToken();
            var tag2 = readToken();
            readToken();
            var result = "UNKNOWN";
            if( symbol === ">" )
                result = nodeGraph.isAncestor( tag1, tag2 );
            else
                result = nodeGraph.isSibling( tag1, tag2 );
            print( tag1 + " " + symbol + " " + tag2 + " ? " + result );
        }
    };
};

function NodeGraph()
{
    var nodes = { };

    this.isAncestor = function( tag1, tag2 )
    {
        if(DEBUG) print( "is " + tag1 + " an ancestor of " + tag2 + "?" );

        if( nodes[tag2].parents.length === 0 )
            return false;

        var p0 = nodes[tag2].parents[0];
        var p1 = nodes[tag2].parents[1];

        if( p0 === tag1 || p1 === tag1 )
            return true;
        
        return this.isAncestor( tag1, p0 ) || this.isAncestor( tag1, p1 );
    };

    this.isSibling = function( tag1, tag2 )
    {
        if(DEBUG) print( "is " + tag1 + " a sibling of " + tag2 + "?" );

        var list1 = this.getAncestorStringList( tag1 );
        var list2 = this.getAncestorStringList( tag2 );

        for( var i=0; i<list1.length; i++ )
            for( var j=0; j<list2.length; j++ )
                if( list1[i] === list2[j] )
                    return true;
            
        return false;
    };

    this.getAncestorStringList = function( tag )
    {
        var list = "";

        if( nodes[tag].parents.length === 0 )
            return list;

        for( var i=0; i<2; i++ )
           list += nodes[tag].parents[i] + this.getAncestorStringList( nodes[tag].parents[i] );

        return list;
    };

    this.initialize = function( p1 )
    {
        if(DEBUG) print( "initialize " + p1 );
        if( ! nodes[p1] )
            nodes[p1] = { tag: p1, parents : [ ], children : [ ] };
    };

    this.linkParents = function()
    {
        for( var tag in nodes )
        {
            var parent = nodes[tag];
            for( var i=0; i<parent.children.length; i++ )
            {
                var child = parent.children[i];
                this.addParent( parent.tag, child );
            }
        }
    };

    this.addParent = function( parent, child )
    {
        if(DEBUG) print( "attempting to add parent " + parent + " to child " + child + "." );
        if( ! nodes[child] )
            this.initialize( child );
        nodes[child].parents.push( parent );
    };

    this.addChild = function( parent, child )
    {
        if(DEBUG) print( "attempting to add child " + child + " to parent " + parent + "." );
        nodes[parent].children.push( child );
        // add parent links later, separately, because child nodes do not yet exist
    };

};

(function()
{
    var app = new App();
    app.main();
})();
