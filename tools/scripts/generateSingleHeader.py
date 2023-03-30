#!/usr/bin/env python3

'''
    This file is part of Bliss.

    MIT License

    Copyright (c) 2023 Kara Wilson

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
'''
import re
import os
import subprocess

from scriptCommon import Globals

header_file_types = [".h", ".hpp"]

#root_path = os.path.join(projPath, 'Bliss')

# pp tokens regexp
r_escape_line = re.compile(r'^.*\\\n$')
r_empty_line = re.compile('^[ \t]*\n$')
r_pp_include = re.compile('^\s*#\s*include\s+["|<](.*)["|>]$')
r_pp_ifndef = re.compile('^\s*#\s*ifndef\s+(.*)\s*$')
r_pp_if_defined = re.compile('^\s*#\s*if\s+defined\(\s*(.*)\s*\)\s*$')
r_pp_if = re.compile('^\s*#\s*if.*$')
r_pp_endif = re.compile('^\s*#\s*endif.*$')
r_pp_define = re.compile('^\s*#\s*define\s+(.*)\s*$')
r_pp_pragma_once = re.compile('^\s*#\s*pragma\s+once\s*$')
r_C_one_line_comment = re.compile('^(.*?)\s*//.*$')
r_C_one_line_block_comment = re.compile('^(.*)/\*.*\*/(.*)$')
r_C_block_begin_comment = re.compile('(.*)/\*.*')
r_C_block_end_comment = re.compile('.*\*/(.*)')

zero_or_something_rx = re.compile(r'\b0 \|\| ')
one_and_something_rx = re.compile(r'\b1 && ')

alone_in_parentheses_rx = re.compile(r'\((?P<inside>0|1|!?defined\((?P<name>[^)]+)\))\)')
zero_and_something_rx = re.compile(r'\b0 && (0|1|!?defined\([^)]+\)|!?\()')
something_and_zero_rx = re.compile(r'(0|1|!?defined\([^)]+\)|\)) && 0')
one_or_something_rx = re.compile(r'\b1 \|\| (0|1|!?defined\([^)]+\)|!?\()')
something_or_one_rx = re.compile(r'(0|1|!?defined\([^)]+\)|\)) \|\| 1')
alone_defined_rx = re.compile(r'^(?P<not>!)?defined\((?P<name>[^)]+)\)$')

include_parser = re.compile(r'\s*#include "(.*)".*')
pragma_once = re.compile('^#pragma once$')
ifndef_re = re.compile("#ifndef ([a-zA-Z0-9_]*)")

# globals
will_escape = False
guard_stack = []
included_files = []
keep_guard = True
in_C_block_comments = False

# Copyright lines
copyright_lines = [
    '// MIT License',

    '// Copyright (c) 2023 Kara Wilson',

    '// Permission is hereby granted, free of charge, to any person obtaining a copy',
    '// of this software and associated documentation files (the "Software"), to deal',
    '// in the Software without restriction, including without limitation the rights',
    '// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell',
    '// copies of the Software, and to permit persons to whom the Software is',
    '// furnished to do so, subject to the following conditions:',

    '// The above copyright notice and this permission notice shall be included in all',
    '// copies or substantial portions of the Software.',

    '// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR',
    '// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,',
    '// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE',
    '// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER',
    '// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,',
    '// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE',
    '// SOFTWARE.'
]

file_header = '''\
// This file is generated. I would advise against editing this directly.

// Generated: {generation_time}

'''

#parser.add_argument("-V", "--version", "Set file version")



headers = []

def HeaderAmalgamate():
    # Argument variables (not necessary)
    source_dir = ""
    starting_file = ""

    scripts_dir = "tools/scripts"

    output_dir = os.path.join(Globals.root_dir, "include")
    output_file = "Bliss.h"
    recursive = True

    acme_header_filename = "Bliss.h"
    path_to_acme_header = os.path.join(os.path.join(Globals.root_dir, "Bliss/src"), acme_header_filename)
    #with open(os.path.join(scripts_dir, "acme.py")) as acme:
        #exec(acme.read())
    #subprocess.run(".{} {} -o {}".format(os.path.join(scripts_dir, "acme.py"), path_to_acme_header, os.path.join(output_dir, output_file)))
    os.system("./{} {} -o {}".format(os.path.join(scripts_dir, "acme.py"), path_to_acme_header, os.path.join(output_dir, output_file)))

if __name__ == '__main__':
    HeaderAmalgamate()