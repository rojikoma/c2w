#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <linux/limits.h>
#include <string.h>
#include "list.h"
#include "debug.h"
// include assert.h instead of using #define ASSERT_TRUE(x)
// ASSERT_FUNC(function call, expected value)
// it might be better if I add handler separately...
#define ASSERT_FUNC(x, y)   if (x != y) {                               \
                                printf("error occurred in %s\n", #x);   \
                                return EXIT_FAILURE;                    \
                            }
#define CSCOPE_FILES        "cscope.files"

typedef struct fileList_t {
    char                fileName[PATH_MAX];
    struct list_head    list;
} fileList;




int get_file_lists(struct list_head *listHead, const char *filePath)
{
    return EXIT_SUCCESS;
}

int generate_html(void)
{
    // read file
    // attach html tag
    // write src_file_name.html
    return EXIT_SUCCESS;
}

// 1.   get file lists
// 2.   for each file list
// 2.1      read file
// 2.2      attach html tags
// 2.3      generate src_file_name.html
// 3.   end?
int generate_web(const char *cscopeOutFilePath)
{
    char        *cscopeFilePath;

    cscopeFilePath = getcwd((char*)cscopeOutFilePath, PATH_MAX);

    LIST_HEAD(srcFiles); //head created

    C2W_PRINT("list head initialized\n");

#if 1 //TODO: use function call
    char fileListFile[PATH_MAX] = {'\0', };;
    FILE *pfFileList;
    char listEntry[PATH_MAX] = {'\0',};

    sprintf(fileListFile, "%s/%s", cscopeFilePath, CSCOPE_FILES);
    printf("Getting file list from \"%s\"\n", fileListFile);

    pfFileList = fopen(fileListFile, "r");

    fileList *flist;

    while(fgets(listEntry, PATH_MAX, pfFileList)) {
        flist = malloc(sizeof(fileList));
        strcpy(flist->fileName, listEntry);
        list_add(&flist->list, &srcFiles);
        C2W_PRINT("%s", listEntry);
    }

    fileList *pos = NULL;
    int      i = 0;

    list_for_each_entry_reverse(pos, &srcFiles, list)
    {
        C2W_PRINT("fileList[%d] = %s", i++, pos->fileName);
    }
    fclose(pfFileList);
#else
    ASSERT_FUNC(get_file_lists(&srcFiles, cscopeFilePath), 0);
#endif
    //list_for_each(pos, &src_files)
        ASSERT_FUNC(generate_html(), 0);

    return EXIT_SUCCESS;
}
