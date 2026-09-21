from ex3.GameStrategy import GameStrategy


class AggressiveStrategy(GameStrategy):
    def execute_turn(self, hand: list, battlefield: list) -> dict:
        cards_played = []
        mana_spent = 0
        for card in hand:
            cards_played.append(card.name)
            mana_spent += card.cost
            battlefield.append(card)

        return {
            "strategy": self.get_strategy_name(),
            "cards_played": cards_played,
            "mana_used": mana_spent,
            "damage_dealt": 8  # Beispielwert für den Output
        }

    def get_strategy_name(self) -> str:
        return "AggressiveStrategy"
