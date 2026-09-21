import functools
import operator
from typing import List, Callable, Dict, Any


def spell_reducer(spells: List[int], operation: str) -> int:
    """
    Reduces a list of spell powers into a single value using functools.reduce.
    Supports: 'add', 'multiply', 'max', 'min'.
    """
    ops = {
        "add": operator.add,
        "multiply": operator.mul,
        "max": max,
        "min": min
    }
    if operation not in ops:
        return 0
    return functools.reduce(ops[operation], spells)


def partial_enchanter(base_enchantment: Callable) -> Dict[str, Callable]:
    """
    Creates specialized versions of a base enchantment function
    using functools.partial with pre-set power and elements.
    """
    # base_enchantment expects (power, element, target)
    fire = functools.partial(base_enchantment, 50, "Fire")
    ice = functools.partial(base_enchantment, 50, "Ice")
    light = functools.partial(base_enchantment, 50, "Lightning")

    return {
        "fire_enchant": fire,
        "ice_enchant": ice,
        "lightning_enchant": light
    }


@functools.lru_cache(maxsize=None)
def memoized_fibonacci(n: int) -> int:
    """
    Calculates the nth Fibonacci number using recursion and lru_cache
    for optimal performance.
    """
    if n < 2:
        return n
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> Callable[[Any], str]:
    """
    Creates a singledispatch function for handling different spell inputs.
    """
    @functools.singledispatch
    def dispatch(arg: Any) -> str:
        return "Unknown magical essence"

    @dispatch.register(int)
    def _(arg: int) -> str:
        return f"Casting damage spell: {arg} HP"

    @dispatch.register(str)
    def _(arg: str) -> str:
        return f"Applying enchantment: {arg}"

    @dispatch.register(list)
    def _(arg: list) -> str:
        return f"Multi-casting {len(arg)} spells"

    return dispatch


if __name__ == "__main__":
    # Testing spell reducer
    powers = [10, 20, 30, 40]
    print(f"Sum: {spell_reducer(powers, 'add')}")
    print(f"Max: {spell_reducer(powers, 'max')}")

    # Testing partial enchanter
    def base_spell(power: int, element: str, target: str) -> str:
        return f"{element} spell ({power} power) cast on {target}"

    enchanters = partial_enchanter(base_spell)
    print(enchanters["fire_enchant"]("Skeleton"))

    # Testing memoized fibonacci
    print(f"Fib(50): {memoized_fibonacci(50)}")

    # Testing dispatcher
    dispatcher = spell_dispatcher()
    print(dispatcher(100))
    print(dispatcher("Invisibility"))
    print(dispatcher([1, 2, 3]))
# python3 ex03/functools_artifacts.py
