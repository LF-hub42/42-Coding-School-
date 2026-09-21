# ft_import_transmutation.py

# Methode 1: Den ganzen "Raum" (Modul) importieren
import alchemy.elements

# Methode 2: Einen gezielten "Gegenstand" (Funktion) herbeirufen
from alchemy.elements import create_water

# Methode 3: Einem Zauberspruch einen Spitznamen (Alias) geben
from alchemy.potions import healing_potion as heal

# Methode 4: Mehrere Dinge gleichzeitig beschwören
from alchemy.elements import create_earth, create_fire
from alchemy.potions import strength_potion


def main() -> None:
    print("=== Import Transmutation Mastery ===")

    print("\nMethod 1 - Full module import:")
    # Hier müssen wir den vollen Pfad nutzen
    print(f"alchemy.elements.create_fire(): {alchemy.elements.create_fire()}")

    print("\nMethod 2 - Specific function import:")
    # Hier nutzen wir die Funktion direkt
    print(f"create_water(): {create_water()}")

    print("\nMethod 3 - Aliased import:")
    # Wir rufen 'heal()' statt 'healing_potion()' auf
    print(f"heal(): {heal()}")

    print("\nMethod 4 - Multiple imports:")
    print(f"create_earth(): {create_earth()}")
    print(f"create_fire(): {create_fire()}")
    print(f"strength_potion(): {strength_potion()}")

    print("\nAll import transmutation methods mastered!")


if __name__ == "__main__":
    main()
# Quick test:
# python3 -c "from alchemy.transmutation import lead_to_gold as l; print(l())"
