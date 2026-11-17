/* bunny.c - deliberately vulnerable demo program (fixed).
 *
 * Prints a greeting for a name supplied on the command line. The name is
 * length-checked and copied with a bounded copy into a fixed stack buffer.
 */
#include <stdio.h>
#include <string.h>

#define NAME_MAX 16

static int greet(const char *name)
{
    char buf[NAME_MAX];

    if (strlen(name) >= sizeof(buf)) {
        fprintf(stderr, "name too long (max %zu bytes)\n", sizeof(buf) - 1);
        return 1;
    }

    snprintf(buf, sizeof(buf), "%s", name);
    printf("Hello, %s!\n", buf);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "usage: %s <name>\n", argv[0]);
        return 2;
    }

    return greet(argv[1]);
}
