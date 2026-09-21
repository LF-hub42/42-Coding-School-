from ex3.FantasyCardFactory import FantasyCardFactory
from ex3.AggressiveStrategy import AggressiveStrategy
from ex3.GameEngine import GameEngine


def main():
    print("=== DataDeck Game Engine ===")

    # Setup
    factory = FantasyCardFactory()
    strategy = AggressiveStrategy()
    engine = GameEngine()
    engine.configure_engine(factory, strategy)

    # Karten erstellen
    hand = [
        factory.create_creature("Fire Dragon"),
        factory.create_creature("Goblin Warrior"),
        factory.create_spell("Lightning Bolt")
    ]

    # Simulation
    print("Configuring Fantasy Card Game...")
    print(f"Factory: {factory.__class__.__name__}")
    print(f"Strategy: {strategy.get_strategy_name()}")

    print("\nSimulating aggressive turn...")
    result = engine.simulate_turn(hand)
    print(f"Turn execution: {result}")


if __name__ == "__main__":
    main()
# Run:python3 -m ex3.main
