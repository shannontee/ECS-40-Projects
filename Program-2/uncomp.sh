#! /bin/bash

if [ $# -ge 1 ] ; then
  for f in $@ ; do
      if [[ $f =~ .*\.(tar\.gz|tgz)$ ]] ; then
        tar -xzf $f
      elif [[ $f =~ .*\.tar$ ]]; then
        tar -xf $f
      elif [[ $f =~ .*\.gz$ ]]; then
        gunzip $f
      elif [[ $f =~ .*\.zip$ ]]; then
        unzip -q $f
      else
        echo uncomp: "$f" has no compression extension.
      fi
  done

else
  echo usage: uncomp {filelist}+

fi
