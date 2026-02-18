# minishell
This project has been created as part
of the 42 curriculum by vpogorel and hmote.

# Description
In this project we reimplemented a small version of the classic UNIX shell. The main challenge was to parse user input and execute commands only using POSIX-compliant C library functions.

![Minishell demo video](https://github.com/WaPoco/minishell/blob/main/minishell-demo.gif)

### Features
- Working history (⬆️ and ⬇️)
- Search and launch the right executable (based on the PATH variable or using a
relative or an absolute path)
- Supports common builtin commands:

     - cd with only a relative or absolute path
     - echo with option of -n
     - env with no options or arguments
     - export with no options
     - unset with no options
     - pwd with no options
     - exit with no options
- Handles ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence
- Handles " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign)
- Pipes (| character). The output of each command in the pipeline is
connected to the input of the next command via a pipe.
- Environment variables ($ followed by a sequence of characters) which
should expand to their values.
- $? which should expand to the exit status of the most recently executed
foreground pipeline
- Handles ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.
- The code includes at most one global variable to indicate a received signal.
- Redirections similar to bash:
    - ```<``` redirects input
    - ```>``` redirects output
    - ```<<``` heredoc mode
    - ```>>``` append mode

For this project the libft library was used, which is a custom implementation of some standard C library functions. The functions implemented in libft are listed in the subject pdf file.
The rest of the features are described in the subject pdf file.
## Architecture:
The project is organized into several modules, each responsible for a specific aspect of the shell's functionality. The main modules include:
- **Initialization**: This module sets up the shell environment, including signal handling and terminal settings.
- **Parsing&Tokanizer**: This module is responsible for parsing user input, handling quotes, and expanding environment variables and extracting the commands into tokens.
- **Execution**: This module executes the parsed commands, handling built-in commands and external executables, as well as managing pipes and redirections as a process with excvp
-  from the library ... 
- **Utilities**: This module contains helper functions for string manipulation, error handling, and other common tasks.
![Minishell-Diagramm](https://github.com/WaPoco/minishell/blob/main/architecure.jpg)

# Instructions
Clone the repository:
```
git clone https://github.com/WaPoco/minishell minishell
```
Change to the minishell folder:
```
cd minishell
```
To compile the project, run:
```
make
```
To run the shell, execute:
```
./minishell
```
To clean up the compiled files, run:
```
make fclean
```

# Resources

- Minishell subject (https://github.com/WaPoco/minishell/blob/main/en.subject.pdf)
- AI was used to generate code snippets and to get suggestions on how to implement certain features. Furthermore I used AI to write some parts of the README file.
- Minishell tutorial (https://42-cursus.gitbook.io/guide/3-rank-03/minishell)














