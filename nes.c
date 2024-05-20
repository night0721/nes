#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <libnotify/notify.h>

#include "config.h"

void send_notification(char *content)
{
    NotifyNotification *notification = notify_notification_new("nes", content, "dialog-information");
    if (notification == NULL) {
        error(0, "Cannot create notification");
    }
    if (!notify_notification_show(notification, NULL)) {
        error(0, "Cannot show notifcation");
    }
    g_object_unref(G_OBJECT(notification));
}

int main(int argc, char **argv)
{
    printf("Usage: nes\n");
    return 0;
}
