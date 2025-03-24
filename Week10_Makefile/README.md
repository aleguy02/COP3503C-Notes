# Makefiles `make` your life easier

These demos were created to demonstrate some basic makefiles.
You probably won't make a more complicated makefile than the one in this demo for COP3503C.

## Example Makefiles
- _**intro_demo_makefile**_: commands depend on your operating system.
This makefile shows some examples of commands you would use in Linux vs. Windows.
- _**compiling_demo_makefile**_: ready for some command line compiling?
This makefile demonstrates how to build, execute, then clean up a simple C++ project.

## How to Makefile
1. Create a file called `Makefile` at the root directory. Make sure there's no file extensions, we don't want them.
2. Add your rules.
3. Call your rule from the terminal with `mingw32-make <rule name>` on Windows or `make <rule name>` on Linux.
Omitting a rule name will run whichever rule is first in your makefile (aka your default rule).