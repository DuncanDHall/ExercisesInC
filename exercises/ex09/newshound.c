/* Example from Head First C.

Downloaded from https://github.com/twcamper/head-first-c

Modified by Allen Downey.
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>


void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

void child_code(int i, char *search_phrase, char *feed)
{
    const char *PYTHON = "/usr/local/bin/python";
    const char *SCRIPT = "rssgossip.py";
    char var[255];

    sprintf(var, "RSS_FEED=%s", feed);
    char *vars[] = {var, NULL};

    int res = execle(PYTHON, PYTHON, SCRIPT, search_phrase, NULL, vars);
    if (res == -1) {
        error("Can't run script.");
    }
    printf("got here\n");
    exit(0);
}

int main(int argc, char *argv[])
{
    pid_t pid;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <search phrase>\n", argv[0]);
        return 1;
    }
    char *feeds[] = {
        "http://www.nytimes.com/services/xml/rss/nyt/Africa.xml",
        "http://www.nytimes.com/services/xml/rss/nyt/Americas.xml",
        "http://www.nytimes.com/services/xml/rss/nyt/MiddleEast.xml",
        "http://www.nytimes.com/services/xml/rss/nyt/Europe.xml",
        "http://www.nytimes.com/services/xml/rss/nyt/AsiaPacific.xml"
    };
    int num_feeds = 5;
    char *search_phrase = argv[1];

    for (int i=0; i<num_feeds; i++) {
        pid = fork();
        if (pid == -1) {
            fprintf(stderr, "fork failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }
        if (pid == 0) {
            child_code(i, search_phrase, feeds[i]);
            exit(i);
        }
    }
    exit(0);
//    return 0;
}
