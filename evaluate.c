#include <stdio.h>
#include <stdlib.h>

// Function to read the next operator from the input expression
char get_op(void) {
    char op;
    char c;
    // Skip spaces before operator
    while ((c = getchar()) == ' ');
    op = c;
    // Check for valid operators: +, -, *, /, %, or newline indicating end of expression
    if (op != '+' && op != '-' && op != '*' && op != '/' && op != '%' && op != '\n') {
        printf("Error: Invalid operator '%c'\n", op);
        exit(EXIT_FAILURE);
    }
    return op;
}

// Function to read the next numeric value from the input expression
float get_num(void) {
    float num;
    char c;
    // Skip spaces before number
    while ((c = getchar()) == ' ');
    ungetc(c, stdin); // Return non-space character back to input stream
    scanf("%f", &num);
    return num;
}

// Recursive function to evaluate the arithmetic expression
float sub_sim_exp(float sub_exp) {
    char next_op = get_op();
    if (next_op == '\n') {
        return sub_exp; // Return the final result when the expression ends
    } else {
        float next_num = get_num(); // Read the next numeric value
        // Perform the corresponding operation based on the next operator
        if (next_op == '+') {
            return sub_sim_exp(sub_exp + next_num);
        } else if (next_op == '-') {
            return sub_sim_exp(sub_exp - next_num);
        } else if (next_op == '*') {
            return sub_sim_exp(sub_exp * next_num);
        } else if (next_op == '/') {
            if (next_num != 0) {
                return sub_sim_exp(sub_exp / next_num);
            } else {
                printf("Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
        } else if (next_op == '%') {
            if (next_num != 0) {
                return sub_sim_exp((int)sub_exp % (int)next_num);
            } else {
                printf("Error: Modulus by zero\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    return 0; // This should never be reached
}

// Function to initiate the evaluation of the arithmetic expression
float sim_exp(void) {
    float num = get_num(); // Get the first numeric value
    return sub_sim_exp(num); // Start the recursive evaluation
}

// Main function
int main() {
    char choice;
    // Main loop to handle multiple expressions
    do {
        // Prompt the user to enter a simple arithmetic expression
        printf("Enter a simple arithmetic expression: ");
        float result = sim_exp(); // Evaluate the expression and get the result
        printf("Result: %.2f\n", result); // Print the result
        
        // Ask the user if they want to continue
        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &choice); // Note the space before %c to consume the newline character
        
        // Clear the input buffer
        while ((getchar()) != '\n');
    } while (choice == 'Y' || choice == 'y'); // Continue if the user enters 'Y' or 'y'

    return 0; // Exit the program
}
