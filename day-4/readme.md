```c 
// Remove trailing newline
line[strcspn(line, "\n")] = '\0';
```
- strcspn() scans the string for the first occurrence of any character in the second argument and returns the index of the first occurrence of the character

## String to Integer
**atoi**
```c 
#include<stdlib.h>

int atoi(const char *nptr);
long atol(const char *nptr);
long long atoll(const char *nptr);
```
or **strol**
```c 
#include <stdlib.h>
long strtol(const char *restrict nptr, char **restrict endptr, int base);
long long strtoll(const char *restrict nptr, char **restrict endptr, int base);
```
***
## scanset 
```c 
sscanf(token, "%[^:]:%s", key, value);
// "%[^:]"         // scan until ':' is encountered
```
