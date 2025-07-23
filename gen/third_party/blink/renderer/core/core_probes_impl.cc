// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   /instrumenting_probes_impl.cc.tmpl
// and input files:
//   core_probes.pidl

#include "third_party/blink/renderer/core/core_probes_inl.h"
#include "third_party/blink/renderer/core/core_probe_sink.h"
#include "third_party/blink/renderer/core/frame\ad_tracker.h"
#include "third_party/blink/renderer/core/frame\animation_frame_timing_monitor.h"
#include "third_party/blink/renderer/core/inspector\devtools_session.h"
#include "third_party/blink/renderer/core/inspector\inspector_animation_agent.h"
#include "third_party/blink/renderer/core/inspector\inspector_audits_agent.h"
#include "third_party/blink/renderer/core/inspector\inspector_css_agent.h"
#include "third_party/blink/renderer/core/inspector\inspector_dom_agent.h"
#include "third_party/blink/renderer/core/inspector\inspector_dom_debugger_agent.h"
#include "third_party/blink/renderer/core/inspector\inspector_dom_snapshot_agent.h"
#include "third_party/blink/renderer/core/inspector\inspector_emulation_agent.h"
#include "third_party/blink/renderer/core/inspector\inspector_event_breakpoints_agent.h"
#include "third_party/blink/renderer/core/inspector\inspector_issue_reporter.h"
#include "third_party/blink/renderer/core/inspector\inspector_layer_tree_agent.h"
#include "third_party/blink/renderer/core/inspector\inspector_log_agent.h"
#include "third_party/blink/renderer/core/inspector\inspector_media_agent.h"
#include "third_party/blink/renderer/core/inspector\inspector_network_agent.h"
#include "third_party/blink/renderer/core/inspector\inspector_overlay_agent.h"
#include "third_party/blink/renderer/core/inspector\inspector_page_agent.h"
#include "third_party/blink/renderer/core/inspector\inspector_performance_agent.h"
#include "third_party/blink/renderer/core/inspector\inspector_performance_timeline_agent.h"
#include "third_party/blink/renderer/core/inspector\inspector_preload_agent.h"
#include "third_party/blink/renderer/core/inspector\inspector_trace_events.h"
#include "third_party/blink/renderer/core/lcp_critical_path_predictor\lcp_script_observer.h"
#include "third_party/blink/renderer/core/frame\performance_monitor.h"
#include "base/synchronization/lock.h"

namespace blink {

namespace {

base::Lock& AgentCountLock()
{
    DEFINE_THREAD_SAFE_STATIC_LOCAL(base::Lock, lock, ());
    return lock;
}

} // namespace

// static
std::atomic<unsigned> CoreProbeSink::s_existingAgents;

CoreProbeSink::CoreProbeSink()
{
}

CoreProbeSink::~CoreProbeSink()
{
    base::AutoLock locker(AgentCountLock());
    if (HasAdTrackers() && --s_numSinksWithAdTracker == 0)
        s_existingAgents &= ~kAdTracker;
    if (HasAnimationFrameTimingMonitors() && --s_numSinksWithAnimationFrameTimingMonitor == 0)
        s_existingAgents &= ~kAnimationFrameTimingMonitor;
    if (HasDevToolsSessions() && --s_numSinksWithDevToolsSession == 0)
        s_existingAgents &= ~kDevToolsSession;
    if (HasInspectorAnimationAgents() && --s_numSinksWithInspectorAnimationAgent == 0)
        s_existingAgents &= ~kInspectorAnimationAgent;
    if (HasInspectorAuditsAgents() && --s_numSinksWithInspectorAuditsAgent == 0)
        s_existingAgents &= ~kInspectorAuditsAgent;
    if (HasInspectorCSSAgents() && --s_numSinksWithInspectorCSSAgent == 0)
        s_existingAgents &= ~kInspectorCSSAgent;
    if (HasInspectorDOMAgents() && --s_numSinksWithInspectorDOMAgent == 0)
        s_existingAgents &= ~kInspectorDOMAgent;
    if (HasInspectorDOMDebuggerAgents() && --s_numSinksWithInspectorDOMDebuggerAgent == 0)
        s_existingAgents &= ~kInspectorDOMDebuggerAgent;
    if (HasInspectorDOMSnapshotAgents() && --s_numSinksWithInspectorDOMSnapshotAgent == 0)
        s_existingAgents &= ~kInspectorDOMSnapshotAgent;
    if (HasInspectorEmulationAgents() && --s_numSinksWithInspectorEmulationAgent == 0)
        s_existingAgents &= ~kInspectorEmulationAgent;
    if (HasInspectorEventBreakpointsAgents() && --s_numSinksWithInspectorEventBreakpointsAgent == 0)
        s_existingAgents &= ~kInspectorEventBreakpointsAgent;
    if (HasInspectorIssueReporters() && --s_numSinksWithInspectorIssueReporter == 0)
        s_existingAgents &= ~kInspectorIssueReporter;
    if (HasInspectorLayerTreeAgents() && --s_numSinksWithInspectorLayerTreeAgent == 0)
        s_existingAgents &= ~kInspectorLayerTreeAgent;
    if (HasInspectorLogAgents() && --s_numSinksWithInspectorLogAgent == 0)
        s_existingAgents &= ~kInspectorLogAgent;
    if (HasInspectorMediaAgents() && --s_numSinksWithInspectorMediaAgent == 0)
        s_existingAgents &= ~kInspectorMediaAgent;
    if (HasInspectorNetworkAgents() && --s_numSinksWithInspectorNetworkAgent == 0)
        s_existingAgents &= ~kInspectorNetworkAgent;
    if (HasInspectorOverlayAgents() && --s_numSinksWithInspectorOverlayAgent == 0)
        s_existingAgents &= ~kInspectorOverlayAgent;
    if (HasInspectorPageAgents() && --s_numSinksWithInspectorPageAgent == 0)
        s_existingAgents &= ~kInspectorPageAgent;
    if (HasInspectorPerformanceAgents() && --s_numSinksWithInspectorPerformanceAgent == 0)
        s_existingAgents &= ~kInspectorPerformanceAgent;
    if (HasInspectorPerformanceTimelineAgents() && --s_numSinksWithInspectorPerformanceTimelineAgent == 0)
        s_existingAgents &= ~kInspectorPerformanceTimelineAgent;
    if (HasInspectorPreloadAgents() && --s_numSinksWithInspectorPreloadAgent == 0)
        s_existingAgents &= ~kInspectorPreloadAgent;
    if (HasInspectorTraceEventss() && --s_numSinksWithInspectorTraceEvents == 0)
        s_existingAgents &= ~kInspectorTraceEvents;
    if (HasLCPScriptObservers() && --s_numSinksWithLCPScriptObserver == 0)
        s_existingAgents &= ~kLCPScriptObserver;
    if (HasPerformanceMonitors() && --s_numSinksWithPerformanceMonitor == 0)
        s_existingAgents &= ~kPerformanceMonitor;
}

// static
unsigned CoreProbeSink::s_numSinksWithAdTracker = 0;

void CoreProbeSink::AddAdTracker(AdTracker* agent)
{
    bool already_had_agent = HasAdTrackers();
    ad_trackers_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithAdTracker == 1)
            s_existingAgents |= kAdTracker;
    }

    DCHECK(HasAgentsGlobal(kAdTracker));
}

void CoreProbeSink::RemoveAdTracker(AdTracker* agent)
{
    if (!HasAdTrackers())
        return;

    ad_trackers_.RemoveAgent(agent);

    if (!HasAdTrackers()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithAdTracker == 0)
            s_existingAgents &= ~kAdTracker;
    }

    if (HasAdTrackers())
        DCHECK(HasAgentsGlobal(kAdTracker));
}

// static
unsigned CoreProbeSink::s_numSinksWithAnimationFrameTimingMonitor = 0;

void CoreProbeSink::AddAnimationFrameTimingMonitor(AnimationFrameTimingMonitor* agent)
{
    bool already_had_agent = HasAnimationFrameTimingMonitors();
    animation_frame_timing_monitors_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithAnimationFrameTimingMonitor == 1)
            s_existingAgents |= kAnimationFrameTimingMonitor;
    }

    DCHECK(HasAgentsGlobal(kAnimationFrameTimingMonitor));
}

void CoreProbeSink::RemoveAnimationFrameTimingMonitor(AnimationFrameTimingMonitor* agent)
{
    if (!HasAnimationFrameTimingMonitors())
        return;

    animation_frame_timing_monitors_.RemoveAgent(agent);

    if (!HasAnimationFrameTimingMonitors()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithAnimationFrameTimingMonitor == 0)
            s_existingAgents &= ~kAnimationFrameTimingMonitor;
    }

    if (HasAnimationFrameTimingMonitors())
        DCHECK(HasAgentsGlobal(kAnimationFrameTimingMonitor));
}

// static
unsigned CoreProbeSink::s_numSinksWithDevToolsSession = 0;

void CoreProbeSink::AddDevToolsSession(DevToolsSession* agent)
{
    bool already_had_agent = HasDevToolsSessions();
    dev_tools_sessions_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithDevToolsSession == 1)
            s_existingAgents |= kDevToolsSession;
    }

    DCHECK(HasAgentsGlobal(kDevToolsSession));
}

void CoreProbeSink::RemoveDevToolsSession(DevToolsSession* agent)
{
    if (!HasDevToolsSessions())
        return;

    dev_tools_sessions_.RemoveAgent(agent);

    if (!HasDevToolsSessions()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithDevToolsSession == 0)
            s_existingAgents &= ~kDevToolsSession;
    }

    if (HasDevToolsSessions())
        DCHECK(HasAgentsGlobal(kDevToolsSession));
}

// static
unsigned CoreProbeSink::s_numSinksWithInspectorAnimationAgent = 0;

void CoreProbeSink::AddInspectorAnimationAgent(InspectorAnimationAgent* agent)
{
    bool already_had_agent = HasInspectorAnimationAgents();
    inspector_animation_agents_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithInspectorAnimationAgent == 1)
            s_existingAgents |= kInspectorAnimationAgent;
    }

    DCHECK(HasAgentsGlobal(kInspectorAnimationAgent));
}

void CoreProbeSink::RemoveInspectorAnimationAgent(InspectorAnimationAgent* agent)
{
    if (!HasInspectorAnimationAgents())
        return;

    inspector_animation_agents_.RemoveAgent(agent);

    if (!HasInspectorAnimationAgents()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithInspectorAnimationAgent == 0)
            s_existingAgents &= ~kInspectorAnimationAgent;
    }

    if (HasInspectorAnimationAgents())
        DCHECK(HasAgentsGlobal(kInspectorAnimationAgent));
}

// static
unsigned CoreProbeSink::s_numSinksWithInspectorAuditsAgent = 0;

void CoreProbeSink::AddInspectorAuditsAgent(InspectorAuditsAgent* agent)
{
    bool already_had_agent = HasInspectorAuditsAgents();
    inspector_audits_agents_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithInspectorAuditsAgent == 1)
            s_existingAgents |= kInspectorAuditsAgent;
    }

    DCHECK(HasAgentsGlobal(kInspectorAuditsAgent));
}

void CoreProbeSink::RemoveInspectorAuditsAgent(InspectorAuditsAgent* agent)
{
    if (!HasInspectorAuditsAgents())
        return;

    inspector_audits_agents_.RemoveAgent(agent);

    if (!HasInspectorAuditsAgents()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithInspectorAuditsAgent == 0)
            s_existingAgents &= ~kInspectorAuditsAgent;
    }

    if (HasInspectorAuditsAgents())
        DCHECK(HasAgentsGlobal(kInspectorAuditsAgent));
}

// static
unsigned CoreProbeSink::s_numSinksWithInspectorCSSAgent = 0;

void CoreProbeSink::AddInspectorCSSAgent(InspectorCSSAgent* agent)
{
    bool already_had_agent = HasInspectorCSSAgents();
    inspector_css_agents_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithInspectorCSSAgent == 1)
            s_existingAgents |= kInspectorCSSAgent;
    }

    DCHECK(HasAgentsGlobal(kInspectorCSSAgent));
}

