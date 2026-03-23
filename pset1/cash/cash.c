#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);
    
    // Convert dollars to cents (e.g., 0.41 -> 41 cents)
    int cents = round(dollars * 100);
    int coins = 0;
    
    // Quarters
    coins += cents / 25;
    cents = cents % 25;
    
    // Dimes
    coins += cents / 10;
    cents = cents % 10;
    
    // Nickels
    coins += cents / 5;
    cents = cents % 5;
    
    // Pennies
    coins += cents;
    
    printf("%i\n", coins);
}
