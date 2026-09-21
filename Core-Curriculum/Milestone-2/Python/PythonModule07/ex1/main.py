from ex0.CreatureCard import CreatureCard
from ex1.SpellCard import SpellCard
from ex1.ArtifactCard import ArtifactCard
from ex1.Deck import Deck


def main():
    print("=== DataDeck Deck Builder ===")

    # 1. Deck instanziieren
    my_deck = Deck()

    # 2. Verschiedene Karten hinzufügen
    print("Building deck with different card types...")
    my_deck.add_card(CreatureCard("Fire Dragon", 5, "Legendary", 7, 5))
    my_deck.add_card(SpellCard("Lightning Bolt", 3, "Rare", "damage"))
    my_deck.add_card(
        ArtifactCard(
            "Mana Crystal",
            2,
            "Common",
            10,
            "Permanent: +1 mana per turn",
        )
    )

    # 3. Statistiken anzeigen
    stats = my_deck.get_deck_stats()
    print(f"Deck stats: {stats}")

    # 4. Karten ziehen und spielen
    print("\nDrawing and playing cards:")
    try:
        # Wir ziehen alle 3 Karten nacheinander
        for _ in range(3):
            card = my_deck.draw_card()
            # Hier passiert die Magie: card kann alles sein, aber wir wissen,
            # dass jede Card die Methode get_card_info() und play() hat!
            info = card.get_card_info()
            print(f"\nDrew: {info['name']} ({card.__class__.__name__})")

            # Simulieren eines Spielzugs mit 5 Mana
            game_state = {"available_mana": 5}
            print(f"Play result: {card.play(game_state)}")

    except IndexError as e:
        print(f"Error: {e}")

    print(
        "\nPolymorphism in action: Same interface, different card behaviors!"
    )


if __name__ == "__main__":
    main()
# Run:python3 -m ex1.main
