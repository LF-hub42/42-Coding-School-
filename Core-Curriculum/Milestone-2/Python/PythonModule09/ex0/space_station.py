from pydantic import BaseModel, Field, ValidationError
from datetime import datetime
from typing import Optional


class SpaceStation(BaseModel):
    """
    Pydantic model for Space Station data validation.
    """
    station_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=1, max_length=50)
    crew_size: int = Field(ge=1, le=20)
    power_level: float = Field(ge=0.0, le=100.0)
    oxygen_level: float = Field(ge=0.0, le=100.0)
    last_maintenance: datetime
    is_operational: bool = True
    notes: Optional[str] = Field(None, max_length=200)


def main() -> None:
    print("Space Station Data Validation")
    print("=" * 40)

    try:
        valid_station = SpaceStation(
            station_id="ISS001",
            name="International Space Station",
            crew_size=6,
            power_level=85.5,
            oxygen_level=92.3,
            last_maintenance="2026-03-25T15:00:00",
            notes="Regular orbit maintenance scheduled."
        )
        print("Valid station created:")
        print(f"ID: {valid_station.station_id}")
        print(f"Name: {valid_station.name}")
        print(f"Crew: {valid_station.crew_size} people")
        print(f"Power: {valid_station.power_level}%")
        print(f"Oxygen: {valid_station.oxygen_level}%")
        status = 'Operational' if valid_station.is_operational else 'Down'
        print(f"Status: {status}")

    except ValidationError as e:
        print(f"Unexpected error: {e}")

    print("=" * 40)
    print("Expected validation error:")
    try:
        SpaceStation(
            station_id="MARS01",
            name="Mars Base Alpha",
            crew_size=25,
            power_level=50.0,
            oxygen_level=40.0,
            last_maintenance=datetime.now()
        )
    except ValidationError as e:
        print(e.errors()[0]['msg'])


if __name__ == "__main__":
    main()
# python3 -m venv .venv
# source .venv/bin/activate
# flake8 . --exclude .venv
# python ex0/space_station.py
# if not installed: pip freeze > requirements.txt
# if not installed: pip install pydantic --no-cache-dir
# clean: rm -rf .venv
