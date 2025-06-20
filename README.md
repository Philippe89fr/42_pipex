## Pipex - 42

# Description:
Pipex is a project that recreates the functionality of UNIX pipes. The program takes two commands and two files as arguments, executing the commands in a pipeline where the output of the first command becomes the input of the second command. This mimics the shell behavior of < file1 cmd1 | cmd2 > file2. The project focuses on understanding and implementing inter-process communication through pipes, process creation with fork(), and program execution with execve(). 

The pipex program takes four arguments:

   - infile: the input file to be read and piped into the first command.
   - cmd1: the first command to be executed.
   - cmd2: the second command to be executed.
   - outfile: the output file where the result of the pipeline will be written.

The program executes the command pipeline cmd1 | cmd2 and redirects the input and output accordingly, similar to the behavior of the shell command | (pipe).

# Context:
Part of 42 Common Core.

# Main Technologies / Skills Used:

- **Programming Languages:** C
- **Variadic Functions:** Using va_start, va_arg, va_copy, va_end to handle variable arguments
- **Number Base Conversion:** Converting integers to decimal, hexadecimal (uppercase/lowercase)
- **Memory Management:** Dynamic allocation for string formatting and buffer management
- **Pointer Manipulation:** Handling void pointers and address formatting
- **String Processing:** Character and string output with proper formatting
- **Makefile Management:** For automating project compilation.
- **Error Handling:** Managing edge cases and invalid format specifiers

# Installation and compilation
1. Clone this repository into your project:
```bash
git clone git@github.com:Philippe89fr/42_printf.git
```
2. Run the following command:
```bash
make bonus
```
3. To use the pipex program, compile it using the provided Makefile. Then, run the program with the required arguments:
```bash
./pipex infile "cmd1" "cmd2" outfile
```
