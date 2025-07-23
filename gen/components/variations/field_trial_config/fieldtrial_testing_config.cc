// Copyright 2025 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE SCHEMA DEFINITION AND DESCRIPTION IN
//   field_trial_testing_config_schema.json
//   fieldtrial_testing_config.json
// DO NOT EDIT.

#include "fieldtrial_testing_config.h"

namespace variations {

const char* const array_kFieldTrialConfig_enable_features_677[] = {
    "ZeroCopyTabCapture",
};
const Study::Platform array_kFieldTrialConfig_platforms_739[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_613[] = {
    {
        "Enabled_20230222",
        array_kFieldTrialConfig_platforms_739,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_677,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_676[] = {
    "ZeroSuggestPrefetchDebouncing",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_265[] = {
    {
        "ZeroSuggestPrefetchDebounceDelay",
        "300",
    },
    {
        "ZeroSuggestPrefetchDebounceFromLastRun",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_738[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_612[] = {
    {
        "Enabled_300ms_FromLastRun",
        array_kFieldTrialConfig_platforms_738,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_265,
        array_kFieldTrialConfig_enable_features_676,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_675[] = {
    "WinSystemLocationPermission",
};
const Study::Platform array_kFieldTrialConfig_platforms_737[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_611[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_737,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_675,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_674[] = {
    "WinSboxParallelProcessLaunch",
};
const Study::Platform array_kFieldTrialConfig_platforms_736[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_610[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_736,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_674,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_673[] = {
    "WinSboxNoFakeGdiInit",
};
const Study::Platform array_kFieldTrialConfig_platforms_735[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_609[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_735,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_673,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_672[] = {
    "Spark",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_264[] = {
    {
        "whats_new_customization",
        "ORIGINAL",
    },
    {
        "whats_new_survey_id",
        "nGcgtQoLx0ugnJ3q1cK0SbfqkdQd",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_734[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_671[] = {
    "Spark",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_263[] = {
    {
        "whats_new_customization",
        "BENEFITS",
    },
    {
        "whats_new_survey_id",
        "PsSZ5E6nP0ugnJ3q1cK0WcE1Zf8H",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_733[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_608[] = {
    {
        "Enabled_benefits",
        array_kFieldTrialConfig_platforms_733,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_263,
        array_kFieldTrialConfig_enable_features_671,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_original",
        array_kFieldTrialConfig_platforms_734,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_264,
        array_kFieldTrialConfig_enable_features_672,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_670[] = {
    "HappinessTrackingSurveysForDesktopWhatsNew",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_262[] = {
    {
        "en_site_id",
        "6bnVh68QF0ugnJ3q1cK0NQxjpCFS",
    },
    {
        "probability",
        "0.8",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_732[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_669[] = {
    "HappinessTrackingSurveysForDesktopWhatsNew",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_261[] = {
    {
        "en_site_id",
        "6bnVh68QF0ugnJ3q1cK0NQxjpCFS",
    },
    {
        "probability",
        "1.0",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_731[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_668[] = {
    "HappinessTrackingSurveysForDesktopWhatsNew",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_260[] = {
    {
        "en_site_id",
        "6bnVh68QF0ugnJ3q1cK0NQxjpCFS",
    },
    {
        "probability",
        "0.4",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_730[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_607[] = {
    {
        "Enabled_en_20241016",
        array_kFieldTrialConfig_platforms_730,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_260,
        array_kFieldTrialConfig_enable_features_668,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_de_20241016",
        array_kFieldTrialConfig_platforms_731,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_261,
        array_kFieldTrialConfig_enable_features_669,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_ja_20241016",
        array_kFieldTrialConfig_platforms_732,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_262,
        array_kFieldTrialConfig_enable_features_670,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_667[] = {
    "IPH_WebUITabStrip",
    "WebUITabStrip",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_259[] = {
    {
        "availability",
        "any",
    },
    {
        "event_trigger",
        "name:webui_tab_strip_iph_triggered;comparator:<3;window:1;storage:365",
    },
    {
        "event_used",
        "name:webui_tab_strip_opened;comparator:==0;window:90;storage:365",
    },
    {
        "session_rate",
        "any",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_729[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_606[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_729,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_259,
        array_kFieldTrialConfig_enable_features_667,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_666[] = {
    "WebRtcThreadsUseResourceEfficientType",
};
const Study::Platform array_kFieldTrialConfig_platforms_728[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_605[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_728,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_666,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_665[] = {
    "WebRtcEncodedTransformDirectCallback",
};
const Study::Platform array_kFieldTrialConfig_platforms_727[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_604[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_727,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_665,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_664[] = {
    "WebRtcAudioSinkUseTimestampAligner",
};
const Study::Platform array_kFieldTrialConfig_platforms_726[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_603[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_726,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_664,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_258[] = {
    {
        "max_post_decode_queue_size",
        "10",
    },
    {
        "reduce_steady_state_queue_size_threshold",
        "20",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_725[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_602[] = {
    {
        "min_pacing:0ms,max_decode_queue_size:8,",
        array_kFieldTrialConfig_platforms_725,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_258,
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_724[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_601[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_724,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_663[] = {
    "WebRtcAllowH265Receive",
};
const Study::Platform array_kFieldTrialConfig_platforms_723[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_662[] = {
    "WebRtcAllowH265Receive",
    "WebRtcAllowH265Send",
};
const Study::Platform array_kFieldTrialConfig_platforms_722[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_600[] = {
    {
        "Enabled_SendReceive",
        array_kFieldTrialConfig_platforms_722,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_662,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_ReceiveOnly",
        array_kFieldTrialConfig_platforms_723,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_663,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_661[] = {
    "WebRTC-Video-H26xPacketBuffer",
};
const Study::Platform array_kFieldTrialConfig_platforms_721[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_599[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_721,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_661,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_720[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_598[] = {
    {
        "Enabled,_20230607_BETA",
        array_kFieldTrialConfig_platforms_720,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_719[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_597[] = {
    {
        "2_V1",
        array_kFieldTrialConfig_platforms_719,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_718[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_596[] = {
    {
        "Enabled,max_queue_time:75ms,_V4",
        array_kFieldTrialConfig_platforms_718,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_717[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_595[] = {
    {
        "Enabled,_20221205",
        array_kFieldTrialConfig_platforms_717,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_716[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_594[] = {
    {
        "262144,_V1",
        array_kFieldTrialConfig_platforms_716,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_715[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_593[] = {
    {
        "num_stddev_delay_clamp:5,num_stddev_delay_outlier:2,num_stddev_size_outlier:2,estimate_noise_when_congested:false,_20230118_BETA",
        array_kFieldTrialConfig_platforms_715,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_714[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_592[] = {
    {
        "Enabled,ResolveStunHostnameForFamily:true,PreferGlobalIPv6Address:true,DiversifyIpv6Interfaces:true,_20220929",
        array_kFieldTrialConfig_platforms_714,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_713[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_591[] = {
    {
        "enabled:true,_V1",
        array_kFieldTrialConfig_platforms_713,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_712[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_590[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_712,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_711[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_589[] = {
    {
        "network_state_probe_duration:200ms,network_state_interval:10s,min_probe_delta:20ms,est_lower_than_network_ratio:0.7,skip_if_est_larger_than_fraction_"
        "of_max:0.9,alr_scale:1.5,step_size:1.5",
        array_kFieldTrialConfig_platforms_711,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_710[] = {
    Study::PLATFORM_WINDOWS,
};
const Study::Platform array_kFieldTrialConfig_platforms_709[] = {
    Study::PLATFORM_WINDOWS,
};
const Study::Platform array_kFieldTrialConfig_platforms_708[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_588[] = {
    {
        "Enabled:true,CandidateFactors:1.02|1.0|0.95,DelayBasedCandidate:true,HigherBwBiasFactor:0.0002,HigherLogBwBiasFactor:0.02,"
        "ObservationDurationLowerBound:250ms,InstantUpperBoundBwBalance:75kbps,BwRampupUpperBoundFactor:1000000.0,InstantUpperBoundTemporalWeightFactor:0.9,"
        "TemporalWeightFactor:0.9,MaxIncreaseFactor:1.3,NewtonStepSize:0.75,InherentLossUpperBoundBwBalance:75kbps,LossThresholdOfHighBandwidthPreference:0.15,"
        "_20220905",
        array_kFieldTrialConfig_platforms_708,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled:true,CandidateFactors:1.02|1.0|0.95,DelayBasedCandidate:true,HigherBwBiasFactor:0.0002,HigherLogBwBiasFactor:0.02,"
        "ObservationDurationLowerBound:250ms,InstantUpperBoundBwBalance:75kbps,BwRampupUpperBoundFactor:1000000.0,InstantUpperBoundTemporalWeightFactor:0.9,"
        "TemporalWeightFactor:0.9,MaxIncreaseFactor:1.3,NewtonStepSize:0.75,InherentLossUpperBoundBwBalance:75kbps,LossThresholdOfHighBandwidthPreference:0.15,"
        "NotIncreaseIfInherentLossLessThanAverageLoss:true,_20220905",
        array_kFieldTrialConfig_platforms_709,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled:true,CandidateFactors:1.02|1.0|0.95,DelayBasedCandidate:true,HigherBwBiasFactor:0.0002,HigherLogBwBiasFactor:0.02,"
        "ObservationDurationLowerBound:250ms,InstantUpperBoundBwBalance:75kbps,BwRampupUpperBoundFactor:1000000.0,InstantUpperBoundTemporalWeightFactor:0.9,"
        "TemporalWeightFactor:0.9,MaxIncreaseFactor:1.3,NewtonStepSize:0.75,InherentLossUpperBoundBwBalance:75kbps,LossThresholdOfHighBandwidthPreference:0.15,"
        "NotIncreaseIfInherentLossLessThanAverageLoss:true,TrendlineIntegrationEnabled:true,TrendlineObservationsWindowSize:2,_20220905",
        array_kFieldTrialConfig_platforms_710,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_707[] = {
    Study::PLATFORM_WINDOWS,
};
const Study::Platform array_kFieldTrialConfig_platforms_706[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_587[] = {
    {
        "burst:20ms,_V1",
        array_kFieldTrialConfig_platforms_706,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "burst:40ms,_V1",
        array_kFieldTrialConfig_platforms_707,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_705[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_586[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_705,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_704[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_585[] = {
    {
        "enable_stable_playout_delay:true,reinit_after_expands:1000",
        array_kFieldTrialConfig_platforms_704,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_703[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_584[] = {
    {
        "Enabled,switch_to_agc2:true,target_range_min_dbfs:-50,target_range_max_dbfs:-30,max_gain_db:50,initial_gain_db:15,max_gain_change_db_per_second:6,"
        "headroom_db:5,enable_clipping_predictor:true,disallow_transient_suppressor_usage:true,_20230614",
        array_kFieldTrialConfig_platforms_703,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_702[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_583[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_702,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_701[] = {
    Study::PLATFORM_WINDOWS,
};
const Study::Platform array_kFieldTrialConfig_platforms_700[] = {
    Study::PLATFORM_WINDOWS,
};
const Study::Platform array_kFieldTrialConfig_platforms_699[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_582[] = {
    {
        "0.1",
        array_kFieldTrialConfig_platforms_699,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "0.3",
        array_kFieldTrialConfig_platforms_700,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "0.7",
        array_kFieldTrialConfig_platforms_701,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_698[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_581[] = {
    {
        "1",
        array_kFieldTrialConfig_platforms_698,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_660[] = {
    "WebGPUUseTintIR",
};
const Study::Platform array_kFieldTrialConfig_platforms_697[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_580[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_697,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_660,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_659[] = {
    "WebGPUUseDXC2",
};
const Study::Platform array_kFieldTrialConfig_platforms_696[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_579[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_696,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_659,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_658[] = {
    "CollectWebGPUSupportMetrics",
};
const Study::Platform array_kFieldTrialConfig_platforms_695[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_578[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_695,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_658,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_87[] = {
    "WebGPUService",
};
const Study::Platform array_kFieldTrialConfig_platforms_694[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_657[] = {
    "WebGPUService",
};
const Study::Platform array_kFieldTrialConfig_platforms_693[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_577[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_693,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_657,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Disabled",
        array_kFieldTrialConfig_platforms_694,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_87,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_656[] = {
    "WebContentsDiscard",
};
const Study::Platform array_kFieldTrialConfig_platforms_692[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_576[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_692,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_656,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_655[] = {
    "WebContentsCaptureHiDPI",
};
const Study::Platform array_kFieldTrialConfig_platforms_691[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_575[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_691,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_655,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_654[] = {
    "WebAudioBypassOutputBuffering",
};
const Study::Platform array_kFieldTrialConfig_platforms_690[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_574[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_690,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_654,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_86[] = {
    "WebAssemblyInliningCallIndirect",
};
const Study::Platform array_kFieldTrialConfig_platforms_689[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_653[] = {
    "WebAssemblyInliningCallIndirect",
};
const Study::Platform array_kFieldTrialConfig_platforms_688[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_573[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_688,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_653,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Control",
        array_kFieldTrialConfig_platforms_689,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_86,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_85[] = {
    "WebAssemblyDeopt",
};
const Study::Platform array_kFieldTrialConfig_platforms_687[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_652[] = {
    "WebAssemblyDeopt",
};
const Study::Platform array_kFieldTrialConfig_platforms_686[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_572[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_686,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_652,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Control",
        array_kFieldTrialConfig_platforms_687,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_85,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_651[] = {
    "VisitedURLRankingService",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_257[] = {
    {
        "VisitedURLRankingFetchDurationInHoursParam",
        "168",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_685[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_571[] = {
    {
        "VisitedURLRankingService",
        array_kFieldTrialConfig_platforms_685,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_257,
        array_kFieldTrialConfig_enable_features_651,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_650[] = {
    "VisibilityAwareResourceScheduler",
};
const Study::Platform array_kFieldTrialConfig_platforms_684[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_570[] = {
    {
        "Enabled_20230807",
        array_kFieldTrialConfig_platforms_684,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_650,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_649[] = {
    "ViewTransitionOnNavigation",
};
const Study::Platform array_kFieldTrialConfig_platforms_683[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_569[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_683,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_649,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_648[] = {
    "VideoDecodeBatching",
};
const Study::Platform array_kFieldTrialConfig_platforms_682[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_568[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_682,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_648,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_647[] = {
    "VerifyDidCommitParams",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_256[] = {
    {
        "gesture",
        "true",
    },
    {
        "http_status_code",
        "true",
    },
    {
        "intended_as_new_entry",
        "true",
    },
    {
        "is_overriding_user_agent",
        "true",
    },
    {
        "method",
        "true",
    },
    {
        "origin",
        "true",
    },
    {
        "post_id",
        "true",
    },
    {
        "should_replace_current_entry",
        "false",
    },
    {
        "should_update_history",
        "true",
    },
    {
        "url",
        "true",
    },
    {
        "url_is_unreachable",
        "false",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_681[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_646[] = {
    "VerifyDidCommitParams",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_255[] = {
    {
        "gesture",
        "true",
    },
    {
        "http_status_code",
        "true",
    },
    {
        "intended_as_new_entry",
        "true",
    },
    {
        "is_overriding_user_agent",
        "true",
    },
    {
        "method",
        "true",
    },
    {
        "origin",
        "true",
    },
    {
        "post_id",
        "true",
    },
    {
        "should_replace_current_entry",
        "false",
    },
    {
        "should_update_history",
        "true",
    },
    {
        "url",
        "true",
    },
    {
        "url_is_unreachable",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_680[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_645[] = {
    "VerifyDidCommitParams",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_254[] = {
    {
        "gesture",
        "true",
    },
    {
        "http_status_code",
        "true",
    },
    {
        "intended_as_new_entry",
        "true",
    },
    {
        "is_overriding_user_agent",
        "true",
    },
    {
        "method",
        "true",
    },
    {
        "origin",
        "true",
    },
    {
        "post_id",
        "true",
    },
    {
        "should_replace_current_entry",
        "true",
    },
    {
        "should_update_history",
        "true",
    },
    {
        "url",
        "true",
    },
    {
        "url_is_unreachable",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_679[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_567[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_679,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_254,
        array_kFieldTrialConfig_enable_features_645,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledWithoutShouldReplace",
        array_kFieldTrialConfig_platforms_680,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_255,
        array_kFieldTrialConfig_enable_features_646,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledWithoutShouldReplaceAndURLIsUnreachable",
        array_kFieldTrialConfig_platforms_681,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_256,
        array_kFieldTrialConfig_enable_features_647,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_644[] = {
    "VSyncDecoding",
};
const Study::Platform array_kFieldTrialConfig_platforms_678[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_566[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_678,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_644,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_643[] = {
    "V8UpdateLimitAfterLoading",
};
const Study::Platform array_kFieldTrialConfig_platforms_677[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_565[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_677,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_643,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_642[] = {
    "V8SlowHistograms",
};
const Study::Platform array_kFieldTrialConfig_platforms_676[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_84[] = {
    "V8SlowHistograms",
};
const Study::Platform array_kFieldTrialConfig_platforms_675[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_564[] = {
    {
        "Control",
        array_kFieldTrialConfig_platforms_675,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_84,
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_676,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_642,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_83[] = {
    "V8SingleThreadedGCInBackgroundParallelPause",
};
const char* const array_kFieldTrialConfig_enable_features_641[] = {
    "V8SingleThreadedGCInBackground",
    "V8SingleThreadedGCInBackgroundNoIncrementalMarking",
};
const Study::Platform array_kFieldTrialConfig_platforms_674[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_82[] = {
    "V8SingleThreadedGCInBackgroundNoIncrementalMarking",
};
const char* const array_kFieldTrialConfig_enable_features_640[] = {
    "V8SingleThreadedGCInBackground",
    "V8SingleThreadedGCInBackgroundParallelPause",
};
const Study::Platform array_kFieldTrialConfig_platforms_673[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_81[] = {
    "V8SingleThreadedGCInBackgroundNoIncrementalMarking",
    "V8SingleThreadedGCInBackgroundParallelPause",
};
const char* const array_kFieldTrialConfig_enable_features_639[] = {
    "V8SingleThreadedGCInBackground",
};
const Study::Platform array_kFieldTrialConfig_platforms_672[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_563[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_672,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_639,
        array_kFieldTrialConfig_disable_features_81,
        nullptr,
        {},
        {},
        {},
    },
    {
        "ParallelPause",
        array_kFieldTrialConfig_platforms_673,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_640,
        array_kFieldTrialConfig_disable_features_82,
        nullptr,
        {},
        {},
        {},
    },
    {
        "NoIncrementalMarking",
        array_kFieldTrialConfig_platforms_674,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_641,
        array_kFieldTrialConfig_disable_features_83,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_80[] = {
    "V8SideStepTransitions",
};
const Study::Platform array_kFieldTrialConfig_platforms_671[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_638[] = {
    "V8SideStepTransitions",
};
const Study::Platform array_kFieldTrialConfig_platforms_670[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_562[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_670,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_638,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Disabled",
        array_kFieldTrialConfig_platforms_671,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_80,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_637[] = {
    "V8SeparateGCPhases",
};
const Study::Platform array_kFieldTrialConfig_platforms_669[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_561[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_669,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_637,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_79[] = {
    "V8ScavengerHigherCapacity",
};
const Study::Platform array_kFieldTrialConfig_platforms_668[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_636[] = {
    "V8ScavengerHigherCapacity",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_253[] = {
    {
        "V8ScavengerMaxCapacity",
        "64",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_667[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_635[] = {
    "V8ScavengerHigherCapacity",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_252[] = {
    {
        "V8ScavengerMaxCapacity",
        "32",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_666[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_634[] = {
    "V8ScavengerHigherCapacity",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_251[] = {
    {
        "V8ScavengerMaxCapacity",
        "16",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_665[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_560[] = {
    {
        "V8ScavengerMaxCapacity16MB",
        array_kFieldTrialConfig_platforms_665,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_251,
        array_kFieldTrialConfig_enable_features_634,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "V8ScavengerMaxCapacity32MB",
        array_kFieldTrialConfig_platforms_666,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_252,
        array_kFieldTrialConfig_enable_features_635,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "V8ScavengerMaxCapacity64MB",
        array_kFieldTrialConfig_platforms_667,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_253,
        array_kFieldTrialConfig_enable_features_636,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Control",
        array_kFieldTrialConfig_platforms_668,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_79,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_78[] = {
    "ConsumeCompileHints",
    "LocalCompileHints",
};
const Study::Platform array_kFieldTrialConfig_platforms_664[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_77[] = {
    "ConsumeCompileHints",
};
const char* const array_kFieldTrialConfig_enable_features_633[] = {
    "LocalCompileHints",
};
const Study::Platform array_kFieldTrialConfig_platforms_663[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_559[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_663,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_633,
        array_kFieldTrialConfig_disable_features_77,
        nullptr,
        {},
        {},
        {},
    },
    {
        "Control",
        array_kFieldTrialConfig_platforms_664,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_78,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_76[] = {
    "V8IntelJCCErratumMitigation",
};
const char* const array_kFieldTrialConfig_enable_features_632[] = {
    "V8SlowHistogramsIntelJCCErratumMitigation",
};
const Study::Platform array_kFieldTrialConfig_platforms_662[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_631[] = {
    "V8IntelJCCErratumMitigation",
    "V8SlowHistogramsIntelJCCErratumMitigation",
};
const Study::Platform array_kFieldTrialConfig_platforms_661[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_630[] = {
    "V8IntelJCCErratumMitigation",
};
const Study::Platform array_kFieldTrialConfig_platforms_660[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_558[] = {
    {
        "EnabledNoSlowHistogram",
        array_kFieldTrialConfig_platforms_660,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_630,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_661,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_631,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Control",
        array_kFieldTrialConfig_platforms_662,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_632,
        array_kFieldTrialConfig_disable_features_76,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_629[] = {
    "V8IncrementalMarkingStartUserVisible",
};
const Study::Platform array_kFieldTrialConfig_platforms_659[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_557[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_659,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_629,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_628[] = {
    "V8GCSpeedUsesCounters",
};
const Study::Platform array_kFieldTrialConfig_platforms_658[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_556[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_658,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_628,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_75[] = {
    "V8FlushBaselineCode",
};
const Study::Platform array_kFieldTrialConfig_platforms_657[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_627[] = {
    "V8FlushBaselineCode",
};
const Study::Platform array_kFieldTrialConfig_platforms_656[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_555[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_656,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_627,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Disabled",
        array_kFieldTrialConfig_platforms_657,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_75,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_626[] = {
    "V8ExternalMemoryAccountedInGlobalLimit",
};
const Study::Platform array_kFieldTrialConfig_platforms_655[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_554[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_655,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_626,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_74[] = {
    "V8EfficiencyModeTiering",
};
const Study::Platform array_kFieldTrialConfig_platforms_654[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_625[] = {
    "V8EfficiencyModeTiering",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_250[] = {
    {
        "V8EfficiencyModeTieringDelayTurbofan",
        "15000",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_653[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_624[] = {
    "V8EfficiencyModeTiering",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_249[] = {
    {
        "V8EfficiencyModeTieringDelayTurbofan",
        "0",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_652[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_623[] = {
    "V8EfficiencyModeTiering",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_248[] = {
    {
        "V8EfficiencyModeTieringDelayTurbofan",
        "10000",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_651[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_553[] = {
    {
        "Delay10k",
        array_kFieldTrialConfig_platforms_651,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_248,
        array_kFieldTrialConfig_enable_features_623,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "NoTurbofan",
        array_kFieldTrialConfig_platforms_652,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_249,
        array_kFieldTrialConfig_enable_features_624,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Delay15k",
        array_kFieldTrialConfig_platforms_653,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_250,
        array_kFieldTrialConfig_enable_features_625,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Control",
        array_kFieldTrialConfig_platforms_654,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_74,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_622[] = {
    "V8CppGCEnableLargerCage",
};
const Study::Platform array_kFieldTrialConfig_platforms_650[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_552[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_650,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_622,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_621[] = {
    "ProduceCompileHints2",
};
const Study::Platform array_kFieldTrialConfig_platforms_649[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_73[] = {
    "ProduceCompileHints2",
};
const Study::Platform array_kFieldTrialConfig_platforms_648[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_551[] = {
    {
        "Disabled",
        array_kFieldTrialConfig_platforms_648,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_73,
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_649,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_621,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_72[] = {
    "V8FlushCodeBasedOnTime",
};
const char* const array_kFieldTrialConfig_enable_features_620[] = {
    "V8FlushCodeBasedOnTabVisibility",
};
const Study::Platform array_kFieldTrialConfig_platforms_647[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_71[] = {
    "V8FlushCodeBasedOnTabVisibility",
};
const char* const array_kFieldTrialConfig_enable_features_619[] = {
    "V8FlushCodeBasedOnTime",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_247[] = {
    {
        "V8FlushCodeOldTime",
        "180",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_646[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_70[] = {
    "V8FlushCodeBasedOnTabVisibility",
};
const char* const array_kFieldTrialConfig_enable_features_618[] = {
    "V8FlushCodeBasedOnTime",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_246[] = {
    {
        "V8FlushCodeOldTime",
        "45",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_645[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_69[] = {
    "V8FlushCodeBasedOnTabVisibility",
};
const char* const array_kFieldTrialConfig_enable_features_617[] = {
    "V8FlushCodeBasedOnTime",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_245[] = {
    {
        "V8FlushCodeOldTime",
        "30",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_644[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_68[] = {
    "V8FlushCodeBasedOnTabVisibility",
};
const char* const array_kFieldTrialConfig_enable_features_616[] = {
    "V8FlushCodeBasedOnTime",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_244[] = {
    {
        "V8FlushCodeOldTime",
        "10",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_643[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_67[] = {
    "V8FlushCodeBasedOnTabVisibility",
};
const char* const array_kFieldTrialConfig_enable_features_615[] = {
    "V8FlushCodeBasedOnTime",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_243[] = {
    {
        "V8FlushCodeOldTime",
        "60",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_642[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_550[] = {
    {
        "FlushCodeBasedOnTime60",
        array_kFieldTrialConfig_platforms_642,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_243,
        array_kFieldTrialConfig_enable_features_615,
        array_kFieldTrialConfig_disable_features_67,
        nullptr,
        {},
        {},
        {},
    },
    {
        "FlushCodeBasedOnTime10",
        array_kFieldTrialConfig_platforms_643,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_244,
        array_kFieldTrialConfig_enable_features_616,
        array_kFieldTrialConfig_disable_features_68,
        nullptr,
        {},
        {},
        {},
    },
    {
        "FlushCodeBasedOnTime30",
        array_kFieldTrialConfig_platforms_644,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_245,
        array_kFieldTrialConfig_enable_features_617,
        array_kFieldTrialConfig_disable_features_69,
        nullptr,
        {},
        {},
        {},
    },
    {
        "FlushCodeBasedOnTime45",
        array_kFieldTrialConfig_platforms_645,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_246,
        array_kFieldTrialConfig_enable_features_618,
        array_kFieldTrialConfig_disable_features_70,
        nullptr,
        {},
        {},
        {},
    },
    {
        "FlushCodeBasedOnTime180",
        array_kFieldTrialConfig_platforms_646,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_247,
        array_kFieldTrialConfig_enable_features_619,
        array_kFieldTrialConfig_disable_features_71,
        nullptr,
        {},
        {},
        {},
    },
    {
        "FlushCodeBasedOnTabVisibility",
        array_kFieldTrialConfig_platforms_647,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_620,
        array_kFieldTrialConfig_disable_features_72,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_614[] = {
    "UsernameFirstFlowWithIntermediateValuesPredictions",
};
const Study::Platform array_kFieldTrialConfig_platforms_641[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_549[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_641,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_614,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_613[] = {
    "UserBypassUI",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_242[] = {
    {
        "expiration",
        "90d",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_640[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_548[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_640,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_242,
        array_kFieldTrialConfig_enable_features_613,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_612[] = {
    "UseThreadPriorityLowest",
};
const Study::Platform array_kFieldTrialConfig_platforms_639[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_547[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_639,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_612,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_611[] = {
    "UseSnappyForParkableStrings",
};
const Study::Platform array_kFieldTrialConfig_platforms_638[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_546[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_638,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_611,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_610[] = {
    "UseSmartRefForGPUFenceHandle",
};
const Study::Platform array_kFieldTrialConfig_platforms_637[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_545[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_637,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_610,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_609[] = {
    "UseRustJsonParser",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_241[] = {
    {
        "UseRustJsonParserInCurrentSequence",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_636[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_544[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_636,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_241,
        array_kFieldTrialConfig_enable_features_609,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_608[] = {
    "UseNewEncryptionKeyForWebData",
};
const Study::Platform array_kFieldTrialConfig_platforms_635[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_543[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_635,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_608,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_607[] = {
    "UseMoveNotCopyInMergeTreeUpdate",
};
const Study::Platform array_kFieldTrialConfig_platforms_634[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_542[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_634,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_607,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_606[] = {
    "UseMoveNotCopyInAXTreeCombiner",
};
const Study::Platform array_kFieldTrialConfig_platforms_633[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_541[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_633,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_606,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_605[] = {
    "UseItemSnippetsAPI",
};
const Study::Platform array_kFieldTrialConfig_platforms_632[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_540[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_632,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_605,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_604[] = {
    "UseDMSAAForTiles",
};
const Study::Platform array_kFieldTrialConfig_platforms_631[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_539[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_631,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_604,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_603[] = {
    "UseClientGmbInterface",
};
const Study::Platform array_kFieldTrialConfig_platforms_630[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_538[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_630,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_603,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_602[] = {
    "UseBrowserCalculatedOrigins",
};
const Study::Platform array_kFieldTrialConfig_platforms_629[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_537[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_629,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_602,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_601[] = {
    "UseBoringSSLForRandBytes",
};
const Study::Platform array_kFieldTrialConfig_platforms_628[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_536[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_628,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_601,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_600[] = {
    "UseAsyncOsCryptInLoginDatabase",
};
const Study::Platform array_kFieldTrialConfig_platforms_627[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_535[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_627,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_600,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_599[] = {
    "WebAppDontAddExistingAppsToSync",
};
const Study::Platform array_kFieldTrialConfig_platforms_626[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_534[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_626,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_599,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_598[] = {
    "ExplicitBrowserSigninUIOnDesktop",
    "SyncEnableContactInfoDataTypeInTransportMode",
};
const Study::Platform array_kFieldTrialConfig_platforms_625[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_533[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_625,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_598,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_597[] = {
    "OutlineSilhouetteIcon",
};
const Study::Platform array_kFieldTrialConfig_platforms_624[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_532[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_624,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_597,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_596[] = {
    "PreloadMediaEngagementData",
};
const Study::Platform array_kFieldTrialConfig_platforms_623[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_531[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_623,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_596,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_595[] = {
    "UiaProvider",
};
const Study::Platform array_kFieldTrialConfig_platforms_622[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_530[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_622,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_595,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_594[] = {
    "UMAPseudoMetricsEffect",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_240[] = {
    {
        "multiplicative_factor",
        "1.05",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_621[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_529[] = {
    {
        "BigEffect_01",
        array_kFieldTrialConfig_platforms_621,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_240,
        array_kFieldTrialConfig_enable_features_594,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_593[] = {
    "UMANonUniformityLogNormal",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_239[] = {
    {
        "delta",
        "0.01",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_620[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_528[] = {
    {
        "group_01",
        array_kFieldTrialConfig_platforms_620,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_239,
        array_kFieldTrialConfig_enable_features_593,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_592[] = {
    "UIEnableSharedImageCacheForGpu",
};
const Study::Platform array_kFieldTrialConfig_platforms_619[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_527[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_619,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_592,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_591[] = {
    "TrustTokens",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_238[] = {
    {
        "TrustTokenOperationsRequiringOriginTrial",
        "all-operations-require-origin-trial",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_618[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_526[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_618,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_238,
        array_kFieldTrialConfig_enable_features_591,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_590[] = {
    "TrustSafetySentimentSurveyV2",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_237[] = {
    {
        "browsing-data-probability",
        "0.0",
    },
    {
        "browsing-data-trigger-id",
        "1iSgej9Tq0ugnJ3q1cK0QwXZ12oo",
    },
    {
        "control-group-probability",
        "0.0",
    },
    {
        "control-group-trigger-id",
        "CXMbsBddw0ugnJ3q1cK0QJM1Hu8m",
    },
    {
        "download-warning-ui-probability",
        "0.0",
    },
    {
        "download-warning-ui-trigger-id",
        "7SS4sg4oR0ugnJ3q1cK0TNvCvd8U",
    },
    {
        "max-time-to-prompt",
        "60m",
    },
    {
        "min-session-time",
        "30s",
    },
    {
        "min-time-to-prompt",
        "2m",
    },
    {
        "ntp-visits-max-range",
        "4",
    },
    {
        "ntp-visits-min-range",
        "2",
    },
    {
        "password-check-probability",
        "0.0",
    },
    {
        "password-check-trigger-id",
        "Xd54YDVNJ0ugnJ3q1cK0UYBRruNH",
    },
    {
        "password-protection-ui-probability",
        "0.0",
    },
    {
        "password-protection-ui-trigger-id",
        "bQBRghu5w0ugnJ3q1cK0RrqdqVRP",
    },
    {
        "privacy-guide-probability",
        "0.0",
    },
    {
        "privacy-guide-trigger-id",
        "tqR1rjeDu0ugnJ3q1cK0P9yJEq7Z",
    },
    {
        "probability",
        "0.0",
    },
    {
        "safe-browsing-interstitial-probability",
        "0.0",
    },
    {
        "safe-browsing-interstitial-trigger-id",
        "Z9pSWP53n0ugnJ3q1cK0Y6YkGRpU",
    },
    {
        "safety-check-probability",
        "0.0",
    },
    {
        "safety-check-trigger-id",
        "YSDfPVMnX0ugnJ3q1cK0RxEhwkay",
    },
    {
        "safety-hub-interaction-probability",
        "0.0",
    },
    {
        "safety-hub-interaction-trigger-id",
        "TZq2S4frt0ugnJ3q1cK0Q5Yd4YJM",
    },
    {
        "safety-hub-notification-probability",
        "0.0",
    },
    {
        "safety-hub-notification-trigger-id",
        "kJV17f8Lv0ugnJ3q1cK0Nptk37ct",
    },
    {
        "trusted-surface-probability",
        "0.0",
    },
    {
        "trusted-surface-time",
        "5s",
    },
    {
        "trusted-surface-trigger-id",
        "CMniDmzgE0ugnJ3q1cK0U6PaEn1f",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_617[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_525[] = {
    {
        "Enabled_20240212",
        array_kFieldTrialConfig_platforms_617,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_237,
        array_kFieldTrialConfig_enable_features_590,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_589[] = {
    "TrustSafetySentimentSurvey",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_236[] = {
    {
        "max-time-to-prompt",
        "60m",
    },
    {
        "min-time-to-prompt",
        "2m",
    },
    {
        "ntp-visits-max-range",
        "4",
    },
    {
        "ntp-visits-min-range",
        "2",
    },
    {
        "privacy-sandbox-3-consent-accept-probability",
        "0.2",
    },
    {
        "privacy-sandbox-3-consent-accept-trigger-id",
        "5t9KNsR4e0ugnJ3q1cK0RPfRpsbm",
    },
    {
        "privacy-sandbox-3-consent-decline-probability",
        "0.2",
    },
    {
        "privacy-sandbox-3-consent-decline-trigger-id",
        "P5svv2BbH0ugnJ3q1cK0YhTWZkiM",
    },
    {
        "privacy-sandbox-3-notice-dismiss-probability",
        "0.2",
    },
    {
        "privacy-sandbox-3-notice-dismiss-trigger-id",
        "2gMg6iHpn0ugnJ3q1cK0XyL2C2EX",
    },
    {
        "privacy-sandbox-3-notice-ok-probability",
        "0.2",
    },
    {
        "privacy-sandbox-3-notice-ok-trigger-id",
        "vBraRD9GZ0ugnJ3q1cK0T1owvGGa",
    },
    {
        "privacy-sandbox-3-notice-settings-probability",
        "0.2",
    },
    {
        "privacy-sandbox-3-notice-settings-trigger-id",
        "WZpnNehvi0ugnJ3q1cK0Nsdcf1Vf",
    },
    {
        "privacy-settings-probability",
        "0.0",
    },
    {
        "probability",
        "1.0",
    },
    {
        "transactions-probability",
        "0.0",
    },
    {
        "trusted-surface-probability",
        "0.0",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_616[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_524[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_616,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_236,
        array_kFieldTrialConfig_enable_features_589,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_588[] = {
    "TruncateLanguageDetectionSample",
};
const Study::Platform array_kFieldTrialConfig_platforms_615[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_523[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_615,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_588,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_587[] = {
    "TransportSecurityFileWriterSchedule",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_235[] = {
    {
        "commit_interval",
        "10m",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_614[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_522[] = {
    {
        "Enabled10Minutes_20241105",
        array_kFieldTrialConfig_platforms_614,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_235,
        array_kFieldTrialConfig_enable_features_587,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_586[] = {
    "TranslateOpenSettings",
};
const Study::Platform array_kFieldTrialConfig_platforms_613[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_521[] = {
    {
        "TranslateBubbleOpenSettings",
        array_kFieldTrialConfig_platforms_613,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_586,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_66[] = {
    "TrackingProtection3pcdUx",
};
const Study::Platform array_kFieldTrialConfig_platforms_612[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_520[] = {
    {
        "Rewind",
        array_kFieldTrialConfig_platforms_612,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_66,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_585[] = {
    "TrackingProtection3pcd",
};
const Study::Platform array_kFieldTrialConfig_platforms_611[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_519[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_611,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_585,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_584[] = {
    "TopChromeWebUIUsesSpareRenderer",
};
const Study::Platform array_kFieldTrialConfig_platforms_610[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_518[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_610,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_584,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_583[] = {
    "ToolbarPinning",
};
const Study::Platform array_kFieldTrialConfig_platforms_609[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_517[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_609,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_583,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_582[] = {
    "TimedHTMLParserBudget",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_234[] = {
    {
        "default-parser-budget",
        "10ms",
    },
    {
        "long-parser-budget",
        "500ms",
    },
    {
        "num-yields-with-default-budget",
        "6",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_608[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_516[] = {
    {
        "group_10_500_6_20230911",
        array_kFieldTrialConfig_platforms_608,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_234,
        array_kFieldTrialConfig_enable_features_582,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_581[] = {
    "ThrottleUnimportantFrameTimers",
};
const Study::Platform array_kFieldTrialConfig_platforms_607[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_515[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_607,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_581,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_580[] = {
    "ThreadedScrollPreventRenderingStarvation",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_233[] = {
    {
        "threshold_ms",
        "100",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_606[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_514[] = {
    {
        "Enabled_100ms",
        array_kFieldTrialConfig_platforms_606,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_233,
        array_kFieldTrialConfig_enable_features_580,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_579[] = {
    "EnableConfigurableThreadCachePurgeInterval",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_232[] = {
    {
        "ThreadCacheDefaultPurgeInterval",
        "2s",
    },
    {
        "ThreadCacheMaxPurgeInterval",
        "60s",
    },
    {
        "ThreadCacheMinPurgeInterval",
        "1s",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_605[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_513[] = {
    {
        "interval_1_2_60_20230909",
        array_kFieldTrialConfig_platforms_605,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_232,
        array_kFieldTrialConfig_enable_features_579,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_578[] = {
    "EnableConfigurableThreadCacheMinCachedMemoryForPurging",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_231[] = {
    {
        "ThreadCacheMinCachedMemoryForPurgingBytes",
        "512000",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_604[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_512[] = {
    {
        "size_500kb_20230909",
        array_kFieldTrialConfig_platforms_604,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_231,
        array_kFieldTrialConfig_enable_features_578,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_65[] = {
    "TheoraVideoCodec",
};
const Study::Platform array_kFieldTrialConfig_platforms_603[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_511[] = {
    {
        "Disabled",
        array_kFieldTrialConfig_platforms_603,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_65,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_577[] = {
    "TextSizeAdjustImprovements",
};
const Study::Platform array_kFieldTrialConfig_platforms_602[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_510[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_602,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_577,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_576[] = {
    "TemplateUrlReconciliation",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_230[] = {
    {
        "reconcile_with_all_known_engines",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_601[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_509[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_601,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_230,
        array_kFieldTrialConfig_enable_features_576,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_575[] = {
    "TcpSocketIoCompletionPortWin",
};
const Study::Platform array_kFieldTrialConfig_platforms_600[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_508[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_600,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_575,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_574[] = {
    "TailoredSecurityIntegration",
};
const Study::Platform array_kFieldTrialConfig_platforms_599[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_507[] = {
    {
        "TailoredSecurityIntegration",
        array_kFieldTrialConfig_platforms_599,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_574,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_573[] = {
    "TabstripDeclutter",
};
const Study::Platform array_kFieldTrialConfig_platforms_598[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_506[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_598,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_573,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_572[] = {
    "TabStripCollectionStorage",
};
const Study::Platform array_kFieldTrialConfig_platforms_597[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_505[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_597,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_572,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_571[] = {
    "IPH_TabSearch",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_229[] = {
    {
        "availability",
        "any",
    },
    {
        "event_trigger",
        "name:tab_search_iph_tgr;comparator:==0;window:90;storage:360",
    },
    {
        "event_used",
        "name:tab_search_opened;comparator:==0;window:90;storage:360",
    },
    {
        "session_rate",
        "<3",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_596[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_504[] = {
    {
        "TabSearchIPH",
        array_kFieldTrialConfig_platforms_596,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_229,
        array_kFieldTrialConfig_enable_features_571,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_570[] = {
    "TabGroupsSaveUIUpdate",
    "TabGroupsSaveV2",
};
const Study::Platform array_kFieldTrialConfig_platforms_595[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_503[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_595,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_570,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_64[] = {
    "TabGroupsCollapseFreezing",
};
const Study::Platform array_kFieldTrialConfig_platforms_594[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_502[] = {
    {
        "Disabled",
        array_kFieldTrialConfig_platforms_594,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_64,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_569[] = {
    "TabGroupSyncServiceDesktopMigration",
};
const Study::Platform array_kFieldTrialConfig_platforms_593[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_501[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_593,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_569,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_568[] = {
    "IPH_TabAudioMuting",
    "TabAudioMuting",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_228[] = {
    {
        "availability",
        "any",
    },
    {
        "event_trigger",
        "name:tab_audio_muting_iph_triggered;comparator:==0;window:120;storage:365",
    },
    {
        "event_used",
        "name:tab_audio_muting_toggle_viewed;comparator:==0;window:120;storage:365",
    },
    {
        "session_rate",
        "==0",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_592[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_500[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_592,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_228,
        array_kFieldTrialConfig_enable_features_568,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_567[] = {
    "SyncIncreaseNudgeDelayForSingleClient",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_227[] = {
    {
        "SyncIncreaseNudgeDelayForSingleClientFactor",
        "2.0",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_591[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_499[] = {
    {
        "EnabledFactor2",
        array_kFieldTrialConfig_platforms_591,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_227,
        array_kFieldTrialConfig_enable_features_567,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_566[] = {
    "SuppressesLoadingPredictorOnSlowNetwork",
    "SuppressesPrerenderingOnSlowNetwork",
    "SuppressesSearchPrefetchOnSlowNetwork",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_226[] = {
    {
        "slow_network_threshold",
        "208ms",
    },
    {
        "slow_network_threshold_for_prerendering",
        "208ms",
    },
    {
        "slow_network_threshold_for_search_prefetch",
        "208ms",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_590[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_498[] = {
    {
        "SuppressesAll",
        array_kFieldTrialConfig_platforms_590,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_226,
        array_kFieldTrialConfig_enable_features_566,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_565[] = {
    "SubframeProcessReuseThresholds",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_225[] = {
    {
        "SubframeProcessReuseMemoryThreshold",
        "2147483648",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_589[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_497[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_589,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_225,
        array_kFieldTrialConfig_enable_features_565,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_564[] = {
    "SubSampleWindowProxyUsageMetrics",
};
const Study::Platform array_kFieldTrialConfig_platforms_588[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_496[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_588,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_564,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_563[] = {
    "StreamlineRendererInit",
};
const Study::Platform array_kFieldTrialConfig_platforms_587[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_495[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_587,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_563,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_562[] = {
    "StorageBuckets",
};
const Study::Platform array_kFieldTrialConfig_platforms_586[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_494[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_586,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_562,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_561[] = {
    "StandardizedBrowserZoom",
};
const Study::Platform array_kFieldTrialConfig_platforms_585[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_493[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_585,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_561,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_560[] = {
    "DeleteOrphanLocalStorageOnStartup",
    "DeleteStaleLocalStorageOnStartup",
    "EvictOrphanQuotaStorage",
    "EvictStaleQuotaStorage",
};
const Study::Platform array_kFieldTrialConfig_platforms_584[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_559[] = {
    "DeleteOrphanLocalStorageOnStartup",
    "DeleteStaleLocalStorageOnStartup",
    "EvictOrphanQuotaStorage",
    "EvictStaleQuotaStorage",
};
const Study::Platform array_kFieldTrialConfig_platforms_583[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_558[] = {
    "DeleteOrphanLocalStorageOnStartup",
    "DeleteStaleLocalStorageOnStartup",
    "EvictOrphanQuotaStorage",
    "EvictStaleQuotaStorage",
};
const Study::Platform array_kFieldTrialConfig_platforms_582[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_492[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_582,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_558,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Auto_Dogfood",
        array_kFieldTrialConfig_platforms_583,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_559,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Opt_In_Dogfood",
        array_kFieldTrialConfig_platforms_584,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_560,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_557[] = {
    "DeleteStaleSessionCookiesOnStartup",
};
const Study::Platform array_kFieldTrialConfig_platforms_581[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_556[] = {
    "DeleteStaleSessionCookiesOnStartup",
};
const Study::Platform array_kFieldTrialConfig_platforms_580[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_555[] = {
    "DeleteStaleSessionCookiesOnStartup",
};
const Study::Platform array_kFieldTrialConfig_platforms_579[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_491[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_579,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_555,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Auto_Dogfood",
        array_kFieldTrialConfig_platforms_580,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_556,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Opt_In_Dogfood",
        array_kFieldTrialConfig_platforms_581,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_557,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_554[] = {
    "SqlWALModeOnWebDatabase",
};
const Study::Platform array_kFieldTrialConfig_platforms_578[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_490[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_578,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_554,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_553[] = {
    "SplitCacheByNetworkIsolationKey",
};
const Study::Platform array_kFieldTrialConfig_platforms_577[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_489[] = {
    {
        "EnableFeatureForTests",
        array_kFieldTrialConfig_platforms_577,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_553,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_63[] = {
    "HttpCacheKeyingExperimentControlGroup2024",
    "SplitCacheByCrossSiteMainFrameNavigationBoolean",
    "SplitCacheByMainFrameNavigationInitiator",
};
const char* const array_kFieldTrialConfig_enable_features_552[] = {
    "SplitCacheByNavigationInitiator",
};
const Study::Platform array_kFieldTrialConfig_platforms_576[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_62[] = {
    "HttpCacheKeyingExperimentControlGroup2024",
    "SplitCacheByCrossSiteMainFrameNavigationBoolean",
    "SplitCacheByNavigationInitiator",
};
const char* const array_kFieldTrialConfig_enable_features_551[] = {
    "SplitCacheByMainFrameNavigationInitiator",
};
const Study::Platform array_kFieldTrialConfig_platforms_575[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_61[] = {
    "HttpCacheKeyingExperimentControlGroup2024",
    "SplitCacheByMainFrameNavigationInitiator",
    "SplitCacheByNavigationInitiator",
};
const char* const array_kFieldTrialConfig_enable_features_550[] = {
    "SplitCacheByCrossSiteMainFrameNavigationBoolean",
};
const Study::Platform array_kFieldTrialConfig_platforms_574[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_488[] = {
    {
        "CrossSiteMainFrameNavigationBoolean_CANARY_DEV_20240916",
        array_kFieldTrialConfig_platforms_574,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_550,
        array_kFieldTrialConfig_disable_features_61,
        nullptr,
        {},
        {},
        {},
    },
    {
        "MainFrameNavigationInitiator_CANARY_DEV_20240916",
        array_kFieldTrialConfig_platforms_575,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_551,
        array_kFieldTrialConfig_disable_features_62,
        nullptr,
        {},
        {},
        {},
    },
    {
        "NavigationInitiator_CANARY_DEV_20240916",
        array_kFieldTrialConfig_platforms_576,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_552,
        array_kFieldTrialConfig_disable_features_63,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_60[] = {
    "SpeculativeServiceWorkerStartup",
};
const char* const array_kFieldTrialConfig_enable_features_549[] = {
    "SpeculativeServiceWorkerWarmUp",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_224[] = {
    {
        "sw_warm_up_batch_timer",
        "1ms",
    },
    {
        "sw_warm_up_dry_run",
        "false",
    },
    {
        "sw_warm_up_duration",
        "10m",
    },
    {
        "sw_warm_up_first_batch_timer",
        "1ms",
    },
    {
        "sw_warm_up_from_loading_predictor",
        "true",
    },
    {
        "sw_warm_up_intersection_observer",
        "false",
    },
    {
        "sw_warm_up_on_idle_timeout",
        "true",
    },
    {
        "sw_warm_up_on_pointerdown",
        "true",
    },
    {
        "sw_warm_up_on_pointerover",
        "true",
    },
    {
        "sw_warm_up_on_visible",
        "false",
    },
    {
        "sw_warm_up_request_queue_length",
        "100",
    },
    {
        "sw_warm_up_wait_for_load",
        "false",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_573[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_487[] = {
    {
        "StayPrewarmed10m_20240315",
        array_kFieldTrialConfig_platforms_573,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_224,
        array_kFieldTrialConfig_enable_features_549,
        array_kFieldTrialConfig_disable_features_60,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_548[] = {
    "SpdyHeadersToHttpResponseUseBuilder",
};
const Study::Platform array_kFieldTrialConfig_platforms_572[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_486[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_572,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_548,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_547[] = {
    "SkipUnnecessaryRemoteFrameGeometryPropagation",
};
const Study::Platform array_kFieldTrialConfig_platforms_571[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_485[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_571,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_547,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_546[] = {
    "SkipPagehideInCommitForDSENavigation",
};
const Study::Platform array_kFieldTrialConfig_platforms_570[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_484[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_570,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_546,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_545[] = {
    "SkiaGraphite",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_223[] = {
    {
        "dawn_backend_validation",
        "false",
    },
    {
        "dawn_skip_validation",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_569[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_483[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_569,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_223,
        array_kFieldTrialConfig_enable_features_545,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_544[] = {
    "SingleVideoFrameRateThrottling",
};
const Study::Platform array_kFieldTrialConfig_platforms_568[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_482[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_568,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_544,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_543[] = {
    "SigninInterceptSimpleButtons",
};
const Study::Platform array_kFieldTrialConfig_platforms_567[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_481[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_567,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_543,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_542[] = {
    "IPH_SideSearch",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_222[] = {
    {
        "availability",
        "any",
    },
    {
        "event_trigger",
        "name:side_search_iph_tgr;comparator:==0;window:90;storage:360",
    },
    {
        "event_used",
        "name:side_search_opened;comparator:==0;window:90;storage:360",
    },
    {
        "session_rate",
        "<3",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_566[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_480[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_566,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_222,
        array_kFieldTrialConfig_enable_features_542,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_541[] = {
    "ResponsiveToolbar",
};
const Study::Platform array_kFieldTrialConfig_platforms_565[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_540[] = {
    "IPH_SidePanelGenericPinnableFeature",
    "ResponsiveToolbar",
    "SidePanelPinning",
};
const Study::Platform array_kFieldTrialConfig_platforms_564[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_479[] = {
    {
        "EnabledWithSidePanelPinning",
        array_kFieldTrialConfig_platforms_564,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_540,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledWithoutSidePanelPinning",
        array_kFieldTrialConfig_platforms_565,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_541,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_539[] = {
    "SidePanelJourneys",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_221[] = {
    {
        "SidePanelJourneysOpensFromOmnibox",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_563[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_478[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_563,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_221,
        array_kFieldTrialConfig_enable_features_539,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_59[] = {
    "SideSearch",
};
const char* const array_kFieldTrialConfig_enable_features_538[] = {
    "SidePanelCompanion",
    "SidePanelCompanionChromeOS",
    "VisualQuerySuggestions",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_220[] = {
    {
        "open-companion-for-image-search",
        "false",
    },
    {
        "open-companion-for-web-search",
        "false",
    },
    {
        "open-contextual-lens-panel",
        "false",
    },
    {
        "open-links-in-current-tab",
        "false",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_562[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_477[] = {
    {
        "EnableCompanionChromeOS_20240222",
        array_kFieldTrialConfig_platforms_562,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_220,
        array_kFieldTrialConfig_enable_features_538,
        array_kFieldTrialConfig_disable_features_59,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_537[] = {
    "ShowSuggestionsOnAutofocus",
};
const Study::Platform array_kFieldTrialConfig_platforms_561[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_476[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_561,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_537,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_536[] = {
    "DesktopScreenshots",
};
const Study::Platform array_kFieldTrialConfig_platforms_560[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_475[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_560,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_536,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_535[] = {
    "SharedWorkerBlobURLFix",
};
const Study::Platform array_kFieldTrialConfig_platforms_559[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_474[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_559,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_535,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_534[] = {
    "IPH_DesktopSharedHighlighting",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_219[] = {
    {
        "availability",
        "any",
    },
    {
        "event_1",
        "name:iph_desktop_shared_highlighting_trigger;comparator:==0;window:7;storage:360",
    },
    {
        "event_trigger",
        "name:iph_desktop_shared_highlighting_trigger;comparator:<5;window:360;storage:360",
    },
    {
        "event_used",
        "name:iph_desktop_shared_highlighting_used;comparator:<2;window:360;storage:360",
    },
    {
        "session_rate",
        "any",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_558[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_473[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_558,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_219,
        array_kFieldTrialConfig_enable_features_534,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_533[] = {
    "HappinessTrackingSurveysForDesktopSettings",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_218[] = {
    {
        "en_site_id",
        "JcjxgSDnh0ugnJ3q1cK0UVkwDj1o",
    },
    {
        "probability",
        "1.0",
    },
    {
        "settings-time",
        "10s",
    },
    {
        "survey",
        "settings-privacy",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_557[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_472[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_557,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_218,
        array_kFieldTrialConfig_enable_features_533,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_532[] = {
    "ServiceWorkerStorageSuppressPostTask",
};
const Study::Platform array_kFieldTrialConfig_platforms_556[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_471[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_556,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_532,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_531[] = {
    "ServiceWorkerStaticRouter",
};
const Study::Platform array_kFieldTrialConfig_platforms_555[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_470[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_555,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_531,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_530[] = {
    "ServiceWorkerDebugCorsExemptHeaderList",
};
const Study::Platform array_kFieldTrialConfig_platforms_554[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_469[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_554,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_530,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_529[] = {
    "ServiceWorkerAvoidMainThreadForInitialization",
};
const Study::Platform array_kFieldTrialConfig_platforms_553[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_468[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_553,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_529,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_528[] = {
    "ServiceWorkerAutoPreload",
    "ServiceWorkerBypassFetchHandlerHashStrings",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_217[] = {
    {
        "script_checksum_to_bypass",
        "144B3D5485B621F5896FD51D6A6FE66A07B6DBC3ACF6404748A833C2D592F900",
    },
    {
        "use_allowlist",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_552[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_467[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_552,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_217,
        array_kFieldTrialConfig_enable_features_528,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_58[] = {
    "SerializeAccessibilityPostLifecycle",
};
const Study::Platform array_kFieldTrialConfig_platforms_551[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_527[] = {
    "SerializeAccessibilityPostLifecycle",
};
const Study::Platform array_kFieldTrialConfig_platforms_550[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_466[] = {
    {
        "Baseline",
        array_kFieldTrialConfig_platforms_550,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_527,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "HoldBack",
        array_kFieldTrialConfig_platforms_551,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_58,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_526[] = {
    "SendTabToSelfIOSPushNotifications",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_216[] = {
    {
        "variant_with_magic_stack_card",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_549[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_465[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_549,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_216,
        array_kFieldTrialConfig_enable_features_526,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_57[] = {
    "SelectParserRelaxation",
};
const Study::Platform array_kFieldTrialConfig_platforms_548[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_525[] = {
    "SelectParserRelaxation",
};
const Study::Platform array_kFieldTrialConfig_platforms_547[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_464[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_547,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_525,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Disabled",
        array_kFieldTrialConfig_platforms_548,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_57,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_524[] = {
    "SegmentationPlatformUmaFromSqlDb",
};
const Study::Platform array_kFieldTrialConfig_platforms_546[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_463[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_546,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_524,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_523[] = {
    "CertVerificationNetworkTime",
    "NetworkTimeServiceQuerying",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_215[] = {
    {
        "FetchBehavior",
        "background-and-on-demand",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_545[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_462[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_545,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_215,
        array_kFieldTrialConfig_enable_features_523,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_522[] = {
    "SearchWebInSidePanel",
};
const Study::Platform array_kFieldTrialConfig_platforms_544[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_461[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_544,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_522,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_521[] = {
    "SearchNavigationPrefetch",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_214[] = {
    {
        "mouse_down",
        "true",
    },
    {
        "navigation_prefetch_param",
        "op",
    },
    {
        "up_or_down",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_543[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_460[] = {
    {
        "EnabledHighPriorityBothTriggers_20230721",
        array_kFieldTrialConfig_platforms_543,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_214,
        array_kFieldTrialConfig_enable_features_521,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_520[] = {
    "SearchEngineChoiceGuestExperience",
};
const Study::Platform array_kFieldTrialConfig_platforms_542[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_459[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_542,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_520,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_519[] = {
    "SeamlessRenderFrameSwap",
};
const Study::Platform array_kFieldTrialConfig_platforms_541[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_458[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_541,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_519,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_518[] = {
    "ScriptedIdleTaskControllerOOMFix",
};
const Study::Platform array_kFieldTrialConfig_platforms_540[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_457[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_540,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_518,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_56[] = {
    "RestrictedWebUICodeCache",
    "ScriptStreamingForNonHTTP",
    "WebUICodeCache",
};
const Study::Platform array_kFieldTrialConfig_platforms_539[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_517[] = {
    "RestrictedWebUICodeCache",
    "ScriptStreamingForNonHTTP",
    "WebUICodeCache",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_213[] = {
    {
        "RestrictedWebUICodeCacheResources",
        "/new_tab_page.js,/shared.rollup.js,/lit/v3_0/lit.rollup.js,/mojo/mojo/public/js/bindings.js,/polymer/v3_0/polymer/polymer_bundled.min.js,/"
        "new_tab_page.mojom-webui.js,/cr_components/searchbox/searchbox.mojom-webui.js,/cr_components/most_visited/most_visited.mojom-webui.js,/lazy_load.js,/"
        "tab_search.js",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_538[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_516[] = {
    "ScriptStreamingForNonHTTP",
};
const Study::Platform array_kFieldTrialConfig_platforms_537[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_456[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_537,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_516,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_CodeCache",
        array_kFieldTrialConfig_platforms_538,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_213,
        array_kFieldTrialConfig_enable_features_517,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Disabled",
        array_kFieldTrialConfig_platforms_539,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_56,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_515[] = {
    "ScreenlockReauthPromoCard",
};
const Study::Platform array_kFieldTrialConfig_platforms_536[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_455[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_536,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_515,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_514[] = {
    "ScaleScrollbarAnimationTiming",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_212[] = {
    {
        "fade_delay_scaling_factor",
        "2.0",
    },
    {
        "fade_duration_scaling_factor",
        "0.5",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_535[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_454[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_535,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_212,
        array_kFieldTrialConfig_enable_features_514,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_513[] = {
    "SavePasswordHashFromProfilePicker",
};
const Study::Platform array_kFieldTrialConfig_platforms_534[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_453[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_534,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_513,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_512[] = {
    "SafetyHub",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_211[] = {
    {
        "background-password-check-interval",
        "30d",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_533[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_452[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_533,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_211,
        array_kFieldTrialConfig_enable_features_512,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_511[] = {
    "SafetyCheckUnusedSitePermissions",
};
const Study::Platform array_kFieldTrialConfig_platforms_532[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_451[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_532,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_511,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_510[] = {
    "SafeBrowsingRemoveCookiesInAuthRequests",
};
const Study::Platform array_kFieldTrialConfig_platforms_531[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_450[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_531,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_510,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_509[] = {
    "SafeBrowsingArchiveImprovements",
    "SafeBrowsingStrictDownloadtimeout",
};
const Study::Platform array_kFieldTrialConfig_platforms_530[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_449[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_530,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_509,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_508[] = {
    "SafeBrowsingHashPrefixRealTimeLookupsFasterOhttpKeyRotation",
};
const Study::Platform array_kFieldTrialConfig_platforms_529[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_448[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_529,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_508,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_507[] = {
    "SafeBrowsingExternalAppRedirectTelemetry",
};
const Study::Platform array_kFieldTrialConfig_platforms_528[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_447[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_528,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_507,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_506[] = {
    "SafeBrowsingDeepScanningCriteria",
};
const Study::Platform array_kFieldTrialConfig_platforms_527[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_446[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_527,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_506,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_505[] = {
    "SafeBrowsingDailyPhishingReportsLimit",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_210[] = {
    {
        "kMaxReportsPerIntervalESB",
        "10",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_526[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_445[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_526,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_210,
        array_kFieldTrialConfig_enable_features_505,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_504[] = {
    "RunPerformanceManagerOnMainThreadSync",
};
const Study::Platform array_kFieldTrialConfig_platforms_525[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_444[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_525,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_504,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_503[] = {
    "ReuseDetectionBasedOnPasswordHashes",
};
const Study::Platform array_kFieldTrialConfig_platforms_524[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_443[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_524,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_503,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_502[] = {
    "ResolutionBasedDecoderPriority",
};
const Study::Platform array_kFieldTrialConfig_platforms_523[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_442[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_523,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_502,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_501[] = {
    "ReportingServiceAlwaysFlush",
};
const Study::Platform array_kFieldTrialConfig_platforms_522[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_441[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_522,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_501,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_209[] = {
    {
        "sendingThreshold",
        "1.0",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_521[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_440[] = {
    {
        "ShowAndPossiblySend",
        array_kFieldTrialConfig_platforms_521,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_209,
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_500[] = {
    "RenderPassDrawnRect",
};
const Study::Platform array_kFieldTrialConfig_platforms_520[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_439[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_520,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_500,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_55[] = {
    "RenderDocumentCompositorReuse",
};
const char* const array_kFieldTrialConfig_enable_features_499[] = {
    "QueueNavigationsWhileWaitingForCommit",
    "RenderDocument",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_208[] = {
    {
        "level",
        "all-frames",
    },
    {
        "queueing_level",
        "full",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_519[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_498[] = {
    "QueueNavigationsWhileWaitingForCommit",
    "RenderDocument",
    "RenderDocumentCompositorReuse",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_207[] = {
    {
        "level",
        "subframe",
    },
    {
        "queueing_level",
        "full",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_518[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_54[] = {
    "RenderDocumentCompositorReuse",
};
const char* const array_kFieldTrialConfig_enable_features_497[] = {
    "QueueNavigationsWhileWaitingForCommit",
    "RenderDocument",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_206[] = {
    {
        "level",
        "non-local-root-subframe",
    },
    {
        "queueing_level",
        "full",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_517[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_53[] = {
    "RenderDocumentCompositorReuse",
};
const char* const array_kFieldTrialConfig_enable_features_496[] = {
    "QueueNavigationsWhileWaitingForCommit",
    "RenderDocument",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_205[] = {
    {
        "level",
        "crashed-frame",
    },
    {
        "queueing_level",
        "full",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_516[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_52[] = {
    "RenderDocumentCompositorReuse",
};
const char* const array_kFieldTrialConfig_enable_features_495[] = {
    "QueueNavigationsWhileWaitingForCommit",
    "RenderDocument",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_204[] = {
    {
        "level",
        "subframe",
    },
    {
        "queueing_level",
        "full",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_515[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_438[] = {
    {
        "EnabledSubframeWithQueueing_20240108",
        array_kFieldTrialConfig_platforms_515,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_204,
        array_kFieldTrialConfig_enable_features_495,
        array_kFieldTrialConfig_disable_features_52,
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledCrashedFrameWithQueueing_20240108",
        array_kFieldTrialConfig_platforms_516,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_205,
        array_kFieldTrialConfig_enable_features_496,
        array_kFieldTrialConfig_disable_features_53,
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledNLRSubframeWithQueueing_20240108",
        array_kFieldTrialConfig_platforms_517,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_206,
        array_kFieldTrialConfig_enable_features_497,
        array_kFieldTrialConfig_disable_features_54,
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledSubframeWithQueueingAndCompReuse_20240108",
        array_kFieldTrialConfig_platforms_518,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_207,
        array_kFieldTrialConfig_enable_features_498,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledAllFramesWithQueueing_20240108",
        array_kFieldTrialConfig_platforms_519,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_208,
        array_kFieldTrialConfig_enable_features_499,
        array_kFieldTrialConfig_disable_features_55,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_494[] = {
    "RemoveRendererProcessLimit",
};
const Study::Platform array_kFieldTrialConfig_platforms_514[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_437[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_514,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_494,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_493[] = {
    "RemoveFontLinkFallbacks",
};
const Study::Platform array_kFieldTrialConfig_platforms_513[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_436[] = {
    {
        "Enabled_20230210",
        array_kFieldTrialConfig_platforms_513,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_493,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_492[] = {
    "RemoveDataUrlInSvgUse",
};
const Study::Platform array_kFieldTrialConfig_platforms_512[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_435[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_512,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_492,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_491[] = {
    "RemotePageMetadata",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_203[] = {
    {
        "supported_countries",
        "*",
    },
    {
        "supported_locales",
        "*",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_511[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_434[] = {
    {
        "Enabled_20240514",
        array_kFieldTrialConfig_platforms_511,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_203,
        array_kFieldTrialConfig_enable_features_491,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_490[] = {
    "RegisterOsUpdateHandlerWin",
};
const Study::Platform array_kFieldTrialConfig_platforms_510[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_433[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_510,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_490,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_489[] = {
    "ReduceSubresourceResponseStartedIPC",
    "UkmReduceAddEntryIPC",
};
const Study::Platform array_kFieldTrialConfig_platforms_509[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_51[] = {
    "UkmReduceAddEntryIPC",
};
const char* const array_kFieldTrialConfig_enable_features_488[] = {
    "ReduceSubresourceResponseStartedIPC",
};
const Study::Platform array_kFieldTrialConfig_platforms_508[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_50[] = {
    "ReduceSubresourceResponseStartedIPC",
};
const char* const array_kFieldTrialConfig_enable_features_487[] = {
    "UkmReduceAddEntryIPC",
};
const Study::Platform array_kFieldTrialConfig_platforms_507[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_432[] = {
    {
        "EnabledUkmReduceAddEntryIPC",
        array_kFieldTrialConfig_platforms_507,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_487,
        array_kFieldTrialConfig_disable_features_50,
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledReduceSubresourceResponseStartedIPC",
        array_kFieldTrialConfig_platforms_508,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_488,
        array_kFieldTrialConfig_disable_features_51,
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledReduceIPCCombined",
        array_kFieldTrialConfig_platforms_509,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_489,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_486[] = {
    "ReduceAcceptLanguage",
};
const Study::Platform array_kFieldTrialConfig_platforms_506[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_431[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_506,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_486,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_485[] = {
    "ReclaimPrepaintTilesWhenIdle",
};
const Study::Platform array_kFieldTrialConfig_platforms_505[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_430[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_505,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_485,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_484[] = {
    "ReclaimOldPrepaintTiles",
};
const Study::Platform array_kFieldTrialConfig_platforms_504[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_429[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_504,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_484,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_49[] = {
    "ReadAnythingReadAloudPhraseHighlighting",
};
const Study::Platform array_kFieldTrialConfig_platforms_503[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_483[] = {
    "ReadAnythingReadAloudPhraseHighlighting",
};
const Study::Platform array_kFieldTrialConfig_platforms_502[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_428[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_502,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_483,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Disabled",
        array_kFieldTrialConfig_platforms_503,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_49,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_48[] = {
    "ReadAnythingReadAloud",
};
const Study::Platform array_kFieldTrialConfig_platforms_501[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_482[] = {
    "ReadAnythingReadAloud",
};
const Study::Platform array_kFieldTrialConfig_platforms_500[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_427[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_500,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_482,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Disabled",
        array_kFieldTrialConfig_platforms_501,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_48,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_481[] = {
    "ReadAnythingPermanentAccessibility",
};
const Study::Platform array_kFieldTrialConfig_platforms_499[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_426[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_499,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_481,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_480[] = {
    "ReadAnythingLocalSidePanel",
};
const Study::Platform array_kFieldTrialConfig_platforms_498[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_425[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_498,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_480,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_479[] = {
    "IPH_ReadingModeSidePanel",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_202[] = {
    {
        "availability",
        "any",
    },
    {
        "distillable_urls",
        "support.google.com,docs.google.com",
    },
    {
        "event_trigger",
        "name:iph_reading_mode_side_panel_trigger;comparator:<=3;window:360;storage:360",
    },
    {
        "event_used",
        "name:reading_mode_side_panel_shown;comparator:==0;window:360;storage:360",
    },
    {
        "session_rate",
        "==0",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_497[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_424[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_497,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_202,
        array_kFieldTrialConfig_enable_features_479,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_478[] = {
    "ReadAnythingDocsIntegration",
};
const Study::Platform array_kFieldTrialConfig_platforms_496[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_423[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_496,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_478,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_47[] = {
    "LoadingPredictorPrefetch",
};
const char* const array_kFieldTrialConfig_enable_features_477[] = {
    "LoadingPredictorUseOptimizationGuide",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_201[] = {
    {
        "use_predictions",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_495[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_422[] = {
    {
        "EnabledWithPreconnect_20240916",
        array_kFieldTrialConfig_platforms_495,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_201,
        array_kFieldTrialConfig_enable_features_477,
        array_kFieldTrialConfig_disable_features_47,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_476[] = {
    "RasterInducingScroll",
};
const Study::Platform array_kFieldTrialConfig_platforms_494[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_421[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_494,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_476,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_475[] = {
    "RTCAlignReceivedEncodedVideoTransforms",
};
const Study::Platform array_kFieldTrialConfig_platforms_493[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_420[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_493,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_475,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_474[] = {
    "QuicDoesNotUseFeatures",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_200[] = {
    {
        "channel",
        "F",
    },
    {
        "epoch",
        "30000000",
    },
    {
        "retransmittable_on_wire_timeout_milliseconds",
        "200",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_492[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_419[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_492,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_200,
        array_kFieldTrialConfig_enable_features_474,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_473[] = {
    "PushMessagingGcmEndpointEnvironment",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_199[] = {
    {
        "PushMessagingGcmEndpointUrl",
        "https://jmt17.google.com/fcm/send/",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_491[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_418[] = {
    {
        "Enabled_Dogfood",
        array_kFieldTrialConfig_platforms_491,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_199,
        array_kFieldTrialConfig_enable_features_473,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_472[] = {
    "PushMessagingDisallowSenderIDs",
};
const Study::Platform array_kFieldTrialConfig_platforms_490[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_417[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_490,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_472,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_471[] = {
    "PsDualWritePrefsToNoticeStorage",
};
const Study::Platform array_kFieldTrialConfig_platforms_489[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_416[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_489,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_471,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_470[] = {
    "PruneOldTransferCacheEntries",
};
const Study::Platform array_kFieldTrialConfig_platforms_488[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_415[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_488,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_470,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_469[] = {
    "InterestGroupUpdateIfOlderThan",
};
const Study::Platform array_kFieldTrialConfig_platforms_487[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_414[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_487,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_469,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_468[] = {
    "FledgeSellerNonce",
};
const Study::Platform array_kFieldTrialConfig_platforms_486[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_413[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_486,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_468,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_467[] = {
    "FledgeConsiderKAnonymity",
    "FledgeEnforceKAnonymity",
};
const Study::Platform array_kFieldTrialConfig_platforms_485[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_412[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_485,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_467,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_466[] = {
    "FledgeDirectFromSellerSignalsHeaderAdSlot",
};
const Study::Platform array_kFieldTrialConfig_platforms_484[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_411[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_484,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_466,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_465[] = {
    "FledgeTrustedSignalsKVv2Support",
};
const Study::Platform array_kFieldTrialConfig_platforms_483[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_410[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_483,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_465,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_464[] = {
    "FledgeUsePreconnectCache",
};
const Study::Platform array_kFieldTrialConfig_platforms_482[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_409[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_482,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_464,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_463[] = {
    "FledgeNoWasmLazyCompilation",
};
const Study::Platform array_kFieldTrialConfig_platforms_481[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_408[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_481,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_463,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_462[] = {
    "FledgeSellerWorkletThreadPool",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_198[] = {
    {
        "seller_worklet_thread_pool_size",
        "2",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_480[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_407[] = {
    {
        "TwoThreads",
        array_kFieldTrialConfig_platforms_480,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_198,
        array_kFieldTrialConfig_enable_features_462,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_461[] = {
    "PrivateAggregationApiProtectedAudienceAdditionalExtensions",
};
const Study::Platform array_kFieldTrialConfig_platforms_479[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_406[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_479,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_461,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_460[] = {
    "FledgeStartAnticipatoryProcesses",
};
const Study::Platform array_kFieldTrialConfig_platforms_478[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_405[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_478,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_460,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_459[] = {
    "FledgeAuctionDealSupport",
};
const Study::Platform array_kFieldTrialConfig_platforms_477[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_404[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_477,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_459,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_458[] = {
    "ProfilesReordering",
};
const Study::Platform array_kFieldTrialConfig_platforms_476[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_403[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_476,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_458,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_457[] = {
    "DevToolsSharedProcessInfobar",
    "ProcessPerSiteUpToMainFrameThreshold",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_197[] = {
    {
        "ProcessPerSiteMainFrameThreshold",
        "15",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_475[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_402[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_475,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_197,
        array_kFieldTrialConfig_enable_features_457,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_456[] = {
    "IsolateFencedFrames",
};
const Study::Platform array_kFieldTrialConfig_platforms_474[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_401[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_474,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_456,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_455[] = {
    "ProcessHtmlDataImmediately",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_196[] = {
    {
        "first",
        "true",
    },
    {
        "main",
        "true",
    },
    {
        "rest",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_473[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_400[] = {
    {
        "AllChunks",
        array_kFieldTrialConfig_platforms_473,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_196,
        array_kFieldTrialConfig_enable_features_455,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_454[] = {
    "ProcessBoundStringEncryption",
};
const Study::Platform array_kFieldTrialConfig_platforms_472[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_399[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_472,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_454,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_453[] = {
    "PrivateStateTokens",
};
const Study::Platform array_kFieldTrialConfig_platforms_471[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_398[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_471,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_453,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_452[] = {
    "PrivateAggregationApiFilteringIds",
};
const Study::Platform array_kFieldTrialConfig_platforms_470[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_397[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_470,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_452,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_451[] = {
    "PrivacySandboxSentimentSurvey",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_195[] = {
    {
        "probability",
        "1.0",
    },
    {
        "sentiment-survey-trigger-id",
        "EHJUDsZQd0ugnJ3q1cK0Ru5GreU3",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_469[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_396[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_469,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_195,
        array_kFieldTrialConfig_enable_features_451,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_450[] = {
    "PrivacySandboxPrivacyPolicy",
};
const Study::Platform array_kFieldTrialConfig_platforms_468[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_395[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_468,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_450,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_449[] = {
    "PrivacySandboxPrivacyGuideAdTopics",
};
const Study::Platform array_kFieldTrialConfig_platforms_467[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_394[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_467,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_449,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_448[] = {
    "PrivacySandboxInternalsDevUI",
};
const Study::Platform array_kFieldTrialConfig_platforms_466[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_393[] = {
    {
        "Enabled_Dogfood",
        array_kFieldTrialConfig_platforms_466,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_448,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_46[] = {
    "HappinessTrackingSurveysForDesktopM1AdPrivacyPage",
    "HappinessTrackingSurveysForDesktopM1FledgeSubpage",
    "HappinessTrackingSurveysForDesktopM1TopicsSubpage",
};
const char* const array_kFieldTrialConfig_enable_features_447[] = {
    "HappinessTrackingSurveysForDesktopM1AdMeasurementSubpage",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_194[] = {
    {
        "en_site_id",
        "vzxsxSxGk0ugnJ3q1cK0PHvFhzka",
    },
    {
        "probability",
        "1.0",
    },
    {
        "settings-time",
        "20s",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_465[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_45[] = {
    "HappinessTrackingSurveysForDesktopM1AdMeasurementSubpage",
    "HappinessTrackingSurveysForDesktopM1AdPrivacyPage",
    "HappinessTrackingSurveysForDesktopM1TopicsSubpage",
};
const char* const array_kFieldTrialConfig_enable_features_446[] = {
    "HappinessTrackingSurveysForDesktopM1FledgeSubpage",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_193[] = {
    {
        "en_site_id",
        "YhMPu6WWx0ugnJ3q1cK0PfKSV3YR",
    },
    {
        "probability",
        "1.0",
    },
    {
        "settings-time",
        "20s",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_464[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_44[] = {
    "HappinessTrackingSurveysForDesktopM1AdMeasurementSubpage",
    "HappinessTrackingSurveysForDesktopM1AdPrivacyPage",
    "HappinessTrackingSurveysForDesktopM1FledgeSubpage",
};
const char* const array_kFieldTrialConfig_enable_features_445[] = {
    "HappinessTrackingSurveysForDesktopM1TopicsSubpage",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_192[] = {
    {
        "en_site_id",
        "HkMzAEAUa0ugnJ3q1cK0UCYW2Hyw",
    },
    {
        "probability",
        "1.0",
    },
    {
        "settings-time",
        "20s",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_463[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_43[] = {
    "HappinessTrackingSurveysForDesktopM1AdMeasurementSubpage",
    "HappinessTrackingSurveysForDesktopM1FledgeSubpage",
    "HappinessTrackingSurveysForDesktopM1TopicsSubpage",
};
const char* const array_kFieldTrialConfig_enable_features_444[] = {
    "HappinessTrackingSurveysForDesktopM1AdPrivacyPage",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_191[] = {
    {
        "en_site_id",
        "gyxt1wCrg0ugnJ3q1cK0TeuAxb15",
    },
    {
        "probability",
        "1.0",
    },
    {
        "settings-time",
        "20s",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_462[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_392[] = {
    {
        "Enabled_PrivacyPage",
        array_kFieldTrialConfig_platforms_462,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_191,
        array_kFieldTrialConfig_enable_features_444,
        array_kFieldTrialConfig_disable_features_43,
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_TopicsSubpage",
        array_kFieldTrialConfig_platforms_463,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_192,
        array_kFieldTrialConfig_enable_features_445,
        array_kFieldTrialConfig_disable_features_44,
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_FledgeSubpage",
        array_kFieldTrialConfig_platforms_464,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_193,
        array_kFieldTrialConfig_enable_features_446,
        array_kFieldTrialConfig_disable_features_45,
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_AdMeasurementSubpage",
        array_kFieldTrialConfig_platforms_465,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_194,
        array_kFieldTrialConfig_enable_features_447,
        array_kFieldTrialConfig_disable_features_46,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_443[] = {
    "PrivacySandboxAdsApiUxEnhancements",
};
const Study::Platform array_kFieldTrialConfig_platforms_461[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_391[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_461,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_443,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_442[] = {
    "AllowURNsInIframes",
    "AttributionReportingCrossAppWeb",
    "BiddingAndScoringDebugReportingAPI",
    "BrowsingTopics",
    "FencedFrames",
    "FencedFramesAPIChanges",
    "InterestGroupStorage",
    "KAnonymityService",
    "PrivacySandboxAdsAPIs",
    "PrivacySandboxAdsAPIsM1Override",
    "PrivateAggregationApi",
    "SharedStorageAPI",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_190[] = {
    {
        "implementation_type",
        "mparch",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_460[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_390[] = {
    {
        "Enabled_Notice_M1_AllAPIs_Expanded_NoOT_Stable",
        array_kFieldTrialConfig_platforms_460,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_190,
        array_kFieldTrialConfig_enable_features_442,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_441[] = {
    "PriorityHeader",
};
const Study::Platform array_kFieldTrialConfig_platforms_459[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_389[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_459,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_441,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_440[] = {
    "PrioritizeCompositingAfterDelayTrials",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_189[] = {
    {
        "PostFCP",
        "50",
    },
    {
        "PreFCP",
        "100",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_458[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_388[] = {
    {
        "PrioritizeCompositingAfter50ms2",
        array_kFieldTrialConfig_platforms_458,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_189,
        array_kFieldTrialConfig_enable_features_440,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_439[] = {
    "PrintWithReducedRasterization",
};
const Study::Platform array_kFieldTrialConfig_platforms_457[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_387[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_457,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_439,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_438[] = {
    "PrintWithPostScriptType42Fonts",
};
const Study::Platform array_kFieldTrialConfig_platforms_456[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_386[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_456,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_438,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_437[] = {
    "IPH_PriceTrackingPageActionIconLabelFeature",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_188[] = {
    {
        "availability",
        "any",
    },
    {
        "event_trigger",
        "name:price_tracking_page_action_icon_label_in_trigger;comparator:==0;window:1;storage:365",
    },
    {
        "event_used",
        "name:used;comparator:any;window:365;storage:365",
    },
    {
        "session_rate",
        "any",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_455[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_385[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_455,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_188,
        array_kFieldTrialConfig_enable_features_437,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_436[] = {
    "PriceTrackingIconColors",
};
const Study::Platform array_kFieldTrialConfig_platforms_454[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_384[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_454,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_436,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_435[] = {
    "PriceTrackingSubscriptionServiceLocaleKey",
    "ShoppingList",
};
const Study::Platform array_kFieldTrialConfig_platforms_453[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_383[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_453,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_435,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_434[] = {
    "PreserveDiscardableImageMapQuality",
};
const Study::Platform array_kFieldTrialConfig_platforms_452[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_382[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_452,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_434,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_433[] = {
    "NewTabPageTriggerForPrerender2",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_187[] = {
    {
        "prerender_new_tab_page_on_mouse_hover_trigger",
        "true",
    },
    {
        "prerender_new_tab_page_on_mouse_pressed_trigger",
        "true",
    },
    {
        "prerender_start_delay_on_mouse_hover_ms",
        "300",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_451[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_381[] = {
    {
        "BothMouseDownAndMouseHover_20241010",
        array_kFieldTrialConfig_platforms_451,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_187,
        array_kFieldTrialConfig_enable_features_433,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_432[] = {
    "Prerender2FallbackPrefetchSpecRules",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_186[] = {
    {
        "kPrerender2FallbackPrefetchReusablePolicy",
        "UseIfIsLikelyAheadOfPrerender",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_450[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_380[] = {
    {
        "Enabled_20241023",
        array_kFieldTrialConfig_platforms_450,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_186,
        array_kFieldTrialConfig_enable_features_432,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_431[] = {
    "Prerender2EmbedderBlockedHosts",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_185[] = {
    {
        "embedder_blocked_hosts",
        "",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_449[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_379[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_449,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_185,
        array_kFieldTrialConfig_enable_features_431,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_430[] = {
    "Prerender2EarlyDocumentLifecycleUpdate",
};
const Study::Platform array_kFieldTrialConfig_platforms_448[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_378[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_448,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_430,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_429[] = {
    "BookmarkTriggerForPrerender2",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_184[] = {
    {
        "prerender_bookmarkbar_on_mouse_hover_trigger",
        "true",
    },
    {
        "prerender_bookmarkbar_on_mouse_pressed_trigger",
        "true",
    },
    {
        "prerender_start_delay_on_mouse_hover_ms",
        "300",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_447[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_377[] = {
    {
        "MouseDownAndMouseHover300ms_20241008",
        array_kFieldTrialConfig_platforms_447,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_184,
        array_kFieldTrialConfig_enable_features_429,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_428[] = {
    "PreloadingHeuristicsMLModel",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_183[] = {
    {
        "enact_candidates",
        "false",
    },
    {
        "one_execution_per_hover",
        "false",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_446[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_376[] = {
    {
        "Enabled_20240726_NoEnact",
        array_kFieldTrialConfig_platforms_446,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_183,
        array_kFieldTrialConfig_enable_features_428,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_427[] = {
    "PreloadTopChromeWebUI",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_182[] = {
    {
        "delay-preload",
        "true",
    },
    {
        "preload-mode",
        "preload-on-warmup",
    },
    {
        "smart-preload",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_445[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_375[] = {
    {
        "preload-on-warmup-delay",
        array_kFieldTrialConfig_platforms_445,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_182,
        array_kFieldTrialConfig_enable_features_427,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_426[] = {
    "PrefetchReusable",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_181[] = {
    {
        "PrefetchReusableUseNewWaitLoop",
        "true",
    },
    {
        "prefetch_reusable_body_size_limit",
        "65536",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_444[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_374[] = {
    {
        "Enabled_20241023",
        array_kFieldTrialConfig_platforms_444,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_181,
        array_kFieldTrialConfig_enable_features_426,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_425[] = {
    "PrefetchProxy",
};
const Study::Platform array_kFieldTrialConfig_platforms_443[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_373[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_443,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_425,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_424[] = {
    "PrefetchNewWaitLoop",
};
const Study::Platform array_kFieldTrialConfig_platforms_442[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_372[] = {
    {
        "Enabled_20240909",
        array_kFieldTrialConfig_platforms_442,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_424,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_423[] = {
    "PrefetchDocumentManagerEarlyCookieCopySkipped",
};
const Study::Platform array_kFieldTrialConfig_platforms_441[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_371[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_441,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_423,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_422[] = {
    "PreconnectToSearchWithPrivacyModeEnabled",
};
const Study::Platform array_kFieldTrialConfig_platforms_440[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_370[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_440,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_422,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_421[] = {
    "PreconnectToSearch",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_180[] = {
    {
        "skip_in_background",
        "true",
    },
    {
        "startup_delay_ms",
        "5000",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_439[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_369[] = {
    {
        "EnabledWithStartupDelayForegroundOnly",
        array_kFieldTrialConfig_platforms_439,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_180,
        array_kFieldTrialConfig_enable_features_421,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_420[] = {
    "PrefetchVirtualMemoryPolicy",
};
const Study::Platform array_kFieldTrialConfig_platforms_438[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_368[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_438,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_420,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_419[] = {
    "PowerBookmarkBackend",
};
const Study::Platform array_kFieldTrialConfig_platforms_437[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_367[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_437,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_419,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_418[] = {
    "PolicyBlocklistProceedUntilResponse",
};
const Study::Platform array_kFieldTrialConfig_platforms_436[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_366[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_436,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_418,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_417[] = {
    "DedicatedWorkerAblationStudyEnabled",
    "PlzDedicatedWorker",
    "ServiceWorkerClientIdAlignedWithSpec",
};
const Study::Platform array_kFieldTrialConfig_platforms_435[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_365[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_435,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_417,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_416[] = {
    "PlusAddressAndroidOpenGmsCoreManagementPage",
    "PlusAddressFallbackFromContextMenu",
    "PlusAddressGlobalToggle",
    "PlusAddressOfferCreationIfPasswordFieldIsNotVisible",
    "PlusAddressOfferCreationOnSingleUsernameForms",
    "PlusAddressPreallocation",
    "PlusAddressRefinedPasswordFormClassification",
    "PlusAddressUserOnboardingEnabled",
    "PlusAddressesEnabled",
};
const Study::Platform array_kFieldTrialConfig_platforms_434[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_364[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_434,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_416,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_415[] = {
    "PermissionsPromptSurvey",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_179[] = {
    {
        "action_filter",
        "Dismissed",
    },
    {
        "initial_permission_status_filter",
        "deny",
    },
    {
        "probability",
        "0.5",
    },
    {
        "probability_vector",
        "0.5,0.5",
    },
    {
        "prompt_disposition_filter",
        "ElementAnchoredBubble",
    },
    {
        "request_type_filter",
        "VideoCapture,AudioCapture",
    },
    {
        "survey_display_time",
        "OnPromptResolved",
    },
    {
        "trigger_id",
        "oqdSQ6wky0ugnJ3q1cK0WRpR8GW2,WCAaJD6T80ugnJ3q1cK0XaNn1zy3",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_433[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_363[] = {
    {
        "RecoverySurveyDismiss_20240729",
        array_kFieldTrialConfig_platforms_433,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_179,
        array_kFieldTrialConfig_enable_features_415,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_414[] = {
    "PermissionElementPromptPositioning",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_178[] = {
    {
        "PermissionElementPromptPositioningParam",
        "legacy_prompt",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_432[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_413[] = {
    "PermissionElementPromptPositioning",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_177[] = {
    {
        "PermissionElementPromptPositioningParam",
        "window_middle",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_431[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_412[] = {
    "PermissionElementPromptPositioning",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_176[] = {
    {
        "PermissionElementPromptPositioningParam",
        "near_element",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_430[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_362[] = {
    {
        "NearElement",
        array_kFieldTrialConfig_platforms_430,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_176,
        array_kFieldTrialConfig_enable_features_412,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "WindowMiddle",
        array_kFieldTrialConfig_platforms_431,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_177,
        array_kFieldTrialConfig_enable_features_413,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "LegacyPrompt",
        array_kFieldTrialConfig_platforms_432,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_178,
        array_kFieldTrialConfig_enable_features_414,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_411[] = {
    "PerformanceInterventionUI",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_175[] = {
    {
        "intervention_dialog_version",
        "3",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_429[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_410[] = {
    "PerformanceInterventionUI",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_174[] = {
    {
        "intervention_dialog_version",
        "2",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_428[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_409[] = {
    "PerformanceInterventionUI",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_173[] = {
    {
        "intervention_dialog_version",
        "1",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_427[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_361[] = {
    {
        "EnabledString1_20240724",
        array_kFieldTrialConfig_platforms_427,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_173,
        array_kFieldTrialConfig_enable_features_409,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledString2_20240724",
        array_kFieldTrialConfig_platforms_428,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_174,
        array_kFieldTrialConfig_enable_features_410,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledString3_20240724",
        array_kFieldTrialConfig_platforms_429,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_175,
        array_kFieldTrialConfig_enable_features_411,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_42[] = {
    "PerformanceControlsBatteryPerformanceSurvey",
    "PerformanceControlsHighEfficiencyOptOutSurvey",
    "PerformanceControlsPerformanceSurvey",
};
const char* const array_kFieldTrialConfig_enable_features_408[] = {
    "PerformanceControlsBatterySaverOptOutSurvey",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_172[] = {
    {
        "en_site_id",
        "gyuzHnE940ugnJ3q1cK0RyY65eG8",
    },
    {
        "probability",
        "1.0",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_426[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_41[] = {
    "PerformanceControlsBatteryPerformanceSurvey",
    "PerformanceControlsBatterySaverOptOutSurvey",
    "PerformanceControlsPerformanceSurvey",
};
const char* const array_kFieldTrialConfig_enable_features_407[] = {
    "PerformanceControlsHighEfficiencyOptOutSurvey",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_171[] = {
    {
        "en_site_id",
        "hEedoxCS30ugnJ3q1cK0YKKzXjSm",
    },
    {
        "probability",
        "1.0",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_425[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_360[] = {
    {
        "EnabledHighEfficiencyOptOut_20230223",
        array_kFieldTrialConfig_platforms_425,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_171,
        array_kFieldTrialConfig_enable_features_407,
        array_kFieldTrialConfig_disable_features_41,
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledBatterySaverOptOut_20230223",
        array_kFieldTrialConfig_platforms_426,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_172,
        array_kFieldTrialConfig_enable_features_408,
        array_kFieldTrialConfig_disable_features_42,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_406[] = {
    "AvoidScheduleWorkDuringNativeEventProcessing",
    "ConditionallySkipGpuChannelFlush",
    "EarlyEstablishGpuChannel",
    "EstablishGpuChannelAsync",
    "ExpandedPrefetchRange",
    "FledgeEnableWALForInterestGroupStorage",
    "GpuInfoCollectionSeparatePrefetch",
    "LevelDBProtoAsyncWrite",
    "MojoBindingsInlineSLS",
    "ReduceCpuUtilization2",
    "RunTasksByBatches",
    "SharedStorageAPIEnableWALForDatabase",
    "SqlWALModeOnDipsDatabase",
    "SqlWALModeOnSegmentationDatabase",
    "UIPumpImprovementsWin",
};
const Study::Platform array_kFieldTrialConfig_platforms_424[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_359[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_424,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_406,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_405[] = {
    "PdfUseSkiaRenderer",
};
const Study::Platform array_kFieldTrialConfig_platforms_423[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_358[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_423,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_405,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_404[] = {
    "PdfSearchify",
};
const Study::Platform array_kFieldTrialConfig_platforms_422[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_357[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_422,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_404,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_403[] = {
    "PdfOopif",
};
const Study::Platform array_kFieldTrialConfig_platforms_421[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_356[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_421,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_403,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_402[] = {
    "PdfCr23",
};
const Study::Platform array_kFieldTrialConfig_platforms_420[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_355[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_420,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_402,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_401[] = {
    "Path2DPaintCache",
};
const Study::Platform array_kFieldTrialConfig_platforms_419[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_354[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_419,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_401,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_400[] = {
    "PasswordManualFallbackAvailable",
};
const Study::Platform array_kFieldTrialConfig_platforms_418[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_353[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_418,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_400,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_399[] = {
    "PassHistogramSharedMemoryOnLaunch",
};
const Study::Platform array_kFieldTrialConfig_platforms_417[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_352[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_417,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_399,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_40[] = {
    "PartitionVisitedLinkDatabase",
    "PartitionVisitedLinkDatabaseWithSelfLinks",
};
const Study::Platform array_kFieldTrialConfig_platforms_416[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_39[] = {
    "PartitionVisitedLinkDatabase",
};
const char* const array_kFieldTrialConfig_enable_features_398[] = {
    "PartitionVisitedLinkDatabaseWithSelfLinks",
};
const Study::Platform array_kFieldTrialConfig_platforms_415[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_38[] = {
    "PartitionVisitedLinkDatabaseWithSelfLinks",
};
const char* const array_kFieldTrialConfig_enable_features_397[] = {
    "PartitionVisitedLinkDatabase",
};
const Study::Platform array_kFieldTrialConfig_platforms_414[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_351[] = {
    {
        "EnabledNoSelfLinks",
        array_kFieldTrialConfig_platforms_414,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_397,
        array_kFieldTrialConfig_disable_features_38,
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledWithSelfLinks",
        array_kFieldTrialConfig_platforms_415,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_398,
        array_kFieldTrialConfig_disable_features_39,
        nullptr,
        {},
        {},
        {},
    },
    {
        "Control",
        array_kFieldTrialConfig_platforms_416,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_40,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_396[] = {
    "PartitionConnectionsByNetworkIsolationKey",
};
const Study::Platform array_kFieldTrialConfig_platforms_413[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_350[] = {
    {
        "EnableFeatureForTests",
        array_kFieldTrialConfig_platforms_413,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_396,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_395[] = {
    "PartitionAllocUseSmallSingleSlotSpans",
};
const Study::Platform array_kFieldTrialConfig_platforms_412[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_349[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_412,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_395,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_394[] = {
    "PartitionAllocUsePoolOffsetFreelists",
};
const Study::Platform array_kFieldTrialConfig_platforms_411[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_348[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_411,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_394,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_393[] = {
    "PartitionAllocUnretainedDanglingPtr",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_170[] = {
    {
        "mode",
        "dump_without_crashing",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_410[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_347[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_410,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_170,
        array_kFieldTrialConfig_enable_features_393,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_392[] = {
    "PartitionAllocShortMemoryReclaim",
};
const Study::Platform array_kFieldTrialConfig_platforms_409[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_346[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_409,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_392,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_391[] = {
    "BlinkUseLargeEmptySlotSpanRingForBufferRoot",
    "PartitionAllocAdjustSizeWhenInForeground",
    "PartitionAllocLargeEmptySlotSpanRing",
};
const Study::Platform array_kFieldTrialConfig_platforms_408[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_345[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_408,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_391,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_37[] = {
    "PartitionAllocSortActiveSlotSpans",
    "PartitionAllocStraightenLargerSlotSpanFreeLists",
};
const char* const array_kFieldTrialConfig_enable_features_390[] = {
    "PartitionAllocMemoryReclaimer",
    "PartitionAllocSortSmallerSlotSpanFreeLists",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_169[] = {
    {
        "interval",
        "4s",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_407[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_36[] = {
    "PartitionAllocSortActiveSlotSpans",
};
const char* const array_kFieldTrialConfig_enable_features_389[] = {
    "PartitionAllocMemoryReclaimer",
    "PartitionAllocSortSmallerSlotSpanFreeLists",
    "PartitionAllocStraightenLargerSlotSpanFreeLists",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_168[] = {
    {
        "interval",
        "4s",
    },
    {
        "mode",
        "always",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_406[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_35[] = {
    "PartitionAllocSortActiveSlotSpans",
    "PartitionAllocSortSmallerSlotSpanFreeLists",
};
const char* const array_kFieldTrialConfig_enable_features_388[] = {
    "PartitionAllocMemoryReclaimer",
    "PartitionAllocStraightenLargerSlotSpanFreeLists",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_167[] = {
    {
        "interval",
        "4s",
    },
    {
        "mode",
        "only-when-unprovisioning",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_405[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_387[] = {
    "PartitionAllocMemoryReclaimer",
    "PartitionAllocSortActiveSlotSpans",
    "PartitionAllocSortSmallerSlotSpanFreeLists",
    "PartitionAllocStraightenLargerSlotSpanFreeLists",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_166[] = {
    {
        "interval",
        "4s",
    },
    {
        "mode",
        "only-when-unprovisioning",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_404[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_34[] = {
    "PartitionAllocSortActiveSlotSpans",
};
const char* const array_kFieldTrialConfig_enable_features_386[] = {
    "PartitionAllocMemoryReclaimer",
    "PartitionAllocSortSmallerSlotSpanFreeLists",
    "PartitionAllocStraightenLargerSlotSpanFreeLists",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_165[] = {
    {
        "interval",
        "8s",
    },
    {
        "mode",
        "only-when-unprovisioning",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_403[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_344[] = {
    {
        "Interval_8sec",
        array_kFieldTrialConfig_platforms_403,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_165,
        array_kFieldTrialConfig_enable_features_386,
        array_kFieldTrialConfig_disable_features_34,
        nullptr,
        {},
        {},
        {},
    },
    {
        "SortActiveSlotSpans",
        array_kFieldTrialConfig_platforms_404,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_166,
        array_kFieldTrialConfig_enable_features_387,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "DontSortSmallerSlotSpanFreeLists",
        array_kFieldTrialConfig_platforms_405,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_167,
        array_kFieldTrialConfig_enable_features_388,
        array_kFieldTrialConfig_disable_features_35,
        nullptr,
        {},
        {},
        {},
    },
    {
        "AlwaysStraightenLargerSlotSpanFreeLists",
        array_kFieldTrialConfig_platforms_406,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_168,
        array_kFieldTrialConfig_enable_features_389,
        array_kFieldTrialConfig_disable_features_36,
        nullptr,
        {},
        {},
        {},
    },
    {
        "DontStraightenLargerSlotSpanFreeLists_v2",
        array_kFieldTrialConfig_platforms_407,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_169,
        array_kFieldTrialConfig_enable_features_390,
        array_kFieldTrialConfig_disable_features_37,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_385[] = {
    "PartitionAllocLargeThreadCacheSize",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_164[] = {
    {
        "PartitionAllocLargeThreadCacheSizeValue",
        "32768",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_402[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_343[] = {
    {
        "size_32768_20230925",
        array_kFieldTrialConfig_platforms_402,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_164,
        array_kFieldTrialConfig_enable_features_385,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_384[] = {
    "PartitionAllocBackupRefPtr",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_163[] = {
    {
        "enabled-processes",
        "all-processes",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_401[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_342[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_401,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_163,
        array_kFieldTrialConfig_enable_features_384,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_383[] = {
    "PartitionAllocSchedulerLoopQuarantine",
    "PartitionAllocZappingByFreeFlags",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_162[] = {
    {
        "PartitionAllocSchedulerLoopQuarantineBranchCapacity",
        "262144",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_400[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_341[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_400,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_162,
        array_kFieldTrialConfig_enable_features_383,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_382[] = {
    "PartitionAllocEventuallyZeroFreedMemory",
    "V8Flag_zero_unused_memory",
};
const Study::Platform array_kFieldTrialConfig_platforms_399[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_340[] = {
    {
        "EnabledPAAndV8_20241106",
        array_kFieldTrialConfig_platforms_399,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_382,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_381[] = {
    "LessAggressiveParkableString",
    "UseZstdForParkableStrings",
};
const Study::Platform array_kFieldTrialConfig_platforms_398[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_339[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_398,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_381,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_380[] = {
    "DelayParkingImages",
    "ParkableImagesToDisk",
    "UseParkableImageSegmentReader",
};
const Study::Platform array_kFieldTrialConfig_platforms_397[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_338[] = {
    {
        "Both_V4",
        array_kFieldTrialConfig_platforms_397,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_380,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_379[] = {
    "PaintHoldingForIframes",
};
const Study::Platform array_kFieldTrialConfig_platforms_396[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_337[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_396,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_379,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_378[] = {
    "PageInfoAboutThisSiteMoreLangs",
};
const Study::Platform array_kFieldTrialConfig_platforms_395[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_336[] = {
    {
        "Enabled_231129",
        array_kFieldTrialConfig_platforms_395,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_378,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_377[] = {
    "PageAllocatorRetryOnCommitFailure",
};
const Study::Platform array_kFieldTrialConfig_platforms_394[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_335[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_394,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_377,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_376[] = {
    "PwaNavigationCapturing",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_161[] = {
    {
        "link_capturing_state",
        "reimpl_on_via_client_mode",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_393[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_375[] = {
    "PwaNavigationCapturing",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_160[] = {
    {
        "link_capturing_state",
        "reimpl_default_off",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_392[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_374[] = {
    "PwaNavigationCapturing",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_159[] = {
    {
        "link_capturing_state",
        "reimpl_default_on",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_391[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_334[] = {
    {
        "EnabledSettingOnByDefault20241105",
        array_kFieldTrialConfig_platforms_391,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_159,
        array_kFieldTrialConfig_enable_features_374,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledSettingOffByDefault20241105",
        array_kFieldTrialConfig_platforms_392,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_160,
        array_kFieldTrialConfig_enable_features_375,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledSettingOnForClientModes",
        array_kFieldTrialConfig_platforms_393,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_161,
        array_kFieldTrialConfig_enable_features_376,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_373[] = {
    "AppSpecificNotifications",
};
const Study::Platform array_kFieldTrialConfig_platforms_390[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_333[] = {
    {
        "EnablePWAIconAndTitleInNativeNotificationsWin",
        array_kFieldTrialConfig_platforms_390,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_373,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_372[] = {
    "MacAllowBackgroundingRenderProcesses",
    "PMProcessPriorityPolicy",
    "PriorityOverridePendingViews",
    "RestrictThreadPoolInBackground",
    "SetIsolatesPriority",
    "UnimportantFramesPriority",
    "UserVisibleProcessPriority",
};
const Study::Platform array_kFieldTrialConfig_platforms_389[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_33[] = {
    "RestrictThreadPoolInBackground",
    "SetIsolatesPriority",
    "UnimportantFramesPriority",
    "UserVisibleProcessPriority",
};
const char* const array_kFieldTrialConfig_enable_features_371[] = {
    "MacAllowBackgroundingRenderProcesses",
    "PMProcessPriorityPolicy",
    "PriorityOverridePendingViews",
};
const Study::Platform array_kFieldTrialConfig_platforms_388[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_32[] = {
    "MacAllowBackgroundingRenderProcesses",
    "RestrictThreadPoolInBackground",
    "SetIsolatesPriority",
    "UnimportantFramesPriority",
    "UserVisibleProcessPriority",
};
const char* const array_kFieldTrialConfig_enable_features_370[] = {
    "PMProcessPriorityPolicy",
    "PriorityOverridePendingViews",
};
const Study::Platform array_kFieldTrialConfig_platforms_387[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_332[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_387,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_370,
        array_kFieldTrialConfig_disable_features_32,
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledWithMacBackgrounding",
        array_kFieldTrialConfig_platforms_388,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_371,
        array_kFieldTrialConfig_disable_features_33,
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledWithTriStatePriority",
        array_kFieldTrialConfig_platforms_389,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_372,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_369[] = {
    "EnableOopPrintDrivers",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_158[] = {
    {
        "EarlyStart",
        "false",
    },
    {
        "JobPrint",
        "true",
    },
    {
        "Sandbox",
        "false",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_386[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_331[] = {
    {
        "Enabled_20230912",
        array_kFieldTrialConfig_platforms_386,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_158,
        array_kFieldTrialConfig_enable_features_369,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_368[] = {
    "OptimizationHints",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_157[] = {
    {
        "max_url_keyed_hint_cache_size",
        "50",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_385[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_330[] = {
    {
        "Enabled_20240625",
        array_kFieldTrialConfig_platforms_385,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_157,
        array_kFieldTrialConfig_enable_features_368,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_367[] = {
    "OptimizationHintsFetchingSRP",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_156[] = {
    {
        "max_urls_for_srp_fetch",
        "10",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_384[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_329[] = {
    {
        "Enabled_20240624",
        array_kFieldTrialConfig_platforms_384,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_156,
        array_kFieldTrialConfig_enable_features_367,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_366[] = {
    "ActiveContentSettingExpiry",
    "OneTimePermission",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_155[] = {
    {
        "show_allow_always_as_first_button",
        "false",
    },
    {
        "use_stronger_prompt_language",
        "true",
    },
    {
        "use_while_visiting_language",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_383[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_365[] = {
    "ActiveContentSettingExpiry",
    "OneTimePermission",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_154[] = {
    {
        "show_allow_always_as_first_button",
        "true",
    },
    {
        "use_stronger_prompt_language",
        "true",
    },
    {
        "use_while_visiting_language",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_382[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_364[] = {
    "ActiveContentSettingExpiry",
    "OneTimePermission",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_153[] = {
    {
        "show_allow_always_as_first_button",
        "true",
    },
    {
        "use_stronger_prompt_language",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_381[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_31[] = {
    "ActiveContentSettingExpiry",
    "OneTimePermission",
};
const Study::Platform array_kFieldTrialConfig_platforms_380[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_30[] = {
    "ActiveContentSettingExpiry",
    "OneTimePermission",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_152[] = {
    {
        "probability",
        "1",
    },
    {
        "probability_vector",
        "1.0,1.0,1.0",
    },
    {
        "prompt_disposition_reason_filter",
        "DefaultFallback",
    },
    {
        "request_type_filter",
        "Geolocation,VideoCapture,AudioCapture",
    },
    {
        "survey_display_time",
        "OnPromptResolved",
    },
    {
        "trigger_id",
        "q1b37Zevt0ugnJ3q1cK0THbqyNJ4,zZBrVcebz0ugnJ3q1cK0Q9Uo6NFQ,m42rnDDGV0ugnJ3q1cK0RDuG9CQ4",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_379[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_363[] = {
    "ActiveContentSettingExpiry",
    "OneTimePermission",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_151[] = {
    {
        "use_stronger_prompt_language",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_378[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_362[] = {
    "ActiveContentSettingExpiry",
    "OneTimePermission",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_150[] = {
    {
        "use_stronger_prompt_language",
        "false",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_377[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_328[] = {
    {
        "EnabledWithNormalLanguage",
        array_kFieldTrialConfig_platforms_377,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_150,
        array_kFieldTrialConfig_enable_features_362,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledWithStrongLanguage",
        array_kFieldTrialConfig_platforms_378,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_151,
        array_kFieldTrialConfig_enable_features_363,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "HatsControl",
        array_kFieldTrialConfig_platforms_379,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_152,
        {},
        array_kFieldTrialConfig_disable_features_30,
        nullptr,
        {},
        {},
        {},
    },
    {
        "Control",
        array_kFieldTrialConfig_platforms_380,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_31,
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledWithAllowOnEveryVisitAsFirstButton",
        array_kFieldTrialConfig_platforms_381,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_153,
        array_kFieldTrialConfig_enable_features_364,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledWithAllowWhileVisitingAsFirstButton",
        array_kFieldTrialConfig_platforms_382,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_154,
        array_kFieldTrialConfig_enable_features_365,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledWithAllowWhileVisitingAsSecondButton",
        array_kFieldTrialConfig_platforms_383,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_155,
        array_kFieldTrialConfig_enable_features_366,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_361[] = {
    "OneCopyLegacyMPVideoFrameUploadViaSI",
};
const Study::Platform array_kFieldTrialConfig_platforms_376[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_327[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_376,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_361,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_360[] = {
    "StarterPackIPH",
};
const Study::Platform array_kFieldTrialConfig_platforms_375[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_326[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_375,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_360,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_29[] = {
    "OmniboxDocumentProviderNoSyncRequirement",
};
const char* const array_kFieldTrialConfig_enable_features_359[] = {
    "OmniboxDocumentProvider",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_149[] = {
    {
        "DocumentProviderBackoffOn401",
        "true",
    },
    {
        "DocumentProviderIgnoreWhenDebouncing",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_374[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_358[] = {
    "OmniboxDocumentProvider",
    "OmniboxDocumentProviderNoSyncRequirement",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_148[] = {
    {
        "DocumentProviderBackoffOn401",
        "true",
    },
    {
        "DocumentProviderIgnoreWhenDebouncing",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_373[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_357[] = {
    "OmniboxDocumentProvider",
    "OmniboxDocumentProviderNoSyncRequirement",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_147[] = {
    {
        "DocumentProviderBackoffOn401",
        "true",
    },
    {
        "DocumentProviderIgnoreWhenDebouncing",
        "false",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_372[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_325[] = {
    {
        "Enabled_NoSyncRequirement_V3",
        array_kFieldTrialConfig_platforms_372,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_147,
        array_kFieldTrialConfig_enable_features_357,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_NoSyncRequirement_IgnoreWhenDebouncing_V3",
        array_kFieldTrialConfig_platforms_373,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_148,
        array_kFieldTrialConfig_enable_features_358,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_IgnoreWhenDebouncing_V3",
        array_kFieldTrialConfig_platforms_374,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_149,
        array_kFieldTrialConfig_enable_features_359,
        array_kFieldTrialConfig_disable_features_29,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_356[] = {
    "OmniboxOnDeviceTailModel",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_146[] = {
    {
        "UnloadExecutorOnIdle ",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_371[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_355[] = {
    "OmniboxOnDeviceTailModel",
};
const Study::Platform array_kFieldTrialConfig_platforms_370[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_324[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_370,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_355,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_Auto_Unload",
        array_kFieldTrialConfig_platforms_371,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_146,
        array_kFieldTrialConfig_enable_features_356,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_354[] = {
    "OmniboxOnDeviceHeadProviderNonIncognito",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_145[] = {
    {
        "SelectionFix ",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_369[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_323[] = {
    {
        "Fix",
        array_kFieldTrialConfig_platforms_369,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_145,
        array_kFieldTrialConfig_enable_features_354,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_353[] = {
    "MlUrlPiecewiseMappedSearchBlending",
    "MlUrlScoring",
    "UrlScoringModel",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_144[] = {
    {
        "MlUrlPiecewiseMappedSearchBlending",
        "true",
    },
    {
        "MlUrlPiecewiseMappedSearchBlending_BreakPoints",
        "0,550;0.018,1150;0.14,1248;1,1422",
    },
    {
        "MlUrlPiecewiseMappedSearchBlending_GroupingThreshold",
        "1264",
    },
    {
        "MlUrlPiecewiseMappedSearchBlending_RelevanceBias",
        "0",
    },
    {
        "MlUrlScoringShortcutDocumentSignals",
        "true",
    },
    {
        "enable_scoring_signals_annotators_for_ml_scoring",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_368[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_352[] = {
    "MlUrlPiecewiseMappedSearchBlending",
    "MlUrlScoring",
    "UrlScoringModel",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_143[] = {
    {
        "MlUrlPiecewiseMappedSearchBlending",
        "true",
    },
    {
        "MlUrlPiecewiseMappedSearchBlending_BreakPoints",
        "0,550;0.018,1200;0.14,1298;1,1422",
    },
    {
        "MlUrlPiecewiseMappedSearchBlending_GroupingThreshold",
        "1314",
    },
    {
        "MlUrlPiecewiseMappedSearchBlending_RelevanceBias",
        "0",
    },
    {
        "MlUrlScoringShortcutDocumentSignals",
        "true",
    },
    {
        "enable_scoring_signals_annotators_for_ml_scoring",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_367[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_351[] = {
    "MlUrlPiecewiseMappedSearchBlending",
    "MlUrlScoring",
    "UrlScoringModel",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_142[] = {
    {
        "MlUrlPiecewiseMappedSearchBlending",
        "true",
    },
    {
        "MlUrlPiecewiseMappedSearchBlending_BreakPoints",
        "0,550;0.018,1250;0.14,1348;1,1422",
    },
    {
        "MlUrlPiecewiseMappedSearchBlending_GroupingThreshold",
        "1364",
    },
    {
        "MlUrlPiecewiseMappedSearchBlending_RelevanceBias",
        "0",
    },
    {
        "MlUrlScoringShortcutDocumentSignals",
        "true",
    },
    {
        "enable_scoring_signals_annotators_for_ml_scoring",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_366[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_350[] = {
    "MlUrlPiecewiseMappedSearchBlending",
    "MlUrlScoring",
    "UrlScoringModel",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_141[] = {
    {
        "MlUrlPiecewiseMappedSearchBlending",
        "true",
    },
    {
        "MlUrlPiecewiseMappedSearchBlending_BreakPoints",
        "0,550;0.018,1300;0.14,1398;1,1422",
    },
    {
        "MlUrlPiecewiseMappedSearchBlending_GroupingThreshold",
        "1414",
    },
    {
        "MlUrlPiecewiseMappedSearchBlending_RelevanceBias",
        "0",
    },
    {
        "MlUrlScoringShortcutDocumentSignals",
        "true",
    },
    {
        "enable_scoring_signals_annotators_for_ml_scoring",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_365[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_322[] = {
    {
        "Enabled_AdjustedBy0",
        array_kFieldTrialConfig_platforms_365,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_141,
        array_kFieldTrialConfig_enable_features_350,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_DemotedBy50",
        array_kFieldTrialConfig_platforms_366,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_142,
        array_kFieldTrialConfig_enable_features_351,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_DemotedBy100",
        array_kFieldTrialConfig_platforms_367,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_143,
        array_kFieldTrialConfig_enable_features_352,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_DemotedBy150",
        array_kFieldTrialConfig_platforms_368,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_144,
        array_kFieldTrialConfig_enable_features_353,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_349[] = {
    "LogUrlScoringSignals",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_140[] = {
    {
        "enable_scoring_signals_annotators",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_364[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_321[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_364,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_140,
        array_kFieldTrialConfig_enable_features_349,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_348[] = {
    "ShowFeaturedEnterpriseSiteSearch",
};
const Study::Platform array_kFieldTrialConfig_platforms_363[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_347[] = {
    "ShowFeaturedEnterpriseSiteSearch",
    "ShowFeaturedEnterpriseSiteSearchIPH",
};
const Study::Platform array_kFieldTrialConfig_platforms_362[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_320[] = {
    {
        "Enabled_IPH",
        array_kFieldTrialConfig_platforms_362,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_347,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_363,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_348,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_346[] = {
    "OmniboxDeleteOldShortcuts",
};
const Study::Platform array_kFieldTrialConfig_platforms_361[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_319[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_361,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_346,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_345[] = {
    "Cr2023ActionChips",
    "Cr2023ActionChipsIcons",
    "OmniboxExpandedLayout",
    "OmniboxExpandedStateColors",
    "OmniboxExpandedStateHeight",
    "OmniboxExpandedStateShape",
    "OmniboxExpandedStateSuggestIcons",
    "OmniboxSteadyStateBackgroundColor",
    "OmniboxSteadyStateHeight",
    "OmniboxSteadyStateTextColor",
    "OmniboxSuggestionHoverFillShape",
    "kOmniboxCR23SteadyStateIcons",
};
const Study::Platform array_kFieldTrialConfig_platforms_360[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_318[] = {
    {
        "enabled",
        array_kFieldTrialConfig_platforms_360,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_345,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_344[] = {
    "OmniboxRemoveSuggestionsFromClipboard",
    "OmniboxUIExperimentMaxAutocompleteMatches",
};
const Study::Platform array_kFieldTrialConfig_platforms_359[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_317[] = {
    {
        "DesktopExperiments",
        array_kFieldTrialConfig_platforms_359,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_344,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_358[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_316[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_358,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_343[] = {
    "OidcAuthProfileManagement",
};
const Study::Platform array_kFieldTrialConfig_platforms_357[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_315[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_357,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_343,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_342[] = {
    "DrawQuadSplitLimit",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_139[] = {
    {
        "num_of_splits",
        "14",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_356[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_341[] = {
    "DrawQuadSplitLimit",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_138[] = {
    {
        "num_of_splits",
        "12",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_355[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_340[] = {
    "DrawQuadSplitLimit",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_137[] = {
    {
        "num_of_splits",
        "10",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_354[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_339[] = {
    "DrawQuadSplitLimit",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_136[] = {
    {
        "num_of_splits",
        "7",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_353[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_338[] = {
    "DrawQuadSplitLimit",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_135[] = {
    {
        "num_of_splits",
        "6",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_352[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_337[] = {
    "DrawQuadSplitLimit",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_134[] = {
    {
        "num_of_splits",
        "8",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_351[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_314[] = {
    {
        "quad_split_limit_8",
        array_kFieldTrialConfig_platforms_351,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_134,
        array_kFieldTrialConfig_enable_features_337,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "quad_split_limit_6",
        array_kFieldTrialConfig_platforms_352,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_135,
        array_kFieldTrialConfig_enable_features_338,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "quad_split_limit_7",
        array_kFieldTrialConfig_platforms_353,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_136,
        array_kFieldTrialConfig_enable_features_339,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "quad_split_limit_10",
        array_kFieldTrialConfig_platforms_354,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_137,
        array_kFieldTrialConfig_enable_features_340,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "quad_split_limit_12",
        array_kFieldTrialConfig_platforms_355,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_138,
        array_kFieldTrialConfig_enable_features_341,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "quad_split_limit_14",
        array_kFieldTrialConfig_platforms_356,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_139,
        array_kFieldTrialConfig_enable_features_342,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_336[] = {
    "NormalMaxItemsInCacheForSoftwareFeature",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_133[] = {
    {
        "NormalMaxItemsInCacheForSoftware",
        "1000",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_350[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_313[] = {
    {
        "ImageCache_1000_20230914",
        array_kFieldTrialConfig_platforms_350,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_133,
        array_kFieldTrialConfig_enable_features_336,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_28[] = {
    "NonStandardAppearanceValueSliderVertical",
};
const Study::Platform array_kFieldTrialConfig_platforms_349[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_312[] = {
    {
        "Disabled",
        array_kFieldTrialConfig_platforms_349,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_28,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_335[] = {
    "NoThrottlingVisibleAgent",
};
const Study::Platform array_kFieldTrialConfig_platforms_348[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_311[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_348,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_335,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_334[] = {
    "NoPreReadMainDllIfSsd",
};
const Study::Platform array_kFieldTrialConfig_platforms_347[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_310[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_347,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_334,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_333[] = {
    "NoPasswordSuggestionFiltering",
};
const Study::Platform array_kFieldTrialConfig_platforms_346[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_309[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_346,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_333,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_332[] = {
    "NewEvSignalsEnabled",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_132[] = {
    {
        "DisableFileSystemInfo",
        "true",
    },
    {
        "DisableSettings",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_345[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_308[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_345,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_132,
        array_kFieldTrialConfig_enable_features_332,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_331[] = {
    "NewContentForCheckerboardedScrolls",
};
const Study::Platform array_kFieldTrialConfig_platforms_344[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_307[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_344,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_331,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_330[] = {
    "NetworkServiceSandbox",
};
const Study::Platform array_kFieldTrialConfig_platforms_343[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_306[] = {
    {
        "Enabled_20231025",
        array_kFieldTrialConfig_platforms_343,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_330,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_329[] = {
    "NetworkQualityEstimator",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_131[] = {
    {
        "HalfLifeSeconds",
        "15",
    },
    {
        "RecentEndToEndThresholdInSeconds",
        "60",
    },
    {
        "RecentHTTPThresholdInSeconds",
        "60",
    },
    {
        "RecentTransportThresholdInSeconds",
        "60",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_342[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_305[] = {
    {
        "Experiment",
        array_kFieldTrialConfig_platforms_342,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_131,
        array_kFieldTrialConfig_enable_features_329,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_328[] = {
    "NetAdapterMaxBufSizeFeature",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_130[] = {
    {
        "NetAdapterMaxBufSize",
        "65536",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_341[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_304[] = {
    {
        "max_buf_size_064k_20230922",
        array_kFieldTrialConfig_platforms_341,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_130,
        array_kFieldTrialConfig_enable_features_328,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_327[] = {
    "MutationEventsSpecialTrialMessage",
};
const Study::Platform array_kFieldTrialConfig_platforms_340[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_303[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_340,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_327,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_27[] = {
    "MutationEvents",
};
const Study::Platform array_kFieldTrialConfig_platforms_339[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_302[] = {
    {
        "Disabled",
        array_kFieldTrialConfig_platforms_339,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_27,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_326[] = {
    "MoveThemePrefsToSpecifics",
};
const Study::Platform array_kFieldTrialConfig_platforms_338[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_301[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_338,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_326,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_325[] = {
    "MojoPredictiveAllocation",
};
const Study::Platform array_kFieldTrialConfig_platforms_337[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_300[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_337,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_325,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_324[] = {
    "LargerDataPipeAllocationSizeFeature",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_129[] = {
    {
        "LargerDataPipeAllocationSize",
        "2097152",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_336[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_299[] = {
    {
        "data_pipe_2048k_20230922",
        array_kFieldTrialConfig_platforms_336,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_129,
        array_kFieldTrialConfig_enable_features_324,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_323[] = {
    "MojoInlineMessagePayloads",
};
const Study::Platform array_kFieldTrialConfig_platforms_335[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_298[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_335,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_323,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_322[] = {
    "MojoChannelAssociatedSendUsesRunOrPostTask",
};
const Study::Platform array_kFieldTrialConfig_platforms_334[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_297[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_334,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_322,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_321[] = {
    "MigrateDefaultChromeAppToWebAppsNonGSuite",
};
const Study::Platform array_kFieldTrialConfig_platforms_333[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_296[] = {
    {
        "Enabled_20210111",
        array_kFieldTrialConfig_platforms_333,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_321,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_320[] = {
    "MigrateDefaultChromeAppToWebAppsGSuite",
};
const Study::Platform array_kFieldTrialConfig_platforms_332[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_295[] = {
    {
        "Enabled_20210111",
        array_kFieldTrialConfig_platforms_332,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_320,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_319[] = {
    "MetricsServiceDeltaSnapshotInBg",
};
const Study::Platform array_kFieldTrialConfig_platforms_331[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_294[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_331,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_319,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_318[] = {
    "MetricsLogTrimming",
};
const Study::Platform array_kFieldTrialConfig_platforms_330[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_293[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_330,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_318,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_26[] = {
    "ReleaseResourceDecodedDataOnMemoryPressure",
};
const char* const array_kFieldTrialConfig_enable_features_317[] = {
    "ForwardMemoryPressureToBlinkIsolates",
    "MemoryPurgeInBackground",
    "ReleaseResourceStrongReferencesOnMemoryPressure",
};
const Study::Platform array_kFieldTrialConfig_platforms_329[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_25[] = {
    "ReleaseResourceStrongReferencesOnMemoryPressure",
};
const char* const array_kFieldTrialConfig_enable_features_316[] = {
    "ForwardMemoryPressureToBlinkIsolates",
    "MemoryPurgeInBackground",
    "ReleaseResourceDecodedDataOnMemoryPressure",
};
const Study::Platform array_kFieldTrialConfig_platforms_328[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_24[] = {
    "ForwardMemoryPressureToBlinkIsolates",
};
const char* const array_kFieldTrialConfig_enable_features_315[] = {
    "MemoryPurgeInBackground",
    "ReleaseResourceDecodedDataOnMemoryPressure",
    "ReleaseResourceStrongReferencesOnMemoryPressure",
};
const Study::Platform array_kFieldTrialConfig_platforms_327[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_23[] = {
    "MemoryPurgeInBackground",
};
const char* const array_kFieldTrialConfig_enable_features_314[] = {
    "ForwardMemoryPressureToBlinkIsolates",
    "ReleaseResourceDecodedDataOnMemoryPressure",
    "ReleaseResourceStrongReferencesOnMemoryPressure",
};
const Study::Platform array_kFieldTrialConfig_platforms_326[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_292[] = {
    {
        "DisableAll",
        array_kFieldTrialConfig_platforms_326,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_314,
        array_kFieldTrialConfig_disable_features_23,
        nullptr,
        {},
        {},
        {},
    },
    {
        "DisableGC",
        array_kFieldTrialConfig_platforms_327,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_315,
        array_kFieldTrialConfig_disable_features_24,
        nullptr,
        {},
        {},
        {},
    },
    {
        "DisableStrongReferences",
        array_kFieldTrialConfig_platforms_328,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_316,
        array_kFieldTrialConfig_disable_features_25,
        nullptr,
        {},
        {},
        {},
    },
    {
        "DisableDecodedData",
        array_kFieldTrialConfig_platforms_329,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_317,
        array_kFieldTrialConfig_disable_features_26,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_22[] = {
    "MemoryCacheStrongReferenceFilterScripts",
};
const char* const array_kFieldTrialConfig_enable_features_313[] = {
    "MemoryCacheStrongReference",
    "MemoryCacheStrongReferenceFilterImages",
};
const Study::Platform array_kFieldTrialConfig_platforms_325[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_291[] = {
    {
        "FilterImageAllPages_20240124",
        array_kFieldTrialConfig_platforms_325,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_313,
        array_kFieldTrialConfig_disable_features_22,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_312[] = {
    "MediaRecorderUseMediaVideoEncoder",
};
const Study::Platform array_kFieldTrialConfig_platforms_324[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_290[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_324,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_312,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_311[] = {
    "HardwareSecureDecryptionFallback",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_128[] = {
    {
        "per_site",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_323[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_289[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_323,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_128,
        array_kFieldTrialConfig_enable_features_311,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_310[] = {
    "HardwareSecureDecryptionExperiment",
};
const Study::Platform array_kFieldTrialConfig_platforms_322[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_288[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_322,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_310,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_309[] = {
    "MediaFoundationVP9Encoding",
};
const Study::Platform array_kFieldTrialConfig_platforms_321[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_287[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_321,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_309,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_308[] = {
    "MediaFoundationCameraUsageMonitoring",
};
const Study::Platform array_kFieldTrialConfig_platforms_320[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_286[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_320,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_308,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_307[] = {
    "MediaFoundationBatchRead",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_127[] = {
    {
        "batch_read_count",
        "200",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_319[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_285[] = {
    {
        "Enabled_200",
        array_kFieldTrialConfig_platforms_319,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_127,
        array_kFieldTrialConfig_enable_features_307,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_306[] = {
    "MediaFoundationAV1Encoding",
};
const Study::Platform array_kFieldTrialConfig_platforms_318[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_284[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_318,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_306,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_305[] = {
    "MediaDeviceIdPartitioning",
    "MediaDeviceIdRandomSaltsPerStorageKey",
};
const Study::Platform array_kFieldTrialConfig_platforms_317[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_283[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_317,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_305,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_304[] = {
    "MaxNumDelayableRequestsPerHostPerClientFeature",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_126[] = {
    {
        "MaxNumDelayableRequestsPerHostPerClient",
        "6",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_316[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_282[] = {
    {
        "MaxRequests_6_20230906",
        array_kFieldTrialConfig_platforms_316,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_126,
        array_kFieldTrialConfig_enable_features_304,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_303[] = {
    "MainNodeAnnotations",
};
const Study::Platform array_kFieldTrialConfig_platforms_315[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_281[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_315,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_303,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_302[] = {
    "MHTML_Improvements",
};
const Study::Platform array_kFieldTrialConfig_platforms_314[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_280[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_314,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_302,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_301[] = {
    "LowPriorityAsyncScriptExecution",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_125[] = {
    {
        "delay_async_exec_opt_out_auto_fetch_priority_hint",
        "false",
    },
    {
        "delay_async_exec_opt_out_high_fetch_priority_hint",
        "false",
    },
    {
        "delay_async_exec_opt_out_low_fetch_priority_hint",
        "false",
    },
    {
        "low_pri_async_exec_cross_site_only",
        "true",
    },
    {
        "low_pri_async_exec_exclude_document_write",
        "false",
    },
    {
        "low_pri_async_exec_exclude_non_parser_inserted",
        "false",
    },
    {
        "low_pri_async_exec_feature_limit",
        "3s",
    },
    {
        "low_pri_async_exec_lower_task_priority",
        "best_effort",
    },
    {
        "low_pri_async_exec_main_frame_only",
        "true",
    },
    {
        "low_pri_async_exec_target",
        "both",
    },
    {
        "low_pri_async_exec_timeout",
        "1s",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_313[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_279[] = {
    {
        "PreviousBest_20240501",
        array_kFieldTrialConfig_platforms_313,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_125,
        array_kFieldTrialConfig_enable_features_301,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_300[] = {
    "LogOnDeviceMetricsOnStartup",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_124[] = {
    {
        "on_device_startup_metric_delay",
        "3m",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_312[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_278[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_312,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_124,
        array_kFieldTrialConfig_enable_features_300,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_299[] = {
    "LocalStateEnterprisePasswordHashes",
};
const Study::Platform array_kFieldTrialConfig_platforms_311[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_277[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_311,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_299,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_298[] = {
    "LoadingPredictorLimitPreconnectSocketCount",
};
const Study::Platform array_kFieldTrialConfig_platforms_310[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_276[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_310,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_298,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_297[] = {
    "LoadingPhaseBufferTimeAfterFirstMeaningfulPaint",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_123[] = {
    {
        "LoadingPhaseBufferTimeAfterFirstMeaningfulPaintMillis",
        "500",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_309[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_275[] = {
    {
        "buffer_500ms_20230907",
        array_kFieldTrialConfig_platforms_309,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_123,
        array_kFieldTrialConfig_enable_features_297,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_296[] = {
    "LiveCaptionMultiLanguage",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_122[] = {
    {
        "available_languages",
        "en-US,fr-FR,it-IT,de-DE",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_308[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_274[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_308,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_122,
        array_kFieldTrialConfig_enable_features_296,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_295[] = {
    "LiveCaptionExperimentalLanguages",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_121[] = {
    {
        "available_languages",
        "en-US,fr-FR,it-IT,de-DE,es-ES,ja-JP,hi-IN,pt-BR,ko-KR,pl-PL,th-TH,tr-TR,id-ID,cmn-Hans-CN,cmn-Hant-TW,vi-VN,ru-RU",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_307[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_273[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_307,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_121,
        array_kFieldTrialConfig_enable_features_295,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_294[] = {
    "LinkedServicesSetting",
    "LinkedServicesSettingIos",
};
const Study::Platform array_kFieldTrialConfig_platforms_306[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_272[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_306,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_294,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_293[] = {
    "LinkPreview",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_120[] = {
    {
        "trigger_type",
        "alt_click",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_305[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_271[] = {
    {
        "EnabledAltClick",
        array_kFieldTrialConfig_platforms_305,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_120,
        array_kFieldTrialConfig_enable_features_293,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_21[] = {
    "GwpAsanMalloc",
    "GwpAsanPartitionAlloc",
};
const char* const array_kFieldTrialConfig_enable_features_292[] = {
    "LightweightUafDetector",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_119[] = {
    {
        "AllocationSamplingMultiplier",
        "100",
    },
    {
        "EvictionTaskIntervalMs",
        "5000",
    },
    {
        "MaxAllocations",
        "1400",
    },
    {
        "MaxMetadata",
        "5100",
    },
    {
        "MaxTotalSize",
        "131072",
    },
    {
        "Mode",
        "Random",
    },
    {
        "TotalSizeHighWaterMark",
        "104857",
    },
    {
        "TotalSizeLowWaterMark",
        "91750",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_304[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_270[] = {
    {
        "Enabled_20240130",
        array_kFieldTrialConfig_platforms_304,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_119,
        array_kFieldTrialConfig_enable_features_292,
        array_kFieldTrialConfig_disable_features_21,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_291[] = {
    "LeakSkiaEventTracerAtExit",
};
const Study::Platform array_kFieldTrialConfig_platforms_303[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_269[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_303,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_291,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_290[] = {
    "LazyUpdateTranslateModel",
};
const Study::Platform array_kFieldTrialConfig_platforms_302[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_268[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_302,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_290,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_289[] = {
    "LazyBlinkTimezoneInit",
};
const Study::Platform array_kFieldTrialConfig_platforms_301[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_267[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_301,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_289,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_288[] = {
    "LayoutNGShapeCache",
};
const Study::Platform array_kFieldTrialConfig_platforms_300[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_266[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_300,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_288,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_287[] = {
    "LCPTimingPredictorPrerender2",
};
const Study::Platform array_kFieldTrialConfig_platforms_299[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_265[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_299,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_287,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_286[] = {
    "LCPPPrefetchSubresource",
};
const Study::Platform array_kFieldTrialConfig_platforms_298[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_264[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_298,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_286,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_285[] = {
    "LCPPMultipleKey",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_118[] = {
    {
        "lcpp_max_hosts_to_track",
        "100",
    },
    {
        "lcpp_multiple_key_histogram_sliding_window_size",
        "1000",
    },
    {
        "lcpp_multiple_key_max_histogram_buckets",
        "10",
    },
    {
        "lcpp_multiple_key_max_path_length",
        "15",
    },
    {
        "lcpp_multiple_key_type",
        "lcpp_key_stat",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_297[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_284[] = {
    "LCPPMultipleKey",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_117[] = {
    {
        "lcpp_max_hosts_to_track",
        "1000",
    },
    {
        "lcpp_multiple_key_max_path_length",
        "15",
    },
    {
        "lcpp_multiple_key_type",
        "default",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_296[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_283[] = {
    "LCPPMultipleKey",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_116[] = {
    {
        "lcpp_max_hosts_to_track",
        "100",
    },
    {
        "lcpp_multiple_key_max_path_length",
        "15",
    },
    {
        "lcpp_multiple_key_type",
        "default",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_295[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_263[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_295,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_116,
        array_kFieldTrialConfig_enable_features_283,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "WithMaxHost1000",
        array_kFieldTrialConfig_platforms_296,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_117,
        array_kFieldTrialConfig_enable_features_284,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledKeyStat",
        array_kFieldTrialConfig_platforms_297,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_118,
        array_kFieldTrialConfig_enable_features_285,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_282[] = {
    "LCPPLazyLoadImagePreload",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_115[] = {
    {
        "lcpp_preload_lazy_load_image_type",
        "native_lazy_loading",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_294[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_262[] = {
    {
        "EnableWithNativeLazyLoading_20231113",
        array_kFieldTrialConfig_platforms_294,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_115,
        array_kFieldTrialConfig_enable_features_282,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_281[] = {
    "LCPCriticalPathPredictor",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_114[] = {
    {
        "lcpp_adjust_image_load_priority",
        "true",
    },
    {
        "lcpp_adjust_image_load_priority_override_first_n_boost",
        "true",
    },
    {
        "lcpp_enable_image_load_priority_for_htmlimageelement",
        "false",
    },
    {
        "lcpp_enable_perf_improvements",
        "true",
    },
    {
        "lcpp_histogram_sliding_window_size",
        "1000",
    },
    {
        "lcpp_image_load_priority",
        "medium",
    },
    {
        "lcpp_max_element_locator_length",
        "1024",
    },
    {
        "lcpp_max_histogram_buckets",
        "10",
    },
    {
        "lcpp_max_hosts_to_track",
        "100",
    },
    {
        "lcpp_recorded_lcp_element_types",
        "image_only",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_293[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_261[] = {
    {
        "MediumPriority_20240418",
        array_kFieldTrialConfig_platforms_293,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_114,
        array_kFieldTrialConfig_enable_features_281,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_280[] = {
    "LCPPFontURLPredictor",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_113[] = {
    {
        "lcpp_enable_font_prefetch",
        "true",
    },
    {
        "lcpp_font_prefetch_threshold",
        "1.1",
    },
    {
        "lcpp_font_url_frequency_threshold",
        "0.1",
    },
    {
        "lcpp_max_font_url_count_per_origin",
        "5",
    },
    {
        "lcpp_max_font_url_length",
        "1024",
    },
    {
        "lcpp_max_font_url_to_preload",
        "5",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_292[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_279[] = {
    "LCPPFontURLPredictor",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_112[] = {
    {
        "lcpp_font_prefetch_threshold",
        "1.1",
    },
    {
        "lcpp_font_url_frequency_threshold",
        "0.1",
    },
    {
        "lcpp_max_font_url_count_per_origin",
        "5",
    },
    {
        "lcpp_max_font_url_length",
        "1024",
    },
    {
        "lcpp_max_font_url_to_preload",
        "5",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_291[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_260[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_291,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_112,
        array_kFieldTrialConfig_enable_features_279,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "WithPrefetch",
        array_kFieldTrialConfig_platforms_292,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_113,
        array_kFieldTrialConfig_enable_features_280,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_278[] = {
    "LCPPDeferUnusedPreload",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_111[] = {
    {
        "load_timing",
        "lcp_timing_predictor",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_290[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_277[] = {
    "LCPPDeferUnusedPreload",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_110[] = {
    {
        "load_timing",
        "post_task",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_289[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_259[] = {
    {
        "EnableWithPostTask_20240426",
        array_kFieldTrialConfig_platforms_289,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_110,
        array_kFieldTrialConfig_enable_features_277,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnableWithLCPTimingPredictor_20240426",
        array_kFieldTrialConfig_platforms_290,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_111,
        array_kFieldTrialConfig_enable_features_278,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_276[] = {
    "CustomProfileStringsForSupervisedUsers",
    "ForceSafeSearchForUnauthenticatedSupervisedUsers",
    "ForceSupervisedUserReauthenticationForBlockedSites",
    "ForceSupervisedUserReauthenticationForYouTube",
    "HideGuestModeForSupervisedUsers",
    "IPH_SupervisedUserProfileSignin",
    "ShowKiteForSupervisedUsers",
    "UncredentialedFilteringFallbackForSupervisedUsers",
};
const Study::Platform array_kFieldTrialConfig_platforms_288[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_258[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_288,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_276,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_20[] = {
    "KeyboardFocusableScrollers",
};
const Study::Platform array_kFieldTrialConfig_platforms_287[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_275[] = {
    "KeyboardFocusableScrollers",
};
const Study::Platform array_kFieldTrialConfig_platforms_286[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_257[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_286,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_275,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Disabled",
        array_kFieldTrialConfig_platforms_287,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_20,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_274[] = {
    "KeyboardAndPointerLockPrompt",
};
const Study::Platform array_kFieldTrialConfig_platforms_285[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_256[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_285,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_274,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_273[] = {
    "AttributionReportingInBrowserMigration",
    "KeepAliveInBrowserMigration",
};
const Study::Platform array_kFieldTrialConfig_platforms_284[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_272[] = {
    "KeepAliveInBrowserMigration",
};
const Study::Platform array_kFieldTrialConfig_platforms_283[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_255[] = {
    {
        "Enabled_20240117",
        array_kFieldTrialConfig_platforms_283,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_272,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "AttributionReportingInBrowserMigration",
        array_kFieldTrialConfig_platforms_284,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_273,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_271[] = {
    "JourneysOnDeviceClusteringContentClustering",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_109[] = {
    {
        "collections_blocklist",
        "/collection/it_glossary,/collection/periodicals,/collection/software,/collection/tv_networks,/collection/websites",
    },
    {
        "search_visits_only",
        "false",
    },
    {
        "use_pairwise_merge",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_282[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_254[] = {
    {
        "AllVisitsContentClusteringPairwiseMerge_20230714",
        array_kFieldTrialConfig_platforms_282,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_109,
        array_kFieldTrialConfig_enable_features_271,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_270[] = {
    "CbcmPolicyInvalidationWithDirectMessagesEnabled",
    "CbcmRemoteCommandsInvalidationWithDirectMessagesEnabled",
    "UserPolicyInvalidationWithDirectMessagesEnabled",
    "UserRemoteCommandsInvalidationWithDirectMessagesEnabled",
};
const Study::Platform array_kFieldTrialConfig_platforms_281[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_253[] = {
    {
        "BrowserPolicyUserRemoteCommands",
        array_kFieldTrialConfig_platforms_281,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_270,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_269[] = {
    "IncreasedCmdBufferParseSlice",
};
const Study::Platform array_kFieldTrialConfig_platforms_280[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_252[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_280,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_269,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_268[] = {
    "IncreaseCoookieAccesCacheSize",
};
const Study::Platform array_kFieldTrialConfig_platforms_279[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_251[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_279,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_268,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_267[] = {
    "ImprovedSemanticsActivityIndicators",
};
const Study::Platform array_kFieldTrialConfig_platforms_278[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_250[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_278,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_267,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_266[] = {
    "ImageDescriptionsAlternativeRouting",
};
const Study::Platform array_kFieldTrialConfig_platforms_277[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_249[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_277,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_266,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_265[] = {
    "IgnoreDuplicateNavs",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_108[] = {
    {
        "duplicate_nav_threshold",
        "1000",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_276[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_264[] = {
    "IgnoreDuplicateNavs",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_107[] = {
    {
        "duplicate_nav_threshold",
        "2000",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_275[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_19[] = {
    "IgnoreDuplicateNavs",
};
const Study::Platform array_kFieldTrialConfig_platforms_274[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_248[] = {
    {
        "Disabled",
        array_kFieldTrialConfig_platforms_274,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_19,
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_2ms",
        array_kFieldTrialConfig_platforms_275,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_107,
        array_kFieldTrialConfig_enable_features_264,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_1ms",
        array_kFieldTrialConfig_platforms_276,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_108,
        array_kFieldTrialConfig_enable_features_265,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_263[] = {
    "IdbPrioritizeForegroundClients",
};
const Study::Platform array_kFieldTrialConfig_platforms_273[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_247[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_273,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_263,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_262[] = {
    "IdbExpediteBackendProcessingForForegroundClients",
};
const Study::Platform array_kFieldTrialConfig_platforms_272[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_246[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_272,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_262,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_261[] = {
    "EnableIpPrivacyProxy",
    "MaskedDomainList",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_106[] = {
    {
        "IpPrivacyBsaEnablePrivacyPass",
        "true",
    },
    {
        "IpPrivacyDirectOnly",
        "false",
    },
    {
        "IpPrivacyIncludeOAuthTokenInGetProxyConfig",
        "true",
    },
    {
        "IpPrivacyTokenServer",
        "https://phosphor-pa.googleapis.com",
    },
    {
        "IpPrivacyTokenServerGetInitialDataPath",
        "/v1/ipblinding/getInitialData",
    },
    {
        "IpPrivacyTokenServerGetProxyConfigPath",
        "/v1/ipblinding/getProxyConfig",
    },
    {
        "IpPrivacyTokenServerGetTokensPath",
        "/v1/ipblinding/auth",
    },
    {
        "IpPrivacyUseProxyChains",
        "true",
    },
    {
        "MaskedDomainListExperimentalVersion",
        "rc0",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_271[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_245[] = {
    {
        "enabled_proxy_a_ip_protection_phase_04_19_2024",
        array_kFieldTrialConfig_platforms_271,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_106,
        array_kFieldTrialConfig_enable_features_261,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_260[] = {
    "IOSPromoAddressBubble",
    "IOSPromoPaymentBubble",
    "IOSPromoRefreshedPasswordBubble",
};
const Study::Platform array_kFieldTrialConfig_platforms_270[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_244[] = {
    {
        "EnabledPromosGroup_2024_10_24",
        array_kFieldTrialConfig_platforms_270,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_260,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_259[] = {
    "HttpsFirstModeV2ForTypicallySecureUsers",
};
const Study::Platform array_kFieldTrialConfig_platforms_269[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_243[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_269,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_259,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_258[] = {
    "HttpsFirstModeV2ForEngagedSites",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_105[] = {
    {
        "http-add-threshold",
        "1",
    },
    {
        "http-remove-threshold",
        "5",
    },
    {
        "https-add-threshold",
        "80",
    },
    {
        "https-remove-threshold",
        "75",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_268[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_242[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_268,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_105,
        array_kFieldTrialConfig_enable_features_258,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_257[] = {
    "HttpsFirstBalancedModeAutoEnable",
};
const Study::Platform array_kFieldTrialConfig_platforms_267[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_241[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_267,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_257,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_256[] = {
    "HttpDiskCachePrewarming",
    "SimpleURLLoaderUseReadAndDiscardBodyOption",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_104[] = {
    {
        "http_disk_cache_prewarming_use_read_and_discard_body_option",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_266[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_240[] = {
    {
        "WithReadAndDiscardBody_20240328",
        array_kFieldTrialConfig_platforms_266,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_104,
        array_kFieldTrialConfig_enable_features_256,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_255[] = {
    "HistoryEmbeddings",
    "HistoryEmbeddingsAnswers",
    "HistorySearchSettingsVisibility",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_103[] = {
    {
        "AnswersInOmniboxScoped",
        "true",
    },
    {
        "ContentVisibilityThreshold",
        "0.0",
    },
    {
        "EnableSidePanel",
        "true",
    },
    {
        "OmniboxScoped",
        "true",
    },
    {
        "SearchPassageMinimumWordCount",
        "5",
    },
    {
        "SearchQueryMinimumWordCount",
        "2",
    },
    {
        "SendQualityLog",
        "true",
    },
    {
        "SendQualityLogV2",
        "true",
    },
    {
        "TrimAfterHostInResults",
        "true",
    },
    {
        "UseMlAnswerer",
        "true",
    },
    {
        "WordMatchLimit",
        "5",
    },
    {
        "WordMatchMaxTermCount",
        "10",
    },
    {
        "WordMatchMinEmbeddingScore",
        "0.7",
    },
    {
        "WordMatchMinTermLength",
        "0",
    },
    {
        "WordMatchRequiredTermRatio",
        "1.0",
    },
    {
        "WordMatchScoreBoostFactor",
        "0.2",
    },
    {
        "WordMatchSmoothingFactor",
        "0",
    },
    {
        "allow_unsigned_user",
        "true",
    },
    {
        "enable_feature_when_main_toggle_on",
        "false",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_265[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_239[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_265,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_103,
        array_kFieldTrialConfig_enable_features_255,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_254[] = {
    "HangoutsExtensionV3",
};
const Study::Platform array_kFieldTrialConfig_platforms_264[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_238[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_264,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_254,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_253[] = {
    "Http2Grease",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_102[] = {
    {
        "http2_grease_settings",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_263[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_237[] = {
    {
        "Enabled6",
        array_kFieldTrialConfig_platforms_263,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_102,
        array_kFieldTrialConfig_enable_features_253,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_252[] = {
    "Journeys",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_101[] = {
    {
        "JourneysLocaleOrLanguageAllowlist",
        "*",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_262[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_236[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_262,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_101,
        array_kFieldTrialConfig_enable_features_252,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_251[] = {
    "GrCacheLimitsFeature",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_100[] = {
    {
        "MaxDefaultGlyphCacheTextureBytes",
        "8388608",
    },
    {
        "MaxGaneshResourceCacheBytes",
        "100663296",
    },
    {
        "MaxHighEndGaneshResourceCacheBytes",
        "268435456",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_261[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_235[] = {
    {
        "cache_96_256_8_default_20230911",
        array_kFieldTrialConfig_platforms_261,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_100,
        array_kFieldTrialConfig_enable_features_251,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_250[] = {
    "GpuYieldRasterization",
};
const Study::Platform array_kFieldTrialConfig_platforms_260[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_234[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_260,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_250,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_249[] = {
    "LensImageFormatOptimizations",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_99[] = {
    {
        "encoding-quality-image-search",
        "40",
    },
    {
        "encoding-quality-region-search",
        "40",
    },
    {
        "use-jpeg-for-image-search",
        "true",
    },
    {
        "use-webp-for-image-search",
        "false",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_259[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_248[] = {
    "LensImageFormatOptimizations",
    "LensStandalone",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_98[] = {
    {
        "encoding-quality-image-search",
        "90",
    },
    {
        "encoding-quality-region-search",
        "90",
    },
    {
        "lens-homepage-url",
        "https://lens.google.com/v3/",
    },
    {
        "lens-html-redirect-fix",
        "false",
    },
    {
        "use-jpeg-for-image-search",
        "true",
    },
    {
        "use-webp-for-image-search",
        "false",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_258[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_247[] = {
    "LensImageFormatOptimizations",
    "LensStandalone",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_97[] = {
    {
        "dismiss-loading-state-on-document-on-load-completed-in-primary-main-frame",
        "false",
    },
    {
        "dismiss-loading-state-on-navigation-entry-committed",
        "true",
    },
    {
        "encoding-quality-image-search",
        "40",
    },
    {
        "encoding-quality-region-search",
        "40",
    },
    {
        "lens-homepage-url",
        "https://lens.google.com/v3/",
    },
    {
        "lens-html-redirect-fix",
        "false",
    },
    {
        "use-jpeg-for-image-search",
        "true",
    },
    {
        "use-webp-for-image-search",
        "false",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_257[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_246[] = {
    "LensImageFormatOptimizations",
    "LensStandalone",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_96[] = {
    {
        "encoding-quality-image-search",
        "90",
    },
    {
        "encoding-quality-region-search",
        "90",
    },
    {
        "lens-homepage-url",
        "https://lens.google.com/v3/",
    },
    {
        "lens-html-redirect-fix",
        "false",
    },
    {
        "use-jpeg-for-image-search",
        "false",
    },
    {
        "use-webp-for-image-search",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_256[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_245[] = {
    "LensImageFormatOptimizations",
    "LensStandalone",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_95[] = {
    {
        "dismiss-loading-state-on-document-on-load-completed-in-primary-main-frame",
        "false",
    },
    {
        "dismiss-loading-state-on-navigation-entry-committed",
        "true",
    },
    {
        "encoding-quality-image-search",
        "45",
    },
    {
        "encoding-quality-region-search",
        "45",
    },
    {
        "lens-homepage-url",
        "https://lens.google.com/v3/",
    },
    {
        "lens-html-redirect-fix",
        "false",
    },
    {
        "use-jpeg-for-image-search",
        "false",
    },
    {
        "use-webp-for-image-search",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_255[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_233[] = {
    {
        "WebpQualityBackendV6",
        array_kFieldTrialConfig_platforms_255,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_95,
        array_kFieldTrialConfig_enable_features_245,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "WebpBackendOnlyV6",
        array_kFieldTrialConfig_platforms_256,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_96,
        array_kFieldTrialConfig_enable_features_246,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "JpegQualityBackendV6",
        array_kFieldTrialConfig_platforms_257,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_97,
        array_kFieldTrialConfig_enable_features_247,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "JpegBackendOnlyV6",
        array_kFieldTrialConfig_platforms_258,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_98,
        array_kFieldTrialConfig_enable_features_248,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "JpegQualityOnlyV6",
        array_kFieldTrialConfig_platforms_259,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_99,
        array_kFieldTrialConfig_enable_features_249,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_244[] = {
    "LensEnableImageTranslate",
};
const Study::Platform array_kFieldTrialConfig_platforms_254[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_232[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_254,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_244,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_243[] = {
    "GlobalMediaControlsUpdatedUI",
};
const Study::Platform array_kFieldTrialConfig_platforms_253[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_231[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_253,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_243,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_242[] = {
    "GenGpuDiskCacheKeyPrefixInGpuService",
};
const Study::Platform array_kFieldTrialConfig_platforms_252[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_230[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_252,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_242,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_241[] = {
    "CPUMeasurementInFreezingPolicy",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_94[] = {
    {
        "freezing_high_cpu_proportion",
        "0.05",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_251[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_229[] = {
    {
        "LowCPUThreshold",
        array_kFieldTrialConfig_platforms_251,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_94,
        array_kFieldTrialConfig_enable_features_241,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_240[] = {
    "FreezingOnBatterySaver",
};
const Study::Platform array_kFieldTrialConfig_platforms_250[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_228[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_250,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_240,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_239[] = {
    "FrameRoutingCache",
};
const Study::Platform array_kFieldTrialConfig_platforms_249[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_227[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_249,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_239,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_238[] = {
    "FormControlsVerticalWritingModeDirectionSupport",
};
const Study::Platform array_kFieldTrialConfig_platforms_248[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_226[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_248,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_238,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_237[] = {
    "FontationsFontBackend",
};
const Study::Platform array_kFieldTrialConfig_platforms_247[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_225[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_247,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_237,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_236[] = {
    "FlushPersistentSystemProfileOnWrite",
};
const Study::Platform array_kFieldTrialConfig_platforms_246[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_224[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_246,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_236,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_18[] = {
    "FingerprintingProtectionSetting",
    "FingerprintingProtectionUx",
};
const char* const array_kFieldTrialConfig_enable_features_235[] = {
    "EnableFingerprintingProtectionFilter",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_93[] = {
    {
        "activation_level",
        "dry_run",
    },
    {
        "enable_only_if_3pc_blocked",
        "false",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_245[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_17[] = {
    "FingerprintingProtectionSetting",
    "FingerprintingProtectionUx",
};
const char* const array_kFieldTrialConfig_enable_features_234[] = {
    "EnableFingerprintingProtectionFilter",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_92[] = {
    {
        "activation_level",
        "dry_run",
    },
    {
        "enable_only_if_3pc_blocked",
        "false",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_244[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_223[] = {
    {
        "Enabled_DryRun_20240729_Dogfood",
        array_kFieldTrialConfig_platforms_244,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_92,
        array_kFieldTrialConfig_enable_features_234,
        array_kFieldTrialConfig_disable_features_17,
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_245,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_93,
        array_kFieldTrialConfig_enable_features_235,
        array_kFieldTrialConfig_disable_features_18,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_233[] = {
    "ServiceWorkerFetchResponseCallbackUseHighPriority",
    "ServiceWorkerMergeFindRegistrationForClientUrl",
    "ServiceWorkerRegistrationCache",
    "ServiceWorkerScopeCache",
    "ServiceWorkerStorageControlResponseUseHighPriority",
};
const Study::Platform array_kFieldTrialConfig_platforms_243[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_222[] = {
    {
        "EnableAll_20231004",
        array_kFieldTrialConfig_platforms_243,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_233,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_232[] = {
    "FetchLaterAPI",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_91[] = {
    {
        "send_on_enter_bfcache",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_242[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_221[] = {
    {
        "Enabled_20240112",
        array_kFieldTrialConfig_platforms_242,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_91,
        array_kFieldTrialConfig_enable_features_232,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_231[] = {
    "LCPPAutoPreconnectLcpOrigin",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_90[] = {
    {
        "lcpp_preconnect_frequency_threshold",
        "0.5",
    },
    {
        "lcpp_preconnect_max_origins",
        "1",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_241[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_220[] = {
    {
        "EnabledWithOne_20240214",
        array_kFieldTrialConfig_platforms_241,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_90,
        array_kFieldTrialConfig_enable_features_231,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_230[] = {
    "FencedFramesSrcPermissionsPolicy",
};
const Study::Platform array_kFieldTrialConfig_platforms_240[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_219[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_240,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_230,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_229[] = {
    "FencedFramesReportEventHeaderChanges",
};
const Study::Platform array_kFieldTrialConfig_platforms_239[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_218[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_239,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_229,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_228[] = {
    "FencedFramesAutomaticBeaconCredentials",
};
const Study::Platform array_kFieldTrialConfig_platforms_238[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_217[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_238,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_228,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_227[] = {
    "FledgeBiddingAndAuctionServer",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_89[] = {
    {
        "FledgeBiddingAndAuctionKeyConfig",
        "{\"https://publickeyservice.gcp.privacysandboxservices.com\": "
        "\"https://publickeyservice.pa.gcp.privacysandboxservices.com/.well-known/protected-auction/v1/public-keys\", "
        "\"https://publickeyservice.pa.gcp.privacysandboxservices.com\": "
        "\"https://publickeyservice.pa.gcp.privacysandboxservices.com/.well-known/protected-auction/v1/public-keys\", "
        "\"https://publickeyservice.pa.aws.privacysandboxservices.com\": "
        "\"https://publickeyservice.pa.aws.privacysandboxservices.com/.well-known/protected-auction/v1/public-keys\"}",
    },
    {
        "FledgeBiddingAndAuctionKeyURL",
        "https://publickeyservice.pa.gcp.privacysandboxservices.com/.well-known/protected-auction/v1/public-keys",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_237[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_216[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_237,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_89,
        array_kFieldTrialConfig_enable_features_227,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_226[] = {
    "ExtremeLightweightUAFDetector",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_88[] = {
    {
        "object_size_threshold_in_bytes",
        "512",
    },
    {
        "quarantine_capacity_for_large_objects_in_bytes",
        "0",
    },
    {
        "quarantine_capacity_for_small_objects_in_bytes",
        "1048576",
    },
    {
        "sampling_frequency",
        "100",
    },
    {
        "target_processes",
        "browser_only",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_236[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_215[] = {
    {
        "Quarantine_900_100_512_v6",
        array_kFieldTrialConfig_platforms_236,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_88,
        array_kFieldTrialConfig_enable_features_226,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_225[] = {
    "ExternalBeginFrameSourceWinUsesRunOrPostTask",
};
const Study::Platform array_kFieldTrialConfig_platforms_235[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_214[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_235,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_225,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_224[] = {
    "ExtensionsServiceWorkerOptimizedEventDispatch",
};
const Study::Platform array_kFieldTrialConfig_platforms_234[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_213[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_234,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_224,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_223[] = {
    "ExtensionManifestV2Disabled",
};
const Study::Platform array_kFieldTrialConfig_platforms_233[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_212[] = {
    {
        "Enabled_DisableMV2Extensions",
        array_kFieldTrialConfig_platforms_233,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_223,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_222[] = {
    "ExtendedReportingRemovePrefDependency",
    "SafeBrowsingHashPrefixRealTimeLookupsSamplePing",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_87[] = {
    {
        "HashPrefixRealTimeLookupsSampleRate",
        "50",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_232[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_16[] = {
    "SafeBrowsingHashPrefixRealTimeLookupsSamplePing",
};
const char* const array_kFieldTrialConfig_enable_features_221[] = {
    "ExtendedReportingRemovePrefDependency",
};
const Study::Platform array_kFieldTrialConfig_platforms_231[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_211[] = {
    {
        "EnabledRemovePrefDependency",
        array_kFieldTrialConfig_platforms_231,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_221,
        array_kFieldTrialConfig_disable_features_16,
        nullptr,
        {},
        {},
        {},
    },
    {
        "EnabledRemovePrefDependencyAndHprtSamplePing",
        array_kFieldTrialConfig_platforms_232,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_87,
        array_kFieldTrialConfig_enable_features_222,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_220[] = {
    "ExpandCompositedCullRect",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_86[] = {
    {
        "dpr_coef",
        "1",
    },
    {
        "small_scroller_opt",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_230[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_210[] = {
    {
        "ExpandCompositedCullRect",
        array_kFieldTrialConfig_platforms_230,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_86,
        array_kFieldTrialConfig_enable_features_220,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_219[] = {
    "EvictionThrottlesDraw",
};
const Study::Platform array_kFieldTrialConfig_platforms_229[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_209[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_229,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_219,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_218[] = {
    "EventTimingSelectionAutoScrollNoInteractionId",
};
const Study::Platform array_kFieldTrialConfig_platforms_228[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_208[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_228,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_218,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_217[] = {
    "EscapeLtGtInAttributes",
};
const Study::Platform array_kFieldTrialConfig_platforms_227[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_207[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_227,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_217,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_216[] = {
    "EsbAiStringUpdate",
};
const Study::Platform array_kFieldTrialConfig_platforms_226[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_206[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_226,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_216,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_215[] = {
    "EnterprisePasswordReuseUiRefresh",
};
const Study::Platform array_kFieldTrialConfig_platforms_225[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_205[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_225,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_215,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_214[] = {
    "EnableTcpPortRandomization",
};
const Study::Platform array_kFieldTrialConfig_platforms_224[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_204[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_224,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_214,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_213[] = {
    "ShoppingPDPMetrics",
};
const Study::Platform array_kFieldTrialConfig_platforms_223[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_203[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_223,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_213,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_212[] = {
    "EnableOverwritingPlaceholderUsernames",
};
const Study::Platform array_kFieldTrialConfig_platforms_222[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_202[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_222,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_212,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_211[] = {
    "AckOnSurfaceActivationWhenInteractive",
    "DrawImmediatelyWhenInteractive",
};
const Study::Platform array_kFieldTrialConfig_platforms_221[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_201[] = {
    {
        "EnabledV4",
        array_kFieldTrialConfig_platforms_221,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_211,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_210[] = {
    "EnableFallbackFontsCrashReporting",
};
const Study::Platform array_kFieldTrialConfig_platforms_220[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_200[] = {
    {
        "Enabled_20230404",
        array_kFieldTrialConfig_platforms_220,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_210,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_209[] = {
    "EnableDiscountInfoApi",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_85[] = {
    {
        "discount-on-shoppy-page",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_219[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_199[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_219,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_85,
        array_kFieldTrialConfig_enable_features_209,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_208[] = {
    "EnableConfigurableThreadCacheMultiplier",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_84[] = {
    {
        "ThreadCacheMultiplier",
        "2",
    },
    {
        "ThreadCacheMultiplierForAndroid",
        "1",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_218[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_198[] = {
    {
        "multiplier_2.0_20230904",
        array_kFieldTrialConfig_platforms_218,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_84,
        array_kFieldTrialConfig_enable_features_208,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_207[] = {
    "EnableCertManagementUIV2Write",
};
const Study::Platform array_kFieldTrialConfig_platforms_217[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_197[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_217,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_207,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_206[] = {
    "EnableBackForwardCacheForOngoingSubframeNavigation",
};
const Study::Platform array_kFieldTrialConfig_platforms_216[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_196[] = {
    {
        "Enabled_20240305",
        array_kFieldTrialConfig_platforms_216,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_206,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_15[] = {
    "ElementGetInnerHTML",
};
const Study::Platform array_kFieldTrialConfig_platforms_215[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_195[] = {
    {
        "Disabled",
        array_kFieldTrialConfig_platforms_215,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_15,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_205[] = {
    "PrefetchUseContentRefactor",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_83[] = {
    {
        "block_until_head_timeout_eager_prefetch",
        "500",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_214[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_194[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_214,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_83,
        array_kFieldTrialConfig_enable_features_205,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_204[] = {
    "DownloadWarningSurvey",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_82[] = {
    {
        "en_site_id",
        "ToBgFcctL0ugnJ3q1cK0UoPbrdFt",
    },
    {
        "probability",
        "0.5",
    },
    {
        "survey_type",
        "5",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_213[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_203[] = {
    "DownloadWarningSurvey",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_81[] = {
    {
        "en_site_id",
        "P1UCDjb5L0ugnJ3q1cK0S1YhAs9h",
    },
    {
        "probability",
        "1.0",
    },
    {
        "survey_type",
        "4",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_212[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_202[] = {
    "DownloadWarningSurvey",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_80[] = {
    {
        "en_site_id",
        "B4TxfW2d50ugnJ3q1cK0SrBjxPp9",
    },
    {
        "probability",
        "1.0",
    },
    {
        "survey_type",
        "3",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_211[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_201[] = {
    "DownloadWarningSurvey",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_79[] = {
    {
        "en_site_id",
        "QGZEf3nUW0ugnJ3q1cK0PoGTrYqX",
    },
    {
        "ignore_delay_seconds",
        "300",
    },
    {
        "probability",
        "0.5",
    },
    {
        "survey_type",
        "2",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_210[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_200[] = {
    "DownloadWarningSurvey",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_78[] = {
    {
        "en_site_id",
        "jhF4CtEp50ugnJ3q1cK0UZhzeE9d",
    },
    {
        "probability",
        "1.0",
    },
    {
        "survey_type",
        "1",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_209[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_199[] = {
    "DownloadWarningSurvey",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_77[] = {
    {
        "en_site_id",
        "ikozJtokP0ugnJ3q1cK0SbwHjMKE",
    },
    {
        "probability",
        "1.0",
    },
    {
        "survey_type",
        "0",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_208[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_193[] = {
    {
        "DownloadBubbleBypass_20240513",
        array_kFieldTrialConfig_platforms_208,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_77,
        array_kFieldTrialConfig_enable_features_199,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "DownloadBubbleHeed_20240513",
        array_kFieldTrialConfig_platforms_209,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_78,
        array_kFieldTrialConfig_enable_features_200,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "DownloadBubbleIgnore_20240513",
        array_kFieldTrialConfig_platforms_210,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_79,
        array_kFieldTrialConfig_enable_features_201,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "DownloadsPageBypass_20240513",
        array_kFieldTrialConfig_platforms_211,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_80,
        array_kFieldTrialConfig_enable_features_202,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "DownloadsPageHeed_20240513",
        array_kFieldTrialConfig_platforms_212,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_81,
        array_kFieldTrialConfig_enable_features_203,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "DownloadsPageIgnore_20240513",
        array_kFieldTrialConfig_platforms_213,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_82,
        array_kFieldTrialConfig_enable_features_204,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_198[] = {
    "DontAlwaysPushPictureLayerImpls",
};
const Study::Platform array_kFieldTrialConfig_platforms_207[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_192[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_207,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_198,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_197[] = {
    "DoNotEvictOnAXLocationChange",
};
const Study::Platform array_kFieldTrialConfig_platforms_206[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_191[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_206,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_197,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_196[] = {
    "UseDnsHttpsSvcb",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_76[] = {
    {
        "UseDnsHttpsSvcbInsecureExtraTimeMax",
        "500ms",
    },
    {
        "UseDnsHttpsSvcbInsecureExtraTimeMin",
        "300ms",
    },
    {
        "UseDnsHttpsSvcbInsecureExtraTimePercent",
        "50",
    },
    {
        "UseDnsHttpsSvcbSecureExtraTimeMax",
        "500ms",
    },
    {
        "UseDnsHttpsSvcbSecureExtraTimeMin",
        "300ms",
    },
    {
        "UseDnsHttpsSvcbSecureExtraTimePercent",
        "50",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_205[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_190[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_205,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_76,
        array_kFieldTrialConfig_enable_features_196,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_195[] = {
    "DlpRegionalizedEndpoints",
};
const Study::Platform array_kFieldTrialConfig_platforms_204[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_189[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_204,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_195,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_194[] = {
    "DiskCacheBackendExperiment",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_75[] = {
    {
        "backend",
        "blockfile",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_203[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_193[] = {
    "DiskCacheBackendExperiment",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_74[] = {
    {
        "backend",
        "simple",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_202[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_188[] = {
    {
        "Simple",
        array_kFieldTrialConfig_platforms_202,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_74,
        array_kFieldTrialConfig_enable_features_193,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Blockfile",
        array_kFieldTrialConfig_platforms_203,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_75,
        array_kFieldTrialConfig_enable_features_194,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_192[] = {
    "DiscountConsentV2",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_73[] = {
    {
        "discount-consent-ntp-variation",
        "4",
    },
    {
        "step-one-static-content",
        "Let Google help you find discounts for your carts",
    },
    {
        "step-one-use-static-content",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_201[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_187[] = {
    {
        "enabled_ntp_native_dialog_with_approved_strings_M104_20220809",
        array_kFieldTrialConfig_platforms_201,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_73,
        array_kFieldTrialConfig_enable_features_192,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_191[] = {
    "DiscountDialogAutoPopupBehaviorSetting",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_72[] = {
    {
        "history-cluster-behavior",
        "1",
    },
    {
        "merchant-wide-behavior",
        "2",
    },
    {
        "non-merchant-wide-behavior",
        "0",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_200[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_186[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_200,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_72,
        array_kFieldTrialConfig_enable_features_191,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_190[] = {
    "DiscardInputEventsToRecentlyMovedFrames",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_71[] = {
    {
        "distance_factor",
        ".5",
    },
    {
        "time_ms",
        "250",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_199[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_189[] = {
    "DiscardInputEventsToRecentlyMovedFrames",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_70[] = {
    {
        "distance_factor",
        "100000.",
    },
    {
        "time_ms",
        "0",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_198[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_185[] = {
    {
        "DoNotDiscard",
        array_kFieldTrialConfig_platforms_198,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_70,
        array_kFieldTrialConfig_enable_features_189,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "50_250_ms",
        array_kFieldTrialConfig_platforms_199,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_71,
        array_kFieldTrialConfig_enable_features_190,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_188[] = {
    "DiscardFrozenBrowsingInstancesWithGrowingPMF",
};
const Study::Platform array_kFieldTrialConfig_platforms_197[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_184[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_197,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_188,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_187[] = {
    "DisallowManagedProfileSignout",
};
const Study::Platform array_kFieldTrialConfig_platforms_196[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_183[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_196,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_187,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_14[] = {
    "UrgentPageDiscarding",
};
const Study::Platform array_kFieldTrialConfig_platforms_195[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_182[] = {
    {
        "Disabled",
        array_kFieldTrialConfig_platforms_195,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_14,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_13[] = {
    "UseGles2ForOopR",
};
const Study::Platform array_kFieldTrialConfig_platforms_194[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_181[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_194,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_13,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_186[] = {
    "DipsOnForegroundSequence",
};
const Study::Platform array_kFieldTrialConfig_platforms_193[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_180[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_193,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_186,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_185[] = {
    "DevToolsExplainThisResourceDogfood",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_69[] = {
    {
        "aida_model_id",
        "codey_gemit_mpp_streaming",
    },
    {
        "aida_temperature",
        "0",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_192[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_179[] = {
    {
        "Enabled_Dogfood",
        array_kFieldTrialConfig_platforms_192,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_69,
        array_kFieldTrialConfig_enable_features_185,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_184[] = {
    "DevToolsAiAssistancePerformanceAgentDogfood",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_68[] = {
    {
        "aida_model_id",
        "codey_gemit_mpp_streaming",
    },
    {
        "aida_temperature",
        "0",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_191[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_178[] = {
    {
        "Enabled_Dogfood",
        array_kFieldTrialConfig_platforms_191,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_68,
        array_kFieldTrialConfig_enable_features_184,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_183[] = {
    "DevToolsAiAssistanceFileAgentDogfood",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_67[] = {
    {
        "aida_model_id",
        "codey_gemit_mpp_streaming",
    },
    {
        "aida_temperature",
        "0",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_190[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_177[] = {
    {
        "Enabled_Dogfood",
        array_kFieldTrialConfig_platforms_190,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_67,
        array_kFieldTrialConfig_enable_features_183,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_182[] = {
    "DetailsStyling",
};
const Study::Platform array_kFieldTrialConfig_platforms_189[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_176[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_189,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_182,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_181[] = {
    "DestroySystemProfiles",
};
const Study::Platform array_kFieldTrialConfig_platforms_188[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_175[] = {
    {
        "DestroySystemProfiles",
        array_kFieldTrialConfig_platforms_188,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_181,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_180[] = {
    "WebAppUniversalInstall",
};
const Study::Platform array_kFieldTrialConfig_platforms_187[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_174[] = {
    {
        "WebAppUniversalInstallExperiment",
        array_kFieldTrialConfig_platforms_187,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_180,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_179[] = {
    "AllowRecentSessionTracking",
    "IPH_DesktopReEngagement",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_66[] = {
    {
        "max_active_days",
        "0",
    },
    {
        "max_active_weeks",
        "0",
    },
    {
        "max_monthly_active_days",
        "2",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_186[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_173[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_186,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_66,
        array_kFieldTrialConfig_enable_features_179,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_12[] = {
    "WebAppsEnableMLModelForPromotion",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_65[] = {
    {
        "guardrail_report_prob",
        "0.5",
    },
    {
        "max_days_to_store_guardrails",
        "180",
    },
    {
        "model_and_user_decline_report_prob",
        "0.5",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_185[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_172[] = {
    {
        "Disabled",
        array_kFieldTrialConfig_platforms_185,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_65,
        {},
        array_kFieldTrialConfig_disable_features_12,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_178[] = {
    "OmniboxDomainSuggestions",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_64[] = {
    {
        "DomainSuggestionsAlternativeScoring",
        "true",
    },
    {
        "DomainSuggestionsMaxMatchesPerDomain",
        "2",
    },
    {
        "DomainSuggestionsMinInputLength",
        "4",
    },
    {
        "DomainSuggestionsScoreFactor",
        "1",
    },
    {
        "DomainSuggestionsTypedUrlsOffset",
        "1",
    },
    {
        "DomainSuggestionsTypedUrlsThreshold",
        "7",
    },
    {
        "DomainSuggestionsTypedVisitCapPerVisit",
        "2",
    },
    {
        "DomainSuggestionsTypedVisitOffset",
        "1",
    },
    {
        "DomainSuggestionsTypedVisitThreshold",
        "4",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_184[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_171[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_184,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_64,
        array_kFieldTrialConfig_enable_features_178,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_177[] = {
    "StarterPackExpansion",
};
const Study::Platform array_kFieldTrialConfig_platforms_183[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_170[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_183,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_177,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_176[] = {
    "JourneysOmniboxHistoryClusterProvider",
    "OmniboxShortcutBoost",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_63[] = {
    {
        "ShortcutBoostGroupWithSearches",
        "true",
    },
    {
        "ShortcutBoostNonTopHitSearchThreshold",
        "2",
    },
    {
        "ShortcutBoostNonTopHitThreshold",
        "2",
    },
    {
        "ShortcutBoostSearchScore",
        "1414",
    },
    {
        "ShortcutBoostUrlScore",
        "1414",
    },
    {
        "omnibox_history_cluster_provider_inherit_search_match_score",
        "true",
    },
    {
        "omnibox_history_cluster_provider_score",
        "1414",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_182[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_169[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_182,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_63,
        array_kFieldTrialConfig_enable_features_176,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_175[] = {
    "OmniboxVitalizeAutocompletedKeywords",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_62[] = {
    {
        "VitalizeAutocompletedKeywordsScore",
        "900",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_181[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_168[] = {
    {
        "enabled",
        array_kFieldTrialConfig_platforms_181,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_62,
        array_kFieldTrialConfig_enable_features_175,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_174[] = {
    "OmniboxCalcProvider",
};
const Study::Platform array_kFieldTrialConfig_platforms_180[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_167[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_180,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_174,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_173[] = {
    "NtpMostRelevantTabResumptionModule",
    "SegmentationPlatformURLVisitResumptionRanker",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_61[] = {
    {
        "use_random_score",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_179[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_166[] = {
    {
        "TabResumption_Random",
        array_kFieldTrialConfig_platforms_179,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_61,
        array_kFieldTrialConfig_enable_features_173,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_11[] = {
    "NtpShoppingTasksModule",
};
const char* const array_kFieldTrialConfig_enable_features_172[] = {
    "NtpModulesLoadTimeoutMilliseconds",
    "NtpPhotosModule",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_60[] = {
    {
        "NtpModulesLoadTimeoutMillisecondsParam",
        "3000",
    },
    {
        "use_sapi_v2",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_178[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_165[] = {
    {
        "RecipeTasksRuleBasedDiscountDriveManagedUsersCartOptimizeRecipeTasksSAPIV2Fre_Enabled",
        array_kFieldTrialConfig_platforms_178,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_60,
        array_kFieldTrialConfig_enable_features_172,
        array_kFieldTrialConfig_disable_features_11,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_171[] = {
    "NtpMobilePromo",
};
const Study::Platform array_kFieldTrialConfig_platforms_177[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_164[] = {
    {
        "Enabled_20241101",
        array_kFieldTrialConfig_platforms_177,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_171,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_170[] = {
    "NtpMiddleSlotPromoDismissal",
};
const Study::Platform array_kFieldTrialConfig_platforms_176[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_163[] = {
    {
        "MiddleSlotPromoDismissal",
        array_kFieldTrialConfig_platforms_176,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_170,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_169[] = {
    "NtpBackgroundImageErrorDetection",
};
const Study::Platform array_kFieldTrialConfig_platforms_175[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_162[] = {
    {
        "ImageErrorDetection",
        array_kFieldTrialConfig_platforms_175,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_169,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_168[] = {
    "NtpDriveModule",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_59[] = {
    {
        "NtpDriveModuleCacheMaxAgeSParam",
        "60",
    },
    {
        "NtpDriveModuleExperimentGroupParam",
        "experiment_1234",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_174[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_161[] = {
    {
        "Cache_1m",
        array_kFieldTrialConfig_platforms_174,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_59,
        array_kFieldTrialConfig_enable_features_168,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_167[] = {
    "DeprecateUnload",
    "DeprecateUnloadByAllowList",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_58[] = {
    {
        "allowlist",
        "a.com,b.com,c.com,d.com,e.com,f.com,web-platform.test,www1.web-platform.test,127.0.0.1,example.test,www.google.com,www.youtube.com,www.facebook.com,"
        "www.pornhub.com,www.xvideos.com,twitter.com,www.wikipedia.org,www.instagram.com,www.reddit.com,www.amazon.com,duckduckgo.com,www.yahoo.com,www.xnxx."
        "com,www.tiktok.com,www.bing.com,www.yahoo.co.jp,weather.com,www.whatsapp.com,dzen.ru,xhamster.com,openai.com,outlook.live.com,www.microsoft.com,"
        "microsoftonline.com,www.microsoftonline.com,www.linkedin.com,www.quora.com,www.twitch.tv,www.naver.com,netflix.com,www.netflix.com,www.office.com,vk."
        "com,www.vk.com,www.globo.com,www.aliexpress.com,www.cnn.com,zoom.us,www.zoom.us,www.imdb.com,x.com,www.nytimes.com,onlyfans.com,www.espn.com,www."
        "amazon.co.jp,www.pinterest.com,www.uol.com.br,www.ebay.com,www.marca.com,www.canva.com,www.spotify.com,www.bbc.com,www.paypal.com,www.apple.com",
    },
    {
        "rollout_bucket",
        "10",
    },
    {
        "rollout_percent",
        "100",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_173[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_160[] = {
    {
        "Enabled_20240124",
        array_kFieldTrialConfig_platforms_173,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_58,
        array_kFieldTrialConfig_enable_features_167,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_166[] = {
    "DelegatedCompositing",
};
const Study::Platform array_kFieldTrialConfig_platforms_172[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_159[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_172,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_166,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_165[] = {
    "DelayablePriorityThresholdFeature",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_57[] = {
    {
        "DelayablePriorityThreshold",
        "medium",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_171[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_158[] = {
    {
        "Medium_20230906",
        array_kFieldTrialConfig_platforms_171,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_57,
        array_kFieldTrialConfig_enable_features_165,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_164[] = {
    "DeferredSpareRendererForTopChromeWebUI",
};
const Study::Platform array_kFieldTrialConfig_platforms_170[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_157[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_170,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_164,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_163[] = {
    "DeferSpeculativeRFHCreation",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_56[] = {
    {
        "create_speculative_rfh_delay_ms",
        "1",
    },
    {
        "create_speculative_rfh_filter_restore",
        "true",
    },
    {
        "warmup_spare_process",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_169[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_156[] = {
    {
        "EnabledWithPrewarmAndDelay",
        array_kFieldTrialConfig_platforms_169,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_56,
        array_kFieldTrialConfig_enable_features_163,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_162[] = {
    "DeferRendererTasksAfterInput",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_55[] = {
    {
        "policy",
        "all-deferrable-types",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_168[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_155[] = {
    {
        "Enabled_AllDeferrableTypes",
        array_kFieldTrialConfig_platforms_168,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_55,
        array_kFieldTrialConfig_enable_features_162,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_161[] = {
    "DefaultOpenSSLBufferSizeFeature",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_54[] = {
    {
        "DefaultOpenSSLBufferSize",
        "17408",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_167[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_154[] = {
    {
        "ssl_buffer_size_17K_20230920",
        array_kFieldTrialConfig_platforms_167,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_54,
        array_kFieldTrialConfig_enable_features_161,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_160[] = {
    "DefaultGpuDiskCacheSize",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_53[] = {
    {
        "GpuDefaultMaxProgramCacheMemoryBytes",
        "6291456",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_166[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_153[] = {
    {
        "max_cache_6M_20230913",
        array_kFieldTrialConfig_platforms_166,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_53,
        array_kFieldTrialConfig_enable_features_160,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_159[] = {
    "DedicatedMediaServiceThread",
};
const Study::Platform array_kFieldTrialConfig_platforms_165[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_152[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_165,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_159,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_158[] = {
    "DecommitPooledPages",
};
const Study::Platform array_kFieldTrialConfig_platforms_164[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_151[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_164,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_158,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_157[] = {
    "ImageDecodeConfigurableFeature",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_52[] = {
    {
        "DecodedImageWorkingSetBudgetBytesForAboveThreshold",
        "268435456",
    },
    {
        "DefaultDecodedImageWorkingSetBudgetBytes",
        "134217728",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_163[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_150[] = {
    {
        "budget_default_128M_256M_20230921",
        array_kFieldTrialConfig_platforms_163,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_52,
        array_kFieldTrialConfig_enable_features_157,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_156[] = {
    "EnableBoundSessionCredentials",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_51[] = {
    {
        "dice-support",
        "enabled",
    },
    {
        "exclusive-registration-path",
        "",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_162[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_149[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_162,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_51,
        array_kFieldTrialConfig_enable_features_156,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_155[] = {
    "ApiEnterpriseReportingPrivateReportDataMaskingEvent",
};
const Study::Platform array_kFieldTrialConfig_platforms_161[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_148[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_161,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_155,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_154[] = {
    "EnableScreenshotProtection",
};
const Study::Platform array_kFieldTrialConfig_platforms_160[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_147[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_160,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_154,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_153[] = {
    "DXGIWaitableSwapChain",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_50[] = {
    {
        "DXGIWaitableSwapChainMaxQueuedFrames",
        "2",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_159[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_146[] = {
    {
        "Enabled_MaxQueuedFrames2_20230203",
        array_kFieldTrialConfig_platforms_159,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_50,
        array_kFieldTrialConfig_enable_features_153,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_152[] = {
    "CoalesceStorageAreaCommits",
};
const Study::Platform array_kFieldTrialConfig_platforms_158[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_145[] = {
    {
        "Enabled_20240904",
        array_kFieldTrialConfig_platforms_158,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_152,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_10[] = {
    "DOMParserIncludeShadowRoots",
};
const Study::Platform array_kFieldTrialConfig_platforms_157[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_144[] = {
    {
        "Disabled",
        array_kFieldTrialConfig_platforms_157,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_10,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_151[] = {
    "DIPS",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_49[] = {
    {
        "triggering_action",
        "bounce",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_156[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_143[] = {
    {
        "AnyBounceTrigger",
        array_kFieldTrialConfig_platforms_156,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_49,
        array_kFieldTrialConfig_enable_features_151,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_150[] = {
    "D3D11Vp9kSVCHWDecoding",
};
const Study::Platform array_kFieldTrialConfig_platforms_155[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_142[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_155,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_150,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_149[] = {
    "CustomizeChromeSidePanelExtensionsCard",
};
const Study::Platform array_kFieldTrialConfig_platforms_154[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_141[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_154,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_149,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_148[] = {
    "CookieSameSiteConsidersRedirectChain",
};
const Study::Platform array_kFieldTrialConfig_platforms_153[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_140[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_153,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_148,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_147[] = {
    "FledgeFacilitatedTestingSignalsHeaders",
};
const Study::Platform array_kFieldTrialConfig_platforms_152[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_139[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_152,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_147,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_146[] = {
    "AttributionDebugReportingCookieDeprecationTesting",
    "CookieDeprecationFacilitatedTesting",
    "SkipTpcdMitigationsForAds",
    "TPCDAdHeuristicSubframeRequestTagging",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_48[] = {
    {
        "SkipTpcdMitigationsForAdsHeuristics",
        "true",
    },
    {
        "SkipTpcdMitigationsForAdsMetadata",
        "true",
    },
    {
        "SkipTpcdMitigationsForAdsSupport",
        "true",
    },
    {
        "decision_delay_time",
        "1s",
    },
    {
        "disable_3p_cookies",
        "true",
    },
    {
        "disable_ads_apis",
        "false",
    },
    {
        "enable_otr_profiles",
        "false",
    },
    {
        "enable_silent_onboarding",
        "false",
    },
    {
        "label",
        "prestable_treatment_1",
    },
    {
        "need_onboarding_for_label",
        "true",
    },
    {
        "need_onboarding_for_synthetic_trial",
        "true",
    },
    {
        "use_profile_filtering",
        "false",
    },
    {
        "version",
        "2",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_151[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_138[] = {
    {
        "Treatment_PreStable_20231002",
        array_kFieldTrialConfig_platforms_151,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_48,
        array_kFieldTrialConfig_enable_features_146,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_145[] = {
    "LensOverlayContextualSearchbox",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_47[] = {
    {
        "file-upload-limit-bytes",
        "200000000",
    },
    {
        "use-pdfs-as-context",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_150[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_137[] = {
    {
        "Enabled_Teamfood",
        array_kFieldTrialConfig_platforms_150,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_47,
        array_kFieldTrialConfig_enable_features_145,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_144[] = {
    "ConfigurableV8CodeCacheHotHours",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_46[] = {
    {
        "V8CodeCacheHotHours",
        "72",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_149[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_136[] = {
    {
        "cache_72h_20230904",
        array_kFieldTrialConfig_platforms_149,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_46,
        array_kFieldTrialConfig_enable_features_144,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_143[] = {
    "ConditionalImageResize",
};
const Study::Platform array_kFieldTrialConfig_platforms_148[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_135[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_148,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_143,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_142[] = {
    "ConcurrentViewTransitionsSPA",
};
const Study::Platform array_kFieldTrialConfig_platforms_147[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_134[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_147,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_142,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_9[] = {
    "CompressionDictionaryTransportRequireKnownRootCert",
};
const Study::Platform array_kFieldTrialConfig_platforms_146[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_133[] = {
    {
        "Disable",
        array_kFieldTrialConfig_platforms_146,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_9,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_8[] = {
    "AutocompleteDictionaryPreload",
    "PreloadedDictionaryConditionalUse",
};
const Study::Platform array_kFieldTrialConfig_platforms_145[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_132[] = {
    {
        "EnabledPreloadConditionalUse",
        array_kFieldTrialConfig_platforms_145,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_8,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_141[] = {
    "CompositeClipPathAnimation",
};
const Study::Platform array_kFieldTrialConfig_platforms_144[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_131[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_144,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_141,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_140[] = {
    "CompositeBGColorAnimation",
    "DeferImplInvalidation",
};
const Study::Platform array_kFieldTrialConfig_platforms_143[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_130[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_143,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_140,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_139[] = {
    "ComposeUpfrontInputModes",
};
const Study::Platform array_kFieldTrialConfig_platforms_142[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_129[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_142,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_139,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_138[] = {
    "AutofillCaretExtraction",
    "ComposeProactiveNudge",
    "EnableComposeNudgeAtCursor",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_45[] = {
    {
        "proactive_nudge_compact_ui",
        "true",
    },
    {
        "proactive_nudge_delay_milliseconds",
        "1000",
    },
    {
        "proactive_nudge_force_show_probability",
        "0.04",
    },
    {
        "proactive_nudge_show_probability",
        "0.02",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_141[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_128[] = {
    {
        "Enabled_CursorNudgeModel",
        array_kFieldTrialConfig_platforms_141,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_45,
        array_kFieldTrialConfig_enable_features_138,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_137[] = {
    "OptimizationGuideComposeOnDeviceEval",
    "OptimizationGuideOnDeviceModel",
    "TextSafetyClassifier",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_44[] = {
    {
        "on_device_retract_unsafe_content",
        "false",
    },
    {
        "on_device_text_safety_token_interval",
        "10",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_140[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_127[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_140,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_44,
        array_kFieldTrialConfig_enable_features_137,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_136[] = {
    "ModelQualityLogging",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_43[] = {
    {
        "model_execution_feature_compose",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_139[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_126[] = {
    {
        "ComposeLoggingEnabled_Dogfood",
        array_kFieldTrialConfig_platforms_139,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_43,
        array_kFieldTrialConfig_enable_features_136,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_135[] = {
    "HappinessTrackingSurveysForComposeClose",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_42[] = {
    {
        "prob",
        "0.1",
    },
    {
        "survey_cycle_length",
        "7",
    },
    {
        "survey_start_date_ms",
        "1729580400000",
    },
    {
        "trigger_id",
        "mT2d9fiNR0ugnJ3q1cK0SdAewrT2",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_138[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_125[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_138,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_42,
        array_kFieldTrialConfig_enable_features_135,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_134[] = {
    "HappinessTrackingSurveysForComposeAcceptance",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_41[] = {
    {
        "prob",
        "0.1",
    },
    {
        "survey_cycle_length",
        "7",
    },
    {
        "survey_start_date_ms",
        "1729580400000",
    },
    {
        "trigger_id",
        "44m1DgehL0ugnJ3q1cK0Qih71MRQ",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_137[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_124[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_137,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_41,
        array_kFieldTrialConfig_enable_features_134,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_133[] = {
    "ComposeAXSnapshot",
};
const Study::Platform array_kFieldTrialConfig_platforms_136[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_123[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_136,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_133,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_132[] = {
    "CompareConfirmationToast",
    "ProductSpecifications",
    "ProductSpecificationsMqlsLogging",
};
const Study::Platform array_kFieldTrialConfig_platforms_135[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_131[] = {
    "CompareConfirmationToast",
    "ProductSpecifications",
    "ProductSpecificationsMqlsLogging",
};
const Study::Platform array_kFieldTrialConfig_platforms_134[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_122[] = {
    {
        "Enabled_Dogfood",
        array_kFieldTrialConfig_platforms_134,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_131,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_135,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_132,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_130[] = {
    "IPH_PriceInsightsPageActionIconLabelFeature",
    "PriceInsights",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_40[] = {
    {
        "availability",
        "any",
    },
    {
        "event_1",
        "name:price_insights_page_action_icon_label_in_trigger;comparator:any;window:0;storage:360",
    },
    {
        "event_trigger",
        "name:price_insights_page_action_icon_label_in_trigger;comparator:any;window:0;storage:360",
    },
    {
        "event_used",
        "name:price_insights_page_action_icon_label_used;comparator:any;window:0;storage:360",
    },
    {
        "price-insights-show-feedback",
        "true",
    },
    {
        "session_rate",
        "any",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_133[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_121[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_133,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_40,
        array_kFieldTrialConfig_enable_features_130,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_129[] = {
    "CommerceLocalPDPDetection",
};
const Study::Platform array_kFieldTrialConfig_platforms_132[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_120[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_132,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_129,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_128[] = {
    "CodeBasedRBD",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_39[] = {
    {
        "code-based-rbd",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_131[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_119[] = {
    {
        "Enabled_20230420",
        array_kFieldTrialConfig_platforms_131,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_39,
        array_kFieldTrialConfig_enable_features_128,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_127[] = {
    "CoalesceSelectionchangeEvent",
};
const Study::Platform array_kFieldTrialConfig_platforms_130[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_118[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_130,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_127,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_126[] = {
    "CloneDevToolsConnectionOnlyIfRequested",
};
const Study::Platform array_kFieldTrialConfig_platforms_129[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_117[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_129,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_126,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_125[] = {
    "ClientSideDetectionSamplePing",
};
const Study::Platform array_kFieldTrialConfig_platforms_128[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_116[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_128,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_125,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_124[] = {
    "ClientSideDetectionRetryLimit",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_38[] = {
    {
        "RetryTimeMax",
        "15",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_127[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_115[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_127,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_38,
        array_kFieldTrialConfig_enable_features_124,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_123[] = {
    "ClientSideDetectionAcceptHCAllowlist",
};
const Study::Platform array_kFieldTrialConfig_platforms_126[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_114[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_126,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_123,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_122[] = {
    "ClearUndecryptablePasswords",
};
const Study::Platform array_kFieldTrialConfig_platforms_125[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_113[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_125,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_122,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_121[] = {
    "ClearGrShaderDiskCacheOnInvalidPrefix",
};
const Study::Platform array_kFieldTrialConfig_platforms_124[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_112[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_124,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_121,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_120[] = {
    "ClassifyUrlOnProcessResponseEvent",
};
const Study::Platform array_kFieldTrialConfig_platforms_123[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_111[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_123,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_120,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_119[] = {
    "LensOverlaySurvey",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_37[] = {
    {
        "en_site_id",
        "LvUA3D5Ts0ugnJ3q1cK0SHbD7uPa",
    },
    {
        "probability",
        "0.5",
    },
    {
        "results-time",
        "6s",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_122[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_110[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_122,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_37,
        array_kFieldTrialConfig_enable_features_119,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_118[] = {
    "IPH_LensOverlayTranslateButton",
    "LensOverlayTranslateButton",
};
const Study::Platform array_kFieldTrialConfig_platforms_121[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_109[] = {
    {
        "TranslateButtonEnabled",
        array_kFieldTrialConfig_platforms_121,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_118,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_117[] = {
    "LensOverlayTranslateLanguages",
};
const Study::Platform array_kFieldTrialConfig_platforms_120[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_108[] = {
    {
        "MoreTranslateLanguagesEnabled",
        array_kFieldTrialConfig_platforms_120,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_117,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_116[] = {
    "LensOverlayLatencyOptimizations",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_36[] = {
    {
        "enable-cluster-info-optimization",
        "true",
    },
    {
        "enable-early-interaction-optimization",
        "true",
    },
    {
        "enable-early-start-query-flow-optimization",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_119[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_107[] = {
    {
        "AllOptimizationsEnabled",
        array_kFieldTrialConfig_platforms_119,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_36,
        array_kFieldTrialConfig_enable_features_116,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_115[] = {
    "LensOverlayImageContextMenuActions",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_35[] = {
    {
        "enable-copy-as-image",
        "true",
    },
    {
        "enable-save-as-image",
        "true",
    },
    {
        "text-received-timeout",
        "2000",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_118[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_106[] = {
    {
        "CopyAndSaveAsImageEnabled",
        array_kFieldTrialConfig_platforms_118,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_35,
        array_kFieldTrialConfig_enable_features_115,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_114[] = {
    "IPH_LensOverlay",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_34[] = {
    {
        "availability",
        "any",
    },
    {
        "event_trigger",
        "name:lens_overlay_iph_triggered;comparator:any;window:90;storage:365",
    },
    {
        "event_used",
        "name:lens_overlay_used;comparator:==0;window:90;storage:365",
    },
    {
        "session_rate",
        "==0",
    },
    {
        "x_url_allow_filters",
        "%5B%22facebook%2Ecom%22%2C%22web%2Ewhatsapp%2Ecom%22%2C%22instagram%2Ecom%22%2C%22x%2Ecom%22%2C%22twitter%2Ecom%22%2C%22reddit%2Ecom%22%2C%22tiktok%"
        "2Ecom%22%2C%22pinterest%2Ecom%22%2C%22quora%2Ecom%22%2C%22youtube%2Ecom%2Fshorts%22%5D",
    },
    {
        "x_url_block_filters",
        "%5B%22facebook%2Ecom%2Flogin%22%2C%22x%2Ecom%2Flogin%22%2C%22instagram%2Ecom%2Faccounts%2Flogin%22%2C%22reddit%2Ecom%2Flogin%22%2C%22tiktok%2Ecom%"
        "2Flogin%22%2C%22pinterest%2Ecom%2Flogin%22%2C%22amazon%2Ecom%2Fap%2Fsignin%22%5D",
    },
    {
        "x_wait_time",
        "7s",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_117[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_105[] = {
    {
        "EnabledSocialMedia",
        array_kFieldTrialConfig_platforms_117,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_34,
        array_kFieldTrialConfig_enable_features_114,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_116[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_104[] = {
    {
        "FetchSrpEnabled",
        array_kFieldTrialConfig_platforms_116,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_113[] = {
    "ChromeWideEchoCancellation",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_33[] = {
    {
        "processing_fifo_size",
        "110",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_115[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_103[] = {
    {
        "Enabled_20220412",
        array_kFieldTrialConfig_platforms_115,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_33,
        array_kFieldTrialConfig_enable_features_113,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_7[] = {
    "NtpWallpaperSearchButtonAnimation",
};
const char* const array_kFieldTrialConfig_enable_features_112[] = {
    "CustomizeChromeWallpaperSearchButton",
    "NtpWallpaperSearchButton",
    "NtpWallpaperSearchButtonHideCondition",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_32[] = {
    {
        "NtpWallpaperSearchButtonHideConditionParam",
        "0",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_114[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_6[] = {
    "NtpWallpaperSearchButtonAnimation",
};
const char* const array_kFieldTrialConfig_enable_features_111[] = {
    "CustomizeChromeWallpaperSearchButton",
    "NtpWallpaperSearchButton",
    "NtpWallpaperSearchButtonHideCondition",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_31[] = {
    {
        "NtpWallpaperSearchButtonHideConditionParam",
        "1",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_113[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_102[] = {
    {
        "DefaultOnLaunched",
        array_kFieldTrialConfig_platforms_113,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_31,
        array_kFieldTrialConfig_enable_features_111,
        array_kFieldTrialConfig_disable_features_6,
        nullptr,
        {},
        {},
        {},
    },
    {
        "DefaultOn",
        array_kFieldTrialConfig_platforms_114,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_32,
        array_kFieldTrialConfig_enable_features_112,
        array_kFieldTrialConfig_disable_features_7,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_110[] = {
    "HappinessTrackingSurveysForWallpaperSearch",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_30[] = {
    {
        "WallpaperSearchHatsDelayParam",
        "18s",
    },
    {
        "en_site_id",
        "foo",
    },
    {
        "probability",
        "1.0",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_112[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_101[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_112,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_30,
        array_kFieldTrialConfig_enable_features_110,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_5[] = {
    "WallpaperSearchSettingsVisibility",
};
const char* const array_kFieldTrialConfig_enable_features_109[] = {
    "CustomizeChromeWallpaperSearch",
    "CustomizeChromeWallpaperSearchInspirationCard",
    "WallpaperSearchGraduated",
};
const Study::Platform array_kFieldTrialConfig_platforms_111[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_100[] = {
    {
        "WallpaperSearchGlobal",
        array_kFieldTrialConfig_platforms_111,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_109,
        array_kFieldTrialConfig_disable_features_5,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_108[] = {
    "ChromeLabs",
};
const Study::Platform array_kFieldTrialConfig_platforms_110[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_99[] = {
    {
        "Enabled_20210128",
        array_kFieldTrialConfig_platforms_110,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_108,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_107[] = {
    "Compose",
};
const Study::Platform array_kFieldTrialConfig_platforms_109[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_98[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_109,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_107,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_106[] = {
    "ChromeCartDomBasedHeuristics",
};
const Study::Platform array_kFieldTrialConfig_platforms_108[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_97[] = {
    {
        "enabled_chrome_cart_dom_based_heuristics_20230214",
        array_kFieldTrialConfig_platforms_108,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_106,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_105[] = {
    "CheckHTMLParserBudgetLessOften",
};
const Study::Platform array_kFieldTrialConfig_platforms_107[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_96[] = {
    {
        "Enabled_Nonstable_20230320",
        array_kFieldTrialConfig_platforms_107,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_105,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_104[] = {
    "ChangeFrameRateOfLoadingTabAnimation",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_29[] = {
    {
        "loading_tab_animation_frame_delay",
        "67ms",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_106[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_95[] = {
    {
        "EnabledWith67msFrameDelay",
        array_kFieldTrialConfig_platforms_106,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_29,
        array_kFieldTrialConfig_enable_features_104,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_103[] = {
    "ChangeDiskCacheSize",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_28[] = {
    {
        "percent_relative_size",
        "400",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_105[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_94[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_105,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_28,
        array_kFieldTrialConfig_enable_features_103,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_4[] = {
    "CdmStorageDatabaseMigration",
};
const Study::Platform array_kFieldTrialConfig_platforms_104[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_93[] = {
    {
        "Disabled",
        array_kFieldTrialConfig_platforms_104,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_4,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_102[] = {
    "CbdTimeframeRequired",
};
const Study::Platform array_kFieldTrialConfig_platforms_103[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_92[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_103,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_102,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_3[] = {
    "RecordSequenceManagerCrashKeys",
    "ThreadControllerSetsProfilerMetadata",
};
const char* const array_kFieldTrialConfig_enable_features_101[] = {
    "AboveNormalCompositingBrowserWin",
    "DelayFirstPeriodicPAPurgeOrReclaim",
    "DelayFirstWorkerWake",
    "ExplicitHighResolutionTimerWin",
    "InhibitLoadingStateUpdate",
    "MainThreadCompositingPriority",
    "QuickIntensiveWakeUpThrottlingAfterLoading",
    "ReduceCookieIPCs",
    "UseCompositorJob",
};
const Study::Platform array_kFieldTrialConfig_platforms_102[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_91[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_102,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_101,
        array_kFieldTrialConfig_disable_features_3,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_100[] = {
    "CastStreamingWinHardwareH264",
};
const Study::Platform array_kFieldTrialConfig_platforms_101[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_90[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_101,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_100,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_99[] = {
    "CastStreamingVp9",
};
const Study::Platform array_kFieldTrialConfig_platforms_100[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_89[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_100,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_99,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_98[] = {
    "CastCertificateRevocation",
};
const Study::Platform array_kFieldTrialConfig_platforms_99[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_88[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_99,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_98,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_97[] = {
    "CanvasHibernationSnapshotZstd",
};
const Study::Platform array_kFieldTrialConfig_platforms_98[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_87[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_98,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_97,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_96[] = {
    "Canvas2DHibernation",
    "Canvas2DHibernationReleaseTransferMemory",
    "ClearCanvasResourcesInBackground",
    "EvictionUnlocksResources",
};
const Study::Platform array_kFieldTrialConfig_platforms_97[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_86[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_97,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_96,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_95[] = {
    "Canvas2DReclaimUnusedResources",
};
const Study::Platform array_kFieldTrialConfig_platforms_96[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_85[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_96,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_95,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_94[] = {
    "Canvas2DAutoFlushParams",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_27[] = {
    {
        "max_pinned_image_kb",
        "32768",
    },
    {
        "max_recorded_op_kb",
        "2048",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_95[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_84[] = {
    {
        "Candidate",
        array_kFieldTrialConfig_platforms_95,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_27,
        array_kFieldTrialConfig_enable_features_94,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_93[] = {
    "CameraMicPreview",
    "GetUserMediaDeferredDeviceSettingsSelection",
};
const Study::Platform array_kFieldTrialConfig_platforms_94[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_83[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_94,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_93,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_92[] = {
    "CacheStorageTaskPriority",
};
const Study::Platform array_kFieldTrialConfig_platforms_93[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_82[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_93,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_92,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_91[] = {
    "CSSLazyParsingFastPath",
};
const Study::Platform array_kFieldTrialConfig_platforms_92[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_81[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_92,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_91,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_2[] = {
    "CSSDisplayAnimation",
};
const Study::Platform array_kFieldTrialConfig_platforms_91[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_90[] = {
    "CSSDisplayAnimation",
};
const Study::Platform array_kFieldTrialConfig_platforms_90[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_80[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_90,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_90,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Disabled",
        array_kFieldTrialConfig_platforms_91,
        {},
        std::nullopt,
        nullptr,
        {},
        {},
        array_kFieldTrialConfig_disable_features_2,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_89[] = {
    "PermissionPredictionsV3",
};
const Study::Platform array_kFieldTrialConfig_platforms_89[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_79[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_89,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_89,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_88[] = {
    "BufferSizeForFilterSourceStreamFeature",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_26[] = {
    {
        "BufferSizeForFilterSourceStream",
        "32768",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_88[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_78[] = {
    {
        "buffer_size_0032k_20230919",
        array_kFieldTrialConfig_platforms_88,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_26,
        array_kFieldTrialConfig_enable_features_88,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_87[] = {
    "BubbleMetricsApi",
};
const Study::Platform array_kFieldTrialConfig_platforms_87[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_77[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_87,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_87,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_86[] = {
    "BrowserThreadPoolAdjustment",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_25[] = {
    {
        "BrowserThreadPoolCoresMultiplier",
        "0.6",
    },
    {
        "BrowserThreadPoolMax",
        "32",
    },
    {
        "BrowserThreadPoolMin",
        "16",
    },
    {
        "BrowserThreadPoolOffset",
        "0",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_86[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_76[] = {
    {
        "thread_pool_default_20230920",
        array_kFieldTrialConfig_platforms_86,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_25,
        array_kFieldTrialConfig_enable_features_86,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_85[] = {
    "BoundaryEventDispatchTracksNodeRemoval",
};
const Study::Platform array_kFieldTrialConfig_platforms_85[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_75[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_85,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_85,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_84[] = {
    "BoostRenderProcessForLoading",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_24[] = {
    {
        "prioritize_prerendering",
        "false",
    },
    {
        "prioritize_prerendering_only",
        "false",
    },
    {
        "prioritize_renderer_initiated",
        "true",
    },
    {
        "target_urls",
        "[]",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_84[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_74[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_84,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_24,
        array_kFieldTrialConfig_enable_features_84,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_83[] = {
    "BlockAcceptClientHints",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_23[] = {
    {
        "BlockedSite",
        "https://www.google.com",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_83[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_73[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_83,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_23,
        array_kFieldTrialConfig_enable_features_83,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_82[] = {
    "BatterySaverModeAlignWakeUps",
    "LowerHighResolutionTimerThreshold",
    "TimerSlackMac",
};
const Study::Platform array_kFieldTrialConfig_platforms_82[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_72[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_82,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_82,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_81[] = {
    "BatchUploadDesktop",
};
const Study::Platform array_kFieldTrialConfig_platforms_81[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_71[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_81,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_81,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_80[] = {
    "BackgroundTabLoadingFromPerformanceManager",
};
const Study::Platform array_kFieldTrialConfig_platforms_80[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_70[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_80,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_80,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_79[] = {
    "BackgroundResourceFetch",
    "ReduceTransferSizeUpdatedIPC",
};
const Study::Platform array_kFieldTrialConfig_platforms_79[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_69[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_79,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_79,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_78[] = {
    "IPH_BackNavigationMenu",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_22[] = {
    {
        "availability",
        ">0",
    },
    {
        "event_trigger",
        "name:back_navigation_menu_iph_is_triggered;comparator:<=4;window:365;storage:365",
    },
    {
        "event_used",
        "name:back_navigation_menu_is_opened;comparator:==0;window:7;storage:365",
    },
    {
        "session_rate",
        "<1",
    },
    {
        "snooze_params",
        "max_limit:4,snooze_interval:7",
    },
    {
        "x_experiment",
        "1",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_78[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_68[] = {
    {
        "EnabledIPHWhenUserPerformsChainedBackNavigation_20230510",
        array_kFieldTrialConfig_platforms_78,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_22,
        array_kFieldTrialConfig_enable_features_78,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_77[] = {
    "AllowSensorsToEnterBfcache",
};
const Study::Platform array_kFieldTrialConfig_platforms_77[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_67[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_77,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_77,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_76[] = {
    "BackForwardCacheSendNotRestoredReasons",
};
const Study::Platform array_kFieldTrialConfig_platforms_76[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_66[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_76,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_76,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_75[] = {
    "BackForwardCacheMediaSessionService",
};
const Study::Platform array_kFieldTrialConfig_platforms_75[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_65[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_75,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_75,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_74[] = {
    "CacheControlNoStoreEnterBackForwardCache",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_21[] = {
    {
        "level",
        "restore-unless-cookie-change",
    },
    {
        "ttl",
        "3m",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_74[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_64[] = {
    {
        "Enabled_20240129",
        array_kFieldTrialConfig_platforms_74,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_21,
        array_kFieldTrialConfig_enable_features_74,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_73[] = {
    "RegisterJSSourceLocationBlockingBFCache",
};
const Study::Platform array_kFieldTrialConfig_platforms_73[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_63[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_73,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_73,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_72[] = {
    "BFCacheOpenBroadcastChannel",
};
const Study::Platform array_kFieldTrialConfig_platforms_72[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_62[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_72,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_72,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_71[] = {
    "AvoidUnnecessaryForcedLayoutMeasurements",
};
const Study::Platform array_kFieldTrialConfig_platforms_71[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_61[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_71,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_71,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_70[] = {
    "AvoidLoadingPredictorPrefetchDuringBrowserStartup",
};
const Study::Platform array_kFieldTrialConfig_platforms_70[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_60[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_70,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_70,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_69[] = {
    "AvoidEntryCreationForNoStore",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_20[] = {
    {
        "AvoidEntryCreationForNoStoreCacheSize",
        "40000",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_69[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_59[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_69,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_20,
        array_kFieldTrialConfig_enable_features_69,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_68[] = {
    "AutofillVcnEnrollRequestTimeout",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_19[] = {
    {
        "autofill_vcn_enroll_request_timeout_milliseconds",
        "10000",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_68[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_67[] = {
    "AutofillVcnEnrollRequestTimeout",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_18[] = {
    {
        "autofill_vcn_enroll_request_timeout_milliseconds",
        "7500",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_67[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_66[] = {
    "AutofillVcnEnrollRequestTimeout",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_17[] = {
    {
        "autofill_vcn_enroll_request_timeout_milliseconds",
        "5000",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_66[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_58[] = {
    {
        "Enabled_5seconds",
        array_kFieldTrialConfig_platforms_66,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_17,
        array_kFieldTrialConfig_enable_features_66,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_7point5seconds",
        array_kFieldTrialConfig_platforms_67,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_18,
        array_kFieldTrialConfig_enable_features_67,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_10seconds",
        array_kFieldTrialConfig_platforms_68,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_19,
        array_kFieldTrialConfig_enable_features_68,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_65[] = {
    "AutofillUpstreamUpdatedUi",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_16[] = {
    {
        "autofill_upstream_updated_ui_treatment",
        "1",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_65[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_57[] = {
    {
        "Enabled_Security",
        array_kFieldTrialConfig_platforms_65,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_16,
        array_kFieldTrialConfig_enable_features_65,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_64[] = {
    "AutofillUpstream",
};
const Study::Platform array_kFieldTrialConfig_platforms_64[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_56[] = {
    {
        "Enabled_20220124",
        array_kFieldTrialConfig_platforms_64,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_64,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_63[] = {
    "AutofillUploadCardRequestTimeout",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_15[] = {
    {
        "autofill_upload_card_request_timeout_milliseconds",
        "9000",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_63[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_62[] = {
    "AutofillUploadCardRequestTimeout",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_14[] = {
    {
        "autofill_upload_card_request_timeout_milliseconds",
        "7000",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_62[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_61[] = {
    "AutofillUploadCardRequestTimeout",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_13[] = {
    {
        "autofill_upload_card_request_timeout_milliseconds",
        "6500",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_61[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_55[] = {
    {
        "Enabled_6point5seconds",
        array_kFieldTrialConfig_platforms_61,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_13,
        array_kFieldTrialConfig_enable_features_61,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_7seconds",
        array_kFieldTrialConfig_platforms_62,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_14,
        array_kFieldTrialConfig_enable_features_62,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_9seconds",
        array_kFieldTrialConfig_platforms_63,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_15,
        array_kFieldTrialConfig_enable_features_63,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_60[] = {
    "AutofillUnmaskCardRequestTimeout",
};
const Study::Platform array_kFieldTrialConfig_platforms_60[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_54[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_60,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_60,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_59[] = {
    "AutofillUKMExperimentalFields",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_12[] = {
    {
        "autofill_experimental_regex_bucket1",
        "test1",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_59[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_53[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_59,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_12,
        array_kFieldTrialConfig_enable_features_59,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_disable_features_1[] = {
    "AutofillCardSurvey",
    "AutofillPasswordSurvey",
};
const char* const array_kFieldTrialConfig_enable_features_58[] = {
    "AutofillAddressSurvey",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_11[] = {
    {
        "en_site_id",
        "qQW9c2ho10ugnJ3q1cK0X48UQjZs",
    },
    {
        "probability",
        "1.0",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_58[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features_0[] = {
    "AutofillAddressSurvey",
    "AutofillCardSurvey",
};
const char* const array_kFieldTrialConfig_enable_features_57[] = {
    "AutofillPasswordSurvey",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_10[] = {
    {
        "en_site_id",
        "6VQ4NCCaq0ugnJ3q1cK0TR13rB8t",
    },
    {
        "probability",
        "1.0",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_57[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_disable_features[] = {
    "AutofillAddressSurvey",
    "AutofillPasswordSurvey",
};
const char* const array_kFieldTrialConfig_enable_features_56[] = {
    "AutofillCardSurvey",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_9[] = {
    {
        "en_site_id",
        "F2fsskHvB0ugnJ3q1cK0NXLjUaK5",
    },
    {
        "probability",
        "1.0",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_56[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_52[] = {
    {
        "Card_20230606",
        array_kFieldTrialConfig_platforms_56,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_9,
        array_kFieldTrialConfig_enable_features_56,
        array_kFieldTrialConfig_disable_features,
        nullptr,
        {},
        {},
        {},
    },
    {
        "Password_20230606",
        array_kFieldTrialConfig_platforms_57,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_10,
        array_kFieldTrialConfig_enable_features_57,
        array_kFieldTrialConfig_disable_features_0,
        nullptr,
        {},
        {},
        {},
    },
    {
        "Address_20230606",
        array_kFieldTrialConfig_platforms_58,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_11,
        array_kFieldTrialConfig_enable_features_58,
        array_kFieldTrialConfig_disable_features_1,
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_55[] = {
    "AutofillStructuredFieldsDisableAddressLines",
};
const Study::Platform array_kFieldTrialConfig_platforms_55[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_51[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_55,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_55,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_54[] = {
    "AutofillSharedStorageServerCardData",
};
const Study::Platform array_kFieldTrialConfig_platforms_54[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_50[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_54,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_54,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_53[] = {
    "AutofillOverwritePlaceholdersOnly",
    "AutofillSkipPreFilledFields",
};
const Study::Platform array_kFieldTrialConfig_platforms_53[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_49[] = {
    {
        "Enabled_OverwritePlaceholdersOnly",
        array_kFieldTrialConfig_platforms_53,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_53,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_52[] = {
    "AutofillPopupZOrderSecuritySurface",
};
const Study::Platform array_kFieldTrialConfig_platforms_52[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_48[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_52,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_52,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_51[] = {
    "AutofillPopupDontAcceptNonVisibleEnoughSuggestion",
};
const Study::Platform array_kFieldTrialConfig_platforms_51[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_47[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_51,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_51,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_50[] = {
    "AutofillPasswordUserPerceptionSurvey",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_8[] = {
    {
        "en_site_id",
        "cLnNGzEX59NNVVEtwumiSF",
    },
    {
        "probability",
        "1",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_50[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_46[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_50,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_8,
        array_kFieldTrialConfig_enable_features_50,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_49[] = {
    "AutofillParseEmailLabelAndPlaceholder",
};
const Study::Platform array_kFieldTrialConfig_platforms_49[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_45[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_49,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_49,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_48[] = {
    "AutofillPageLanguageDetection",
};
const Study::Platform array_kFieldTrialConfig_platforms_48[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_44[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_48,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_48,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_47[] = {
    "AutofillModelPredictions",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_7[] = {
    {
        "model_active",
        "false",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_47[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_43[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_47,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_7,
        array_kFieldTrialConfig_enable_features_47,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_46[] = {
    "AutofillLogUKMEventsWithSampleRate",
};
const Study::Platform array_kFieldTrialConfig_platforms_46[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_42[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_46,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_46,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_45[] = {
    "AutofillLogDeduplicationMetrics",
};
const Study::Platform array_kFieldTrialConfig_platforms_45[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_41[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_45,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_45,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_44[] = {
    "AutofillInferLabelFromDefaultSelectText",
};
const Study::Platform array_kFieldTrialConfig_platforms_44[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_40[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_44,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_44,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_43[] = {
    "AutofillFixFormTracking",
    "AutofillPreferSavedFormAsSubmittedForm",
    "AutofillUseSubmittedFormInHtmlSubmission",
};
const Study::Platform array_kFieldTrialConfig_platforms_43[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_39[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_43,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_43,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_42[] = {
    "AutofillImportFromAutocompleteUnrecognized",
};
const Study::Platform array_kFieldTrialConfig_platforms_42[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_38[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_42,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_42,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_41[] = {
    "AutofillUseAUAddressModel",
    "AutofillUseCAAddressModel",
    "AutofillUseDEAddressModel",
};
const Study::Platform array_kFieldTrialConfig_platforms_41[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_37[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_41,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_41,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_40[] = {
    "AutofillGreekRegexes",
    "AutofillUseITAddressModel",
    "AutofillUsePLAddressModel",
};
const Study::Platform array_kFieldTrialConfig_platforms_40[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_36[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_40,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_40,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_39[] = {
    "AutofillGranularFillingAvailable",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_6[] = {
    {
        "autofill_granular_filling_with_expand_control_visible_on_selection_only",
        "true",
    },
    {
        "autofill_granular_filling_with_fill_everything_in_the_footer",
        "true",
    },
    {
        "autofill_granular_filling_with_improved_labels",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_39[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_38[] = {
    "AutofillGranularFillingAvailable",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_5[] = {
    {
        "autofill_granular_filling_with_expand_control_visible_on_selection_only",
        "false",
    },
    {
        "autofill_granular_filling_with_fill_everything_in_the_footer",
        "false",
    },
    {
        "autofill_granular_filling_with_improved_labels",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_38[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_37[] = {
    "AutofillGranularFillingAvailable",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_4[] = {
    {
        "autofill_granular_filling_with_expand_control_visible_on_selection_only",
        "false",
    },
    {
        "autofill_granular_filling_with_fill_everything_in_the_footer",
        "true",
    },
    {
        "autofill_granular_filling_with_improved_labels",
        "false",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_37[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_36[] = {
    "AutofillGranularFillingAvailable",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_3[] = {
    {
        "autofill_granular_filling_with_expand_control_visible_on_selection_only",
        "false",
    },
    {
        "autofill_granular_filling_with_fill_everything_in_the_footer",
        "true",
    },
    {
        "autofill_granular_filling_with_improved_labels",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_36[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_35[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_36,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_3,
        array_kFieldTrialConfig_enable_features_36,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_WithoutImprovedLabels",
        array_kFieldTrialConfig_platforms_37,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_4,
        array_kFieldTrialConfig_enable_features_37,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_WithFillEverythingAtTheTop",
        array_kFieldTrialConfig_platforms_38,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_5,
        array_kFieldTrialConfig_enable_features_38,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Enabled_WithExpandControlVisibleOnSelectionOnly",
        array_kFieldTrialConfig_platforms_39,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_6,
        array_kFieldTrialConfig_enable_features_39,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_35[] = {
    "AutofillGivePrecedenceToEmailOverUsername",
};
const Study::Platform array_kFieldTrialConfig_platforms_35[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_34[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_35,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_35,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_34[] = {
    "AutofillEnableManualFallbackIPH",
    "AutofillForUnclassifiedFieldsAvailable",
};
const Study::Platform array_kFieldTrialConfig_platforms_34[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_33[] = {
    {
        "Enabled_AutofillForUnclassifiedFieldsAndManualFallbackIPH",
        array_kFieldTrialConfig_platforms_34,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_34,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_33[] = {
    "AutofillFixCurrentValueInImport",
    "AutofillFixInitialValueOfSelect",
    "AutofillFixValueSemantics",
};
const Study::Platform array_kFieldTrialConfig_platforms_33[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_32[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_33,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_33,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_32[] = {
    "AllowJavaScriptToResetAutofillState",
    "AutofillFixCachingOnJavaScriptChanges",
};
const Study::Platform array_kFieldTrialConfig_platforms_32[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_31[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_32,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_32,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_31[] = {
    "AutofillParseVcnCardOnFileStandaloneCvcFields",
    "SyncAutofillWalletUsageData",
};
const Study::Platform array_kFieldTrialConfig_platforms_31[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_30[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_31,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_31,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_30[] = {
    "AutofillEnableVcnGrayOutForMerchantOptOut",
};
const Study::Platform array_kFieldTrialConfig_platforms_30[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_29[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_30,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_30,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_29[] = {
    "AutofillEnableSupportForParsingWithSharedLabels",
};
const Study::Platform array_kFieldTrialConfig_platforms_29[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_28[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_29,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_29,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_28[] = {
    "AutofillEnableLocalIban",
    "AutofillEnableServerIban",
};
const Study::Platform array_kFieldTrialConfig_platforms_28[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_27[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_28,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_28,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_27[] = {
    "AutofillEnablePaymentsFieldSwapping",
};
const Study::Platform array_kFieldTrialConfig_platforms_27[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_26[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_27,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_27,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_26[] = {
    "AutofillEnableNewSaveCardBubbleUi",
};
const Study::Platform array_kFieldTrialConfig_platforms_26[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_25[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_26,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_26,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_25[] = {
    "AutofillEnableRankingFormulaAddressProfiles",
    "AutofillEnableRankingFormulaCreditCards",
};
const Study::Platform array_kFieldTrialConfig_platforms_25[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_24[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_25,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_25,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_24[] = {
    "AutofillEnableLogFormEventsToAllParsedFormTypes",
};
const Study::Platform array_kFieldTrialConfig_platforms_24[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_23[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_24,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_24,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_23[] = {
    "AutofillEnableSaveCardLoadingAndConfirmation",
    "AutofillEnableSaveCardLocalSaveFallback",
    "AutofillEnableVcnEnrollLoadingAndConfirmation",
};
const Study::Platform array_kFieldTrialConfig_platforms_23[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_22[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_23,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_23,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_22[] = {
    "AutofillEnableLabelPrecedenceForTurkishAddresses",
};
const Study::Platform array_kFieldTrialConfig_platforms_22[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_21[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_22,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_22,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_21[] = {
    "AutofillEnableFpanRiskBasedAuthentication",
};
const Study::Platform array_kFieldTrialConfig_platforms_21[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_20[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_21,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_21,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_20[] = {
    "AutofillEnableFillingPhoneCountryCodesByAddressCountryCodes",
};
const Study::Platform array_kFieldTrialConfig_platforms_20[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_19[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_20,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_20,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_19[] = {
    "AutofillEnableExpirationDateImprovements",
};
const Study::Platform array_kFieldTrialConfig_platforms_19[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_18[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_19,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_19,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_18[] = {
    "AutofillEnableCvcStorageAndFilling",
    "AutofillEnableCvcStorageAndFillingEnhancement",
    "SyncAutofillWalletCredentialData",
};
const Study::Platform array_kFieldTrialConfig_platforms_18[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_17[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_18,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_18,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_17[] = {
    "AutofillEnableCardBenefitsIph",
};
const Study::Platform array_kFieldTrialConfig_platforms_17[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_16[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_17,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_17,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_16[] = {
    "AutofillEnableCardBenefitsForCapitalOne",
};
const Study::Platform array_kFieldTrialConfig_platforms_16[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_15[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_16,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_16,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_15[] = {
    "AutofillEnableCardBenefitsForAmericanExpress",
};
const Study::Platform array_kFieldTrialConfig_platforms_15[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_14[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_15,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_15,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_14[] = {
    "AutofillEnableAccountStorageForIneligibleCountries",
};
const Study::Platform array_kFieldTrialConfig_platforms_14[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_13[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_14,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_14,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_13[] = {
    "AutofillDisableLocalCardMigration",
};
const Study::Platform array_kFieldTrialConfig_platforms_13[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_12[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_13,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_13,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_12[] = {
    "AutofillDecoupleAutofillCountFromCache",
};
const Study::Platform array_kFieldTrialConfig_platforms_12[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_11[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_12,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_12,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_11[] = {
    "AutofillCreditCardUserPerceptionSurvey",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_2[] = {
    {
        "en_site_id",
        "Q13fLRHym0ugnJ3q1cK0Tm5d8fMW",
    },
    {
        "probability",
        "1",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_11[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_10[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_11,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_2,
        array_kFieldTrialConfig_enable_features_11,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_10[] = {
    "AutofillAi",
};
const Study::Platform array_kFieldTrialConfig_platforms_10[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_9[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_10,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_10,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_9[] = {
    "AutofillAddressUserPerceptionSurvey",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_1[] = {
    {
        "en_site_id",
        "Q13fLRHym0ugnJ3q1cK0Tm5d8fMW",
    },
    {
        "probability",
        "1",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_9[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_8[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_9,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_1,
        array_kFieldTrialConfig_enable_features_9,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_8[] = {
    "AutoSpeculationRules",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params_0[] = {
    {
        "config",
        "{\"framework_to_speculation_rules\":{\"12\":\"{\\\"prefetch\\\":[{\\\"source\\\":\\\"document\\\",\\\"eagerness\\\":\\\"conservative\\\","
        "\\\"where\\\":{\\\"href_matches\\\":\\\"/*\\\"}}]}\"}}",
    },
    {
        "holdback",
        "true",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_8[] = {
    Study::PLATFORM_WINDOWS,
};
const char* const array_kFieldTrialConfig_enable_features_7[] = {
    "AutoSpeculationRules",
};
const FieldTrialTestingExperimentParams array_kFieldTrialConfig_params[] = {
    {
        "config",
        "{\"framework_to_speculation_rules\":{\"12\":\"{\\\"prefetch\\\":[{\\\"source\\\":\\\"document\\\",\\\"eagerness\\\":\\\"conservative\\\","
        "\\\"where\\\":{\\\"href_matches\\\":\\\"/*\\\"}}]}\"}}",
    },
    {
        "holdback",
        "false",
    },
};
const Study::Platform array_kFieldTrialConfig_platforms_7[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_7[] = {
    {
        "Enabled_20231201",
        array_kFieldTrialConfig_platforms_7,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params,
        array_kFieldTrialConfig_enable_features_7,
        {},
        nullptr,
        {},
        {},
        {},
    },
    {
        "Holdback_20231201",
        array_kFieldTrialConfig_platforms_8,
        {},
        std::nullopt,
        nullptr,
        array_kFieldTrialConfig_params_0,
        array_kFieldTrialConfig_enable_features_8,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_6[] = {
    "AutoDisableAccessibility",
};
const Study::Platform array_kFieldTrialConfig_platforms_6[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_6[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_6,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_6,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_5[] = {
    "AudioOffload",
};
const Study::Platform array_kFieldTrialConfig_platforms_5[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_5[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_5,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_5,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_4[] = {
    "AllowDatapipeDrainedAsBytesConsumerInBFCache",
};
const Study::Platform array_kFieldTrialConfig_platforms_4[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_4[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_4,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_4,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_3[] = {
    "AiSettingsPageRefresh",
};
const Study::Platform array_kFieldTrialConfig_platforms_3[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_3[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_3,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_3,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_2[] = {
    "AggressiveShaderCacheLimits",
};
const Study::Platform array_kFieldTrialConfig_platforms_2[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_2[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_2,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_2,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_1[] = {
    "AccessibilitySerializationSizeMetrics",
};
const Study::Platform array_kFieldTrialConfig_platforms_1[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_1[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_1,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_1,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features_0[] = {
    "ANGLEPerContextBlobCache",
};
const Study::Platform array_kFieldTrialConfig_platforms_0[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments_0[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms_0,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features_0,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const char* const array_kFieldTrialConfig_enable_features[] = {
    "UseNewAlpsCodepointHttp2",
    "UseNewAlpsCodepointQUIC",
};
const Study::Platform array_kFieldTrialConfig_platforms[] = {
    Study::PLATFORM_WINDOWS,
};
const FieldTrialTestingExperiment array_kFieldTrialConfig_experiments[] = {
    {
        "Enabled",
        array_kFieldTrialConfig_platforms,
        {},
        std::nullopt,
        nullptr,
        {},
        array_kFieldTrialConfig_enable_features,
        {},
        nullptr,
        {},
        {},
        {},
    },
};
const FieldTrialTestingStudy array_kFieldTrialConfig_studies[] = {
    {
        "ALPSNewCodepoint",
        array_kFieldTrialConfig_experiments,
    },
    {
        "ANGLEPerContextBlobCache",
        array_kFieldTrialConfig_experiments_0,
    },
    {
        "AccessibilitySerializationSizeMetrics",
        array_kFieldTrialConfig_experiments_1,
    },
    {
        "AggressiveShaderCacheLimits",
        array_kFieldTrialConfig_experiments_2,
    },
    {
        "AiSettingsPageRefresh",
        array_kFieldTrialConfig_experiments_3,
    },
    {
        "AllowDatapipeDrainedAsBytesConsumerInBFCache",
        array_kFieldTrialConfig_experiments_4,
    },
    {
        "AudioOffload",
        array_kFieldTrialConfig_experiments_5,
    },
    {
        "AutoDisableAccessibility",
        array_kFieldTrialConfig_experiments_6,
    },
    {
        "AutoSpeculationRules",
        array_kFieldTrialConfig_experiments_7,
    },
    {
        "AutofillAddressUserPerceptionSurveyUS",
        array_kFieldTrialConfig_experiments_8,
    },
    {
        "AutofillAiTeamfood",
        array_kFieldTrialConfig_experiments_9,
    },
    {
        "AutofillCreditCardUserPerceptionSurvey",
        array_kFieldTrialConfig_experiments_10,
    },
    {
        "AutofillDecoupleAutofillCountFromCache",
        array_kFieldTrialConfig_experiments_11,
    },
    {
        "AutofillDisableLocalCardMigration",
        array_kFieldTrialConfig_experiments_12,
    },
    {
        "AutofillEnableAccountStorageForIneligibleCountries",
        array_kFieldTrialConfig_experiments_13,
    },
    {
        "AutofillEnableCardBenefitsForAmericanExpress",
        array_kFieldTrialConfig_experiments_14,
    },
    {
        "AutofillEnableCardBenefitsForCapitalOne",
        array_kFieldTrialConfig_experiments_15,
    },
    {
        "AutofillEnableCardBenefitsIph",
        array_kFieldTrialConfig_experiments_16,
    },
    {
        "AutofillEnableCvcStorage",
        array_kFieldTrialConfig_experiments_17,
    },
    {
        "AutofillEnableExpirationDateImprovements",
        array_kFieldTrialConfig_experiments_18,
    },
    {
        "AutofillEnableFillingPhoneCountryCodesByAddressCountryCodes",
        array_kFieldTrialConfig_experiments_19,
    },
    {
        "AutofillEnableFpanRiskBasedAuthentication",
        array_kFieldTrialConfig_experiments_20,
    },
    {
        "AutofillEnableLabelPrecedenceForTurkishAddresses",
        array_kFieldTrialConfig_experiments_21,
    },
    {
        "AutofillEnableLoadingAndConfirmation",
        array_kFieldTrialConfig_experiments_22,
    },
    {
        "AutofillEnableLogFormEventsToAllParsedFormTypes",
        array_kFieldTrialConfig_experiments_23,
    },
    {
        "AutofillEnableNewCardProfileRankingAlgorithm",
        array_kFieldTrialConfig_experiments_24,
    },
    {
        "AutofillEnableNewSaveCardBubbleUi",
        array_kFieldTrialConfig_experiments_25,
    },
    {
        "AutofillEnablePaymentsFieldSwapping",
        array_kFieldTrialConfig_experiments_26,
    },
    {
        "AutofillEnableServerIban",
        array_kFieldTrialConfig_experiments_27,
    },
    {
        "AutofillEnableSupportForParsingWithSharedLabels",
        array_kFieldTrialConfig_experiments_28,
    },
    {
        "AutofillEnableVcnGrayOutForMerchantOptOut",
        array_kFieldTrialConfig_experiments_29,
    },
    {
        "AutofillEnableVirtualCardOnFile",
        array_kFieldTrialConfig_experiments_30,
    },
    {
        "AutofillFixCachingOnJavaScriptChanges",
        array_kFieldTrialConfig_experiments_31,
    },
    {
        "AutofillFixValueSemantics",
        array_kFieldTrialConfig_experiments_32,
    },
    {
        "AutofillForUnclassifiedFieldsAvailable",
        array_kFieldTrialConfig_experiments_33,
    },
    {
        "AutofillGivePrecedenceToEmailOverUsername",
        array_kFieldTrialConfig_experiments_34,
    },
    {
        "AutofillGranularFillingAvailable",
        array_kFieldTrialConfig_experiments_35,
    },
    {
        "AutofillI18nAddressModelAndRegexesGEITPL",
        array_kFieldTrialConfig_experiments_36,
    },
    {
        "AutofillI18nAddressModelNewCountries",
        array_kFieldTrialConfig_experiments_37,
    },
    {
        "AutofillImportFromAutocompleteUnrecognized",
        array_kFieldTrialConfig_experiments_38,
    },
    {
        "AutofillImproveSubmissionDetectionV2",
        array_kFieldTrialConfig_experiments_39,
    },
    {
        "AutofillInferLabelFromDefaultSelectText",
        array_kFieldTrialConfig_experiments_40,
    },
    {
        "AutofillLogDeduplicationMetrics",
        array_kFieldTrialConfig_experiments_41,
    },
    {
        "AutofillLogUKMEventsWithSampleRate",
        array_kFieldTrialConfig_experiments_42,
    },
    {
        "AutofillModelPredictions",
        array_kFieldTrialConfig_experiments_43,
    },
    {
        "AutofillPageLanguageDetection",
        array_kFieldTrialConfig_experiments_44,
    },
    {
        "AutofillParseEmailLabelAndPlaceholder",
        array_kFieldTrialConfig_experiments_45,
    },
    {
        "AutofillPasswordUserPerceptionSurvey",
        array_kFieldTrialConfig_experiments_46,
    },
    {
        "AutofillPopupDontAcceptNonVisibleEnoughSuggestion",
        array_kFieldTrialConfig_experiments_47,
    },
    {
        "AutofillPopupZOrderSecuritySurface_V2",
        array_kFieldTrialConfig_experiments_48,
    },
    {
        "AutofillPreFilledFieldsCorrectly",
        array_kFieldTrialConfig_experiments_49,
    },
    {
        "AutofillSharedStorageServerCardData",
        array_kFieldTrialConfig_experiments_50,
    },
    {
        "AutofillStructuredFieldsDisableAddressLines",
        array_kFieldTrialConfig_experiments_51,
    },
    {
        "AutofillSurveys",
        array_kFieldTrialConfig_experiments_52,
    },
    {
        "AutofillUKMExperimentalFields",
        array_kFieldTrialConfig_experiments_53,
    },
    {
        "AutofillUnmaskCardRequestTimeout",
        array_kFieldTrialConfig_experiments_54,
    },
    {
        "AutofillUploadCardRequestTimeout",
        array_kFieldTrialConfig_experiments_55,
    },
    {
        "AutofillUpstream",
        array_kFieldTrialConfig_experiments_56,
    },
    {
        "AutofillUpstreamUpdatedUi",
        array_kFieldTrialConfig_experiments_57,
    },
    {
        "AutofillVcnEnrollRequestTimeout",
        array_kFieldTrialConfig_experiments_58,
    },
    {
        "AvoidEntryCreationForNoStore",
        array_kFieldTrialConfig_experiments_59,
    },
    {
        "AvoidLoadingPredictorPrefetchDuringBrowserStartup",
        array_kFieldTrialConfig_experiments_60,
    },
    {
        "AvoidUnnecessaryForcedLayoutMeasurements",
        array_kFieldTrialConfig_experiments_61,
    },
    {
        "BackForwardCacheBroadcastChannel",
        array_kFieldTrialConfig_experiments_62,
    },
    {
        "BackForwardCacheCaptureBlockingDetails",
        array_kFieldTrialConfig_experiments_63,
    },
    {
        "BackForwardCacheForPageWithCacheControlNotStoredHeader",
        array_kFieldTrialConfig_experiments_64,
    },
    {
        "BackForwardCacheMediaSessionService",
        array_kFieldTrialConfig_experiments_65,
    },
    {
        "BackForwardCacheNotRestoredReasons",
        array_kFieldTrialConfig_experiments_66,
    },
    {
        "BackForwardCacheSensors",
        array_kFieldTrialConfig_experiments_67,
    },
    {
        "BackNavigationMenuIPH",
        array_kFieldTrialConfig_experiments_68,
    },
    {
        "BackgroundResourceFetch",
        array_kFieldTrialConfig_experiments_69,
    },
    {
        "BackgroundTabLoadingFromPerformanceManager",
        array_kFieldTrialConfig_experiments_70,
    },
    {
        "BatchUploadDesktop",
        array_kFieldTrialConfig_experiments_71,
    },
    {
        "BatterySaverModeAlignWakeUps",
        array_kFieldTrialConfig_experiments_72,
    },
    {
        "BlockAcceptClientHints",
        array_kFieldTrialConfig_experiments_73,
    },
    {
        "BoostRenderProcessForLoading",
        array_kFieldTrialConfig_experiments_74,
    },
    {
        "BoundaryEventDispatchTracksNodeRemoval",
        array_kFieldTrialConfig_experiments_75,
    },
    {
        "BrowserThreadPoolAdjustmentForDesktop",
        array_kFieldTrialConfig_experiments_76,
    },
    {
        "BubbleMetricsApi",
        array_kFieldTrialConfig_experiments_77,
    },
    {
        "BufferSizeForFilterSourceStream",
        array_kFieldTrialConfig_experiments_78,
    },
    {
        "CPSS-V3",
        array_kFieldTrialConfig_experiments_79,
    },
    {
        "CSSDisplayAnimation",
        array_kFieldTrialConfig_experiments_80,
    },
    {
        "CSSLazyParsingFastPath",
        array_kFieldTrialConfig_experiments_81,
    },
    {
        "CacheStorageTaskPriority",
        array_kFieldTrialConfig_experiments_82,
    },
    {
        "CameraMicPreview",
        array_kFieldTrialConfig_experiments_83,
    },
    {
        "Canvas2DAutoFlushParams",
        array_kFieldTrialConfig_experiments_84,
    },
    {
        "Canvas2DReclaimUnusedResources",
        array_kFieldTrialConfig_experiments_85,
    },
    {
        "CanvasHibernationExperiments",
        array_kFieldTrialConfig_experiments_86,
    },
    {
        "CanvasHibernationSnapshotZstd",
        array_kFieldTrialConfig_experiments_87,
    },
    {
        "CastCertificateRevocation",
        array_kFieldTrialConfig_experiments_88,
    },
    {
        "CastStreamingVp9",
        array_kFieldTrialConfig_experiments_89,
    },
    {
        "CastStreamingWinHardwareH264",
        array_kFieldTrialConfig_experiments_90,
    },
    {
        "CatanCombinedHoldback23H2",
        array_kFieldTrialConfig_experiments_91,
    },
    {
        "CbdTimeframeRequired",
        array_kFieldTrialConfig_experiments_92,
    },
    {
        "CdmStorageDatabaseDefaultTrial",
        array_kFieldTrialConfig_experiments_93,
    },
    {
        "ChangeDiskCacheSize",
        array_kFieldTrialConfig_experiments_94,
    },
    {
        "ChangeFrameRateOfLoadingTabAnimation",
        array_kFieldTrialConfig_experiments_95,
    },
    {
        "CheckHTMLParserBudgetLessOften",
        array_kFieldTrialConfig_experiments_96,
    },
    {
        "ChromeCartDomBasedHeuristics",
        array_kFieldTrialConfig_experiments_97,
    },
    {
        "ChromeCompose",
        array_kFieldTrialConfig_experiments_98,
    },
    {
        "ChromeLabs",
        array_kFieldTrialConfig_experiments_99,
    },
    {
        "ChromeWallpaperSearchGlobal",
        array_kFieldTrialConfig_experiments_100,
    },
    {
        "ChromeWallpaperSearchHaTS",
        array_kFieldTrialConfig_experiments_101,
    },
    {
        "ChromeWallpaperSearchLaunch",
        array_kFieldTrialConfig_experiments_102,
    },
    {
        "ChromeWideEchoCancellation",
        array_kFieldTrialConfig_experiments_103,
    },
    {
        "ChromnientFetchSrp",
        array_kFieldTrialConfig_experiments_104,
    },
    {
        "ChromnientIPH",
        array_kFieldTrialConfig_experiments_105,
    },
    {
        "ChromnientImageContextMenuActions",
        array_kFieldTrialConfig_experiments_106,
    },
    {
        "ChromnientLatencyOptimizations",
        array_kFieldTrialConfig_experiments_107,
    },
    {
        "ChromnientMoreTranslateLanguages",
        array_kFieldTrialConfig_experiments_108,
    },
    {
        "ChromnientPostLaunchTranslate",
        array_kFieldTrialConfig_experiments_109,
    },
    {
        "ChromnientSurvey",
        array_kFieldTrialConfig_experiments_110,
    },
    {
        "ClassifyUrlOnProcessResponseEventLinuxMacAndWindows",
        array_kFieldTrialConfig_experiments_111,
    },
    {
        "ClearGrShaderDiskCacheOnInvalidPrefix",
        array_kFieldTrialConfig_experiments_112,
    },
    {
        "ClearUndecryptablePasswords",
        array_kFieldTrialConfig_experiments_113,
    },
    {
        "ClientSideDetectionAcceptHCAllowlist",
        array_kFieldTrialConfig_experiments_114,
    },
    {
        "ClientSideDetectionRetryLimit",
        array_kFieldTrialConfig_experiments_115,
    },
    {
        "ClientSideDetectionSamplePing",
        array_kFieldTrialConfig_experiments_116,
    },
    {
        "CloneDevToolsConnectionOnlyIfRequested",
        array_kFieldTrialConfig_experiments_117,
    },
    {
        "CoalesceSelectionchangeEvent",
        array_kFieldTrialConfig_experiments_118,
    },
    {
        "CodeBasedRBD",
        array_kFieldTrialConfig_experiments_119,
    },
    {
        "CommerceLocalPDPDetection",
        array_kFieldTrialConfig_experiments_120,
    },
    {
        "CommercePriceInsights",
        array_kFieldTrialConfig_experiments_121,
    },
    {
        "Compare",
        array_kFieldTrialConfig_experiments_122,
    },
    {
        "ComposeAXSnapshot",
        array_kFieldTrialConfig_experiments_123,
    },
    {
        "ComposeAcceptanceSurvey",
        array_kFieldTrialConfig_experiments_124,
    },
    {
        "ComposeCloseSurvey",
        array_kFieldTrialConfig_experiments_125,
    },
    {
        "ComposeModelQualityLogging",
        array_kFieldTrialConfig_experiments_126,
    },
    {
        "ComposeOnDeviceModel",
        array_kFieldTrialConfig_experiments_127,
    },
    {
        "ComposeProactiveNudgePosition",
        array_kFieldTrialConfig_experiments_128,
    },
    {
        "ComposeUpfrontInputModes",
        array_kFieldTrialConfig_experiments_129,
    },
    {
        "CompositeBackgroundColorAnimation",
        array_kFieldTrialConfig_experiments_130,
    },
    {
        "CompositeClipPathAnimation",
        array_kFieldTrialConfig_experiments_131,
    },
    {
        "CompressionDictionaryPreload",
        array_kFieldTrialConfig_experiments_132,
    },
    {
        "CompressionDictionaryTransportRequireKnownRootCert",
        array_kFieldTrialConfig_experiments_133,
    },
    {
        "ConcurrentViewTransitionsSPA",
        array_kFieldTrialConfig_experiments_134,
    },
    {
        "ConditionalImageResize",
        array_kFieldTrialConfig_experiments_135,
    },
    {
        "ConfigurableV8CodeCacheHotHours",
        array_kFieldTrialConfig_experiments_136,
    },
    {
        "ContextualSearchBox",
        array_kFieldTrialConfig_experiments_137,
    },
    {
        "CookieDeprecationFacilitatedTestingCookieDeprecation",
        array_kFieldTrialConfig_experiments_138,
    },
    {
        "CookieDeprecationFacilitatedTestingFledgeTrustedSignalsHeaders",
        array_kFieldTrialConfig_experiments_139,
    },
    {
        "CookieSameSiteConsidersRedirectChainDesktop",
        array_kFieldTrialConfig_experiments_140,
    },
    {
        "CustomizeChromeSidePanelExtensionsCard",
        array_kFieldTrialConfig_experiments_141,
    },
    {
        "D3D11Vp9kSVCHWDecoding",
        array_kFieldTrialConfig_experiments_142,
    },
    {
        "DIPSOnHTTPCache",
        array_kFieldTrialConfig_experiments_143,
    },
    {
        "DOMParserIncludeShadowRoots",
        array_kFieldTrialConfig_experiments_144,
    },
    {
        "DOMStorageReliabilityEnhancements",
        array_kFieldTrialConfig_experiments_145,
    },
    {
        "DXGIWaitableSwapChain",
        array_kFieldTrialConfig_experiments_146,
    },
    {
        "DataControlsScreenshotProtection",
        array_kFieldTrialConfig_experiments_147,
    },
    {
        "DataMaskingReportingAPI",
        array_kFieldTrialConfig_experiments_148,
    },
    {
        "DbscPhase1aStudy",
        array_kFieldTrialConfig_experiments_149,
    },
    {
        "DecodedImageWorkingSetBudget",
        array_kFieldTrialConfig_experiments_150,
    },
    {
        "DecommitPooledPages",
        array_kFieldTrialConfig_experiments_151,
    },
    {
        "DedicatedMediaServiceThread",
        array_kFieldTrialConfig_experiments_152,
    },
    {
        "DefaultGpuDiskCacheSize",
        array_kFieldTrialConfig_experiments_153,
    },
    {
        "DefaultOpenSSLBufferSizeFeature",
        array_kFieldTrialConfig_experiments_154,
    },
    {
        "DeferRendererTasksAfterInput",
        array_kFieldTrialConfig_experiments_155,
    },
    {
        "DeferSpeculativeRFHCreation",
        array_kFieldTrialConfig_experiments_156,
    },
    {
        "DeferredSparerRendererForTopChromeWebUI",
        array_kFieldTrialConfig_experiments_157,
    },
    {
        "DelayablePriorityThreshold",
        array_kFieldTrialConfig_experiments_158,
    },
    {
        "DelegatedCompositingOnWindows",
        array_kFieldTrialConfig_experiments_159,
    },
    {
        "DeprecateUnload",
        array_kFieldTrialConfig_experiments_160,
    },
    {
        "DesktopNtpDriveCache",
        array_kFieldTrialConfig_experiments_161,
    },
    {
        "DesktopNtpImageErrorDetection",
        array_kFieldTrialConfig_experiments_162,
    },
    {
        "DesktopNtpMiddleSlotPromoDismissal",
        array_kFieldTrialConfig_experiments_163,
    },
    {
        "DesktopNtpMobilePromo",
        array_kFieldTrialConfig_experiments_164,
    },
    {
        "DesktopNtpModules",
        array_kFieldTrialConfig_experiments_165,
    },
    {
        "DesktopNtpTabResumption",
        array_kFieldTrialConfig_experiments_166,
    },
    {
        "DesktopOmniboxCalculatorProvider",
        array_kFieldTrialConfig_experiments_167,
    },
    {
        "DesktopOmniboxKeywordProvider",
        array_kFieldTrialConfig_experiments_168,
    },
    {
        "DesktopOmniboxShortcutBoost",
        array_kFieldTrialConfig_experiments_169,
    },
    {
        "DesktopOmniboxStarterPackExpansion",
        array_kFieldTrialConfig_experiments_170,
    },
    {
        "DesktopOmnibox_HistoryQuickProviderSpecificity",
        array_kFieldTrialConfig_experiments_171,
    },
    {
        "DesktopPWAInstallPromotionML",
        array_kFieldTrialConfig_experiments_172,
    },
    {
        "DesktopReEngagement",
        array_kFieldTrialConfig_experiments_173,
    },
    {
        "DesktopWebAppUniversalInstallExperiment",
        array_kFieldTrialConfig_experiments_174,
    },
    {
        "DestroySystemProfiles",
        array_kFieldTrialConfig_experiments_175,
    },
    {
        "DetailsStyling",
        array_kFieldTrialConfig_experiments_176,
    },
    {
        "DevToolsAiAssistanceFileAgentDogfood",
        array_kFieldTrialConfig_experiments_177,
    },
    {
        "DevToolsAiAssistancePerformanceAgentDogfood",
        array_kFieldTrialConfig_experiments_178,
    },
    {
        "DevToolsExplainThisResourceDogfood",
        array_kFieldTrialConfig_experiments_179,
    },
    {
        "DipsOnForegroundSequence",
        array_kFieldTrialConfig_experiments_180,
    },
    {
        "DisableGles2ForOopR",
        array_kFieldTrialConfig_experiments_181,
    },
    {
        "DisableUrgentPageDiscarding",
        array_kFieldTrialConfig_experiments_182,
    },
    {
        "DisallowManagedProfileSignout",
        array_kFieldTrialConfig_experiments_183,
    },
    {
        "DiscardFrozenBrowsingInstancesWithGrowingPMF",
        array_kFieldTrialConfig_experiments_184,
    },
    {
        "DiscardInputEventsToRecentlyMovedFrames",
        array_kFieldTrialConfig_experiments_185,
    },
    {
        "DiscountAutoPopup",
        array_kFieldTrialConfig_experiments_186,
    },
    {
        "DiscountConsentV2",
        array_kFieldTrialConfig_experiments_187,
    },
    {
        "DiskCacheBackendExperiment",
        array_kFieldTrialConfig_experiments_188,
    },
    {
        "DlpRegionalizedEndpoints",
        array_kFieldTrialConfig_experiments_189,
    },
    {
        "DnsHttpsSvcbTimeout",
        array_kFieldTrialConfig_experiments_190,
    },
    {
        "DoNotEvictOnAXLocationChange",
        array_kFieldTrialConfig_experiments_191,
    },
    {
        "DontAlwaysPushPictureLayerImpls",
        array_kFieldTrialConfig_experiments_192,
    },
    {
        "DownloadWarningSurvey",
        array_kFieldTrialConfig_experiments_193,
    },
    {
        "EagerPrefetchBlockUntilHeadDifferentTimeoutsRetrospective",
        array_kFieldTrialConfig_experiments_194,
    },
    {
        "ElementGetInnerHTML",
        array_kFieldTrialConfig_experiments_195,
    },
    {
        "EnableBackForwardCacheForOngoingSubframeNavigation",
        array_kFieldTrialConfig_experiments_196,
    },
    {
        "EnableCertManagementUIV2Write",
        array_kFieldTrialConfig_experiments_197,
    },
    {
        "EnableConfigurableThreadCacheMultiplier",
        array_kFieldTrialConfig_experiments_198,
    },
    {
        "EnableDiscountOnShoppyPagesDesktop",
        array_kFieldTrialConfig_experiments_199,
    },
    {
        "EnableFallbackFontsCrashReporting",
        array_kFieldTrialConfig_experiments_200,
    },
    {
        "EnableImmediateDrawDuringScrollInteraction",
        array_kFieldTrialConfig_experiments_201,
    },
    {
        "EnableOverwritingPlaceholderUsernames",
        array_kFieldTrialConfig_experiments_202,
    },
    {
        "EnablePDPMetricsUSDesktopIOS",
        array_kFieldTrialConfig_experiments_203,
    },
    {
        "EnableTcpPortRandomization",
        array_kFieldTrialConfig_experiments_204,
    },
    {
        "EnterprisePasswordReuseUiRefresh",
        array_kFieldTrialConfig_experiments_205,
    },
    {
        "EsbAiStringUpdate",
        array_kFieldTrialConfig_experiments_206,
    },
    {
        "EscapeLtGtInAttributes",
        array_kFieldTrialConfig_experiments_207,
    },
    {
        "EventTimingSelectionAutoScrollNoInteractionId",
        array_kFieldTrialConfig_experiments_208,
    },
    {
        "EvictionThrottlesDraw",
        array_kFieldTrialConfig_experiments_209,
    },
    {
        "ExpandCompositedCullRect",
        array_kFieldTrialConfig_experiments_210,
    },
    {
        "ExtendedReportingRemovePrefDependency",
        array_kFieldTrialConfig_experiments_211,
    },
    {
        "ExtensionManifestV2Deprecation",
        array_kFieldTrialConfig_experiments_212,
    },
    {
        "ExtensionsServiceWorkerOptimizedEventDispatch",
        array_kFieldTrialConfig_experiments_213,
    },
    {
        "ExternalBeginFrameSourceWinUsesRunOrPostTask",
        array_kFieldTrialConfig_experiments_214,
    },
    {
        "ExtremeLightweightUAFDetector",
        array_kFieldTrialConfig_experiments_215,
    },
    {
        "FLEDGEBiddingAndAuctionServer",
        array_kFieldTrialConfig_experiments_216,
    },
    {
        "FencedFramesEnableCredentialsForAutomaticBeacons",
        array_kFieldTrialConfig_experiments_217,
    },
    {
        "FencedFramesEnableReportEventHeaderChanges",
        array_kFieldTrialConfig_experiments_218,
    },
    {
        "FencedFramesEnableSrcPermissionsPolicy",
        array_kFieldTrialConfig_experiments_219,
    },
    {
        "FenderAutoPreconnectLcpOrigins",
        array_kFieldTrialConfig_experiments_220,
    },
    {
        "FetchLaterAPI",
        array_kFieldTrialConfig_experiments_221,
    },
    {
        "FindRegistrationImprovements",
        array_kFieldTrialConfig_experiments_222,
    },
    {
        "FingerprintingProtectionFilter",
        array_kFieldTrialConfig_experiments_223,
    },
    {
        "FlushPersistentSystemProfileOnWrite",
        array_kFieldTrialConfig_experiments_224,
    },
    {
        "FontationsFontBackend",
        array_kFieldTrialConfig_experiments_225,
    },
    {
        "FormControlsVerticalWritingModeDirectionSupport",
        array_kFieldTrialConfig_experiments_226,
    },
    {
        "FrameRoutingCache",
        array_kFieldTrialConfig_experiments_227,
    },
    {
        "FreezingOnBatterySaver",
        array_kFieldTrialConfig_experiments_228,
    },
    {
        "FreezingOnBatterySaverTweaks",
        array_kFieldTrialConfig_experiments_229,
    },
    {
        "GenGpuDiskCacheKeyPrefixInGpuService",
        array_kFieldTrialConfig_experiments_230,
    },
    {
        "GlobalMediaControlsUpdatedUI",
        array_kFieldTrialConfig_experiments_231,
    },
    {
        "GoogleLensDesktopContentMenuTranslate",
        array_kFieldTrialConfig_experiments_232,
    },
    {
        "GoogleLensDesktopImageFormatOptimizations",
        array_kFieldTrialConfig_experiments_233,
    },
    {
        "GpuYieldRasterization",
        array_kFieldTrialConfig_experiments_234,
    },
    {
        "GrCacheLimits",
        array_kFieldTrialConfig_experiments_235,
    },
    {
        "GroupedHistoryAllLocales",
        array_kFieldTrialConfig_experiments_236,
    },
    {
        "HTTP2",
        array_kFieldTrialConfig_experiments_237,
    },
    {
        "HangoutsExtensionV3",
        array_kFieldTrialConfig_experiments_238,
    },
    {
        "HistoryEmbeddings",
        array_kFieldTrialConfig_experiments_239,
    },
    {
        "HttpDiskCachePrewarming",
        array_kFieldTrialConfig_experiments_240,
    },
    {
        "HttpsFirstBalancedModeAutoEnable",
        array_kFieldTrialConfig_experiments_241,
    },
    {
        "HttpsFirstModeV2ForEngagedSites",
        array_kFieldTrialConfig_experiments_242,
    },
    {
        "HttpsFirstModeV2ForTypicallySecureUsers",
        array_kFieldTrialConfig_experiments_243,
    },
    {
        "IOSAcquisitionOnDesktopPromo",
        array_kFieldTrialConfig_experiments_244,
    },
    {
        "IPProtectionPhase0",
        array_kFieldTrialConfig_experiments_245,
    },
    {
        "IdbExpediteBackendProcessingForForegroundClients",
        array_kFieldTrialConfig_experiments_246,
    },
    {
        "IdbPrioritizeForegroundClients",
        array_kFieldTrialConfig_experiments_247,
    },
    {
        "IgnoreDuplicateNavs",
        array_kFieldTrialConfig_experiments_248,
    },
    {
        "ImageDescriptionsAlternativeRouting",
        array_kFieldTrialConfig_experiments_249,
    },
    {
        "ImprovedSemanticsActivityIndicators",
        array_kFieldTrialConfig_experiments_250,
    },
    {
        "IncreaseCoookieAccesCacheSize",
        array_kFieldTrialConfig_experiments_251,
    },
    {
        "IncreasedCmdBufferParseSlice",
        array_kFieldTrialConfig_experiments_252,
    },
    {
        "InvalidationsWithDirectMessagesPerPlatform",
        array_kFieldTrialConfig_experiments_253,
    },
    {
        "JourneysOnDeviceClusteringContentClustering",
        array_kFieldTrialConfig_experiments_254,
    },
    {
        "KeepAliveInBrowserMigration",
        array_kFieldTrialConfig_experiments_255,
    },
    {
        "KeyboardAndPointerLockPrompt",
        array_kFieldTrialConfig_experiments_256,
    },
    {
        "KeyboardFocusableScrollers",
        array_kFieldTrialConfig_experiments_257,
    },
    {
        "KidsProfilePhase2",
        array_kFieldTrialConfig_experiments_258,
    },
    {
        "LCPPDeferUnusedPreload",
        array_kFieldTrialConfig_experiments_259,
    },
    {
        "LCPPFontURLPredictor",
        array_kFieldTrialConfig_experiments_260,
    },
    {
        "LCPPImageLoadingPriority",
        array_kFieldTrialConfig_experiments_261,
    },
    {
        "LCPPLazyLoadImagePreload",
        array_kFieldTrialConfig_experiments_262,
    },
    {
        "LCPPMultipleKey",
        array_kFieldTrialConfig_experiments_263,
    },
    {
        "LCPPPrefetchSubresource",
        array_kFieldTrialConfig_experiments_264,
    },
    {
        "LCPTimingPredictorPrerender2",
        array_kFieldTrialConfig_experiments_265,
    },
    {
        "LayoutNGShapeCache",
        array_kFieldTrialConfig_experiments_266,
    },
    {
        "LazyBlinkTimezoneInit",
        array_kFieldTrialConfig_experiments_267,
    },
    {
        "LazyUpdateTranslateModel",
        array_kFieldTrialConfig_experiments_268,
    },
    {
        "LeakSkiaEventTracerAtExit",
        array_kFieldTrialConfig_experiments_269,
    },
    {
        "LightweightUAFDetector",
        array_kFieldTrialConfig_experiments_270,
    },
    {
        "LinkPreview",
        array_kFieldTrialConfig_experiments_271,
    },
    {
        "LinkedServicesSetting",
        array_kFieldTrialConfig_experiments_272,
    },
    {
        "LiveCaptionExperimentalLanguages",
        array_kFieldTrialConfig_experiments_273,
    },
    {
        "LiveCaptionMultiLanguageRollout",
        array_kFieldTrialConfig_experiments_274,
    },
    {
        "LoadingPhaseBufferTimeAfterFirstMeaningfulPaint",
        array_kFieldTrialConfig_experiments_275,
    },
    {
        "LoadingPredictorLimitPreconnectSocketCount",
        array_kFieldTrialConfig_experiments_276,
    },
    {
        "LocalStateEnterprisePasswordHashes",
        array_kFieldTrialConfig_experiments_277,
    },
    {
        "LogOnDeviceMetricsOnStartup",
        array_kFieldTrialConfig_experiments_278,
    },
    {
        "LowPriorityAsyncScriptExecution",
        array_kFieldTrialConfig_experiments_279,
    },
    {
        "MHTML_Improvements",
        array_kFieldTrialConfig_experiments_280,
    },
    {
        "MainNodeAnnotationsRollout",
        array_kFieldTrialConfig_experiments_281,
    },
    {
        "MaxNumDelayableRequestsPerHostPerClient",
        array_kFieldTrialConfig_experiments_282,
    },
    {
        "MediaDeviceIdStoragePartitioning",
        array_kFieldTrialConfig_experiments_283,
    },
    {
        "MediaFoundationAV1Encoding",
        array_kFieldTrialConfig_experiments_284,
    },
    {
        "MediaFoundationBatchRead",
        array_kFieldTrialConfig_experiments_285,
    },
    {
        "MediaFoundationCameraUsageMonitoring",
        array_kFieldTrialConfig_experiments_286,
    },
    {
        "MediaFoundationVP9Encoding",
        array_kFieldTrialConfig_experiments_287,
    },
    {
        "MediaHardwareSecureDecryption",
        array_kFieldTrialConfig_experiments_288,
    },
    {
        "MediaHardwareSecureDecryptionFallbackPerSite",
        array_kFieldTrialConfig_experiments_289,
    },
    {
        "MediaRecorderUseMediaVideoEncoder",
        array_kFieldTrialConfig_experiments_290,
    },
    {
        "MemoryCacheStrongReference",
        array_kFieldTrialConfig_experiments_291,
    },
    {
        "MemoryPurgeInBackground",
        array_kFieldTrialConfig_experiments_292,
    },
    {
        "MetricsLogTrimming",
        array_kFieldTrialConfig_experiments_293,
    },
    {
        "MetricsServiceDeltaSnapshotInBg",
        array_kFieldTrialConfig_experiments_294,
    },
    {
        "MigrateDefaultChromeAppToWebAppsGSuite",
        array_kFieldTrialConfig_experiments_295,
    },
    {
        "MigrateDefaultChromeAppToWebAppsNonGSuite",
        array_kFieldTrialConfig_experiments_296,
    },
    {
        "MojoChannelAssociatedSendUsesRunOrPostTask",
        array_kFieldTrialConfig_experiments_297,
    },
    {
        "MojoInlineMessagePayloads",
        array_kFieldTrialConfig_experiments_298,
    },
    {
        "MojoLargerDataPipeAllocationSize",
        array_kFieldTrialConfig_experiments_299,
    },
    {
        "MojoPredictiveAllocation",
        array_kFieldTrialConfig_experiments_300,
    },
    {
        "MoveThemePrefsToSpecifics",
        array_kFieldTrialConfig_experiments_301,
    },
    {
        "MutationEvents",
        array_kFieldTrialConfig_experiments_302,
    },
    {
        "MutationEventsSpecialTrialMessage",
        array_kFieldTrialConfig_experiments_303,
    },
    {
        "NetAdapterMaxBufSize",
        array_kFieldTrialConfig_experiments_304,
    },
    {
        "NetworkQualityEstimatorParameterTuning",
        array_kFieldTrialConfig_experiments_305,
    },
    {
        "NetworkServiceSandboxWindows",
        array_kFieldTrialConfig_experiments_306,
    },
    {
        "NewContentForCheckerboardedScrolls",
        array_kFieldTrialConfig_experiments_307,
    },
    {
        "NewEvSignalsEnabled",
        array_kFieldTrialConfig_experiments_308,
    },
    {
        "NoPasswordSuggestionFiltering",
        array_kFieldTrialConfig_experiments_309,
    },
    {
        "NoPreReadMainDllIfSsd",
        array_kFieldTrialConfig_experiments_310,
    },
    {
        "NoThrottlingVisibleAgent",
        array_kFieldTrialConfig_experiments_311,
    },
    {
        "NonStandardAppearanceValueSliderVertical",
        array_kFieldTrialConfig_experiments_312,
    },
    {
        "NormalMaxItemsInCacheForSoftware",
        array_kFieldTrialConfig_experiments_313,
    },
    {
        "OcclusionCullingQuadSplitLimit",
        array_kFieldTrialConfig_experiments_314,
    },
    {
        "OidcAuthProfileManagement",
        array_kFieldTrialConfig_experiments_315,
    },
    {
        "OmitBlurEventOnElementRemoval",
        array_kFieldTrialConfig_experiments_316,
    },
    {
        "OmniboxBundledExperimentV1",
        array_kFieldTrialConfig_experiments_317,
    },
    {
        "OmniboxCr23M113Desktop",
        array_kFieldTrialConfig_experiments_318,
    },
    {
        "OmniboxDeleteOldShortcuts",
        array_kFieldTrialConfig_experiments_319,
    },
    {
        "OmniboxFeaturedEnterpriseSiteSearch",
        array_kFieldTrialConfig_experiments_320,
    },
    {
        "OmniboxLogURLScoringSignals",
        array_kFieldTrialConfig_experiments_321,
    },
    {
        "OmniboxMlUrlPiecewiseMappedScoringDesktop",
        array_kFieldTrialConfig_experiments_322,
    },
    {
        "OmniboxOnDeviceHeadModelSelectionFix",
        array_kFieldTrialConfig_experiments_323,
    },
    {
        "OmniboxOnDeviceTailSuggest",
        array_kFieldTrialConfig_experiments_324,
    },
    {
        "OmniboxRelaxedDriveRequirements",
        array_kFieldTrialConfig_experiments_325,
    },
    {
        "OmniboxStarterPackIPH",
        array_kFieldTrialConfig_experiments_326,
    },
    {
        "OneCopyLegacyMPVideoFrameUploadViaSI",
        array_kFieldTrialConfig_experiments_327,
    },
    {
        "OneTimePermission",
        array_kFieldTrialConfig_experiments_328,
    },
    {
        "OptGuideBatchSRPTuning",
        array_kFieldTrialConfig_experiments_329,
    },
    {
        "OptGuideURLCacheSize",
        array_kFieldTrialConfig_experiments_330,
    },
    {
        "OutOfProcessPrintDriversPrint",
        array_kFieldTrialConfig_experiments_331,
    },
    {
        "PMProcessPriorityPolicy",
        array_kFieldTrialConfig_experiments_332,
    },
    {
        "PWAIconAndTitleInNativeNotificationsWin",
        array_kFieldTrialConfig_experiments_333,
    },
    {
        "PWANavigationCapturingV2WindowMacLinux",
        array_kFieldTrialConfig_experiments_334,
    },
    {
        "PageAllocatorRetryOnCommitFailure",
        array_kFieldTrialConfig_experiments_335,
    },
    {
        "PageInfoAboutThisSite40Langs",
        array_kFieldTrialConfig_experiments_336,
    },
    {
        "PaintHoldingOOPIF",
        array_kFieldTrialConfig_experiments_337,
    },
    {
        "ParkableImages",
        array_kFieldTrialConfig_experiments_338,
    },
    {
        "ParkableStringsLessAggressiveAndZstd",
        array_kFieldTrialConfig_experiments_339,
    },
    {
        "PartialPageZeroing",
        array_kFieldTrialConfig_experiments_340,
    },
    {
        "PartitionAllocAdvancedMemorySafetyChecks",
        array_kFieldTrialConfig_experiments_341,
    },
    {
        "PartitionAllocBackupRefPtr",
        array_kFieldTrialConfig_experiments_342,
    },
    {
        "PartitionAllocLargeThreadCacheSizeDesktop",
        array_kFieldTrialConfig_experiments_343,
    },
    {
        "PartitionAllocMemoryReclaimer",
        array_kFieldTrialConfig_experiments_344,
    },
    {
        "PartitionAllocParameterTuning",
        array_kFieldTrialConfig_experiments_345,
    },
    {
        "PartitionAllocShortMemoryReclaim",
        array_kFieldTrialConfig_experiments_346,
    },
    {
        "PartitionAllocUnretainedDanglingPtr",
        array_kFieldTrialConfig_experiments_347,
    },
    {
        "PartitionAllocUsePoolOffsetFreelists",
        array_kFieldTrialConfig_experiments_348,
    },
    {
        "PartitionAllocUseSmallSingleSlotSpans",
        array_kFieldTrialConfig_experiments_349,
    },
    {
        "PartitionNetworkStateByNetworkAnonymizationKey",
        array_kFieldTrialConfig_experiments_350,
    },
    {
        "PartitionVisitedLinkDatabaseWithSelfLinks",
        array_kFieldTrialConfig_experiments_351,
    },
    {
        "PassHistogramSharedMemoryOnLaunch",
        array_kFieldTrialConfig_experiments_352,
    },
    {
        "PasswordManualFallbackAvailable",
        array_kFieldTrialConfig_experiments_353,
    },
    {
        "Path2DPaintCache",
        array_kFieldTrialConfig_experiments_354,
    },
    {
        "PdfCr23",
        array_kFieldTrialConfig_experiments_355,
    },
    {
        "PdfOutOfProcessIframe",
        array_kFieldTrialConfig_experiments_356,
    },
    {
        "PdfSearchify",
        array_kFieldTrialConfig_experiments_357,
    },
    {
        "PdfUseSkiaRenderer",
        array_kFieldTrialConfig_experiments_358,
    },
    {
        "PerfCombined2024",
        array_kFieldTrialConfig_experiments_359,
    },
    {
        "PerformanceControlsHatsStudy",
        array_kFieldTrialConfig_experiments_360,
    },
    {
        "PerformanceInterventionUILaunch",
        array_kFieldTrialConfig_experiments_361,
    },
    {
        "PermissionElementPromptPositioning",
        array_kFieldTrialConfig_experiments_362,
    },
    {
        "PermissionsPEPCHaTS",
        array_kFieldTrialConfig_experiments_363,
    },
    {
        "PlusAddressesExperiment",
        array_kFieldTrialConfig_experiments_364,
    },
    {
        "PlzDedicatedWorker",
        array_kFieldTrialConfig_experiments_365,
    },
    {
        "PolicyBlocklistProceedUntilResponse",
        array_kFieldTrialConfig_experiments_366,
    },
    {
        "PowerBookmarkBackend",
        array_kFieldTrialConfig_experiments_367,
    },
    {
        "PreReadDllBrowserProcess",
        array_kFieldTrialConfig_experiments_368,
    },
    {
        "PreconnectToSearchDesktop",
        array_kFieldTrialConfig_experiments_369,
    },
    {
        "PreconnectToSearchWithPrivacyModeEnabled",
        array_kFieldTrialConfig_experiments_370,
    },
    {
        "PrefetchDocumentManagerEarlyCookieCopySkipped",
        array_kFieldTrialConfig_experiments_371,
    },
    {
        "PrefetchNewWaitLoop",
        array_kFieldTrialConfig_experiments_372,
    },
    {
        "PrefetchProxyDesktop",
        array_kFieldTrialConfig_experiments_373,
    },
    {
        "PrefetchReusable",
        array_kFieldTrialConfig_experiments_374,
    },
    {
        "PreloadTopChromeWebUI",
        array_kFieldTrialConfig_experiments_375,
    },
    {
        "PreloadingHeuristicsMLModel",
        array_kFieldTrialConfig_experiments_376,
    },
    {
        "Prerender2BookmarkBarTriggerV2",
        array_kFieldTrialConfig_experiments_377,
    },
    {
        "Prerender2EarlyDocumentLifecycleUpdate",
        array_kFieldTrialConfig_experiments_378,
    },
    {
        "Prerender2EmbedderBlockedHosts",
        array_kFieldTrialConfig_experiments_379,
    },
    {
        "Prerender2FallbackPrefetchSpecRules",
        array_kFieldTrialConfig_experiments_380,
    },
    {
        "Prerender2NewTabPageTriggerV2",
        array_kFieldTrialConfig_experiments_381,
    },
    {
        "PreserveDiscardableImageMapQuality",
        array_kFieldTrialConfig_experiments_382,
    },
    {
        "PriceTrackingDesktopExpansionStudy",
        array_kFieldTrialConfig_experiments_383,
    },
    {
        "PriceTrackingIconColors",
        array_kFieldTrialConfig_experiments_384,
    },
    {
        "PriceTrackingPageActionIconLabelFeatureIPH",
        array_kFieldTrialConfig_experiments_385,
    },
    {
        "PrintWithPostScriptType42Fonts",
        array_kFieldTrialConfig_experiments_386,
    },
    {
        "PrintWithReducedRasterization",
        array_kFieldTrialConfig_experiments_387,
    },
    {
        "PrioritizeCompositingAfterDelay",
        array_kFieldTrialConfig_experiments_388,
    },
    {
        "PriorityHeader",
        array_kFieldTrialConfig_experiments_389,
    },
    {
        "PrivacySandboxAdsAPIs",
        array_kFieldTrialConfig_experiments_390,
    },
    {
        "PrivacySandboxAdsApiUxEnhancements",
        array_kFieldTrialConfig_experiments_391,
    },
    {
        "PrivacySandboxHatsForDesktopM1",
        array_kFieldTrialConfig_experiments_392,
    },
    {
        "PrivacySandboxInternalsDevUI",
        array_kFieldTrialConfig_experiments_393,
    },
    {
        "PrivacySandboxPrivacyGuideAdTopics",
        array_kFieldTrialConfig_experiments_394,
    },
    {
        "PrivacySandboxPrivacyPolicy",
        array_kFieldTrialConfig_experiments_395,
    },
    {
        "PrivacySandboxSentimentSurvey",
        array_kFieldTrialConfig_experiments_396,
    },
    {
        "PrivateAggregationApiFilteringIds",
        array_kFieldTrialConfig_experiments_397,
    },
    {
        "PrivateStateTokens",
        array_kFieldTrialConfig_experiments_398,
    },
    {
        "ProcessBoundStringEncryption",
        array_kFieldTrialConfig_experiments_399,
    },
    {
        "ProcessHtmlDataImmediately",
        array_kFieldTrialConfig_experiments_400,
    },
    {
        "ProcessIsolationForFencedFrames",
        array_kFieldTrialConfig_experiments_401,
    },
    {
        "ProcessPerSiteUpToMainFrameThreshold",
        array_kFieldTrialConfig_experiments_402,
    },
    {
        "ProfilesReordering",
        array_kFieldTrialConfig_experiments_403,
    },
    {
        "ProtectedAudienceDealsSupport",
        array_kFieldTrialConfig_experiments_404,
    },
    {
        "ProtectedAudienceEarlyProcessCreationStudy",
        array_kFieldTrialConfig_experiments_405,
    },
    {
        "ProtectedAudienceMorePAggMetrics",
        array_kFieldTrialConfig_experiments_406,
    },
    {
        "ProtectedAudienceMultiThreadedSellerWorklet",
        array_kFieldTrialConfig_experiments_407,
    },
    {
        "ProtectedAudienceNoWasmLazyCompilationStudy",
        array_kFieldTrialConfig_experiments_408,
    },
    {
        "ProtectedAudiencePreconnectCacheStudy",
        array_kFieldTrialConfig_experiments_409,
    },
    {
        "ProtectedAudienceTrustedKVSupport",
        array_kFieldTrialConfig_experiments_410,
    },
    {
        "ProtectedAudiencesHeaderDirectFromSellerSignalsStudy",
        array_kFieldTrialConfig_experiments_411,
    },
    {
        "ProtectedAudiencesKAnonymityEnforcementStudy",
        array_kFieldTrialConfig_experiments_412,
    },
    {
        "ProtectedAudiencesSellerNonce",
        array_kFieldTrialConfig_experiments_413,
    },
    {
        "ProtectedAudiencesUpdateIfOlderThanMs",
        array_kFieldTrialConfig_experiments_414,
    },
    {
        "PruneOldTransferCacheEntries",
        array_kFieldTrialConfig_experiments_415,
    },
    {
        "PsDualWritePrefsToNoticeStorage",
        array_kFieldTrialConfig_experiments_416,
    },
    {
        "PushMessagingDisallowSenderIDs",
        array_kFieldTrialConfig_experiments_417,
    },
    {
        "PushMessagingGcmEndpointEnvironment",
        array_kFieldTrialConfig_experiments_418,
    },
    {
        "QUIC",
        array_kFieldTrialConfig_experiments_419,
    },
    {
        "RTCAlignReceivedEncodedVideoTransforms",
        array_kFieldTrialConfig_experiments_420,
    },
    {
        "RasterInducingScroll",
        array_kFieldTrialConfig_experiments_421,
    },
    {
        "ReactivePrefetchDesktop",
        array_kFieldTrialConfig_experiments_422,
    },
    {
        "ReadAnythingDocsIntegrationRollout",
        array_kFieldTrialConfig_experiments_423,
    },
    {
        "ReadAnythingIPHRollout",
        array_kFieldTrialConfig_experiments_424,
    },
    {
        "ReadAnythingLocalSidePanelRollout",
        array_kFieldTrialConfig_experiments_425,
    },
    {
        "ReadAnythingPermanentAccessibility",
        array_kFieldTrialConfig_experiments_426,
    },
    {
        "ReadAnythingReadAloudDesktop",
        array_kFieldTrialConfig_experiments_427,
    },
    {
        "ReadAnythingReadAloudPhraseHighlighting",
        array_kFieldTrialConfig_experiments_428,
    },
    {
        "ReclaimOldPrepaintTiles",
        array_kFieldTrialConfig_experiments_429,
    },
    {
        "ReclaimPrepaintTilesWhenIdle",
        array_kFieldTrialConfig_experiments_430,
    },
    {
        "ReduceAcceptLanguage",
        array_kFieldTrialConfig_experiments_431,
    },
    {
        "ReduceIPCCombined",
        array_kFieldTrialConfig_experiments_432,
    },
    {
        "RegisterOsUpdateHandlerWin",
        array_kFieldTrialConfig_experiments_433,
    },
    {
        "RemotePageMetadataDesktopExpansion",
        array_kFieldTrialConfig_experiments_434,
    },
    {
        "RemoveDataUrlInSvgUse",
        array_kFieldTrialConfig_experiments_435,
    },
    {
        "RemoveFontLinkFallbacks",
        array_kFieldTrialConfig_experiments_436,
    },
    {
        "RemoveRendererProcessLimit",
        array_kFieldTrialConfig_experiments_437,
    },
    {
        "RenderDocumentWithNavigationQueueing",
        array_kFieldTrialConfig_experiments_438,
    },
    {
        "RenderPassDrawnRect",
        array_kFieldTrialConfig_experiments_439,
    },
    {
        "ReportCertificateErrors",
        array_kFieldTrialConfig_experiments_440,
    },
    {
        "ReportingServiceAlwaysFlush",
        array_kFieldTrialConfig_experiments_441,
    },
    {
        "ResolutionBasedDecoderPriority",
        array_kFieldTrialConfig_experiments_442,
    },
    {
        "ReuseDetectionBasedOnPasswordHashes",
        array_kFieldTrialConfig_experiments_443,
    },
    {
        "RunPerformanceManagerOnMainThreadSync",
        array_kFieldTrialConfig_experiments_444,
    },
    {
        "SafeBrowsingDailyPhishingReportsLimit",
        array_kFieldTrialConfig_experiments_445,
    },
    {
        "SafeBrowsingDeepScanningCriteria",
        array_kFieldTrialConfig_experiments_446,
    },
    {
        "SafeBrowsingExternalAppRedirectTelemetry",
        array_kFieldTrialConfig_experiments_447,
    },
    {
        "SafeBrowsingHashPrefixRealTimeLookupsFasterOhttpKeyRotation",
        array_kFieldTrialConfig_experiments_448,
    },
    {
        "SafeBrowsingNestedArchives",
        array_kFieldTrialConfig_experiments_449,
    },
    {
        "SafeBrowsingRemoveCookiesInAuthRequests",
        array_kFieldTrialConfig_experiments_450,
    },
    {
        "SafetyCheckUnusedSitePermissions",
        array_kFieldTrialConfig_experiments_451,
    },
    {
        "SafetyHub",
        array_kFieldTrialConfig_experiments_452,
    },
    {
        "SavePasswordHashFromProfilePicker",
        array_kFieldTrialConfig_experiments_453,
    },
    {
        "ScaleScrollbarAnimationTiming",
        array_kFieldTrialConfig_experiments_454,
    },
    {
        "ScreenlockReauthPromoCard",
        array_kFieldTrialConfig_experiments_455,
    },
    {
        "ScriptStreamingForNonHTTP",
        array_kFieldTrialConfig_experiments_456,
    },
    {
        "ScriptedIdleTaskControllerOOMFix",
        array_kFieldTrialConfig_experiments_457,
    },
    {
        "SeamlessRenderFrameSwap",
        array_kFieldTrialConfig_experiments_458,
    },
    {
        "SearchEngineChoiceGuestExperience",
        array_kFieldTrialConfig_experiments_459,
    },
    {
        "SearchPrefetchHighPriorityPrefetches",
        array_kFieldTrialConfig_experiments_460,
    },
    {
        "SearchWebInSidePanel",
        array_kFieldTrialConfig_experiments_461,
    },
    {
        "SecureTimeCertificateVerification",
        array_kFieldTrialConfig_experiments_462,
    },
    {
        "SegmentationPlatformUmaFromSqlDb",
        array_kFieldTrialConfig_experiments_463,
    },
    {
        "SelectParserRelaxation",
        array_kFieldTrialConfig_experiments_464,
    },
    {
        "SendTabToSelfIOSPushNotifications",
        array_kFieldTrialConfig_experiments_465,
    },
    {
        "SerializeAccessibilityPostLifecycle",
        array_kFieldTrialConfig_experiments_466,
    },
    {
        "ServiceWorkerAutoPreload",
        array_kFieldTrialConfig_experiments_467,
    },
    {
        "ServiceWorkerAvoidMainThreadForInitialization",
        array_kFieldTrialConfig_experiments_468,
    },
    {
        "ServiceWorkerDebugCorsExemptHeaderList",
        array_kFieldTrialConfig_experiments_469,
    },
    {
        "ServiceWorkerStaticRouter",
        array_kFieldTrialConfig_experiments_470,
    },
    {
        "ServiceWorkerStorageSuppressPostTask",
        array_kFieldTrialConfig_experiments_471,
    },
    {
        "SettingSearchExplorationHaTS",
        array_kFieldTrialConfig_experiments_472,
    },
    {
        "SharedHighlightingIphDesktop",
        array_kFieldTrialConfig_experiments_473,
    },
    {
        "SharedWorkerBlobURLFix",
        array_kFieldTrialConfig_experiments_474,
    },
    {
        "SharingHubDesktopScreenshots",
        array_kFieldTrialConfig_experiments_475,
    },
    {
        "ShowSuggestionsOnAutofocus",
        array_kFieldTrialConfig_experiments_476,
    },
    {
        "SidePanelCompanionDesktopM116Plus",
        array_kFieldTrialConfig_experiments_477,
    },
    {
        "SidePanelJourneys",
        array_kFieldTrialConfig_experiments_478,
    },
    {
        "SidePanelPinningWithResponsiveToolbar",
        array_kFieldTrialConfig_experiments_479,
    },
    {
        "SideSearchInProductHelp",
        array_kFieldTrialConfig_experiments_480,
    },
    {
        "SigninInterceptSimpleButtons",
        array_kFieldTrialConfig_experiments_481,
    },
    {
        "SingleVideoFrameRateThrottling",
        array_kFieldTrialConfig_experiments_482,
    },
    {
        "SkiaGraphite",
        array_kFieldTrialConfig_experiments_483,
    },
    {
        "SkipPagehideInCommitForDSENavigation",
        array_kFieldTrialConfig_experiments_484,
    },
    {
        "SkipUnnecessaryRemoteFrameGeometryPropagation",
        array_kFieldTrialConfig_experiments_485,
    },
    {
        "SpdyHeadersToHttpResponseUseBuilder",
        array_kFieldTrialConfig_experiments_486,
    },
    {
        "SpeculativeServiceWorkerWarmUp",
        array_kFieldTrialConfig_experiments_487,
    },
    {
        "SplitCacheByNavigationInitiatorSite",
        array_kFieldTrialConfig_experiments_488,
    },
    {
        "SplitCacheByNetworkIsolationKey",
        array_kFieldTrialConfig_experiments_489,
    },
    {
        "SqlWalMode",
        array_kFieldTrialConfig_experiments_490,
    },
    {
        "StaleSessionCookieCleanup",
        array_kFieldTrialConfig_experiments_491,
    },
    {
        "StaleStorageCleanup",
        array_kFieldTrialConfig_experiments_492,
    },
    {
        "StandardizedBrowserZoom",
        array_kFieldTrialConfig_experiments_493,
    },
    {
        "StorageBuckets",
        array_kFieldTrialConfig_experiments_494,
    },
    {
        "StreamlineRendererInit",
        array_kFieldTrialConfig_experiments_495,
    },
    {
        "SubSampleWindowProxyUsageMetrics",
        array_kFieldTrialConfig_experiments_496,
    },
    {
        "SubframeProcessReuseThresholds",
        array_kFieldTrialConfig_experiments_497,
    },
    {
        "SuppressesNetworkActivitiesOnSlowNetwork",
        array_kFieldTrialConfig_experiments_498,
    },
    {
        "SyncIncreaseNudgeDelayForSingleClient",
        array_kFieldTrialConfig_experiments_499,
    },
    {
        "TabAudioMuting",
        array_kFieldTrialConfig_experiments_500,
    },
    {
        "TabGroupSyncServiceDesktopMigration",
        array_kFieldTrialConfig_experiments_501,
    },
    {
        "TabGroupsCollapseFreezing",
        array_kFieldTrialConfig_experiments_502,
    },
    {
        "TabGroupsSaveUIUpdateAndSaveV2",
        array_kFieldTrialConfig_experiments_503,
    },
    {
        "TabSearchInProductHelp",
        array_kFieldTrialConfig_experiments_504,
    },
    {
        "TabStripCollectionStorage",
        array_kFieldTrialConfig_experiments_505,
    },
    {
        "TabstripDeclutter",
        array_kFieldTrialConfig_experiments_506,
    },
    {
        "TailoredSecurityIntegration",
        array_kFieldTrialConfig_experiments_507,
    },
    {
        "TcpSocketIoCompletionPortWin",
        array_kFieldTrialConfig_experiments_508,
    },
    {
        "TemplateUrlReconciliation",
        array_kFieldTrialConfig_experiments_509,
    },
    {
        "TextSizeAdjustImprovements",
        array_kFieldTrialConfig_experiments_510,
    },
    {
        "TheoraVideoCodec",
        array_kFieldTrialConfig_experiments_511,
    },
    {
        "ThreadCacheMinCachedMemoryForPurging",
        array_kFieldTrialConfig_experiments_512,
    },
    {
        "ThreadCachePurgeInterval",
        array_kFieldTrialConfig_experiments_513,
    },
    {
        "ThreadedScrollPreventRenderingStarvation",
        array_kFieldTrialConfig_experiments_514,
    },
    {
        "ThrottleUnimportantFrameTimers",
        array_kFieldTrialConfig_experiments_515,
    },
    {
        "TimedHTMLParserBudget",
        array_kFieldTrialConfig_experiments_516,
    },
    {
        "ToolbarPinning",
        array_kFieldTrialConfig_experiments_517,
    },
    {
        "TopChromeWebUIUsesSpareRenderer",
        array_kFieldTrialConfig_experiments_518,
    },
    {
        "TrackingProtection3pcd",
        array_kFieldTrialConfig_experiments_519,
    },
    {
        "TrackingProtection3pcdUx",
        array_kFieldTrialConfig_experiments_520,
    },
    {
        "TranslateBubbleOpenSettings",
        array_kFieldTrialConfig_experiments_521,
    },
    {
        "TransportSecurityFileWriterSchedule",
        array_kFieldTrialConfig_experiments_522,
    },
    {
        "TruncateLanguageDetectionSample",
        array_kFieldTrialConfig_experiments_523,
    },
    {
        "TrustSafetySentimentSurvey",
        array_kFieldTrialConfig_experiments_524,
    },
    {
        "TrustSafetySentimentSurveyV2",
        array_kFieldTrialConfig_experiments_525,
    },
    {
        "TrustTokenOriginTrial",
        array_kFieldTrialConfig_experiments_526,
    },
    {
        "UIEnableSharedImageCacheForGpu",
        array_kFieldTrialConfig_experiments_527,
    },
    {
        "UMA-NonUniformity-Trial-1-Percent",
        array_kFieldTrialConfig_experiments_528,
    },
    {
        "UMA-Pseudo-Metrics-Effect-Injection-25-Percent",
        array_kFieldTrialConfig_experiments_529,
    },
    {
        "UiaProviderWin",
        array_kFieldTrialConfig_experiments_530,
    },
    {
        "UnifiedAutoplay",
        array_kFieldTrialConfig_experiments_531,
    },
    {
        "UnoDesktopM0Followup",
        array_kFieldTrialConfig_experiments_532,
    },
    {
        "UnoDesktopM0Full",
        array_kFieldTrialConfig_experiments_533,
    },
    {
        "UnoPwa",
        array_kFieldTrialConfig_experiments_534,
    },
    {
        "UseAsyncOsCryptInLoginDatabase",
        array_kFieldTrialConfig_experiments_535,
    },
    {
        "UseBoringSSLForRandBytes",
        array_kFieldTrialConfig_experiments_536,
    },
    {
        "UseBrowserCalculatedOrigins",
        array_kFieldTrialConfig_experiments_537,
    },
    {
        "UseClientGmbInterface",
        array_kFieldTrialConfig_experiments_538,
    },
    {
        "UseDMSAAForTiles",
        array_kFieldTrialConfig_experiments_539,
    },
    {
        "UseItemSnippetsAPI",
        array_kFieldTrialConfig_experiments_540,
    },
    {
        "UseMoveNotCopyInAXTreeCombiner",
        array_kFieldTrialConfig_experiments_541,
    },
    {
        "UseMoveNotCopyInMergeTreeUpdate",
        array_kFieldTrialConfig_experiments_542,
    },
    {
        "UseNewEncryptionKeyForWebData",
        array_kFieldTrialConfig_experiments_543,
    },
    {
        "UseRustJsonParserInCurrentSequence",
        array_kFieldTrialConfig_experiments_544,
    },
    {
        "UseSmartRefForGPUFenceHandle",
        array_kFieldTrialConfig_experiments_545,
    },
    {
        "UseSnappyForParkableStrings",
        array_kFieldTrialConfig_experiments_546,
    },
    {
        "UseThreadPriorityLowest",
        array_kFieldTrialConfig_experiments_547,
    },
    {
        "UserBypassUI",
        array_kFieldTrialConfig_experiments_548,
    },
    {
        "UsernameFirstFlowWithIntermediateValuesPredictions",
        array_kFieldTrialConfig_experiments_549,
    },
    {
        "V8CodeFlushing",
        array_kFieldTrialConfig_experiments_550,
    },
    {
        "V8CompileHints3",
        array_kFieldTrialConfig_experiments_551,
    },
    {
        "V8CppGCEnableLargerCage",
        array_kFieldTrialConfig_experiments_552,
    },
    {
        "V8EfficiencyModeTiering",
        array_kFieldTrialConfig_experiments_553,
    },
    {
        "V8ExternalMemoryAccountedInGlobalLimit",
        array_kFieldTrialConfig_experiments_554,
    },
    {
        "V8FlushBaselineCode",
        array_kFieldTrialConfig_experiments_555,
    },
    {
        "V8GCSpeedUsesCounters",
        array_kFieldTrialConfig_experiments_556,
    },
    {
        "V8IncrementalMarkingStartUserVisible",
        array_kFieldTrialConfig_experiments_557,
    },
    {
        "V8IntelJCCErratumMitigation",
        array_kFieldTrialConfig_experiments_558,
    },
    {
        "V8LocalCompileHints",
        array_kFieldTrialConfig_experiments_559,
    },
    {
        "V8ScavengerHigherCapacity",
        array_kFieldTrialConfig_experiments_560,
    },
    {
        "V8SeparateGCPhases",
        array_kFieldTrialConfig_experiments_561,
    },
    {
        "V8SideStepTransitions",
        array_kFieldTrialConfig_experiments_562,
    },
    {
        "V8SingleThreadedGCInBackgroundVariants",
        array_kFieldTrialConfig_experiments_563,
    },
    {
        "V8SlowHistograms",
        array_kFieldTrialConfig_experiments_564,
    },
    {
        "V8UpdateLimitAfterLoading",
        array_kFieldTrialConfig_experiments_565,
    },
    {
        "VSyncDecoding",
        array_kFieldTrialConfig_experiments_566,
    },
    {
        "VerifyDidCommitParams",
        array_kFieldTrialConfig_experiments_567,
    },
    {
        "VideoDecodeBatching",
        array_kFieldTrialConfig_experiments_568,
    },
    {
        "ViewTransitionOnNavigation",
        array_kFieldTrialConfig_experiments_569,
    },
    {
        "VisibilityAwareResourceScheduler",
        array_kFieldTrialConfig_experiments_570,
    },
    {
        "VisitedURLRankingService",
        array_kFieldTrialConfig_experiments_571,
    },
    {
        "WebAssemblyDeopt",
        array_kFieldTrialConfig_experiments_572,
    },
    {
        "WebAssemblyInliningCallIndirect",
        array_kFieldTrialConfig_experiments_573,
    },
    {
        "WebAudioBypassOutputBuffering",
        array_kFieldTrialConfig_experiments_574,
    },
    {
        "WebContentsCaptureHiDPI",
        array_kFieldTrialConfig_experiments_575,
    },
    {
        "WebContentsDiscard",
        array_kFieldTrialConfig_experiments_576,
    },
    {
        "WebGPU",
        array_kFieldTrialConfig_experiments_577,
    },
    {
        "WebGPUSupportMetrics",
        array_kFieldTrialConfig_experiments_578,
    },
    {
        "WebGPUUseDXC2",
        array_kFieldTrialConfig_experiments_579,
    },
    {
        "WebGPUUseTintIR",
        array_kFieldTrialConfig_experiments_580,
    },
    {
        "WebRTC-Aec3BufferingMaxAllowedExcessRenderBlocksOverride",
        array_kFieldTrialConfig_experiments_581,
    },
    {
        "WebRTC-Aec3DelayEstimateSmoothingDelayFoundOverride",
        array_kFieldTrialConfig_experiments_582,
    },
    {
        "WebRTC-Aec3TransparentModeHmm",
        array_kFieldTrialConfig_experiments_583,
    },
    {
        "WebRTC-Audio-GainController2",
        array_kFieldTrialConfig_experiments_584,
    },
    {
        "WebRTC-Audio-NetEqDecisionLogicConfig",
        array_kFieldTrialConfig_experiments_585,
    },
    {
        "WebRTC-Audio-OpusAvoidNoisePumpingDuringDtx",
        array_kFieldTrialConfig_experiments_586,
    },
    {
        "WebRTC-BurstyPacer",
        array_kFieldTrialConfig_experiments_587,
    },
    {
        "WebRTC-Bwe-LossBasedBweV2",
        array_kFieldTrialConfig_experiments_588,
    },
    {
        "WebRTC-Bwe-ProbingConfiguration",
        array_kFieldTrialConfig_experiments_589,
    },
    {
        "WebRTC-Bwe-ReceiverLimitCapsOnly",
        array_kFieldTrialConfig_experiments_590,
    },
    {
        "WebRTC-Bwe-RobustThroughputEstimatorSettings",
        array_kFieldTrialConfig_experiments_591,
    },
    {
        "WebRTC-IPv6NetworkResolutionFixes",
        array_kFieldTrialConfig_experiments_592,
    },
    {
        "WebRTC-JitterEstimatorConfig",
        array_kFieldTrialConfig_experiments_593,
    },
    {
        "WebRTC-SendBufferSizeBytes",
        array_kFieldTrialConfig_experiments_594,
    },
    {
        "WebRTC-SendPacketsOnWorkerThread",
        array_kFieldTrialConfig_experiments_595,
    },
    {
        "WebRTC-SlackedTaskQueuePacedSender",
        array_kFieldTrialConfig_experiments_596,
    },
    {
        "WebRTC-VP8ConferenceTemporalLayers",
        array_kFieldTrialConfig_experiments_597,
    },
    {
        "WebRTC-Video-EnableRetransmitAllLayers",
        array_kFieldTrialConfig_experiments_598,
    },
    {
        "WebRTC-Video-H26xPacketBuffer",
        array_kFieldTrialConfig_experiments_599,
    },
    {
        "WebRTC-Video-ReceiveAndSendH265",
        array_kFieldTrialConfig_experiments_600,
    },
    {
        "WebRTC-Vp9ExternalRefCtrl",
        array_kFieldTrialConfig_experiments_601,
    },
    {
        "WebRTC-ZeroPlayoutDelay",
        array_kFieldTrialConfig_experiments_602,
    },
    {
        "WebRtcAudioSinkUseTimestampAligner",
        array_kFieldTrialConfig_experiments_603,
    },
    {
        "WebRtcEncodedTransformDirectCallback",
        array_kFieldTrialConfig_experiments_604,
    },
    {
        "WebRtcThreadsUseResourceEfficientType",
        array_kFieldTrialConfig_experiments_605,
    },
    {
        "WebUITabStrip",
        array_kFieldTrialConfig_experiments_606,
    },
    {
        "WhatsNewHats",
        array_kFieldTrialConfig_experiments_607,
    },
    {
        "WhatsNewSparkEdition",
        array_kFieldTrialConfig_experiments_608,
    },
    {
        "WinSboxNoFakeGdiInit",
        array_kFieldTrialConfig_experiments_609,
    },
    {
        "WinSboxParallelProcessLaunch",
        array_kFieldTrialConfig_experiments_610,
    },
    {
        "WinSystemLocationPermission",
        array_kFieldTrialConfig_experiments_611,
    },
    {
        "ZPSPrefetchDebouncingDesktop",
        array_kFieldTrialConfig_experiments_612,
    },
    {
        "ZeroCopyTabCaptureStudyWin",
        array_kFieldTrialConfig_experiments_613,
    },
};
const FieldTrialTestingConfig kFieldTrialConfig = {
    array_kFieldTrialConfig_studies,
};

} // namespace variations
