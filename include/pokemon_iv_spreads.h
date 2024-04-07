static const u8 IV_HP_SPREADS[NUMBER_OF_MON_TYPES][NUM_STATS] =
{
    [TYPE_NORMAL]   = {31, 31, 31, 31, 31, 31},
    [TYPE_FIGHTING] = {31, 31, 30, 30, 30, 30},
    [TYPE_FLYING]   = {31, 31, 31, 30, 30, 30},
    [TYPE_POISON]   = {31, 31, 30, 31, 30, 30},
    [TYPE_GROUND]   = {31, 31, 31, 31, 30, 30},
    [TYPE_ROCK]     = {31, 31, 30, 30, 31, 30},
    [TYPE_BUG]      = {31, 31, 31, 30, 31, 30},
    [TYPE_GHOST]    = {31, 30, 31, 31, 31, 30},
    [TYPE_STEEL]    = {31, 31, 31, 31, 31, 30},
    [TYPE_FIRE]     = {31, 30, 31, 30, 30, 31},
    [TYPE_WATER]    = {31, 31, 31, 30, 30, 31},
    [TYPE_GRASS]    = {30, 31, 31, 31, 30, 31},
    [TYPE_ELECTRIC] = {31, 31, 31, 31, 30, 31},
    [TYPE_PSYCHIC]  = {30, 31, 31, 30, 31, 31},
    [TYPE_ICE]      = {31, 31, 31, 30, 31, 31},
    [TYPE_DRAGON]   = {30, 31, 31, 31, 31, 31},
    [TYPE_DARK]     = {31, 31, 31, 31, 31, 31}
};
