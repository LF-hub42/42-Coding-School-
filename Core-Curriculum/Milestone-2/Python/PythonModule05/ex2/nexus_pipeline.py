from abc import ABC, abstractmethod
from typing import Any, List, Protocol, runtime_checkable


@runtime_checkable
class ProcessingStage(Protocol):
    """Protocol defining what a processing stage must look like."""

    def process(self, data: Any) -> Any:
        ...


class InputStage:
    """Stage for initial data validation."""

    def process(self, data: Any) -> Any:
        print("Stage 1: Input validation and parsing")
        return data


class TransformStage:
    """Stage for data transformation."""

    def process(self, data: Any) -> Any:
        print("Stage 2: Data transformation and enrichment")
        if isinstance(data, dict):
            data["metadata"] = "enriched"
        return data


class OutputStage:
    """Stage for final formatting."""

    def process(self, data: Any) -> Any:
        print("Stage 3: Output formatting and delivery")
        return f"Processed: {data}"


class ProcessingPipeline(ABC):
    """Abstract base class for pipelines managing multiple stages."""

    def __init__(self, pipeline_id: str):
        self.pipeline_id = pipeline_id
        self.stages: List[ProcessingStage] = []

    def add_stage(self, stage: ProcessingStage) -> None:
        """Add a stage that follows the ProcessingStage protocol."""
        self.stages.append(stage)

    @abstractmethod
    def process(self, data: Any) -> Any:
        """To be overridden by specialized adapters."""
        pass


class JSONAdapter(ProcessingPipeline):
    """Adapter specifically for JSON-like dictionary data."""

    def process(self, data: Any) -> Any:
        """Process data through all stages with error handling."""
        print(f"\nProcessing JSON data through pipeline {self.pipeline_id}...")
        current_data = data
        try:
            for stage in self.stages:
                current_data = stage.process(current_data)
            return current_data
        except Exception as e:
            return f"Pipeline Error: {e}"


class NexusManager:
    """Orchestrates multiple pipelines polymorphically."""

    def __init__(self):
        self.pipelines: List[ProcessingPipeline] = []

    def add_pipeline(self, pipeline: ProcessingPipeline) -> None:
        self.pipelines.append(pipeline)

    def run_all(self, data_list: List[Any]) -> None:
        """Executes all pipelines on the provided data."""
        for i, pipeline in enumerate(self.pipelines):
            if i < len(data_list):
                result = pipeline.process(data_list[i])
                print(f"Final Result: {result}")


def main() -> None:
    """Master Pipeline Demo."""
    print("=== CODE NEXUS - ENTERPRISE PIPELINE SYSTEM ===")

    # Setup Stages
    in_stage = InputStage()
    trans_stage = TransformStage()
    out_stage = OutputStage()

    # Setup Pipeline
    json_pipe = JSONAdapter("JSON_CONVERTER_01")
    json_pipe.add_stage(in_stage)
    json_pipe.add_stage(trans_stage)
    json_pipe.add_stage(out_stage)

    # Manager Integration
    nexus = NexusManager()
    nexus.add_pipeline(json_pipe)

    # Execution
    test_data = [{"sensor": "temp", "value": 23.5}]
    nexus.run_all(test_data)

    print("\nNexus Integration complete. All systems operational.")


if __name__ == "__main__":
    main()
