```markdown
# 📐 Factorial Calculator in C

This is a simple C program that calculates the **factorial** of a non-negative integer using **recursion**.

---

## 🔍 What is a Factorial?

The factorial of a number `n` (written as `n!`) is the product of all positive integers from `1` to `n`.

- `0! = 1`
- `5! = 5 × 4 × 3 × 2 × 1 = 120`

---

## 🛠️ Features

- Accepts a non-negative integer input from the user.
- Calculates the factorial using a **recursive function**.
- Handles invalid (negative) input with an error message.
- Uses `long long` to support large values (up to `20!` safely).

---

## 📁 File Structure

```

factorial/
│
├── factorial.c     # Main C source file
└── README.md       # Project documentation

````

---

## 🚀 How to Run

1. **Compile the code** using GCC or any C compiler:
```bash
gcc factorial.c -o factorial
````

2. **Run the executable**:

```bash
./factorial
```

---

## 📌 Example Output

```
Enter the value of n : 6
The factorial of 6! is : 720
```

If a negative number is entered:

```
Enter the value of n : -3
ERROR invalid input.
```

---

## ⚠️ Notes

* Maximum safe input: `n <= 20`, due to `long long` limit and recursion depth.
* For very large numbers, consider using **iterative methods** or **arbitrary-precision libraries**.

---

## 👨‍💻 Author

Sparsh Singh
B.Tech CSE Student, Central University of Rajasthan

```

---

Let me know if you'd like to include this in a GitHub project or need an **iterative version** as well.
```
