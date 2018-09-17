#! /bin/bash
 
if [ $# -eq 0 ] ; then 
  echo Executable name required.
  echo usage: makemake.sh executable_name
fi

echo -n $1 :" " > Makefile

for out in `grep -l "#include*" *.cpp | sed s/.cpp/.o/g`; do
    ofiles="$ofiles $out"
done

echo -n $ofiles >> Makefile
echo "  " >> Makefile 

if [  $# -le 1 ]; then
  echo -e -n "\tg++ -ansi -Wall -g -o $1$ofiles" >> Makefile
else
  echo -e -n "\tg++ -ansi -Wall -g -o $1 $2 $3$ofiles" >> Makefile
fi

echo "  " >> Makefile
echo "" >> Makefile 
     
for cppfiles in `grep -l "#include*" *.cpp`; do
  all_files="$all_files $cppfiles"   
        
  echo -n ${cppfiles%\.cpp}\.o" ": >> Makefile
  echo -n "" $cppfiles >> Makefile
  for h in `awk -F\" '/#include *\"/ {print $2} ' $cppfiles`; do
    echo -n "" $h >> Makefile
  done
  echo " " >> Makefile
       
  if [ $# -le 1 ]; then
    echo -e "\tg++ -ansi -Wall -g -c $cppfiles" >> Makefile  
  else
    echo -e "\tg++ -ansi -Wall -g -c $2 $3 $cppfiles" >> Makefile
  fi
  echo "" >> Makefile
done
   
echo "clean : " >> Makefile
echo -e -n "\trm -f $1" >> Makefile
for o in $ofiles; do
  echo -n " "$o" " >> Makefile
done

echo "  " >> Makefile 
 

