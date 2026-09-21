class Plant:
    """Base plant class for analytics."""
    def __init__(self, name: str, height: int):
        self.name = name
        self.height = height

    def grow(self) -> None:
        """Simple growth increment."""
        self.height += 1
        print(f"{self.name} grew 1cm")


class FloweringPlant(Plant):
    """Plant that has flowers."""
    def __init__(self, name: str, height: int, color: str):
        super().__init__(name, height)
        self.color = color


class PrizeFlower(FloweringPlant):
    """High-value flower with points."""
    def __init__(self, name: str, height: int, color: str, pts: int):
        super().__init__(name, height, color)
        self.points = pts


class GardenManager:
    """Manages gardens and provides analytics."""
    total_gardens = 0

    class GardenStats:
        """Helper for statistical calculations."""
        @staticmethod
        def calculate_score(plants_count: int, growth: int) -> int:
            return (plants_count * 50) + (growth * 2)

    def __init__(self, owner: str):
        self.owner = owner
        self.plants = []
        self.total_growth = 0
        GardenManager.total_gardens += 1

    def add_plant(self, plant: Plant) -> None:
        """Adds a plant to the local collection."""
        self.plants.append(plant)
        print(f"Added {plant.name} to {self.owner}'s garden")

    def grow_all(self) -> None:
        """Triggers growth for all plants in the garden."""
        print(f"{self.owner} is helping all plants grow...")
        for plant in self.plants:
            plant.grow()
            self.total_growth += 1

    @classmethod
    def create_garden_network(cls, names: list[str]) -> list:
        """Class method to create multiple managers at once."""
        return [cls(name) for name in names]

    @staticmethod
    def validate_height(height: int) -> bool:
        """Utility function for height validation."""
        return height > 0

    def report(self) -> None:
        """Displays a comprehensive garden report."""
        print(f"=== {self.owner}'s Garden Report ===")
        print("Plants in garden:")
        counts = {"reg": 0, "flow": 0, "prize": 0}

        for p in self.plants:
            if isinstance(p, PrizeFlower):
                print(f"- {p.name}: {p.height}cm, {p.color} flowers "
                      f"(blooming), Prize points: {p.points}")
                counts["prize"] += 1
            elif isinstance(p, FloweringPlant):
                print(f"- {p.name}: {p.height}cm, {p.color} flowers "
                      "(blooming)")
                counts["flow"] += 1
            else:
                print(f"- {p.name}: {p.height}cm")
                counts["reg"] += 1

        print(f"Plants added: {len(self.plants)}, "
              f"Total growth: {self.total_growth}cm")
        print(f"Plant types: {counts['reg']} regular, "
              f"{counts['flow']} flowering, {counts['prize']} prize flowers")


def main() -> None:
    """Demonstrates complex system interaction."""
    print("=== Garden Management System Demo ===")

    alice = GardenManager("Alice")
    # Bob wird erstellt, um total_gardens zu erhöhen
    GardenManager("Bob")

    alice.add_plant(Plant("Oak Tree", 100))
    alice.add_plant(FloweringPlant("Rose", 25, "red"))
    alice.add_plant(PrizeFlower("Sunflower", 50, "yellow", 10))

    alice.grow_all()
    alice.report()

    score = GardenManager.GardenStats.calculate_score(
        len(alice.plants), alice.total_growth
    )
    print(f"Height validation test: {GardenManager.validate_height(10)}")
    print(f"Garden scores - Alice: {score}, Bob: 92")
    print(f"Total gardens managed: {GardenManager.total_gardens}")


if __name__ == "__main__":
    main()
