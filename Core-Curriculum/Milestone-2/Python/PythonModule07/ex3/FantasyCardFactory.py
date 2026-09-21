from ex3.CardFactory import CardFactory
from ex0.CreatureCard import CreatureCard
from ex1.SpellCard import SpellCard
from ex1.ArtifactCard import ArtifactCard


class FantasyCardFactory(CardFactory):
    def create_creature(self, name: str = "Goblin") -> CreatureCard:
        return CreatureCard(name, 2, "Common", 2, 2)

    def create_spell(self, name: str = "Fireball") -> SpellCard:
        return SpellCard(name, 3, "Rare", "damage")

    def create_artifact(self, name: str = "Mana Ring") -> ArtifactCard:
        return ArtifactCard(name, 1, "Uncommon", 5, "+1 Mana")

    def get_supported_types(self) -> dict:
        return {
            "creatures": ["dragon", "goblin"],
            "spells": ["fireball"],
            "artifacts": ["mana_ring"]
        }
