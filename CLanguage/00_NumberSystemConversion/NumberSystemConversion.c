/*
*   @Author: Vivek Bhandare
*   Student @ AstroMediComp
*    
*   Converting a number from one number system to another
*    
*       01. Decimal to Binary
*       02. Decimal to Octal
*       03. Decimal to Hexadecimal
* 
*       04. Binary to Decimal
*       05. Octal to Decimal
*       06. Hexadecimal to Decimal
*   
*       07. Binary to Octal
*       08. Binary to Hexadecimal
*    
*       09. Octal to Binary
*       10. Octal to Hexadecimal
*   
*       11. Hexadecimal to Binary
*       12. Hexadecimal to Octal
*/


#include <stdio.h> //for printf()


//defining the constants here to use later in code
#define BINARY_BASE 2
#define OCTAL_BASE 8
#define HEXADEC_BASE 16
#define DECIMAL_BASE 10

//this defines whether the number should be of 8 or 16 or 32 bits
#define HOW_MUCH_BITS 32

//'A' to 'F' ASCII values => 65 to 70
#define UPPER_CASE_A 65
#define UPPER_CASE_F 70

//'0' to '9' ASCII values => 48 to 57
#define DIGIT_0 48
#define DIGIT_9 57


int main(void)
{
    //function declarations
    int* decimal_to_any(int, int);
    int any_to_decimal(char*, int, int);
    int print_array_elements(int*, int, int);
    int power(int, int);

    //variable declarations
    char conversion_type;

    int decimal_to_what;
    int decimal_number;
    int* answer;

    int what_to_decimal;
    char bin_or_oct_or_hex_number[HOW_MUCH_BITS];
    int answer_in_decimal;

    int binary_to_what;
    char binary_number[HOW_MUCH_BITS];

    int octal_to_what;
    char octal_number[HOW_MUCH_BITS];

    int hexadecimal_to_what;
    char hexadecimal_number[HOW_MUCH_BITS];


    //code
    printf("Which number system conversion you want to do ?\n\n");
    printf("Enter 'A' or 'a' For Decimal to Binary/Octal/Hexadecimal\n");
    printf("Enter 'B' or 'b' For Binary/Octal/Hexadecimal to Decimal\n");
    printf("Enter 'C' or 'c' For Binary to Octal/Hexadecimal\n");
    printf("Enter 'D' or 'd' For Octal to Binary/Hexadecimal\n");
    printf("Enter 'E' or 'e' For Hexadecimal to Binary/Octal\n");
    scanf("%c", &conversion_type);


    //main switch-case for what type of conversion we want to do
    switch (conversion_type)
    {
    //case 'A' or 'a' => Decimal to Binary/Octal/Hexadecimal
    case 'A':
    case 'a':
        printf("Enter 1 For Decimal to Binary\n");
        printf("Enter 2 For Decimal to Octal\n");
        printf("Enter 3 For Decimal to Hexadecimal\n");
        scanf("%d", &decimal_to_what);

        switch (decimal_to_what)
        {

        case 1:
            printf("Enter the Decimal Number for converting it into Binary : ");
            scanf("%d", &decimal_number);
            answer = decimal_to_any(decimal_number, BINARY_BASE);
            printf("Decimal Number : %d Is Converted To Binary Number : ", decimal_number);
            break;

        case 2:
            printf("Enter the Decimal Number for converting it into Octal : ");
            scanf("%d", &decimal_number);
            answer = decimal_to_any(decimal_number, OCTAL_BASE);
            printf("Decimal Number : %d Is Converted To Octal Number : ", decimal_number);
            break;

        case 3:
            printf("Enter the Decimal Number for converting it into Hexadecimal : ");
            scanf("%d", &decimal_number);
            answer = decimal_to_any(decimal_number, HEXADEC_BASE);
            printf("Decimal Number : %d Is Converted To Hexadecimal Number : ", decimal_number);
            break;

        default: //'default' for case(decimal_to_what)
            printf("Invalid Option Entered For Conversion Of Decimal To Binary/Octal/Hexadecimal !!! Please try again !!!\n");
            break;

        } //ending curly brace of switch(decimal_to_what)

        //below function will print converted number from decimal
        print_array_elements(answer, HOW_MUCH_BITS, decimal_to_what);
        
        break; //break for case 'A' or case 'a'

    //case 'B' or 'b' => Binary/Octal/Hexadecimal to Decimal
    case 'B':
    case 'b':
        printf("Enter 1 For Binary to Decimal\n");
        printf("Enter 2 For Octal to Decimal\n");
        printf("Enter 3 For Hexadecimal to Decimal\n");
        scanf("%d", &what_to_decimal);

        switch (what_to_decimal)
        {
        case 1:
            printf("Enter the Binary Number for converting it into Decimal : ");
            scanf("%s", &bin_or_oct_or_hex_number);
            answer_in_decimal = any_to_decimal(bin_or_oct_or_hex_number, BINARY_BASE, what_to_decimal);
            printf("Binary Number : %s Is Converted To Decimal Number : %d", bin_or_oct_or_hex_number, answer_in_decimal);
            break;

        case 2:
            printf("Enter the Octal Number for converting it into Decimal : ");
            scanf("%s", &bin_or_oct_or_hex_number);
            answer_in_decimal = any_to_decimal(bin_or_oct_or_hex_number, OCTAL_BASE, what_to_decimal);
            printf("Octal Number : %s Is Converted To Decimal Number : %d", bin_or_oct_or_hex_number, answer_in_decimal);
            break;

        case 3:
            printf("Enter the Hexadecimal Number for converting it into Decimal : ");
            scanf("%s", &bin_or_oct_or_hex_number);
            answer_in_decimal = any_to_decimal(bin_or_oct_or_hex_number, HEXADEC_BASE, what_to_decimal);
            printf("Hexadecimal Number : %s Is Converted To Decimal Number : %d", bin_or_oct_or_hex_number, answer_in_decimal);
            break;

        default: //'default' for case(what_to_decimal)
            printf("Invalid Option Entered For Conversion Of Binary/Octal/Hexadecimal To Decimal !!! Please try again !!!\n");
            break;
        } //ending curly brace of switch(what_to_decimal)

        break; //break for case 'B' or case 'b'

    //case 'C' or 'c' => Binary to Octal/Hexadecimal
    case 'C':
    case 'c':
        printf("Enter 1 For Binary to Octal\n");
        printf("Enter 2 For Binary to Hexadecimal\n");
        scanf("%d", &binary_to_what);

        switch (binary_to_what)
        {
        case 1:
            printf("Enter the Binary Number for converting it into Octal : ");
            scanf("%s", &binary_number);
            //first converting the given binary number to decimal
            answer_in_decimal = any_to_decimal(binary_number, BINARY_BASE, binary_to_what);
            printf("First converted the Binary Number : %s To Decimal Number : %d\n", binary_number, answer_in_decimal);
            //then converting that decimal number to octal
            answer = decimal_to_any(answer_in_decimal, OCTAL_BASE);
            printf("Then converted the Decimal Number : %d To Octal Number : ", answer_in_decimal);
            print_array_elements(answer, HOW_MUCH_BITS, 1);
            break;

        case 2:
            printf("Enter the Binary Number for converting it into Hexadecimal : ");
            scanf("%s", &binary_number);
            //first converting the given binary number to decimal
            answer_in_decimal = any_to_decimal(binary_number, BINARY_BASE, binary_to_what);
            printf("First converted the Binary Number : %s To Decimal Number : %d\n", binary_number, answer_in_decimal);
            //then converting that decimal number to hexadecimal
            answer = decimal_to_any(answer_in_decimal, HEXADEC_BASE);
            printf("Then converted the Decimal Number : %d To Hexadecimal Number : ", answer_in_decimal);
            print_array_elements(answer, HOW_MUCH_BITS, 3);
            break;

        default: //'default' for case(binary_to_what)
            printf("Invalid Option Entered For Conversion Of Binary to Octal/Hexadecimal !!! Please try again !!!\n");
            break;
        }

        break; //break for case 'C' or case 'c'

    //case 'D' or 'd' => Octal to Binary/Hexadecimal
    case 'D':
    case 'd':
        printf("Enter 1 For Octal to Binary\n");
        printf("Enter 2 For Octal to Hexadecimal\n");
        scanf("%d", &octal_to_what);

        switch (octal_to_what)
        {
        case 1:
            printf("Enter the Octal Number for converting it into Binary : ");
            scanf("%s", &octal_number);
            //first converting the given octal number to decimal
            answer_in_decimal = any_to_decimal(octal_number, OCTAL_BASE, 2);
            printf("First converted the Octal Number : %s To Decimal Number : %d\n", octal_number, answer_in_decimal);
            //then converting that decimal number to binary
            answer = decimal_to_any(answer_in_decimal, BINARY_BASE);
            printf("Then converted the Decimal Number : %d To Binary Number : ", answer_in_decimal);
            print_array_elements(answer, HOW_MUCH_BITS, 1);
            break;

        case 2:
            printf("Enter the Octal Number for converting it into Hexadecimal : ");
            scanf("%s", &octal_number);
            //first converting the given octal number to decimal
            answer_in_decimal = any_to_decimal(octal_number, OCTAL_BASE, 2);
            printf("First converted the Octal Number : %s To Decimal Number : %d\n", octal_number, answer_in_decimal);
            //then converting that decimal number to hexadecimal
            answer = decimal_to_any(answer_in_decimal, HEXADEC_BASE);
            printf("Then converted the Decimal Number : %d To Hexadecimal Number : ", answer_in_decimal);
            print_array_elements(answer, HOW_MUCH_BITS, 3);
            break;

        default: //'default' for case(octal_to_what)
            printf("Invalid Option Entered For Conversion Of Octal to Binary/Hexadecimal !!! Please try again !!!\n");
            break;
        }

        break; //break for case 'D' or case 'd'

    //case 'E' or 'e' => Hexadecimal to Binary/Octal
    case 'E':
    case 'e':
        printf("Enter 1 For Hexadecimal to Binary\n");
        printf("Enter 2 For Hexadecimal to Octal\n");
        scanf("%d", &hexadecimal_to_what);

        switch (hexadecimal_to_what)
        {
        case 1:
            printf("Enter the Hexadecimal Number for converting it into Binary : ");
            scanf("%s", &hexadecimal_number);
            //first converting the given hexadecimal number to decimal
            answer_in_decimal = any_to_decimal(hexadecimal_number, HEXADEC_BASE, 3);
            printf("First converted the Hexadecimal Number : %s To Decimal Number : %d\n", hexadecimal_number, answer_in_decimal);
            //then converting that decimal number to binary
            answer = decimal_to_any(answer_in_decimal, BINARY_BASE);
            printf("Then converted the Decimal Number : %d To Binary Number : ", answer_in_decimal);
            print_array_elements(answer, HOW_MUCH_BITS, 1);
            break;

        case 2:
            printf("Enter the Hexadecimal Number for converting it into Octal : ");
            scanf("%s", &hexadecimal_number);
            //first converting the given hexadecimal number to decimal
            answer_in_decimal = any_to_decimal(hexadecimal_number, HEXADEC_BASE, 3);
            printf("First converted the Hexadecimal Number : %s To Decimal Number : %d\n", hexadecimal_number, answer_in_decimal);
            //then converting that decimal number to octal
            answer = decimal_to_any(answer_in_decimal, OCTAL_BASE);
            printf("Then converted the Decimal Number : %d To Octal Number : ", answer_in_decimal);
            print_array_elements(answer, HOW_MUCH_BITS, 2);
            break;

        default: //'default' for case(hexadecimal_to_what)
            printf("Invalid Option Entered For Conversion Of Hexadecimal to Binary/Octal !!! Please try again !!!\n");
            break;
        }

        break; //break for case 'D' or case 'd'

    default:
        printf("Invalid Option Entered For Conversion Type !!! Please try again !!!\n");
        break; //'default' for case(conversion_type)

    } //ending curly brace of switch(conversion_type)

    return(0);
}


