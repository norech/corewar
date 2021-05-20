/*
** EPITECH PROJECT, 2021
** champion
** File description:
** Source code
*/

#ifndef E03F6F4D_5128_4119_8E15_1C6AFA342691
#define E03F6F4D_5128_4119_8E15_1C6AFA342691

#include <corewar/corewar.h>

int load_champion_from_file(champion_t *champ, char *file);

int load_champion_from_bytes(champion_t *champ, byte_t *bytes, int bytes_count);

int create_champion(champion_t *champ, program_memory_t *mem);

int create_champion_from_file(champion_t *champ, program_memory_t *mem,
    char *file);

#endif /* E03F6F4D_5128_4119_8E15_1C6AFA342691 */
