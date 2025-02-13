# Overview
- Liner data structure
- Last In First Out structure **LIFO**
- Its a *stack* of something. you put something on the top, and then you take something from the top
- Opetaions:
    - Push an element on top od the stack
    - Pop and element, remove the top element of the stack
    - Peek is to see what on the top, but dont remove it
    - IsEmpty is to check if there are any elements in the stack
    - Size returns the number of elements in the stack

## Usage:
1. Funcion call management: used in most languages, the stack maintains the order of function calls
2. Parsing syntax: Used for seeing if expressions are correct 
3. DFS implements backtracking with a stack
**Example** Parser checks if every open bracket is closed. When it encounters "(" it pushes something on the stack. When it encounters ")" it removes somethign from the stack. At the end stack should be empty
**Example** Check the value and syntax of expression a\*b+c\*d. This is in a tree, and for the compiler it looks like: ab\*cd\*+. the stack puts a and b to the stack. Then it encounters *, so it takes 2 elements from the stack and multiplies them, and puts the value back in the stack. The same thing is done with the c and d and *. Then when it encounters +, it takes 2 elements from the stack, adds them together, and puts the result on the stack. Stack should have only 1 element, and it should be the result
