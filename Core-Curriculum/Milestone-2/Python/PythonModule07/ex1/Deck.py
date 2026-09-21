import random
from ex0.Card import Card


class Deck:
    def __init__(self):
        self.cards: list[Card] = []

    def add_card(self, card: Card) -> None:
        self.cards.append(card)

    def shuffle(self) -> None:
        random.shuffle(self.cards)

    def draw_card(self) -> Card:
        if not self.cards:
            raise IndexError("Deck is empty")
        return self.cards.pop()

    def get_deck_stats(self) -> dict:
        # Hier zählen wir die Typen (Profi-Ansatz)
        stats = {
            "total_cards": len(self.cards),
            "creatures": 0,
            "spells": 0,
            "artifacts": 0,
        }
        for card in self.cards:
            # Wir prüfen den Klassennamen für die Stats
            class_name = card.__class__.__name__.lower()
            if "creature" in class_name:
                stats["creatures"] += 1
            elif "spell" in class_name:
                stats["spells"] += 1
            elif "artifact" in class_name:
                stats["artifacts"] += 1

        # Durchschnittskosten
        if self.cards:
            avg_cost = sum(c.cost for c in self.cards) / len(self.cards)
        else:
            avg_cost = 0
        stats["avg_cost"] = avg_cost
        return stats
