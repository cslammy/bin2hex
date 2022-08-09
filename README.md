# bin2hex
C printf %x for hex, %d for decimal, %s for string, methods to convert hex or dec to binary for C

Some techs are good at seeing hex and converting it to binary in their head, but I'm not.  So I wrote or stole a couple of functions to convert hex to binary. bin2hex uses recursion and printf as a side effect. Only 4 lines of code, so, easy. However, I also wanted a function to return the binary as a string. bin2hex4.c and h do that.

Code was written on CodeBlocks using a windows 10 machine, but should be portable to embedded systems by modifying the malloc statement. 
