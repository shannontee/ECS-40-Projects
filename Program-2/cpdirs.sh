#! /bin/bash


if [ -d "$1" ] && [ -d "$2" ] && [ -d "$3" ]; then
  
for f1 in $1/* ; do
  file1="${f1##*/}"
  result=different
  for f2 in $2/*; do
    if [ -e "$2/$file1" ] ; then 
      if [ "$2/$file1" -nt "$1/$file1" ]; then
        cp "$2/$file1" $3
      else
        cp "$1/$file1" $3
      fi
      result=same
      break
    fi
  done
  if [ $result = different ] ; then
    cp "$1/$file1" $3
  fi
done
 
for f2 in $2/*; do
  file2="${f2##*/}"
  result=different
  for f1 in $1/*; do
    if [ -e "$1/$file2" ] ; then
      result=same
      break
    fi
  done
  if [ $result = different ] ; then
    cp "$2/$file2" $3
  fi
done

else
    echo usage: cpdirs.sh source_directory1 source_directory2 dest_directory
fi
