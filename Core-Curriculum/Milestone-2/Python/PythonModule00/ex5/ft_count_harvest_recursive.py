def count_to_target(current, target):
    if current > target:
        return
    print(f"Day {current}")
    # Die Funktion ruft sich selbst mit der nächsten Zahl auf
    count_to_target(current + 1, target)

def ft_count_harvest_recursive():
    days = int(input("Days until harvest: "))
    count_to_target(1, days)
    print("Harvest time!")
