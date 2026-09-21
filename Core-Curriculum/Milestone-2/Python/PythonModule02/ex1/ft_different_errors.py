def garden_operations() -> None:
    """Demonstrates handling of various specific error types."""
    # 1. ValueError
    print("Testing ValueError...")
    try:
        int("tomato")
    except ValueError as e:
        print(f"Caught ValueError: {e}")

    # 2. ZeroDivisionError
    print("Testing ZeroDivisionError...")
    try:
        10 / 0
    except ZeroDivisionError as e:
        print(f"Caught ZeroDivisionError: {e}")

    # 3. FileNotFoundError
    print("Testing FileNotFoundError...")
    try:
        open("missing_sensor_data.txt", "r")
    except FileNotFoundError:
        # F541 behoben: normales String statt f-string, da kein {}
        # E501 behoben: Zeile gekürzt
        print("Caught FileNotFoundError: No such file 'missing.txt'")

    # 4. KeyError
    print("Testing KeyError...")
    try:
        garden = {"tomato": "healthy"}
        print(garden["cucumber"])
    except KeyError as e:
        print(f"Caught KeyError: {e}")

    # 5. Multiple Errors
    print("Testing multiple errors together...")
    try:
        # F841 behoben: Variable entfernt, da sie nicht genutzt wurde
        10 / 0
    except (ValueError, ZeroDivisionError, KeyError):
        print("Caught an error, but program continues!")


def test_error_types() -> None:
    """Entry point for testing error scenarios."""
    print("=== Garden Error Types Demo ===")
    garden_operations()
    print("All error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
