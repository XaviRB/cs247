/* 
 * CS:APP Data Lab 
 * 
 * Xavier Rodriguez
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  /* brief description of how your implementation works */
  int Funct(arg1, arg2, ...) {
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   *
   * exploit ability of shifts to compute powers of 2
   */
  int pow2plus1(int x) {
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   *
   * exploit ability of shifts to compute powers of 2 
   */
  int pow2plus4(int x) {
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  return ~(~x | ~y);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  int MSB = (n << 3);
  int step2 = (x >> MSB);
  int final = step2 & 0xff;

  return final;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  /*
    int mask = ~2 + 1;
    int shiftAmount = 31 + ((~n) + 1);//this evaluates to 31 - n on two's complement machines
    mask = mask << shiftAmount;
    mask = ~mask;//If n equals 0, it means we have negated all bits and hence have mask = 0
    x = x >> n;
    return x & mask;
    */
  int zero = ~(!n + ~0);
  int step1 = ~zero & ((x >> 1) & ~(1 << 31)) >> (n + ~0);
  int final = (zero & x) | step1;
  return final;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  int mask = (1 << 24) + (1 << 16) + (1 << 8) + 1;
  int result = (mask & (x >> 0)) + (mask & (x >> 1)) + (mask & (x >> 2)) + (mask & (x >> 3)) + (mask & (x >> 4)) +
               (mask & (x >> 5)) +
               (mask & (x >> 6)) +
               (mask & (x >> 7));
  int final = ((result >> 0) & 0xff) + ((result >> 8) & 0xff) + ((result >> 16) & 0xff) + ((result >> 24) & 0xff);            

  return final;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  int MSB = (x >> 31) & 1;
  int part1 = (~x + 1);
  int minus_msb = (part1 >> 31) & 1;   
  int calc = MSB | minus_msb;
  int final =  1 & ~calc; 
  return final;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  int eq_32 = !(n^32);
  int sub_1 = ~0;
  
  x = x >> (n + sub_1);
  int calc = !((x + 1)^(!x));
  int final = eq_32 | calc;
  return final;
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  int neg_check = x >> 31;
  int calc = (neg_check & ((1 << n) + ~0));
  x += calc;
  int final = x >> n;
  return final;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return (~x) + 1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  int not_zero = !!x;
  int neg_check = (x >> 31) & 1;
  int final = (!neg_check) & not_zero;
  return final;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int checkSign = (( (~x + 1) + y) >> 31 & 1);
  int shift_left = 1 << 31; 
  int left_x = x & shift_left;
  int left_y = y & shift_left;  
  
  int xor_operator = left_x ^ left_y;
  xor_operator = (xor_operator >> 31) & 1;
  int final = (!checkSign & !xor_operator) | (xor_operator & (left_x >> 31));
  return final;
}

/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  unsigned NaN = ( ((uf >> 23) & 0xff) == 0xff && (uf & 0x7fffff) != 0); //checks NaN
  if(NaN) {
    return uf;
  }
  else{
    return uf^(1<<31);
  }
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  int bias = 158;
  int mask = 1<<31;
  int sign = x & (1 << 31);
    
  if (sign){
    x = ~x + 1;
  }
  else if (!x){
    return 0;
  }
  else if (mask == x){
    return mask | (158 << 23);
  }
    
  while (!( mask & x)) {
    x = x << 1;
    bias -= 1;
  }
  int frac = ((~mask) & x) >> 8;

  if (x & 0x80 && ((x & 0x7F) > 0 || frac & 1)){
    frac += 1;
  }
  int final = sign + (bias << 23) + frac;

  return final;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  int exp = (uf >> 23) & 0xFF;
  int one = 0xFF;

  if(!exp){
    exp = one;
    uf = (uf << 1) | (uf & 0x80000000) ;
  }
  else if(exp ^ one){
    uf = uf + (1 << 23);
  }
  else if(!(exp ^ 0xFE)){
    exp = one;
    uf = (exp << 23) | (uf & 0x80000000) ;
  }

  return uf;
}
