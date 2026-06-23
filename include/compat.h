#pragma once

// Prevent Windows CRT collisions with N64 symbols
#ifdef log
#undef log
#endif

#ifdef _itoa
#undef _itoa
#endif