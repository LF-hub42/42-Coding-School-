from typing import Generator


def event_generator(count: int) -> Generator[str, None, None]:
    """Yields simulated game events one by one."""
    players = ["alice", "bob", "charlie"]
    actions = ["killed monster", "found treasure", "leveled up"]

    for i in range(1, count + 1):
        player = players[i % len(players)]
        action = actions[i % len(actions)]
        yield f"Event {i}: Player {player} (level {i % 20}) {action}"


def main() -> None:
    """Processes events from a generator stream."""
    print("=== Game Data Stream Processor ===")
    print("Processing 1000 game events...")

    stream = event_generator(1000)

    for _ in range(3):
        print(next(stream))
    print("...")

    stats = {"treasure": 0, "level_up": 0}
    for event in event_generator(1000):
        if "found treasure" in event:
            stats["treasure"] += 1
        elif "leveled up" in event:
            stats["level_up"] += 1

    print("\n=== Stream Analytics ===")
    print("Total events processed: 1000")
    print(f"Treasure events: {stats['treasure']}")
    print(f"Level-up events: {stats['level_up']}")


if __name__ == "__main__":
    main()
