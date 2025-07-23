#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_INTERNAL_COVERAGE_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_INTERNAL_COVERAGE_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/internal-coverage.tq?l=11&c=1
TNode<CoverageInfo> GetCoverageInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSFunction> p_function, compiler::CodeAssemblerLabel* label_IfNoCoverageInfo);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/internal-coverage.tq?l=20&c=1
void IncrementBlockCount_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<CoverageInfo> p_coverageInfo, TNode<Smi> p_slot);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/internal-coverage.tq?l=15&c=24
TNode<CoverageInfo> Cast_CoverageInfo_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_INTERNAL_COVERAGE_TQ_CSA_H_
