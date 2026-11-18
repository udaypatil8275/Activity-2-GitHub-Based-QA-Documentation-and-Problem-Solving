# Activity 2 - GitHub-Based QA Documentation and Problem Solving

**Project:** Arduino Uno + LM35 Temperature Monitoring and Alarm (educational code-review exercise)

**Course:** Project Management (2307476T), BTech E&TC, Semester VII, Academic Year 2026-27.

## Project overview
The Arduino reads an LM35 temperature sensor through analog input A0 and controls an alarm indicator at D8. The baseline contains four **intentionally introduced defects** to support a transparent QA exercise. A corrected code version is provided for static comparison. **No hardware, simulation, or compile results are claimed.**

## Files
- `baseline/temperature_monitor_baseline.ino`: intentionally defective example
- `src/temperature_monitor.ino`: reviewed correction
- `docs/QA_PLAN.md`: requirements, acceptance checks, validation plan
- `docs/ROOT_CAUSE_AND_RESOLUTION.md`: four 5-Why analyses and resolution log
- `docs/PROJECT_PLAN.md`: project schedule, risks, tracking

## QA workflow
Baseline -> identify issues -> analyze root cause -> implement code changes -> review diff -> validate (future) -> close issues with evidence. GitHub Issues and pull requests provide traceability.

## Constraints
This is a documentation/code-only activity. The revised code is **not verified on an Arduino**. An unplugged LM35 may produce a plausible ADC reading, so range checks are not a complete disconnect detector. Actual ADC reference and output driver requirements depend on hardware.

## Report
See Moodle report artifact prepared separately. Link GitHub issues and pull requests as evidence; do not represent proposed checks as completed tests.
