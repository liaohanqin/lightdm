#include <stdlib.h>
#include <unistd.h>

#include "status.h"

static void
request_cb (const gchar *request)
{
}

int
main (int argc, char **argv)
{
    gchar *display;

    status_connect (request_cb);

    display = getenv ("DISPLAY");
    if (display == NULL)
        status_notify ("GUEST-WRAPPER-? START");
    else if (display[0] == ':')
        status_notify ("GUEST-WRAPPER-X-%s START", display + 1);
    else
        status_notify ("GUEST-WRAPPER-X-%s START", display);

    execv (argv[1], argv + 1);

    return EXIT_FAILURE;
}
