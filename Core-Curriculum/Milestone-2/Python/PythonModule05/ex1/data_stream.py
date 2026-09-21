from abc import ABC, abstractmethod
from typing import Any, List, Dict, Union, Optional


class DataStream(ABC):
    """Abstract base class for all data streams."""

    def __init__(self, stream_id: str):
        self.stream_id = stream_id
        self.processed_count = 0

    @abstractmethod
    def process_batch(self, data_batch: List[Any]) -> str:
        """Process a batch of data."""
        pass

    def filter_data(self, data_batch: List[Any],
                    criteria: Optional[str] = None) -> List[Any]:
        """Default filter: returns all data if no criteria is given."""
        return data_batch

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        """Return basic stream statistics."""
        return {
            "id": self.stream_id,
            "count": self.processed_count
        }


class SensorStream(DataStream):
    """Handles environmental sensor data."""

    def process_batch(self, data_batch: List[float]) -> str:
        try:
            self.processed_count += len(data_batch)
            count = len(data_batch)
            avg = sum(data_batch) / count if count > 0 else 0.0
            return f"Sensor analysis: {count} readings, avg: {avg}°C"
        except Exception as e:
            return f"Sensor error: {str(e)}"

    def filter_data(self, data_batch: List[float],
                    criteria: Optional[str] = None) -> List[float]:
        if criteria == "high_temp":
            return [x for x in data_batch if x > 30.0]
        return data_batch


class TransactionStream(DataStream):
    """Handles financial transaction data."""

    def process_batch(self, data_batch: List[Dict[str, Any]]) -> str:
        self.processed_count += len(data_batch)
        net = 0
        for tx in data_batch:
            if tx['type'] == 'buy':
                net -= tx['amount']
            else:
                net += tx['amount']
        return f"Transaction analysis: {len(data_batch)} ops, net: {net}"


class EventStream(DataStream):
    """Handles system events."""

    def process_batch(self, data_batch: List[str]) -> str:
        self.processed_count += len(data_batch)
        errors = [x for x in data_batch if "error" in x.lower()]
        return f"Event analysis: {len(data_batch)} events, {len(errors)} errs"


class StreamProcessor:
    """Orchestrates multiple streams polymorphically."""

    def __init__(self):
        self.streams: List[DataStream] = []

    def add_stream(self, stream: DataStream) -> None:
        self.streams.append(stream)

    def process_all(self, all_data: List[List[Any]]) -> None:
        """Processes mixed stream types through unified interface."""
        print("=== Polymorphic Stream Processing ===")
        for i, stream in enumerate(self.streams):
            if i < len(all_data):
                result = stream.process_batch(all_data[i])
                print(f"- {stream.stream_id}: {result}")


def main() -> None:
    """Demo for polymorphic stream processing."""
    print("=== CODE NEXUS - POLYMORPHIC STREAM SYSTEM ===")

    s_stream = SensorStream("SENSOR_001")
    t_stream = TransactionStream("TRANS_001")
    e_stream = EventStream("EVENT_001")

    sensor_data = [22.5, 31.2, 25.0]
    trans_data = [
        {'type': 'buy', 'amount': 100},
        {'type': 'sell', 'amount': 150}
    ]
    event_data = ["login", "ERROR: disk full", "logout"]

    manager = StreamProcessor()
    manager.add_stream(s_stream)
    manager.add_stream(t_stream)
    manager.add_stream(e_stream)

    manager.process_all([sensor_data, trans_data, event_data])
    print("\nAll streams processed successfully.")


if __name__ == "__main__":
    main()
