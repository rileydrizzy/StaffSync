#include <cdk.h>
#include "display.h"

/* ---------- Main Menu ---------- */

int main(void)
{
  CDKSCREEN *cdkScreen = 0;
  CDKSCROLL *menu = 0;

  /* Init curses + CDK */
  WINDOW *cursesWin = initscr();
  noecho();
  cbreak();
  keypad(cursesWin, TRUE);

  cdkScreen = initCDKScreen(cursesWin);
  initCDKColor();

  const char *items[] = {"<C><B>Register Staff", "<C><B>View All Staff",
                         "<C><B>Search Staff", "<C><B>Exit"};

  menu = newCDKScroll(cdkScreen, CENTER, CENTER, RIGHT, 15, 80,
                      "<C></B>Staff Management (CDK UI)", (CDK_CSTRING2)items,
                      4, TRUE, A_REVERSE, TRUE, FALSE);

  if (menu == 0)
  {
    endCDK();
    return 1;
  }

  for (;;)
  {
    int choice = activateCDKScroll(menu, 0);

    /* If user hit ESC, treat as Exit */
    if (menu->exitType == vESCAPE_HIT)
      break;

    switch (choice)
    {
    case 0:
      //ui_register_staff(cdkScreen);
      break;
    case 1:
      //ui_view_all_staff(cdkScreen);
      break;
    case 2:
      //ui_search_staff(cdkScreen);
      break;
    case 3: /* Exit */
      goto done;
    default:
      break;
    }

    /* Redraw menu after each screen */
    drawCDKScroll(menu, TRUE);
    refreshCDKScreen(cdkScreen);
  }

done:
  destroyCDKScroll(menu);
  endCDK(); /* cleans up screen + curses */
  return 0;
}
