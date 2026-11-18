# Root cause analysis and resolution log

All four defects were intentionally introduced in the educational baseline and identified through code review. No physical test has been performed.

| ID | Severity | 5-Why summary / root cause | Proposed correction | Static review evidence | Status |
|---|---|---|---|---|---|
| QA-01 | High | Alarm may not drive correctly -> pin mode missing -> setup omitted initialization -> no output checklist -> root cause: absent pin initialization requirement | Add pinMode and defined startup LOW | src setup() has both | Code change reviewed; hardware unverified |
| QA-02 | High | Temperature estimate inaccurate -> ADC voltage scaled by 3.3 V -> assumed reference mismatches Uno default -> no board reference documented -> root cause: undocumented ADC reference assumption | Use 5.0 V reference assumption and document verification | src ADC_REFERENCE_V | Code change reviewed; hardware unverified |
| QA-03 | Medium | Alarm chatters near threshold -> single threshold -> noisy samples cross boundary -> no stateful control -> root cause: missing hysteresis requirement | 35 C trip, 33 C clear | src alarmActive and thresholds | Code change reviewed; hardware unverified |
| QA-04 | High | Implausible readings accepted -> no plausibility check -> no fault-handling requirement -> root cause: absent sensor validation policy | Flag out-of-range values; document disconnect detection limitation | src plausible branch | Partial mitigation; disconnect still unverified |

## Resolution policy
Do not mark issues as hardware-verified or closed until their acceptance checks are demonstrated. Link review commits and any future PRs in issue comments. Maintain an explicit distinction between static review and experimental testing.
