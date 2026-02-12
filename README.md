# minishell
This project has been created as part
of the 42 curriculum by vpogorel and hmote.

# Description
In this project we reimplemented a small version of the classic UNIX shell. The main challenge was to parse user input and execute commands only using POSIX-compliant C library functions.

![Minishell](https://github.com/WaPoco/minishell/blob/main/minishell.png)

### ✨ Features
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
- Redirections similar to bash shell:
    - ```<``` redirects input
    - ```>``` redirects output
    - ```<<``` heredoc mode
    - ```>>``` append mode

Our own Libft Library was used in this project.
The rest of the features are described in the subject pdf file.

# Instructions

To compile the project, run:
```
bash make

```
To run the shell, execute:
```
bash ./minishell
```

# Rescources
- [Minishell subject]









