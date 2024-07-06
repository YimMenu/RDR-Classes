#pragma once
#include "script/types.hpp"

enum class MPGameState
{
	INVALID = -1,
	GAME_INIT,
	LOAD_INIT_THREADS,
	LOAD_MAIN_THREADS,
	ROUTE_TRANSITION,
	CREATE_PLAYER_CAMP,
	VERIFY_MADAM_NAZAR,
	CHECK_FOR_INVITE,
	SPAWN_PLAYER,
	MAIN_UPDATE_FIRST_FRAME,
	MAIN_UPDATE,
	END,
	ALL_LEAVE
};

struct MP_HOST_DATA
{
	alignas(8) MPGameState GameState;
};
static_assert(sizeof(MP_HOST_DATA) == 1 * 8);