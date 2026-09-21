import sys


def manage_streams() -> None:
    """Demonstrates use of standard input, output, and error streams."""
    print("=== CYBER ARCHIVES - COMMUNICATION SYSTEM ===")

    sys.stdout.write("Input Stream active. Enter archivist ID: ")
    sys.stdout.flush()
    archivist_id = sys.stdin.readline().strip()

    sys.stdout.write("Input Stream active. Enter status report: ")
    sys.stdout.flush()
    status = sys.stdin.readline().strip()

    sys.stdout.write(
        f"[STANDARD] Archive status from {archivist_id}: {status}\n"
    )
    sys.stderr.write(
        "[ALERT] System diagnostic: Communication channels verified\n"
    )
    sys.stdout.write("[STANDARD] Data transmission complete\n")
    print("Three-channel communication test successful.")


if __name__ == "__main__":
    manage_streams()
