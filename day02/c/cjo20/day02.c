#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute_program(int * program, int ctr)
{
    while(1)
    {
        switch(program[ctr])
        {
            case 1: // ADD
                {
                    int a_loc = program[ctr + 1];
                    int b_loc = program[ctr + 2];
                    int c_loc = program[ctr + 3];
                    ctr += 4;
                    program[c_loc] = program[a_loc] + program[b_loc];
                    break;
                }
            case 2: // MUL
                {
                    int a_loc = program[ctr + 1];
                    int b_loc = program[ctr + 2];
                    int c_loc = program[ctr + 3];
                    ctr += 4;
                    program[c_loc] = program[a_loc] * program[b_loc];
                    break;
                }
            case 99:    
                {
                    return;
                }
            default:
                printf("Invalid opcode %d\n", program[ctr]);
                exit(1);
        }
    }
}


int main(int argc, char * argv[])
{
    int input[] = {1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,10,1,19,1,19,9,23,1,23,6,27,1,9,27,31,1,31,10,35,2,13,35,39,1,39,10,43,1,43,9,47,1,47,13,51,1,51,13,55,2,55,6,59,1,59,5,63,2,10,63,67,1,67,9,71,1,71,13,75,1,6,75,79,1,10,79,83,2,9,83,87,1,87,5,91,2,91,9,95,1,6,95,99,1,99,5,103,2,103,10,107,1,107,6,111,2,9,111,115,2,9,115,119,2,13,119,123,1,123,9,127,1,5,127,131,1,131,2,135,1,135,6,0,99,2,0,14,0};
    int input_size = sizeof(input) / sizeof(int);
    
    int * program_cpy = (int *) malloc(input_size * sizeof(int));
    memcpy(program_cpy, input, input_size * sizeof(int));

    program_cpy[1] = 12;
    program_cpy[2] = 2;
    execute_program(program_cpy, 0);
    printf("Result: %d\n", input[0]);

    for (int i = 0; i < input_size; ++i)
    {
        for (int j = 0; j < input_size; ++j)
        {
            memcpy(program_cpy, input, input_size * sizeof(int));        

            program_cpy[1] = i;
            program_cpy[2] = j;

            execute_program(program_cpy, 0);

            if (program_cpy[0] == 19690720)
            {
                printf("Solution Found! %d\n", i * 100 + j);
                return 0;
            }
        }
    }
    
    printf("No solution found\n");
    

    return 1;
}