//below function converts a decimal number to either binary or octal or hexadecimal number
int* decimal_to_any(int in_dec_num, int in_base_digits)
{
    //variable declarations
    int quotient;
    int remainder;
    int static array_to_return[HOW_MUCH_BITS];
    int highest_index;

    //suppose constant's value is 8 then assign a value of 7 to variable 'highest_index' to fill the array in reverse order further
    highest_index = HOW_MUCH_BITS - 1;

    //do-while loop until quotient is zero
    do
    {
        quotient = in_dec_num / in_base_digits;
        remainder = in_dec_num % in_base_digits;
        array_to_return[highest_index] = remainder; //assigning the values of remainder to array in reverse order
        highest_index = highest_index - 1;
        in_dec_num = quotient;
    } while (quotient != 0);

    //the name of the array is itself its address
    return(array_to_return);
}


//below function converts either binary or octal or hexadecimal number to decimal number
int any_to_decimal(char* in_var_num, int in_base_digits, int what_to_dec)
{
    //variable declarations
    int decimal_num_to_return = 0;
    int index = 0;

    
    for (int bit = HOW_MUCH_BITS - 1; bit >= 0; bit--)
    {
        //if block for converting binary/octal number to decimal number
        if ((what_to_dec == 1 || what_to_dec == 2))
        {
            if ((int)in_var_num[bit] >= DIGIT_0 && (int)in_var_num[bit] <= DIGIT_9)
            {
                decimal_num_to_return = decimal_num_to_return + (((int)in_var_num[bit] - DIGIT_0) * power(in_base_digits, index));
                index++;
            }
            else
                continue;
        }
        //else if block for converting hexadecimal number to decimal number
        else if (what_to_dec == 3)
        {
            //assuming that the Hexadecimal Number entered is consist of 0 to 9 or A to F

            //if the entered character is a digit between 0 to 9
            if (((int)in_var_num[bit] >= DIGIT_0) && ((int)in_var_num[bit] <= DIGIT_9))
            {
                decimal_num_to_return = decimal_num_to_return + (((int)in_var_num[bit] - DIGIT_0) * power(in_base_digits, index));
                index++;
            }
            //if the entered character is a character between A to F
            else if (((int)in_var_num[bit] >= UPPER_CASE_A) && ((int)in_var_num[bit] <= UPPER_CASE_F))
            {
                decimal_num_to_return = decimal_num_to_return + (((int)in_var_num[bit] - (UPPER_CASE_A - 10)) * power(in_base_digits, index));
                index++;
            }
        }

    } //ending curly brace of for loop hexadecimal number to decimal number

    //return the converted decimal number
    return(decimal_num_to_return);
}