void CoreProbeSink::RemoveInspectorCSSAgent(InspectorCSSAgent* agent)
{
    if (!HasInspectorCSSAgents())
        return;

    inspector_css_agents_.RemoveAgent(agent);

    if (!HasInspectorCSSAgents()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithInspectorCSSAgent == 0)
            s_existingAgents &= ~kInspectorCSSAgent;
    }

    if (HasInspectorCSSAgents())
        DCHECK(HasAgentsGlobal(kInspectorCSSAgent));
}

// static
unsigned CoreProbeSink::s_numSinksWithInspectorDOMAgent = 0;

void CoreProbeSink::AddInspectorDOMAgent(InspectorDOMAgent* agent)
{
    bool already_had_agent = HasInspectorDOMAgents();
    inspector_dom_agents_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithInspectorDOMAgent == 1)
            s_existingAgents |= kInspectorDOMAgent;
    }

    DCHECK(HasAgentsGlobal(kInspectorDOMAgent));
}

void CoreProbeSink::RemoveInspectorDOMAgent(InspectorDOMAgent* agent)
{
    if (!HasInspectorDOMAgents())
        return;

    inspector_dom_agents_.RemoveAgent(agent);

    if (!HasInspectorDOMAgents()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithInspectorDOMAgent == 0)
            s_existingAgents &= ~kInspectorDOMAgent;
    }

    if (HasInspectorDOMAgents())
        DCHECK(HasAgentsGlobal(kInspectorDOMAgent));
}

// static
unsigned CoreProbeSink::s_numSinksWithInspectorDOMDebuggerAgent = 0;

void CoreProbeSink::AddInspectorDOMDebuggerAgent(InspectorDOMDebuggerAgent* agent)
{
    bool already_had_agent = HasInspectorDOMDebuggerAgents();
    inspector_dom_debugger_agents_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithInspectorDOMDebuggerAgent == 1)
            s_existingAgents |= kInspectorDOMDebuggerAgent;
    }

    DCHECK(HasAgentsGlobal(kInspectorDOMDebuggerAgent));
}

void CoreProbeSink::RemoveInspectorDOMDebuggerAgent(InspectorDOMDebuggerAgent* agent)
{
    if (!HasInspectorDOMDebuggerAgents())
        return;

    inspector_dom_debugger_agents_.RemoveAgent(agent);

    if (!HasInspectorDOMDebuggerAgents()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithInspectorDOMDebuggerAgent == 0)
            s_existingAgents &= ~kInspectorDOMDebuggerAgent;
    }

    if (HasInspectorDOMDebuggerAgents())
        DCHECK(HasAgentsGlobal(kInspectorDOMDebuggerAgent));
}

// static
unsigned CoreProbeSink::s_numSinksWithInspectorDOMSnapshotAgent = 0;

void CoreProbeSink::AddInspectorDOMSnapshotAgent(InspectorDOMSnapshotAgent* agent)
{
    bool already_had_agent = HasInspectorDOMSnapshotAgents();
    inspector_dom_snapshot_agents_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithInspectorDOMSnapshotAgent == 1)
            s_existingAgents |= kInspectorDOMSnapshotAgent;
    }

    DCHECK(HasAgentsGlobal(kInspectorDOMSnapshotAgent));
}

void CoreProbeSink::RemoveInspectorDOMSnapshotAgent(InspectorDOMSnapshotAgent* agent)
{
    if (!HasInspectorDOMSnapshotAgents())
        return;

    inspector_dom_snapshot_agents_.RemoveAgent(agent);

    if (!HasInspectorDOMSnapshotAgents()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithInspectorDOMSnapshotAgent == 0)
            s_existingAgents &= ~kInspectorDOMSnapshotAgent;
    }

    if (HasInspectorDOMSnapshotAgents())
        DCHECK(HasAgentsGlobal(kInspectorDOMSnapshotAgent));
}

// static
unsigned CoreProbeSink::s_numSinksWithInspectorEmulationAgent = 0;

void CoreProbeSink::AddInspectorEmulationAgent(InspectorEmulationAgent* agent)
{
    bool already_had_agent = HasInspectorEmulationAgents();
    inspector_emulation_agents_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithInspectorEmulationAgent == 1)
            s_existingAgents |= kInspectorEmulationAgent;
    }

    DCHECK(HasAgentsGlobal(kInspectorEmulationAgent));
}

void CoreProbeSink::RemoveInspectorEmulationAgent(InspectorEmulationAgent* agent)
{
    if (!HasInspectorEmulationAgents())
        return;

    inspector_emulation_agents_.RemoveAgent(agent);

    if (!HasInspectorEmulationAgents()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithInspectorEmulationAgent == 0)
            s_existingAgents &= ~kInspectorEmulationAgent;
    }

    if (HasInspectorEmulationAgents())
        DCHECK(HasAgentsGlobal(kInspectorEmulationAgent));
}

// static
unsigned CoreProbeSink::s_numSinksWithInspectorEventBreakpointsAgent = 0;

void CoreProbeSink::AddInspectorEventBreakpointsAgent(InspectorEventBreakpointsAgent* agent)
{
    bool already_had_agent = HasInspectorEventBreakpointsAgents();
    inspector_event_breakpoints_agents_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithInspectorEventBreakpointsAgent == 1)
            s_existingAgents |= kInspectorEventBreakpointsAgent;
    }

    DCHECK(HasAgentsGlobal(kInspectorEventBreakpointsAgent));
}

void CoreProbeSink::RemoveInspectorEventBreakpointsAgent(InspectorEventBreakpointsAgent* agent)
{
    if (!HasInspectorEventBreakpointsAgents())
        return;

    inspector_event_breakpoints_agents_.RemoveAgent(agent);

    if (!HasInspectorEventBreakpointsAgents()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithInspectorEventBreakpointsAgent == 0)
            s_existingAgents &= ~kInspectorEventBreakpointsAgent;
    }

    if (HasInspectorEventBreakpointsAgents())
        DCHECK(HasAgentsGlobal(kInspectorEventBreakpointsAgent));
}

// static
unsigned CoreProbeSink::s_numSinksWithInspectorIssueReporter = 0;

void CoreProbeSink::AddInspectorIssueReporter(InspectorIssueReporter* agent)
{
    bool already_had_agent = HasInspectorIssueReporters();
    inspector_issue_reporters_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithInspectorIssueReporter == 1)
            s_existingAgents |= kInspectorIssueReporter;
    }

    DCHECK(HasAgentsGlobal(kInspectorIssueReporter));
}

void CoreProbeSink::RemoveInspectorIssueReporter(InspectorIssueReporter* agent)
{
    if (!HasInspectorIssueReporters())
        return;

    inspector_issue_reporters_.RemoveAgent(agent);

    if (!HasInspectorIssueReporters()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithInspectorIssueReporter == 0)
            s_existingAgents &= ~kInspectorIssueReporter;
    }

    if (HasInspectorIssueReporters())
        DCHECK(HasAgentsGlobal(kInspectorIssueReporter));
}

// static
unsigned CoreProbeSink::s_numSinksWithInspectorLayerTreeAgent = 0;

void CoreProbeSink::AddInspectorLayerTreeAgent(InspectorLayerTreeAgent* agent)
{
    bool already_had_agent = HasInspectorLayerTreeAgents();
    inspector_layer_tree_agents_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithInspectorLayerTreeAgent == 1)
            s_existingAgents |= kInspectorLayerTreeAgent;
    }

    DCHECK(HasAgentsGlobal(kInspectorLayerTreeAgent));
}

void CoreProbeSink::RemoveInspectorLayerTreeAgent(InspectorLayerTreeAgent* agent)
{
    if (!HasInspectorLayerTreeAgents())
        return;

    inspector_layer_tree_agents_.RemoveAgent(agent);

    if (!HasInspectorLayerTreeAgents()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithInspectorLayerTreeAgent == 0)
            s_existingAgents &= ~kInspectorLayerTreeAgent;
    }

    if (HasInspectorLayerTreeAgents())
        DCHECK(HasAgentsGlobal(kInspectorLayerTreeAgent));
}

// static
unsigned CoreProbeSink::s_numSinksWithInspectorLogAgent = 0;

void CoreProbeSink::AddInspectorLogAgent(InspectorLogAgent* agent)
{
    bool already_had_agent = HasInspectorLogAgents();
    inspector_log_agents_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithInspectorLogAgent == 1)
            s_existingAgents |= kInspectorLogAgent;
    }

    DCHECK(HasAgentsGlobal(kInspectorLogAgent));
}

void CoreProbeSink::RemoveInspectorLogAgent(InspectorLogAgent* agent)
{
    if (!HasInspectorLogAgents())
        return;

    inspector_log_agents_.RemoveAgent(agent);

    if (!HasInspectorLogAgents()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithInspectorLogAgent == 0)
            s_existingAgents &= ~kInspectorLogAgent;
    }

    if (HasInspectorLogAgents())
        DCHECK(HasAgentsGlobal(kInspectorLogAgent));
}

// static
unsigned CoreProbeSink::s_numSinksWithInspectorMediaAgent = 0;

void CoreProbeSink::AddInspectorMediaAgent(InspectorMediaAgent* agent)
{
    bool already_had_agent = HasInspectorMediaAgents();
    inspector_media_agents_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithInspectorMediaAgent == 1)
            s_existingAgents |= kInspectorMediaAgent;
    }

    DCHECK(HasAgentsGlobal(kInspectorMediaAgent));
}

void CoreProbeSink::RemoveInspectorMediaAgent(InspectorMediaAgent* agent)
{
    if (!HasInspectorMediaAgents())
        return;

    inspector_media_agents_.RemoveAgent(agent);

    if (!HasInspectorMediaAgents()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithInspectorMediaAgent == 0)
            s_existingAgents &= ~kInspectorMediaAgent;
    }

    if (HasInspectorMediaAgents())
        DCHECK(HasAgentsGlobal(kInspectorMediaAgent));
}

// static
unsigned CoreProbeSink::s_numSinksWithInspectorNetworkAgent = 0;

void CoreProbeSink::AddInspectorNetworkAgent(InspectorNetworkAgent* agent)
{
    bool already_had_agent = HasInspectorNetworkAgents();
    inspector_network_agents_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithInspectorNetworkAgent == 1)
            s_existingAgents |= kInspectorNetworkAgent;
    }

    DCHECK(HasAgentsGlobal(kInspectorNetworkAgent));
}

void CoreProbeSink::RemoveInspectorNetworkAgent(InspectorNetworkAgent* agent)
{
    if (!HasInspectorNetworkAgents())
        return;

    inspector_network_agents_.RemoveAgent(agent);

    if (!HasInspectorNetworkAgents()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithInspectorNetworkAgent == 0)
            s_existingAgents &= ~kInspectorNetworkAgent;
    }

    if (HasInspectorNetworkAgents())
        DCHECK(HasAgentsGlobal(kInspectorNetworkAgent));
}

// static
unsigned CoreProbeSink::s_numSinksWithInspectorOverlayAgent = 0;

void CoreProbeSink::AddInspectorOverlayAgent(InspectorOverlayAgent* agent)
{
    bool already_had_agent = HasInspectorOverlayAgents();
    inspector_overlay_agents_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithInspectorOverlayAgent == 1)
            s_existingAgents |= kInspectorOverlayAgent;
    }

    DCHECK(HasAgentsGlobal(kInspectorOverlayAgent));
}

void CoreProbeSink::RemoveInspectorOverlayAgent(InspectorOverlayAgent* agent)
{
    if (!HasInspectorOverlayAgents())
        return;

    inspector_overlay_agents_.RemoveAgent(agent);

    if (!HasInspectorOverlayAgents()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithInspectorOverlayAgent == 0)
            s_existingAgents &= ~kInspectorOverlayAgent;
    }

    if (HasInspectorOverlayAgents())
        DCHECK(HasAgentsGlobal(kInspectorOverlayAgent));
}

// static
unsigned CoreProbeSink::s_numSinksWithInspectorPageAgent = 0;

