class Plant:
    """A plant that can grow and age through methods."""
    def __init__(self, name: str, height: int, age: int):
        self.name = name
        self.height = height
        self.age = age

    def grow(self, cm: int) -> None:
        """Increases plant height."""
        self.height += cm

    def age_up(self) -> None:
        """Increases plant age."""
        self.age += 1

    def get_info(self) -> str:
        """Returns plant status string."""
        return f"{self.name}: {self.height}cm, {self.age} days old"


def main() -> None:
    """Simulates a week of growth."""
    rose = Plant("Rose", 25, 30)
    initial_height = rose.height

    print("=== Day 1 ===")
    print(rose.get_info())

    for _ in range(6):
        rose.grow(1)
        rose.age_up()

    print("=== Day 7 ===")
    print(rose.get_info())

    growth = rose.height - initial_height
    print(f"Growth this week: +{growth}cm")


if __name__ == "__main__":
    main()
