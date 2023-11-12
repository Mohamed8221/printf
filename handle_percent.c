#include <unistd.h>

/**
* handle_percent - Handles the '%' specifier.
* @count: The count of printed characters.
*/
void handle_percent(int *count)
{
write(1, "%", 1);
(*count)++;
}