void CoreProbeSink::AddInspectorPageAgent(InspectorPageAgent* agent)
{
    bool already_had_agent = HasInspectorPageAgents();
    inspector_page_agents_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithInspectorPageAgent == 1)
            s_existingAgents |= kInspectorPageAgent;
    }

    DCHECK(HasAgentsGlobal(kInspectorPageAgent));
}

void CoreProbeSink::RemoveInspectorPageAgent(InspectorPageAgent* agent)
{
    if (!HasInspectorPageAgents())
        return;

    inspector_page_agents_.RemoveAgent(agent);

    if (!HasInspectorPageAgents()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithInspectorPageAgent == 0)
            s_existingAgents &= ~kInspectorPageAgent;
    }

    if (HasInspectorPageAgents())
        DCHECK(HasAgentsGlobal(kInspectorPageAgent));
}

// static
unsigned CoreProbeSink::s_numSinksWithInspectorPerformanceAgent = 0;

void CoreProbeSink::AddInspectorPerformanceAgent(InspectorPerformanceAgent* agent)
{
    bool already_had_agent = HasInspectorPerformanceAgents();
    inspector_performance_agents_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithInspectorPerformanceAgent == 1)
            s_existingAgents |= kInspectorPerformanceAgent;
    }

    DCHECK(HasAgentsGlobal(kInspectorPerformanceAgent));
}

void CoreProbeSink::RemoveInspectorPerformanceAgent(InspectorPerformanceAgent* agent)
{
    if (!HasInspectorPerformanceAgents())
        return;

    inspector_performance_agents_.RemoveAgent(agent);

    if (!HasInspectorPerformanceAgents()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithInspectorPerformanceAgent == 0)
            s_existingAgents &= ~kInspectorPerformanceAgent;
    }

    if (HasInspectorPerformanceAgents())
        DCHECK(HasAgentsGlobal(kInspectorPerformanceAgent));
}

// static
unsigned CoreProbeSink::s_numSinksWithInspectorPerformanceTimelineAgent = 0;

void CoreProbeSink::AddInspectorPerformanceTimelineAgent(InspectorPerformanceTimelineAgent* agent)
{
    bool already_had_agent = HasInspectorPerformanceTimelineAgents();
    inspector_performance_timeline_agents_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithInspectorPerformanceTimelineAgent == 1)
            s_existingAgents |= kInspectorPerformanceTimelineAgent;
    }

    DCHECK(HasAgentsGlobal(kInspectorPerformanceTimelineAgent));
}

void CoreProbeSink::RemoveInspectorPerformanceTimelineAgent(InspectorPerformanceTimelineAgent* agent)
{
    if (!HasInspectorPerformanceTimelineAgents())
        return;

    inspector_performance_timeline_agents_.RemoveAgent(agent);

    if (!HasInspectorPerformanceTimelineAgents()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithInspectorPerformanceTimelineAgent == 0)
            s_existingAgents &= ~kInspectorPerformanceTimelineAgent;
    }

    if (HasInspectorPerformanceTimelineAgents())
        DCHECK(HasAgentsGlobal(kInspectorPerformanceTimelineAgent));
}

// static
unsigned CoreProbeSink::s_numSinksWithInspectorPreloadAgent = 0;

void CoreProbeSink::AddInspectorPreloadAgent(InspectorPreloadAgent* agent)
{
    bool already_had_agent = HasInspectorPreloadAgents();
    inspector_preload_agents_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithInspectorPreloadAgent == 1)
            s_existingAgents |= kInspectorPreloadAgent;
    }

    DCHECK(HasAgentsGlobal(kInspectorPreloadAgent));
}

void CoreProbeSink::RemoveInspectorPreloadAgent(InspectorPreloadAgent* agent)
{
    if (!HasInspectorPreloadAgents())
        return;

    inspector_preload_agents_.RemoveAgent(agent);

    if (!HasInspectorPreloadAgents()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithInspectorPreloadAgent == 0)
            s_existingAgents &= ~kInspectorPreloadAgent;
    }

    if (HasInspectorPreloadAgents())
        DCHECK(HasAgentsGlobal(kInspectorPreloadAgent));
}

// static
unsigned CoreProbeSink::s_numSinksWithInspectorTraceEvents = 0;

void CoreProbeSink::AddInspectorTraceEvents(InspectorTraceEvents* agent)
{
    bool already_had_agent = HasInspectorTraceEventss();
    inspector_trace_eventss_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithInspectorTraceEvents == 1)
            s_existingAgents |= kInspectorTraceEvents;
    }

    DCHECK(HasAgentsGlobal(kInspectorTraceEvents));
}

void CoreProbeSink::RemoveInspectorTraceEvents(InspectorTraceEvents* agent)
{
    if (!HasInspectorTraceEventss())
        return;

    inspector_trace_eventss_.RemoveAgent(agent);

    if (!HasInspectorTraceEventss()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithInspectorTraceEvents == 0)
            s_existingAgents &= ~kInspectorTraceEvents;
    }

    if (HasInspectorTraceEventss())
        DCHECK(HasAgentsGlobal(kInspectorTraceEvents));
}

// static
unsigned CoreProbeSink::s_numSinksWithLCPScriptObserver = 0;

void CoreProbeSink::AddLCPScriptObserver(LCPScriptObserver* agent)
{
    bool already_had_agent = HasLCPScriptObservers();
    lcp_script_observers_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithLCPScriptObserver == 1)
            s_existingAgents |= kLCPScriptObserver;
    }

    DCHECK(HasAgentsGlobal(kLCPScriptObserver));
}

void CoreProbeSink::RemoveLCPScriptObserver(LCPScriptObserver* agent)
{
    if (!HasLCPScriptObservers())
        return;

    lcp_script_observers_.RemoveAgent(agent);

    if (!HasLCPScriptObservers()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithLCPScriptObserver == 0)
            s_existingAgents &= ~kLCPScriptObserver;
    }

    if (HasLCPScriptObservers())
        DCHECK(HasAgentsGlobal(kLCPScriptObserver));
}

// static
unsigned CoreProbeSink::s_numSinksWithPerformanceMonitor = 0;

void CoreProbeSink::AddPerformanceMonitor(PerformanceMonitor* agent)
{
    bool already_had_agent = HasPerformanceMonitors();
    performance_monitors_.AddAgent(agent);

    if (!already_had_agent) {
        base::AutoLock locker(AgentCountLock());
        if (++s_numSinksWithPerformanceMonitor == 1)
            s_existingAgents |= kPerformanceMonitor;
    }

    DCHECK(HasAgentsGlobal(kPerformanceMonitor));
}

void CoreProbeSink::RemovePerformanceMonitor(PerformanceMonitor* agent)
{
    if (!HasPerformanceMonitors())
        return;

    performance_monitors_.RemoveAgent(agent);

    if (!HasPerformanceMonitors()) {
        base::AutoLock locker(AgentCountLock());
        if (--s_numSinksWithPerformanceMonitor == 0)
            s_existingAgents &= ~kPerformanceMonitor;
    }

    if (HasPerformanceMonitors())
        DCHECK(HasAgentsGlobal(kPerformanceMonitor));
}

void CoreProbeSink::Trace(Visitor* visitor) const
{
    visitor->Trace(ad_trackers_);
    visitor->Trace(animation_frame_timing_monitors_);
    visitor->Trace(dev_tools_sessions_);
    visitor->Trace(inspector_animation_agents_);
    visitor->Trace(inspector_audits_agents_);
    visitor->Trace(inspector_css_agents_);
    visitor->Trace(inspector_dom_agents_);
    visitor->Trace(inspector_dom_debugger_agents_);
    visitor->Trace(inspector_dom_snapshot_agents_);
    visitor->Trace(inspector_emulation_agents_);
    visitor->Trace(inspector_event_breakpoints_agents_);
    visitor->Trace(inspector_issue_reporters_);
    visitor->Trace(inspector_layer_tree_agents_);
    visitor->Trace(inspector_log_agents_);
    visitor->Trace(inspector_media_agents_);
    visitor->Trace(inspector_network_agents_);
    visitor->Trace(inspector_overlay_agents_);
    visitor->Trace(inspector_page_agents_);
    visitor->Trace(inspector_performance_agents_);
    visitor->Trace(inspector_performance_timeline_agents_);
    visitor->Trace(inspector_preload_agents_);
    visitor->Trace(inspector_trace_eventss_);
    visitor->Trace(lcp_script_observers_);
    visitor->Trace(performance_monitors_);
}

namespace probe {

void DidClearDocumentOfWindowObjectImpl(LocalFrame* param_local_frame)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorAnimationAgents()) {
        probe_sink->InspectorAnimationAgents().ForEachAgent([&](InspectorAnimationAgent* agent) { agent->DidClearDocumentOfWindowObject(param_local_frame); });
    }
}

void DidCreateMainWorldContextImpl(LocalFrame* param_local_frame)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->DidCreateMainWorldContext(param_local_frame); });
    }
}

void WillInsertDOMNodeImpl(Node* parent)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(parent);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMDebuggerAgents()) {
        probe_sink->InspectorDOMDebuggerAgents().ForEachAgent([&](InspectorDOMDebuggerAgent* agent) { agent->WillInsertDOMNode(parent); });
    }
}

void DidInsertDOMNodeImpl(Node* param_node)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_node);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMAgents()) {
        probe_sink->InspectorDOMAgents().ForEachAgent([&](InspectorDOMAgent* agent) { agent->DidInsertDOMNode(param_node); });
    }
    if (probe_sink->HasInspectorDOMDebuggerAgents()) {
        probe_sink->InspectorDOMDebuggerAgents().ForEachAgent([&](InspectorDOMDebuggerAgent* agent) { agent->DidInsertDOMNode(param_node); });
    }
    if (probe_sink->HasInspectorDOMSnapshotAgents()) {
        probe_sink->InspectorDOMSnapshotAgents().ForEachAgent([&](InspectorDOMSnapshotAgent* agent) { agent->DidInsertDOMNode(param_node); });
    }
}

void WillRemoveDOMNodeImpl(Node* param_node)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_node);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMAgents()) {
        probe_sink->InspectorDOMAgents().ForEachAgent([&](InspectorDOMAgent* agent) { agent->WillRemoveDOMNode(param_node); });
    }
}

void WillModifyDOMAttrImpl(Element* param_element, const AtomicString& old_value, const AtomicString& new_value)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_element);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMAgents()) {
        probe_sink->InspectorDOMAgents().ForEachAgent([&](InspectorDOMAgent* agent) { agent->WillModifyDOMAttr(param_element, old_value, new_value); });
    }
    if (probe_sink->HasInspectorDOMDebuggerAgents()) {
        probe_sink->InspectorDOMDebuggerAgents().ForEachAgent(
            [&](InspectorDOMDebuggerAgent* agent) { agent->WillModifyDOMAttr(param_element, old_value, new_value); });
    }
}

void DidModifyDOMAttrImpl(Element* param_element, const QualifiedName& name, const AtomicString& value)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_element);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMAgents()) {
        probe_sink->InspectorDOMAgents().ForEachAgent([&](InspectorDOMAgent* agent) { agent->DidModifyDOMAttr(param_element, name, value); });
    }
}

void DidRemoveDOMAttrImpl(Element* param_element, const QualifiedName& name)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_element);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMAgents()) {
        probe_sink->InspectorDOMAgents().ForEachAgent([&](InspectorDOMAgent* agent) { agent->DidRemoveDOMAttr(param_element, name); });
    }
}

void WillChangeStyleElementImpl(Element* param_element)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_element);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorCSSAgents()) {
        probe_sink->InspectorCSSAgents().ForEachAgent([&](InspectorCSSAgent* agent) { agent->WillChangeStyleElement(param_element); });
    }
}

void CharacterDataModifiedImpl(CharacterData* param_character_data)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_character_data);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMAgents()) {
        probe_sink->InspectorDOMAgents().ForEachAgent([&](InspectorDOMAgent* agent) { agent->CharacterDataModified(param_character_data); });
    }
    if (probe_sink->HasInspectorDOMDebuggerAgents()) {
        probe_sink->InspectorDOMDebuggerAgents().ForEachAgent([&](InspectorDOMDebuggerAgent* agent) { agent->CharacterDataModified(param_character_data); });
    }
    if (probe_sink->HasInspectorDOMSnapshotAgents()) {
        probe_sink->InspectorDOMSnapshotAgents().ForEachAgent([&](InspectorDOMSnapshotAgent* agent) { agent->CharacterDataModified(param_character_data); });
    }
}

