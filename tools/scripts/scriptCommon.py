import os
import sys

# Set directory to script dir (Prevents issues if executed from a different location)
os.chdir(os.path.dirname(os.path.abspath(__file__)))
# Get Project Directory (Just goes back)
os.chdir('../../')

class Globals:
    build_folder = "build"

    root_dir = os.getcwd()
    build_dir = os.path.join(root_dir, build_folder)