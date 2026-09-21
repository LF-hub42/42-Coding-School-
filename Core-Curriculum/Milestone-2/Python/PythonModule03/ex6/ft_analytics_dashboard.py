def run_dashboard() -> None:
    """Demonstrates all types of Python comprehensions."""
    data = {"alice": 2300, "bob": 1800, "charlie": 2150, "diana": 2050}

    print("=== Game Analytics Dashboard ===")

    # 1. List Comprehension: Filter und Transformation
    high_scorers = [name for name, score in data.items() if score > 2000]
    scores_doubled = [score * 2 for score in data.values()]
    print(f"High scorers (>2000): {high_scorers}")
    print(f"Scores doubled: {scores_doubled}")

    # 2. Dict Comprehension: Mapping erstellen
    score_cats = {n: "high" if s > 2000 else "medium" for n, s in data.items()}
    print(f"Score categories: {score_cats}")

    # 3. Set Comprehension: Einzigartige Werte extrahieren
    unique_levels = {s // 100 for s in data.values()}
    print(f"Unique score regions (per 100s): {unique_levels}")


if __name__ == "__main__":
    run_dashboard()
