# Simple Calculator

This is a simple command-line calculator program written in C that provides various arithmetic, bitwise, trigonometric, inverse trigonometric, factorial, and power functions.

---

## Features

* **Arithmetic Operations:** Perform addition, subtraction, multiplication, and division.
* **Bitwise Operations:** Execute AND, OR, NOT, XOR, left shift, and right shift operations.
* **Trigonometric Functions:** Calculate sine, cosine, tangent, secant, cosecant, and cotangent.
* **Inverse Trigonometric Functions:** Determine arcsine, arccosine, arctangent, arcsecant, arccosecant, and arccotangent.
* **Factorial:** Compute the factorial of a non-negative integer.
* **Power:** Calculate the power of a base raised to an exponent.

---

## How to Compile and Run

1.  **Save the code:** Save the provided C code into a file named `calculator.c`.
2.  **Compile:** Open a terminal or command prompt and compile the code using a C compiler (like GCC):

    ```bash
    gcc calculator.c -o calculator -lm
    ```
    The `-lm` flag is essential for linking the math library, which is required for trigonometric and inverse trigonometric functions.

3.  **Run:** Execute the compiled program:

    ```bash
    ./calculator
    ```

---

## Usage

Upon running the program, you will be presented with a main menu offering different categories of operations.

### Main Menu

.......WELCOME TO THE SIMPLE CALCULATOR.........

ENTER (1) FOR : Addion, Subtraction, Multiplication, Division
ENTER (2) FOR : BitWise AND, OR, NOT, XOR, LEFTSHIFT, RIGHTSHIFT
ENTER (3) FOR : Trignometric functions Sin(), Cos(), Sec(), Cosec(), Tan(), Cot()
ENTER (4) FOR : Inverse-Trignometric functions Sin^-1(), Cos^-1(), Sec^-1(), Cosec^-1(), Tan^-1(), Cot^-1()
ENTER (5) FOR : Factorial for 'x'
ENTER (6) FOR : For calculating X^y

Choose one the above options :-

### Navigating the Calculator

* Enter the number corresponding to the desired category of operations.
* Within each category, you will be prompted to choose a specific operation and enter the required input values.
* After each calculation, you'll have the option to **continue within the current menu (1)** or **return to the main menu (0)**.
* To **exit the calculator**, enter `0` when prompted in the main menu loop.

### Examples:

#### Arithmetic Operations:

1.  Choose option `1` from the main menu.
2.  Select an arithmetic operation (e.g., `1` for Addition).
3.  Enter the two numbers when prompted.

    ```
    ENTER (1) FOR : Addion
    ENTER (2) FOR : Subtraction
    ENTER (3) FOR : Multiplication
    ENTER (4) FOR : Division

    Choose one the above options :-
    1

    Enter the value of 'a' and 'b' respectively :-
    10 5
    The sum of a = '10.00' and b = '5.00' is a + b = 15.00
    Enter 1 to continue, 0 to GOTO main menu:
    ```

#### Factorial:

1.  Choose option `5` from the main menu.
2.  Enter a non-negative integer when prompted.

    ```
    ENTER (5) FOR : Factorial for 'x'

    Enter the Number :-
    5
    The factorial of a = '5.000000' is '120.000000'
    Enter 1 to continue, 0 to GOTO main menu:
    ```

#### Error Handling:

The calculator includes basic error handling for invalid inputs (e.g., division by zero, invalid range for inverse trigonometric functions, or non-integer/negative input for factorial).

---

## Code Structure

The code is organized into several functions:

* **`add`, `sub`, `divide`, `mul`**: Perform basic arithmetic operations.
* **`and`, `or`, `xor`, `not`, `leftShift`, `rightShift`**: Handle bitwise operations.
* **`Sin`, `Cos`, `Tan`, `Sec`, `Cosec`, `Cot`**: Implement trigonometric functions.
* **`aSin`, `aCos`, `aTan`, `aSec`, `aCosec`, `aCot`**: Implement inverse trigonometric functions.
* **`factorial`**: Calculates the factorial of a number recursively.
* **`power`**: Calculates the power of a base to an exponent iteratively.
* **`menuBack`**: Prompts the user to continue in the current sub-menu or return to the main menu.
* **`mainMenu`**: Prompts the user to continue to the main menu or exit the calculator.
* **`main`**: The main function that drives the calculator's user interface and logic.

---

## Requirements

* A C compiler (e.g., GCC)
* The `math.h` library (usually included with standard C installations)

---

## Author
SPARSH SINGH
---
