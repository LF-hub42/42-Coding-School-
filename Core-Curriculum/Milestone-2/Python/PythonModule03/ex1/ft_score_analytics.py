import sys


def analyze_scores(argv: list[str]) -> None:
    """Processes scores from strings to integers and prints analytics."""
    print("=== Player Score Analytics ===")

    if len(argv) < 2:
        print("No scores provided. Usage: "
              "python3 ft_score_analytics.py <score1> <score2> ...")
        return

    try:
        # Liste mit List-Comprehension (oder Schleife) füllen
        scores = [int(arg) for arg in argv[1:]]

        print(f"Scores processed: {scores}")
        print(f"Total players: {len(scores)}")
        print(f"Total score: {sum(scores)}")
        print(f"Average score: {sum(scores) / len(scores)}")
        print(f"High score: {max(scores)}")
        print(f"Low score: {min(scores)}")
        print(f"Score range: {max(scores) - min(scores)}")

    except ValueError:
        print("Error: All arguments must be numeric scores!")


if __name__ == "__main__":
    analyze_scores(sys.argv)
