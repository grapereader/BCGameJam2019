module states
    type, public :: GameStateObject
        integer currState
    end type GameStateObject

    contains
        function createGameState()
            real :: result

            result = 3
        end function createGameState

        subroutine runStateMachine(gameState)
            implicit none
            type(GameStateObject) :: gameState
        end subroutine runStateMachine
end module states

