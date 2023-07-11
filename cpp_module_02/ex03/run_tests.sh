#!/bin/bash

test_cases=(
    "1 2 3 4 5 6"                                 # Insufficient number of parameters
    ""                                            # No parameters
    "1 2 3 4 5 6 2 a"                             # At least one non-numeric parameter
    "2 2 0 0 4 0 2 4"                             # Point inside the triangle (integer coordinates)
    "3 3 0 0 4 0 2 4"                             # Point outside the triangle (integer coordinates)
    "2.5 2.5 0 0 4 0 2 4"                         # Point inside the triangle (floating-point coordinates)
    "3.5 3.5 0 0 4 0 2 4"                         # Point outside the triangle (floating-point coordinates)
    "0 0 0 0 4 0 2 4"                             # Point coincides with one of the vertices (integer coordinates)
    "2.5 4 0 0 4 0 2.5 4"                         # Point coincides with one of the vertices (floating-point coordinates)
    "2 1 1 1 3 1 2 4"                             # Point coincides with one of the edges (integer coordinates)
    "4.5 1 4.5 -3 4.5 5 10 -1"                    # Point coincides with one of the edges (floating-point coordinates)
    "5 5 0 0 4 0 2 4"                             # Point lies on the extension of one of the edges (integer coordinates)
    "6.5 8 0 0 4 0 2 4"                           # Point lies on the extension of one of the edges (floating-point coordinates)
    "5 1 0 0 4 0 2 4"                             # Point lies on the same line as the edges but outside the triangle (integer coordinates)
    "6.5 1.5 0 0 4 0 2 4"                         # Point lies on the same line as the edges but outside the triangle (floating-point coordinates)
    "2.345 3.678 1.23 4.56 7.89 9.01 2.34 5.67"   # Custom test case with floating-point coordinates
)

expected_outputs=(
    "Error: invalid number of arguments."
    "Error: invalid number of arguments."
    "Error: invalid argument."
    "The point is inside the triangle."
    "The point is outside the triangle."
    "The point is inside the triangle."
    "The point is outside the triangle."
    "The point is outside the triangle."
    "The point is outside the triangle."
    "The point is outside the triangle."
    "The point is outside the triangle."
    "The point is outside the triangle."
    "The point is outside the triangle."
    "The point is outside the triangle."
    "The point is outside the triangle."
    "The point is outside the triangle."
)

for i in "${!test_cases[@]}"; do
    printf -v test_case_number "%02d" $((i+1))
    echo -n "Test Case $test_case_number: "
    output=$(./BSP ${test_cases[i]})
    if [[ "$output" == "${expected_outputs[i]}" ]]; then
        echo -e "\e[32mPASSED\e[0m"   # Print PASSED in green
    else
        echo -e "\e[31mFAILED\e[0m"   # Print FAILED in red
    fi
done