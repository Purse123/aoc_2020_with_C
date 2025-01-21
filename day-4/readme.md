```c 
// Remove trailing newline
line[strcspn(line, "\n")] = '\0';
```
- strcspn() scans the string for the first occurrence of any character in the second argument and returns the index of the first occurrence of the character
