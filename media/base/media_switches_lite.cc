
#include "media/base/media_switches.h"

#include "base/command_line.h"
#include "build/build_config.h"
#include "build/chromeos_buildflags.h"
// #include "components/system_media_controls/linux/buildflags/buildflags.h"
#include "media/media_buildflags.h"

#if BUILDFLAG(IS_LINUX)
#include "base/cpu.h"
#endif

namespace media {

BASE_FEATURE(kRevokeMediaSourceObjectURLOnAttach, "RevokeMediaSourceObjectURLOnAttach", base::FEATURE_ENABLED_BY_DEFAULT);

// Use R16 texture for 9-16 bit channel instead of half-float conversion by CPU.
BASE_FEATURE(kUseR16Texture, "use-r16-texture", base::FEATURE_DISABLED_BY_DEFAULT);

}