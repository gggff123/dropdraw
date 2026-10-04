#include <ncurses/ncurses.h>
int main(){
    // Main
    initscr();
    clear();
    noecho();
    start_color();
    // -------------- Color pairs ---------------------
    init_pair(1,COLOR_WHITE,COLOR_BLUE); // Blue
    init_pair(2,COLOR_WHITE,COLOR_RED); // Red
    init_pair(3,COLOR_BLACK,COLOR_WHITE); // White
    init_pair(4,COLOR_WHITE,COLOR_GREEN); // Green
    init_pair(5,COLOR_BLACK,COLOR_CYAN); // Cyan
    init_pair(6,COLOR_WHITE,COLOR_MAGENTA); // Magenta
    init_pair(7,COLOR_BLACK,COLOR_YELLOW); // Yellow
    init_pair(8,COLOR_WHITE,COLOR_BLACK); // Black
    keypad(stdscr,TRUE);
    curs_set(0);
    box(stdscr,1,1);
    // ------------ Variables --------------------
    int y = 10;
    int x = 10;
    int ch;
    int color = 1;
    WINDOW *menu = newwin(19, 50, 4, 8);

    keypad(menu, TRUE);

    int in_menu = 1;

    while (in_menu) {
        werase(menu);

        // Color the entire menu window
        wbkgd(menu, COLOR_PAIR(1));

        wattron(menu, COLOR_PAIR(1));

        box(menu, 0, 0);

        mvwprintw(menu, 2, 14, "Welcome to Dropdraw");

        mvwprintw(menu, 4, 4, "--> Press [r] to draw in RED");
        mvwprintw(menu, 5, 4, "--> Press [b] to draw in BLUE");
        mvwprintw(menu, 6, 4, "--> Press [g] to draw in GREEN");
        mvwprintw(menu, 7, 4, "--> Press [y] to draw in YELLOW");
        mvwprintw(menu, 8, 4, "--> Press [c] to draw in CYAN");
        mvwprintw(menu, 9, 4, "--> Press [m] to draw in MAGENTA");
        mvwprintw(menu, 10, 4, "--> Press [w] to draw in WHITE");
        mvwprintw(menu, 11, 4, "--> Press [k] to draw in BLACK");
        mvwprintw(menu, 12, 4, "--> Press [v] to clear the screen");
        mvwprintw(menu, 16, 4, "[ENTER] Start    [q] Quit");

        wattroff(menu, COLOR_PAIR(1));

        wrefresh(menu);

        ch = wgetch(menu);

        if (ch == '\n' || ch == KEY_ENTER) {
            in_menu = 0;
        }

        if (ch == 'q') {
            delwin(menu);
            endwin();
            return 0;
        }
    }

    delwin(menu);

    clear();
    box(stdscr,1,1);
    refresh();
    // Functionality 
    attron(COLOR_PAIR(1));
    mvaddch(y,x,'#');
    attroff(COLOR_PAIR(1));
    refresh();
    while ((ch = getch())!='q'){
        if (ch=='b'){
            color=1;
        }
        if (ch=='r'){
            color=2;
        }
        if (ch=='w'){
            color=3;
        }
        if (ch=='g'){
            color=4;
        }
        if (ch=='c'){
            color=5;
        }
        if (ch=='m'){
            color=6;
        }
        if (ch=='y'){
            color=7;
        }
        if (ch=='k'){
            color=8;
        }
        if (ch=='v'){
            clear();
            box(stdscr,1,1);
        }
        attron(COLOR_PAIR(color));
        mvaddch(y,x,' ');
        attroff(COLOR_PAIR(color));
        switch (ch)
        {
        case KEY_UP:
        if (y > 1)
            y--;
        break;

        case KEY_DOWN:
        if (y < LINES - 2)
            y++;
        break;

        case KEY_LEFT:
        if (x > 1)
             x--;
        break;

        case KEY_RIGHT:
        if (x < COLS - 2)
                x++;
        break;
        }
        attron(COLOR_PAIR(color));
        mvaddch(y,x,'#');
        attroff(COLOR_PAIR(color));
        refresh();
    }
    // ---------------- Exit -------------------
    endwin();
    return 0;
}