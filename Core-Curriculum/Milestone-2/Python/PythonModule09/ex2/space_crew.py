from pydantic import BaseModel, Field, ValidationError, model_validator
from datetime import datetime
from enum import Enum
from typing import List


class Rank(str, Enum):
    CADET = "cadet"
    OFFICER = "officer"
    LIEUTENANT = "lieutenant"
    CAPTAIN = "captain"
    COMMANDER = "commander"


class CrewMember(BaseModel):
    """Individual crew member model."""
    member_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=2, max_length=50)
    rank: Rank
    age: int = Field(ge=18, le=80)
    specialization: str = Field(min_length=3, max_length=30)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = True


class SpaceMission(BaseModel):
    """Mission model containing nested CrewMember models."""
    mission_id: str = Field(min_length=5, max_length=15)
    mission_name: str = Field(min_length=3, max_length=100)
    destination: str = Field(min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(ge=1, le=3650)
    crew: List[CrewMember] = Field(min_items=1, max_items=12)
    mission_status: str = "planned"
    budget_millions: float = Field(ge=1.0, le=10000.0)

    @model_validator(mode='after')
    def validate_mission_safety(self) -> 'SpaceMission':
        if not self.mission_id.startswith("M"):
            raise ValueError("Mission ID must start with 'M'")

        leadership_ranks = {Rank.COMMANDER, Rank.CAPTAIN}
        has_leader = any(m.rank in leadership_ranks for m in self.crew)
        if not has_leader:
            raise ValueError("Mission must have a Commander or Captain")

        if self.duration_days > 365:
            exp_members = [m for m in self.crew if m.years_experience >= 5]
            if len(exp_members) < len(self.crew) / 2:
                raise ValueError("Long missions need 50% experienced crew")

        if not all(m.is_active for m in self.crew):
            raise ValueError("All crew members must be active")

        return self


def main() -> None:
    print("Space Mission Crew Validation")
    print("=" * 50)

    try:
        valid_mission = SpaceMission(
            mission_id="M2024_MARS",
            mission_name="Mars Colony Establishment",
            destination="Mars",
            launch_date="2024-12-01T10:00:00",
            duration_days=900,
            budget_millions=2500.0,
            crew=[
                CrewMember(
                    member_id="CMD01", name="Sarah Connor",
                    rank=Rank.COMMANDER, age=45,
                    specialization="Command", years_experience=20
                ),
                CrewMember(
                    member_id="NAV01", name="John Smith",
                    rank=Rank.LIEUTENANT, age=30,
                    specialization="Navigation", years_experience=8
                )
            ]
        )
        print(f"Valid mission: {valid_mission.mission_name}")
    except ValidationError as e:
        print(f"Unexpected error: {e}")

    print("=" * 50)
    print("Expected validation error:")
    try:
        SpaceMission(
            mission_id="M_FAIL_01",
            mission_name="Short Trip",
            destination="Moon",
            launch_date=datetime.now(),
            duration_days=10,
            budget_millions=100.0,
            crew=[
                CrewMember(
                    member_id="CAD01", name="Cadet", rank=Rank.CADET,
                    age=19, specialization="Cleaning", years_experience=0
                )
            ]
        )
    except ValidationError as e:
        print(e.errors()[0]['msg'])


if __name__ == "__main__":
    main()
