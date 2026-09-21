class Plant:
    """Base class for all plants."""
    def __init__(self, name: str, height: int, age: int):
        self.name = name
        self.height = height
        self.age = age


class Flower(Plant):
    """Flower class inheriting from Plant."""
    def __init__(self, name: str, height: int, age: int, color: str):
        super().__init__(name, height, age)
        self.color = color

    def bloom(self) -> None:
        print(f"{self.name} is blooming beautifully!")

    def get_info(self) -> str:
        return (
            f"{self.name} (Flower): {self.height}cm, "
            f"{self.age} days, {self.color} color"
        )


class Tree(Plant):
    """Tree class inheriting from Plant."""
    def __init__(self, name: str, height: int, age: int, diameter: int):
        super().__init__(name, height, age)
        self.diameter = diameter

    def produce_shade(self) -> None:
        shade = self.diameter * 1.56  # Beispielrechnung für Schatten
        print(f"{self.name} provides {int(shade)} square meters of shade")

    def get_info(self) -> str:
        return (
            f"{self.name} (Tree): {self.height}cm, "
            f"{self.age} days, {self.diameter}cm diameter"
        )


class Vegetable(Plant):
    """Vegetable class inheriting from Plant."""
    def __init__(
        self,
        name: str,
        height: int,
        age: int,
        season: str,
        vitamin: str,
    ):
        super().__init__(name, height, age)
        self.season = season
        self.vitamin = vitamin

    def get_nutritional_value(self) -> None:
        print(f"{self.name} is rich in {self.vitamin}")

    def get_info(self) -> str:
        return (
            f"{self.name} (Vegetable): {self.height}cm, "
            f"{self.age} days, {self.season} harvest"
        )


def main() -> None:
    print("=== Garden Plant Types ===")

    # Jeweils 2 Instanzen erstellen
    rose = Flower("Rose", 25, 30, "red")
    Flower("Tulip", 20, 15, "yellow")
    oak = Tree("Oak", 500, 1825, 50)
    Tree("Pine", 300, 1000, 30)
    tomato = Vegetable("Tomato", 80, 90, "summer", "vitamin C")
    Vegetable("Carrot", 15, 60, "autumn", "vitamin A")

    print(rose.get_info())
    rose.bloom()

    print(oak.get_info())
    oak.produce_shade()

    print(tomato.get_info())
    tomato.get_nutritional_value()


if __name__ == "__main__":
    main()
