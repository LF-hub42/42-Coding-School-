class GardenError(Exception):
    """Base class for all garden-related errors."""
    pass


class WaterError(GardenError):
    """Raised when irrigation parameters are invalid."""
    pass


class PlantError(GardenError):
    """Raised when plant health or naming fails validation."""
    pass


class GardenManager:
    """Manages garden operations with robust error handling."""

    def __init__(self):
        self.plants = []

    def add_plant(self, name: str) -> None:
        """Adds a plant with validation."""
        try:
            if not name:
                raise PlantError("Plant name cannot be empty!")
            self.plants.append(name)
            print(f"Added {name} successfully")
        except PlantError as e:
            print(f"Error adding plant: {e}")

    def water_plants(self) -> None:
        """Waters all plants with guaranteed cleanup."""
        print("Opening watering system")
        try:
            if not self.plants:
                print("No plants to water.")
                return
            for plant in self.plants:
                print(f"Watering {plant} - success")
        finally:
            # Cleanup muss immer passieren, auch wenn oben ein Fehler käme
            print("Closing watering system (cleanup)")

    def check_health(self, plant: str, water: int, sun: int) -> None:
        """Validates health and handles specific agricultural errors."""
        try:
            if water > 10:
                raise WaterError(f"Water level {water} is too high (max 10)")
            if sun < 2:
                raise PlantError(f"Sunlight hours {sun} is too low (min 2)")
            print(f"{plant}: healthy (water: {water}, sun: {sun})")
        except (WaterError, PlantError) as e:
            print(f"Error checking {plant}: {e}")


def test_garden_management() -> None:
    """Demonstrates a resilient garden management system."""
    print("=== Garden Management System ===")
    gm = GardenManager()

    # 1. Adding plants
    print("Adding plants to garden...")
    gm.add_plant("tomato")
    gm.add_plant("lettuce")
    gm.add_plant("")  # Fehlerfall

    # 2. Watering with finally
    print("\nWatering plants...")
    gm.water_plants()

    # 3. Health checks
    print("\nChecking plant health...")
    gm.check_health("tomato", 5, 8)
    gm.check_health("lettuce", 15, 8)  # Fehlerfall

    # 4. Error Recovery & Custom Exceptions
    print("\nTesting error recovery...")
    try:
        raise GardenError("Not enough water in tank")
    except GardenError as e:
        print(f"Caught GardenError: {e}")
        print("System recovered and continuing...")

    print("\nGarden management system test complete!")


if __name__ == "__main__":
    test_garden_management()
