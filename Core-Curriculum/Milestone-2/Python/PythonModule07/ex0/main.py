from .CreatureCard import CreatureCard


def main():
    print("=== DataDeck Card Foundation ===")

    # 1. Karte erstellen
    dragon = CreatureCard("Fire Dragon", 5, "Legendary", 7, 5)

    # 2. Info anzeigen
    print("\nCreatureCard Info:")
    info = dragon.get_card_info()
    info.update({
        "type": "Creature",
        "attack": dragon.attack,
        "health": dragon.health
    })
    print(info)

    # 3. Play-Test (Genug Mana)
    print(f"\nPlaying {dragon.name} with 6 mana available:")
    game_state = {"available_mana": 6}
    print(f"Playable: {dragon.is_playable(game_state['available_mana'])}")
    print(f"Play result: {dragon.play(game_state)}")

    # 4. Kampf-Test
    print(f"\n{dragon.name} attacks Goblin Warrior:")
    print(f"Attack result: {dragon.attack_target('Goblin Warrior')}")

    # 5. Play-Test (Zu wenig Mana)
    print("\nTesting insufficient mana (3 available):")
    low_mana_state = {"available_mana": 3}
    print(f"Playable: {dragon.is_playable(low_mana_state['available_mana'])}")


if __name__ == "__main__":
    main()
# Run:python3 -m ex0.main
