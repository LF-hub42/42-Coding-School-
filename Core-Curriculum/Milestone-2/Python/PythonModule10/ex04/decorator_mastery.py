import functools
import time
from typing import Callable, Any, NoReturn


def spell_timer(func: Callable) -> Callable:
    """
    Decorator that measures and prints the execution time of a function.
    """
    @functools.wraps(func)
    def wrapper(*args: Any, **kwargs: Any) -> Any:
        print(f"Casting {func.__name__}...")
        start_time = time.time()
        result = func(*args, **kwargs)
        end_time = time.time()
        duration = end_time - start_time
        print(f"Spell completed in {duration:.3f} seconds")
        return result
    return wrapper


def power_validator(min_power: int) -> Callable:
    """
    Decorator factory that validates if the power (first argument)
    is high enough to cast the spell.
    """
    def decorator(func: Callable) -> Callable:
        @functools.wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> Any:
            power = kwargs.get("power")
            if power is None and args:
                power = args[-1]
            if power < min_power:
                return "Insufficient power for this spell"
            return func(*args, **kwargs)
        return wrapper
    return decorator


def retry_spell(max_attempts: int) -> Callable:
    """
    Decorator that retries a function if it raises an exception.
    """
    def decorator(func: Callable) -> Callable:
        @functools.wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> Any:
            for attempt in range(1, max_attempts + 1):
                try:
                    return func(*args, **kwargs)
                except Exception:
                    print(f"Spell failed, retrying... (attempt {attempt}/"
                          f"{max_attempts})")
            return (f"Spell casting failed after {max_attempts} "
                    f"attempts")
        return wrapper
    return decorator


class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        """
        Validates a mage name: min 3 chars, letters and spaces only.
        """
        if len(name) < 3:
            return False
        return all(char.isalpha() or char.isspace() for char in name)

    @power_validator(min_power=10)
    def cast_spell(self, spell_name: str, power: int) -> str:
        """
        Instance method to cast a spell, protected by power_validator.
        """
        return f"Successfully cast {spell_name} with power {power}"


if __name__ == "__main__":
    # Testing spell_timer
    @spell_timer
    def slow_fireball() -> str:
        time.sleep(0.1)
        return "Fireball cast!"

    print("Testing spell timer...")
    print(f"Result: {slow_fireball()}\n")

    # Testing MageGuild
    guild = MageGuild()
    print("Testing MageGuild name validation:")
    print(f"Is 'Al' valid? {guild.validate_mage_name('Al')}")
    print(f"Is 'Gandalf' valid? {guild.validate_mage_name('Gandalf')}")

    print("\nTesting power_validator on cast_spell:")
    print(guild.cast_spell("Lightning", 15))
    print(guild.cast_spell("Spark", 5))

    # Testing retry_spell
    @retry_spell(max_attempts=3)
    def unstable_portal() -> NoReturn:
        raise ValueError("Portal collapsed")

    print("\nTesting retry_spell:")
    print(unstable_portal())
# python3 ex04/decorator_mastery.py