void DidInvalidateStyleAttrImpl(Node* param_node)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_node);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMAgents()) {
        probe_sink->InspectorDOMAgents().ForEachAgent([&](InspectorDOMAgent* agent) { agent->DidInvalidateStyleAttr(param_node); });
    }
    if (probe_sink->HasInspectorDOMDebuggerAgents()) {
        probe_sink->InspectorDOMDebuggerAgents().ForEachAgent([&](InspectorDOMDebuggerAgent* agent) { agent->DidInvalidateStyleAttr(param_node); });
    }
}

void DidPerformSlotDistributionImpl(HTMLSlotElement* param_html_slot_element)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_html_slot_element);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMAgents()) {
        probe_sink->InspectorDOMAgents().ForEachAgent([&](InspectorDOMAgent* agent) { agent->DidPerformSlotDistribution(param_html_slot_element); });
    }
}

void DocumentDetachedImpl(Document* param_document)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_document);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorCSSAgents()) {
        probe_sink->InspectorCSSAgents().ForEachAgent([&](InspectorCSSAgent* agent) { agent->DocumentDetached(param_document); });
    }
}

void ActiveStyleSheetsUpdatedImpl(Document* param_document)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_document);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorCSSAgents()) {
        probe_sink->InspectorCSSAgents().ForEachAgent([&](InspectorCSSAgent* agent) { agent->ActiveStyleSheetsUpdated(param_document); });
    }
}

void FontsUpdatedImpl(
    ExecutionContext* param_execution_context, const FontFace* face, const String& src, const FontCustomPlatformData* font_custom_platform_data)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorCSSAgents()) {
        probe_sink->InspectorCSSAgents().ForEachAgent([&](InspectorCSSAgent* agent) { agent->FontsUpdated(face, src, font_custom_platform_data); });
    }
}

void MediaQueryResultChangedImpl(Document* param_document)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_document);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorCSSAgents()) {
        probe_sink->InspectorCSSAgents().ForEachAgent([&](InspectorCSSAgent* agent) { agent->MediaQueryResultChanged(); });
    }
}

void DidPushShadowRootImpl(Element* host, ShadowRoot* param_shadow_root)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(host);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMAgents()) {
        probe_sink->InspectorDOMAgents().ForEachAgent([&](InspectorDOMAgent* agent) { agent->DidPushShadowRoot(host, param_shadow_root); });
    }
}

void WillPopShadowRootImpl(Element* host, ShadowRoot* param_shadow_root)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(host);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMAgents()) {
        probe_sink->InspectorDOMAgents().ForEachAgent([&](InspectorDOMAgent* agent) { agent->WillPopShadowRoot(host, param_shadow_root); });
    }
}

void WillSendXMLHttpOrFetchNetworkRequestImpl(ExecutionContext* param_execution_context, const String& url)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMDebuggerAgents()) {
        probe_sink->InspectorDOMDebuggerAgents().ForEachAgent([&](InspectorDOMDebuggerAgent* agent) { agent->WillSendXMLHttpOrFetchNetworkRequest(url); });
    }
}

void DidCreateCanvasContextImpl(Document* param_document)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_document);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorEventBreakpointsAgents()) {
        probe_sink->InspectorEventBreakpointsAgents().ForEachAgent([&](InspectorEventBreakpointsAgent* agent) { agent->DidCreateCanvasContext(); });
    }
}

void DidCreateOffscreenCanvasContextImpl(OffscreenCanvas* param_offscreen_canvas)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_offscreen_canvas);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorEventBreakpointsAgents()) {
        probe_sink->InspectorEventBreakpointsAgents().ForEachAgent([&](InspectorEventBreakpointsAgent* agent) { agent->DidCreateOffscreenCanvasContext(); });
    }
}

void DidFireWebGLErrorImpl(Element* param_element, const String& error_name)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_element);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorEventBreakpointsAgents()) {
        probe_sink->InspectorEventBreakpointsAgents().ForEachAgent([&](InspectorEventBreakpointsAgent* agent) { agent->DidFireWebGLError(error_name); });
    }
}

void DidFireWebGLWarningImpl(Element* param_element)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_element);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorEventBreakpointsAgents()) {
        probe_sink->InspectorEventBreakpointsAgents().ForEachAgent([&](InspectorEventBreakpointsAgent* agent) { agent->DidFireWebGLWarning(); });
    }
}

void DidFireWebGLErrorOrWarningImpl(Element* param_element, const String& message)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_element);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorEventBreakpointsAgents()) {
        probe_sink->InspectorEventBreakpointsAgents().ForEachAgent([&](InspectorEventBreakpointsAgent* agent) { agent->DidFireWebGLErrorOrWarning(message); });
    }
}

void DidResizeMainFrameImpl(LocalFrame* param_local_frame)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->DidResizeMainFrame(); });
    }
}

void ApplyAcceptLanguageOverrideImpl(ExecutionContext* param_execution_context, String* accept_language)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorEmulationAgents()) {
        probe_sink->InspectorEmulationAgents().ForEachAgent([&](InspectorEmulationAgent* agent) { agent->ApplyAcceptLanguageOverride(accept_language); });
    }
}

void ApplyAcceptLanguageOverrideImpl(CoreProbeSink* param_core_probe_sink, String* accept_language)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_core_probe_sink);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorEmulationAgents()) {
        probe_sink->InspectorEmulationAgents().ForEachAgent([&](InspectorEmulationAgent* agent) { agent->ApplyAcceptLanguageOverride(accept_language); });
    }
}

void ApplyHardwareConcurrencyOverrideImpl(CoreProbeSink* param_core_probe_sink, unsigned int& hardware_concurrency)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_core_probe_sink);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorEmulationAgents()) {
        probe_sink->InspectorEmulationAgents().ForEachAgent(
            [&](InspectorEmulationAgent* agent) { agent->ApplyHardwareConcurrencyOverride(hardware_concurrency); });
    }
}

void ApplyUserAgentOverrideImpl(CoreProbeSink* param_core_probe_sink, String* user_agent)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_core_probe_sink);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorEmulationAgents()) {
        probe_sink->InspectorEmulationAgents().ForEachAgent([&](InspectorEmulationAgent* agent) { agent->ApplyUserAgentOverride(user_agent); });
    }
}

void ApplyUserAgentMetadataOverrideImpl(CoreProbeSink* param_core_probe_sink, std::optional<blink::UserAgentMetadata>* ua_metadata_override)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_core_probe_sink);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorEmulationAgents()) {
        probe_sink->InspectorEmulationAgents().ForEachAgent(
            [&](InspectorEmulationAgent* agent) { agent->ApplyUserAgentMetadataOverride(ua_metadata_override); });
    }
}

void DidBlockRequestImpl(CoreProbeSink* param_core_probe_sink, const ResourceRequest& param_resource_request, DocumentLoader* param_document_loader,
    const KURL& fetch_context_url, const ResourceLoaderOptions& param_resource_loader_options,
    ResourceRequestBlockedReason param_resource_request_blocked_reason, ResourceType param_resource_type)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_core_probe_sink);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent([&](InspectorNetworkAgent* agent) {
            agent->DidBlockRequest(param_resource_request, param_document_loader, fetch_context_url, param_resource_loader_options,
                param_resource_request_blocked_reason, param_resource_type);
        });
    }
}

void DidChangeResourcePriorityImpl(
    LocalFrame* param_local_frame, DocumentLoader* param_document_loader, uint64_t identifier, ResourceLoadPriority load_priority)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent(
            [&](InspectorNetworkAgent* agent) { agent->DidChangeResourcePriority(param_document_loader, identifier, load_priority); });
    }
}

void PrepareRequestImpl(CoreProbeSink* param_core_probe_sink, DocumentLoader* param_document_loader, ResourceRequest& param_resource_request,
    ResourceLoaderOptions& param_resource_loader_options, ResourceType param_resource_type)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_core_probe_sink);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorEmulationAgents()) {
        probe_sink->InspectorEmulationAgents().ForEachAgent([&](InspectorEmulationAgent* agent) {
            agent->PrepareRequest(param_document_loader, param_resource_request, param_resource_loader_options, param_resource_type);
        });
    }
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent([&](InspectorNetworkAgent* agent) {
            agent->PrepareRequest(param_document_loader, param_resource_request, param_resource_loader_options, param_resource_type);
        });
    }
}

void WillSendRequestImpl(ExecutionContext* param_execution_context, DocumentLoader* param_document_loader, const KURL& fetch_context_url,
    const ResourceRequest& param_resource_request, const ResourceResponse& redirect_response, const ResourceLoaderOptions& param_resource_loader_options,
    ResourceType param_resource_type, RenderBlockingBehavior param_render_blocking_behavior, base::TimeTicks timestamp)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent([&](InspectorNetworkAgent* agent) {
            agent->WillSendRequest(param_execution_context, param_document_loader, fetch_context_url, param_resource_request, redirect_response,
                param_resource_loader_options, param_resource_type, param_render_blocking_behavior, timestamp);
        });
    }
    if (probe_sink->HasInspectorTraceEventss()) {
        probe_sink->InspectorTraceEventss().ForEachAgent([&](InspectorTraceEvents* agent) {
            agent->WillSendRequest(param_execution_context, param_document_loader, fetch_context_url, param_resource_request, redirect_response,
                param_resource_loader_options, param_resource_type, param_render_blocking_behavior, timestamp);
        });
    }
}

void WillSendNavigationRequestImpl(CoreProbeSink* param_core_probe_sink, uint64_t identifier, DocumentLoader* param_document_loader, const KURL& param_kurl,
    const AtomicString& http_method, EncodedFormData* param_encoded_form_data)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_core_probe_sink);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent([&](InspectorNetworkAgent* agent) {
            agent->WillSendNavigationRequest(identifier, param_document_loader, param_kurl, http_method, param_encoded_form_data);
        });
    }
    if (probe_sink->HasInspectorTraceEventss()) {
        probe_sink->InspectorTraceEventss().ForEachAgent([&](InspectorTraceEvents* agent) {
            agent->WillSendNavigationRequest(identifier, param_document_loader, param_kurl, http_method, param_encoded_form_data);
        });
    }
}

void MarkResourceAsCachedImpl(LocalFrame* param_local_frame, DocumentLoader* param_document_loader, uint64_t identifier)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent(
            [&](InspectorNetworkAgent* agent) { agent->MarkResourceAsCached(param_document_loader, identifier); });
    }
    if (probe_sink->HasInspectorTraceEventss()) {
        probe_sink->InspectorTraceEventss().ForEachAgent([&](InspectorTraceEvents* agent) { agent->MarkResourceAsCached(param_document_loader, identifier); });
    }
}

void DidReceiveResourceResponseImpl(CoreProbeSink* param_core_probe_sink, uint64_t identifier, DocumentLoader* param_document_loader,
    const ResourceResponse& param_resource_response, const Resource* param_resource)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_core_probe_sink);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent([&](InspectorNetworkAgent* agent) {
            agent->DidReceiveResourceResponse(identifier, param_document_loader, param_resource_response, param_resource);
        });
    }
    if (probe_sink->HasInspectorTraceEventss()) {
        probe_sink->InspectorTraceEventss().ForEachAgent([&](InspectorTraceEvents* agent) {
            agent->DidReceiveResourceResponse(identifier, param_document_loader, param_resource_response, param_resource);
        });
    }
}

void DidReceiveDataImpl(CoreProbeSink* param_core_probe_sink, uint64_t identifier, DocumentLoader* param_document_loader, base::SpanOrSize<const char> data)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_core_probe_sink);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent(
            [&](InspectorNetworkAgent* agent) { agent->DidReceiveData(identifier, param_document_loader, data); });
    }
    if (probe_sink->HasInspectorTraceEventss()) {
        probe_sink->InspectorTraceEventss().ForEachAgent([&](InspectorTraceEvents* agent) { agent->DidReceiveData(identifier, param_document_loader, data); });
    }
}

