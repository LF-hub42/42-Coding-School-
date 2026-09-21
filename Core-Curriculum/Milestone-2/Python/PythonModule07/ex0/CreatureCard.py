from .Card import Card


class CreatureCard(Card):
    def __init__(
        self,
        name: str,
        cost: int,
        rarity: str,
        attack: int,
        health: int
    ):
        # Validierung laut Subjekt: Positive Integer
        if not isinstance(attack, int) or attack < 0:
            raise ValueError("Attack must be a positive integer")
        if not isinstance(health, int) or health <= 0:
            raise ValueError("Health must be a positive integer")

        super().__init__(name, cost, rarity)
        self.attack = attack
        self.health = health

    def play(self, game_state: dict) -> dict:
        # Logik: Prüfe Mana (optional, aber gut für den Spielverlauf)
        mana = game_state.get("available_mana", 0)
        if not self.is_playable(mana):
            return {"error": "Not enough mana"}

        return {
            "card_played": self.name,
            "mana_used": self.cost,
            "effect": "Creature summoned to battlefield"
        }

    def attack_target(self, target) -> dict:
        # Hier gehen wir davon aus, dass 'target' einen Namen hat
        target_name = getattr(target, 'name', str(target))
        return {
            "attacker": self.name,
            "target": target_name,
            "damage_dealt": self.attack,
            "combat_resolved": True
        }
