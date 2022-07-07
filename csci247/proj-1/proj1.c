/*
Course: CSCI 247  - Winter 2022
File Name: proj1.c
Name: Xavier Rodriguez

What this program does is it takes in args either -x or -x 
Then it takes in the user inputs and convertes the decimial input
To a binary conversion or hexadecimal conversion. side note to end the program it is ^D
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

// decimal to hexadecimal function that takes in the users int
void decToHex(int num){
    int index = 0;
    //hex
    char hex [32] ;
    //had a nested while loop and a switch case
    //checks if num is
    while( num > 0 ){
        switch( num % 16 ){
            case 10 :
                hex [ index] = 'A' ; 
                break ;
            case 11 :
                hex [index] = 'B'; 
                break ;
            case 12 :
                hex [index] = 'C' ; 
                break ;
            case 13 :
                hex [index] = 'D'; 
                break ;
            case 14 :
                hex [index] = 'E' ; 
                break ;
            case 15 :
                hex [index] = 'F'; 
                break ;
            default :
                hex [index] = (num%16) + 0x30 ;
        }
        //within the while loop
        num = num / 16 ;
        index ++ ;
    }

    //printing out the hexadecimal
    printf("0x");
    int a = ( index-1 );
    //prints the string in reverse
    for( ; a >= 0 ; a--){
        printf( "%c" , hex[a] ) ;
    }
    printf("\n");
}

//Decmial to binary 
void decToBinary(int num){
    long tempDecimal;
    //binary
    char binary[32];
    int index = 0;
    
    // Copy decimal value to temp variable //
    tempDecimal = num;
    //converts the decmial to binary 
    while(tempDecimal > 0){
        binary[index] = (tempDecimal % 2) + '0';
        tempDecimal /= 2;
        index++;
    }
    //
    binary[index] = '\0';
    
    //printing out the hexadecimal
    int i = index;
    //reversed the string
    for(; i >= 0; --i) {
        printf("%c", binary[i]);

    if(i % 4 == 0) printf(" ");
   }

    printf("\n");
}

 //MAIN
int main (int argc, char* argv[]) {

    //DEC TO HEX
    if(strcmp(argv[1], "-x") == 0){ 
        int inputStr;

        printf("Enter any decimal number: \n");
        //reads till end of file
        while(scanf("%d", &inputStr) != EOF) {
            decToHex(inputStr);
        }
        
    }

    //DEC TO BINARY 
    else if(strcmp(argv[1], "-b") == 0){
        int inputStr;

        printf("Enter any decimal number: \n");
        //reads till end of file
        while(scanf("%d", &inputStr) != EOF) {
            decToBinary(inputStr);
        }
    }
    else{
        printf("Wrong conversion input\n");
    }
}