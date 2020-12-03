#include <stdio.h>
#include <stdlib.h>

int calculate_single_fuel(int mass)
{
    return (mass / 3) - 2;
}

int calculate_complex_fuel(int mass)
{
    int fuel = (mass / 3) - 2;

    if (fuel < 0)
    {
        return 0;
    }
    else {
        return fuel + calculate_complex_fuel(fuel);
    }
}

int main(int argc, char * argv[])
{
    FILE * input = fopen("day01.txt", "r");

    char * line = NULL;
    size_t line_size = 0;
    
    int total_simple_fuel = 0;
    int total_complex_fuel = 0;
    
    while(getline(&line, &line_size, input) != -1)
    {
        int mass = atoi(line);

        total_simple_fuel += calculate_single_fuel(mass);
        total_complex_fuel += calculate_complex_fuel(mass);

        free(line);
        line = NULL;   
    }

    printf("Simple fuel: %d\n", total_simple_fuel);
    printf("Simple fuel: %d\n", total_complex_fuel);
   

}