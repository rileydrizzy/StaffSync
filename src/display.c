/**  @file display.c
        @brief This file contains the functions to display the data of the
   employees.
        @author Ladipo Ezekiel Ipadeola
        @date 2/9/2026
        @version 1.0
*/

#include "display.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cdk/cdk.h>

static void show_info(CDKSCREEN *screen, const char *title, const char *msg)
{
    char *mesg[6];
    char titleLine[256];

    snprintf(titleLine, sizeof(titleLine), "<C></B>%s", title);
    mesg[0] = titleLine;
    mesg[1] = " ";
    mesg[2] = (char *)msg;
    mesg[3] = " ";
    mesg[4] = "<C>Press any key to continue...";
    mesg[5] = 0;

    CDKDIALOG *d =
        newCDKDialog(screen, CENTER, CENTER, mesg, 5, (char *[]){"<C>OK"}, 1,
                     A_REVERSE, TRUE, TRUE, FALSE);
    activateCDKDialog(d, 0);
    destroyCDKDialog(d);
    refreshCDKScreen(screen);
}

/* Register Staff UI: collects inputs but DOES NOT save anything. */
static void ui_register_staff(CDKSCREEN *screen)
{

    eraseCDKScreen(screen);
    CDKENTRY *idEntry = 0;
    CDKENTRY *nameEntry = 0;
    CDKENTRY *deptEntry = 0;

    const char *id = 0;
    const char *name = 0;
    const char *dept = 0;

    /* Title */
    show_info(screen, "Register Staff", "UI only. Inputs will NOT be saved.");
    screen = eraseCDKScreen(screen);

    idEntry = newCDKEntry(screen, CENTER, 6, "<B>Staff ID: ", " ", A_NORMAL, '.',
                          vMIXED, 1, 64, 128, TRUE, FALSE);

    nameEntry = newCDKEntry(screen, CENTER, 8, "<B>Full Name: ", " ", A_NORMAL,
                            '.', vMIXED, 1, 64, 128, TRUE, FALSE);

    deptEntry = newCDKEntry(screen, CENTER, 10, "<B>Department: ", " ", A_NORMAL,
                            '.', vMIXED, 1, 64, 128, TRUE, FALSE);

    refreshCDKScreen(screen);

    id = activateCDKEntry(idEntry, 0);
    if (idEntry->exitType == vESCAPE_HIT)
        goto cleanup;

    name = activateCDKEntry(nameEntry, 0);
    if (nameEntry->exitType == vESCAPE_HIT)
        goto cleanup;

    dept = activateCDKEntry(deptEntry, 0);
    if (deptEntry->exitType == vESCAPE_HIT)
        goto cleanup;

    /* NO persistence/logic — just confirm inputs captured by UI */
    {
        char msg[512];
        snprintf(msg, sizeof(msg),
                 "Captured (not saved):\n"
                 " - Staff ID: %s\n"
                 " - Name: %s\n"
                 " - Dept: %s",
                 (id && *id) ? id : "(empty)", (name && *name) ? name : "(empty)",
                 (dept && *dept) ? dept : "(empty)");
        show_info(screen, "Register Staff (UI Only)", msg);
    }

cleanup:
    if (idEntry)
        destroyCDKEntry(idEntry);
    if (nameEntry)
        destroyCDKEntry(nameEntry);
    if (deptEntry)
        destroyCDKEntry(deptEntry);
    refreshCDKScreen(screen);
}

/* View All Staff UI: shows placeholder list (NO retrieval). */
static void ui_view_all_staff(CDKSCREEN *screen)
{
    show_info(
        screen, "View All Staff",
        "UI only.\nNo data source connected.\n(Implement listing logic later.)");
}

/* Search Staff UI: gets a search term but DOES NOT search. */
static void ui_search_staff(CDKSCREEN *screen)
{
    CDKENTRY *qEntry = 0;
    const char *q = 0;

    show_info(screen, "Search Staff", "UI only. Search will NOT run.");

    qEntry = newCDKEntry(screen, CENTER, 8, "<B>Search term (name/id): ", " ",
                         A_NORMAL, '.', vMIXED, 0, 80, 256, TRUE, FALSE);

    refreshCDKScreen(screen);
    q = activateCDKEntry(qEntry, 0);

    if (qEntry->exitType != vESCAPE_HIT)
    {
        char msg[256];
        snprintf(msg, sizeof(msg),
                 "You entered: %s\n\n(UI only — no search performed.)",
                 (q && *q) ? q : "(empty)");
        show_info(screen, "Search Staff (UI Only)", msg);
    }

    if (qEntry)
        destroyCDKEntry(qEntry);
    refreshCDKScreen(screen);
}
