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

import os
import subprocess
import shutil

from time import sleep

from scriptCommon import Globals

def Build():
    command_queue = [    
                "cmake -B {}".format(Globals.build_folder) , 
                "cmake --build {}".format(Globals.build_folder)
                ]
    with open(os.path.join(Globals.root_dir, "tools/scripts/generateSingleHeader.py")) as genhead:
        exec(genhead.read())
    
    if os.path.exists(Globals.build_dir):
        shutil.rmtree(Globals.build_dir)
    
    for cmd in command_queue:
        subprocess.run(cmd, shell=True)
def Run():
    #print(os.path.join(Globals.build_dir, "samples/demo/DEMO"))

    if os.path.exists(os.path.join(Globals.build_dir, "samples/demo/DEMO")):
        subprocess.run("./build/samples/demo/DEMO")
    else:
        print("Executable does not exists I thinks. Exiting...\n")

    return

if __name__ == "__main__":
    print("Building...\n")
    Build()
    print("Build Finished!\n")
    sleep(0.25)
    print("Running...\n")
    Run()
    print(Globals.root_dir)