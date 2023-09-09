# Reverse Polish Notation (RPN)

Reverse Polish Notation, often abbreviated as RPN, is a mathematical notation used to represent mathematical expressions and perform calculations in a way that eliminates the need for parentheses to indicate the order of operations. RPN is also known as postfix notation because operators appear after their operands.

In RPN, the basic idea is to evaluate expressions from left to right, and whenever an operator is encountered, it is applied to the two operands immediately preceding it. This makes RPN particularly useful for computer programs and calculators because it eliminates the need to maintain a stack of parentheses and ensures a straightforward, unambiguous evaluation process.

## RPN Expression Format

In RPN, operators follow their operands. Here's how a typical RPN expression is structured:

`
Operand1 Operand2 Operator
`

For example, to express the addition of 3 and 4 in RPN, you would write:

`
3 4 +
`

## Valid RPN Expressions

Here are some examples of valid RPN expressions and their corresponding infix (traditional) notation:

1. **Addition**: RPN - `3 4 +` (Infix - `3 + 4`)
2. **Subtraction**: RPN - `5 2 -` (Infix - `5 - 2`)
3. **Multiplication**: RPN - `2 6 *` (Infix - `2 * 6`)
4. **Division**: RPN - `8 4 /` (Infix - `8 / 4`)
5. **Complex Expression**: RPN - `3 4 + 2 * 7 /` (Infix - `((3 + 4) * 2) / 7)`

## Invalid RPN Expressions

Here are examples of invalid RPN expressions, along with explanations for why they are not valid:

1. I**ncorrect Operator Placement**: RPN - `3 + 4` (Operators should appear after their operands in RPN; this is in infix notation.)
2. **Missing Operator**: RPN - `5 2` (An operator is missing; it's unclear what operation should be performed.)
3. **Unbalanced Operators**: RPN - `3 4 + +` (There is an extra operator without a corresponding operand.)

In RPN, it's crucial to maintain a proper order of operands and operators to ensure that expressions can be evaluated correctly without the need for parentheses.

RPN can be particularly useful in computer programming and calculator applications due to its simplicity and ease of implementation in algorithms for arithmetic operations. It eliminates the ambiguity associated with traditional infix notation and simplifies parsing and calculation processes.

## Why use the `std::stack` container?

### 1. LIFO (Last-In-First-Out) Structure

`std::stack` follows the **LIFO** (Last-In-First-Out) principle, which aligns perfectly with RPN's evaluation strategy. In RPN, operands are pushed onto the stack in the order they are encountered, and operators are applied to the most recently pushed operands. Using a stack for RPN allows us to maintain the correct order of operands and operators for efficient evaluation.

### 2. Natural Operand Storage

The `std::stack` container is well-suited for storing operands as they are encountered in the RPN expression. Operands can be pushed onto the stack as they are parsed from the expression, making it straightforward to retrieve and manipulate them when operators are encountered. This natural representation simplifies the code for RPN evaluation.

### 3. Operator Handling

Operators in RPN are used to perform calculations on the top elements of the stack. `std::stack` provides easy access to the top element (the most recently pushed operand), making it convenient to pop operands, apply operators, and push results back onto the stack. This aligns with RPN's evaluation process, which involves continuous operator handling.

### 4. Simplified Error Handling

Using `std::stack` can help simplify error handling in RPN evaluation. If the input RPN expression is well-formed, the stack should be empty after evaluation. If there are any errors, such as insufficient operands or extra operators, these can be easily detected by checking the stack's state. This simplifies error detection and reporting in the code.

### 5. Efficient Implementation

`std::stack` is typically implemented as a deque or a list, both of which provide efficient push and pop operations from the top of the stack. This efficiency is essential for the performance of RPN evaluation, especially when dealing with complex expressions.
