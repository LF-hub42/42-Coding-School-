class TournamentManager:
    _instance = None

    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(TournamentManager, cls).__new__(cls)
            cls._instance.participants = []
            cls._instance.match_history = []
            cls._instance.is_started = False
        return cls._instance

    def register_participant(self, name: str):
        if name not in self.participants:
            self.participants.append(name)
            return f"Participant {name} registered."
        return f"{name} already registered."

    def start_tournament(self):
        if len(self.participants) < 2:
            return "Need at least 2 participants!"
        self.is_started = True
        return "Tournament started!"

    def record_match(self, p1: str, p2: str, winner: str):
        self.match_history.append({"p1": p1, "p2": p2, "winner": winner})
        return f"Winner: {winner}"
