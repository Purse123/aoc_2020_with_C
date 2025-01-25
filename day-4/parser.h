#ifndef PARSER_H
#define PARSER_H

#include "validation.h"
#include <stdbool.h>

HEIGHT parse_height(char *height_str);
bool PASSPORT_PARSER(char *passport_str, PASSPORT *passport);

#endif
