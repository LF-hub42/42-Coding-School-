from abc import ABC, abstractmethod
from typing import Any, List, Union


class DataProcessor(ABC):
    """Abstract base class for all data processors in the Nexus."""

    @abstractmethod
    def process(self, data: Any) -> str:
        """Process the data and return a result string."""
        pass

    @abstractmethod
    def validate(self, data: Any) -> bool:
        """Validate if data is appropriate for this processor."""
        pass

    def format_output(self, result: str) -> str:
        """Default implementation for formatting output."""
        return f"Output: {result}"


class NumericProcessor(DataProcessor):
    """Processor for numeric lists."""

    def validate(self, data: Any) -> bool:
        if isinstance(data, list) and all(
            isinstance(x, (int, float)) for x in data
        ):
            print("Validation: Numeric data verified")
            return True
        return False

    def process(self, data: List[Union[int, float]]) -> str:
        count = len(data)
        total = sum(data)
        avg = total / count if count > 0 else 0.0
        return f"Processed {count} numeric values, sum={total}, avg={avg}"


class TextProcessor(DataProcessor):
    """Processor for strings."""

    def validate(self, data: Any) -> bool:
        if isinstance(data, str):
            print("Validation: Text data verified")
            return True
        return False

    def process(self, data: str) -> str:
        chars = len(data)
        words = len(data.split())
        return f"Processed text: {chars} characters, {words} words"


class LogProcessor(DataProcessor):
    """Processor for log entries."""

    def validate(self, data: Any) -> bool:
        is_log = isinstance(data, str) and (
            data.startswith("ERROR") or data.startswith("INFO")
        )
        if is_log:
            print("Validation: Log entry verified")
            return True
        return False

    def process(self, data: str) -> str:
        level = data.split(":")[0]
        msg = data.split(":")[1].strip() if ":" in data else data
        tag = "[ALERT]" if level == "ERROR" else "[INFO]"
        return f"{tag} {level} level detected: {msg}"


def main() -> None:
    """Main entry point for testing processors."""
    print("=== CODE NEXUS - DATA PROCESSOR FOUNDATION ===")

    num_proc = NumericProcessor()
    text_proc = TextProcessor()
    log_proc = LogProcessor()

    data_items = [
        (num_proc, [1, 2, 3, 4, 5], "Numeric Processor"),
        (text_proc, "Hello Nexus World", "Text Processor"),
        (log_proc, "ERROR: Connection timeout", "Log Processor")
    ]

    for proc, val, name in data_items:
        print(f"Initializing {name}...")
        print(f"Processing data: {repr(val)}")
        if proc.validate(val):
            res = proc.process(val)
            print(proc.format_output(res))

    print("\n=== Polymorphic Processing Demo ===")
    print("Processing multiple data types through same interface...")
    mixed_data = [
        (num_proc, [1, 2, 3]),
        (text_proc, "Hello Nexus"),
        (log_proc, "INFO: System ready")
    ]

    for i, (proc, val) in enumerate(mixed_data, 1):
        if proc.validate(val):
            print(f"Result {i}: {proc.process(val)}")

    print("\nFoundation systems online. Nexus ready for advanced streams.")


if __name__ == "__main__":
    main()
