class SecurePlant:
    """Protects data from invalid values using private attributes."""
    def __init__(self, name: str):
        self.name = name
        self.__height = 0
        self.__age = 0

    def set_height(self, height: int) -> None:
        if height < 0:
            print(f"Invalid operation attempted: height {height}cm [REJECTED]")
            print("Security: Negative height rejected")
        else:
            self.__height = height
            print(f"Height updated: {height}cm [OK]")

    def set_age(self, age: int) -> None:
        if age < 0:
            print(f"Invalid operation attempted: age {age} days [REJECTED]")
            print("Security: Negative age rejected")
        else:
            self.__age = age
            print(f"Age updated: {age} days [OK]")

    def get_info(self) -> str:
        return (
            f"Current plant: {self.name} "
            f"({self.__height}cm, {self.__age} days)"
        )


def main() -> None:
    print("=== Garden Security System ===")
    rose = SecurePlant("Rose")
    print(f"Plant created: {rose.name}")

    rose.set_height(25)
    rose.set_age(30)
    rose.set_height(-5)

    print(rose.get_info())


if __name__ == "__main__":
    main()
