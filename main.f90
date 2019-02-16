module utils
    contains
        subroutine test(a)
            implicit none
            real :: a
            print *, a
        end subroutine test
end module utils

module ui
    use, intrinsic :: iso_c_binding, only: c_null_char
    use :: ncurses

    integer, parameter :: WIDTH = 180
    integer, parameter :: HEIGHT = 50

    integer, parameter :: BOTTOM_PANEL_HEIGHT = 15
    integer, parameter :: RIGHT_PANEL_WIDTH = 30

    contains
        subroutine drawUi()
            e = move(0, 0)
            e = vline(int(ichar('*'), 8), HEIGHT)
            e = hline(int(ichar('*'), 8), WIDTH)

            e = move(0, 5)
            e = addstr("CHAD'S WORLD V 0.1" // c_null_char)

            e = move(height, 0)
            e = hline(int(ichar('*'), 8), WIDTH)

            e = move(0, width)
            e = vline(int(ichar('*'), 8), HEIGHT)

            e = move(HEIGHT - BOTTOM_PANEL_HEIGHT, 1)
            e = hline(int(ichar('-'), 8), WIDTH - 2)
            e = move(HEIGHT - BOTTOM_PANEL_HEIGHT + 2, 2)
            e = addstr('SOME DESCRIPTION HERE' // c_null_char)

            e = move(1, WIDTH - RIGHT_PANEL_WIDTH - 2)
            e = vline(int(ichar('|'), 8), HEIGHT - BOTTOM_PANEL_HEIGHT)

            e = move(2, WIDTH - RIGHT_PANEL_WIDTH + 2)
            e = addstr('STATUS' // c_null_char)

        end subroutine drawUi
end module ui

program gamejam
    use, intrinsic :: iso_c_binding, only: c_null_char
    use :: ncurses
    use ui
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
end program gamejam
