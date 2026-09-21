import alchemy.transmutation


def main() -> None:
    print("=== Pathway Debate Mastery ===")

    print("\nTesting Absolute Imports (from basic.py):")
    print(f"lead_to_gold(): {alchemy.transmutation.lead_to_gold()}")

    print("\nTesting Relative Imports (from advanced.py):")
    p_s = alchemy.transmutation.philosophers_stone()
    print(f"philosophers_stone(): {p_s}")


if __name__ == "__main__":
    main()

# Command to test Part III:
# python3 ft_pathway_debate.py
# python3 -c "import alchemy.transmutation;
# alchemy.transmutation.philosophers_stone()"
