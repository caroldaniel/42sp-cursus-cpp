#!/bin/bash

# Colors
RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
PURPLE="\033[0;35m"
CYAN="\033[0;36m"

# Bold Colors
BOLD_RED="\033[1;31m"
BOLD_GREEN="\033[1;32m"
BOLD_YELLOW="\033[1;33m"
BOLD_BLUE="\033[1;34m"
BOLD_PURPLE="\033[1;35m"
BOLD_CYAN="\033[1;36m"

# Reset
NC="\033[0m"

echo
echo -e "${BOLD_CYAN}===================== TESTS =====================${NC}"

echo 
echo -e "${BOLD_PURPLE}No argument test------------------------------------${NC}"

# Test with no argument
echo "./ScalarConverter"
./ScalarConverter

echo
echo
echo -e "${BOLD_RED}Invalid inputs tests--------------------------------${NC}"

# Test with invalid inputs
echo "./ScalarConverter 🌊"
./ScalarConverter 🌊 
echo "./ScalarConverter 🌊🌊"
./ScalarConverter 🌊🌊
echo "./ScalarConverter teste"
./ScalarConverter teste
echo "./ScalarConverter \"teste\""
./ScalarConverter "teste"
echo "./ScalarConverter 'teste'"
./ScalarConverter 'teste'
echo "./ScalarConverter 0000r"
./ScalarConverter 0000r
echo "./ScalarConverter 9f"
./ScalarConverter 9f
echo "./ScalarConverter 99f"
./ScalarConverter 99f
echo "./ScalarConverter '\\n'"
./ScalarConverter "'\n'"
echo "./ScalarConverter '\\t'"
./ScalarConverter "'\t'"
echo "./ScalarConverter '\\r'"
./ScalarConverter "'\r'"
echo "./ScalarConverter '\\v'"
./ScalarConverter "'\v'"
echo "./ScalarConverter '\\b'"
./ScalarConverter "'\b'"
echo "./ScalarConverter '\\f'"
./ScalarConverter "'\f'"
echo "./ScalarConverter '\\a'"
./ScalarConverter "'\a'"
echo "./ScalarConverter '\\e'"
./ScalarConverter "'\e'"
echo "./ScalarConverter '\\0'"
./ScalarConverter "'\0'"
echo "./ScalarConverter '\\x0'"
./ScalarConverter "'\x0'"
echo "./ScalarConverter '\\x0f'"
./ScalarConverter "'\x0f'"
echo "./ScalarConverter ' '"
./ScalarConverter "' '"
echo "./ScalarConverter '	'"
./ScalarConverter "'	'"


echo
echo
echo -e "${BOLD_YELLOW}Limits tests----------------------------------------${NC}"

# Test with limits
echo "./ScalarConverter 2147483647"
./ScalarConverter 2147483647
echo "./ScalarConverter -2147483648"
./ScalarConverter -2147483648
echo "./ScalarConverter 2147483648"
./ScalarConverter 2147483648
echo "./ScalarConverter -2147483649"
./ScalarConverter -2147483649
echo "./ScalarConverter 340282346638528859811704183484516925440.0f"
./ScalarConverter 340282346638528859811704183484516925440.0f
echo "./ScalarConverter -340282346638528859811704183484516925440.0000000000000000f"
./ScalarConverter -340282346638528859811704183484516925440.0000000000000000f
echo "./ScalarConverter 340282346638528859811704183484516925455.9f"
./ScalarConverter 340282446638528859811704183484516925455.9f
echo "./ScalarConverter -340282446638528859811704183484516925499.9900000000000000f"
./ScalarConverter -340282446638528859811704183484516925499.9900000000000000f
echo "./ScalarConverter 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0"
./ScalarConverter 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0
echo "./ScalarConverter -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0"
./ScalarConverter -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0
echo "./ScalarConverter 179769313486239570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858399.9"
./ScalarConverter 179769313486239570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858399.9
echo "./ScalarConverter -179769313486239570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858399.9"
./ScalarConverter -179769313486239570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858399.9

echo
echo
echo -e "${BOLD_BLUE}Char tests----------------------------------------${NC}"

# Test with char
echo "./ScalarConverter 'A'"
./ScalarConverter "'A'"
echo "./ScalarConverter 'l'"
./ScalarConverter "'l'"
echo "./ScalarConverter 'e'"
./ScalarConverter "'e'"
echo "./ScalarConverter 'x'"
./ScalarConverter "'x'"
echo "./ScalarConverter '/'"
./ScalarConverter "'/'"
echo "./ScalarConverter '?'"
./ScalarConverter "'?'"
echo "./ScalarConverter ':'"
./ScalarConverter "':'"
echo "./ScalarConverter '%'"
./ScalarConverter "'%'"
echo "./ScalarConverter '1'"
./ScalarConverter "'1'"

echo
echo
echo -e "${BOLD_YELLOW}Integer tests-------------------------------------${NC}"

# Test with integer
echo "./ScalarConverter 0"
./ScalarConverter 0
echo "./ScalarConverter 1"
./ScalarConverter 1
echo "./ScalarConverter -1"
./ScalarConverter -1
echo "./ScalarConverter 42"
./ScalarConverter 42
echo "./ScalarConverter 65"
./ScalarConverter 65
echo "./ScalarConverter 314"
./ScalarConverter 314

echo
echo
echo -e "${BOLD_GREEN}Float tests----------------------------------------${NC}"

# Test with float
echo "./ScalarConverter 0.0f"
./ScalarConverter 0.0f
echo "./ScalarConverter 1.1f"
./ScalarConverter 1.1f
echo "./ScalarConverter -1.1f"
./ScalarConverter -1.1f
echo "./ScalarConverter 42.42f"
./ScalarConverter 42.42f
echo "./ScalarConverter 65.56f"
./ScalarConverter 65.56f
echo "./ScalarConverter 3.14f"
./ScalarConverter 3.14f

echo
echo
echo -e "${BOLD_PURPLE}Double tests----------------------------------------${NC}"

# Test with double
echo "./ScalarConverter 0.0"
./ScalarConverter 0.0
echo "./ScalarConverter 1.1"
./ScalarConverter 1.1
echo "./ScalarConverter -1.1"
./ScalarConverter -1.1
echo "./ScalarConverter 42.42"
./ScalarConverter 42.42
echo "./ScalarConverter 65.56"
./ScalarConverter 65.56
echo "./ScalarConverter 3.14"
./ScalarConverter 3.14

echo
echo
echo -e "${BOLD_CYAN}Pseudo literal tests--------------------------------${NC}"

# Test with pseudo literal
echo "./ScalarConverter nan"
./ScalarConverter nan
echo "./ScalarConverter nanf"
./ScalarConverter nanf
echo "./ScalarConverter +inf"
./ScalarConverter +inf
echo "./ScalarConverter -inf"
./ScalarConverter -inf
echo "./ScalarConverter +inff"
./ScalarConverter +inff
echo "./ScalarConverter -inff"
./ScalarConverter -inff

echo
