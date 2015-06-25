# socket-sample
a simplest c socket example with dns query

please use `make -f Makefile_socket` to generate 'client' and 'server' binary code.
default port listen on 1234, and the menu like this

~~~
./client
What's your requirement? 1.DNS 2. QUERY 3. QUIT: 1
Input URL address: www.google.com
receive from server: 210.242.127.29
What's your requirement? 1.DNS 2. QUERY 3. QUIT: 2
Input student ID: 343423
receive from server: No such student ID
What's your requirement? 1.DNS 2. QUERY 3. QUIT: 5566
Invalid choice!
What's your requirement? 1.DNS 2. QUERY 3. QUIT: 2
Input student ID: 5566
receive from server: Alice@network.xxx.com
~~~

we support two option
1. query dns
2. search email by id in file


 
we refer [http://www.thegeekstuff.com/2011/12/c-socket-programming/](http://www.thegeekstuff.com/2011/12/c-socket-programming/) to implment basic socket client/server
in query dns, we use [http://www.binarytides.com/dns-query-code-in-c-with-linux-sockets/](http://www.binarytides.com/dns-query-code-in-c-with-linux-sockets/),
the menu refer to [http://cboard.cprogramming.com/c-programming/64154-how-make-menu-c-dos.html](http://cboard.cprogramming.com/c-programming/64154-how-make-menu-c-dos.html)
