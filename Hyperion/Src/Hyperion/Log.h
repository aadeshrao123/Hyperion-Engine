
#include <memory.h>
#include "Core.h"
#include "spdlog/spdlog.h"
namespace Hyperion
{
	class HYPERION_API Log
	{
	public:

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

		private:
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
};

//core log macros
#define HY_CORE_TRACE(...)		::Hyperion::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HY_CORE_INFO(...)		::Hyperion::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HY_CORE_WARN(...)		::Hyperion::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HY_CORE_ERROR(...)		::Hyperion::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HY_CORE_FATAL(...)		::Hyperion::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//client log macros
#define HY_TRACE(...)			::Hyperion::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HY_INFO(...)			::Hyperion::Log::GetClientLogger()->info(__VA_ARGS__)
#define HY_WARN(...)			::Hyperion::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HY_ERROR(...)			::Hyperion::Log::GetClientLogger()->error(__VA_ARGS__)
#define HY_FATAL(...)			::Hyperion::Log::GetClientLogger()->fatal(__VA_ARGS__)