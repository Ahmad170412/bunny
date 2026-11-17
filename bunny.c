/* bunny.c - deliberately vulnerable demo program.
 *
 * Prints a greeting for a name supplied on the command line.
 * Do not deploy this: the first version copies the argument into a fixed
 * stack buffer with no length check.
 */
#include <stdio.h>
#include <string.h>

static void greet(const char *name)
{
    char buf[16];

    strcpy(buf, name);
    printf("Hello, %s!\n", buf);
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "usage: %s <name>\n", argv[0]);
        return 2;
    }

    greet(argv[1]);
    return 0;
}
