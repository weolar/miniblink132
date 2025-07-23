// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   /probe_sink.h.tmpl
// and input files:
//   core_probes.pidl

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_CORE_PROBE_SINK_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_CORE_PROBE_SINK_H_

#include <atomic>

#include "third_party/blink/renderer/core/inspector/agent_registry.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/heap/garbage_collected.h"

namespace blink {

class AdTracker;
class AnimationFrameTimingMonitor;
class DevToolsSession;
class InspectorAnimationAgent;
class InspectorAuditsAgent;
class InspectorCSSAgent;
class InspectorDOMAgent;
class InspectorDOMDebuggerAgent;
class InspectorDOMSnapshotAgent;
class InspectorEmulationAgent;
class InspectorEventBreakpointsAgent;
class InspectorIssueReporter;
class InspectorLayerTreeAgent;
class InspectorLogAgent;
class InspectorMediaAgent;
class InspectorNetworkAgent;
class InspectorOverlayAgent;
class InspectorPageAgent;
class InspectorPerformanceAgent;
class InspectorPerformanceTimelineAgent;
class InspectorPreloadAgent;
class InspectorTraceEvents;
class LCPScriptObserver;
class PerformanceMonitor;

class CORE_EXPORT CoreProbeSink final : public GarbageCollected<CoreProbeSink> {

public:
    enum AgentType : unsigned {
        kAdTracker = 1u << 0,
        kAnimationFrameTimingMonitor = 1u << 1,
        kDevToolsSession = 1u << 2,
        kInspectorAnimationAgent = 1u << 3,
        kInspectorAuditsAgent = 1u << 4,
        kInspectorCSSAgent = 1u << 5,
        kInspectorDOMAgent = 1u << 6,
        kInspectorDOMDebuggerAgent = 1u << 7,
        kInspectorDOMSnapshotAgent = 1u << 8,
        kInspectorEmulationAgent = 1u << 9,
        kInspectorEventBreakpointsAgent = 1u << 10,
        kInspectorIssueReporter = 1u << 11,
        kInspectorLayerTreeAgent = 1u << 12,
        kInspectorLogAgent = 1u << 13,
        kInspectorMediaAgent = 1u << 14,
        kInspectorNetworkAgent = 1u << 15,
        kInspectorOverlayAgent = 1u << 16,
        kInspectorPageAgent = 1u << 17,
        kInspectorPerformanceAgent = 1u << 18,
        kInspectorPerformanceTimelineAgent = 1u << 19,
        kInspectorPreloadAgent = 1u << 20,
        kInspectorTraceEvents = 1u << 21,
        kLCPScriptObserver = 1u << 22,
        kPerformanceMonitor = 1u << 23,
    };

    CoreProbeSink();
    ~CoreProbeSink();
    CoreProbeSink(const CoreProbeSink&) = delete;
    CoreProbeSink& operator=(const CoreProbeSink&) = delete;

    void Trace(Visitor*) const;

    bool HasAdTrackers() const
    {
        return !ad_trackers_.IsEmpty();
    }
    const AgentRegistry<AdTracker>& AdTrackers() const
    {
        return ad_trackers_;
    }
    void AddAdTracker(AdTracker* agent);
    void RemoveAdTracker(AdTracker* agent);

    bool HasAnimationFrameTimingMonitors() const
    {
        return !animation_frame_timing_monitors_.IsEmpty();
    }
    const AgentRegistry<AnimationFrameTimingMonitor>& AnimationFrameTimingMonitors() const
    {
        return animation_frame_timing_monitors_;
    }
    void AddAnimationFrameTimingMonitor(AnimationFrameTimingMonitor* agent);
    void RemoveAnimationFrameTimingMonitor(AnimationFrameTimingMonitor* agent);

    bool HasDevToolsSessions() const
    {
        return !dev_tools_sessions_.IsEmpty();
    }
    const AgentRegistry<DevToolsSession>& DevToolsSessions() const
    {
        return dev_tools_sessions_;
    }
    void AddDevToolsSession(DevToolsSession* agent);
    void RemoveDevToolsSession(DevToolsSession* agent);

    bool HasInspectorAnimationAgents() const
    {
        return !inspector_animation_agents_.IsEmpty();
    }
    const AgentRegistry<InspectorAnimationAgent>& InspectorAnimationAgents() const
    {
        return inspector_animation_agents_;
    }
    void AddInspectorAnimationAgent(InspectorAnimationAgent* agent);
    void RemoveInspectorAnimationAgent(InspectorAnimationAgent* agent);

