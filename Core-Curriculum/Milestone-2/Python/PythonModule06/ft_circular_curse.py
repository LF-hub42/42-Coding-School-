from alchemy.grimoire import record_spell, validate_ingredients


def main() -> None:
    print("=== Circular Curse Breaking ===")
    v_f = "fire air"
    print(f'validate_ingredients("{v_f}"): {validate_ingredients(v_f)}')

    print("\nTesting spell recording with validation:")
    # Zeile gekürzt für Flake8
    res = record_spell("Fireball", v_f)
    print(f'record_spell("Fireball", "{v_f}"): {res}')

    print("\nCircular dependency curse avoided using late imports!")


if __name__ == "__main__":
    main()

# Command to test Part IV:
# python3 ft_circular_curse.py
# python3 -c "from alchemy.grimoire import record_spell;
# record_spell('Test', 'fire')"
