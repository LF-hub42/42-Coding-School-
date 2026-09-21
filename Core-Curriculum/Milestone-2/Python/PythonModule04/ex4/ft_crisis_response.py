def handle_crisis(filename: str) -> None:
    """Attempts to access files and handles potential crises gracefully."""
    try:
        with open(filename, "r") as archive:
            print(f"ROUTINE ACCESS: Attempting access to '{filename}'...")
            content = archive.read().strip()
            print(f"SUCCESS: Archive recovered - \"{content}\"")
            print("STATUS: Normal operations resumed")
    except FileNotFoundError:
        print(f"CRISIS ALERT: Attempting access to '{filename}'...")
        print("RESPONSE: Archive not found in storage matrix")
        print("STATUS: Crisis handled, system stable")
    except PermissionError:
        print(f"CRISIS ALERT: Attempting access to '{filename}'...")
        print("RESPONSE: Security protocols deny access")
        print("STATUS: Crisis handled, security maintained")
    except Exception as e:
        print(f"CRISIS ALERT: Attempting access to '{filename}'...")
        print(f"RESPONSE: Unexpected anomaly: {e}")
        print("STATUS: Crisis handled, system containment active")


def run_crisis_sim() -> None:
    """Simulates various archival crisis scenarios."""
    print("=== CYBER ARCHIVES - CRISIS RESPONSE SYSTEM ===")
    handle_crisis("lost_archive.txt")

    handle_crisis("classified_vault.txt")

    handle_crisis("standard_archive.txt")

    print("All crisis scenarios handled successfully. Archives secure.")


if __name__ == "__main__":
    run_crisis_sim()