void DidReceiveBlobImpl(
    CoreProbeSink* param_core_probe_sink, uint64_t identifier, DocumentLoader* param_document_loader, BlobDataHandle* param_blob_data_handle)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_core_probe_sink);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent(
            [&](InspectorNetworkAgent* agent) { agent->DidReceiveBlob(identifier, param_document_loader, param_blob_data_handle); });
    }
}

void DidReceiveEncodedDataLengthImpl(CoreProbeSink* param_core_probe_sink, DocumentLoader* loader, uint64_t identifier, size_t encoded_data_length)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_core_probe_sink);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent(
            [&](InspectorNetworkAgent* agent) { agent->DidReceiveEncodedDataLength(loader, identifier, encoded_data_length); });
    }
}

void DidFinishLoadingImpl(CoreProbeSink* param_core_probe_sink, uint64_t identifier, DocumentLoader* param_document_loader, base::TimeTicks finish_time,
    int64_t encoded_data_length, int64_t decoded_body_length)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_core_probe_sink);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent([&](InspectorNetworkAgent* agent) {
            agent->DidFinishLoading(identifier, param_document_loader, finish_time, encoded_data_length, decoded_body_length);
        });
    }
    if (probe_sink->HasInspectorTraceEventss()) {
        probe_sink->InspectorTraceEventss().ForEachAgent([&](InspectorTraceEvents* agent) {
            agent->DidFinishLoading(identifier, param_document_loader, finish_time, encoded_data_length, decoded_body_length);
        });
    }
}

void DidReceiveCorsRedirectResponseImpl(ExecutionContext* param_execution_context, uint64_t identifier, DocumentLoader* param_document_loader,
    const ResourceResponse& param_resource_response, Resource* param_resource)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent([&](InspectorNetworkAgent* agent) {
            agent->DidReceiveCorsRedirectResponse(identifier, param_document_loader, param_resource_response, param_resource);
        });
    }
}

void DidFailLoadingImpl(CoreProbeSink* param_core_probe_sink, uint64_t identifier, DocumentLoader* param_document_loader,
    const ResourceError& param_resource_error, const base::UnguessableToken& param_base)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_core_probe_sink);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorIssueReporters()) {
        probe_sink->InspectorIssueReporters().ForEachAgent([&](InspectorIssueReporter* agent) {
            agent->DidFailLoading(param_core_probe_sink, identifier, param_document_loader, param_resource_error, param_base);
        });
    }
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent([&](InspectorNetworkAgent* agent) {
            agent->DidFailLoading(param_core_probe_sink, identifier, param_document_loader, param_resource_error, param_base);
        });
    }
    if (probe_sink->HasInspectorTraceEventss()) {
        probe_sink->InspectorTraceEventss().ForEachAgent([&](InspectorTraceEvents* agent) {
            agent->DidFailLoading(param_core_probe_sink, identifier, param_document_loader, param_resource_error, param_base);
        });
    }
}

void WillSendEventSourceRequestImpl(ExecutionContext* param_execution_context)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent([&](InspectorNetworkAgent* agent) { agent->WillSendEventSourceRequest(); });
    }
}

void WillDispatchEventSourceEventImpl(
    ExecutionContext* param_execution_context, uint64_t identifier, const AtomicString& event_name, const AtomicString& event_id, const String& data)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent(
            [&](InspectorNetworkAgent* agent) { agent->WillDispatchEventSourceEvent(identifier, event_name, event_id, data); });
    }
}

void WillLoadXHRImpl(
    ExecutionContext* param_execution_context, const AtomicString& method, const KURL& url, bool async, const HTTPHeaderMap& headers, bool include_credentials)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent(
            [&](InspectorNetworkAgent* agent) { agent->WillLoadXHR(param_execution_context, method, url, async, headers, include_credentials); });
    }
}

void DidFinishXHRImpl(ExecutionContext* param_execution_context, XMLHttpRequest* xhr)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent([&](InspectorNetworkAgent* agent) { agent->DidFinishXHR(xhr); });
    }
}

void DidFinishSyncXHRImpl(ExecutionContext* context, const base::TimeDelta blocking_time)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(context);
    if (!probe_sink)
        return;
    if (probe_sink->HasAnimationFrameTimingMonitors()) {
        probe_sink->AnimationFrameTimingMonitors().ForEachAgent([&](AnimationFrameTimingMonitor* agent) { agent->DidFinishSyncXHR(blocking_time); });
    }
}

void ScriptImportedImpl(ExecutionContext* param_execution_context, uint64_t identifier, const String& source_string)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent([&](InspectorNetworkAgent* agent) { agent->ScriptImported(identifier, source_string); });
    }
}

void ScriptExecutionBlockedByCSPImpl(ExecutionContext* param_execution_context, const String& directive_text)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorEventBreakpointsAgents()) {
        probe_sink->InspectorEventBreakpointsAgents().ForEachAgent(
            [&](InspectorEventBreakpointsAgent* agent) { agent->ScriptExecutionBlockedByCSP(directive_text); });
    }
}

void DidReceiveScriptResponseImpl(ExecutionContext* param_execution_context, uint64_t identifier)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent([&](InspectorNetworkAgent* agent) { agent->DidReceiveScriptResponse(identifier); });
    }
}

void DomContentLoadedEventFiredImpl(LocalFrame* param_local_frame)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasDevToolsSessions()) {
        probe_sink->DevToolsSessions().ForEachAgent([&](DevToolsSession* agent) { agent->DomContentLoadedEventFired(param_local_frame); });
    }
    if (probe_sink->HasInspectorDOMAgents()) {
        probe_sink->InspectorDOMAgents().ForEachAgent([&](InspectorDOMAgent* agent) { agent->DomContentLoadedEventFired(param_local_frame); });
    }
    if (probe_sink->HasInspectorIssueReporters()) {
        probe_sink->InspectorIssueReporters().ForEachAgent([&](InspectorIssueReporter* agent) { agent->DomContentLoadedEventFired(param_local_frame); });
    }
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->DomContentLoadedEventFired(param_local_frame); });
    }
}

void LoadEventFiredImpl(LocalFrame* param_local_frame)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->LoadEventFired(param_local_frame); });
    }
}

void FrameAttachedToParentImpl(LocalFrame* param_local_frame, const std::optional<AdScriptIdentifier>& ad_script_on_stack)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->FrameAttachedToParent(param_local_frame, ad_script_on_stack); });
    }
}

void FrameDetachedFromParentImpl(LocalFrame* param_local_frame, FrameDetachType param_frame_detach_type)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent(
            [&](InspectorPageAgent* agent) { agent->FrameDetachedFromParent(param_local_frame, param_frame_detach_type); });
    }
}

void FrameSubtreeWillBeDetachedImpl(LocalFrame* param_local_frame, Frame* param_frame)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->FrameSubtreeWillBeDetached(param_frame); });
    }
}

void DidStartProvisionalLoadImpl(LocalFrame* param_local_frame)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasDevToolsSessions()) {
        probe_sink->DevToolsSessions().ForEachAgent([&](DevToolsSession* agent) { agent->DidStartProvisionalLoad(param_local_frame); });
    }
}

void DidFailProvisionalLoadImpl(LocalFrame* param_local_frame)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasDevToolsSessions()) {
        probe_sink->DevToolsSessions().ForEachAgent([&](DevToolsSession* agent) { agent->DidFailProvisionalLoad(param_local_frame); });
    }
}

void WillCommitLoadImpl(LocalFrame* param_local_frame, DocumentLoader* param_document_loader)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorEmulationAgents()) {
        probe_sink->InspectorEmulationAgents().ForEachAgent(
            [&](InspectorEmulationAgent* agent) { agent->WillCommitLoad(param_local_frame, param_document_loader); });
    }
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->WillCommitLoad(param_local_frame, param_document_loader); });
    }
}

void DidCommitLoadImpl(LocalFrame* param_local_frame, DocumentLoader* param_document_loader)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasDevToolsSessions()) {
        probe_sink->DevToolsSessions().ForEachAgent([&](DevToolsSession* agent) { agent->DidCommitLoad(param_local_frame, param_document_loader); });
    }
    if (probe_sink->HasInspectorDOMAgents()) {
        probe_sink->InspectorDOMAgents().ForEachAgent([&](InspectorDOMAgent* agent) { agent->DidCommitLoad(param_local_frame, param_document_loader); });
    }
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent(
            [&](InspectorNetworkAgent* agent) { agent->DidCommitLoad(param_local_frame, param_document_loader); });
    }
}

void DidNavigateWithinDocumentImpl(LocalFrame* param_local_frame, blink::mojom::SameDocumentNavigationType param_blink)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->DidNavigateWithinDocument(param_local_frame, param_blink); });
    }
}

void DidRestoreFromBackForwardCacheImpl(LocalFrame* param_local_frame)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMAgents()) {
        probe_sink->InspectorDOMAgents().ForEachAgent([&](InspectorDOMAgent* agent) { agent->DidRestoreFromBackForwardCache(param_local_frame); });
    }
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->DidRestoreFromBackForwardCache(param_local_frame); });
    }
}

void DidOpenDocumentImpl(LocalFrame* param_local_frame, DocumentLoader* param_document_loader)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->DidOpenDocument(param_local_frame, param_document_loader); });
    }
}

void WillCreateDocumentParserImpl(Document* param_document, bool& force_sync_parsing)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_document);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorEmulationAgents()) {
        probe_sink->InspectorEmulationAgents().ForEachAgent([&](InspectorEmulationAgent* agent) { agent->WillCreateDocumentParser(force_sync_parsing); });
    }
}

void FrameDocumentUpdatedImpl(LocalFrame* param_local_frame)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMAgents()) {
        probe_sink->InspectorDOMAgents().ForEachAgent([&](InspectorDOMAgent* agent) { agent->FrameDocumentUpdated(param_local_frame); });
    }
}

void FrameOwnerContentUpdatedImpl(LocalFrame* param_local_frame, HTMLFrameOwnerElement* param_html_frame_owner_element)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMAgents()) {
        probe_sink->InspectorDOMAgents().ForEachAgent(
            [&](InspectorDOMAgent* agent) { agent->FrameOwnerContentUpdated(param_local_frame, param_html_frame_owner_element); });
    }
}

void FrameStartedLoadingImpl(LocalFrame* param_local_frame)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorTraceEventss()) {
        probe_sink->InspectorTraceEventss().ForEachAgent([&](InspectorTraceEvents* agent) { agent->FrameStartedLoading(param_local_frame); });
    }
}

void FrameStoppedLoadingImpl(LocalFrame* param_local_frame)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->FrameStoppedLoading(param_local_frame); });
    }
}

void FrameRequestedNavigationImpl(LocalFrame* param_local_frame, Frame* target_frame, const KURL& url, ClientNavigationReason reason, NavigationPolicy policy)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->FrameRequestedNavigation(target_frame, url, reason, policy); });
    }
}

void FrameScheduledNavigationImpl(LocalFrame* param_local_frame, const KURL& url, base::TimeDelta delay, ClientNavigationReason reason)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent(
            [&](InspectorNetworkAgent* agent) { agent->FrameScheduledNavigation(param_local_frame, url, delay, reason); });
    }
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent(
            [&](InspectorPageAgent* agent) { agent->FrameScheduledNavigation(param_local_frame, url, delay, reason); });
    }
}

void FrameClearedScheduledNavigationImpl(LocalFrame* param_local_frame)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent([&](InspectorNetworkAgent* agent) { agent->FrameClearedScheduledNavigation(param_local_frame); });
    }
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->FrameClearedScheduledNavigation(param_local_frame); });
    }
}

void WillCreateWebSocketImpl(ExecutionContext* param_execution_context, uint64_t identifier, const KURL& request_url, const String& protocol,
    std::optional<base::UnguessableToken>* devtools_token)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent(
            [&](InspectorNetworkAgent* agent) { agent->WillCreateWebSocket(param_execution_context, identifier, request_url, protocol, devtools_token); });
    }
}

void WillSendWebSocketHandshakeRequestImpl(
    ExecutionContext* param_execution_context, uint64_t identifier, network::mojom::blink::WebSocketHandshakeRequest* request)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent(
            [&](InspectorNetworkAgent* agent) { agent->WillSendWebSocketHandshakeRequest(param_execution_context, identifier, request); });
    }
}

