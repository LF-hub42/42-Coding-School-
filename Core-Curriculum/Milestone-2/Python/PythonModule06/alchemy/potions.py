from alchemy.elements import create_fire, create_water


def healing_potion() -> str:
    return f"Healing potion brewed with {create_fire()} and {create_water()}"


def strength_potion() -> str:
    # Um die Warnung zu vermeiden, nutze ich nur create_fire
    return f"Strength potion brewed with {create_fire()}"


def invisibility_potion() -> str:
    return f"Invisibility potion brewed with {create_water()}"

# Run Code:
# python3 ft_sacred_scroll.py
