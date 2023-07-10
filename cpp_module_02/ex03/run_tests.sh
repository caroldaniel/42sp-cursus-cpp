#!/bin/bash

# Test cases
test_cases=(
  "1 1 0 0 2 0 0 2"    # Point inside triangle
  "3 3 0 0 2 0 0 2"    # Point outside triangle
  "1 1 0 0 2 0 1 1"    # Point on triangle edge
  "0 0 0 0 2 0 0 2"    # Point coincides with triangle vertex
  "1 1 1 1 1 1 1 1"    # Degenerate triangle (points coincident)
)

# Expected outputs corresponding to test cases
expected_outputs=(
  "The point is inside the triangle."
  "The point is outside the triangle."
  "The point is inside the triangle."
  "The point is inside the triangle."
  "Error: invalid triangle."
)

# Iterate over test cases
for ((i=0; i<${#test_cases[@]}; i++)); do
  echo "Test Case $((i+1)): ${test_cases[i]}"

  # Execute BSP program with test case
  echo "./BSP ${test_cases[i]}"
  output=$(./BSP ${test_cases[i]})

  # Compare expected output with actual output
  if [ "$output" = "${expected_outputs[i]}" ]; then
    echo "Expected: ${expected_outputs[i]}"
    echo "Actual:   $output"
    echo "Result:   Pass"
  else
    echo "Expected: ${expected_outputs[i]}"
    echo "Actual:   $output"
    echo "Result:   Fail"
  fi

  echo
done