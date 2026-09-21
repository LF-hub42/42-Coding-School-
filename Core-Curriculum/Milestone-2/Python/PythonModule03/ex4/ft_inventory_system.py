import sys


def process_inventory(args: list[str]) -> None:
    """Manages game inventory using dictionaries."""
    inventory: dict[str, int] = {}

    if len(args) < 2:
        usage = "python3 ft_inventory_system.py item:qty item:qty ..."
        print(f"Usage: {usage}")
        return

    for arg in args[1:]:
        try:
            name, qty = arg.split(":")
            inventory[name] = int(qty)
        except ValueError:
            continue

    total_units = sum(inventory.values())
    print("=== Inventory System Analysis ===")
    print(f"Total items in inventory: {total_units}")
    print(f"Unique item types: {len(inventory)}")

    print("\n=== Current Inventory ===")
    sorted_items = sorted(
        inventory.items(), key=lambda x: x[1], reverse=True
    )
    for item, qty in sorted_items:
        perc = (qty / total_units) * 100
        print(f"{item}: {qty} units ({perc:.1f}%)")

    most = max(inventory, key=inventory.get)
    least = min(inventory, key=inventory.get)
    print(f"\nMost abundant: {most} ({inventory[most]} units)")
    print(f"Least abundant: {least} ({inventory[least]} units)")


if __name__ == "__main__":
    process_inventory(sys.argv)
