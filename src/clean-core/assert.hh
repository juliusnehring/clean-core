#pragma once

#include <clean-core/macros.hh>

// least overhead assertion macros
// see https://godbolt.org/z/BvF_yn
// [[unlikely]] produces more code in O0 so it is only used outside of debug
// decltype(...) is an unevaluated context, thus eliminating any potential side effect
// assertion handler is customizable

// ASSERT(cond) aborts if `cond` is false
// BOUND_CHECK(var, lb, ub) asserts `lb <= var && var < ub`
// NOTE: neither macro must contain side effects!

// compile flags
// CC_ENABLE_ASSERTIONS enables assertions
// CC_ENABLE_BOUND_CHECKING enables bound checking

#define CC_DETAIL_EXECUTE_ASSERT(condition, msg) \
    (CC_UNLIKELY(!(condition)) ? ::cc::detail::assertion_failed({#condition, CC_PRETTY_FUNC, __FILE__, msg, __LINE__}) : void(0)) // force ;

#define CC_RUNTIME_ASSERT(condition) CC_DETAIL_EXECUTE_ASSERT(condition, nullptr)
#define CC_RUNTIME_ASSERT_MSG(condition, msg) CC_DETAIL_EXECUTE_ASSERT(condition, msg)

#if !defined(CC_ENABLE_ASSERTIONS)
#define CC_ASSERT(condition) CC_UNUSED(condition)
#define CC_ASSERT_MSG(condition, msg) CC_UNUSED(condition)
#else
#define CC_ASSERT(condition) CC_DETAIL_EXECUTE_ASSERT(condition, nullptr)
#define CC_ASSERT_MSG(condition, msg) CC_DETAIL_EXECUTE_ASSERT(condition, msg)
#endif

#ifdef CC_ENABLE_BOUND_CHECKING
#define CC_ASSERT_IN_BOUNDS(var, lb, ub) CC_ASSERT((lb) <= (var) && (var) < (ub) && "bound check")
#else
#define CC_ASSERT_IN_BOUNDS(var, lb, ub) CC_UNUSED((lb) <= (var) && (var) < (ub))
#endif

#ifdef CC_ENABLE_NULL_CHECKING
#define CC_ASSERT_IS_NULL(p) CC_ASSERT((p) == nullptr && "must be null")
#define CC_ASSERT_NOT_NULL(p) CC_ASSERT((p) != nullptr && "must not be null")
#else
#define CC_ASSERT_IS_NULL(p) CC_UNUSED((p) == nullptr && "")
#define CC_ASSERT_NOT_NULL(p) CC_UNUSED((p) != nullptr && "")
#endif

#ifdef CC_ENABLE_CONTRACT_CHECKING
#define CC_CONTRACT(condition) CC_ASSERT((condition) && "contract violation")
#else
#define CC_CONTRACT(condition) CC_UNUSED((condition) && "")
#endif

#ifdef CC_ENABLE_ASSERTIONS
#define CC_UNREACHABLE(msg) \
    (::cc::detail::assertion_failed({"unreachable code reached: " msg, CC_PRETTY_FUNC, __FILE__, nullptr, __LINE__}), CC_BUILTIN_UNREACHABLE)
#else
#define CC_UNREACHABLE(msg) CC_BUILTIN_UNREACHABLE
#endif

// workaround for https://gcc.gnu.org/bugzilla/show_bug.cgi?id=86678
#if defined(CC_COMPILER_GCC) && __GNUC__ < 9
#define CC_UNREACHABLE_SWITCH_WORKAROUND(type)                \
    if (type != decltype(type){} || type == decltype(type){}) \
        CC_UNREACHABLE("unhandled case for " #type);          \
    else                                                      \
        return {} // force ;
#else
#define CC_UNREACHABLE_SWITCH_WORKAROUND(type) CC_UNREACHABLE("unhandled case for " #type)
#endif

namespace cc::detail
{
struct assertion_info
{
    char const* expr;
    char const* func;
    char const* file;
    char const* msg;
    int line;
};

[[noreturn]] CC_COLD_FUNC CC_DONT_INLINE void assertion_failed(assertion_info const& info);
}

namespace cc
{
/// handler that is called whenever an assertion is violated
/// pass nullptr to reset to default handler
/// this is a thread_local handler
/// the handler must be replaced before it is deleted (non-owning view)
void set_assertion_handler(void (*handler)(detail::assertion_info const& info));
}
