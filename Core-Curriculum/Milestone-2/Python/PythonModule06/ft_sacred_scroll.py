from alchemy.potions import healing_potion


def main() -> None:
    print("=== Sacred Scroll Mastery ===")
    print()

    print("--- Part I: Sacred Scroll Test ---")
    # Ich teste den einfachen Import einer Trank-Funktion
    result = healing_potion()
    print(f"Ergebnis: {result}")


if __name__ == "__main__":
    main()

# Quick test commands:
# python3 ft_sacred_scroll.py
# python3 -c "from alchemy.transmutation import lead_to_gold; lead_to_gold()"
