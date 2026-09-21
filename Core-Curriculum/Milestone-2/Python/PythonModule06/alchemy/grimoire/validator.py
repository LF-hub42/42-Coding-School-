# alchemy/grimoire/validator.py

def validate_ingredients(ingredients: str) -> str:
    elements = ["fire", "water", "earth", "air"]
    # Prüft, ob mindestens ein Element im String vorkommt
    if any(el in ingredients.lower() for el in elements):
        return f"{ingredients} - VALID"
    return f"{ingredients} - INVALID"
