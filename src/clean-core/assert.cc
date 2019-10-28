#include <clean-core/assert.hh>

#include <cstdio>
#include <cstdlib>

namespace
{
using assertion_handler_t = void (*)(cc::detail::assertion_info const&);

thread_local assertion_handler_t s_current_handler = nullptr;

void default_assertion_handler(cc::detail::assertion_info const& info)
{
    fprintf(stderr, "assertion `%s' failed.\n", info.expr);
    fprintf(stderr, "  in %s\n", info.func);
    fprintf(stderr, "  file %s:%d\n", info.file, info.line);
    fflush(stderr);

    // TODO: stacktrace

    std::abort();
}
} // namespace

void cc::detail::assertion_failed(assertion_info const& info)
{
    if (s_current_handler)
        s_current_handler(info);
    else
        default_assertion_handler(info);
}

void cc::set_assertion_handler(void (*handler)(detail::assertion_info const&)) { s_current_handler = handler; }
