from typing import Callable, Dict, Any


def mage_counter() -> Callable[[], int]:
    """
    Creates a counting closure.
    The counter starts at 1 and persists between calls.
    """
    count = 0

    def counter() -> int:
        nonlocal count
        count += 1
        return count
    return counter


def spell_accumulator(initial_power: int) -> Callable[[int], int]:
    """
    Creates a power accumulator closure.
    Each call adds a value to the persistent total power.
    """
    total_power = initial_power

    def accumulator(power: int) -> int:
        nonlocal total_power
        total_power += power
        return total_power
    return accumulator


def enchantment_factory(enchantment_type: str) -> Callable[[str], str]:
    """
    Returns a function that applies a specific enchantment to an item.
    Example: enchantment_factory("Flaming")("Sword") -> "Flaming Sword"
    """
    def enchant(item_name: str) -> str:
        return f"{enchantment_type} {item_name}"
    return enchant


def memory_vault() -> Dict[str, Callable]:
    """
    Creates a private memory storage system using closures.
    Returns a dictionary with 'store' and 'recall' functions.
    """
    vault = {}

    def store(key: str, value: Any) -> None:
        vault[key] = value

    def recall(key: str) -> Any:
        return vault.get(key, "Memory not found")

    return {
        "store": store,
        "recall": recall
    }


if __name__ == "__main__":
    # Testing mage counter
    print("Testing mage counter...")
    my_counter = mage_counter()
    print(f"Call 1: {my_counter()}")
    print(f"Call 2: {my_counter()}")

    # Testing spell accumulator
    print("\nTesting spell accumulator (start with 10)...")
    acc = spell_accumulator(10)
    print(f"Add 5: {acc(5)}")
    print(f"Add 20: {acc(20)}")

    # Testing enchantment factory
    print("\nTesting enchantment factory...")
    fire_enchant = enchantment_factory("Flaming")
    ice_enchant = enchantment_factory("Frozen")
    print(fire_enchant("Sword"))
    print(ice_enchant("Shield"))

    # Testing memory vault
    print("\nTesting memory vault...")
    v = memory_vault()
    v["store"]("ancient_spell", "Klaatu Barada Nikto")
    print(f"Recall spell: {v['recall']('ancient_spell')}")
    print(f"Recall unknown: {v['recall']('lost_scroll')}")
# python3 ex02/scope_mysteries.py
