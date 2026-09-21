class GameEngine:
    def __init__(self):
        self.factory = None
        self.strategy = None

    def configure_engine(self, factory, strategy):
        self.factory = factory
        self.strategy = strategy

    def simulate_turn(self, hand: list) -> dict:
        battlefield = []
        return self.strategy.execute_turn(hand, battlefield)
