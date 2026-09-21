import sys


def main() -> None:
    """Prints command line arguments and their count."""
    print("=== Command Quest ===")

    # sys.argv[0] ist immer der Dateiname selbst
    program_name = sys.argv[0]
    # Die tatsächlichen Argumente starten ab Index 1
    args = sys.argv[1:]

    if not args:
        print("No arguments provided!")
    else:
        print(f"Arguments received: {len(args)}")
        for i, arg in enumerate(args, 1):
            print(f"Argument {i}: {arg}")

    print(f"Program name: {program_name}")
    print(f"Total arguments: {len(sys.argv)}")


if __name__ == "__main__":
    main()
