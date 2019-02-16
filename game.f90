module game
    use, intrinsic :: iso_c_binding, only: c_null_char
    use :: ncurses
    use ui

    contains
        subroutine runGame()
            implicit none
            integer :: e, k

            integer :: x, y

            stdscr = initscr()
            e = curs_set(0)
            e = start_color()

            e = keypad(stdscr, TRUE)

            x = 10
            y = 10

            do
                e = init_pair(1 _c_short, COLOR_GREEN, COLOR_BLACK)
                e = move(y, x)
                e = attron(COLOR_PAIR(1))
                e = addstr('@@@' // c_null_char)
                call drawUi
                e = attroff(COLOR_PAIR(1))

                e = refresh()

                k = getch()

                if (k == KEY_LEFT) then
                    x = x - 1
                end if

                if (k == KEY_RIGHT) then
                    x = x + 1
                end if

                if (k == KEY_UP) then
                    y = y - 1
                end if

                if (k == KEY_DOWN) then
                    y = y + 1
                end if

                if (k == KEY_BACKSPACE) then
                    exit
                end if
            end do
            e = endwin()
        end subroutine runGame
end module game
