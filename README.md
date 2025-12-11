# Simple Arithmetic Expression Evaluator

This program reads and evaluates simple arithmetic expressions entered by the user. It works by reading one number at a time, then applying operators as they appear in order from left to right. The program supports addition, subtraction, multiplication, division, and modulus. It continues to run until the user chooses to stop.

# Features

The evaluator uses a recursive approach to process expressions. It reads the first number, then repeatedly reads the next operator and number pair. Each step updates the running total and calls the same function again until it reaches the end of the expression.

Supported operators

- + addition
− − subtraction

- * multiplication
− / division
− % modulus

The program stops and reports errors when an invalid operator appears or if the user tries division or modulus by zero.

# How the Program Works

The program is built around a few helper functions.

The operator reader skips spaces until it finds a valid operator. If the character is not allowed, the program exits with an error.
The number reader skips spaces and reads the next numeric value.
The recursive evaluator performs the operation and calls itself again until it hits a newline.

The main function prompts the user for an expression, displays the result, and then asks whether they want to evaluate another one.

```vbnet
Enter a simple arithmetic expression: 10 + 5 * 2
Result: 30.00
Do you want to continue? (Y/N): Y
Enter a simple arithmetic expression: 12 % 5 - 1
Result: 1.00
Do you want to continue? (Y/N): N
```
