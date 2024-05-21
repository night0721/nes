#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <libnotify/notify.h>

#include "nes.h"

void send_notification(char *content)
{
    NotifyNotification *notification = notify_notification_new("nes", content, "dialog-information");
    if (notification == NULL) {
        fprintf(stderr, "nes: Cannot create notification\n");
    }
    if (!notify_notification_show(notification, NULL)) {
        fprintf(stderr, "nes: Cannot show notification\n");
    }
    g_object_unref(G_OBJECT(notification));
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Neo Event Scheduler %s\n\nUsage: nes COMMAND\n\n", VERSION);
        printf("list\t\tList all oncoming events\n");
        printf("sched\t\tSchedule an event\n");
        printf("run\t\tRun an event\n");
        printf("edit\t\tEdit an event\n");
        printf("search\t\t Search for an event\n");
        exit(EXIT_FAILURE);
    }
    if (strncmp(argv[1], "list", 4) == 0) {
        /* accept argv[2] as timerange */

    } else if (strncmp(argv[1], "run", 3) == 0) {

    } else if (strncmp(argv[1], "sched", 4) == 0) {

    } else if (strncmp(argv[1], "edit", 4) == 0) {
        /* using $EDITOR */
    } else if (strncmp(argv[1], "search", 6) == 0) {

    }
    return EXIT_FAILURE;
}
