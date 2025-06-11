#include <stdio.h>
#include <math.h>

static double result;
static int a1, a2, a3, a4, a5, a6;

// Airthematic Functions
double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double divide(double a, double b) { return a / b; }
double mul(double a, double b) { return a * b; }

// Bitwise Functions
int and(int a, int b) { return a & b; }
int or(int a, int b) { return a | b; }
int xor(int a, int b) { return a ^ b; }
int not(int a) { return ~a; }
int leftShift(int a, int n) { return a << n; }
int rightShift(int a, int n) { return a >> n; }

// Trignometric Functions
double Sin(double x) { return sin(x); }
double Cos(double x) { return cos(x); }
double Tan(double x) { return tan(x); }
double Sec(double x) { return 1 / cos(x); }
double Cosec(double x) { return 1 / sin(x); }
double Cot(double x) { return 1 / tan(x); }

// Inverse-Trignometric Functions
double aSin(double x) { return asin(x); }
double aCos(double x) { return acos(x); }
double aTan(double x) { return atan(x); }
double aSec(double x) { return acos(1 / x); }
double aCosec(double x) { return asin(1 / x); }
double aCot(double x) { return atan(1 / x); }

// Function for factorial
double factorial(double a)
{
    if (a == 0 || a == 1)
    {
        return 1;
    }

    return a * factorial(a - 1);
}

// Function for calculating power
int power(int base, int expo)
{
    int result = 1;
    for (int i = 0; i < expo; i++)
    {
        result *= base;
    }
    return result;
}

void menuBack(int *flag)
{
    int input;
    printf("Enter 1 to continue, 0 to GOTO main menu: \n");
    scanf("%d", &input);
    if (input == 0 || input == 1)
        *flag = input;
    else
    {
        printf("Invalid input. Try again.\n");
        menuBack(flag);
    }
}

void mainMenu(int *flag)
{
    int input;
    printf("Enter 1 for the main menu options, 0 to EXIT from the claculator :-\n");
    scanf("%d", &input);
    if (input == 0 || input == 1)
    {
        *flag = input;
    }
    else
    {
        printf("------------------Invalid input. Try again.---------------\n");
        mainMenu(flag);
    }
}

