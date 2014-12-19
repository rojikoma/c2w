#include <stdlib.h>
#include <stdio.h>
#include "parser.h"

#define MAX_LINE_LEN    1024


int parse_cscope_db(const char *src, const char **tgt)
{
    FILE *fp;
    char    line[MAX_LINE_LEN];

    fp = fopen(src, "r");
    if (fp == NULL)
        return EXIT_FAILURE;

    // TODO: header file information processing
    // trimming header
    fgets(line, MAX_LINE_LEN, fp);
    printf("header removed: \n\"%s\"\n", line);

//   for_each_file {
//
//       read_file_mark();
//
//       while(src_line_is_not_empty) {
//
//           trim_empty_line();
//
//           get_line_number();
//
//           while(symbol_is_not_empty) {
//               get_symbol();
//                   get_symbol_type();
//           }
//       }
//
//   }
    return EXIT_SUCCESS;
}
