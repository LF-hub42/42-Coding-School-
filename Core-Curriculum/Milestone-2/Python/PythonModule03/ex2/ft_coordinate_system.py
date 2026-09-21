import math


def calculate_distance(p1: tuple, p2: tuple) -> float:
    """Calculates Euclidean distance between two 3D points."""
    return math.sqrt(
        (p2[0] - p1[0])**2 +
        (p2[1] - p1[1])**2 +
        (p2[2] - p1[2])**2
    )


def main() -> None:
    """Demonstrates tuple creation, parsing and unpacking."""
    print("=== Game Coordinate System ===")

    pos1 = (10, 20, 5)
    origin = (0, 0, 0)
    print(f"Position created: {pos1}")
    dist1 = calculate_distance(origin, pos1)
    print(f"Distance between {origin} and {pos1}: {dist1:.2f}")

    coord_str = "3,4,0"
    print(f"Parsing coordinates: \"{coord_str}\"")
    try:
        x, y, z = [int(c) for c in coord_str.split(",")]
        pos2 = (x, y, z)
        print(f"Parsed position: {pos2}")
        dist2 = calculate_distance(origin, pos2)
        print(f"Distance between {origin} and {pos2}: {dist2:.1f}")
    except ValueError as e:
        print(f"Error parsing coordinates: {e}")

    print("Unpacking demonstration:")
    px, py, pz = pos2
    print(f"Player at x={px}, y={py}, z={pz}")
    print(f"Coordinates: X={px}, Y={py}, Z={pz}")


if __name__ == "__main__":
    main()
