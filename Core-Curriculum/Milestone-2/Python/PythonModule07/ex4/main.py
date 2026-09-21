from ex4.TournamentManager import TournamentManager


def main():
    print("=== DataDeck Tournament Manager (Singleton) ===")
    tm1 = TournamentManager()
    tm2 = TournamentManager()

    print(f"Same instance? {tm1 is tm2}")  # MUSS True sein

    tm1.register_participant("DragonMaster")
    tm1.register_participant("SpellCaster")

    print(f"Participants via tm2: {tm2.participants}")
    print(tm1.start_tournament())
    print(tm1.record_match("DragonMaster", "SpellCaster", "DragonMaster"))


if __name__ == "__main__":
    main()
# Run:python3 -m ex4.main
