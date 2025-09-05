# minishell
In this project we reimplementated a small version of the classic UNIX shell. The main challenge was to parse userput and execute commands only using functions provided by POSIX UNIX labraries in C.
# ✨ Features
- supports common builtin comands cd, echo, env, export, unset, pwd and exit
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

# File structure


# How to install





