
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

static void
usage(const char *s)
{
    fprintf(stderr, "usage: %s pid resource cur max\n", s);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    pid_t pid;
    struct rlimit64 rl;
    int resource;
    int rc;
    if (argc != 5)
        usage(*argv);
    if (sscanf(argv[1], "%d", &pid) != 1)
        usage(*argv);
    if (sscanf(argv[2], "%d", &resource) != 1)
        usage(*argv);
    if (sscanf(argv[3], "%llu", &rl.rlim_cur) != 1)
        usage(*argv);
    if (sscanf(argv[4], "%llu", &rl.rlim_max) != 1)
        usage(*argv);
    printf("setting resource %d of pid %d to [%llu,%llu]\n", resource, pid,
            rl.rlim_cur, rl.rlim_max);
            
    rc = prlimit64(pid, RLIMIT_CORE, &rl, NULL);
//    rc = prlimit64(pid, resource, &rl, NULL);
    if (rc < 0) {
        perror("prlimit");
        exit(EXIT_FAILURE);
    }
    return 0;
}
