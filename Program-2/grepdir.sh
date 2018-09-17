#! /bin/bash

if [ -d $1 ] && [ -n "$2" ] && [ $# -ge 2 ]; then
  find $1 -type f -exec grep -s $4 $3 $2 {} \;

else
  echo usage: grepdir.sh directory pattern [-grep option]*
  exit

fi
