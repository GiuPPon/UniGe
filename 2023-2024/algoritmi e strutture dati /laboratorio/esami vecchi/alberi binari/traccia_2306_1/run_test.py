#!/usr/bin/env python3

import argparse
from bisect import bisect_left
import difflib
import json
from math import isclose
from numbers import Number
import re
import subprocess
from typing import Optional, Sequence

MAX_STR_LEN = 50  # maximum length of shown strings

# https://www.regular-expressions.info/floatingpoint.html

number_re = re.compile(r'[-+]?[0-9]*\.?[0-9]+(?:[eE][-+]?[0-9]+)?')

# To execute as:
# run_test.py executablename test_file.json

# Parse arguments given within the execution of the program
# parameters will be saved in parser.parameter_var_name
# e.g. after these lines of code I will retrieve the first par by accessing
# parser.executable
# and the second par with parser.test_data
parser = argparse.ArgumentParser()
parser.add_argument('executable')
parser.add_argument('--test_data', default='test.json')
# If --verbose flag is passed, we set this parameter to True
parser.add_argument('--verbose', default=False, action='store_true')
args = parser.parse_args()


def show(s):
    """Returns repr(s) if it's shorter than MAX_STR_LEN or if args.verbose is True, otherwise chops it."""
    return repr(s) if args.verbose or len(s) <= MAX_STR_LEN else repr(s[:MAX_STR_LEN - 3] + '...')



# Load the json file, and transform its content to a Python object
with open(args.test_data) as f:
    cases = json.load(f)

# Takes a Sequence of numbers, a number x and return the closest number present in the seq to x
def closest(seq: Sequence[Number], x: Number) -> Number:  # https://stackoverflow.com/a/12141511
    """
    Assumes seq is sorted. Returns closest value to x.

    If two values are equally close, return the smallest number.
    """
    pos = bisect_left(seq, x)
    if pos == 0:
        return seq[0]
    if pos == len(seq):
        return seq[-1]
    before, after = seq[pos - 1], seq[pos]
    if after - x < x - before:
        return after
    else:
        return before


def test(spec) -> Optional[str]:
    """Runs a test according to the specification. Returns an error message or None if all is ok."""

    spec.setdefault('error', False)  # a test case where 'error' isn't specified should return no error
    
    try:
        input = spec['input'].encode()
    except KeyError:
        input = '\n'.join(str(x) for x in spec['numeric_input']).encode()
        
    # Run executable (name given in args), gives input specified, and capture the output
    # Save into stdout and stderr output, accordingly
    result = subprocess.run([args.executable, 'q'], input=input, capture_output=True)
    stdout, stderr = result.stdout.decode(), result.stderr.decode()

    # Assumption: in result.returncode we have the exit status code of subprocess.run
    # Considering the 'error' field in specs
    # error: {true|false}
    # check if error is returned when expected and viceversa
    def check_error(expected_error):
        if expected_error:
            if result.returncode == 0:
                return "should have returned an error"
        else:
            if result.returncode != 0:
                return "should not have returned an error"
    
    def diff(expected, obtained):
        return '\n'.join(difflib.unified_diff(expected.splitlines(), obtained.splitlines(),
                                              fromfile='expected', tofile='obtained', lineterm=''))

    # Considering the 'stdout' field in specs
    # stdout: "....."
    # check and return diff between expected stdout and actual stdout
    def check_stdout(expected_stdout):
        if stdout != expected_stdout:
            return f"differences in output\n{diff(expected_stdout, stdout)}"
    
    # Considering the 'stderr' field in specs
    # stderr: "....." 
    # check and return diff between expected stderr and actual stderr
    def check_stderr(expected_stderr):
        if stderr != expected_stderr:
            return f"differences in standard error\n{diff(expected_stderr, stderr)}"
    
    # Considering the 'in_stdout' field in specs
    # in_stdout: ["...", ..., "..."]
    # check if each substring given is present in the actual stdout
    def check_in_stdout(substrings):
        for substring in substrings:
            if substring not in stdout:
                return f'expected string {show(substring)} not in output'
                
    def check_in_stdout_ordered(substrings):
        tmp_stdout = str(stdout)
        for substring in substrings:
            if substring in tmp_stdout:
                tmp_stdout = tmp_stdout[tmp_stdout.index(substring)+len(substring):]
            else:
                return f'expected string {show(substring)} not in output in the expected order!'
    
    # Considering the 'close_values' field in specs
    # close_values: [0,1, ..., 1000]
    # close_values: [0.0, 1.0, ..., 1000.0]
    # check if each given value is present in the actual stdout
    # if not present, also closest values are checked and reported
    def check_close_values(close_values):
        values_in_output = sorted(float(v) for v in number_re.findall(stdout))
        if not values_in_output and close_values:
            return "numeric values expected in the output"
        for v in close_values:
            closest_value = closest(values_in_output, v)
            if not isclose(v, closest_value):
                return f"{v} expected in the output, closest value is {closest_value}"
    
    checks = [('error', check_error),
              ('stdout', check_stdout),
              ('stderr', check_stderr),
              ('in_stdout', check_in_stdout),
              ('in_stdout_ordered', check_in_stdout_ordered),
              ('close_values', check_close_values),
              ]

    for fieldname, checker in checks:
        try:
            spec_value = spec[fieldname]
        except KeyError:
            pass
        else:
            error = checker(spec_value)
            if error is not None:
                return error

# cases in json will be enumerated (from 0 to n), in var cases there will be the obj defined in json
for i, case in enumerate(cases):
    try:
        print(f'Test {i}: '+case['test_description'], end='\n', flush=True)
    except KeyError:
        print(f'Test {i}:', end='\n', flush=True)
    error = test(case)
    
    if error is None:
        print("\tOK ✅")
    else:
        print("\tFAIL ❌... What went wrong? ...\n\t"+error)
        #break
"""        
else:
    print("All tests OK! 🤓")
"""