#!/bin/bash
gcc -c -Wall -Werror -Wextra -pedantic -fpic *.c
gcc -shared *.o -o liball.so
