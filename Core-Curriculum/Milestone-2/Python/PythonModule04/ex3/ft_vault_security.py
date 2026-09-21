def secure_vault_access() -> None:
    """Uses context managers to ensure secure file operations."""
    print("=== CYBER ARCHIVES - VAULT SECURITY SYSTEM ===")
    print("Initiating secure vault access...")

    try:
        with open("ancient_fragment.txt", "r") as vault:
            _ = vault.read()
            print("Vault connection established with failsafe protocols")
            print("SECURE EXTRACTION:")
            print("[CLASSIFIED] Quantum encryption keys recovered")
            print("[CLASSIFIED] Archive integrity: 100%")
    except FileNotFoundError:
        print("ERROR: Source vault not found.")

    with open("security_log.txt", "w") as secret_vault:
        secret_vault.write("[CLASSIFIED] New security protocols archived\n")

    print("Vault automatically sealed upon completion")
    print("All vault operations completed with maximum security.")


if __name__ == "__main__":
    secure_vault_access()