    bool HasInspectorAuditsAgents() const
    {
        return !inspector_audits_agents_.IsEmpty();
    }
    const AgentRegistry<InspectorAuditsAgent>& InspectorAuditsAgents() const
    {
        return inspector_audits_agents_;
    }
    void AddInspectorAuditsAgent(InspectorAuditsAgent* agent);
    void RemoveInspectorAuditsAgent(InspectorAuditsAgent* agent);

    bool HasInspectorCSSAgents() const
    {
        return !inspector_css_agents_.IsEmpty();
    }
    const AgentRegistry<InspectorCSSAgent>& InspectorCSSAgents() const
    {
        return inspector_css_agents_;
    }
    void AddInspectorCSSAgent(InspectorCSSAgent* agent);
    void RemoveInspectorCSSAgent(InspectorCSSAgent* agent);

    bool HasInspectorDOMAgents() const
    {
        return !inspector_dom_agents_.IsEmpty();
    }
    const AgentRegistry<InspectorDOMAgent>& InspectorDOMAgents() const
    {
        return inspector_dom_agents_;
    }
    void AddInspectorDOMAgent(InspectorDOMAgent* agent);
    void RemoveInspectorDOMAgent(InspectorDOMAgent* agent);

    bool HasInspectorDOMDebuggerAgents() const
    {
        return !inspector_dom_debugger_agents_.IsEmpty();
    }
    const AgentRegistry<InspectorDOMDebuggerAgent>& InspectorDOMDebuggerAgents() const
    {
        return inspector_dom_debugger_agents_;
    }
    void AddInspectorDOMDebuggerAgent(InspectorDOMDebuggerAgent* agent);
    void RemoveInspectorDOMDebuggerAgent(InspectorDOMDebuggerAgent* agent);

    bool HasInspectorDOMSnapshotAgents() const
    {
        return !inspector_dom_snapshot_agents_.IsEmpty();
    }
    const AgentRegistry<InspectorDOMSnapshotAgent>& InspectorDOMSnapshotAgents() const
    {
        return inspector_dom_snapshot_agents_;
    }
    void AddInspectorDOMSnapshotAgent(InspectorDOMSnapshotAgent* agent);
    void RemoveInspectorDOMSnapshotAgent(InspectorDOMSnapshotAgent* agent);

    bool HasInspectorEmulationAgents() const
    {
        return !inspector_emulation_agents_.IsEmpty();
    }
    const AgentRegistry<InspectorEmulationAgent>& InspectorEmulationAgents() const
    {
        return inspector_emulation_agents_;
    }
    void AddInspectorEmulationAgent(InspectorEmulationAgent* agent);
    void RemoveInspectorEmulationAgent(InspectorEmulationAgent* agent);

    bool HasInspectorEventBreakpointsAgents() const
    {
        return !inspector_event_breakpoints_agents_.IsEmpty();
    }
    const AgentRegistry<InspectorEventBreakpointsAgent>& InspectorEventBreakpointsAgents() const
    {
        return inspector_event_breakpoints_agents_;
    }
    void AddInspectorEventBreakpointsAgent(InspectorEventBreakpointsAgent* agent);
    void RemoveInspectorEventBreakpointsAgent(InspectorEventBreakpointsAgent* agent);

    bool HasInspectorIssueReporters() const
    {
        return !inspector_issue_reporters_.IsEmpty();
    }
    const AgentRegistry<InspectorIssueReporter>& InspectorIssueReporters() const
    {
        return inspector_issue_reporters_;
    }
    void AddInspectorIssueReporter(InspectorIssueReporter* agent);
    void RemoveInspectorIssueReporter(InspectorIssueReporter* agent);

    bool HasInspectorLayerTreeAgents() const
    {
        return !inspector_layer_tree_agents_.IsEmpty();
    }
    const AgentRegistry<InspectorLayerTreeAgent>& InspectorLayerTreeAgents() const
    {
        return inspector_layer_tree_agents_;
    }
    void AddInspectorLayerTreeAgent(InspectorLayerTreeAgent* agent);
    void RemoveInspectorLayerTreeAgent(InspectorLayerTreeAgent* agent);

