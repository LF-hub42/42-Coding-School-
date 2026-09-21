def ft_count_harvest_iterative():
    days = int(input("Days until harvest: "))
    for i in range(1, days + 1):
        # Das 'f' vor dem Text erlaubt es, {i} als Zahl zu benutzen
        print(f"Day {i}")
    print("Harvest time!")
