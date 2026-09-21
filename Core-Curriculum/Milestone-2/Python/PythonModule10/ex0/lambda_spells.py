from typing import List, Dict


def artifact_sorter(artifacts: List[Dict]) -> List[Dict]:
    """
    Sorts magical artifacts by power level in descending order.
    Uses a lambda function as the sorting key.
    """
    # Use sorted() with a lambda to access the 'power' key
    return sorted(artifacts, key=lambda x: x['power'], reverse=True)


def power_filter(mages: List[Dict], min_power: int) -> List[Dict]:
    """
    Filters mages who have a power level greater than or equal to min_power.
    Uses filter() with a lambda expression.
    """
    # filter() returns an iterator, so we cast it to a list
    return list(filter(lambda m: m['power'] >= min_power, mages))


def spell_transformer(spells: List[str]) -> List[str]:
    """
    Transforms spell names by adding a visual border.
    Example: 'fireball' -> '* fireball *'
    Uses map() with a lambda expression.
    """
    return list(map(lambda s: f"* {s} *", spells))


def mage_stats(mages: List[Dict]) -> Dict:
    """
    Calculates max, min, and average power levels of a list of mages.
    Uses lambdas in combination with max(), min(), and sum().
    """
    if not mages:
        return {'max_power': 0, 'min_power': 0, 'avg_power': 0.0}

    # Extract power levels for calculations
    powers = [m['power'] for m in mages]

    return {
        'max_power': max(powers, key=lambda p: p),
        'min_power': min(powers, key=lambda p: p),
        'avg_power': round(sum(powers) / len(powers), 2)
    }


if __name__ == "__main__":
    # --- Test Suite ---

    # Testing Artifact Sorter
    artifacts = [
        {'name': 'Fire Staff', 'power': 92, 'type': 'Staff'},
        {'name': 'Crystal Orb', 'power': 85, 'type': 'Orb'},
        {'name': 'Wooden Wand', 'power': 10, 'type': 'Wand'}
    ]
    print("Testing artifact sorter...")
    sorted_artifacts = artifact_sorter(artifacts)
    for art in sorted_artifacts:
        print(f"{art['name']} ({art['power']} power) comes before...")

    # Testing Spell Transformer
    spells = ["fireball", "heal", "shield"]
    print("\nTesting spell transformer...")
    transformed = spell_transformer(spells)
    print(" ".join(transformed))

    # Testing Power Filter
    mages = [
        {'name': 'Alex', 'power': 95, 'element': 'Fire'},
        {'name': 'Jordan', 'power': 42, 'element': 'Water'},
        {'name': 'Riley', 'power': 88, 'element': 'Air'}
    ]
    print("\nTesting power filter (min 50)...")
    strong_mages = power_filter(mages, 50)
    for mage in strong_mages:
        print(f"Mage {mage['name']} stays in the guild.")

    # Testing Stats
    print("\nTesting mage stats...")
    stats = mage_stats(mages)
    print(f"Stats: {stats}")
# python3 ex00/lambda_spells.py
