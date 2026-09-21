import os
import sys

from dotenv import load_dotenv


def consult_oracle() -> None:
    """Loads and displays environment configuration safely."""
    env_path = os.path.join(os.path.dirname(__file__), ".env")
    load_dotenv(env_path)

    print("ORACLE STATUS: Reading the Matrix...")

    # Using defaults for safety as required by Subject
    mode = os.getenv("MATRIX_MODE", "development")
    db = os.getenv("DATABASE_URL", "None")
    api_key = os.getenv("API_KEY")

    print("\nConfiguration loaded:")
    print(f"Mode: {mode}")
    print(f"Database: {'Connected' if db != 'None' else 'Disconnected'}")

    if api_key:
        print("API Access: Authenticated")
    else:
        print("[WARNING] No API_KEY found!")

    print("\nEnvironment security check:")
    if api_key and api_key != "shhh_secret_key":
        print("[OK] Production secrets detected")
    else:
        print("[INFO] Running with default/missing credentials")


if __name__ == "__main__":
    try:
        consult_oracle()
    except Exception as error:
        print(f"Critical System Failure: {error}")
        sys.exit(1)
