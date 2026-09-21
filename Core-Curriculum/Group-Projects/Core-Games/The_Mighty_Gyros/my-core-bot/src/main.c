#include "bot.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

t_pos corpos;

// Hilfsfunktion: Zählt Einheiten eines Typs sicher und gibt Speicher frei
static int get_unit_count(int unitType)
{
    int j = 0;
    t_obj **units = ft_get_units_own();
    if (!units) return 0;
    for (int i = 0; units[i]; i++)
    {
        if ((int)units[i]->s_unit.unit_type == unitType)
            j++;
    }
    free(units);
    return j;
}

// Manhattan-Distanz Check
static bool distance_is_smaller_and_safe(t_pos current, t_pos target, t_pos base)
{
    int dist_to_target = abs(current.x - target.x) + abs(current.y - target.y);
    int dist_to_base = abs(current.x - base.x) + abs(current.y - base.y);
    return (dist_to_base < dist_to_target);
}

// Zählt alle Einheiten basierend auf dem UNIT_ALL enum aus deinem Header
static int posa_anguria(int pious)
{
    int i = 0;
    if (pious == UNIT_ALL || pious == UNIT_WARRIOR) i += get_unit_count(UNIT_WARRIOR);
    if (pious == UNIT_ALL || pious == UNIT_MINER) i += get_unit_count(UNIT_MINER);
    return i;
}

void ft_on_tick(unsigned long tick)
{
    printf("-----> [⚡️ TICK %ld 🔥]\n", tick);

    t_obj *core = ft_get_core_own();
    if (!core) return;
    corpos = core->pos;
    t_obj *enemy_core = ft_get_core_opponent();

    // --- PRODUKTION: 2 Miner, dann Krieger ---
    int current_miners = get_unit_count(UNIT_MINER);
    if (core->s_core.gems >= 100 && current_miners < 2)
        core_action_createUnit(UNIT_MINER);
    else if (core->s_core.gems >= 150)
        core_action_createUnit(UNIT_WARRIOR);

    t_obj **all_own = ft_get_units_own();
    if (!all_own) return;

    // Speicher für sortierte Listen reservieren
    int total = 0;
    while (all_own[total]) total++;
    t_obj **units_miner = calloc(total + 1, sizeof(t_obj *));
    t_obj **units_warrior = calloc(total + 1, sizeof(t_obj *));

    int m_idx = 0, w_idx = 0;
    for (int i = 0; all_own[i]; i++)
    {
        if (all_own[i]->s_unit.unit_type == UNIT_MINER)
            units_miner[m_idx++] = all_own[i];
        else if (all_own[i]->s_unit.unit_type == UNIT_WARRIOR)
            units_warrior[w_idx++] = all_own[i];
    }

    // --- MINER LOGIK ---
    for (int i = 0; i < m_idx; i++)
    {
        t_obj *nearest_gem = ft_get_gems_nearest(units_miner[i]->pos);
        if (units_miner[i]->s_unit.gems > 0 && nearest_gem)
        {
            if (distance_is_smaller_and_safe(units_miner[i]->pos, nearest_gem->pos, core->pos))
            {
                core_action_pathfind(units_miner[i], core->pos);
                core_action_transferGems(units_miner[i], core->pos, 999);
                continue;
            }
        }
        if (nearest_gem)
            core_action_pathfind(units_miner[i], nearest_gem->pos);
    }

    // --- KRIEGER LOGIK (1 Verteidiger, Rest Rush) ---
    t_obj *threat = ft_get_units_opponent_nearest(core->pos);
    for (int i = 0; i < w_idx; i++)
    {
        if (i == 0) // Der erste Krieger ist der Guard
        {
            if (threat && (abs(threat->pos.x - core->pos.x) + abs(threat->pos.y - core->pos.y) < 15))
                core_action_pathfind(units_warrior[i], threat->pos);
            else
            {
                t_pos guard_pos = core->pos;
                guard_pos.x += (core->pos.x < 10) ? 6 : -6;
                core_action_pathfind(units_warrior[i], guard_pos);
            }
        }
        else // Alle weiteren stürmen den Gegner
        {
            if (enemy_core)
                core_action_pathfind(units_warrior[i], enemy_core->pos);
        }
    }

    // --- CLEANUP ---
    free(all_own);
    free(units_miner);
    free(units_warrior);
}

int main(int argc, char **argv)
{
    return core_startGame("The_Mighty_Gyros", argc, argv, ft_on_tick, false);
}
