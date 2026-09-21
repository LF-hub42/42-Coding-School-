#ifndef BOT_H
#define BOT_H

#include "core_lib.h"

typedef enum e_various
{
	UNIT_ALL = 4,
} t_various;

t_obj *ft_get_core_own(void);
t_obj *ft_get_core_opponent(void);
t_obj *ft_get_gems_nearest(t_pos pos);
t_obj *ft_get_deposit_nearest(t_pos pos);
t_obj *ft_get_deposit_gems_nearest(t_pos pos);
t_obj *ft_get_units_opponent_nearest(t_pos pos);
t_obj **ft_get_units_own(void);
t_obj **ft_get_units_opponent(void);
bool	is_unit_own(const t_obj *obj);

#endif /* BOT_H */
