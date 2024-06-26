#!/usr/bin/python3

## Task: 2.0
### DOXYGEN Task

import re
import csv

def extract_functions(header_file):
    with open(header_file, 'r') as file:
        content = file.read()

    # Regular expression to match Doxygen comments
    comment_pattern = re.compile(r'/\*\*.*?\*/', re.DOTALL)
    comments = comment_pattern.findall(content)

    # Regular expression to match function signatures with return type
    function_pattern = re.compile(r'([a-zA-Z_][a-zA-Z0-9_]*\s+)+([a-zA-Z_][a-zA-Z0-9_]*)\s*\((.*?)\)\s*;')
    functions = function_pattern.findall(content)

    return comments, functions

def parse_functions(functions):
    function_list = []
    for func in functions:
        return_type = " ".join(func[0].split()) # Join split parts of the return type
        function_name = func[1]
        arguments = func[2]
        function_list.append((return_type, function_name, arguments))
    return function_list

def save_to_csv(function_list, csv_file):
    with open(csv_file, 'w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(['Return Type', 'Function Name', 'Arguments'])
        writer.writerows(function_list)

if __name__ == "__main__":
    header_file = 'DIO.h'  # Replace with your header file
    csv_file = 'extracted_functions.csv' # Output CSV file

    comments, functions = extract_functions(header_file)
    function_list = parse_functions(functions)
    save_to_csv(function_list, csv_file)

    print(f'Extracted {len(function_list)} functions and saved to {csv_file}')
##########################################################