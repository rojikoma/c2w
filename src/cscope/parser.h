/*
 * from cscope manpage-
 * SYMBOL DATABASE FORMAT
 *
 *      The symbol database (cscope.out) file format is
 *
 *             <header>
 *             <first file symbol data>
 *                    ...
 *             <last file symbol data>
 *             <trailer>
 *
 *      The header is a single line
 *
 *             cscope <format version> <current dir> [-c] [-q <symbols>] [-T] <trailer offset>
 *
 *      The format version is first number in the  cscope  version
 *      that  wrote the database, e.g. the format version is 9 for
 *      cscope version 9.14.  When the format  version  number  in
 *      the  cscope  program is greater than that in the database,
 *      the entire database will be rebuilt when any part of it is
 *      out  of date.  The current directory is either a full path
 *      or prefixed by $HOME, allowing  the  user's  login  to  be
 *      moved  to  a  different file system without rebuilding the
 *      database.  The trailer offset is the  fseek(3)  offset  of
 *      the trailer.
 *
 *      The header is followed by the symbol data for each file in
 *      alphabetical order.  This  allows  fast  updating  of  the
 *      database  when  only a few files have changed, because the
 *      old database is copied to the new database up to the point
 *      of  the changed file.  Then the changed file's symbol data
 *      is added to the new database, the old database  is  copied
 *      up to the next changed file, and so on.
 *
 *      Two  data  compression  techniques  are used on the symbol
 *      data: (1) keywords and trailing syntax  are  converted  to
 *      control  characters,  and  (2)  common digraphs (character
 *      pairs) are compressed to meta-characters (characters  with
 *      the  eight  bit set).  Since this makes it hard to read or
 *      postprocess the database, you  may  want  to  use  the  -c
 *      option  to  turn off data compression when the database is
 *      built.
 *
 *      The symbol data for each file starts with
 *
 *             <file mark><file path>
 *             <empty line>
 *
 *      and for each source line containing a symbol
 *
 *             <line number><blank><non-symbol text>
 *             <optional mark><symbol>
 *             <non-symbol text>
 *             repeat above 2 lines as necessary
 *             <empty line>
 *
 *      Leading and trailing white space in  the  source  line  is
 *      removed.   Tabs are changed to blanks, and multiple blanks
 *      are squeezed to a single  blank,  even  in  character  and
 *      string  constants.  The symbol data for the last file ends
 *      with
 *
 *             <file mark>
 *
 *      A mark is a tab followed by one of these characters:
 *
 *             Char   Meaning
 *
 *             @      file
 *             $      function definition
 *             `      function call
 *             }      function end
 *             #      #define
 *             )      #define end
 *             ~      #include
 *             =      direct assignment, increment, or decrement
 *             ;      enum/struct/union definition end
 *             c      class definition
 *             e      enum definition
 *             g      other global definition
 *             l      function/block local definition
 *             m      global enum/struct/union member definition
 *             p      function parameter definition
 *             s      struct definition
 *             t      typedef definition
 *             u      union definition
 *
 *      A #include mark is followed by '<' or '"' to determine  if
 *      the  current  directory  should  be searched.  An untagged
 *      enum/struct/union definition has a mark without  a  symbol
 *      name so its beginning can be found.
 *
 *      Historical note: The first three mark characters were cho-
 *      sen because they are not used by the C language, but since
 *      they  can  appear in a string constant, the tab prefix was
 *      added.  They were never changed to more meaningful charac-
 *      ters  because  other programs had been written to read the
 *      database file.
 *
 *      The trailer contains lists of source directories,  include
 *      directories, and source files; its format is
 *
 *             <number of viewpath nodes>
 *             <first directory in viewpath, if any>
 *                    ...
 *             <last directory in viewpath>
 *             <number of source directories>
 *             <first source directory path (always .)>
 *                    ...
 *             <last source directory path>
 *             <number of include directories>
 *             <first include directory path>
 *                    ...
 *
 *             <last include directory path (normally /usr/include)>
 *             <number of source and included files>
 *             <length of string space needed>
 *             <first file path>
 *                    ...
 *             <last file path>
 *
 *      Low  level access to the symbol database was traditionally
 *      provided by ccalls.  Cscope now emulates this  functional-
 *      ity  with the -x option so that everyone can get access to
 *      the extra information stored in the database.  One of  the
 *      main  differences  in  the  output is that a new column is
 *      added, entitled "Ccalls", which contains the  symbol  name
 *      from  the  database.  This information was previously only
 *      extracted as part of the  code  fragment  associated  with
 *      each  set of results.  As such, the new output format when
 *      using the -x option consists of the  file  name,  function
 *      name, line number, ccalls information and line text, sepa-
 *      rated by spaces.
 */

int parse_cscope_db(const char *src, const char **tgt);
