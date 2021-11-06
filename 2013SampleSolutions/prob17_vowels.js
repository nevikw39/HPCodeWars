
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
   if( value==0x0D )
      postChar += String.fromCharCode(0x0A); // Add linefeed to CR.
   return token;
};

function trim(s)
{
   return s.replace(/^\s+/g,'').replace(/\s+$/g,'');
};

function readDictionary( fileName )
{
   var infile = new BufferedReader( new FileReader( fileName) );
   var words = [ ];
   var line;
   while( (line=infile.readLine()) !== null )
      words.push( trim(String(line)) );
   return words;
};

main();

var postChar = ' ';

/* ********** */
function main()
{
   
   var words = readDictionary( "wordlist.txt" );
   // speed up the process by pre-computing all the word codes
   var wordCodes = { };
   for( var i=0; i<words.length; i++ )
   {
      var word = words[i].toUpperCase();
      var code = codify( word );
      wordCodes[ word ] = code;
   }

   /*needs to be converted*/
   var code = readToken();
   while( code !== ">>>>>>>" )
   {
      var DEBUG = false;
      if(DEBUG) System.out.print( "\n   processing code '" + code + "'\n" );
      var matches = [ ];
      for( var i=0; i<words.length; i++ )
      {
         var word = words[i].toUpperCase();
         if( code === wordCodes[word] || 
             ( isAnagram( code, word ) && codify(code) === wordCodes[word]  ) )
         {
            matches.push( word );
            if(DEBUG) System.out.print( "   MATCH word '" + word + "' with code '" + code + "'\n" );
         }
      }
      if( matches.length === 0 )
         System.out.print( "?" + code + "?" + postChar );
      else if( matches.length === 1 )
         System.out.print( matches[0] + postChar );
      else
      {
         var preChar = '?';
         for( var i=0; i<matches.length; i++ )
         {
            System.out.print( preChar + matches[i] );
            preChar = '/';
         }
         System.out.print( "?" );
         System.out.print( postChar );
      }
      code = readToken();
   }
};

function codify( word )
{
   /*needs to be converted*/
   var code = "";
   for( var i=0; i<word.length; i++ )
   {
      var c = word[i];
      if( !isVowel( c ) )
         code += c;
   }
   return code;
};

function isAnagram( code, word )
{
   return( sortChars(code) === (sortChars(word)) );
};

function sortChars( unsorted )
{
   var charArray = [ ];
   for( var i=0; i<unsorted.length; i++ )
      charArray.push( unsorted.charAt(i) );
   charArray.sort();
   var sorted = "";
   for( var i=0; i<charArray.length; i++ )
      sorted += charArray[i];
   return sorted;        
};

function isVowel( c )
{
   return( c === 'A' || c === 'E' || c === 'I' || c === 'O' || c === 'U'  );
};
