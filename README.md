<p align="center">
  <img src="https://github.com/pibouill/42-project-badges/blob/main/badges/get_next_linem.png" alt="ready to help"/>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/pibouill/get_next_line">
</p>

# get_next_line
>This project is about programming a function that returns a line
read from a file descriptor.

```
char *get_next_line(int fd);
```

External functions allowed:
- read
- malloc

Repeated calls of the function allows us to read the entirety of a file.

get_next_line returns the line that was read or NULL if an error occurred.

### Bonus part
>Your get_next_line() can manage multiple file descriptors at the same time.
For example, if you can read from the file descriptors 3, 4 and 5, you should be
able to read from a different fd per call without losing the reading thread of each
file descriptor or returning a line from another fd.
It means that you should be able to call get_next_line() to read from fd 3, then
fd 4, then 5, then once again 3, once again 4, and so forth.
