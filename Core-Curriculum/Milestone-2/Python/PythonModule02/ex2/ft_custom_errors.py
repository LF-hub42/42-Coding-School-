class GardenError(Exception):
    """Base class for all exceptions in the garden system."""
    pass


class PlantError(GardenError):
    """Raised when a specific problem with a plant occurs."""
    pass


class WaterError(GardenError):
    """Raised when there is an issue with the irrigation system."""
    pass


def test_custom_errors() -> None:
    """Demonstrates how to raise and catch custom garden exceptions."""
    print("=== Custom Garden Errors Demo ===")

    # 1. Testing PlantError
    print("Testing PlantError...")
    try:
        raise PlantError("The tomato plant is wilting!")
    except PlantError as e:
        print(f"Caught PlantError: {e}")

    # 2. Testing WaterError
    print("Testing WaterError...")
    try:
        raise WaterError("Not enough water in the tank!")
    except WaterError as e:
        print(f"Caught WaterError: {e}")

    # 3. Testing catching all garden errors through the base class
    print("Testing catching all garden errors...")
    errors_to_test = [
        PlantError("The tomato plant is wilting!"),
        WaterError("Not enough water in the tank!")
    ]

    for error in errors_to_test:
        try:
            raise error
        except GardenError as e:
            # Da PlantError und WaterError von GardenError erben,
            # werden sie hier beide abgefangen.
            print(f"Caught a garden error: {e}")

    print("All custom error types work correctly!")


if __name__ == "__main__":
    test_custom_errors()
