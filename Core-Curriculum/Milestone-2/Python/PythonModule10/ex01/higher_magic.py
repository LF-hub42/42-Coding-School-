from typing import Callable, List, Any, Tuple


def spell_combiner(spell1: Callable, spell2: Callable) -> Callable:
    """
    Returns a new function that executes two spells and returns their results.
    The combined spell receives the same arguments for both parts.
    """
    def combined_spell(*args: Any, **kwargs: Any) -> Tuple[Any, Any]:
        return (spell1(*args, **kwargs), spell2(*args, **kwargs))
    return combined_spell


def power_amplifier(base_spell: Callable, multiplier: int) -> Callable:
    """
    Returns a function that multiplies the result of the base spell.
    Assumes the base spell returns a numerical value.
    """
    def amplified_spell(*args: Any, **kwargs: Any) -> Any:
        return base_spell(*args, **kwargs) * multiplier
    return amplified_spell


def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    """
    Returns a function that only executes the spell if the condition is met.
    If the condition is False, it returns 'Spell fizzled'.
    """
    def cast_if_valid(*args: Any, **kwargs: Any) -> Any:
        if condition(*args, **kwargs):
            return spell(*args, **kwargs)
        return "Spell fizzled"
    return cast_if_valid


def spell_sequence(spells: List[Callable]) -> Callable:
    """
    Returns a function that executes a list of spells in order.
    Returns a list containing the result of each spell.
    """
    def sequence_runner(*args: Any, **kwargs: Any) -> List[Any]:
        return [s(*args, **kwargs) for s in spells]
    return sequence_runner


if __name__ == "__main__":
    # --- Example Spells for Testing ---
    def fireball(target: str) -> str:
        return f"Fireball hits {target}"

    def heal(target: str) -> str:
        return f"Heals {target}"

    def get_damage(target: str) -> int:
        # Dummy damage for testing
        return 10

    # Testing spell_combiner
    print("Testing spell combiner...")
    combo = spell_combiner(fireball, heal)
    print(f"Result: {combo('Dragon')}")

    # Testing power_amplifier
    print("\nTesting power amplifier...")
    mega_fire = power_amplifier(get_damage, 3)
    print(f"Original: 10, Amplified: {mega_fire('Dragon')}")

    # Testing conditional_caster
    print("\nTesting conditional caster...")
    # Condition: target must not be 'Ally'

    def is_enemy(target: str) -> bool:
        return target != "Ally"

    safe_spell = conditional_caster(is_enemy, fireball)
    print(f"Against Dragon: {safe_spell('Dragon')}")
    print(f"Against Ally: {safe_spell('Ally')}")

    # Testing spell_sequence
    print("\nTesting spell sequence...")
    actions = [fireball, heal]
    seq = spell_sequence(actions)
    print(f"Sequence results: {seq('Hydra')}")
# python3 ex01/higher_magic.py
