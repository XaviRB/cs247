/*
Course: CSCI 247  - Winter 2022
File Name: Lab1.c
Name: Xavier Rodriguez
*/

/*
1. What are preprocessor directives? – explain what is happening behind the scenes.
    To my understanding preprocessor directives are used to do specific actions within the scource file. I belive that it is the first thing that is being refercenced before the macro.
2. What are forward declarations - Explain why it is required.
      Forward declarations is you telling the compiler that you will define it later in the program. It is required so you can carry along a block of code somewhere else.
3. What is a macro – Explain some of the advantages of using Macros.
      macros are kinda like functions but are used in preprocceser and it helps define things when using macros and the main advatages is that macros can help define things further down the code. 
4. Functions – Explain why a function call is more advantageous than adding code to the main routine.
      functions are very useful so you dont have to run a chunck of code again and will be correct so you dont run the risk of something going wrong with the function.
5. Escape character(\) – Explain why an escape character is needed in a string for some characters
       this is too reduce ambiguity in quotes (and other characters) used in that string so it can be read correctly.
6. Operators – What are they in the printf function? When is the value evaluated for this operator? How is an operator different from a Macro or Function?
      operators are a symbol which operates on a variable or value and when used in a printf function it reads the main value or varible in the operator. A value is only evaluted in a operator when the operator is called after the value is stored. As for how a operator is differnent from a macro or a function is that it can be set to whatever you want and it isnt done in the preprocessor.
7. Keywords - What is a keyword? What are the keywords in this code?
      predefined, reserved words used in programming that have special meanings to the compiler. some keywords would be dataypes, function words like if , else, ect.
8. What does the printf function do? What is the significance of the display in the context of your program?
      what printf does is it prints whatever is contaited in it for example string, float, integer ect. The importance of seeing what is printing is so you can see whats going on in your program. very useful to see what is actully happaning.
*/

#include <stdio.h>
#include <string.h>
//task 4
#define DATA_TYPE_NAME  "char" // "int" "float" "double" "unsigned char" "signed char" "short" "unsigned short" "long"
#define DATA_TYPE char // int float double unsigned char signed char short unsigned short long

//Declerations
void DataTypeSizes(void);
char* GetStringFromStdin(char* str); 
void DisplayString(const char* str);

//my main
 int main(int argc, char* argv[]) {

      //task 6
      //gives values of argv
      printf("argc value = %i\n", argc);
      int i;
      for(i = 1; i < argc; i++){
         printf("argv value = %s\n",argv[i]);
      }
      
      //task6(int argc,char* argv[]);
      DataTypeSizes();
      char str[100];
      GetStringFromStdin(str);
      DisplayString(str);

      //task6
      //gives last two parameters of three string inputs
      int i2;
      for(i2 = 2; i2 < argc; i2++){
         DisplayString(argv[i2]);
      }

      return(0);
}

//task 4
void DataTypeSizes(void) {
   printf("\"%s\" is a standard C datatype. Size of a \"%s\" data type is = %ld\r\n", DATA_TYPE_NAME, DATA_TYPE_NAME, sizeof(DATA_TYPE));
}

//task 5
//uses fgets 
char* GetStringFromStdin(char* str){
      printf("Input a String: ");
      fgets (str, 100, stdin);
      return str;

} 
//prints string
void DisplayString(const char* str){
      printf("String = %s\n", str);
}

