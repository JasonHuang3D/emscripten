/*
 * Copyright 2015 The Emscripten Authors.  All rights reserved.
 * Emscripten is available under two separate licenses, the MIT license and the
 * University of Illinois/NCSA Open Source License.  Both these licenses can be
 * found in the LICENSE file.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#include <emscripten.h>

int main()
{
    const char * file = "/test.txt";
    void* buffer;
    int num, error;

    printf("load %s\n", file);
    emscripten_wget_data(file, &buffer, &num, &error);
    assert(!error);
    assert(strstr(buffer, "emscripten") == buffer); 

    printf("load non-existing\n");
    emscripten_wget_data("doesnotexist", &buffer, &num, &error);
    assert(error);

    printf("ok!\n");
    REPORT_RESULT(1);
    return 0;
}
