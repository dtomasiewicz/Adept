#include "hash.h"
#include "lookup3.h"
#include <stdint.h>
#include <string.h>

int hashString(const char *str) {
	return (int) hashlittle(str, strlen(str), (uint32_t) 42);
}
