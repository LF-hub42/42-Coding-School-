def water_plants(plant_list: list) -> None:
    """
    Simulates watering plants with guaranteed cleanup.

    Args:
        plant_list: A list of plant names to water.
    """
    print("Opening watering system")
    try:
        for plant in plant_list:
            if plant is None:
                # Wir simulieren einen Fehler bei ungültigen Daten
                raise ValueError("Cannot water None - invalid plant!")
            print(f"Watering {plant}")
    except ValueError as e:
        print(f"Error: {e}")
    finally:
        # Dieser Teil wird IMMER ausgeführt
        print("Closing watering system (cleanup)")


def test_watering_system() -> None:
    """Demonstrates the finally block with success and error cases."""
    print("=== Garden Watering System ===")

    # 1. Erfolgreicher Durchlauf
    print("Testing normal watering...")
    water_plants(["tomato", "lettuce", "carrots"])
    print("Watering completed successfully!\n")

    # 2. Durchlauf mit Fehler
    print("Testing with error...")
    water_plants(["tomato", None])
    print("Cleanup always happens, even with errors!")


if __name__ == "__main__":
    test_watering_system()
