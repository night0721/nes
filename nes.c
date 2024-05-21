#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/inotify.h>

#include <libnotify/notify.h>

#include "nes.h"

static void
send_notification(char *content)
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

static _Noreturn
usage(int code)
{
	fprintf(code ? stderr : stdout,
		"Neo Event Scheduler %s\n\n"
		"Usage: nes <command>\n\n"
		"	sched <time> <title> [details]	Schedule an event\n"
		"	edit				Edit schedule with $EDITOR\n"
		"	list <timerange>		List all upcoming events\n"
		"	search				Search for events\n"
		"	run				Spawn notifier daemon\n"
		, VERSION);
	exit(code);
}

int
main(int argc, char **argv)
{
	if (argc < 2) {
		usage(1);
	}
	FILE *db = fopen(DATABASE_PATH, "r");
	if (strcmp(argv[1], "sched") == 0) {
		/* time can be relative or absolute */
	} else if (strcmp(argv[1], "edit") == 0) {
		/* spawn $EDITOR */
	} else if (strcmp(argv[1], "list") == 0) {
		/* accept argv[2] as timerange */
	} else if (strcmp(argv[1], "search") == 0) {

	} else if (strcmp(argv[1], "run") == 0) {

	}
	return EXIT_FAILURE;
}
