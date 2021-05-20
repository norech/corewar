/*
** EPITECH PROJECT, 2021
** append_instance
** File description:
** Source code
*/

#include <my.h>
#include "corewar/corewar.h"

int append_instance(champion_t *champ, program_memory_t *instance)
{
    program_memory_t *old_instances = champ->instances;
    program_memory_t *new_instances;

    if (champ->instances_count == champ->instances_max) {
        champ->instances_max *= 2;
        new_instances = realloc(old_instances,
            sizeof(program_memory_t) * champ->instances_max);
        if (new_instances == NULL)
            return (-1);
        champ->instances = new_instances;
    }
    my_memcpy(&champ->instances[champ->instances_count++], instance,
        sizeof(program_memory_t));
    return (champ->instances_count);
}