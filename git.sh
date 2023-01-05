#!/bin/bash

COMMIT=$(echo "----commit at date : $(date)-----")
#echo $COMMIT
git add .
git commit -m "$COMMIT"

#bash ~ / nor.sh./**/ *.c./**/ *.h> / dev / null