    bool HasInspectorLogAgents() const
    {
        return !inspector_log_agents_.IsEmpty();
    }
    const AgentRegistry<InspectorLogAgent>& InspectorLogAgents() const
    {
        return inspector_log_agents_;
    }
    void AddInspectorLogAgent(InspectorLogAgent* agent);
    void RemoveInspectorLogAgent(InspectorLogAgent* agent);

    bool HasInspectorMediaAgents() const
    {
        return !inspector_media_agents_.IsEmpty();
    }
    const AgentRegistry<InspectorMediaAgent>& InspectorMediaAgents() const
    {
        return inspector_media_agents_;
    }
    void AddInspectorMediaAgent(InspectorMediaAgent* agent);
    void RemoveInspectorMediaAgent(InspectorMediaAgent* agent);

    bool HasInspectorNetworkAgents() const
    {
        return !inspector_network_agents_.IsEmpty();
    }
    const AgentRegistry<InspectorNetworkAgent>& InspectorNetworkAgents() const
    {
        return inspector_network_agents_;
    }
    void AddInspectorNetworkAgent(InspectorNetworkAgent* agent);
    void RemoveInspectorNetworkAgent(InspectorNetworkAgent* agent);

    bool HasInspectorOverlayAgents() const
    {
        return !inspector_overlay_agents_.IsEmpty();
    }
    const AgentRegistry<InspectorOverlayAgent>& InspectorOverlayAgents() const
    {
        return inspector_overlay_agents_;
    }
    void AddInspectorOverlayAgent(InspectorOverlayAgent* agent);
    void RemoveInspectorOverlayAgent(InspectorOverlayAgent* agent);

    bool HasInspectorPageAgents() const
    {
        return !inspector_page_agents_.IsEmpty();
    }
    const AgentRegistry<InspectorPageAgent>& InspectorPageAgents() const
    {
        return inspector_page_agents_;
    }
    void AddInspectorPageAgent(InspectorPageAgent* agent);
    void RemoveInspectorPageAgent(InspectorPageAgent* agent);

    bool HasInspectorPerformanceAgents() const
    {
        return !inspector_performance_agents_.IsEmpty();
    }
    const AgentRegistry<InspectorPerformanceAgent>& InspectorPerformanceAgents() const
    {
        return inspector_performance_agents_;
    }
    void AddInspectorPerformanceAgent(InspectorPerformanceAgent* agent);
    void RemoveInspectorPerformanceAgent(InspectorPerformanceAgent* agent);

    bool HasInspectorPerformanceTimelineAgents() const
    {
        return !inspector_performance_timeline_agents_.IsEmpty();
    }
    const AgentRegistry<InspectorPerformanceTimelineAgent>& InspectorPerformanceTimelineAgents() const
    {
        return inspector_performance_timeline_agents_;
    }
    void AddInspectorPerformanceTimelineAgent(InspectorPerformanceTimelineAgent* agent);
    void RemoveInspectorPerformanceTimelineAgent(InspectorPerformanceTimelineAgent* agent);

    bool HasInspectorPreloadAgents() const
    {
        return !inspector_preload_agents_.IsEmpty();
    }
    const AgentRegistry<InspectorPreloadAgent>& InspectorPreloadAgents() const
    {
        return inspector_preload_agents_;
    }
    void AddInspectorPreloadAgent(InspectorPreloadAgent* agent);
    void RemoveInspectorPreloadAgent(InspectorPreloadAgent* agent);

    bool HasInspectorTraceEventss() const
    {
        return !inspector_trace_eventss_.IsEmpty();
    }
    const AgentRegistry<InspectorTraceEvents>& InspectorTraceEventss() const
    {
        return inspector_trace_eventss_;
    }
    void AddInspectorTraceEvents(InspectorTraceEvents* agent);
    void RemoveInspectorTraceEvents(InspectorTraceEvents* agent);

    bool HasLCPScriptObservers() const
    {
        return !lcp_script_observers_.IsEmpty();
    }
    const AgentRegistry<LCPScriptObserver>& LCPScriptObservers() const
    {
        return lcp_script_observers_;
    }
    void AddLCPScriptObserver(LCPScriptObserver* agent);
    void RemoveLCPScriptObserver(LCPScriptObserver* agent);

    bool HasPerformanceMonitors() const
    {
        return !performance_monitors_.IsEmpty();
    }
    const AgentRegistry<PerformanceMonitor>& PerformanceMonitors() const
    {
        return performance_monitors_;
    }
    void AddPerformanceMonitor(PerformanceMonitor* agent);
    void RemovePerformanceMonitor(PerformanceMonitor* agent);

