/*
 * Copyright (c) 2013 Texas Instruments Incorporated - http://www.ti.com
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the
 *   distribution.
 *
 *   Neither the name of Texas Instruments Incorporated nor the names of
 *   its contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== main_host.c ========
 *
 */
#include <stdio.h>
#include <stdlib.h>

#include "App.h"

#define Main_USAGE "\
Usage:\n\
    app_host [options]\n\
\n\
Options:\n\
    h   : print this help message\n\
    l   : list the available remote names\n\
\n\
Examples:\n\
    app_host\n\
    app_host -l\n\
    app_host -h\n\
\n"

/* private functions */
static int parse_args(int argc, char *argv[]);

/* private data */

/*
 *  ======== main ========
 */
int main(int argc, char* argv[])
{
    int status;

    printf("--> main:\n");

    /* parse command line */
    status = parse_args(argc, argv);

    if (status < 0) {
        printf("main: Error: parse_args() failed, status=%d", status);
        goto leave;
    }

    /* bootstrap the application */
    status = App_main();

    if (status < 0) {
        printf("main: Error: App_main() failed, status=%d\n", status);
        status = -1;
        goto leave;
    }

leave:
    printf("<-- main: status=%d\n", status);

    return (status);
}

/*
 *  ======== parse_args ========
 */
static int parse_args(int argc, char *argv[])
{
    int     x, cp, opt, argNum;
    int     status = 0;

    /* parse the command line options */
    for (opt = 1; (opt < argc) && (argv[opt][0] == '-'); opt++) {
        for (x = 0, cp = 1; argv[opt][cp] != '\0'; cp++) {
            x = (x << 8) | (int)argv[opt][cp];
        }

        switch (x) {
            case 'h': /* -h */
                printf("%s", Main_USAGE);
                exit(0);
                break;

            case 'l': /* -l */
                printf("Available remote processors: DSP, IPU");
                exit(0);
                break;

            default:
                printf(
                    "Error: %s, line %d: invalid option, %c\n",
                    __FILE__, __LINE__, (char)x);
                printf("%s", Main_USAGE);
                status = -1;
                goto leave;
        }
    }

    /* parse the command line arguments */
    for (argNum = 1; opt < argc; argNum++, opt++) {

        switch (argNum) {
#if 0
            case 1:
                break;
#endif

            default:
                printf(
                    "Error: %s, line %d: too many arguments\n",
                    __FILE__, __LINE__);
                printf("%s", Main_USAGE);
                status = -1;
                goto leave;
        }
    }

leave:
    return(status);
}