void DidReceiveWebSocketHandshakeResponseImpl(ExecutionContext* param_execution_context, uint64_t identifier,
    network::mojom::blink::WebSocketHandshakeRequest* request, network::mojom::blink::WebSocketHandshakeResponse* response)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent(
            [&](InspectorNetworkAgent* agent) { agent->DidReceiveWebSocketHandshakeResponse(param_execution_context, identifier, request, response); });
    }
}

void DidCloseWebSocketImpl(ExecutionContext* param_execution_context, uint64_t identifier)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent([&](InspectorNetworkAgent* agent) { agent->DidCloseWebSocket(param_execution_context, identifier); });
    }
}

void DidReceiveWebSocketMessageImpl(
    ExecutionContext* param_execution_context, uint64_t identifier, int opcode, bool masked, const Vector<base::span<const char>>& data)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent(
            [&](InspectorNetworkAgent* agent) { agent->DidReceiveWebSocketMessage(identifier, opcode, masked, data); });
    }
}

void DidSendWebSocketMessageImpl(ExecutionContext* param_execution_context, uint64_t identifier, int opcode, bool masked, base::span<const char> payload)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent(
            [&](InspectorNetworkAgent* agent) { agent->DidSendWebSocketMessage(identifier, opcode, masked, payload); });
    }
}

void DidReceiveWebSocketMessageErrorImpl(ExecutionContext* param_execution_context, uint64_t identifier, const String& error_message)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent(
            [&](InspectorNetworkAgent* agent) { agent->DidReceiveWebSocketMessageError(identifier, error_message); });
    }
}

void WebTransportCreatedImpl(ExecutionContext* param_execution_context, uint64_t transport_id, const KURL& request_url)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent(
            [&](InspectorNetworkAgent* agent) { agent->WebTransportCreated(param_execution_context, transport_id, request_url); });
    }
}

void WebTransportConnectionEstablishedImpl(ExecutionContext* param_execution_context, uint64_t transport_id)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent([&](InspectorNetworkAgent* agent) { agent->WebTransportConnectionEstablished(transport_id); });
    }
}

void WebTransportClosedImpl(ExecutionContext* param_execution_context, uint64_t transport_id)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent([&](InspectorNetworkAgent* agent) { agent->WebTransportClosed(transport_id); });
    }
}

void WillCreateP2PSocketUdpImpl(ExecutionContext* param_execution_context, std::optional<base::UnguessableToken>* devtools_token)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent([&](InspectorNetworkAgent* agent) { agent->WillCreateP2PSocketUdp(devtools_token); });
    }
}

void LayerTreeDidChangeImpl(LocalFrame* param_local_frame)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorLayerTreeAgents()) {
        probe_sink->InspectorLayerTreeAgents().ForEachAgent([&](InspectorLayerTreeAgent* agent) { agent->LayerTreeDidChange(); });
    }
}

void LayerTreePaintedImpl(LocalFrame* param_local_frame)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorLayerTreeAgents()) {
        probe_sink->InspectorLayerTreeAgents().ForEachAgent([&](InspectorLayerTreeAgent* agent) { agent->LayerTreePainted(); });
    }
}

void PseudoElementCreatedImpl(PseudoElement* param_pseudo_element)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_pseudo_element);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMAgents()) {
        probe_sink->InspectorDOMAgents().ForEachAgent([&](InspectorDOMAgent* agent) { agent->PseudoElementCreated(param_pseudo_element); });
    }
}

void TopLayerElementsChangedImpl(Document* param_document)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_document);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMAgents()) {
        probe_sink->InspectorDOMAgents().ForEachAgent([&](InspectorDOMAgent* agent) { agent->TopLayerElementsChanged(); });
    }
}

void PseudoElementDestroyedImpl(PseudoElement* param_pseudo_element)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_pseudo_element);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMAgents()) {
        probe_sink->InspectorDOMAgents().ForEachAgent([&](InspectorDOMAgent* agent) { agent->PseudoElementDestroyed(param_pseudo_element); });
    }
}

void DidCreateAnimationImpl(Document* param_document, unsigned param_unsigned)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_document);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorAnimationAgents()) {
        probe_sink->InspectorAnimationAgents().ForEachAgent([&](InspectorAnimationAgent* agent) { agent->DidCreateAnimation(param_unsigned); });
    }
}

void AnimationUpdatedImpl(Document* param_document, Animation* param_animation)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_document);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorAnimationAgents()) {
        probe_sink->InspectorAnimationAgents().ForEachAgent([&](InspectorAnimationAgent* agent) { agent->AnimationUpdated(param_animation); });
    }
}

void WindowOpenImpl(
    ExecutionContext* param_execution_context, const KURL& url, const AtomicString& window_name, const WebWindowFeatures& window_features, bool user_gestrue)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->WindowOpen(url, window_name, window_features, user_gestrue); });
    }
}

void ConsoleMessageAddedImpl(ExecutionContext* param_execution_context, ConsoleMessage* param_console_message)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorLogAgents()) {
        probe_sink->InspectorLogAgents().ForEachAgent([&](InspectorLogAgent* agent) { agent->ConsoleMessageAdded(param_console_message); });
    }
}

void InspectorIssueAddedImpl(CoreProbeSink* param_core_probe_sink, protocol::Audits::InspectorIssue* param_protocol)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_core_probe_sink);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorAuditsAgents()) {
        probe_sink->InspectorAuditsAgents().ForEachAgent([&](InspectorAuditsAgent* agent) { agent->InspectorIssueAdded(param_protocol); });
    }
}

void WillRunJavaScriptDialogImpl(LocalFrame* frame)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->WillRunJavaScriptDialog(); });
    }
}

void DidRunJavaScriptDialogImpl(LocalFrame* frame)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasAnimationFrameTimingMonitors()) {
        probe_sink->AnimationFrameTimingMonitors().ForEachAgent([&](AnimationFrameTimingMonitor* agent) { agent->DidRunJavaScriptDialog(); });
    }
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->DidRunJavaScriptDialog(); });
    }
}

void DocumentWriteFetchScriptImpl(Document* param_document)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_document);
    if (!probe_sink)
        return;
    if (probe_sink->HasPerformanceMonitors()) {
        probe_sink->PerformanceMonitors().ForEachAgent([&](PerformanceMonitor* agent) { agent->DocumentWriteFetchScript(param_document); });
    }
}

void DidChangeViewportImpl(LocalFrame* document)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(document);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->DidChangeViewport(); });
    }
}

void BreakableLocationImpl(ExecutionContext* context, const char* name)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorEventBreakpointsAgents()) {
        probe_sink->InspectorEventBreakpointsAgents().ForEachAgent([&](InspectorEventBreakpointsAgent* agent) { agent->BreakableLocation(name); });
    }
}

void WillHandlePromiseImpl(ExecutionContext* context, ScriptState* script_state, bool resolving, const char* class_like_name, PropertyName property_like_name,
    const String& script_url)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(context);
    if (!probe_sink)
        return;
    if (probe_sink->HasAnimationFrameTimingMonitors()) {
        probe_sink->AnimationFrameTimingMonitors().ForEachAgent(
            [&](AnimationFrameTimingMonitor* agent) { agent->WillHandlePromise(script_state, resolving, class_like_name, property_like_name, script_url); });
    }
}

RecalculateStyle::RecalculateStyle(Document* document)
    : document(document)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kAnimationFrameTimingMonitor | CoreProbeSink::kInspectorCSSAgent | CoreProbeSink::kInspectorPageAgent
            | CoreProbeSink::kInspectorPerformanceAgent | CoreProbeSink::kPerformanceMonitor))
        return;
    probe_sink = ToCoreProbeSink(document);
    if (!probe_sink)
        return;
    if (probe_sink->HasAnimationFrameTimingMonitors()) {
        probe_sink->AnimationFrameTimingMonitors().ForEachAgent([&](AnimationFrameTimingMonitor* agent) { agent->Will(*this); });
    }
    if (probe_sink->HasInspectorCSSAgents()) {
        probe_sink->InspectorCSSAgents().ForEachAgent([&](InspectorCSSAgent* agent) { agent->Will(*this); });
    }
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->Will(*this); });
    }
    if (probe_sink->HasInspectorPerformanceAgents()) {
        probe_sink->InspectorPerformanceAgents().ForEachAgent([&](InspectorPerformanceAgent* agent) { agent->Will(*this); });
    }
    if (probe_sink->HasPerformanceMonitors()) {
        probe_sink->PerformanceMonitors().ForEachAgent([&](PerformanceMonitor* agent) { agent->Will(*this); });
    }
}

RecalculateStyle::~RecalculateStyle()
{
    if (!probe_sink)
        return;
    if (probe_sink->HasAnimationFrameTimingMonitors()) {
        probe_sink->AnimationFrameTimingMonitors().ForEachAgent([&](AnimationFrameTimingMonitor* agent) { agent->Did(*this); });
    }
    if (probe_sink->HasInspectorCSSAgents()) {
        probe_sink->InspectorCSSAgents().ForEachAgent([&](InspectorCSSAgent* agent) { agent->Did(*this); });
    }
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->Did(*this); });
    }
    if (probe_sink->HasInspectorPerformanceAgents()) {
        probe_sink->InspectorPerformanceAgents().ForEachAgent([&](InspectorPerformanceAgent* agent) { agent->Did(*this); });
    }
    if (probe_sink->HasPerformanceMonitors()) {
        probe_sink->PerformanceMonitors().ForEachAgent([&](PerformanceMonitor* agent) { agent->Did(*this); });
    }
}

UpdateLayout::UpdateLayout(Document* document)
    : document(document)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kAnimationFrameTimingMonitor | CoreProbeSink::kInspectorPageAgent
            | CoreProbeSink::kInspectorPerformanceAgent | CoreProbeSink::kPerformanceMonitor))
        return;
    probe_sink = ToCoreProbeSink(document);
    if (!probe_sink)
        return;
    if (probe_sink->HasAnimationFrameTimingMonitors()) {
        probe_sink->AnimationFrameTimingMonitors().ForEachAgent([&](AnimationFrameTimingMonitor* agent) { agent->Will(*this); });
    }
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->Will(*this); });
    }
    if (probe_sink->HasInspectorPerformanceAgents()) {
        probe_sink->InspectorPerformanceAgents().ForEachAgent([&](InspectorPerformanceAgent* agent) { agent->Will(*this); });
    }
    if (probe_sink->HasPerformanceMonitors()) {
        probe_sink->PerformanceMonitors().ForEachAgent([&](PerformanceMonitor* agent) { agent->Will(*this); });
    }
}

UpdateLayout::~UpdateLayout()
{
    if (!probe_sink)
        return;
    if (probe_sink->HasAnimationFrameTimingMonitors()) {
        probe_sink->AnimationFrameTimingMonitors().ForEachAgent([&](AnimationFrameTimingMonitor* agent) { agent->Did(*this); });
    }
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->Did(*this); });
    }
    if (probe_sink->HasInspectorPerformanceAgents()) {
        probe_sink->InspectorPerformanceAgents().ForEachAgent([&](InspectorPerformanceAgent* agent) { agent->Did(*this); });
    }
    if (probe_sink->HasPerformanceMonitors()) {
        probe_sink->PerformanceMonitors().ForEachAgent([&](PerformanceMonitor* agent) { agent->Did(*this); });
    }
}

EvaluateScriptBlock::EvaluateScriptBlock(std::reference_wrapper<std::remove_reference_t<ScriptState&>> script_state,
    std::reference_wrapper<std::remove_reference_t<const KURL&>> source_url, bool is_module, bool sanitize)
    : script_state(script_state)
    , source_url(source_url)
    , is_module(is_module)
    , sanitize(sanitize)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kAnimationFrameTimingMonitor))
        return;
    probe_sink = ToCoreProbeSink(script_state);
    if (!probe_sink)
        return;
    if (probe_sink->HasAnimationFrameTimingMonitors()) {
        probe_sink->AnimationFrameTimingMonitors().ForEachAgent([&](AnimationFrameTimingMonitor* agent) { agent->Will(*this); });
    }
}

