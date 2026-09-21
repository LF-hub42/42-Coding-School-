def create_archive() -> None:
    """Creates a new storage unit and inscribes data."""
    filename = "new_discovery.txt"
    print("=== CYBER ARCHIVES - PRESERVATION SYSTEM ===")
    print(f"Initializing new storage unit: {filename}")

    vault = open(filename, "w")
    print("Storage unit created successfully...")

    print("Inscribing preservation data...")
    vault.write("[ENTRY 001] New quantum algorithm discovered\n")
    vault.write("[ENTRY 002] Efficiency increased by 347%\n")
    vault.write("[ENTRY 003] Archived by Data Archivist trainee\n")

    vault.close()
    print("Data inscription complete. Storage unit sealed.")
    print(f"Archive '{filename}' ready for long-term preservation.")


if __name__ == "__main__":
    create_archive()
