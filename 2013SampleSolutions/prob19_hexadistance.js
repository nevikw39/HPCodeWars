
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

// model the hexagonal grid using a 2D array. we'll offset the y-value of the
// odd-indexed rows by 1/2 to approximate the hexagons. it won't be perfect,
// but for the purpose of this program it will suffice.
var grid =
    [
        [ 'T', 'L', 'U', 'E', 'W', '2' ],
        [ 'A', 'H', 'R', 'X', 'K', '6' ],
        [ '3', 'V', '5', 'B', 'Z', 'N' ],
        [ 'F', 'C', 'J', '8', 'P', 'D' ],
        [ 'Q', 'Y', 'M', 'G', '4', 'S' ],
    ];

var GRID_ROW_COUNT = grid.length;
var GRID_COL_COUNT = grid[0].length;

// locate() returns the array coordinates of a letter
function locate( letter )
{
    for( var y=0; y<GRID_ROW_COUNT; y++ )
        for( var x=0; x<GRID_COL_COUNT; x++ )
            if( grid[y][x] === letter )
                return { 'x':x, 'y':y };
};

// getY() returns the y-center value of a hexagon
function getY( hex )
{
	var y = hex.y;
	if( hex.x % 2 )
		y += 0.5;
    return y;
};

// distance() returns the distance between the centers of two hexagons
function distance( h0, h1 )
{
	var dx = h0.x - h1.x;
	var dy = getY(h0) - getY(h1);
    return Math.sqrt( dx*dx + dy*dy );
};

// getNeighbor() returns a neighbor of a hexagon. a hexagon has at most six
// neighbors, so the index selects which neighbor is returned. if the array
// indices are out-of-bounds, getNeighbor returns hex h0.
function getNeighbor( h0, index )
{
    var offsetByCol =
    [
        [
            { dx:  0, dy: -1 },
            { dx:  1, dy: -1 },
            { dx:  1, dy: 0 },
            { dx:  0, dy: 1 },
            { dx: -1, dy: 0 },
            { dx: -1, dy: -1 }
        ],
        [
            { dx:  0, dy: -1 },
            { dx:  1, dy: 0 },
            { dx:  1, dy: 1 },
            { dx:  0, dy: 1 },
            { dx: -1, dy: 1 },
            { dx: -1, dy: 0 }
        ]
    ];
    var hex = { x:h0.x, y:h0.y };
    var offset = offsetByCol[ h0.x % 2 ][ index ];
    hex.x = h0.x + offset.dx;
    hex.y = h0.y + offset.dy;
    if( hex.x >= 0 && hex.x <= GRID_COL_COUNT &&
        hex.y >= 0 && hex.y <= GRID_ROW_COUNT )
        return hex;
    else
        return h0; // return "self"
};

function main()
{
	// read the number of pairs
    var n = parseInt( readLine() );
    for( var i=0; i<n; i++ )
    {
    	// read the next pair
        var line = trim( readLine() );
        var pair = line.split( " " );
        // convert the letters into array coordinates
        var h0 = locate( pair[0] );
        var h1 = locate( pair[1] );
        // "walk" from h0 to h1. each time through the loop, h0 is
        // changed to the next hexagon and hops is incremented.
        for( var hops=0; distance(h0,h1)>0.1; hops++ )
        {
            var hMin = { x:h0.x, y:h0.y };
            var dMin = distance( h0, h1 );
            // examine each of h0's six neighbors
            for( var j=0; j<6; j++ )
            {
                var hex = getNeighbor( h0, j );
                var d = distance( hex, h1 );
                // if the distance from hex to h1 less than dMin, then
                // save its position and keep examining other neighbors.
                if( d < dMin )
                {
                    dMin = d;
                    hMin = { x:hex.x, y:hex.y };
                }
            }
            h0 = { x:hMin.x, y:hMin.y };
        }
        print( line + " " + hops );
    }
};

main();
