def analyze_achievements() -> None:
    """Analyzes player achievements using set operations."""
    alice: set[str] = {
        'first_kill', 'level_10', 'treasure_hunter', 'speed_demon'
    }
    bob: set[str] = {
        'first_kill', 'level_10', 'boss_slayer', 'collector'
    }
    charlie: set[str] = {
        'level_10', 'treasure_hunter', 'boss_slayer',
        'speed_demon', 'perfectionist'
    }

    print(f"Player alice achievements: {alice}")
    print(f"Player bob achievements: {bob}")
    print(f"Player charlie achievements: {charlie}")

    print("\n=== Achievement Analytics ===")
    all_unique = alice | bob | charlie
    print(f"All unique achievements: {all_unique}")
    print(f"Total unique achievements: {len(all_unique)}")

    common = alice & bob & charlie
    print(f"Common to all players: {common}")

    rare = (alice - bob - charlie) | (bob - alice - charlie) | \
           (charlie - alice - bob)
    print(f"Rare achievements (1 player): {rare}")


if __name__ == "__main__":
    print("=== Achievement Tracker System ===")
    analyze_achievements()
