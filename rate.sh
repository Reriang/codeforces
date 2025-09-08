#!/bin/bash

RED="$(printf '\033[31m')"  GREEN="$(printf '\033[32m')"  ORANGE="$(printf '\033[33m')"  BLUE="$(printf '\033[34m')"
MAGENTA="$(printf '\033[35m')"  CYAN="$(printf '\033[36m')"  WHITE="$(printf '\033[37m')" BLACK="$(printf '\033[30m')"
REDBG="$(printf '\033[41m')"  GREENBG="$(printf '\033[42m')"  ORANGEBG="$(printf '\033[43m')"  BLUEBG="$(printf '\033[44m')"
MAGENTABG="$(printf '\033[45m')"  CYANBG="$(printf '\033[46m')"  WHITEBG="$(printf '\033[47m')" BLACKBG="$(printf '\033[40m')"


file1="$1"
file2="$2"

if [ -z "$file1" ] || [ -z "$file2" ]; then
    echo "Usage: $0 file1 file2"
    exit 1
fi

cmp "$file1" "$file2" > /dev/null 2>&1

if [ $? -ne 0 ]; then
    echo -e ${RED}"False"
    exit 1
else
    echo -e ${GREEN}"Accepted"
    exit 0
fi