EvaluateScriptBlock::~EvaluateScriptBlock()
{
    if (!probe_sink)
        return;
    if (probe_sink->HasAnimationFrameTimingMonitors()) {
        probe_sink->AnimationFrameTimingMonitors().ForEachAgent([&](AnimationFrameTimingMonitor* agent) { agent->Did(*this); });
    }
}

ExecuteScript::ExecuteScript(
    ExecutionContext* context, v8::Local<v8::Context> v8_context, std::reference_wrapper<std::remove_reference_t<const String&>> script_url, int script_id)
    : context(context)
    , v8_context(v8_context)
    , script_url(script_url)
    , script_id(script_id)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kAdTracker | CoreProbeSink::kAnimationFrameTimingMonitor | CoreProbeSink::kInspectorEventBreakpointsAgent
            | CoreProbeSink::kInspectorPerformanceAgent | CoreProbeSink::kLCPScriptObserver | CoreProbeSink::kPerformanceMonitor))
        return;
    probe_sink = ToCoreProbeSink(context);
    if (!probe_sink)
        return;
    if (probe_sink->HasAdTrackers()) {
        probe_sink->AdTrackers().ForEachAgent([&](AdTracker* agent) { agent->Will(*this); });
    }
    if (probe_sink->HasAnimationFrameTimingMonitors()) {
        probe_sink->AnimationFrameTimingMonitors().ForEachAgent([&](AnimationFrameTimingMonitor* agent) { agent->Will(*this); });
    }
    if (probe_sink->HasInspectorEventBreakpointsAgents()) {
        probe_sink->InspectorEventBreakpointsAgents().ForEachAgent([&](InspectorEventBreakpointsAgent* agent) { agent->Will(*this); });
    }
    if (probe_sink->HasInspectorPerformanceAgents()) {
        probe_sink->InspectorPerformanceAgents().ForEachAgent([&](InspectorPerformanceAgent* agent) { agent->Will(*this); });
    }
    if (probe_sink->HasLCPScriptObservers()) {
        probe_sink->LCPScriptObservers().ForEachAgent([&](LCPScriptObserver* agent) { agent->Will(*this); });
    }
    if (probe_sink->HasPerformanceMonitors()) {
        probe_sink->PerformanceMonitors().ForEachAgent([&](PerformanceMonitor* agent) { agent->Will(*this); });
    }
}

ExecuteScript::~ExecuteScript()
{
    if (!probe_sink)
        return;
    if (probe_sink->HasAdTrackers()) {
        probe_sink->AdTrackers().ForEachAgent([&](AdTracker* agent) { agent->Did(*this); });
    }
    if (probe_sink->HasAnimationFrameTimingMonitors()) {
        probe_sink->AnimationFrameTimingMonitors().ForEachAgent([&](AnimationFrameTimingMonitor* agent) { agent->Did(*this); });
    }
    if (probe_sink->HasInspectorEventBreakpointsAgents()) {
        probe_sink->InspectorEventBreakpointsAgents().ForEachAgent([&](InspectorEventBreakpointsAgent* agent) { agent->Did(*this); });
    }
    if (probe_sink->HasInspectorPerformanceAgents()) {
        probe_sink->InspectorPerformanceAgents().ForEachAgent([&](InspectorPerformanceAgent* agent) { agent->Did(*this); });
    }
    if (probe_sink->HasLCPScriptObservers()) {
        probe_sink->LCPScriptObservers().ForEachAgent([&](LCPScriptObserver* agent) { agent->Did(*this); });
    }
    if (probe_sink->HasPerformanceMonitors()) {
        probe_sink->PerformanceMonitors().ForEachAgent([&](PerformanceMonitor* agent) { agent->Did(*this); });
    }
}

CallFunction::CallFunction(ExecutionContext* context, v8::Local<v8::Context> v8_context, v8::Local<v8::Function> function, int depth)
    : context(context)
    , v8_context(v8_context)
    , function(function)
    , depth(depth)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kAdTracker | CoreProbeSink::kInspectorPerformanceAgent | CoreProbeSink::kInspectorTraceEvents
            | CoreProbeSink::kLCPScriptObserver | CoreProbeSink::kPerformanceMonitor))
        return;
    probe_sink = ToCoreProbeSink(context);
    if (!probe_sink)
        return;
    if (probe_sink->HasAdTrackers()) {
        probe_sink->AdTrackers().ForEachAgent([&](AdTracker* agent) { agent->Will(*this); });
    }
    if (probe_sink->HasInspectorPerformanceAgents()) {
        probe_sink->InspectorPerformanceAgents().ForEachAgent([&](InspectorPerformanceAgent* agent) { agent->Will(*this); });
    }
    if (probe_sink->HasInspectorTraceEventss()) {
        probe_sink->InspectorTraceEventss().ForEachAgent([&](InspectorTraceEvents* agent) { agent->Will(*this); });
    }
    if (probe_sink->HasLCPScriptObservers()) {
        probe_sink->LCPScriptObservers().ForEachAgent([&](LCPScriptObserver* agent) { agent->Will(*this); });
    }
    if (probe_sink->HasPerformanceMonitors()) {
        probe_sink->PerformanceMonitors().ForEachAgent([&](PerformanceMonitor* agent) { agent->Will(*this); });
    }
}

CallFunction::~CallFunction()
{
    if (!probe_sink)
        return;
    if (probe_sink->HasAdTrackers()) {
        probe_sink->AdTrackers().ForEachAgent([&](AdTracker* agent) { agent->Did(*this); });
    }
    if (probe_sink->HasInspectorPerformanceAgents()) {
        probe_sink->InspectorPerformanceAgents().ForEachAgent([&](InspectorPerformanceAgent* agent) { agent->Did(*this); });
    }
    if (probe_sink->HasInspectorTraceEventss()) {
        probe_sink->InspectorTraceEventss().ForEachAgent([&](InspectorTraceEvents* agent) { agent->Did(*this); });
    }
    if (probe_sink->HasLCPScriptObservers()) {
        probe_sink->LCPScriptObservers().ForEachAgent([&](LCPScriptObserver* agent) { agent->Did(*this); });
    }
    if (probe_sink->HasPerformanceMonitors()) {
        probe_sink->PerformanceMonitors().ForEachAgent([&](PerformanceMonitor* agent) { agent->Did(*this); });
    }
}

UserCallback::UserCallback(
    ExecutionContext* context, const char* name, AtomicString atomic_name, bool recurring, EventTarget* event_target, Event* event, EventListener* listener)
    : context(context)
    , name(name)
    , atomic_name(atomic_name)
    , recurring(recurring)
    , event_target(event_target)
    , event(event)
    , listener(listener)
{
    if (!CoreProbeSink::HasAgentsGlobal(
            CoreProbeSink::kInspectorDOMDebuggerAgent | CoreProbeSink::kInspectorEventBreakpointsAgent | CoreProbeSink::kPerformanceMonitor))
        return;
    probe_sink = ToCoreProbeSink(context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMDebuggerAgents()) {
        probe_sink->InspectorDOMDebuggerAgents().ForEachAgent([&](InspectorDOMDebuggerAgent* agent) { agent->Will(*this); });
    }
    if (probe_sink->HasInspectorEventBreakpointsAgents()) {
        probe_sink->InspectorEventBreakpointsAgents().ForEachAgent([&](InspectorEventBreakpointsAgent* agent) { agent->Will(*this); });
    }
    if (probe_sink->HasPerformanceMonitors()) {
        probe_sink->PerformanceMonitors().ForEachAgent([&](PerformanceMonitor* agent) { agent->Will(*this); });
    }
}

UserCallback::~UserCallback()
{
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMDebuggerAgents()) {
        probe_sink->InspectorDOMDebuggerAgents().ForEachAgent([&](InspectorDOMDebuggerAgent* agent) { agent->Did(*this); });
    }
    if (probe_sink->HasInspectorEventBreakpointsAgents()) {
        probe_sink->InspectorEventBreakpointsAgents().ForEachAgent([&](InspectorEventBreakpointsAgent* agent) { agent->Did(*this); });
    }
    if (probe_sink->HasPerformanceMonitors()) {
        probe_sink->PerformanceMonitors().ForEachAgent([&](PerformanceMonitor* agent) { agent->Did(*this); });
    }
}

InvokeCallback::InvokeCallback(std::reference_wrapper<std::remove_reference_t<ScriptState&>> script_state, const char* name, CallbackFunctionBase* callback,
    v8::MaybeLocal<v8::Value> function)
    : script_state(script_state)
    , name(name)
    , callback(callback)
    , function(function)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kAnimationFrameTimingMonitor))
        return;
    probe_sink = ToCoreProbeSink(script_state);
    if (!probe_sink)
        return;
    if (probe_sink->HasAnimationFrameTimingMonitors()) {
        probe_sink->AnimationFrameTimingMonitors().ForEachAgent([&](AnimationFrameTimingMonitor* agent) { agent->Will(*this); });
    }
}

InvokeCallback::~InvokeCallback()
{
    if (!probe_sink)
        return;
    if (probe_sink->HasAnimationFrameTimingMonitors()) {
        probe_sink->AnimationFrameTimingMonitors().ForEachAgent([&](AnimationFrameTimingMonitor* agent) { agent->Did(*this); });
    }
}

InvokeEventHandler::InvokeEventHandler(std::reference_wrapper<std::remove_reference_t<ScriptState&>> script_state, Event* event, JSBasedEventListener* listener)
    : script_state(script_state)
    , event(event)
    , listener(listener)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kAnimationFrameTimingMonitor))
        return;
    probe_sink = ToCoreProbeSink(script_state);
    if (!probe_sink)
        return;
    if (probe_sink->HasAnimationFrameTimingMonitors()) {
        probe_sink->AnimationFrameTimingMonitors().ForEachAgent([&](AnimationFrameTimingMonitor* agent) { agent->Will(*this); });
    }
}

InvokeEventHandler::~InvokeEventHandler()
{
    if (!probe_sink)
        return;
    if (probe_sink->HasAnimationFrameTimingMonitors()) {
        probe_sink->AnimationFrameTimingMonitors().ForEachAgent([&](AnimationFrameTimingMonitor* agent) { agent->Did(*this); });
    }
}

V8Compile::V8Compile(ExecutionContext* context, std::reference_wrapper<std::remove_reference_t<const String&>> file_name, int line, int column)
    : context(context)
    , file_name(file_name)
    , line(line)
    , column(column)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPerformanceAgent | CoreProbeSink::kPerformanceMonitor))
        return;
    probe_sink = ToCoreProbeSink(context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPerformanceAgents()) {
        probe_sink->InspectorPerformanceAgents().ForEachAgent([&](InspectorPerformanceAgent* agent) { agent->Will(*this); });
    }
    if (probe_sink->HasPerformanceMonitors()) {
        probe_sink->PerformanceMonitors().ForEachAgent([&](PerformanceMonitor* agent) { agent->Will(*this); });
    }
}

V8Compile::~V8Compile()
{
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPerformanceAgents()) {
        probe_sink->InspectorPerformanceAgents().ForEachAgent([&](InspectorPerformanceAgent* agent) { agent->Did(*this); });
    }
    if (probe_sink->HasPerformanceMonitors()) {
        probe_sink->PerformanceMonitors().ForEachAgent([&](PerformanceMonitor* agent) { agent->Did(*this); });
    }
}

ParseHTML::ParseHTML(Document* document, HTMLDocumentParser* parser)
    : document(document)
    , parser(parser)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorTraceEvents))
        return;
    probe_sink = ToCoreProbeSink(document);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorTraceEventss()) {
        probe_sink->InspectorTraceEventss().ForEachAgent([&](InspectorTraceEvents* agent) { agent->Will(*this); });
    }
}

ParseHTML::~ParseHTML()
{
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorTraceEventss()) {
        probe_sink->InspectorTraceEventss().ForEachAgent([&](InspectorTraceEvents* agent) { agent->Did(*this); });
    }
}

void ForcePseudoStateImpl(Element* element, CSSSelector::PseudoType pseudo_state, bool* result)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(element);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorCSSAgents()) {
        probe_sink->InspectorCSSAgents().ForEachAgent([&](InspectorCSSAgent* agent) { agent->ForcePseudoState(element, pseudo_state, result); });
    }
}

