from ex0.Card import Card
from ex2.Combatable import Combatable
from ex2.Magical import Magical


class EliteCard(Card, Combatable, Magical):
    def __init__(
        self,
        name: str,
        cost: int,
        rarity: str,
        attack: int,
        mana_power: int,
    ):
        super().__init__(name, cost, rarity)
        self.attack_val = attack
        self.mana_power = mana_power

    def play(self, game_state: dict) -> dict:
        return {
            "card_played": self.name,
            "effect": "Elite card enters the fray!",
        }

    def attack(self, target) -> dict:
        return {
            "attacker": self.name,
            "target": str(target),
            "damage": self.attack_val,
            "combat_type": "melee",
        }

    def defend(self, incoming_damage: int) -> dict:
        blocked = 3
        return {
            "defender": self.name,
            "damage_taken": max(0, incoming_damage - blocked),
            "damage_blocked": blocked,
            "still_alive": True,
        }

    def get_combat_stats(self) -> dict:
        return {"attack": self.attack_val}

    def cast_spell(self, spell_name: str, targets: list) -> dict:
        return {
            "caster": self.name,
            "spell": spell_name,
            "targets": targets,
            "mana_used": 4,
        }

    def channel_mana(self, amount: int) -> dict:
        self.mana_power += amount
        return {"channeled": amount, "total_mana": self.mana_power}

    def get_magic_stats(self) -> dict:
        return {"mana_power": self.mana_power}
