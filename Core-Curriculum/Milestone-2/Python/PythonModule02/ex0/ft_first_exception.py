def check_temperature(temp_str: str) -> None:
    """
    Validates a temperature string and handles errors.
    """
    try:
        # 1. Versuch: Umwandlung in eine Zahl
        temp = int(temp_str)

        # 2. Check: Ist die Temperatur im Bereich 0-40?
        if temp < 0:
            print(f"Error: {temp}°C is too cold for plants (min 0°C)")
        elif temp > 40:
            print(f"Error: {temp}°C is too hot for plants (max 40°C)")
        else:
            print(f"Temperature {temp}°C is perfect for plants!")

    except ValueError:
        # Wird ausgelöst, wenn int() fehlschlägt (z.B. bei "abc")
        print(f"Error: '{temp_str}' is not a valid number")


def test_temperature_input() -> None:
    """Tests the validation pipeline with various scenarios."""
    print("=== Garden Temperature Checker ===")

    test_cases = ["25", "abc", "100", "-50"]

    for case in test_cases:
        print(f"Testing temperature: {case}")
        check_temperature(case)

    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature_input()
