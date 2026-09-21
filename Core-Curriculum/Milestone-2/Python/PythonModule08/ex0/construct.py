import sys
import os
import site


def check_matrix_status() -> None:
    """
    Detects the virtual environment and displays system paths.
    Requirement: Python 3.10+, Type Hints, Graceful Exception Handling.
    """
    try:
        # Detect virtual env: sys.prefix differs from base_prefix when active
        in_venv: bool = sys.prefix != sys.base_prefix

        if not in_venv:
            print("MATRIX STATUS: You're still plugged in")
            print()

            print(f"Current Python: {sys.executable}")
            print("Virtual Environment: None detected")
            print()

            print("WARNING: You're in the global environment!")
            print("The machines can see everything you install.")
            print()

            print("To enter the construct, run:")
            print("python3 -m venv matrix_env")
            print("source matrix_env/bin/activate # On Unix")
            print("source matrix_env/Scripts/activate # On Windows")
            print()
            print("Then run this program again.")
        else:
            venv_name: str = os.path.basename(sys.prefix)
            print("MATRIX STATUS: Welcome to the construct")
            print()
            print(f"Current Python: {sys.executable}")
            print(f"Virtual Environment: {venv_name}")
            print(f"Environment Path: {sys.prefix}")
            print()

            print("SUCCESS: You're in an isolated environment!")
            print("Safe to install packages without affecting")
            print("the global system.")
            print()

            print("Package installation path:")
            print(site.getsitepackages()[0])
    except Exception as e:
        print(f"Error detecting environment: {e}")
        sys.exit(1)


if __name__ == "__main__":
    check_matrix_status()
# flake8 . --exclude=matrix_env
# RUN: python3 -m venv matrix_env
# python3 ex00/construct.py
# source matrix_env/bin/activate
# clean: find . -type d -name "__pycache__" -exec rm -rf {} +
