# Das hier gehört IN die Datei ex2/main.py
from ex2.EliteCard import EliteCard


def main():
    print("=== DataDeck Ability System ===")
    hero = EliteCard("Arcane Warrior", 6, "Epic", 5, 10)

    print("\nPlaying Arcane Warrior (Elite Card):")
    # Hier rufen wir die Methode aus Card auf
    print(hero.play({}))

    print("\nCombat phase:")
    # Hier rufen wir Methoden aus Combatable auf
    print(hero.attack("Enemy Orc"))
    print(hero.defend(5))

    print("\nMagic phase:")
    # Hier rufen wir Methoden aus Magical auf
    print(hero.cast_spell("Fireball", ["Enemy1", "Enemy2"]))
    print(hero.channel_mana(3))


if __name__ == "__main__":
    main()
# Run:python3 -m ex2.main