int main()
{
    int options;
    int action = 1;
    while (action)
    {

        printf("........WELCOME TO THE SIMPLE CALCULATOR.........\n\n");
        printf("ENTER (1) FOR : Addion, Subtraction, Multiplication, Division\n");
        printf("ENTER (2) FOR : BitWise AND, OR, NOT, XOR, LEFTSHIFT, RIGHTSHIFT\n");
        printf("ENTER (3) FOR : Trignometric functions Sin(), Cos(), Sec(), Cosec(), Tan(), Cot()\n");
        printf("ENTER (4) FOR : Inverse-Trignometric functions Sin^-1(), Cos^-1(), Sec^-1(), Cosec^-1(), Tan^-1(), Cot^-1()\n");
        printf("ENTER (5) FOR : Factorial for 'x' \n");
        printf("ENTER (6) FOR : For calculating X^y\n\n");
        printf("Choose one the above options :-\n");
        scanf("%d", &options);

        if (options == 1) // AIRTHEMATIC OPERATIONS
        {
            a1 = 1;
            while (a1)
            {
                int op;
                double a, b, result;
                printf("\nENTER (1) FOR : Addion\n");
                printf("ENTER (2) FOR : Subtraction\n");
                printf("ENTER (3) FOR : Multiplication\n");
                printf("ENTER (4) FOR : Division\n\n");
                printf("Choose one the above options :-\n");
                scanf("%d", &op);

                printf("\nEnter the value of 'a' and 'b' respectively :- \n");
                scanf("%lf %lf", &a, &b);

                switch (op)
                {
                case 1:
                    result = add(a, b);
                    printf("The sum of a = '%.2lf' and b = '%.2lf' is a + b = %.2lf \n", a, b, result);

                    break;

                case 2:
                    result = sub(a, b);
                    printf("The sub of a = '%.2lf' and b = '%.2lf' is a - b = %.2lf \n", a, b, result);

                    break;

                case 3:
                    result = mul(a, b);
                    printf("The mul of a = '%.2lf' and b = '%.2lf' is a * b = %.2lf \n", a, b, result);

                    break;

                case 4:
                    if (b == 0)
                    {
                        printf("Division by Zero is not allowed\n");
                    }
                    else
                    {
                        result = divide(a, b);
                        printf("The divisio of a = '%.2lf' and b = '%.2lf' is a/ b = %.2lf \n", a, b, result);
                    }
                    break;

                default:
                    printf("--------------:Invalid input try again:-----------------\n");
                    break;
                }
                menuBack(&a1);
            }
        }
        else if (options == 2)
        {
            a2 = 1;
            while (a2)
            {
                int op, n;
                int a, b, result;
                printf("\nENTER (1) FOR : BitWise AND\n");
                printf("ENTER (2) FOR : BitWise OR\n");
                printf("ENTER (3) FOR : BitWise NOT\n");
                printf("ENTER (4) FOR : BitWise XOR\n");
                printf("ENTER (5) FOR : BitWise LEFTSHIFT\n");
                printf("ENTER (6) FOR : BitWise RIGHTSHIFT\n\n");

                printf("Choose on the above options :-\n ");
                scanf("%d", &op);

                printf("\nEnter the value of 'a' and 'b' respectively :- \n");
                scanf("%d %d", &a, &b);
                switch (op)
                {
                case 1:
                    result = and(a, b);
                    printf("The value of a & b = %d\n", result);

                    break;

                case 2:
                    result = or(a, b);
                    printf("The value of a | b = %d\n", result);

                    break;

                case 3:
                    result = not(a);
                    printf("The value of ~a = %d\n", result);

                    break;

                case 4:
                    result = xor(a, b);
                    printf("The value of a ^ b = %d\n", result);

                    break;

                case 5:

                    printf("Enter the number of shifts :- \n");
                    scanf("%d", &n);
                    result = leftShift(a, n);
                    printf("The value of a << n = %d\n", result);

                    break;

                case 6:

                    printf("Enter the number of shifts :- \n");
                    scanf("%d", &n);
                    result = rightShift(a, n);
                    printf("The value of a >> n = %d\n", result);

                    break;

                default:
                    printf("--------------:Invalid input try again:-----------------\n");
                    break;
                }
                menuBack(&a2);
            }
        }
        else if (options == 3)
        {
            a3 = 1;
            while (a3)
            {
                double x, result;
                int op;

                printf("\nENTER (1) FOR : Trignometric functions Sin()\n");
                printf("ENTER (2) FOR : Trignometric functions Cos()\n");
                printf("ENTER (3) FOR : Trignometric functions Sec()\n");
                printf("ENTER (4) FOR : Trignometric functions Cosec()\n");
                printf("ENTER (5) FOR : Trignometric functions Tan()\n");
                printf("ENTER (6) FOR : Trignometric functions Cot()\n\n");

                printf("Choose on the above options :-\n ");
                scanf("%d", &op);
                printf("\nEnter the value of 'x' :- \n");
                scanf("%lf", &x);

                switch (op)
                {
                case 1:
                    result = Sin(x);
                    printf("The value of Sin(x) is '%lf'\n", result);
                    break;
                case 2:
                    result = Cos(x);
                    printf("The value of Cos(x) is '%lf'\n", result);
                    break;
                case 3:
                    if (cos(x) == 0)
                    {
                        printf("Error: Undefined result because cos(x) = 0.\n");
                        continue;
                    }
                    result = Sec(x);
                    printf("The value of Sec(x) is '%lf'\n", result);
                    break;
                case 4:
                    if (sin(x) == 0)
                    {
                        printf("Error: Undefined result because sin(x) = 0.\n");
                        continue;
                    }
                    result = Cosec(x);
                    printf("The value of Cosec(x) is '%lf'\n", result);
                    break;
                case 5:
                    if (cos(x) == 0)
                    {
                        printf("Error: Undefined result because cos(x) = 0.\n");
                        continue;
                    }
                    result = Tan(x);
                    printf("The value of Tan(x) is '%lf'\n", result);
                    break;
                case 6:
                    if (sin(x) == 0)
                    {
                        printf("Error: Undefined result because sin(x) = 0.\n");
                        continue;
                    }
                    result = Cot(x);
                    printf("The value of Cot(x) is '%lf'\n", result);
                    break;
                default:
                    printf("--------------:Invalid input try again:-----------------\n");
                    break;
                }
                menuBack(&a3);
            }
        }
        else if (options == 4)
        {
            a4 = 1;
            while (a4)
            {
                double x, result;
                int op;

                printf("ENTER (1) FOR : Inverse-Trignometric functions Sin^-1()\n");
                printf("ENTER (2) FOR : Inverse-Trignometric functions Cos^-1()\n");
                printf("ENTER (3) FOR : Inverse-Trignometric functions Sec^-1()\n");
                printf("ENTER (4) FOR : Inverse-Trignometric functions Cosec^-1()\n");
                printf("ENTER (5) FOR : Inverse-Trignometric functions Tan^-1()\n");
                printf("ENTER (6) FOR : Inverse-Trignometric functions Cot^-1()\n");

                printf("Choose on the above options :-\n ");
                scanf("%d", &op);
                printf("Enter the value of 'x' :- \n");
                scanf("%lf", &x);

                switch (op)
                {
                case 1:
                    if (x < -1 || x > 1)
                    {
                        printf("Error: Input must be in [-1, 1] for asin() or acos().\n");
                        continue;
                    }
                    result = aSin(x);
                    printf("The value of Sin^-1(x) is '%lf'\n", result);
                    break;
                case 2:
                    if (x < -1 || x > 1)
                    {
                        printf("Error: Input must be in [-1, 1] for asin() or acos().\n");
                        continue;
                    }
                    result = aCos(x);
                    printf("The value of Cos^-1(x) is '%lf'\n", result);
                    break;
                case 3:
                    if (x > -1 && x < 1)
                    {
                        printf("Error: Input must be ≤ -1 or ≥ 1 for asec() or acosec().\n");
                        continue;
                    }
                    result = aSec(x);
                    printf("The value of Sec^-1(x) is '%lf'\n", result);
                    break;
                case 4:
                    if (x > -1 && x < 1)
                    {
                        printf("Error: Input must be ≤ -1 or ≥ 1 for asec() or acosec().\n");
                        continue;
                    }
                    result = aCosec(x);
                    printf("The value of Cosec^-1(x) is '%lf'\n", result);
                    break;
                case 5:
                    result = aTan(x);
                    printf("The value of Tan^-1(x) is '%lf'\n", result);
                    break;
                case 6:
                    result = aCot(x);
                    printf("The value of Cot^-1(x) is '%lf'\n", result);
                    break;
                default:
                    printf("--------------:Invalid input try again:-----------------\n");
                    break;
                }
                menuBack(&a4);
            }
        }
        else if (options == 5)
        {
            a5 = 1;
            while (a5)
            {
                double a, result;
                printf("Enter the Number :-\n");
                scanf("%lf", &a);
                if (a < 0 || floor(a) != a)
                {
                    printf("Factorial is only defined for non-negative integers.\n");
                }
                else
                {
                    result = factorial(a);
                    printf("The factorial of a = '%lf' is '%lf'\n", a, result);
                }
                menuBack(&a5);
            }
        }
        else if (options == 6)
        {
            a6 = 1;
            while (a6)
            {
                int result, base, expo;
                printf("Enter the value of base and power respectively :- \n");
                scanf("%d %d", &base, &expo);
                result = power(base, expo);
                printf("The value of %d^%d is '%d'\n", base, expo, result);
                menuBack(&a6);
            }
        }
        else
        {
            mainMenu(&action);
        }
    }

    return 0;
}