#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//this guy is the bomb--recurse me up Scotty!
//https://www.quora.com/How-can-you-convert-hexadecimal-to-binary-without-using-arrays-in-C-program
//check yer work
//https://www.rapidtables.com/convert/number/hex-to-binary.html


void hex2bin(int16_t h)

{
if (!h) return; //countdown if not zero run function again put h values on stack
hex2bin(h>>1);
printf("%d",h&1); //pop most recent value off stack and print it, so, low to high
return;

}


uint8_t * hex2bin4(uint32_t h)
{

 /*
 embedded should manage memory allocation for you

 Windows doesnt but here is ptr statements

 that should work if you are using embedded
 const uint8_t memree;
 uint8_t *memreeptr;
 memreeptr = &memree;
 */

//allocate memory.
uint8_t *memreeptr = malloc(128*sizeof(uint8_t));

uint8_t x = 0;
uint16_t count, first, fin = 0;

//ascii ONE is 49
//ascii ZERO is 48

//get 1 if it exists for initial &1 pass
first = h;
first = first&1;

if (first)
    {
    *memreeptr = 49;
    }

//trap h = 0 (ha! thought you could fool me?)
if (!first)
    {
    *memreeptr = 48;
    }
  count = 1;

//next, turn the rest of it into 1 and 0's
  while (h > 0)
    {
      h = h >> 1;
      x = h&1;
      if (h > 0)
      {

      if (x)

            {
            *(memreeptr + count) = 49;
            }

      if (!x)
            {
            *(memreeptr + count) = 48;
            }
     count++;

      } //end if
    } //end while

    //reversal of fortune
    uint8_t temp[count];

    for (uint16_t i = 0; i < count ; i++)
    {
      temp[count - 1 - i] = *(memreeptr + i);
    }

    for (uint16_t i = 0; i < count ; i++)
    {
       *(memreeptr + i) = temp[i];
       fin = i;
    }
// add back null
*(memreeptr + fin + 1) = 0;

return memreeptr;

free(memreeptr);
}

//example use



int main(void)
{
uint8_t * bn;
uint8_t * qn;
uint8_t * xn;

uint16_t y = 0;
uint16_t x = 0;
uint16_t z = 0;

x = 0b0000000000001111;
y = 0b1110000000000000;

//use to print single value
bn = hex2bin4(y);
printf("y hex value is: 0x%x \n",y);
printf("y binary value is: 0b%s \n",bn);

//use to print added values.
qn = hex2bin4(x + y);
printf("after adding x and y, hex value is: 0x%x \n",x + y);
printf("after adding x and y, binary value is: 0b%s \n",qn);


z = 0b0000000000000001;
xn = hex2bin4(z);
printf("z initial binary value initial is: 0b%s \n",xn);
xn = hex2bin4(z*3);
printf("z second binary value initial is: 0b%s \n",xn);



return 0;
}
