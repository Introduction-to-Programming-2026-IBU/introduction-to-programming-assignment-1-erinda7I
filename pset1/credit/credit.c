#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");
    long temp = number;
    int sum = 0;
    int count = 0;
    int first_two = 0;
    
    // Luhn's Algorithm
    while (temp > 0)
    {
        int digit = temp % 10;
        count++;
        
        // Multiply every other digit by 2
        if (count % 2 == 0)
        {
            int doubled = digit * 2;
            sum += (doubled / 10) + (doubled % 10);
        }
        else
        {
            sum += digit;
        }
        
        // Get first two digits
        if (temp >= 10 && temp <= 99)
        {
            first_two = temp;
        }
        
        temp /= 10;
    }
    
    // Check if valid using Luhn's algorithm
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    
    // Check card type based on length and starting digits
    if ((count == 13 || count == 16) && (first_two / 10 == 4))
    {
        printf("VISA\n");
    }
    else if (count == 15 && (first_two == 34 || first_two == 37))
    {
        printf("AMEX\n");
    }
    else if (count == 16 && (first_two >= 51 && first_two <= 55))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
