#!/usr/bin/env python3

import os
import subprocess

PROJECT = "CG_MCE"

DESCRIPTION = (
    "Cross-platform modular emulator framework for retro computers written in C."
)

README = f"""# {PROJECT}

## Overview

CG_MCE (Classic Game / Computer Modular Emulator)

A modular emulator framework written in C.

Current CPU:
- Z80

Goals:
- Accurate hardware emulation
- Modular architecture
- Easy addition of new CPUs
- Terminal debugger
- Retro computer research

## Status

Early development.

## Build

Coming soon.

## License

TBD
"""

GITIGNORE = """# Object files
*.o
*.obj

# Libraries
*.a
*.so
*.dll

# Executables
*.exe
*.out

# Build
build/
bin/

# Editors
.vscode/
.idea/

# Python
__pycache__/
*.pyc
"""

DIRECTORIES = [
    "docs",
    "tests",
    "tools",
    "include",
    "src"
]


def run(cmd):
    print(">", " ".join(cmd))
    subprocess.run(cmd)


print("Preparing repository...")

for d in DIRECTORIES:
    os.makedirs(d, exist_ok=True)

if not os.path.exists("README.md"):
    with open("README.md", "w") as f:
        f.write(README)

if not os.path.exists(".gitignore"):
    with open(".gitignore", "w") as f:
        f.write(GITIGNORE)

run(["git", "add", "."])

run(["git", "commit", "-m", "Repository initialization"])

run([
    "gh",
    "repo",
    "edit",
    "--description",
    DESCRIPTION
])

run(["git", "push"])

print()
