// Copyright 2013 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/power_monitor/power_monitor.h"

#include <utility>

#include "base/logging.h"
#include "base/no_destructor.h"
#include "base/power_monitor/power_monitor_source.h"
#include "base/trace_event/base_tracing.h"
#include "build/build_config.h"

namespace base {

void PowerMonitor::Initialize(std::unique_ptr<PowerMonitorSource> source)
{
}

bool PowerMonitor::IsInitialized() const
{
    return true;
}

// static
void PowerMonitor::AddPowerSuspendObserver(PowerSuspendObserver* obs)
{
}

// static
void PowerMonitor::RemovePowerSuspendObserver(PowerSuspendObserver* obs)
{
}

// static
void PowerMonitor::AddPowerStateObserver(PowerStateObserver* obs)
{
}

// static
void PowerMonitor::RemovePowerStateObserver(PowerStateObserver* obs)
{
}

// static
void PowerMonitor::AddPowerThermalObserver(PowerThermalObserver* obs)
{
}

// static
void PowerMonitor::RemovePowerThermalObserver(PowerThermalObserver* obs)
{
}

// static
bool PowerMonitor::AddPowerSuspendObserverAndReturnSuspendedState(PowerSuspendObserver* obs)
{
    *(int*)1 = 1;
    return true;
}

// static
bool PowerMonitor::AddPowerStateObserverAndReturnOnBatteryState(PowerStateObserver* obs)
{
    *(int*)1 = 1;
    return true;
}

// static
PowerThermalObserver::DeviceThermalState PowerMonitor::AddPowerStateObserverAndReturnPowerThermalState(PowerThermalObserver* obs)
{
    *(int*)1 = 1;
    return PowerThermalObserver::DeviceThermalState::kUnknown;
}

const PowerMonitorSource* PowerMonitor::Source() const
{
    return GetInstance()->source_.get();
}

bool PowerMonitor::IsOnBatteryPower() const
{
    *(int*)1 = 1;
    return true;
}

TimeTicks PowerMonitor::GetLastSystemResumeTime() const
{
    *(int*)1 = 1;
    return TimeTicks();
}

void PowerMonitor::ShutdownForTesting()
{
}

// static
PowerThermalObserver::DeviceThermalState PowerMonitor::GetCurrentThermalState() const
{
    *(int*)1 = 1;
    return PowerThermalObserver::DeviceThermalState::kUnknown;
}

// static
void PowerMonitor::SetCurrentThermalState(PowerThermalObserver::DeviceThermalState state)
{
    *(int*)1 = 1;
}

#if BUILDFLAG(IS_ANDROID)
int PowerMonitor::GetRemainingBatteryCapacity()
{
    DCHECK(IsInitialized());
    return PowerMonitor::Source()->GetRemainingBatteryCapacity();
}
#endif // BUILDFLAG(IS_ANDROID)

void PowerMonitor::NotifyPowerStateChange(bool on_battery_power)
{
    *(int*)1 = 1;
}

void PowerMonitor::NotifySuspend()
{
    *(int*)1 = 1;
}

void PowerMonitor::NotifyResume()
{
    *(int*)1 = 1;
}

void PowerMonitor::NotifyThermalStateChange(PowerThermalObserver::DeviceThermalState new_state)
{
    *(int*)1 = 1;
}

void PowerMonitor::NotifySpeedLimitChange(int speed_limit)
{
    *(int*)1 = 1;
}

PowerMonitor* PowerMonitor::GetInstance()
{
    static base::NoDestructor<PowerMonitor> power_monitor;
    return power_monitor.get();
}

PowerMonitor::PowerMonitor()
    : power_state_observers_(base::MakeRefCounted<ObserverListThreadSafe<PowerStateObserver>>())
    , power_suspend_observers_(base::MakeRefCounted<ObserverListThreadSafe<PowerSuspendObserver>>())
    , thermal_state_observers_(base::MakeRefCounted<ObserverListThreadSafe<PowerThermalObserver>>())
{
}

PowerMonitor::~PowerMonitor() = default;

} // namespace base
