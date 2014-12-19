#include <stdlib.h>
#include <stdio.h>
#include "cscope/parser.h"
#include "db/db_generator.h"
#include "web/web_generator.h"

void print_usage()
{
    printf("usage: c2w filename\n");
}

int main(const int argc, const char **argv)
{
    const char *src_fn;
    const char *gen_fn;
    int rv = -1;

    if (argc != 2) {
        print_usage();
        exit(EXIT_FAILURE);
    }

    /* TODO: validate file(name, type?)*/
    src_fn = argv[1];

    rv = parse_cscope_db(src_fn, &gen_fn);
    if (rv != 0) exit(EXIT_FAILURE);

    rv = generate_db(gen_fn);
    if (rv !=0) exit(EXIT_FAILURE);

    rv = generate_web(argv[1]);
    if (rv !=0) exit(EXIT_FAILURE);

    return EXIT_SUCCESS;
}
