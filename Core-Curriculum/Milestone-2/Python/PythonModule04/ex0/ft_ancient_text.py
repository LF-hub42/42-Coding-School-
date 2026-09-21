def recover_data() -> None:
    """Recovers data from the ancient storage vault."""
    filename = "ancient_fragment.txt"
    print("=== CYBER ARCHIVES - DATA RECOVERY SYSTEM ===")
    print(f"Accessing Storage Vault: {filename}")

    try:
        vault = open(filename, "r")
        print("Connection established...")

        print("RECOVERED DATA:")
        content = vault.read()
        print(content)

        vault.close()
        print("Data recovery complete. Storage unit disconnected.")

    except FileNotFoundError:
        print("ERROR: Storage vault not found. Run data generator first.")


if __name__ == "__main__":
    recover_data()
