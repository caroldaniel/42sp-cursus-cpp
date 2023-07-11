#!/bin/bash

./Fixed > test_output.log
# Compare the test output with the provided logs using diff
diff test_output.log expected_output.txt

# Check the exit code of diff
if [ $? -eq 0 ]; then
	echo -e "\e[32mPASSED\e[0m"   # Print PASSED in green
else
	echo -e "\e[31mFAILED\e[0m"   # Print FAILED in red
fi