# Creating a Simple Shell in C
### Explore the importance of a shell in a OS and learn how to create a simple shell using system call in C.
---
## Tech Stack: 
<p align="center">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=ubuntu,git,bash,c,vscode,vim, " />
  </a>
</p>

## Requirement:
- **Environment:** `Ubuntu 24.04 LTS`
- **GNU Compiler Collection:** `gcc`
- **Coding Style Checker:** [`betty`](https://github.com/hs-hq/Betty/tree/main)

## Compilation Command:
Using `Ubuntu 24.04 LTS` to compile the program using `gcc`, with the option `-Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`.

## Testing:
Your shell should work like this in interactive mode:
``` bash
user@ubuntu:/# ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
user@ubuntu:/#
```
But also in non-interactive mode:
``` bash
user@ubuntu:/# echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
user@ubuntu:/# cat test_ls_2
/bin/ls
/bin/ls
user@ubuntu:/# cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
user@ubuntu:/#
```

## Flowchart:

## Authors:

