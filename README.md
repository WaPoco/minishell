# minishell
In this project we reimplemented a small version of the classic UNIX shell. The main challenge was to parse user input and execute commands only using POSIX-compliant C library functions.

![Minishell](https://github.com/WaPoco/minishell/blob/main/minishell.png)

# ✨ Features
- Working histroy
- Search and launch the right executable (based on the PATH variable or using a
relative or an absolute path)
- 
- supports common builtin comands:
    cd, echo, env, export, unset, pwd and exit
- Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence
- executes exernal commands with execve
- handles single quotes ```'``` but not specialcharacters (<,<<, >, >>, |, ...) in a quoted sequence
- handles double quotes ```''``` but not specialcharacters (<,<<, >, >>, |, ...) except for the dollar sign ```$```
##### Redirections
- ```<``` redirects input
- ```>``` redirects output
- ```<<``` heredoc mode
- ```>>``` append mode 
- Pipes ```|``` to connect multiple comamnds
- environmental variables ```$USER```

- Minishell supports the built-in commands like cd, echo, env, export, unset and pwd. On top it supports the original unix signals like bash and executes external commands.
...
# 👥 Teamwork
This was a group project (2 people).
We had to work closely, divide responsibilities and integrate our work efficiently.

# File structure


# How to install