void ShouldForceCorsPreflightImpl(ExecutionContext* param_execution_context, bool* result)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent([&](InspectorNetworkAgent* agent) { agent->ShouldForceCorsPreflight(result); });
    }
}

void ShouldBlockRequestImpl(CoreProbeSink* param_core_probe_sink, const KURL& param_kurl, bool* result)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_core_probe_sink);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent([&](InspectorNetworkAgent* agent) { agent->ShouldBlockRequest(param_kurl, result); });
    }
}

void ShouldBypassServiceWorkerImpl(ExecutionContext* context, bool* result)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent([&](InspectorNetworkAgent* agent) { agent->ShouldBypassServiceWorker(result); });
    }
}

void ConsoleTimeStampImpl(v8::Isolate* isolate, v8::Local<v8::String> label)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(isolate);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPerformanceAgents()) {
        probe_sink->InspectorPerformanceAgents().ForEachAgent([&](InspectorPerformanceAgent* agent) { agent->ConsoleTimeStamp(isolate, label); });
    }
}

void WillStartDebuggerTaskImpl(CoreProbeSink* param_core_probe_sink)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_core_probe_sink);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPerformanceAgents()) {
        probe_sink->InspectorPerformanceAgents().ForEachAgent([&](InspectorPerformanceAgent* agent) { agent->WillStartDebuggerTask(); });
    }
}

void DidFinishDebuggerTaskImpl(CoreProbeSink* param_core_probe_sink)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_core_probe_sink);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPerformanceAgents()) {
        probe_sink->InspectorPerformanceAgents().ForEachAgent([&](InspectorPerformanceAgent* agent) { agent->DidFinishDebuggerTask(); });
    }
}

void LifecycleEventImpl(LocalFrame* param_local_frame, DocumentLoader* param_document_loader, const char* name, double timestamp)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_local_frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent(
            [&](InspectorPageAgent* agent) { agent->LifecycleEvent(param_local_frame, param_document_loader, name, timestamp); });
    }
}

void PaintTimingImpl(Document* param_document, const char* name, double timestamp)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_document);
    if (!probe_sink)
        return;
    if (probe_sink->HasDevToolsSessions()) {
        probe_sink->DevToolsSessions().ForEachAgent([&](DevToolsSession* agent) { agent->PaintTiming(param_document, name, timestamp); });
    }
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->PaintTiming(param_document, name, timestamp); });
    }
    if (probe_sink->HasInspectorTraceEventss()) {
        probe_sink->InspectorTraceEventss().ForEachAgent([&](InspectorTraceEvents* agent) { agent->PaintTiming(param_document, name, timestamp); });
    }
}

void DidCreateAudioContextImpl(ExecutionContext* param_execution_context)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorEventBreakpointsAgents()) {
        probe_sink->InspectorEventBreakpointsAgents().ForEachAgent([&](InspectorEventBreakpointsAgent* agent) { agent->DidCreateAudioContext(); });
    }
}

void DidCloseAudioContextImpl(ExecutionContext* param_execution_context)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorEventBreakpointsAgents()) {
        probe_sink->InspectorEventBreakpointsAgents().ForEachAgent([&](InspectorEventBreakpointsAgent* agent) { agent->DidCloseAudioContext(); });
    }
}

void DidResumeAudioContextImpl(ExecutionContext* param_execution_context)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorEventBreakpointsAgents()) {
        probe_sink->InspectorEventBreakpointsAgents().ForEachAgent([&](InspectorEventBreakpointsAgent* agent) { agent->DidResumeAudioContext(); });
    }
}

void DidSuspendAudioContextImpl(ExecutionContext* param_execution_context)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorEventBreakpointsAgents()) {
        probe_sink->InspectorEventBreakpointsAgents().ForEachAgent([&](InspectorEventBreakpointsAgent* agent) { agent->DidSuspendAudioContext(); });
    }
}

void DidProduceCompilationCacheImpl(CoreProbeSink* param_core_probe_sink, const ClassicScript& param_classic_script, v8::Local<v8::Script> script)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_core_probe_sink);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->DidProduceCompilationCache(param_classic_script, script); });
    }
}

void ApplyCompilationModeOverrideImpl(ExecutionContext* param_execution_context, const ClassicScript& param_classic_script,
    v8::ScriptCompiler::CachedData** cached_data, v8::ScriptCompiler::CompileOptions* param_v8)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent(
            [&](InspectorPageAgent* agent) { agent->ApplyCompilationModeOverride(param_classic_script, cached_data, param_v8); });
    }
}

void NodeCreatedImpl(Node* node)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(node);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMAgents()) {
        probe_sink->InspectorDOMAgents().ForEachAgent([&](InspectorDOMAgent* agent) { agent->NodeCreated(node); });
    }
}

void FileChooserOpenedImpl(LocalFrame* frame, HTMLInputElement* element, bool multiple, bool* intercepted)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(frame);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPageAgents()) {
        probe_sink->InspectorPageAgents().ForEachAgent([&](InspectorPageAgent* agent) { agent->FileChooserOpened(frame, element, multiple, intercepted); });
    }
}

void PlayerErrorsRaisedImpl(ExecutionContext* context, String player_id, const Vector<InspectorPlayerError>& errors)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorMediaAgents()) {
        probe_sink->InspectorMediaAgents().ForEachAgent([&](InspectorMediaAgent* agent) { agent->PlayerErrorsRaised(player_id, errors); });
    }
}

void PlayerEventsAddedImpl(ExecutionContext* context, String player_id, const Vector<InspectorPlayerEvent>& events)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorMediaAgents()) {
        probe_sink->InspectorMediaAgents().ForEachAgent([&](InspectorMediaAgent* agent) { agent->PlayerEventsAdded(player_id, events); });
    }
}

void PlayerMessagesLoggedImpl(ExecutionContext* context, String player_id, const Vector<InspectorPlayerMessage>& messages)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorMediaAgents()) {
        probe_sink->InspectorMediaAgents().ForEachAgent([&](InspectorMediaAgent* agent) { agent->PlayerMessagesLogged(player_id, messages); });
    }
}

void PlayerPropertiesChangedImpl(ExecutionContext* context, String player_id, const Vector<InspectorPlayerProperty>& properties)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorMediaAgents()) {
        probe_sink->InspectorMediaAgents().ForEachAgent([&](InspectorMediaAgent* agent) { agent->PlayerPropertiesChanged(player_id, properties); });
    }
}

void PlayersCreatedImpl(ExecutionContext* context, const Vector<WebString>& players)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorMediaAgents()) {
        probe_sink->InspectorMediaAgents().ForEachAgent([&](InspectorMediaAgent* agent) { agent->PlayersCreated(players); });
    }
}

void SetDevToolsIdsImpl(CoreProbeSink* param_core_probe_sink, ResourceRequest& request, const FetchInitiatorInfo& param_fetch_initiator_info)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_core_probe_sink);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent([&](InspectorNetworkAgent* agent) { agent->SetDevToolsIds(request, param_fetch_initiator_info); });
    }
}

void DidMutateStyleSheetImpl(Document* param_document, CSSStyleSheet* style_sheet)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_document);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorCSSAgents()) {
        probe_sink->InspectorCSSAgents().ForEachAgent([&](InspectorCSSAgent* agent) { agent->DidMutateStyleSheet(style_sheet); });
    }
}

void DidReplaceStyleSheetTextImpl(Document* param_document, CSSStyleSheet* style_sheet, const String& text)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_document);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorCSSAgents()) {
        probe_sink->InspectorCSSAgents().ForEachAgent([&](InspectorCSSAgent* agent) { agent->DidReplaceStyleSheetText(style_sheet, text); });
    }
}

void GetTextPositionImpl(Document* param_document, wtf_size_t offset, const String* text, TextPosition* result)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_document);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorCSSAgents()) {
        probe_sink->InspectorCSSAgents().ForEachAgent([&](InspectorCSSAgent* agent) { agent->GetTextPosition(offset, text, result); });
    }
}

void LocalFontsEnabledImpl(ExecutionContext* param_execution_context, bool* result)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorCSSAgents()) {
        probe_sink->InspectorCSSAgents().ForEachAgent([&](InspectorCSSAgent* agent) { agent->LocalFontsEnabled(result); });
    }
}

void DidUpdateComputedStyleImpl(Element* param_element, const ComputedStyle* old_style, const ComputedStyle* new_style)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_element);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorCSSAgents()) {
        probe_sink->InspectorCSSAgents().ForEachAgent([&](InspectorCSSAgent* agent) { agent->DidUpdateComputedStyle(param_element, old_style, new_style); });
    }
}

void GetDisabledImageTypesImpl(ExecutionContext* param_execution_context, HashSet<String>* result)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorEmulationAgents()) {
        probe_sink->InspectorEmulationAgents().ForEachAgent([&](InspectorEmulationAgent* agent) { agent->GetDisabledImageTypes(result); });
    }
}

void OnContentSecurityPolicyViolationImpl(ExecutionContext* context, const blink::ContentSecurityPolicyViolationType violationType)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMDebuggerAgents()) {
        probe_sink->InspectorDOMDebuggerAgents().ForEachAgent(
            [&](InspectorDOMDebuggerAgent* agent) { agent->OnContentSecurityPolicyViolation(violationType); });
    }
}

void IsCacheDisabledImpl(ExecutionContext* param_execution_context, bool* is_cache_disabled)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorNetworkAgents()) {
        probe_sink->InspectorNetworkAgents().ForEachAgent([&](InspectorNetworkAgent* agent) { agent->IsCacheDisabled(is_cache_disabled); });
    }
}

void PerformanceEntryAddedImpl(ExecutionContext* param_execution_context, PerformanceEntry* param_performance_entry)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPerformanceTimelineAgents()) {
        probe_sink->InspectorPerformanceTimelineAgents().ForEachAgent(
            [&](InspectorPerformanceTimelineAgent* agent) { agent->PerformanceEntryAdded(param_execution_context, param_performance_entry); });
    }
}

void ApplyAutomationOverrideImpl(ExecutionContext* param_execution_context, bool& enabled)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_execution_context);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorEmulationAgents()) {
        probe_sink->InspectorEmulationAgents().ForEachAgent([&](InspectorEmulationAgent* agent) { agent->ApplyAutomationOverride(enabled); });
    }
}

void DidAddSpeculationRuleSetImpl(Document& param_document, const SpeculationRuleSet& rule_set)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_document);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPreloadAgents()) {
        probe_sink->InspectorPreloadAgents().ForEachAgent([&](InspectorPreloadAgent* agent) { agent->DidAddSpeculationRuleSet(param_document, rule_set); });
    }
}

void DidRemoveSpeculationRuleSetImpl(Document& param_document, const SpeculationRuleSet& rule_set)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_document);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPreloadAgents()) {
        probe_sink->InspectorPreloadAgents().ForEachAgent([&](InspectorPreloadAgent* agent) { agent->DidRemoveSpeculationRuleSet(rule_set); });
    }
}

void SpeculationCandidatesUpdatedImpl(Document& param_document, const HeapVector<Member<SpeculationCandidate>>& candidates)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(param_document);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorPreloadAgents()) {
        probe_sink->InspectorPreloadAgents().ForEachAgent(
            [&](InspectorPreloadAgent* agent) { agent->SpeculationCandidatesUpdated(param_document, candidates); });
    }
}

void DidInitializeFrameWidgetImpl(LocalFrame* document)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(document);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorOverlayAgents()) {
        probe_sink->InspectorOverlayAgents().ForEachAgent([&](InspectorOverlayAgent* agent) { agent->DidInitializeFrameWidget(); });
    }
}

void UpdateScrollableFlagImpl(Node* node, std::optional<bool> param_std)
{
    CoreProbeSink* probe_sink = ToCoreProbeSink(node);
    if (!probe_sink)
        return;
    if (probe_sink->HasInspectorDOMAgents()) {
        probe_sink->InspectorDOMAgents().ForEachAgent([&](InspectorDOMAgent* agent) { agent->UpdateScrollableFlag(node, param_std); });
    }
}

} // namespace probe
} // namespace blink