int print_array_elements(int* array_name, int array_size, int what_to_print)
{
    //variable declarations
    char print_leading_zero = 'N';

    //code
    for (int bit = 0; bit < array_size; bit++)
    {
        //if-block is for printing binary or octal number
        if ((what_to_print == 1) || (what_to_print == 2))
        {
            //below continue is to skip the printing of leading zero if any.
            if (array_name[bit] == 0 && (print_leading_zero == 'N'))
            {
                continue;
            }
            //if first non-zero value arrives in an array, then only the control will go to the else-block
            //thus assigning 'Y' to print_leading_zero so that above if condition will fail from the next iterations of for loop
            else
            {
                printf("%d", array_name[bit]);
                print_leading_zero = 'Y';
            }
        }
        //else-if block is for printing hexadecimal number
        else if (what_to_print == 3)
        {
            //below continue is to skip the printing of leading zero if any.
            if (array_name[bit] == 0 && (print_leading_zero == 'N'))
            {
                continue;
            }
            //if first non-zero value arrives in an array, then only the control will go to the else-block
            //thus assigning 'Y' to print_leading_zero so that above if condition will fail from the next iterations of for loop
            else
            {
                if ((array_name[bit] >= 10) && (array_name[bit] <= 15))
                {
                    //type casting integer value of 10 by adding it 55, so that it gives 65 which when casted to char gives A
                    //repeating this process from 10 to 15 so that we can print 'A' to 'F' values
                    printf("%c", (char)(array_name[bit] + 55));
                }
                else
                {
                    printf("%d", array_name[bit]);
                }
                print_leading_zero = 'Y';
            }
        }
    }
    printf("\n");

    return(0);
}


int power(int in_base, int in_power)
{
    //variable declarations
    int pow = 1;

    //code
    while (in_power > 0)
    {
        pow = pow * in_base;
        in_power--;
    }

    return(pow);
}