    // Queries process-wide. Intended for fast-return cases only.
    static bool HasAgentsGlobal(unsigned mask)
    {
        return s_existingAgents.load(std::memory_order_acquire) & mask;
    }

private:
    AgentRegistry<AdTracker> ad_trackers_;
    AgentRegistry<AnimationFrameTimingMonitor> animation_frame_timing_monitors_;
    AgentRegistry<DevToolsSession> dev_tools_sessions_;
    AgentRegistry<InspectorAnimationAgent> inspector_animation_agents_;
    AgentRegistry<InspectorAuditsAgent> inspector_audits_agents_;
    AgentRegistry<InspectorCSSAgent> inspector_css_agents_;
    AgentRegistry<InspectorDOMAgent> inspector_dom_agents_;
    AgentRegistry<InspectorDOMDebuggerAgent> inspector_dom_debugger_agents_;
    AgentRegistry<InspectorDOMSnapshotAgent> inspector_dom_snapshot_agents_;
    AgentRegistry<InspectorEmulationAgent> inspector_emulation_agents_;
    AgentRegistry<InspectorEventBreakpointsAgent> inspector_event_breakpoints_agents_;
    AgentRegistry<InspectorIssueReporter> inspector_issue_reporters_;
    AgentRegistry<InspectorLayerTreeAgent> inspector_layer_tree_agents_;
    AgentRegistry<InspectorLogAgent> inspector_log_agents_;
    AgentRegistry<InspectorMediaAgent> inspector_media_agents_;
    AgentRegistry<InspectorNetworkAgent> inspector_network_agents_;
    AgentRegistry<InspectorOverlayAgent> inspector_overlay_agents_;
    AgentRegistry<InspectorPageAgent> inspector_page_agents_;
    AgentRegistry<InspectorPerformanceAgent> inspector_performance_agents_;
    AgentRegistry<InspectorPerformanceTimelineAgent> inspector_performance_timeline_agents_;
    AgentRegistry<InspectorPreloadAgent> inspector_preload_agents_;
    AgentRegistry<InspectorTraceEvents> inspector_trace_eventss_;
    AgentRegistry<LCPScriptObserver> lcp_script_observers_;
    AgentRegistry<PerformanceMonitor> performance_monitors_;

    // Number of sinks with an enabled agent of each type, used to keep
    // |s_existingAgents| up to date.
    // Access must be guarded by AgentCountMutex in the source file.
    static unsigned s_numSinksWithAdTracker;
    static unsigned s_numSinksWithAnimationFrameTimingMonitor;
    static unsigned s_numSinksWithDevToolsSession;
    static unsigned s_numSinksWithInspectorAnimationAgent;
    static unsigned s_numSinksWithInspectorAuditsAgent;
    static unsigned s_numSinksWithInspectorCSSAgent;
    static unsigned s_numSinksWithInspectorDOMAgent;
    static unsigned s_numSinksWithInspectorDOMDebuggerAgent;
    static unsigned s_numSinksWithInspectorDOMSnapshotAgent;
    static unsigned s_numSinksWithInspectorEmulationAgent;
    static unsigned s_numSinksWithInspectorEventBreakpointsAgent;
    static unsigned s_numSinksWithInspectorIssueReporter;
    static unsigned s_numSinksWithInspectorLayerTreeAgent;
    static unsigned s_numSinksWithInspectorLogAgent;
    static unsigned s_numSinksWithInspectorMediaAgent;
    static unsigned s_numSinksWithInspectorNetworkAgent;
    static unsigned s_numSinksWithInspectorOverlayAgent;
    static unsigned s_numSinksWithInspectorPageAgent;
    static unsigned s_numSinksWithInspectorPerformanceAgent;
    static unsigned s_numSinksWithInspectorPerformanceTimelineAgent;
    static unsigned s_numSinksWithInspectorPreloadAgent;
    static unsigned s_numSinksWithInspectorTraceEvents;
    static unsigned s_numSinksWithLCPScriptObserver;
    static unsigned s_numSinksWithPerformanceMonitor;

    // Bit-set of types of enabled agent which exist in this process.
    // Always a bitwise-or of AgentType enumerators.
    static std::atomic<unsigned> s_existingAgents;
};

} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_CORE_PROBE_SINK_H_
