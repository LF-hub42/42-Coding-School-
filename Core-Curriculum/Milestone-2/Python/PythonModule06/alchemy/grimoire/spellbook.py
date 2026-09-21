# alchemy/grimoire/spellbook.py

def record_spell(spell_name: str, ingredients: str) -> str:
    # Das hier ist der "Late Import"
    from .validator import validate_ingredients

    result = validate_ingredients(ingredients)
    if "VALID" in result and "INVALID" not in result:
        return f"Spell recorded: {spell_name} ({result})"
    return f"Spell rejected: {spell_name} ({result})"
