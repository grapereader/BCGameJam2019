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

