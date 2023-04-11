# 0x17. C - Simple Shell

simple_shell - a simple Unix command line interpreter

# SYNOPSIS

simple_shell

# DESCRIPTION

simple_shell is a basic Unix command line interpreter developed as part of the Holberton School curriculum. It provides a simple interface for executing commands on a Unix system, including support for arguments.

Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.

The only difference is when you print an error, the name of the program must be equivalent to your argv[0]

If an executable cannot be found, an error message is printed and the prompt is displayed again. The shell handles errors and the "end of file" condition (Ctrl+D).

# OPTIONS

Your shell should work like this in interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

But also in non-interactive mode:

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

# EXAMPLES

simple_shell
ls
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write) 

# AUTHORS

- Jessia Grimes

# SEE ALSO

- The POSIX shell command language specification: https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html
- The GNU Bash manual: https://www.gnu.org/software/bash/manual/
- The zsh manual: http://zsh.sourceforge.net/Doc/Release/
- The fish shell documentation: https://fishshell.com/docs/current/
- The tcsh manual: https://www.tcsh.org/
- The Korn shell manual: http://www.kornshell.com/doc/
- The ash manual: https://www.in-ulm.de/~mascheck/various/ash/
- The dash manual: https://manpages.debian.org/stretch/dash/dash.1.en.html

# BUGS

No known bugs.

# VERSION

This is version 1.0 of the simple_shell command line interpreter.

# COPYRIGHT
