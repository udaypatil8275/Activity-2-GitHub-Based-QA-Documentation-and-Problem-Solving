# QA Plan - LM35 Temperature Monitor

**Scope:** Static code review of an Arduino Uno LM35 monitor; no hardware or simulator testing claimed.

## Requirements
R1: Alarm pin configured as output. R2: ADC conversion uses documented 5.0 V reference assumption. R3: Alarm activates at 35 C and clears at 33 C to prevent rapid toggling. R4: Implausible readings are flagged; disconnected sensor detection is **not guaranteed**.

## Review method
Compare `baseline/temperature_monitor_baseline.ino` with `src/temperature_monitor.ino`; trace each requirement to an issue and inspect code. These are **static review observations**, not measured results.

## Planned validation (not performed)
Compile using Arduino Uno board profile; simulate sensor voltages at 0.30, 0.33, 0.35 and 0.36 V; check hysteresis and alarm pin; verify analog reference with a meter; unplug sensor and confirm fault behavior. Sensor disconnect requires a hardware diagnostic strategy beyond range checking.

## Severity scheme
High: alarm/output reliability or incorrect measurement; Medium: noise-induced toggling; Low: documentation.
