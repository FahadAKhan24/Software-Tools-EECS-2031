
#FAHAD AHMED KHAN
#214468888


#!/bin/bash
rm -f output.log
rm -f /usr/tmp/temp$$
if test -e hello.c ; then
  gcc -ansi -pedantic hello.c -o hello 2>/usr/tmp/temp$$ 

     if test -s /usr/tmp/temp$$ ; then
       echo "hello.c compilation errors" > output.log
       exit
     else 
         # append to output.log file "hello.c compiles successfully"
         echo "hello.c compiles successfully" > output.log
     fi     
          
 
else 
    echo "hello.c does not exist" > output.log 
    exit
fi
    
./hello > helloout.txt
echo "Hello World" > hellotest.txt

if cmp -s helloout.txt hellotest.txt ; then
   echo "output correct" > hello.log
else 
    echo "output mismatch " > hello.log
fi
exit




